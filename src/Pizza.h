#pragma once
#include <list>
#include "Ingredient.h"

class Pizza
{
public:
	Pizza() = default;
	~Pizza() = default;	// should be virtual

private:
	std::list<Ingredient> ingredients;
};