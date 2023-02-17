#include "xmlcookbookreader.h"

XmlCookBookReader::XmlCookBookReader(CookBook *cookbook) {
  m_cookbook = cookbook;
}

bool XmlCookBookReader::read(QIODevice *device) {
  reader.setDevice(device);

  if (reader.readNextStartElement()) {
    if (reader.name() == QString("cookbook"))
      readCookBook();
    else
      reader.raiseError(QObject::tr("Not a cookbook file"));
  }
  return !reader.error();
}

void XmlCookBookReader::readCookBook() {
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("recipe"))
      readRecipe();
    else
      reader.skipCurrentElement();
  }
}

void XmlCookBookReader::readRecipe() {
  Q_ASSERT(reader.isStartElement() && reader.name() == QString("recipe"));

  Recipe *rec = new Recipe;

  readTitle(rec);
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("ingredientList"))
      readIngredientList(rec);
    else if (reader.name() == QString("instructions"))
      readInstructions(rec);
    else
      reader.skipCurrentElement();
  }

  m_cookbook->addRecipe(rec);
}

void XmlCookBookReader::readTitle(Recipe *recipe) {
  Q_ASSERT(reader.name() == QString("recipe") &&
           reader.attributes().hasAttribute("title"));

  QString title = reader.attributes().value("title").toString();
  recipe->setTitle(title);
}

void XmlCookBookReader::readIngredientList(Recipe *recipe) {
  Q_ASSERT(reader.isStartElement() &&
           reader.name() == QString("ingredientList"));

  QStringList ingredList;
  while (reader.readNextStartElement()) {
    if (reader.name() == QString("ingredient")) {
      QString ingr = reader.readElementText();
      ingredList.append(ingr);
    } else
      reader.skipCurrentElement();
  }
  recipe->setIngredients(ingredList);
}

void XmlCookBookReader::readInstructions(Recipe *recipe) {
  Q_ASSERT(reader.isStartElement() && reader.name() == QString("instructions"));

  QString instructions = reader.readElementText();
  recipe->setInstructions(instructions);
}

QString XmlCookBookReader::errorString() const {
  return QObject::tr("%1\nLine %2, column %3")
      .arg(reader.errorString())
      .arg(reader.lineNumber())
      .arg(reader.columnNumber());
}
