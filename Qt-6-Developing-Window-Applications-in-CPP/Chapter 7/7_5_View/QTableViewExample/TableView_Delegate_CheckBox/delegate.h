#pragma once
#include <QStyledItemDelegate>

class CheckBoxDelegate : public QStyledItemDelegate {
    Q_OBJECT

  public:
    CheckBoxDelegate (QObject* parent = nullptr);

    // QAbstractItemDelegate interface
  public:
    void paint (QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    QWidget* createEditor (QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void setEditorData (QWidget* editor, const QModelIndex& index) const;
    void setModelData (QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
    void updateEditorGeometry (QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};
