#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_generateButton_clicked() {
  /* Открываем файл для Записи с помощью пути, указанного в lineEditWrite */
  QFile file(ui->lineEditWrite->text());
  file.open(QIODevice::WriteOnly);

  /* Создаем объект, с помощью которого осуществляется запись в файл */
  QXmlStreamWriter xmlWriter(&file);
  xmlWriter.setAutoFormatting(true); // Устанавливаем автоформатирование текста
  xmlWriter.writeStartDocument(); // Запускаем запись в документ
  xmlWriter.writeStartElement(
      "resources"); // Записываем первый элемент с его именем

  xmlWriter.writeStartElement(
      "checkBox_1"); // Записываем тег с именем для первого чекбокса
  /* На основе состояния чекбокса записываем атрибут "boolean"
   * с указанием состояния чекбокса в этом атрибуте
   * */
  xmlWriter.writeAttribute("boolean",
                           (ui->checkBox->isChecked() ? "true" : "false"));
  /* Записываем также в тело этого элемента строку из соответствующего lineEdit
   * */
  xmlWriter.writeCharacters(ui->lineEditCB1->text());
  xmlWriter.writeEndElement(); // Закрываем тег

  /* Повторяем те же действия для двух других чекбоксов
   * */
  xmlWriter.writeStartElement("checkBox_2");
  xmlWriter.writeAttribute("boolean",
                           (ui->checkBox_2->isChecked() ? "true" : "false"));
  xmlWriter.writeCharacters(ui->lineEditCB2->text());
  xmlWriter.writeEndElement();

  xmlWriter.writeStartElement("checkBox_3");
  xmlWriter.writeAttribute("boolean",
                           (ui->checkBox_3->isChecked() ? "true" : "false"));
  xmlWriter.writeCharacters(ui->lineEditCB3->text());
  xmlWriter.writeEndElement();

  /* Закрываем тег "resources"
   * */
  xmlWriter.writeEndElement();
  /* Завершаем запись в документ
   * */
  xmlWriter.writeEndDocument();
  file.close(); // Закрываем файл
}

void MainWindow::on_dialogButton_clicked() {
  /* Вызываем диалог выбора файла для сохранения */
  QString filename = QFileDialog::getSaveFileName(this, tr("Save Xml"), ".",
                                                  tr("Xml files (*.xml)"));
  /* Устанавливаем в lineEditWrite путь к файлу, с которым будем работать */
  if (filename != "") {
    ui->lineEditWrite->setText(filename);
  }
}

void MainWindow::on_readButton_clicked() {
  /* Открываем файл для Чтения с помощью пути, указанного в lineEditWrite */
  QFile file(ui->lineEditRead->text());
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "Ошибка файла", "Не удалось открыть файл",
                         QMessageBox::Ok);
  } else {
    /* Создаем объект, с помощью которого осуществляется чтение из файла */
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);
    xmlReader.readNext(); // Переходит к первому элементу в файле

    /* Крутимся в цикле до тех пор, пока не достигнем конца документа
     * */
    while (!xmlReader.atEnd()) {
      /* Проверяем, является ли элемент началом тега
       * */
      if (xmlReader.isStartElement()) {
        /* Проверяем, относится ли тег к одному из чекбоксов.
         * Если "ДА", то выполняем проверку атрибута чекбокса
         * и записи для lineEdit
         * */
        if (xmlReader.name().toString() == "checkBox_1") {
          /* Забираем все атрибуты тега и перебираем их для проверки на
           * соответствие нужному нам атрибуту
           * */
          foreach (const QXmlStreamAttribute &attr, xmlReader.attributes()) {
            /* Если найден нужный атрибут, то по его значению устанавливаем
             * состояние чекбокса
             * */
            if (attr.name().toString() == "boolean") {
              QString attribute_value = attr.value().toString();
              ui->checkBox->setChecked(
                  (QString::compare(attribute_value, "true") == 0) ? true
                                                                   : false);
            }
          }
          /* забираем текст из тела тега и вставляем его соответствующий
           * lineEdit
           * */
          ui->lineEditCB1->setText(xmlReader.readElementText());

          /* аналогично работаем с остальными тегами */
        } else if (xmlReader.name().toString() == "checkBox_2") {
          foreach (const QXmlStreamAttribute &attr, xmlReader.attributes()) {
            if (attr.name().toString() == "boolean") {
              QString attribute_value = attr.value().toString();
              ui->checkBox_2->setChecked(
                  (QString::compare(attribute_value, "true") == 0) ? true
                                                                   : false);
            }
          }
          ui->lineEditCB2->setText(xmlReader.readElementText());
        } else if (xmlReader.name().toString() == "checkBox_3") {
          foreach (const QXmlStreamAttribute &attr, xmlReader.attributes()) {
            if (attr.name().toString() == "boolean") {
              QString attribute_value = attr.value().toString();
              ui->checkBox_3->setChecked(
                  (QString::compare(attribute_value, "true") == 0) ? true
                                                                   : false);
            }
          }
          ui->lineEditCB3->setText(xmlReader.readElementText());
        }
      }
      xmlReader.readNext(); // Переходим к следующему элементу файла
    }
    file.close(); // Закрываем файл

    /* В данном коде не осуществляется проверка на закрытие тега
     * поскольку в этом нет необходимости, но функционал QXmlStreamReader это
     * позволяет
     * */
  }
}

void MainWindow::on_dialogReadButton_clicked() {
  /* Вызываем диалог выбора файла для чтения */
  QString filename = QFileDialog::getOpenFileName(this, tr("Open Xml"), ".",
                                                  tr("Xml files (*.xml)"));
  /* Устанавливаем в lineEditRead путь к файлу, с которым будем работать */
  if (filename != "") {
    ui->lineEditRead->setText(filename);
  }
}
