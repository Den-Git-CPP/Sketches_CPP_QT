#pragma one

#include <QGraphicsView>

class View : public QGraphicsView {
    Q_OBJECT
  public:
    explicit View (QWidget* parent = nullptr);

  signals:

  public slots:

    // QWidget interface
  protected:
    void mousePressEvent (QMouseEvent* event) override;
};
