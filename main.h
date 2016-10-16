#pragma once

#include <glut.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "ship.h"
#include "universe.h"
#include "structs.h"

#define M_PI 3.1415

void reshape(int width, int height);
void display();
void arrows(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
ship *get_ship();
universe *get_stars();