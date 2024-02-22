#ifndef GRAPHSBUILD_H
#define GRAPHSBUILD_H

#include <qcustomplot.h>

#include <QDialog>
#include <QVector>

namespace Ui {
class Graps;
}

class Graps : public QDialog {
  Q_OBJECT

 public:
  explicit Graps(QWidget *parent = nullptr);
  ~Graps();

 private:
  enum { kCorect = 0, kIncorect = 1 };
  Ui::Graps *ui_;
  QVector<double> x_, y_;
  QString m_a_;

 public slots:
  void slot(QString a);

  void BuildGraphUsingButton();
};

#endif  // GRAPHSBUILD_H
