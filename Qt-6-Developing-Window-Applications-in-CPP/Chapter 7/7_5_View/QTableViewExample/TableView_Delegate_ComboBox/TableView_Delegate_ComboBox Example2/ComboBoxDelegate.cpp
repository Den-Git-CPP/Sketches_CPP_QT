#include "ComboBoxDelegate.h"

ComboDelegate::ComboDelegate(QObject *parent) : QStyledItemDelegate (parent), m_comboModel (nullptr), m_comboColumn (0) {}

QAbstractItemModel* ComboDelegate::comboModel () const
{
    return m_comboModel;
}

void ComboDelegate::setComboModel(QAbstractItemModel *comboModel)
{
    m_comboModel = comboModel;
}

int ComboDelegate::comboColumn() const
{
    return m_comboColumn;
}

void ComboDelegate::setComboColumn(int comboColumn)
{
    m_comboColumn = comboColumn;
}

QWidget *ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    QComboBox* result = new QComboBox (parent);
    if (m_comboModel) {
        result->setModel (m_comboModel);
        result->setModelColumn (m_comboColumn);
    }
    result->setGeometry (option.rect);
    return result;
}

void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* result = qobject_cast<QComboBox*> (editor);
    result->setCurrentIndex (result->findData (index.data (), Qt::EditRole));
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* result = qobject_cast<QComboBox*> (editor);
    model->setData (index, result->currentData (Qt::EditRole), Qt::EditRole);
}

void ComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry (option.rect);
}
