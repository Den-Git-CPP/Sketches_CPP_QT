#include "cookbook.h"

void CookBook::addRecipe(Recipe *recipe){
    m_recipes.append(recipe);
}

void CookBook::print() const {
    foreach(Recipe* recipe, m_recipes)
        recipe->print();
}