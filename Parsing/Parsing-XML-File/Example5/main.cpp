#include <QDebug>
#include <QFile>

#include "recipe.h"
#include "xmlcookbookreader.h"

void readXml(const QString& fileName) {
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file" << file.errorString();
    return;
  }

  CookBook* cookbook = new CookBook;
  XmlCookBookReader xmlReader(cookbook);

  if (!xmlReader.read(&file))
    qDebug() << "Parse error in file " << xmlReader.errorString();
  else
    cookbook->print();
}

int main(int argc, char* argv[]) {
  readXml(":/test.xml");
  return 0;
}
