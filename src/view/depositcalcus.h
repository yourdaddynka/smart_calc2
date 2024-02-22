#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H
#include <QDialog>

#include "../controllers/controllerdeposit.h"
namespace Ui {
class DepositCalc;
}

class DepositCalc : public QDialog {
  Q_OBJECT

 public:
  explicit DepositCalc(QWidget *parent = nullptr);
  ~DepositCalc();

 private:
  enum { kCorect = 0, kIncorect = 1 };
  Ui::DepositCalc *ui_;

 private slots:
  void DeposCalc();
};

#endif  // DEPOSIT_CALC_H
