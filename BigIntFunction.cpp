#include "cls.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <sstream>


template <typename T>
std::string toString(T v) { 
    std::ostringstream os;
    os << v;
    return os.str();
}

BigInt::BigInt(const BigInt &bigint) {
    num = bigint.num;
    point = bigint.point;
}

BigInt::BigInt() : num("0") {} 

BigInt::BigInt(const std::string& value) {
    if (value.empty()) {
        num = "0";
        point = 0;
        return;
    }

    if (value[0] == '-') {
        point = -1; 
    } else if (value == "0") {
        num = "0";
        point = 0;
        return;
    } else {
        point = 1;
    }


    std::string processed = value;
    std::string::size_type startIndex = (point == -1) ? 1 : 0;
    std::string::size_type firstNonZero = startIndex;

    while (firstNonZero < processed.size() && processed[firstNonZero] == '0') {
        ++firstNonZero;
    }

    if (firstNonZero == processed.size()) {
        num = "0";
    } else {
        num = (point == -1 ? "-" : "") + processed.substr(firstNonZero);
    }
}

BigInt::BigInt(int v) {
    if (v > 0) point = 1;
    if (v == 0) point = 0;
    if (v < 0) point = -1;

    num = toString(v);
}

BigInt::BigInt(const short& value) {
    if (value > 0) point = 1;
    if (value < 0) point = -1;
    if (value == 0) point = 0;

    num = toString(value); 
}

BigInt::BigInt(const char& value) {
    if (value > 0) point  = 1;
    if (value < 0) point = -1;
    if (value == 0) point = 0;

    num = toString(value);
}

BigInt::BigInt(const long& value) {
    if (value > 0) point = 1;
    if (value < 0) point = -1;
    if (value == 0) point = 0;

    num = toString(value);
}

BigInt::~BigInt() {
}


BigInt::operator int() {
    return atoi(num.c_str()); 
}

BigInt::operator std::string() {
    return num;
}

BigInt::operator short() {
    return atoi(num.c_str());
}

BigInt::operator char() {
    return atoi(num.c_str());
}

BigInt::operator long() {
    long result = 0;
    size_t i; 
    size_t length = num.size();
    if (point == 1) {
        for (i = 0; i < length; i++) {
            result += (num[(length - 1) - i] - '0') * pow(10, i);
        }
    } else if (point == -1) {
        for (i = 0; i < length - 1; i++) {
            result += (num[(length - 1) - i] - '0') * pow(10, i);
        }
        result = -result;
    }

    return result;
}

std::ostream& operator << (std::ostream &os, const BigInt& other) {
    os << other.getNum();
    return os;
}



std::istream& operator>>(std::istream &is, BigInt& bigint) {
    std::string input;
    is >> input;
    if (input.empty() || (!isdigit(input[0]) && input[0] != '-') || 
        (input[0] == '-' && input.size() == 1)) {
        std::cerr << "Error: Invalid input." << std::endl;
        is.setstate(std::ios::failbit); 
        return is;
    }

    for (size_t i = 1; i < input.size(); ++i) { 
        if (!isdigit(input[i])) {
            std::cerr << "Error: Input contains invalid characters." << std::endl;
            is.setstate(std::ios::failbit); 
            return is;
        }
    }

    bigint = BigInt(input); 
    return is;
}

BigInt& BigInt::operator=(const BigInt& other) {
    if (this != &other) {  
        num = other.num; 
        point = other.point; 
    }
    return *this;
}

bool operator>=(const BigInt& left, const BigInt& right) {
    if (left.point > right.point) return true;
    if (left.point < right.point) return false;


    if (left.point == 1) { 
        if (left.num.length() > right.num.length()) return true;
        if (left.num.length() < right.num.length()) return false;
        return left.num >= right.num; 
    } else if (left.point == -1) {  
        if (left.num.length() > right.num.length()) return false;
        if (left.num.length() < right.num.length()) return true;
        return left.num <= right.num;  
    }

    return true;
}

bool operator==(const BigInt& left, const BigInt& right) {
    return left.num == right.num;
}

BigInt operator+(const BigInt& left, const BigInt& right) {
    std::string num1 = left.getNum();
    std::string num2 = right.getNum();
    if (num1[0] == '-' && num2[0] == '-') {
        BigInt temp1(num1.substr(1));
        BigInt temp2(num2.substr(1));
        return BigInt("-" + (temp1 + temp2).getNum()); 
    }

    if (num1[0] == '-') {
        BigInt temp1(num1.substr(1));
        return BigInt(num2) - temp1;
    }

    if (num2[0] == '-') {
        BigInt temp2(num2.substr(1));
        return BigInt(num1) - temp2; 
    }

    std::string result;
    size_t carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.insert(result.begin(), (sum % 10) + '0'); 

        --i;
        --j;
    }

    return BigInt(result);
}

BigInt operator-(const BigInt& left, const BigInt& right) {
    std::string num1 = left.getNum();
    std::string num2 = right.getNum();

    if (num1[0] == '-' && num2[0] != '-') {
        return BigInt("-" + (BigInt(num1.substr(1)) + BigInt(num2)).getNum());
    }
    if (num1[0] != '-' && num2[0] == '-') {
        return BigInt(num1) + BigInt(num2.substr(1));
    }

    if (num1[0] == '-' && num2[0] == '-') {
        return BigInt(num2.substr(1)) - BigInt(num1.substr(1));
    }

    bool isNegative = false;
    if (num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2)) {
        std::swap(num1, num2);
        isNegative = true;
    }

    std::string result;
    size_t borrow = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sub = digit1 - digit2 - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.insert(result.begin(), sub + '0');
        --i;
        --j;
    }

    std::string::size_type nonZero = result.find_first_not_of('0');
    if (nonZero == std::string::npos) {
        result = "0";
    } else {
        result = result.substr(nonZero);
    }

    if (isNegative && result != "0") {
        result.insert(result.begin(), '-');
    }

    return BigInt(result);
}

BigInt operator*(const BigInt& left, const BigInt& right) { //------------------------------------------------------------------
    std::string arr1 = left.getNum();
    std::string arr2 = right.getNum();
    int i, j, posHigh, posLow, mul, sum;

    if (arr1 == "0" || arr2 == "0") {
        return BigInt("0");
    }

    bool minus = false;
    std::string num1 = arr1;
    std::string num2 = arr2;

    if (arr1[0] == '-' && arr2[0] == '-') {
        num1 = arr1.substr(1);
        num2 = arr2.substr(1);
    } else if (arr1[0] == '-') {
        num1 = arr1.substr(1); 
        minus = true;
    } else if (arr2[0] == '-') {
        num2 = arr2.substr(1);
        minus = true;
    }

    int maxSize = num1.size() + num2.size();
    int* result = new int[maxSize];
    for (i = 0; i < maxSize; ++i) result[i] = 0;

    for (i = num1.size() - 1; i >= 0; --i) {
        for (j = num2.size() - 1; j >= 0; --j) {
            mul = (num1[i] - '0') * (num2[j] - '0');
            posLow = i + j + 1;
            posHigh = i + j;

            sum = mul + result[posLow];
            result[posLow] = sum % 10;
            result[posHigh] += sum / 10;
        }
    }
    std::string resultStr;
    bool leadingZero = true;
    for (int i = 0; i < maxSize; ++i) {
        if (leadingZero && result[i] == 0) continue;
        leadingZero = false;
        resultStr.push_back(result[i] + '0');
    }

    delete[] result;

    if (minus) {
        resultStr = "-" + resultStr;
    }

   return BigInt(resultStr);
}

BigInt operator/(const BigInt& left, const BigInt& right) { // ----------------------------------------------------
    if (right.num == "0") {
        throw std::runtime_error("Division by zero is not allowed.");
    }

    bool isNegative = (left.point != right.point);

    std::string num1 = (left.num[0] == '-') ? left.num.substr(1) : left.num;
    std::string num2 = (right.num[0] == '-') ? right.num.substr(1) : right.num;

    std::string result = "";
    BigInt rem("0");
    BigInt divisor(num2);

    for (size_t i = 0; i < num1.size(); ++i) {
        rem = rem * BigInt("10") + BigInt(std::string(1, num1[i]));
        int count = 0;

        while (rem >= divisor) {
            rem = rem - divisor;
            ++count;
        }
        result += toString(count);
    }

    size_t pos = result.find_first_not_of('0');
    if (pos == std::string::npos) {
        return BigInt("0");
    }

    result = result.substr(pos);

    if (isNegative && result != "0") {
        result.insert(result.begin(), '-');
    }

    return BigInt(result);
}

BigInt operator%(const BigInt& left, const BigInt& right) {
    if (right.num == "0") {
        throw std::runtime_error("Division by zero is not allowed.");
    }

    bool isNegative = (left.point < 0);

    std::string num1 = (left.num[0] == '-') ? left.num.substr(1) : left.num;
    std::string num2 = (right.num[0] == '-') ? right.num.substr(1) : right.num;

    BigInt rem("0");
    BigInt divisor(num2);

    for (size_t i = 0; i < num1.size(); ++i) {
        rem = rem * BigInt("10") + BigInt(std::string(1, num1[i]));
        while (rem >= divisor) {
            rem = rem - divisor;
        }
    }

    if (isNegative && rem.num != "0") {
        rem = BigInt("-" + rem.num);
    }

    return rem;
}

BigInt BigInt::gcd(const BigInt& other) const {
    BigInt zero("0");
    BigInt a = (*this >= zero) ? *this : -1 * *this;
    BigInt b = (other >= zero) ? other : -1 * other;

    while (!(b == zero)) {
        BigInt temp = b;
        b = a % b; 
        a = temp;
    }

    return a;
}

BigInt BigInt::lcm(const BigInt& other) const {
    BigInt gcd_val = this->gcd(other);
    BigInt zero("0");
    BigInt a = (*this >= zero) ? *this : -1 * *this;
    BigInt b = (other >= zero) ? other : -1 * other;

    BigInt product = a * b;
    BigInt lcm_val = product / gcd_val;

    return lcm_val;
}

BigInt operator+(BigInt a, std::string b) {
    BigInt bigB(b);
    return a + bigB;
}
BigInt operator+(int a, BigInt b) {
    BigInt bigA(a);
    return bigA + b;
}
BigInt operator+(BigInt a, int b) {
    BigInt bigB(b); 
    return a + bigB;
}
BigInt operator+(short a, BigInt b) {
    BigInt bigA(a);
    return bigA + b;
}
BigInt operator+(BigInt a, short b) {
    BigInt bigB(b);
    return a + bigB;
}
BigInt operator+(long a, BigInt b) {
    BigInt bigA(a);
    return bigA + b;
}
BigInt operator+(BigInt a, long b) {
    BigInt bigB(b);
    return a + bigB;
}
BigInt operator+(char a, BigInt b) {
    BigInt bigA(a - '0');
    return bigA + b;
}
BigInt operator+(BigInt a, char b) {
    BigInt bigB(b - '0');
    return a + bigB;
}

BigInt operator-(std::string a, BigInt b) {
    BigInt bigA(a);
    return bigA - b;
}
BigInt operator-(BigInt a, std::string b) {
    BigInt bigB(b); 
    return a - bigB;
}
BigInt operator-(int a, BigInt b) {
    BigInt bigA(a);
    return bigA - b;
}
BigInt operator-(BigInt a, int b) {
    BigInt bigB(b);
    return a - bigB;
}
BigInt operator-(short a, BigInt b) {
    BigInt bigA(a);
    return bigA - b;
}
BigInt operator-(BigInt a, short b) {
    BigInt bigB(b);
    return a - bigB;
}
BigInt operator-(long a, BigInt b) {
    BigInt bigA(a);
    return bigA - b; 
}
BigInt operator-(BigInt a, long b) {
    BigInt bigB(b);
    return a - bigB;
}
BigInt operator-(char a, BigInt b) {
    BigInt bigA(a - '0'); 
    return bigA - b;
}
BigInt operator-(BigInt a, char b) {
    BigInt bigB(b - '0'); 
    return a - bigB;
}

BigInt operator*(std::string a, BigInt b) {
    BigInt bigA(a);
    return bigA * b;
}
BigInt operator*(BigInt a, std::string b) {
    BigInt bigB(b); 
    return a * bigB;
}
BigInt operator*(int a, BigInt b) {
    BigInt bigA(a);
    return bigA * b;
}
BigInt operator*(BigInt a, int b) {
    BigInt bigB(b);
    return a * bigB;
}
BigInt operator*(short a, BigInt b) {
    BigInt bigA(a);
    return bigA * b;
}
BigInt operator*(BigInt a, short b) {
    BigInt bigB(b);
    return a * bigB;
}
BigInt operator*(long a, BigInt b) {
    BigInt bigA(a);
    return bigA * b; 
}
BigInt operator*(BigInt a, long b) {
    BigInt bigB(b);
    return a * bigB;
}
BigInt operator*(char a, BigInt b) {
    BigInt bigA(a - '0'); 
    return bigA * b;
}
BigInt operator*(BigInt a, char b) {
    BigInt bigB(b - '0'); 
    return a * bigB;
}

BigInt operator/(std::string a, BigInt b) {
    BigInt bigA(a);
    return bigA / b;
}
BigInt operator/(BigInt a, std::string b) {
    BigInt bigB(b); 
    return a / bigB;
}
BigInt operator/(int a, BigInt b) {
    BigInt bigA(a);
    return bigA / b;
}
BigInt operator/(BigInt a, int b) {
    BigInt bigB(b);
    return a / bigB;
}
BigInt operator/(short a, BigInt b) {
    BigInt bigA(a);
    return bigA / b;
}
BigInt operator/(BigInt a, short b) {
    BigInt bigB(b);
    return a / bigB;
}
BigInt operator/(long a, BigInt b) {
    BigInt bigA(a);
    return bigA / b; 
}
BigInt operator/(BigInt a, long b) {
    BigInt bigB(b);
    return a / bigB;
}
BigInt operator/(char a, BigInt b) {
    BigInt bigA(a - '0'); 
    return bigA / b;
}
BigInt operator/(BigInt a, char b) {
    BigInt bigB(b - '0'); 
    return a / bigB;
}

BigInt operator%(std::string a, BigInt b) {
    BigInt bigA(a);
    return bigA % b;
}
BigInt operator%(BigInt a, std::string b) {
    BigInt bigB(b); 
    return a % bigB;
}
BigInt operator%(int a, BigInt b) {
    BigInt bigA(a);
    return bigA % b;
}
BigInt operator%(BigInt a, int b) {
    BigInt bigB(b);
    return a % bigB;
}
BigInt operator%(short a, BigInt b) {
    BigInt bigA(a);
    return bigA % b;
}
BigInt operator%(BigInt a, short b) {
    BigInt bigB(b);
    return a % bigB;
}
BigInt operator%(long a, BigInt b) {
    BigInt bigA(a);
    return bigA % b; 
}
BigInt operator%(BigInt a, long b) {
    BigInt bigB(b);
    return a % bigB;
}
BigInt operator%(char a, BigInt b) {
    BigInt bigA(a - '0'); 
    return bigA % b;
}
BigInt operator%(BigInt a, char b) {
    BigInt bigB(b - '0'); 
    return a % bigB;
}


