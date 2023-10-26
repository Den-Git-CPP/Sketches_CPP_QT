#ifndef PROGRESSBARDEMO_H
#define PROGRESSBARDEMO_H

#include <QStyledItemDelegate>

#include <QWidget>
#include <QTimer>

class QTableWidget;
class QPushButton;

class ProgressBarDemo : public QWidget {
    Q_OBJECT

public:
    ProgressBarDemo( QWidget* parent = 0 );
    ~ProgressBarDemo();

private slots:
    void addRow();
    void onProgress();

private:
    QTableWidget* m_table;
    QPushButton* m_btnAdd;

    QTimer m_timer;

    int m_currentRow;
    int m_currentProgress;

};

class ProgressBarDelegate : public QStyledItemDelegate {
public:
    ProgressBarDelegate( QObject* parent = 0 );
    void paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const;
};

#endif // PROGRESSBARDEMO_H
