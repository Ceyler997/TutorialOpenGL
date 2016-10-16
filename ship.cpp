#include "main.h"

ship::ship()
{
	int window[4];
	glGetIntegerv(GL_VIEWPORT, window);//window[2] - width, window[3] - height
	center.x = window[2]/2;
	center.y = window[3]/2;
	angle = 0;
}

void ship::get_coords(position *set) {//27 радиус описанной окружности, 2,565 - угол 147 град
	set[0].x = center.x + sin(angle*M_PI / 4 + 2.565) * 27;
	set[1].x = center.x + sin(angle*M_PI / 4) * 27;
	set[2].x = center.x + sin(angle*M_PI / 4 - 2.565) * 27;
	set[0].y = center.y + cos(angle*M_PI / 4 + 2.565) * 27;
	set[1].y = center.y + cos(angle*M_PI / 4) * 27;
	set[2].y = center.y + cos(angle*M_PI / 4 - 2.565) * 27;
}

void ship::get_center(position &coord) {
	coord = center;
}

void ship::move_to(int x, int y) {
	position test;
	int window[4];//window[2] - width, window[3] - height
	glGetIntegerv(GL_VIEWPORT, window);
	if (x > window[2]) x = window[2];
	else
		if (x < 0) x = 0;
	if (y > window[3]) y = window[3];
	else
		if (y < 0) y = 0;
	while (center.x != x || center.y != y) {
		test.x = x - center.x;
		test.y = y - center.y;
		if (test.x*test.y == 0)
			if (test.x + test.y > 0)
				if (test.x > 0) {
					angle = 2;
					++center.x;
				}
				else {
					angle = 0;
					++center.y;
				}
			else
				if (test.x < 0) {
					angle = 6;
					--center.x;
				}
				else {
					angle = 4;
					--center.y;
				}
		else
			if (test.x*test.y>0)
				if (test.x > 0) {
					angle = 3;
					++center.x;
					++center.y;
				}
				else {
					angle = 7;
					--center.x;
					--center.y;
				}
			else
				if (test.x > 0) {
					angle = 1;
					++center.x;
					--center.y;
				}
				else {
					angle = 5;
					--center.x;
					++center.y;
				}
				draw_ship();
	}
}

void ship::draw_ship() {
	position coord[3];
	universe *stars = get_stars();
	get_coords(coord);//getting ship info

	glClear(GL_COLOR_BUFFER_BIT);
	stars->draw_stars();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(coord[0].x, coord[0].y);
	glVertex2i(coord[1].x, coord[1].y);
	glVertex2i(coord[2].x, coord[2].y);
	glEnd();

	glutSwapBuffers();
}