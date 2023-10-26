#include "progressbardemo.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QPushButton>

#include <QApplication>

static const QStringList TABLE_COLUMN_LABELS = QStringList() << "Progress";
static const int PROGRESS_STEP = 5;
static const int PROGRESS_DELAY_MSEC = 100;
static const int MAX_PROGRESS_VALUE = 100;

static const int PROGRESS_BAR_HEIGHT_PX = 20;

ProgressBarDemo::ProgressBarDemo( QWidget* parent ) :
    QWidget( parent ),
    m_currentRow( 0 ),
    m_currentProgress( 0 ) {

    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout( mainLayout );

    m_table = new QTableWidget;
    m_table->setColumnCount( TABLE_COLUMN_LABELS.count() );
    m_table->setHorizontalHeaderLabels( TABLE_COLUMN_LABELS );
    m_table->horizontalHeader()->setStretchLastSection( true );
    m_table->setItemDelegateForColumn( 0, new ProgressBarDelegate );
    mainLayout->addWidget( m_table );

    QHBoxLayout* panelLayout = new QHBoxLayout;
    mainLayout->addLayout( panelLayout );

    panelLayout->addStretch( 1 );

    m_btnAdd = new QPushButton( "Add" );
    connect( m_btnAdd, SIGNAL( clicked() ), SLOT( addRow() ) );
    panelLayout->addWidget( m_btnAdd );

    resize( 640, 480 );

    m_timer.setInterval( PROGRESS_DELAY_MSEC );
    connect( &m_timer, SIGNAL( timeout() ), SLOT( onProgress() ) );
}

ProgressBarDemo::~ProgressBarDemo() {
}

void ProgressBarDemo::addRow() {
    m_currentProgress = 0;
    m_currentRow = m_table->rowCount();

    m_table->insertRow( m_currentRow );
    if( QTableWidgetItem* item = new QTableWidgetItem( "0" ) ) {
        item->setFlags( item->flags() ^ Qt::ItemIsEditable );
        m_table->setItem( m_currentRow, 0, item );
    }

    m_btnAdd->setDisabled( true );
    m_timer.start();
}

void ProgressBarDemo::onProgress() {
    m_currentProgress += PROGRESS_STEP;

    if( QTableWidgetItem* item = m_table->item( m_currentRow, 0 ) ) {
        item->setData( Qt::DisplayRole, m_currentProgress );
    }

    if( m_currentProgress == MAX_PROGRESS_VALUE ) {
        m_timer.stop();
        m_btnAdd->setEnabled( true );
    }
}

ProgressBarDelegate::ProgressBarDelegate( QObject* parent ) : QStyledItemDelegate( parent ) {
}

void ProgressBarDelegate::paint(
    QPainter* painter,
    const QStyleOptionViewItem& option,
    const QModelIndex& index
) const {
    int progress = index.data().toInt();

    QStyleOptionProgressBar progressBarOption;
    QRect r = option.rect;
    r.setHeight( PROGRESS_BAR_HEIGHT_PX );
    r.moveCenter( option.rect.center() );
    progressBarOption.rect = r;
    progressBarOption.textAlignment = Qt::AlignCenter;
    progressBarOption.minimum = 0;
    progressBarOption.maximum = MAX_PROGRESS_VALUE;
    progressBarOption.progress = progress;
    progressBarOption.text = QString::number( progress ) + "%";
    progressBarOption.textVisible = true;

    QStyledItemDelegate::paint( painter, option, QModelIndex() );
    QApplication::style()->drawControl( QStyle::CE_ProgressBar, &progressBarOption, painter );
}
