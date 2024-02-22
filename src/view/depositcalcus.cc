#include "depositcalcus.h"

#include "mainwindow.h"
#include "ui_depositcalcus.h"

DepositCalc::DepositCalc(QWidget *parent)
    : QDialog(parent), ui_(new Ui::DepositCalc) {
  ui_->setupUi(this);
  connect(ui_->result, SIGNAL(clicked()), this, SLOT(DeposCalc()));
}

DepositCalc::~DepositCalc() { delete ui_; }
void DepositCalc::DeposCalc() {
  bool ok1, ok2, ok3, ok4, ok5, ok6;
  int period_type = 0, kapital_type = 0, error_flag = 0;

  double summ_input = ui_->sum_input->toPlainText().toDouble(&ok1);
  double procent_input = ui_->procent_input->toPlainText().toDouble(&ok2);
  double time_input = ui_->time_month->toPlainText().toDouble(&ok3);
  double nalog_input = ui_->nalog_input->toPlainText().toDouble(&ok4);
  double izyatiya = ui_->izyatiya->toPlainText().toDouble(&ok5);
  double popolnenya = ui_->popolnenya->toPlainText().toDouble(&ok6);
  double depos_output = 0, nalog_out = 0, procent_out = 0;
  kapital_type = (ui_->kapital->currentText() == "Да" ? 1 : 0);
  period_type = (ui_->period_viplat->currentText() == "Раз в год" ? 12 : 1);
  if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6) {
    s21::ControllerDeposit deposit;
    s21::DepositData param{summ_input,  time_input,  procent_input,
                           nalog_input, period_type, popolnenya,
                           izyatiya,    kapital_type};
    deposit.DepositCalc(param);
    if (deposit.GetErr() == kCorect) {
      depos_output = deposit.GetRes().all_summ;
      nalog_out = deposit.GetRes().nalog_summ;
      procent_out = deposit.GetRes().procent_out;
      if (depos_output >= 0 && nalog_out >= 0 && procent_out >= 0) {
        ui_->deposit_sum_output->setText(QString::number(depos_output, 'f', 2));
        ui_->nalog_sum_output->setText(QString::number(nalog_out, 'f', 2));
        ui_->pocent_output->setText(QString::number(procent_out, 'f', 2));
      } else
        error_flag = 1;
    } else
      error_flag = 1;
  } else
    error_flag = 1;
  if (error_flag) {
    ui_->deposit_sum_output->setText("ERROR");
    ui_->nalog_sum_output->setText("ERROR");
    ui_->pocent_output->setText("ERROR");
  }
}
