#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QCloseEvent>
#include <QIcon>
#include <QMenu>

MainWidget::MainWidget (QWidget* parent) : QWidget (parent), ui (new Ui::MainWidget)
{
    ui->setupUi (this);

    //   connect (ui->bnShowMsg, SIGNAL (clicked (bool)), SLOT (onShowMessageInTray ()));

    /* Инициализируем иконку трея, устанавливаем иконку из набора системных иконок,
     * а также задаем всплывающую подсказку
     * */
    m_trayIcon = new QSystemTrayIcon (QIcon (":/images/tray_icon.ico"), this);

    /* После чего создаем контекстное меню*/
    QMenu* menu         = new QMenu;
    QAction* exitAction = menu->addAction ("Выход");

    connect (m_trayIcon, SIGNAL (activated (QSystemTrayIcon::ActivationReason)), SLOT (onTrayIconActivated (QSystemTrayIcon::ActivationReason)));
    connect (exitAction, SIGNAL (triggered (bool)), qApp, SLOT (quit ()));
    /* Устанавливаем контекстное меню на иконку
     * и показываем иконку приложения в трее
     * */
    m_trayIcon->setContextMenu (menu);
    m_trayIcon->show ();
}

MainWidget::~MainWidget ()
{
    delete ui;
}

void MainWidget::closeEvent (QCloseEvent* event)
{ /* Если окно видимо и чекбокс отмечен, то завершение приложения
   * игнорируется, а окно просто скрывается, что сопровождается
   * соответствующим всплывающим сообщением
   */
    hide ();
    event->ignore ();
}
/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void MainWidget::onTrayIconActivated (QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
        case QSystemTrayIcon::Trigger:
            setVisible (!isVisible ());
            break;

        default:
            break;
    }
}

void MainWidget::onShowMessageInTray ()
{
    //
    m_trayIcon->showMessage ("Message title", //
      "Message text",                         //
      QSystemTrayIcon::Information);          //
}
