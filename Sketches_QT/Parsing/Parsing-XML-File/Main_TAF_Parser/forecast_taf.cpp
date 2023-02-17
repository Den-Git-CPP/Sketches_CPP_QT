#include "forecast_taf.h"

Forecast_TAF::Forecast_TAF (QObject* parent) {}

void Forecast_TAF::print ()
{
    qDebug () << _raw_text << _station_id << _issue_time << _bulletin_time << _valid_time_from << _valid_time_to << _remarks << _latitude
              << _longitude << _elevation_m;
    qDebug () << "Forecast_TAF END";

    for (auto elem : _all_forecast_node) {
        elem.print ();
    }
}
