#include <QDebug>
#include <QString>
#pragma once
class Forecast {
  public:
    Forecast ();
    ~Forecast (){};
    void print ();

  private:
    QString _fcst_time_from{};
    QString _fcst_time_to{};
    QString _change_indicator{};
    QString _time_becoming{};
    QString _probability{};
    QString _wx_string{};
    QString _not_decoded{};
    QString _visibility_statute_mi{};
    QString _altim_in_hg{};
    QString _vert_vis_ft{};
};
