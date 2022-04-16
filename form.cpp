#include "form.h"

#include <QPaintEvent>
#include <QPainter>
#include <QStyleOption>

#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  ui->setupUi(this);
  setMouseTracking(true);
  qApp->installEventFilter(this);
}

Form::~Form() { delete ui; }

void Form::paintEvent(QPaintEvent *) {
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Form::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    //    m_bDrag = true;
  }
}

void Form::mouseMoveEvent(QMouseEvent *event) {
  if (m_bDrag) {
    QPoint distance = event->globalPos() - mouseStartPoint;
    this->move(windowTopLeftPoint + distance);
  }
}

void Form::mouseReleaseEvent(QMouseEvent *event) {
  m_bDrag = !m_bDrag;
  mouseStartPoint = event->globalPos();
  windowTopLeftPoint = this->frameGeometry().topLeft();
}

bool Form::eventFilter(QObject *watched, QEvent *event) {
  if (event->type() == QEvent::MouseMove) {
    if (watched != nullptr && watched != this && m_bDrag) {
      QMouseEvent *me = dynamic_cast<QMouseEvent *>(event);
      QPoint distance = me->globalPos() - mouseStartPoint;
      this->move(windowTopLeftPoint + distance);
    }
  }
  return QObject::eventFilter(watched, event);
}
