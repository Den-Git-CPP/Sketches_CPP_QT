#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QXmlStreamReader>
#include <QTreeWidgetItem>
#include <QStack>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
