#pragma once
#include "structs.h"

class universe {
private:
	int amount;
	position *stars;
public:
	universe(int amount);
	void draw_stars();
};