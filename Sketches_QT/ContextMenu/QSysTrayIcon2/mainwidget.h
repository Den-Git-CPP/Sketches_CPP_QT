#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget( QWidget* parent = 0 );
    ~MainWidget();

    void closeEvent( QCloseEvent* event );

private slots:
    void onTrayIconActivated( QSystemTrayIcon::ActivationReason reason );
    void onShowMessageInTray();

private:
    Ui::MainWidget* ui;
    QSystemTrayIcon* m_trayIcon;
};

#endif // MAINWIDGET_H
