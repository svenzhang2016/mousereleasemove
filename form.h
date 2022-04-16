#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

 public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

 protected:
  void paintEvent(QPaintEvent *e);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  virtual bool eventFilter(QObject *watched, QEvent *event);

 private:
  Ui::Form *ui;
  bool m_bDrag{false};
  QPoint mouseStartPoint;
  QPoint windowTopLeftPoint;
  bool m_PosSetted{false};
  int timerId;
};

#endif  // FORM_H
