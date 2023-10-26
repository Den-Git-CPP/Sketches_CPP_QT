#include "modelviewdemowidget.h"

#include <QTableView>
#include <QHeaderView>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

// ********************************************************************************
ModelViewDemoWidget::ModelViewDemoWidget( QWidget* parent ) : QWidget( parent ) {
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout( mainLayout );

    m_view = new QTableView;
    m_view->horizontalHeader()->setResizeMode( QHeaderView::Stretch );
    m_view->setModel( m_model = new PersonsModel );
    mainLayout->addWidget( m_view );

    QGridLayout* panelLayout = new QGridLayout;
    mainLayout->addLayout( panelLayout );

    QLabel* lbRemove = new QLabel( trUtf8( "<a href=\"#\">Удалить</a>" ) );
    connect( lbRemove, SIGNAL( linkActivated( QString ) ), m_model, SLOT( removeSelected() ) );
    lbRemove->setAlignment( Qt::AlignRight );
    panelLayout->addWidget( lbRemove, 0, 6 );

    QLabel* lbSurname = new QLabel( trUtf8( "Фамилия" ) );
    panelLayout->addWidget( lbSurname, 1, 0 );
    m_surnameEdit = new QLineEdit;
    panelLayout->addWidget( m_surnameEdit, 1, 1 );

    QLabel* lbName = new QLabel( trUtf8( "Имя" ) );
    panelLayout->addWidget( lbName, 1, 2 );
    m_nameEdit = new QLineEdit;
    panelLayout->addWidget( m_nameEdit, 1, 3 );

    QLabel* lbPatronymic = new QLabel( trUtf8( "Отчество" ) );
    panelLayout->addWidget( lbPatronymic, 1, 4 );
    m_patronymicEdit = new QLineEdit;
    panelLayout->addWidget( m_patronymicEdit, 1, 5 );

    QPushButton* bnAdd = new QPushButton( trUtf8( "Добавить" ) );
    connect( bnAdd, SIGNAL( clicked() ), SLOT( onAppend() ) );
    panelLayout->addWidget( bnAdd, 1, 6 );

    resize( 800, 600 );
}

ModelViewDemoWidget::~ModelViewDemoWidget() {
}

void ModelViewDemoWidget::onAppend() {
    m_model->appendPerson(
        m_surnameEdit->text(),
        m_nameEdit->text(),
        m_patronymicEdit->text()
    );
}

// ********************************************************************************
PersonsModel::PersonsModel( QObject* parent ) : QAbstractTableModel( parent ) {
}

int PersonsModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return m_persons.count();
}

int PersonsModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return LAST;
}

QVariant PersonsModel::data( const QModelIndex& index, int role ) const {
    if(
        !index.isValid() ||
        m_persons.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }

    return m_persons[ index.row() ][ Column( index.column() ) ];
}

bool PersonsModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || m_persons.count() <= index.row() ) {
        return false;
    }

    m_persons[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}

QVariant PersonsModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case SURNAME:
        return trUtf8( "Фамилия" );
    case NAME:
        return trUtf8( "Имя" );
    case PATRONYMIC:
        return trUtf8( "Отчество" );
    case SELECTION:
        return trUtf8( "Выбор" );
    }

    return QVariant();
}

Qt::ItemFlags PersonsModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    if( index.isValid() ) {
        if( index.column() == SELECTION ) {
            flags |= Qt::ItemIsEditable;
        }
    }

    return flags;
}

void PersonsModel::appendPerson( const QString& surname, const QString& name, const QString& patronymic ) {
    PersonData person;
    person[ SURNAME ] = surname;
    person[ NAME ] = name;
    person[ PATRONYMIC ] = patronymic;
    person[ SELECTION ] = false;

    int row = m_persons.count();
    beginInsertRows( QModelIndex(), row, row );
    m_persons.append( person );
    endInsertRows();
}

void PersonsModel::removeSelected() {
    int i = 0;
    Persons::iterator it = m_persons.begin();
    while( it != m_persons.end() ) {
        if( it->value( SELECTION, false ).toBool() ) {
            beginRemoveRows( QModelIndex(), i, i );
            it = m_persons.erase( it );
            endRemoveRows();
        } else {
            ++i;
            ++it;
        }

        if( it == m_persons.end() ) {
            break;
        }
    }
}
