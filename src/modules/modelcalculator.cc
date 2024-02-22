#include "modelcalculator.h"

#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
namespace s21 {
int ModelCalculator::priority(char p) {
  int res = 10;
  if (p == '(' || p == ')')
    res = 1;
  else if (isNumbers(p) || p == ' ')
    res = 0;
  else if (p == '-' || p == '+')
    res = 2;
  else if (p == '*' || p == '/' || p == '%' || p == '^')
    res = 3;
  else if ((p >= 'a' && p != 'e' && p <= 'j'))
    res = 4;
  return res;
}
bool ModelCalculator::isNumbers(char s) {
  return ((s >= '0' && s <= '9') || s == '.' || s == 'x' || s == 'e');
}
bool ModelCalculator::isOperations(char s) {
  return (2 <= priority(s) && priority(s) <= 4);
}
bool ModelCalculator::isExponent(char op, char exp) {
  return (op == '-' || op == '+') && exp == 'e';
}
void ModelCalculator::FunctionReduction() {
  std::string res_string;
  for (std::size_t i = 0; i < input_string_.size(); i++) {
    if (input_string_.compare(i, 4, "asin") == 0) {
      res_string.push_back('d');
      i += 3;
    } else if (input_string_.compare(i, 4, "acos") == 0) {
      res_string.push_back('j');
      i += 3;
    } else if (input_string_.compare(i, 4, "atan") == 0) {
      res_string.push_back('f');
      i += 3;
    } else if (input_string_.compare(i, 4, "sqrt") == 0) {
      res_string.push_back('g');
      i += 3;
    } else if (input_string_.compare(i, 2, "ln") == 0) {
      res_string.push_back('h');
      i++;
    } else if (input_string_.compare(i, 3, "log") == 0) {
      res_string.push_back('i');
      i += 2;
    } else if (input_string_.compare(i, 3, "mod") == 0) {
      res_string.push_back('%');
      i += 2;
    } else if (input_string_.compare(i, 3, "sin") == 0) {
      res_string.push_back('a');
      i += 2;
    } else if (input_string_.compare(i, 3, "cos") == 0) {
      res_string.push_back('b');
      i += 2;
    } else if (input_string_.compare(i, 3, "tan") == 0) {
      res_string.push_back('c');
      i += 2;
    } else {
      res_string.push_back(input_string_[i]);
    }
  }
  input_string_.swap(res_string);
}
void ModelCalculator::HandlingUnaryMinus() {
  std::string calc_st;
  for (std::size_t i = 0; i < input_string_.size(); i++) {
    if (input_string_[i] == '-' && i - 1 < input_string_.size() &&
        input_string_[i + 1] == '-') {
      calc_st.push_back('+');
      i++;
    } else if ((input_string_[i] == '+' || input_string_[i] == '-') &&
               (i == 0 || strchr("(+-", input_string_[i - 1]) != nullptr)) {
      calc_st.push_back('0');
      calc_st.push_back(input_string_[i]);
    } else
      calc_st.push_back(input_string_[i]);
  }
  input_string_.swap(calc_st);
}

void ModelCalculator::WritingANumberToPostfix(std::string &postfix,
                                              std::size_t &i) {
  while (isNumbers(input_string_[i]) ||
         isExponent(input_string_[i], input_string_[i - 1])) {
    postfix.push_back(input_string_[i++]);
  }
  postfix.push_back(' ');
  i--;
}
void ModelCalculator::PopClosedBracket(std::string &postfix) {
  while (!operations_.empty() && operations_.top().op_data != '(') {
    postfix += operations_.top().op_data;
    operations_.pop();
  }
  operations_.pop();
}
void ModelCalculator::AddingTheRestOfString(std::string &postfix,
                                            char input_string_sym) {
  while (!operations_.empty() &&
         priority(operations_.top().op_data) >= priority(input_string_sym)) {
    postfix += operations_.top().op_data;
    operations_.pop();
  }
  operations_.push({input_string_sym, priority(input_string_sym), 0});
}
void ModelCalculator::PopTheRestOfTheString(std::string &postfix) {
  while (!operations_.empty()) {
    postfix += operations_.top().op_data;
    operations_.pop();
  }
}

void ModelCalculator::FromInfixToPostfix() {
  std::string postfix;
  for (std::size_t i = 0; i < input_string_.size(); i++) {
    if (isNumbers(input_string_[i])) {
      WritingANumberToPostfix(postfix, i);
    } else if (input_string_[i] == '(') {
      operations_.push({input_string_[i], priority(input_string_[i]), 0});
    } else if (input_string_[i] == ')') {
      PopClosedBracket(postfix);
    } else {
      AddingTheRestOfString(postfix, input_string_[i]);
    }
  }
  PopTheRestOfTheString(postfix);
  input_string_.swap(postfix);
}
double ModelCalculator::CalculationOfSubstringsByFunctions(char s) {
  double num_calc1 = numbers_.top().num_data;
  double calc_res = num_calc1;
  numbers_.pop();
  if (s == 'a')
    calc_res = sin(num_calc1);
  else if (s == 'b')
    calc_res = cos(num_calc1);
  else if (s == 'c')
    calc_res = tan(num_calc1);
  else if (s == 'd')
    calc_res = asin(num_calc1);
  else if (s == 'j')
    calc_res = acos(num_calc1);
  else if (s == 'f')
    calc_res = atan(num_calc1);
  else if (s == 'g')
    calc_res = sqrt(num_calc1);
  else if (s == 'h')
    calc_res = log(num_calc1);
  else if (s == 'i')
    calc_res = log10(num_calc1);
  if (strchr("^%+-*/", s) && (!numbers_.empty())) {
    double num_calc2 = numbers_.top().num_data;
    numbers_.pop();
    if (s == '^')
      calc_res = powl(num_calc2, num_calc1);
    else if (s == '%')
      calc_res = fmod(num_calc2, num_calc1);
    else if (s == '+')
      calc_res = num_calc2 + num_calc1;
    else if (s == '-')
      calc_res = num_calc2 - num_calc1;
    else if (s == '*')
      calc_res = num_calc2 * num_calc1;
    else if (s == '/')
      calc_res = num_calc2 / num_calc1;
  }
  return calc_res;
}

void ModelCalculator::AllCalculation(double x) {
  for (std::size_t i = 0; i < input_string_.size(); i++) {
    double num = 0;
    if (input_string_[i] == 'x')
      numbers_.push({0, 0, x});

    else if (isNumbers(input_string_[i])) {
      try {
        num = std::stod(input_string_.substr(i));
      } catch (const std::out_of_range &e) {
        SetErr(kIncorect);
      }
      for (; isNumbers(input_string_[i]) ||
             isExponent(input_string_[i], input_string_[i - 1]);
           i++)
        ;
      numbers_.push({0, 0, num});
    } else if (isOperations(input_string_[i])) {
      numbers_.push(
          {0, 0, CalculationOfSubstringsByFunctions(input_string_[i])});
    }
  }
  result_ = numbers_.top().num_data;
}

void ModelCalculator::CheckErrorString() {
  for (std::size_t i = 0; i < input_string_.size(); i++) {
    if (priority(input_string_[i]) == 10 || priority(input_string_[i]) == 1) {
      SetErr(kIncorect);
      break;
    }
  }
}

void ModelCalculator::calculations(std::string input_string, double x) {
  input_string_ = input_string;
  result_ = 0;
  SetErr(kCorect);
  FunctionReduction();
  HandlingUnaryMinus();
  FromInfixToPostfix();
  CheckErrorString();
  if (GetErr() == kCorect) AllCalculation(x);
  if (std::isnan(result_) || std::isinf(result_)) SetErr(kIncorect);
}
}  // namespace s21
