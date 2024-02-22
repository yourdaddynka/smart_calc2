#ifndef CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELCALCULATOR_H_
#define CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELCALCULATOR_H_
#include <stack>
#include <string>
typedef struct {
  char op_data;
  int priority;
  double num_data;
} StackToken;

namespace s21 {
class ModelCalculator {
 public:
  /* constructors */
  ModelCalculator() = default;
  ~ModelCalculator() = default;
  /* Get */
  double GetRes() { return result_; };
  int GetErr() { return error_; };
  /* calculator */
  void calculations(std::string input_string, double x);

 private:
  /* methods */
  void SetErr(int error) { error_ = error; };
  void FunctionReduction();
  void HandlingUnaryMinus();
  void FromInfixToPostfix();
  void AllCalculation(double x);
  /*help methods */
  void WritingANumberToPostfix(std::string &postfix, std::size_t &i);
  void PopClosedBracket(std::string &postfix);
  void AddingTheRestOfString(std::string &postfix, char input_string_sym);
  void PopTheRestOfTheString(std::string &postfix);
  double CalculationOfSubstringsByFunctions(char s);
  void CheckErrorString();
  int priority(char p);
  bool isNumbers(char s);
  bool isOperations(char s);
  bool isExponent(char op, char exp);

  /* objects */

  enum { kCorect = 0, kIncorect = 1 };
  double result_;
  int error_;
  std::stack<StackToken> operations_;
  std::stack<StackToken> numbers_;
  std::string input_string_;
};
}  // namespace s21
#endif  // CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELCALCULATOR_H_