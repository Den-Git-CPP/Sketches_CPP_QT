#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_pushButton_clicked()
{
    QXmlStreamReader xmlReader;
    xmlReader.addData(ui->textBrowser->toPlainText());

    ui->treeWidget->clear();

    QStack<QTreeWidgetItem*> widgetStack;

    while(!xmlReader.atEnd()){
        if(xmlReader.isStartElement()){
            QStringList sl;
            sl<<xmlReader.name().toString();
            QTreeWidgetItem *item = new QTreeWidgetItem(sl);
            if(widgetStack.count()==0){
                ui->treeWidget->addTopLevelItem(item);
            } else{
                widgetStack.top()->addChild(item);
            }
            widgetStack.push(item);
            ui->treeWidget->addTopLevelItem(item);
        }
        if(xmlReader.isEndElement()){
            widgetStack.pop();
        }
        xmlReader.readNext();
    }
    if(xmlReader.hasError()){
        qDebug()<<xmlReader.errorString();
    }

}

