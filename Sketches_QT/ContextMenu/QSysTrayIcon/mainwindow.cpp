#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{

    // 12 оследний штрих — отредактируйте событие инициализации формы и пропишите вызовы созданных нами методов

    ui->setupUi (this);
    this->setTrayIconActions ();
    this->showTrayIcon ();
}

MainWindow::~MainWindow () { delete ui; }

void MainWindow::changeEvent (QEvent* event)
{
    // 11 ерехватчик события сворачивания формы на панель задач и вместо этого свернём её в трей
    QMainWindow::changeEvent (event);
    if (event->type () == QEvent::WindowStateChange) {
        if (isMinimized ()) {
            this->hide ();
        }
    }
}

void MainWindow::trayIconActivated (QSystemTrayIcon::ActivationReason reason)
{
    // 9  обработки кликов по иконке в системном трее
    switch (reason) {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick: this->trayActionExecute (); break;
        default: break;
    }
}

void MainWindow::trayActionExecute ()
{ // 8
    QMessageBox::information (this, "TrayIcon", "Тестовое сообщение. Замените вызов этого сообщения своим кодом.");
}

void MainWindow::setTrayIconActions ()
{ // 10 добавьте контекстное меню для нашего значка
    // Setting actions...
    minimizeAction = new QAction ("Свернуть", this);
    restoreAction  = new QAction ("Восстановить", this);
    quitAction     = new QAction ("Выход", this);

    // Connecting actions to slots...
    connect (minimizeAction, SIGNAL (triggered ()), this, SLOT (hide ()));
    connect (restoreAction, SIGNAL (triggered ()), this, SLOT (showNormal ()));
    connect (quitAction, SIGNAL (triggered ()), qApp, SLOT (quit ()));

    // Setting system tray's icon menu...
    trayIconMenu = new QMenu (this);
    trayIconMenu->addAction (minimizeAction);
    trayIconMenu->addAction (restoreAction);
    trayIconMenu->addAction (quitAction);
}

void MainWindow::showTrayIcon () // 7
{
    // Создаём экземпляр класса и задаём его свойства...
    trayIcon = new QSystemTrayIcon (this);
    QIcon trayImage (":/resource/meteo.ico");
    trayIcon->setIcon (trayImage);
    trayIcon->setContextMenu (trayIconMenu);

    // Подключаем обработчик клика по иконке...
    connect (trayIcon, SIGNAL (activated (QSystemTrayIcon::ActivationReason)), //
      this, SLOT (trayIconActivated (QSystemTrayIcon::ActivationReason)));

    // Выводим значок...
    trayIcon->show ();
}
