#include <gtest/gtest.h>
#include "../controllers/controllercalculator.h"
#include "../controllers/controllerdeposit.h"

// using namespace s21;
TEST(ControllerCalculatorTest, Test0) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("5+1", 0);
  EXPECT_EQ(calculator.GetRes(), 6.0);
  EXPECT_EQ( calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test1) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("sqrt(16)+sin(1)", 0);
  EXPECT_NEAR(calculator.GetRes(), 4.84147, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test2) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("2^(2^(2^2))", 0);
  EXPECT_EQ(calculator.GetRes(), 65536);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test3) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("log(25)-acos(0.45)", 0);
  EXPECT_NEAR(calculator.GetRes(), 0.293909, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test4) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("(4*sin(2.9)+3*cos(0.47))/4", 0);
  EXPECT_NEAR(calculator.GetRes(), 0.907926, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test5) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("log(50)/acos(0.35)*atan(1.1)*sqrt(64)", 0);
  EXPECT_NEAR(calculator.GetRes(), 9.3318876, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test6) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
  "(sin(1.4)*cos(0.85)/tan(0.68))/(asin(0.38)/2*acos(0.45)^3-atan(0.54)*sqrt(49))+ln(5)*log(100)",0);
  EXPECT_NEAR(calculator.GetRes(), 2.98616, 1e-5);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test7) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
      "acos(0.25)^ln(2)-atan(1.5)*sqrt(16)*log(10)*sin(2.5)/(cos(1.1)/"
      "tan(1.9)*asin(0.4))",
      0);
  EXPECT_NEAR(calculator.GetRes(), 38.104222613215, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test8) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
      "((sin(1.7)*acos(0.3)-atan(0.35)*tan(1.5))^2)/sqrt(9)*(ln(7)+log(1000)/"
      "acos(0.6))",
      0);
  EXPECT_NEAR(calculator.GetRes(), 21.0601731, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test9) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
      "atan(0.75)*log(10)+sqrt(64)*sin(2)-cos(0.576)/acos(0.78)/"
      "5-2*ln(3)*asin(0.29)*tan(1.05)",
      0);
  EXPECT_NEAR(calculator.GetRes(), 6.5427849584, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test10) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
      "(cos(2.1)^2*sin(1.2)*atan(0.85)+acos(0.4))/"
      "log(250)*sqrt(169)+ln(5)*asin(0.55)*tan(0.5)",
      0);
  EXPECT_NEAR(calculator.GetRes(), 7.70412863, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test11) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
      "(sin(0.93)+acos(0.71)/atan(1.37)*tan(1.8))/"
      "(sqrt(25)*ln(10)*acos(0.3)-asin(0.6)*cos(1.1))",
      0);
  EXPECT_NEAR(calculator.GetRes(), -0.193212471, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test12) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("sin(cos(tan(ln(log(1234)+1)*2)/3)-4)", 0);
  EXPECT_NEAR(calculator.GetRes(), -0.134926396, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test13) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation(
      "(sin(0.93)+acos(0.71)/atan(1.37)*tan(1.8))/"
      "(sqrt(25)*ln(10)*acos(0.3)-asin(0.6)*cos(1.1))-sin(cos(tan(ln(log((cos("
      "2.1)^2*sin(1.2)*atan(0.85)+acos(0.4))/"
      "log(250)*sqrt(169)+ln(5)*asin(0.55)*tan(0.5))+1)*2)/3)-4)",
      0);
  EXPECT_NEAR(calculator.GetRes(), -0.565264615, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test14) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("1/0", 0);
  EXPECT_EQ(calculator.GetErr(), 1);
}

TEST(ControllerCalculatorTest, Test15) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("sqrt(-16)", 0);
  EXPECT_EQ(calculator.GetErr(), 1);
}

TEST(ControllerCalculatorTest, Test16) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("654+", 0);
  EXPECT_EQ(calculator.GetRes(), 654);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test17) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("(5+", 0);
  EXPECT_EQ(calculator.GetErr(), 1);
}

TEST(ControllerCalculatorTest, Test18) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("sin(x)", 1);
  EXPECT_NEAR(calculator.GetRes(), 0.841471, 1e-06);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test19) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("1e+06", 0);
  EXPECT_EQ(calculator.GetRes(), 1000000);
  EXPECT_EQ(calculator.GetErr(), 0);
}
TEST(ControllerCalculatorTest, Test20) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("3+1e+06", 0);
  EXPECT_EQ(calculator.GetRes(), 1e+06+3);
  EXPECT_EQ(calculator.GetErr(), 0);
}
TEST(ControllerCalculatorTest, Test21) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("INCORRECT", 0);
  EXPECT_EQ(calculator.GetErr(), 1);
}

TEST(ControllerCalculatorTest, Test22) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("1e+999", 0);
  EXPECT_EQ(calculator.GetErr(), 1);
}

TEST(ControllerCalculatorTest, Test23) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("1e-900", 0);
  EXPECT_EQ(calculator.GetErr(), 1);
}

TEST(ControllerCalculatorTest, Test24) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("-1-(-1-(-1-(-2-1)))", 0);
  EXPECT_EQ(calculator.GetRes(), 2);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test25) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("1--1", 0);
  EXPECT_EQ(calculator.GetRes(), 2);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test26) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("1-sin(1)", 0);
  EXPECT_NEAR(calculator.GetRes(), 0.158529, 1e-6);
  EXPECT_EQ(calculator.GetErr(), 0);
}

TEST(ControllerCalculatorTest, Test27) {
 s21:: ControllerCalculator calculator;
  calculator.Calculation("+5+5", 0);
  EXPECT_EQ(calculator.GetRes(), 10);
  EXPECT_EQ(calculator.GetErr(), 0);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}