#include "universe.h"
#include "main.h"

universe::universe(int st_amount)
{
	amount = st_amount;
	stars = new position[amount];
	int window[4];//window[2] - width, window[3] - height
	glGetIntegerv(GL_VIEWPORT, window);
	for (int count = 0; count < amount; ++count) {
		stars[count].x = rand() % window[2];
		stars[count].y = rand() % window[3];
	}
}

void universe::draw_stars() {
	glColor3f(1.0, 1.0, 0.0);
	for (int count = 0; count < amount; ++count) {
		glBegin(GL_POINTS);
		glVertex2i(stars[count].x, stars[count].y);		
		glEnd();
	}
}