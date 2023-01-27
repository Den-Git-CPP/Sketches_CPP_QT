#include <QXmlSimpleReader>
#include <QXmlStreamReader>
#include <QDebug>

int main(int argc, char *argv[])
{
    QFile file(":/test.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file" << file.errorString();
        exit(0);
    }

    QXmlStreamReader reader(&file);
 if(reader.readNextStartElement()) {
        if(reader.name()==QString("unit") || reader.name() == QString("unit2")) {
            while(reader.readNextStartElement()) {
                if(reader.name() == QString("unit_type")) {
                    qDebug() << "Unit Type " << reader.name()  << "Value " << reader.readElementText();
                     //reader.skipCurrentElement();
                }
                if(reader.name() == QString("manufacturer")) {
                      qDebug() << "Unit manufacturer " << reader.name() << "Value " << reader.readElementText();
                       //  reader.skipCurrentElement();
                }
                if(reader.name() == QString("article_number")) {
                       qDebug() << "Unit article_number " << reader.name() << "Value " << reader.readElementText();
                      //  reader.skipCurrentElement();
                }
                if(reader.name() == QString("production_date")) {
                       qDebug() << "Unit production_date " << reader.name() << "Value " <<reader.readElementText();
                }
                if(reader.name() == QString("delivery_revision")) {
                       qDebug() << "Unit delivery_revision " << reader.name() << reader.readElementText()<<"\n";
                        // reader.skipCurrentElement();
                }
                if(reader.name() == QString("present_revision")) {
                        qDebug() << "Unit present_revision " << reader.name() << reader.readElementText();
                     //    reader.skipCurrentElement();
                }
                if(reader.name() == QString("rev_date")) {
                        qDebug() << "Unit rev_date " << reader.name() << reader.readElementText();
                      //   reader.skipCurrentElement();
                }
                if(reader.name() == QString("made_the_last_rev")) {
                       qDebug() << "Unit made_the_last_rev " << reader.name() << reader.readElementText();
                      //  reader.skipCurrentElement();
                }
                if(reader.name() == QString("serial_number")) {
                        qDebug() << "Unit serial_number " << reader.name() << reader.readElementText();
                         reader.skipCurrentElement();
                }
                if(reader.name() == QString("eth_addresses")) {
                    while(reader.readNextStartElement()) {
                        if(reader.name() == QString("eth_address")) {
                            qDebug() << "Ethernet Element eth_address " << reader.name() << reader.readElementText();
                            reader.skipCurrentElement();
                        }

                    }
                }
                if(reader.name() == QString("boards")) {
                    while(reader.readNextStartElement()) {
                        if(reader.name() == QString("board")) {
                            while(reader.readNextStartElement()) {
                                if(reader.name() == QString("board_type")) {
                                    qDebug() << "Boards board_type" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("article_number")) {
                                    qDebug() << "Boards article_number" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("production_date")) {
                                    qDebug() << "Boards production_date" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("delivery_revision")) {
                                    qDebug() << "Boards delivery_revision" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("present_revision")) {
                                    qDebug() << "Boards present_revision" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("rev_date")) {
                                    qDebug() << "Boards rev_date" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("made_the_last_rev")) {
                                    qDebug() << "Boards made_the_last_rev" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                                if(reader.name() == QString("serial_number")) {
                                    qDebug() << "Boards serial_number" << reader.name() << reader.readElementText();
                                    reader.skipCurrentElement();
                                }
                            }
                        }
                    }
                }
            }

        }
    }

    return 0;
}
