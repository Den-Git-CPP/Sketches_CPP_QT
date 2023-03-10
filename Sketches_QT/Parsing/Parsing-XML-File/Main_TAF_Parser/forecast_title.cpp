#include "forecast_title.h"

Forecast_Title::Forecast_Title (QObject* parent) : QObject (parent) {}

void Forecast_Title::print ()
{
    qDebug () << _request_index << _name << _type << _time_taken_ms << _num_results << "\n";
    for (const auto& elem : _erorrs) {
        qDebug () << "Erorrs:" << elem;
    };

    for (const auto& elem : _warnings) {
        qDebug () << "Warnings:" << elem;
    };

    qDebug () << "Forecast_Title END";
}
