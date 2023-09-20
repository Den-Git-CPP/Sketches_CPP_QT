#include "xml3.h"

xml3::xml3 (QObject* parent) : QObject (parent) {}

xml3::~xml3 () {}

void xml3::Read ()
{
    //
    QFile file (":/file.xml");
    if (!file.open (QFile::ReadOnly | QFile::Text)) {
        //        QMessageBox::critical(this,"Load XML File Problem",
        //        "Couldn't open xmlfile.xml to load settings for download",
        //        QMessageBox::Ok);
        //        return;
        qDebug () << "Cannot read file" << file.errorString ();
        exit (0);
    }
    xmlReader.setDevice (&file);
    while (!xmlReader.atEnd () && !xmlReader.hasError ()) {

        QXmlStreamReader::TokenType token = xmlReader.readNext ();
        QString xml_name                  = xmlReader.name ().toString ();

        if (token == QXmlStreamReader::StartDocument) {
            continue;
        }
        if (token == QXmlStreamReader::StartElement) {
            if (xml_name == "response"         //
                || xml_name == "request_index" //
            ) {
                continue;
            }
            else if (!xml_name.isEmpty ()) {
                if (xml_name == "request"                  //
                    || xml_name == "raw_text"              //
                    || xml_name == "station_id"            //
                    || xml_name == "issue_time"            //
                    || xml_name == "bulletin_time"         //
                    || xml_name == "valid_time_from"       //
                    || xml_name == "valid_time_to"         //
                    || xml_name == "latitude"              //
                    || xml_name == "longitude"             //
                    || xml_name == "elevation_m"           //
                    || xml_name == "fcst_time_from"        //
                    || xml_name == "fcst_time_to"          //
                    || xml_name == "wind_dir_degrees"      //
                    || xml_name == "wind_speed_kt"         //
                    || xml_name == "visibility_statute_mi" //
                    || xml_name == "wx_string"             //
                    || xml_name == "fcst_time_from"        //
                    || xml_name == "fcst_time_to"          //
                    || xml_name == "change_indicator"      //
                    || xml_name == "visibility_statute_mi" //
                    || xml_name == "wx_string"             //
                    || xml_name == "not_decoded"           //
                    || xml_name == "change_indicator"      //
                    || xml_name == "visibility_statute_mi" //
                    || xml_name == "wx_string"             //
                ) {
                    QString xml_text = xmlReader.readElementText ();
                    mp_Token.insert (xml_name, xml_text);
                }
                else if (xml_name == "sky_condition") {
                    qDebug () << "Sky_Condition:\n"
                              << xmlReader.attributes ().value ("sky_cover").toString () //
                              << xmlReader.attributes ().value ("cloud_base_ft_agl").toString ();
                }
            }
            else {
                xmlReader.skipCurrentElement ();
            }
        }
        //
    }
    if (xmlReader.hasError ()) {
        qDebug () << xmlReader.errorString ();
        return;
    }
}
