#include "graphsbuild.h"

#include "mainwindow.h"
#include "ui_graphsbuild.h"
Graps::Graps(QWidget *parent) : QDialog(parent), ui_(new Ui::Graps) {
  ui_->setupUi(this);
}
Graps::~Graps() { delete ui_; }
void Graps::slot(QString a) {
  m_a_ = a;
  connect(ui_->Plot, &QPushButton::clicked, this,
          &Graps::BuildGraphUsingButton);
}
void Graps::BuildGraphUsingButton() {
  bool ok1, ok2, ok3, ok4;
  double Xmin = ui_->Xmin->toPlainText().toDouble(&ok1);
  double Xmax = ui_->Xmax->toPlainText().toDouble(&ok2);
  double Ymin = ui_->Ymin->toPlainText().toDouble(&ok3);
  double Ymax = ui_->Ymax->toPlainText().toDouble(&ok4);
  int flag = 0;
  if (ok1 && ok2 && ok3 && ok4) {
    if (Xmin >= Xmax) {
      Xmin = -10;
      Xmax = 10;
      ui_->Xmin->setPlainText(QString::number(Xmin));
      ui_->Xmax->setPlainText(QString::number(Xmin));
    }
    if (Ymin >= Ymax) {
      Ymin = -10;
      Ymax = 10;
      ui_->Ymin->setPlainText(QString::number(Ymin));
      ui_->Ymax->setPlainText(QString::number(Ymax));
    }
    ui_->widget->xAxis->setRange(Xmin, Xmax);
    ui_->widget->yAxis->setRange(Ymin, Ymax);
    x_.clear();
    y_.clear();
    s21::ControllerCalculator graphCalc;
    for (int i = -100000; i < 100000; i++) {
      graphCalc.Calculation((m_a_.isEmpty() ? "0" : m_a_).toStdString(),
                            i * 0.1);
      if (graphCalc.GetErr() != kIncorect) {
        x_.push_back(i * 0.1);
        y_.push_back(graphCalc.GetRes());
      }
    }
    ui_->widget->addGraph();
    ui_->widget->graph(0)->setData(x_, y_);
    ui_->widget->replot();
    ui_->widget->setInteraction(QCP::iRangeZoom, true);
    ui_->widget->setInteraction(QCP::iRangeDrag, true);
  } else
    flag = 1;
  if (flag == 1) {
    ui_->Xmin->setPlainText("ERROR");
    ui_->Xmax->setPlainText("ERROR");
    ui_->Ymin->setPlainText("ERROR");
    ui_->Ymax->setPlainText("ERROR");
  }
}
