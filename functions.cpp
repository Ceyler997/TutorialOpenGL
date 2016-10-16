#include "main.h"

void reshape(int width, int height) {
	glutReshapeWindow(800, 600);//back to 800x600
}

void display()
{
	int window[4];//window[2] - width, window[3] - height
	ship* hero=get_ship();

	glGetIntegerv(GL_VIEWPORT, window);//getting window info

	glMatrixMode(GL_PROJECTION);//activate projection matrix
	glLoadIdentity();//set active matrix as identity
	gluOrtho2D(0, window[2], window[3], 0);//set TODO

	glClear(GL_COLOR_BUFFER_BIT);

	hero->draw_ship();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		ship *hero = get_ship();
		hero->move_to(x, y);
	}
}

void arrows(int key, int x, int y) {
	ship *hero = get_ship();
	position center;
	int speed = 10;
	hero->get_center(center);
	if (key == GLUT_KEY_UP)
		hero->move_to(center.x, center.y - speed);
	if (key == GLUT_KEY_DOWN)
		hero->move_to(center.x, center.y + speed);
	if (key == GLUT_KEY_RIGHT)
		hero->move_to(center.x + speed, center.y);
	if (key == GLUT_KEY_LEFT)
		hero->move_to(center.x - speed, center.y);
}

void keyboard(unsigned char key, int x, int y) {
	ship *hero = get_ship();
	position center;
	int speed = 10;
	hero->get_center(center);
	if (key == 'w' || key == 'W')
		hero->move_to(center.x, center.y - speed);
	if (key == 's' || key == 'S')
		hero->move_to(center.x, center.y + speed);
	if (key == 'd' || key == 'D')
		hero->move_to(center.x + speed, center.y);
	if (key == 'a' || key == 'A')
		hero->move_to(center.x - speed, center.y);
}

ship *get_ship() {
	static ship hero;
	return &hero;
}

universe *get_stars() {
	static universe *stars = nullptr;
	if (stars == nullptr)
		stars = new universe(3000);
	return stars;
}