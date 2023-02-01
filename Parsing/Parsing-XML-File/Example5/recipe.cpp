#include "recipe.h"

void Recipe::print() const {
  qDebug("Title: " + m_title.toLocal8Bit());
  qDebug("Ingredients: " + m_ingredients.join(", ").toLocal8Bit());
  qDebug("Instructions: " + m_instructions.toLocal8Bit());
}
