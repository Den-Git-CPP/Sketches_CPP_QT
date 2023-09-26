#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenuShow(QPoint)));

    ui->setupUi(this);
   }

Widget::~Widget()
{
    delete ui;
}

void Widget::customContextMenuShow(const QPoint &pos)
{
    QPoint globalPos = mapToGlobal(pos);
    QMenu menu(this);
    QAction* One_Action = menu.addAction(
            QIcon(),
            QString("One_Action")
                );
    QAction* Two_Action = menu.addAction(
            QIcon(),
            QString("Two_Action")
                );
    menu.addSeparator();
    QAction* Three_Action = menu.addAction(
            QIcon(),
            QString("Three_Action")
                );

    QAction* selected_action = menu.exec(globalPos);
    if(selected_action) {
      if(selected_action == One_Action)
      {
        // do something for first action
       }
      else if(selected_action == Two_Action)
      {
        // do something for second action
      }
      else if(selected_action == Three_Action)
      {
        // do something for second action
      }
     }


}

