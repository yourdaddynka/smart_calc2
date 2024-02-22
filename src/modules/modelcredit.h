#ifndef CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELCREDIT_H_
#define CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELCREDIT_H_
namespace s21 {
struct ResultParametrs {
  double result_all;
  double result_monthly_payment;
  double result_monthly_one;
  double result_monthly_close;
};
class ModelCredit {
 public:
  /* constructors */
  ModelCredit() = default;
  ~ModelCredit() = default;
  /* Get */
  ResultParametrs GetResAll() { return result_; }
  int GetErr() { return error_; }
  /* methods */
  void CreditAnnCalc(double summ, int time, double procent);
  void CreditDiffCalc(double summ, int time, double procent);

 private:
  void SetErr(int error) { error_ = error; }

  enum { kCorect = 0, kIncorect = 1 };
  int error_;
  ResultParametrs result_;
};
}  // namespace s21
#endif  // CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELCREDIT_H_