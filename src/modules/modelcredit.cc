
#include "modelcredit.h"

#include <cmath>
namespace s21 {
void ModelCredit::CreditAnnCalc(double summ, int time, double procent) {
  if (summ <= 0 || time <= 0 || procent <= 0) {
    SetErr(kIncorect);
    return;
  } else {
    SetErr(kCorect);
    double proc = procent / 100 / 12;
    result_.result_monthly_payment = summ * (proc / (1 - pow(1 + proc, -time)));
    for (int i = 0; i < time;
         i++, result_.result_all += (result_.result_monthly_payment))
      ;
  }
}

void ModelCredit::CreditDiffCalc(double summ, int time, double procent) {
  if (summ <= 0 || time <= 0 || procent <= 0) {
    SetErr(kIncorect);
    return;
  } else {
    SetErr(kCorect);
    double proc = procent / 100 / 12;
    double diff_pay = 0;
    for (int i = 0; i < time; i++) {
      result_.result_all += diff_pay =
          (summ / time) + ((summ - i * (summ / time)) * proc);
      if (i == 0) result_.result_monthly_one = diff_pay;
      if (i == time - 1) result_.result_monthly_close = diff_pay;
    }
  }
}
};  // namespace s21
