#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>

#include "../controllers/controllercredit.h"
namespace Ui {
class CreditCalculator;
}

class CreditCalculator : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalculator(QWidget *parent = nullptr);
  ~CreditCalculator();

 private slots:
  void CreditCalc();

 private:
  enum { kCorect = 0, kIncorect = 1 };
  Ui::CreditCalculator *ui_;
};

#endif  // CREDIT_CALC_H
