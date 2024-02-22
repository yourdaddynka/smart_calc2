#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>

#include <QMainWindow>

#include "../controllers/controllercalculator.h"
#include "creditcalcus.h"
#include "depositcalcus.h"
#include "graphsbuild.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 signals:
  void signal(QString a);

 private:
  enum { kCorect = 0, kIncorect = 1 };
  Ui::MainWindow *ui_;
  Graps *graphs_;
  CreditCalculator *cr_calc_;
  DepositCalc *de_calc_;

 private slots:
  void digits_numbers();
  void dot_clicked();
  void on_pushButton_phony_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_X_clicked();
  void math_operations();
  void trigon_operations();
  void on_pushButton_graph_clicked();
  void on_pushButton_deposit_clicked();
  void on_pushButton_credit_clicked();
  void clean_one();
  void exponent();
};
#endif  // MAINWINDOW_H
