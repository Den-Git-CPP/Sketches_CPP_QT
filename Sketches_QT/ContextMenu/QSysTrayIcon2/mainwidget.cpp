#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QIcon>
#include <QMenu>
#include <QCloseEvent>

MainWidget::MainWidget( QWidget* parent ) :
    QWidget( parent ),
    ui( new Ui::MainWidget ) {
    ui->setupUi( this );

    connect( ui->bnShowMsg, SIGNAL( clicked( bool ) ), SLOT( onShowMessageInTray() ) );

    m_trayIcon = new QSystemTrayIcon( QIcon( ":/images/tray_icon.ico" ), this );
    connect( m_trayIcon, SIGNAL( activated( QSystemTrayIcon::ActivationReason ) ), SLOT( onTrayIconActivated( QSystemTrayIcon::ActivationReason ) ) );

    QMenu* menu = new QMenu;

    QAction* exitAction = menu->addAction( "Exit" );
    connect( exitAction, SIGNAL( triggered( bool ) ), qApp, SLOT( quit() ) );

    m_trayIcon->setContextMenu( menu );

    m_trayIcon->show();
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::closeEvent( QCloseEvent* event ) {
    hide();
    event->ignore();
}

void MainWidget::onTrayIconActivated( QSystemTrayIcon::ActivationReason reason ) {
    switch( reason ) {
    case QSystemTrayIcon::Trigger:
        setVisible( !isVisible() );
        break;

    default:
        break;
    }
}

void MainWidget::onShowMessageInTray() {
    m_trayIcon->showMessage( "Message title", "Message text", QSystemTrayIcon::Information );
}
