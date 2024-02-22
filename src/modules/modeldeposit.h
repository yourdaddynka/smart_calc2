#ifndef CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELDEPOSIT_H_
#define CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELDEPOSIT_H_
namespace s21 {
struct ResultDeposit {
  double procent_out;
  double nalog_summ;
  double all_summ;
};
struct DepositData {
  double summa;
  double time;
  double procent;
  double nalog_procent;
  int periodichnost;
  double popolnenya;
  double izyatia;
  int kapitaliz;
};
class ModelDeposit {
  enum { kCorect = 0, kIncorect = 1 };

 public:
  /* constructors */
  ModelDeposit() = default;
  ~ModelDeposit() = default;
  /* Get */

  ResultDeposit GetResAll() { return result_; }
  int GetErr() { return error_; }
  /* credit */
  void DepositCalc(const DepositData& param);

 private:
  void SetErr(int error) { error_ = error; }

  int error_;
  ResultDeposit result_;
};
}  // namespace s21
#endif  // CPP3_S21_SMARTCALC_v2_0_SRC_MODULES_MODELDEPOSIT_H_