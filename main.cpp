#include "cls.h"
#include<iostream>

int main() {
    BigInt num, num0;

    std::cout << "Enter two numbers:" << std::endl;
    
    if (!(std::cin >> num >> num0)) {
        std::cerr << "Error: Input failed." << std::endl;
        return 1;
    }
    
    std::cout << num << " + " << num0 << " = " << num + num0 << std::endl;
    std::cout << num << " - " << num0 << " = " << num - num0 << std::endl;
    std::cout << num << " * " << num0 << " = " << num * num0 << std::endl;
    std::cout << num << " / " << num0 << " = " << num / num0 << std::endl;
    std::cout << num << " % " << num0 << " = " << num % num0 << std::endl;
    std::cout << num << " % " << num0 << " = " << num % num0 << std::endl;
    std::cout << "НОД(" << num << ", " << num0 << ")" << " = " << num.gcd(num0) << std::endl;
    std::cout << "НОК(" << num << ", " << num0 << ")" << " = " << num.lcm(num0) << std::endl;
    return 0;
}

