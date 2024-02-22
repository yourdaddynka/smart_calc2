#ifndef CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERCALCULATOR_H_
#define CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERCALCULATOR_H_
#include "../modules/modelcalculator.h"
namespace s21 {
class ControllerCalculator {
 public:
  /* constructors */
  ControllerCalculator() = default;
  ~ControllerCalculator() = default;
  /* Get/Set */
  double GetRes() { return model_calc_.GetRes(); }
  int GetErr() { return model_calc_.GetErr(); }
  /* calculator */
  void Calculation(std::string input_string, double x) {
    model_calc_.calculations(input_string, x);
  }

 private:
  ModelCalculator model_calc_;
};
}  // namespace s21
#endif  // CPP3_S21_SMARTCALC_v2_0_SRC_CONTROLLERS_CONTROLLERCALCULATOR_H_