#include <QDebug>
#include <QFile>
#include <QXmlSimpleReader>
#include <QXmlStreamReader>

int main(int argc, char *argv[]) {
  QFile file(":/file.xml");
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file" << file.errorString();
    exit(0);
  }

  QXmlStreamReader reader(&file);

  if (reader.readNextStartElement()) {
    if (reader.name() == QString("root")) {
      while (reader.readNextStartElement()) {
        if (reader.name() == QString("childA")) {
          while (reader.readNextStartElement()) {
            if (reader.name() == QString("subchild1")) {
              qDebug() << reader.readElementText();
            } else {
              reader.skipCurrentElement();
            }
          }

        } else {
          reader.skipCurrentElement();
        }
      }

    } else {
      reader.raiseError(QObject::tr("Incorrect file"));
    }
  }

  return 0;
}
