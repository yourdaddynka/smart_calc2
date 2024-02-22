#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QtCore>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui_->pushButton_dot, SIGNAL(clicked()), this, SLOT(dot_clicked()));

  connect(ui_->pushButton_AC, SIGNAL(clicked()), this,
          SLOT(on_pushButton_AC_clicked()));

  connect(ui_->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_sum, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_del, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_ln, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui_->pushButton_log, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui_->pushButton_closed_bracket, SIGNAL(clicked()), this,
          SLOT(math_operations()));

  connect(ui_->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui_->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui_->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui_->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui_->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui_->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));

  connect(ui_->pushButton_C, SIGNAL(clicked()), this, SLOT(clean_one()));
  connect(ui_->pushButton_exp, SIGNAL(clicked()), this, SLOT(exponent()));
}
MainWindow::~MainWindow() { delete ui_; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui_->result_show->toPlainText();
  if ((!new_label.isEmpty() && new_label.back() != ')' &&
       new_label.back() != 'x') ||
      new_label.isEmpty()) {
    ui_->result_show->setText(new_label + button->text());
  }
}

void MainWindow::dot_clicked() {
  int flag = 0;
  QString dot_st = ui_->result_show->toPlainText();
  if (!dot_st.isEmpty() > 0) {
    QString str = dot_st;
    QChar last_char = dot_st.back();
    for (int i = 0; i < dot_st.length(); i++) {
      if (str[i] == '.')
        flag = 1;
      else if (!str[i].isDigit() && str[i] != '.' && str[i] != 'x')
        flag = 0;
      if (!last_char.isDigit()) flag = 1;
    }
    if (flag == 0) ui_->result_show->setText(dot_st + ".");
  }
}

void MainWindow::math_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString math_op_st = ui_->result_show->toPlainText();
  int openBr = math_op_st.count('(');
  int closedBr = math_op_st.count(')');
  QString but = button->text();
  if (!math_op_st.isEmpty()) {
    QChar last_char = math_op_st.back();
    if (last_char == 'e' && (but == "+" || but == "-")) {
      math_op_st += but;
    } else if (last_char.isDigit() || last_char == ')' || last_char == 'x') {
      if (but == "aˆb")
        math_op_st += "^";
      else if (but == "÷")
        math_op_st += "/";
      else if (but == "-" || (but == ')' && openBr > closedBr) || but == "+" ||
               but == "*" || but == "%")
        math_op_st += but;
    } else if ((last_char.isDigit() || last_char == ')' || last_char == 'x' ||
                last_char == '(') &&
               but == "-")
      math_op_st += but;
    else if (!last_char.isDigit() && last_char != ')' && last_char != '.' &&
             last_char != 'x' && !math_op_st.endsWith("e-") &&
             !math_op_st.endsWith("e-")) {
      if ((but == "sqrt" || but == "ln" || but == "log"))
        math_op_st += but + "(";
      else if (but == '(' && !math_op_st.endsWith("e+") &&
               !math_op_st.endsWith("e-") && !math_op_st.endsWith("e")) {
        math_op_st += but;
      }
    }
  } else {
    if (but == "(" || but == '-')
      math_op_st += but;
    else if (but == "log" || but == "ln" || but == "sqrt")
      math_op_st += but + "(";
  }
  ui_->result_show->setText(math_op_st);
}

void MainWindow::trigon_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString trig_op_st = ui_->result_show->toPlainText();
  if ((!trig_op_st.isEmpty() && !trig_op_st.back().isDigit() &&
       trig_op_st.back() != ')' && trig_op_st.back() != 'x' &&
       trig_op_st.back() != '.' && !trig_op_st.endsWith("e+") &&
       !trig_op_st.endsWith("e-")) ||
      trig_op_st.isEmpty())
    ui_->result_show->setText(trig_op_st + button->text() + "(");
}

void MainWindow::on_pushButton_AC_clicked() { ui_->result_show->clear(); }

void MainWindow::on_pushButton_X_clicked() {
  QString x_string = ui_->result_show->toPlainText();
  if ((!x_string.isEmpty() && !x_string.endsWith("e-") &&
       !x_string.endsWith("e+") && !x_string.back().isDigit() &&
       x_string.back() != '.' && x_string.back() != ')' &&
       x_string.back() != 'x') ||
      x_string.isEmpty())
    ui_->result_show->setText(x_string += 'x');
}

void MainWindow::on_pushButton_phony_clicked() {
  QString x_label_st =
      ui_->label_x->toPlainText().isEmpty() ? "0" : ui_->label_x->toPlainText();
  ui_->label_x->setPlainText(x_label_st);
  QString input_string = ui_->result_show->toPlainText().isEmpty()
                             ? "0"
                             : ui_->result_show->toPlainText();
  bool ok;
  double x_label = x_label_st.toDouble(&ok);
  int BrSum = input_string.count('(') - input_string.count(')');
  if (!input_string.isEmpty() && input_string.back() != '(')
    for (int i = 0; i < BrSum && BrSum >= 0; i++) {
      input_string += ")";
    }
  if (ok && !input_string.isEmpty() && input_string.back() != '(') {
    s21::ControllerCalculator calculator;
    calculator.Calculation(input_string.toStdString(), x_label);
    if (calculator.GetErr() == kIncorect)
      ui_->result_show->setText("INCORRECT");
    else {
      QString result = QString::number(calculator.GetRes(), 'f', 6);
      while (result.endsWith('0')) {
        result.chop(1);
      }
      if (result.endsWith('.')) {
        result.chop(1);
      }
      ui_->result_show->setText(result);
    }
  } else
    ui_->result_show->setText("INCORRECT");
}

void MainWindow::exponent() {
  QString exponent = ui_->result_show->toPlainText();
  if (!exponent.isEmpty() && exponent.back().isDigit())
    ui_->result_show->setText(exponent + 'e');
}

void MainWindow::clean_one() {
  QString clean_string = ui_->result_show->toPlainText();
  if (!clean_string.isEmpty() &&
      (clean_string.back().isDigit() || clean_string.back() == '.' ||
       clean_string.back() == 'x'))
    clean_string.chop(1);
  else
    while (!clean_string.isEmpty() &&
           (!clean_string.back().isDigit() || clean_string.back() == '.' ||
            clean_string.back() == 'x')) {
      clean_string.chop(1);
    }
  ui_->result_show->setText(clean_string);
}

void MainWindow::on_pushButton_graph_clicked() {
  graphs_ = new Graps(this);
  if (graphs_->isVisible())
    graphs_->close();
  else
    graphs_->show();
  connect(this, &MainWindow::signal, graphs_, &Graps::slot);
  QString currentString = ui_->result_show->toPlainText();
  emit signal(currentString);
}

void MainWindow::on_pushButton_deposit_clicked() {
  de_calc_ = new DepositCalc(this);
  de_calc_->show();
}

void MainWindow::on_pushButton_credit_clicked() {
  cr_calc_ = new CreditCalculator(this);
  cr_calc_->show();
}
