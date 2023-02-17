
#include "xmlparser.h"

XMLParser::XMLParser(QObject *parent) : QObject(parent) {}

void XMLParser::Read(MainTAF *main_TAF) {
  QFile file(":/file.xml");
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file" << file.errorString();
    exit(0);
  }
  reader.setDevice(&file);
  if (reader.readNextStartElement()) {
    if (reader.name() == QString("response")) {
      read_response(main_TAF);
    }
  }
}
void XMLParser::read_response(MainTAF *main_TAF) {
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("request_index")) {
      read_request_index(main_TAF);
    } else if (reader.name() == QString("data_source")) {
      read_data_sourse(main_TAF);
    } else if (reader.name() == QString("request")) {
      read_data_request_type(main_TAF);
    } else if (reader.name() == QString("errors")) {
      read_data_errors(main_TAF);
    } else if (reader.name() == QString("warnings")) {
      read_data_warnings(main_TAF);
    } else if (reader.name() == QString("time_taken_ms")) {
      read_time_taken_ms(main_TAF);
    } else if (reader.name() == QString("data")) {
      read_data(main_TAF);
    }
    // else             reader.skipCurrentElement ();
  }

  main_TAF->forecast_Title->print();
}
void XMLParser::read_request_index(MainTAF *main_TAF) {
  Q_ASSERT(reader.name() == QString("request_index"));
  main_TAF->forecast_Title->set_request_index(reader.readElementText());
}
void XMLParser::read_data_sourse(MainTAF *main_TAF) {
  Q_ASSERT(reader.name() == QString("data_source") &&
           reader.attributes().hasAttribute("name"));
  main_TAF->forecast_Title->set_name(
      reader.attributes().value("name").toString());
  reader.skipCurrentElement();
}
void XMLParser::read_data_request_type(MainTAF *main_TAF) {
  Q_ASSERT(reader.name() == QString("request") &&
           reader.attributes().hasAttribute("type"));

  main_TAF->forecast_Title->set_type(
      reader.attributes().value("type").toString());

  reader.skipCurrentElement();
}
void XMLParser::read_data_errors(MainTAF *main_TAF) {
  Q_ASSERT(reader.isStartElement() && reader.name() == QString("errors"));
  QStringList errors_list;
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("error")) {
      errors_list.append(reader.readElementText());
    }
  }
  main_TAF->forecast_Title->set_erorrs(errors_list);
}
void XMLParser::read_data_warnings(MainTAF *main_TAF) {
  Q_ASSERT(reader.isStartElement() && reader.name() == QString("warnings"));
  QStringList warnings_list;
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("warning")) {
      warnings_list.append(reader.readElementText());
    }
  }
  main_TAF->forecast_Title->set_warnings(warnings_list);
}
void XMLParser::read_time_taken_ms(MainTAF *main_TAF) {
  Q_ASSERT(reader.name() == QString("time_taken_ms"));
  main_TAF->forecast_Title->set_time_taken_ms(reader.readElementText());
}
void XMLParser::read_data(MainTAF *main_TAF) {
  read_data_num_results(main_TAF);
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("TAF")) {
      read_TAF(main_TAF);
    } else
      reader.skipCurrentElement();
  }
}
void XMLParser::read_data_num_results(MainTAF *main_TAF) {
  Q_ASSERT(reader.name() == QString("data") &&
           reader.attributes().hasAttribute("num_results"));
  main_TAF->forecast_Title->set_num_results(
      reader.attributes().value("num_results").toString());
  // reader.skipCurrentElement ();
}
void XMLParser::read_TAF(MainTAF *main_TAF) {
  Q_ASSERT(reader.isStartElement() && reader.name() == QString("TAF"));
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("raw_text")) {
      read_raw_text(main_TAF);
    }
    // else             reader.skipCurrentElement ();
  }
  main_TAF->forecast_TAF->print();
}
void XMLParser::read_raw_text(MainTAF *main_TAF) {
  Q_ASSERT(reader.name() == QString("raw_text"));
  main_TAF->forecast_TAF->set_raw_text(reader.readElementText());
}

/*          if (reader.name () == QString ("TAF")) {
                while (reader.readNextStartElement ()) {
                    if (reader.name () == QString ("raw_text")) {}
                    if (reader.name () == QString ("station_id")) {}
                    if (reader.name () == QString ("issue_time")) {}
                    if (reader.name () == QString ("bulletin_time")) {}
                    if (reader.name () == QString ("valid_time_from")) {}
                    if (reader.name () == QString ("valid_time_to")) {}
                    if (reader.name () == QString ("remarks")) {}
                    if (reader.name () == QString ("latitude")) {}
                    if (reader.name () == QString ("longitude")) {}
                    if (reader.name () == QString ("elevation_m")) {}
                    if (reader.name () == QString ("forecast")) {
                        while (reader.readNextStartElement ()) {
                            if (reader.name () == QString ("fcst_time_from")) {}
                            if (reader.name () == QString ("fcst_time_to")) {}
                            if (reader.name () == QString ("change_indicator"))
{} if (reader.name () == QString ("time_becoming")) {} if (reader.name () ==
QString ("probability")) {} if (reader.name () == QString ("wind_dir_degrees"))
{} if (reader.name () == QString ("wind_speed_kt")) {} if (reader.name () ==
QString ("wind_gust_kt")) {} if (reader.name () == QString
("wind_shear_hgt_ft_agl")) {} if (reader.name () == QString
("wind_shear_dir_degrees")) {} if (reader.name () == QString
("wind_shear_speed_kt")) {} if (reader.name () == QString
("visibility_statute_mi")) {} if (reader.name () == QString ("altim_in_hg")) {}
                            if (reader.name () == QString ("vert_vis_ft")) {}
                            if (reader.name () == QString ("wx_string")) {}
                            if (reader.name () == QString ("not_decoded")) {}
                            if (reader.name () == QString ("sky_condition") &&
reader.attributes ().hasAttribute ("sky_cover")
                                && reader.attributes ().hasAttribute
("cloud_base_ft_agl") && reader.attributes ().hasAttribute ("cloud_type ")) {
                                QString sky_cover_str         =
reader.attributes ().value ("sky_cover").toString (); QString
cloud_base_ft_agl_str = reader.attributes ().value
("cloud_base_ft_agl").toString (); QString cloud_type            =
reader.attributes ().value ("cloud_type").toString ();

reader.skipCurrentElement ();
}
if (reader.name () == QString ("turbulence_condition") && reader.attributes
().hasAttribute ("turbulence_intensity")
    && reader.attributes ().hasAttribute ("turbulence_min_alt_ft_agl")
    && reader.attributes ().hasAttribute ("turbulence_max_alt_ft_agl")) {
    QString turbulence_intensity      = reader.attributes ().value
("turbulence_intensity").toString (); QString turbulence_min_alt_ft_agl =
reader.attributes ().value ("turbulence_min_alt_ft_agl").toString (); QString
turbulence_max_alt_ft_agl = reader.attributes ().value
("turbulence_max_alt_ft_agl").toString ();

    reader.skipCurrentElement ();
}
if (reader.name () == QString ("icing_condition") && reader.attributes
().hasAttribute ("icing_intensity")
    && reader.attributes ().hasAttribute ("icing_min_alt_ft_agl") &&
reader.attributes ().hasAttribute ("icing_max_alt_ft_agl")) { QString
icing_intensity      = reader.attributes ().value ("icing_intensity").toString
(); QString icing_min_alt_ft_agl = reader.attributes ().value
("icing_min_alt_ft_agl").toString (); QString icing_max_alt_ft_agl =
reader.attributes ().value ("icing_max_alt_ft_agl").toString ();

    reader.skipCurrentElement ();
}
if (reader.name () == QString ("temperature") && reader.attributes
().hasAttribute ("valid_time")
    && reader.attributes ().hasAttribute ("sfc_temp_c") && reader.attributes
().hasAttribute ("max_temp_c")
    && reader.attributes ().hasAttribute ("min_temp_c")) {
    QString valid_time = reader.attributes ().value ("valid_time").toString ();
    QString sfc_temp_c = reader.attributes ().value ("sfc_temp_c").toString ();
    QString max_temp_c = reader.attributes ().value ("max_temp_c").toString ();
    QString min_temp_c = reader.attributes ().value ("min_temp_c").toString ();
    reader.skipCurrentElement ();
}
if (reader.name () == QString ("valid_time")) {}
if (reader.name () == QString ("sfc_temp_c")) {}
if (reader.name () == QString ("max_temp_c")) {}
if (reader.name () == QString ("min_temp_c")) {}

} // while forecast
}     // FORECAST
}         // while TAF
}*/             // TAF
