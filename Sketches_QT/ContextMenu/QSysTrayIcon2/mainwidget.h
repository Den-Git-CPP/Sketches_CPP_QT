#pragma once
#include <QSystemTrayIcon>
#include <QWidget>

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

  public:
    explicit MainWidget (QWidget* parent = 0);
    ~MainWidget ();
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     *  чтобы оно сворачивалось в трей, когда мы этого хотим
     */
    void closeEvent (QCloseEvent* event);

  private slots:
    /* Слот, который будет принимать сигнал от события
     * нажатия на иконку приложения в трее
     */
    void onTrayIconActivated (QSystemTrayIcon::ActivationReason reason);
    /* Функция, которая будет отображать сообщение о сворачивании в трей
     */
    void onShowMessageInTray ();

  private:
    Ui::MainWidget* ui;
    /* Объявляем объект будущей иконки приложения для трея */
    QSystemTrayIcon* m_trayIcon;
};
