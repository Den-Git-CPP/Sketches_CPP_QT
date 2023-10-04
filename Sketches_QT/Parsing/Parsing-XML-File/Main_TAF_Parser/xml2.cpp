#include "xml2.h"

XML2::XML2 (QObject* parent) : QObject (parent) {}
void XML2::Read ()
{ //
    QFile file (":/resource/file.xml");
    if (!file.open (QFile::ReadOnly | QFile::Text)) {
        //        QMessageBox::critical(this,"Load XML File Problem",
        //        "Couldn't open xmlfile.xml to load settings for download",
        //        QMessageBox::Ok);
        //        return;
        qDebug () << "Cannot read file" << file.errorString ();
        exit (0);
    }
    xmlReader.setDevice (&file);
    xmlReader.readNext ();
    while (!xmlReader.atEnd () && !xmlReader.hasError ()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext ();
        if (token == QXmlStreamReader::StartDocument) {
            continue;
        }
        if (token == QXmlStreamReader::StartElement) {
            if (xmlReader.name ().toString () == "response") {
                continue;
            }
            else if (xmlReader.name ().toString () == "request_index") {
                qDebug () << xmlReader.readElementText ();
            }
            else if (xmlReader.name ().toString () == "data_source") {
                qDebug () << xmlReader.attributes ().value ("name").toString ();
            }
            else if (xmlReader.name ().toString () == "request") {
                qDebug () << xmlReader.attributes ().value ("type").toString ();
            }
            else if (xmlReader.name ().toString () == "errors") {
                read_errors ();
            }
            else if (xmlReader.name ().toString () == "warnings") {
                read_my_warninngs ();
            }
            else if (xmlReader.name ().toString () == "time_taken_ms") {
                qDebug () << xmlReader.readElementText ();
            }
            else if (xmlReader.name ().toString () == "data") {
                qDebug () << xmlReader.attributes ().value ("num_results").toString ();
            }
            else if (xmlReader.name ().toString () == "TAF") {
                read_TAF ();
            }
        }
    } // while end file
    if (xmlReader.hasError ()) {
        qDebug () << xmlReader.errorString ();
        return;
    }

    qDebug () << "READ_END";
}
void XML2::read_errors ()
{
    while (xmlReader.readNextStartElement ()) {
        if (xmlReader.name ().toString () == "error") {
            qDebug () << xmlReader.readElementText ();
        }
    }
}
void XML2::read_my_warninngs ()
{
    while (xmlReader.readNextStartElement ()) {
        if (xmlReader.name ().toString () == "warning") {
            qDebug () << xmlReader.readElementText ();
        }
    }
}
void XML2::read_TAF ()
{
    while (xmlReader.readNextStartElement ()) {
        if (xmlReader.name ().toString () == "raw_text") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "station_id") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "issue_time") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "bulletin_time") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "valid_time_from") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "valid_time_to") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "remarks") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "latitude") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "longitude") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "elevation_m") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "forecast") {
            read_forecast ();
        }
    } // end while

    if (QXmlStreamReader::EndElement && xmlReader.name ().toString () == "TAF") {
        qDebug () << "Create TAF\n";
        read_TAF ();
    }
}
void XML2::read_forecast ()
{
    while (xmlReader.readNextStartElement ()) {
        if (xmlReader.name ().toString () == "fcst_time_from") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "fcst_time_to") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "change_indicator") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "time_becoming") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "probability") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wind_dir_degrees") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wind_speed_kt") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wind_gust_kt") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wind_shear_hgt_ft_agl") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wind_shear_dir_degrees") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wind_shear_speed_kt") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "visibility_statute_mi") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "altim_in_hg") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "vert_vis_ft") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "wx_string") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "not_decoded") {
            qDebug () << xmlReader.readElementText ();
        }
        else if (xmlReader.name ().toString () == "sky_condition") {
            qDebug () << xmlReader.attributes ().value ("sky_cover").toString () << xmlReader.attributes ().value ("cloud_base_ft_agl").toString ();
        }
        else if (xmlReader.name ().toString () == "turbulence_condition") {
            qDebug () << xmlReader.attributes ().value ("turbulence_intensity").toString ()
                      << xmlReader.attributes ().value ("turbulence_min_alt_ft_agl").toString ()
                      << xmlReader.attributes ().value ("turbulence_max_alt_ft_agl").toString ();
        }
        else if (xmlReader.name ().toString () == "icing_condition") {
            qDebug () << xmlReader.attributes ().value ("icing_intensity").toString () << xmlReader.attributes ().value ("icing_min_alt_ft_agl").toString ()
                      << xmlReader.attributes ().value ("icing_max_alt_ft_agl").toString ();
        }
        else {
            xmlReader.skipCurrentElement ();
        }
        xmlReader.readNext ();
    }
}
