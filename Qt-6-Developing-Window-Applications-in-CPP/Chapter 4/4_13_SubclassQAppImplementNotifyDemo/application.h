#pragma once

#include <QApplication>

class Application : public QApplication {
    Q_OBJECT
  public:
    explicit Application (int& argc, char** argv);

  signals:

  public slots:

    // QCoreApplication interface
  public:
    bool notify (QObject* dest, QEvent* event) override;
};

#pragma once
