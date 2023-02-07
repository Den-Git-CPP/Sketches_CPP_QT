#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {

  QFile file(":/file1.xml");
  if (!file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)) {
    qDebug() << "failed to open file1.xml";
    return;
  }
  QXmlStreamAttributes attributes;
  QXmlStreamWriter writer;
  writer.setDevice(&file);
  writer.setAutoFormatting(true);
  writer.writeStartDocument(); // Написать первую строку документа
  writer.writeStartElement("ConfigInfo");

  writer.writeComment("Начните сохранять данные конфигурации в строке 1 !");
  writer.writeStartElement("RootDir");
  attributes.append("itemText", "BG-HAO(2873/2873)");
  attributes.append("dirBaseName", "BG-HAO");
  attributes.append("withSubDir", "false");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeStartElement("SubDir");
  attributes.clear();
  attributes.append("itemText", "/");
  attributes.append("dirBaseName", "BG-HAO");
  attributes.append("withSubDir", "false");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeTextElement("ImageSum", "2873");
  writer.writeEmptyElement("DirInfo");
  attributes.clear();
  attributes.append("dirFullName", "/home/liuqiang/Documents/BG/train/BG-HAO");
  attributes.append("imageNumber", "2873");
  writer.writeAttributes(attributes);
  writer.writeTextElement("Weight", "1.0");
  writer.writeEmptyElement("Label");
  attributes.clear();
  attributes.append("name", "(0)hao");
  attributes.append("color", "#12ec76");
  attributes.append("number", "0");
  writer.writeAttributes(attributes);
  writer.writeEndElement();
  writer.writeEndElement();
  writer.writeComment("Данные конфигурации строки 1 сохранены !");

  writer.writeComment("Начните сохранять данные конфигурации в строке 2 !");
  writer.writeStartElement("RootDir");
  attributes.clear();
  attributes.append("itemText", "BG-CHA(4222/4222)");
  attributes.append("dirBaseName", "BG-CHA");
  attributes.append("withSubDir", "false");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeStartElement("SubDir");
  attributes.clear();
  attributes.append("itemText", "/");
  attributes.append("dirBaseName", "BG-CHA");
  attributes.append("withSubDir", "false");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeTextElement("ImageSum", "4222");
  writer.writeEmptyElement("DirInfo");
  attributes.clear();
  attributes.append("dirFullName", "/home/liuqiang/Documents/BG/train/BG-CHA");
  attributes.append("imageNumber", "4222");
  writer.writeAttributes(attributes);
  writer.writeTextElement("Weight", "1.0");
  writer.writeEmptyElement("Label");
  attributes.clear();
  attributes.append("name", "(1)cha");
  attributes.append("color", "#0cc8f3");
  attributes.append("number", "1");
  writer.writeAttributes(attributes);
  writer.writeEndElement();
  writer.writeEndElement();
  writer.writeComment("Данные конфигурации строки 2 сохранены !");

  writer.writeComment("Начните сохранять данные конфигурации в строке 3 !");
  writer.writeStartElement("RootDir");
  attributes.clear();
  attributes.append("itemText", "train(7095/7095)");
  attributes.append("dirBaseName", "train");
  attributes.append("withSubDir", "true");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeStartElement("SubDir");
  attributes.clear();
  attributes.append("itemText", "/");
  attributes.append("dirBaseName", "train");
  attributes.append("withSubDir", "true");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeTextElement("ImageSum", "7095");
  writer.writeEmptyElement("DirInfo");
  attributes.clear();
  attributes.append("dirFullName", "/home/liuqiang/Documents/BG/train/BG-HAO");
  attributes.append("imageNumber", "2873");
  writer.writeAttributes(attributes);
  writer.writeEmptyElement("DirInfo");
  attributes.clear();
  attributes.append("dirFullName", "/home/liuqiang/Documents/BG/train/BG-CHA");
  attributes.append("imageNumber", "4222");
  writer.writeAttributes(attributes);
  writer.writeTextElement("Weight", "1.0");
  writer.writeEmptyElement("Label");
  attributes.clear();
  attributes.append("name", "(0)hao");
  attributes.append("color", "#12ec76");
  attributes.append("number", "0");
  writer.writeAttributes(attributes);
  writer.writeEndElement();
  writer.writeEndElement();
  writer.writeComment("Данные конфигурации строки 3 сохранены !");

  writer.writeComment("Начните сохранять данные конфигурации в строке 4 !");
  writer.writeStartElement("RootDir");
  attributes.clear();
  attributes.append("itemText", "train(7095/7095)");
  attributes.append("dirBaseName", "train");
  attributes.append("withSubDir", "true");
  attributes.append("showSubDir", "true");
  writer.writeAttributes(attributes);
  writer.writeStartElement("SubDir");
  attributes.clear();
  attributes.append("itemText", "BG-HAO(2873/2873)");
  attributes.append("dirBaseName", "BG-HAO");
  attributes.append("withSubDir", "false");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeTextElement("ImageSum", "2873");
  writer.writeEmptyElement("DirInfo");
  attributes.clear();
  attributes.append("dirFullName", "/home/liuqiang/Documents/BG/train/BG-HAO");
  attributes.append("imageNumber", "2873");
  writer.writeAttributes(attributes);
  writer.writeTextElement("Weight", "1.0");
  writer.writeEmptyElement("Label");
  attributes.clear();
  attributes.append("name", "(1)cha");
  attributes.append("color", "#0cc8f3");
  attributes.append("number", "1");
  writer.writeAttributes(attributes);
  writer.writeEndElement();
  writer.writeStartElement("SubDir");
  attributes.clear();
  attributes.append("itemText", "BG-CHA(4222/4222)");
  attributes.append("dirBaseName", "BG-CHA");
  attributes.append("withSubDir", "false");
  attributes.append("showSubDir", "false");
  writer.writeAttributes(attributes);
  writer.writeTextElement("ImageSum", "4222");
  writer.writeEmptyElement("DirInfo");
  attributes.clear();
  attributes.append("dirFullName", "/home/liuqiang/Documents/BG/train/BG-CHA");
  attributes.append("imageNumber", "4222");
  writer.writeAttributes(attributes);
  writer.writeTextElement("Weight", "1.0");
  writer.writeEmptyElement("Label");
  attributes.clear();
  attributes.append("name", "(1)cha");
  attributes.append("color", "#0cc8f3");
  attributes.append("number", "1");
  writer.writeAttributes(attributes);
  writer.writeEndElement();
  writer.writeEndElement();
  writer.writeComment("Данные конфигурации строки 4 сохранены !");

  writer.writeEndElement();
  file.close();
}

void MainWindow::on_pushButton_2_clicked() {

  QFile file(":/file1.xml");
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "failed to open file1.xml";
    return;
  }
  QXmlStreamReader reader;
  reader.setDevice(&file);
  reader.readNext();
  if (reader.isStartDocument()) {
    QString version = reader.documentVersion().toString();
    QString encoding = reader.documentEncoding().toString();
    bool isAlone = reader.isStandaloneDocument();
    qDebug() << "Version: " << version << "; Encoding: " << encoding
             << "Standalone: " << isAlone;
    reader.readNext();
  }
  while (!reader.atEnd()) { // Если конец документа не читается и ошибки нет
    if (reader.isStartElement()) {
      if (reader.name().toString() == "ConfigInfo") {
        qDebug() << "start reading: " << reader.name().toString();
        reader.readNext();
      } else if (reader.name().toString() == "RootDir") {
        qDebug() << reader.name().toString()
                 << reader.attributes().value("itemText")
                 << reader.attributes().value("dirBaseName")
                 << reader.attributes().value("withSubDir")
                 << reader.attributes().value("showSubDir");
        reader.readNext();
      } else if (reader.name().toString() == "SubDir") {
        qDebug() << reader.name().toString()
                 << reader.attributes().value("itemText")
                 << reader.attributes().value("dirBaseName")
                 << reader.attributes().value("withSubDir")
                 << reader.attributes().value("showSubDir");
        reader.readNext();
      } else if (reader.name().toString() == "ImageSum") {
        qDebug() << reader.name().toString()
                 << reader.readElementText().toInt();
        reader.readNext();
      } else if (reader.name().toString() == "DirInfo") {
        qDebug() << reader.name().toString()
                 << reader.attributes().value("dirFullName")
                 << reader.attributes().value("imageNumber");
        reader.readNext();
      } else if (reader.name().toString() == "Weight") {
        qDebug() << reader.name().toString()
                 << reader.readElementText().toFloat();
        reader.readNext();
      } else if (reader.name().toString() == "Label") {
        qDebug() << reader.name().toString()
                 << reader.attributes().value("name")
                 << reader.attributes().value("color")
                 << reader.attributes().value("number");
        reader.readNext();
      } else {
        reader.readNext();
      }
    } else if (reader.isComment()) {
      qDebug() << reader.text(); // Прочитать содержание комментария
      reader.readNext();
    } else if (reader.isEndElement()) {
      reader.readNext();
    } else {
      reader.readNext();
    }
    if (reader.hasError()) { // Если во время чтения возникает ошибка, выведите
                             // сообщение об ошибке
      qDebug() << "error: " << reader.errorString();
    }
  }
  file.close();
}
