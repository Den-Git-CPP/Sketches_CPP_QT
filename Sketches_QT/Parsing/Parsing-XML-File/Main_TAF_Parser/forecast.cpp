#include "forecast.h"

Forecast::Forecast () {}

void Forecast::print ()
{
    qDebug () << _fcst_time_from << _fcst_time_to << _change_indicator << "\n"
              << _time_becoming << "\n"
              << _probability << "\n"
              << _wx_string << "\n"
              << _not_decoded << "\n"
              << _visibility_statute_mi << "\n"
              << _altim_in_hg << "\n"
              << _vert_vis_ft << "\n";
}
