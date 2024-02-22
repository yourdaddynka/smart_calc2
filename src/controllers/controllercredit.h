#ifndef CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERCREDIT_H_
#define CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERCREDIT_H_
#include "../modules/modelcredit.h"
namespace s21 {
class ControllerCredit {
 public:
  /* constructors */
  ControllerCredit() = default;
  ~ControllerCredit() = default;
  /* Get/Set */
  ResultParametrs GetRes() { return model_credit_.GetResAll(); }
  int GetErr() { return model_credit_.GetErr(); }
  /* calculator */
  void AnnCalc(double summ, int time, double procent) {
    model_credit_.CreditAnnCalc(summ, time, procent);
  }
  void DiffCalc(double summ, int time, double procent) {
    model_credit_.CreditDiffCalc(summ, time, procent);
  }

 private:
  ModelCredit model_credit_;
};
}  // namespace s21
#endif  // CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERCREDIT_H_