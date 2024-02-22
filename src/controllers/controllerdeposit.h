#ifndef CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERDEPOSIT_H_
#define CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERDEPOSIT_H_
#include "../modules/modeldeposit.h"
namespace s21 {
class ControllerDeposit {
 public:
  /* constructors */
  ControllerDeposit() = default;
  ~ControllerDeposit() = default;
  /* Get/Set */
  ResultDeposit GetRes() { return model_deposit_.GetResAll(); }
  DepositData deposit_data;
  int GetErr() { return model_deposit_.GetErr(); }
  /* calculator */
  void DepositCalc(DepositData deposit_data) {
    model_deposit_.DepositCalc(deposit_data);
  }

 private:
  ModelDeposit model_deposit_;
};
}  // namespace s21
#endif  // CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERDEPOSIT_H_