#pragma one

#include <QGraphicsRectItem>

class Rect : public QGraphicsRectItem {
  public:
    explicit Rect ();

    // QGraphicsItem interface
  protected:
    void keyPressEvent (QKeyEvent* event) override;
};
