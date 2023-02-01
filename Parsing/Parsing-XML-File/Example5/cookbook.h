#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <QList>
#include "recipe.h"

class CookBook
{
public:
    void addRecipe(Recipe* recipe);
    void print() const;
private:
    QList<Recipe*> m_recipes;
};

#endif // COOKBOOK_H