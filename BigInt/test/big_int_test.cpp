#include <gtest/gtest.h>

#include "bigint.hpp"


TEST(LongNumberTest, ComparisonOperators) {
    biv::LongNumber a("123");
    biv::LongNumber b("456");
    biv::LongNumber c("123");
    biv::LongNumber d("-123");


    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a == b);

    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != c);


    EXPECT_TRUE(b > a);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(d < a);
}
TEST(LongNumberTest, ArithmeticOperations) {
    biv::LongNumber a("123");
    biv::LongNumber b("456");
    biv::LongNumber c("-100");
    biv:: LongNumber zero;


    EXPECT_EQ(a + b, biv::LongNumber("579"));
    EXPECT_EQ(a + c, biv::LongNumber("23"));
    EXPECT_EQ(a + zero, a);


    EXPECT_EQ(b - a, biv::LongNumber("333"));
    EXPECT_EQ(a - b, biv::LongNumber("-333"));
    EXPECT_EQ(zero - a, biv::LongNumber("-123"));


    EXPECT_EQ(a * b, biv::LongNumber("56088"));
    EXPECT_EQ(a * c, biv::LongNumber("-12300"));
    EXPECT_EQ(a * zero, zero);

   
    EXPECT_EQ(-a, biv::LongNumber("-123"));
    EXPECT_EQ(-zero, zero);
}
TEST(LongNumberTest, DivisionAndModulo) {
    biv::LongNumber a("1000");
    biv::LongNumber b("17");
    biv::LongNumber c("-3");

    
    EXPECT_EQ(a / b, biv::LongNumber("58"));
    EXPECT_EQ(b / c, biv::LongNumber("-5"));

 
    EXPECT_EQ(a % b, biv::LongNumber("14"));
    EXPECT_EQ(b % c, biv::LongNumber("2"));
}

int main(int argc,char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
