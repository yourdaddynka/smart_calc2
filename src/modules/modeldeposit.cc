#include "modeldeposit.h"

#include <cmath>
namespace s21 {
void ModelDeposit::DepositCalc(const DepositData& param) {
  if (param.summa < 0 || param.time < 0 || param.procent < 0 ||
      param.nalog_procent < 0 || param.periodichnost < 0 ||
      param.popolnenya < 0 || param.izyatia < 0) {
    SetErr(kIncorect);
    return;
  } else {
    SetErr(kCorect);
    double summ_buff = param.summa;
    for (int i = 0; i < param.time; i++) {
      double month_summ = 0;
      if (param.periodichnost == 1) {
        month_summ = summ_buff * param.procent * 0.01 / 12;
      } else if (param.periodichnost == 12 && i % 11 == 0 && i > 0) {
        month_summ = summ_buff * param.procent * 0.01;
      }
      summ_buff = summ_buff + param.popolnenya - param.izyatia;
      if (param.kapitaliz == 1) {
        summ_buff += month_summ;
      }
      result_.procent_out += month_summ;
    }
    result_.nalog_summ = result_.procent_out * param.nalog_procent * 0.01;
    result_.all_summ = param.summa + result_.procent_out - result_.nalog_summ +
                       ((param.popolnenya - param.izyatia) * param.time);
  }
}
}  // namespace s21
