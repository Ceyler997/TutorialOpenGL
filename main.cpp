#include"main.h"

int main(int argc, char * argv[]) {
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//activate double buffer and GRBA color

	glutInitWindowSize(800, 600);
	glutCreateWindow("Spaceship");
	glutPositionWindow(283, 84);//a middle of the 1366x768 screen
	glutReshapeFunc(reshape);//handling window reshaoing
	glutSpecialFunc(arrows);//handling arrows keyboard commands
	glutKeyboardFunc(keyboard);//handling WASD and Esc keyboard commands
	glutMouseFunc(mouse);//handling mouse commands
	glutDisplayFunc(display);//start position

	glutMainLoop();//start a programm
	delete get_stars();
	return 0;
}