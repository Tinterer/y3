#include <iostream>

class BigInt {
private:
    int point;
    std::string num; 
public:
    BigInt(); //конструктор по умолчанию
    BigInt(int v); // конструктор обрабатывающий случай когда вводится int
    BigInt(const std::string& s); // конструктор string
    BigInt(const short& value);
    BigInt(const char& value); 
    BigInt(const long& value); 
    ~BigInt(); // деструктор  

    operator int();                   //      
    operator std::string();           //      
    operator short();                 //      Приведение длинного целого к базовым типам данных
    operator char();                  //      
    operator long();                  //     

    BigInt operator-() const;         // унарный минус

    BigInt(const BigInt &bigint);     // копирование

    BigInt& operator=(const BigInt& other);   // оператор присваивания 

    std::string getNum() const {return num;}

    BigInt gcd(const BigInt& other) const;
    BigInt lcm(const BigInt& other) const;

    friend BigInt operator+(const BigInt& left, const BigInt& right);           // оператор сложения
    friend BigInt operator-(const BigInt& left, const BigInt& right);           // оператор вычитания
    friend BigInt operator*(const BigInt& left, const BigInt& right);           // оператор умножения
    friend std::ostream& operator<<(std::ostream &os, const BigInt& bigint);    // оператор ввода
    friend std::istream& operator>>(std::istream &is, BigInt& bigint);          // оператор вывода
    friend BigInt operator/(const BigInt& left, const BigInt& right);           // оператор деления
    friend bool operator>=(const BigInt& left, const BigInt& right);            // оператор больше или равно (для деления)
    friend bool operator==(const BigInt& left, const BigInt& right);            // оператор равно
    friend BigInt operator%(const BigInt& left, const BigInt& right);           // оператор выделения остатка

    friend BigInt operator+(std::string a,BigInt b);
    friend BigInt operator+(BigInt a,std::string b);
        
    friend BigInt operator+(int a,BigInt b);
    friend BigInt operator+(BigInt a,int b);

    friend BigInt operator+(short a,BigInt b);
    friend BigInt operator+(BigInt a,short b);

    friend BigInt operator+(long a,BigInt b);
    friend BigInt operator+(BigInt a,long b);

    friend BigInt operator+(char a,BigInt b);
    friend BigInt operator+(BigInt a,char b); 

    friend BigInt operator-(std::string a,BigInt b);
    friend BigInt operator-(BigInt a,std::string b);

    friend BigInt operator-(int a,BigInt b);
    friend BigInt operator-(BigInt a,int b);

    friend BigInt operator-(short a,BigInt b);
    friend BigInt operator-(BigInt a,short b);

    friend BigInt operator-(long a,BigInt b);
    friend BigInt operator-(BigInt a,long b);

    friend BigInt operator-(char a,BigInt b);
    friend BigInt operator-(BigInt a,char b);

    friend BigInt operator*(std::string a,BigInt b);
    friend BigInt operator*(BigInt a,std::string b);

    friend BigInt operator*(int a,BigInt b);
    friend BigInt operator*(BigInt a,int b);

    friend BigInt operator*(short a,BigInt b);
    friend BigInt operator*(BigInt a,short b);

    friend BigInt operator*(long a,BigInt b);
    friend BigInt operator*(BigInt a,long b);

    friend BigInt operator*(char a,BigInt b);
    friend BigInt operator*(BigInt a,char b);

    friend BigInt operator/(std::string a,BigInt b);
    friend BigInt operator/(BigInt a,std::string b);

    friend BigInt operator/(int a,BigInt b);
    friend BigInt operator/(BigInt a,int b);

    friend BigInt operator/(short a,BigInt b);
    friend BigInt operator/(BigInt a,short b);

    friend BigInt operator/(long a,BigInt b);
    friend BigInt operator/(BigInt a,long b);

    friend BigInt operator/(char a,BigInt b);
    friend BigInt operator/(BigInt a,char b);

    friend BigInt operator%(std::string a,BigInt b);
    friend BigInt operator%(BigInt a,std::string b);

    friend BigInt operator%(int a,BigInt b);
    friend BigInt operator%(BigInt a,int b);

    friend BigInt operator%(short a,BigInt b);
    friend BigInt operator%(BigInt a,short b);

    friend BigInt operator%(long a,BigInt b);
    friend BigInt operator%(BigInt a,long b);

    friend BigInt operator%(char a,BigInt b);
    friend BigInt operator%(BigInt a,char b);
};

BigInt operator+(const BigInt& left, const BigInt& right);
BigInt operator-(const BigInt& left, const BigInt& right);
BigInt operator*(const BigInt& left, const BigInt& right);
BigInt operator/(const BigInt& left, const BigInt& right);
BigInt operator%(const BigInt& left, const BigInt& right);
std::ostream& operator<<(std::ostream &os, const BigInt& bigint); 
std::istream& operator>>(std::istream &is, BigInt& bigint);
bool operator>=(const BigInt& left, const BigInt& right);

