#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QStringList>

class Recipe
{
public:
    QString title() const {return m_title;}
    QStringList ingredients() const {return m_ingredients;}
    QString instructions() const {return m_instructions;}
    void setTitle(const QString& title) {this->m_title = title;}
    void setIngredients(const QStringList& ingredientList){
        this->m_ingredients = ingredientList;
    }
    void setInstructions(const QString& instructions){
        this->m_instructions = instructions;
    }
    void print() const;
private:
    QString m_title;
    QStringList m_ingredients;
    QString m_instructions;
};

#endif // RECIPE_H