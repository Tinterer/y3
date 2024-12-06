#include <gtest/gtest.h>
#include "cls.h"


TEST(BigIntTests, DefaultConstructor) 
{
    BigInt num;

    EXPECT_EQ(std::string(num), "0"); 
}


TEST(BigIntTests, BigIntConstructor) 
{
    BigInt num("-1111111111111111111111111111111111111");
    BigInt test(num);

    EXPECT_EQ(std::string(test), "-1111111111111111111111111111111111111");
}


TEST(BigIntTests, StringConstructor) 
{
    BigInt num("1111111111111111111111111111111111111");
    EXPECT_EQ(std::string(num), "1111111111111111111111111111111111111");

    BigInt num2("-1111111111111111111111111111111111111");
    EXPECT_EQ(std::string(num2), "-1111111111111111111111111111111111111");
}


TEST(BigIntTests, long_IntConstructor) 
{
    BigInt num(12345678900);
    EXPECT_EQ(std::string(num), "12345678900");

    BigInt num2(-12345678900);
    EXPECT_EQ(std::string(num2), "-12345678900");

}


TEST(BigIntTests, Addition) 
{
    BigInt num1("12312312312312312331233");
    BigInt num2("12312312312312312312312");
    BigInt result = num1 + num2;
    EXPECT_EQ(std::string(result), "24624624624624624643545");

    BigInt num3("-12312312312312312331233");
    BigInt num4("12312312312312312312312");
    result = num3 + num4;
    EXPECT_EQ(std::string(result), "-18921");

    BigInt num5("12312312312312312331233");
    BigInt num6("-12312312312312312312312");
    result = num5 + num6;
    EXPECT_EQ(std::string(result), "18921");

    BigInt num7("-12312312312312312331233");
    BigInt num8("-12312312312312312312312");
    result = num7 + num8;
    EXPECT_EQ(std::string(result), "-24624624624624624643545");

    BigInt num9("-123456");

    result = num9 + static_cast<int>(123455);
    EXPECT_EQ(std::string(result), "-1");

    result = static_cast<int>(123455) + num9;
    EXPECT_EQ(std::string(result), "-1");

    result = num9 + static_cast<short>(123455);
    EXPECT_EQ(std::string(result), "-1");

    result = static_cast<short>(123455) + num9;
    EXPECT_EQ(std::string(result), "-1");

    result = num9 +static_cast<long>(1000000);
    EXPECT_EQ(std::string(result), "876544");

    result = static_cast<long>(1000000) + num9;
    EXPECT_EQ(std::string(result), "876544");
}


TEST(BigIntTests, Subtraction) 
{
    BigInt num1("12312312312312312331233");
    BigInt num2("12312312312312312312312");
    BigInt result = num1 - num2;
    EXPECT_EQ(std::string(result), "18921");

    BigInt num3("-12312312312312312331233");
    BigInt num4("12312312312312312312312");
    result = num3 - num4;
    EXPECT_EQ(std::string(result), "-24624624624624624643545");

    BigInt num5("12312312312312312331233");
    BigInt num6("-12312312312312312312312");
    result = num5 - num6;
    EXPECT_EQ(std::string(result), "24624624624624624643545");

    BigInt num7("-12312312312312312331233");
    BigInt num8("-12312312312312312312312");
    result = num7 - num8;
    EXPECT_EQ(std::string(result), "-18921");

    BigInt num9("-100");

    result = num9 - static_cast<int>(100);
    EXPECT_EQ(std::string(result), "-200");

    result = static_cast<int>(100) - num9;
    EXPECT_EQ(std::string(result), "200");

    result = num9 - static_cast<short>(100);
    EXPECT_EQ(std::string(result), "-200");

    result = static_cast<short>(100) - num9;
    EXPECT_EQ(std::string(result), "200");

    result = num9 - static_cast<long>(100);
    EXPECT_EQ(std::string(result), "-200");

    result = static_cast<long>(100) - num9;
    EXPECT_EQ(std::string(result), "200");
}


TEST(BigIntTests, Multiplication)
{
    BigInt num1("123");
    BigInt num2("456");
    BigInt result = num1 * num2;
    EXPECT_EQ(std::string(result), "56088");

    BigInt num3("-123");
    BigInt num4("456");
    result = num3 * num4;
    EXPECT_EQ(std::string(result), "-56088");

    BigInt num5("123");
    BigInt num6("-456");
    result = num5 * num6;
    EXPECT_EQ(std::string(result), "-56088");

    BigInt num7("-123");
    BigInt num8("-456");
    result = num7 * num8;
    EXPECT_EQ(std::string(result), "56088");

    BigInt num9("-121212");

    result = num9 * static_cast<int>(123);
    EXPECT_EQ(std::string(result), "-14909076");

    result = static_cast<int>(123) * num9;
    EXPECT_EQ(std::string(result), "-14909076");

    result = num9 * static_cast<short>(123);
    EXPECT_EQ(std::string(result), "-14909076");

    result = static_cast<short>(123) * num9;
    EXPECT_EQ(std::string(result), "-14909076");

    result = num9 * static_cast<long>(123);
    EXPECT_EQ(std::string(result), "-14909076");

    result = static_cast<long>(123) * num9;
    EXPECT_EQ(std::string(result), "-14909076");
}


TEST(BigIntTests, Division) 
{
    BigInt num1("10005");
    BigInt num2("250");
    BigInt result = num1 / num2;
    EXPECT_EQ(std::string(result), "40");

    BigInt num3("10005");
    BigInt num4("-250");
    result = num3 / num4;
    EXPECT_EQ(std::string(result), "-40");

    BigInt num5("-10005");
    BigInt num6("250");
    result = num5 / num6;
    EXPECT_EQ(std::string(result), "-40");

    BigInt num7("-10005");
    BigInt num8("-250");
    result = num7 / num8;
    EXPECT_EQ(std::string(result), "40");

    BigInt num9("-123123");

    result = num9 / static_cast<int>(123000);
    EXPECT_EQ(std::string(result), "-1");

    result = static_cast<int>(123000) / num9;
    EXPECT_EQ(std::string(result), "0");

    result = num9 / static_cast<short>(123000);
    EXPECT_EQ(std::string(result), "-1");

    result = static_cast<short>(123000) / num9;
    EXPECT_EQ(std::string(result), "0");

    result = num9 / static_cast<long>(123110000);
    EXPECT_EQ(std::string(result), "0");

    result = static_cast<long>(123110000) / num9;
    EXPECT_EQ(std::string(result), "-999");
}


TEST(BigIntTests, OstOtDel) 
{
    BigInt num1("123123");
    BigInt num2("123000");
    BigInt result = num1 % num2;
    EXPECT_EQ(std::string(result), "123");

    BigInt num3("123123");
    BigInt num4("-123000");
    result = num3 % num4;
    EXPECT_EQ(std::string(result), "123");

    BigInt num5("-123123");
    BigInt num6("123000");
    result = num5 % num6;
    EXPECT_EQ(std::string(result), "-123");

    BigInt num7("-123123");
    BigInt num8("-123000");
    result = num7 % num8;
    EXPECT_EQ(std::string(result), "-123");

    BigInt num9("-123456");

    result = num9 % static_cast<int>(123455);
    EXPECT_EQ(std::string(result), "-1");

    result = static_cast<int>(123455) % num9;
    EXPECT_EQ(std::string(result), "123455");

    result = num9 % static_cast<short>(123455);
    EXPECT_EQ(std::string(result), "-1");

    result = static_cast<short>(123455) % num9;
    EXPECT_EQ(std::string(result), "123455");

    result = num9 % static_cast<long>(12311000);
    EXPECT_EQ(std::string(result), "-123456");

    result = static_cast<long>(123456789) % num9;
    EXPECT_EQ(std::string(result), "789");
}


TEST(BigIntTests, GCD) 
{
    BigInt num1("10000");
    BigInt num2("250");
    BigInt result1 = num1.gcd(num2);
    EXPECT_EQ(std::string(result1), "250");

    BigInt num3("10000");
    BigInt num4("-250");
    BigInt result2 = num3.gcd(num4);
    EXPECT_EQ(std::string(result2), "250");

    BigInt num5("-10000");
    BigInt num6("250");
    BigInt result3 = num5.gcd(num6);
    EXPECT_EQ(std::string(result3), "250");

    BigInt num7("-10000");
    BigInt num8("-250");
    BigInt result4 = num7.gcd(num8);
    EXPECT_EQ(std::string(result4), "250");
}


TEST(BigIntTests, LCM) 
{
    BigInt num1("124");
    BigInt num2("7");
    BigInt result1 = num1.lcm(num2);
    EXPECT_EQ(std::string(result1), "868");

    BigInt num3("124");
    BigInt num4("-7");
    BigInt result2 = num3.lcm(num4);
    EXPECT_EQ(std::string(result2), "868");

    BigInt num5("-124");
    BigInt num6("7");
    BigInt result3 = num5.lcm(num6);
    EXPECT_EQ(std::string(result3), "868");

    BigInt num7("-124");
    BigInt num8("-7");
    BigInt result4 = num7.lcm(num8);
    EXPECT_EQ(std::string(result4), "868");
}


TEST(BigIntTests, TypeConversion) 
{
    BigInt num("11111");

    int i = num;
    EXPECT_EQ(i, 11111);

    short sh = num;
    EXPECT_EQ(sh, 11111);

    long l = num;
    EXPECT_EQ(l, 11111);

    std::string s = num;
    EXPECT_EQ(s, "11111");
    
}


TEST(BigIntTests, OperationWithZero) 
{
    BigInt num1("0");
    BigInt num2("0");
    
    BigInt result = num1 + num2;
    EXPECT_EQ(std::string(result), "0");

    result = num1 - num2;
    EXPECT_EQ(std::string(result), "0");

    result = num1 * num2;
    EXPECT_EQ(std::string(result), "0");

    EXPECT_THROW(num1 / num2, std::runtime_error("Division by zero is not allowed.")); 
}


TEST(BigIntTests, OutputOperator) {
    BigInt num("1111111111111111111");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "1111111111111111111");
}


TEST(BigIntTests, InputOperator) {
    std::stringstream ss("1111111111111111111");
    BigInt num;
    ss >> num;  
    std::stringstream result;
    result << num;
    EXPECT_EQ(result.str(), "1111111111111111111");
}


TEST(BigIntTests, RavnoOperator) {
    BigInt num1("1111111111111111111");
    BigInt num2 = num1;  
    EXPECT_EQ(std::string(num2), "1111111111111111111");
}
