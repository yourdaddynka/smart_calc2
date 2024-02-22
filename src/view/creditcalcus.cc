#include "creditcalcus.h"

#include "mainwindow.h"
#include "ui_creditcalcus.h"

CreditCalculator::CreditCalculator(QWidget *parent)
    : QDialog(parent), ui_(new Ui::CreditCalculator) {
  ui_->setupUi(this);
  connect(ui_->pushButton_result, SIGNAL(clicked()), this, SLOT(CreditCalc()));
}
CreditCalculator::~CreditCalculator() { delete ui_; }
void CreditCalculator::CreditCalc() {
  bool ok1, ok2, ok3, credit_type;
  double summ = ui_->summ_input->toPlainText().toDouble(&ok1);
  double pricent = ui_->pricent_input->toPlainText().toDouble(&ok2);
  double time = ui_->time_input->toPlainText().toDouble(&ok3);
  int flag = 0;
  credit_type =
      ((ui_->comboBox->currentText() == "аннуитентный") ? true : false);
  if (ok1 && ok2 && ok3) {
    s21::ControllerCredit controller;
    if (credit_type)
      controller.AnnCalc(summ, time, pricent);
    else
      controller.DiffCalc(summ, time, pricent);
    if (controller.GetErr() == kCorect) {
      double all_summ = controller.GetRes().result_all;
      double monthy_payment = controller.GetRes().result_monthly_payment;
      double monthy_one = controller.GetRes().result_monthly_one;
      double monthy_closed = controller.GetRes().result_monthly_close;
      ui_->All_sum->setText(QString::number(all_summ, 'f', 2));
      ui_->pereplata->setText(QString::number((all_summ - summ), 'f', 2));
      ui_->one_month_diff->setText(
          QString::number((credit_type ? 0 : monthy_one), 'f', 2));
      ui_->closed_month_diff->setText(
          QString::number((credit_type ? 0 : monthy_closed), 'f', 2));
      ui_->month_money->setText(QString::number(monthy_payment, 'f', 2));
    } else
      flag = 1;
  } else
    flag = 1;
  if (flag == 1) {
    ui_->All_sum->setText("ERROR");
    ui_->month_money->setText("ERROR");
    ui_->pereplata->setText("ERROR");
    ui_->one_month_diff->setText("ERROR");
    ui_->closed_month_diff->setText("ERROR");
  }
}
