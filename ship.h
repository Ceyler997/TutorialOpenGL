#pragma once
#include "structs.h"

class ship {
private:
	position center;//ship center
	int angle;//from 0 to 7, 0 = 0, 1 = 1.5 ... 7=10.5 hours
public:
	ship();
	void get_coords(position *set);
	void get_center(position &coord);
	void move_to(int x, int y);
	void draw_ship();
};