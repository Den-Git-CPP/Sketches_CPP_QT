#pragma once

#include "maintaf.h"

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QXmlSimpleReader>
#include <QXmlStreamReader>
class XMLParser : public QObject {
    Q_OBJECT
public:
    explicit XMLParser (QObject* parent = nullptr);

public:
    void read_response (MainTAF* main_TAF);
    void read_request_index (MainTAF* main_TAF);
    void read_data_sourse (MainTAF* main_TAF);
    void read_data_request_type (MainTAF* main_TAF);
    void read_data_errors (MainTAF* main_TAF);
    void read_data_warnings (MainTAF* main_TAF);
    void read_time_taken_ms (MainTAF* main_TAF);
    void read_data (MainTAF* main_TAF);
    void read_data_num_results (MainTAF* main_TAF);
    void read_TAF (MainTAF* main_TAF);
    void read_raw_text (MainTAF* main_TAF);

public slots:
    void Read (MainTAF* main_TAF);

private:
    QXmlStreamReader reader;
};
