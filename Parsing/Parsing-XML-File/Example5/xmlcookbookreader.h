#ifndef XMLCOOKBOOKREADER_H
#define XMLCOOKBOOKREADER_H

#include <QIODevice>
#include <QXmlStreamReader>
#include "recipe.h"
#include "cookbook.h"

class XmlCookBookReader
{
public:
    XmlCookBookReader(CookBook* cookbook);
    bool read(QIODevice *device);
    QString errorString() const;
private:
    QXmlStreamReader reader;
    CookBook* m_cookbook;

    void readCookBook();
    void readRecipe();
    void readTitle(Recipe *recipe);
    void readIngredientList(Recipe *recipe);
    void readInstructions(Recipe *recipe);
};

#endif // XMLCOOKBOOKREADER_H