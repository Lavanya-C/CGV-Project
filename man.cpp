
#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <MMSystem.h>
#include <string.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>

using namespace std;

void cutter(float x, float y)
{

	//Draw face
	float radius = 35.0;
	glColor3f(1.0, 0.90, 0.85);

	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd(); 

	radius = 6.0;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 20, sin(i) * radius + y + 160);
	glEnd();

	radius = 3.0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 20, sin(i) * radius + y + 160);
	glEnd();


	//Hair of man
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 40, y + 150);
	glVertex2f(x - 40, y + 145);
	glVertex2f(x - 32, y + 185);
	glVertex2f(x + 15, y + 190);
	glVertex2f(x + 50, y + 185);
	glVertex2f(x + 40, y + 175);
	glVertex2f(x + 10, y + 170);
	glVertex2f(x - 10, y + 155);
	glVertex2f(x - 40, y + 150);
	glEnd();

	//Draw neck of the man
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0, y + 100.0);
	glVertex2f(x - 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 100.0);
	glEnd();


	//Draws left hand of man
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y + 90);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 50, y + 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 75);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 75, y + 105);
	glVertex2f(x + 75, y + 95);
	glEnd();

	//Draw basket
	glColor3f(0.8500, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 20, y + 30);
	glVertex2f(x + 30, y + 20);
	glVertex2f(x + 70, y + 20);
	glVertex2f(x + 80, y + 30);
	glVertex2f(x + 80, y + 60);
	glVertex2f(x + 20, y + 60);
	glEnd();
	//Handle of basket
	glColor3f(0.8500, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 45, y + 60);
	glVertex2f(x + 55, y + 60);
	glVertex2f(x + 45, y + 90);
	glVertex2f(x + 55, y + 90);
	glEnd();
	
	//Shirt of man
	glColor3f(0.8, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 10, y + 100);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y);
	glEnd();

	//Draws left leg of man
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 15, y - 75);
	glVertex2f(x - 15, y);
	glVertex2f(x - 5, y);
	glVertex2f(x - 5, y - 75);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 15, y - 75);
	glVertex2f(x - 5, y - 65);
	glVertex2f(x + 15, y - 70);
	glVertex2f(x + 15, y - 75);
	glEnd();

	//Draw right leg of man
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y - 75);
	glVertex2f(x + 10, y);
	glVertex2f(x + 20, y);
	glVertex2f(x + 20, y - 75);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y - 75);
	glVertex2f(x + 20, y - 65);
	glVertex2f(x + 40, y - 70);
	glVertex2f(x + 40, y - 75);
	glEnd();


	//Draw trousers of man
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 25);
	glVertex2f(x + 25, y + 25);
	glVertex2f(x + 25, y);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y - 30);
	glVertex2f(x - 25, y);
	glVertex2f(x - 2, y);
	glVertex2f(x - 2, y - 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x + 4, y - 30);
	glVertex2f(x + 4, y);
	glVertex2f(x + 25, y);
	glVertex2f(x + 25, y - 30);
	glEnd();
	
	//Draw right hand of man
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + 70);
	glVertex2f(x, y + 80);
	glVertex2f(x + 55, y + 65);
	glVertex2f(x + 55, y + 55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x + 55, y + 55);
	glVertex2f(x + 55, y + 65);
	glVertex2f(x + 80, y + 95);
	glVertex2f(x + 80, y + 85);
	glEnd();

	//Draw mouth of man
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 25, y + 125);
	glVertex2f(x + 10, y + 125);
	glVertex2f(x + 10, y + 127);
	glEnd();

	//Draws the Nose of the man
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 32, y + 140);
	glVertex2f(x + 32, y + 150);
	glVertex2f(x + 34, y + 155);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 10, y + 160);
	glVertex2f(x - 20, y + 160);
	glVertex2f(x - 20, y + 140);
	glVertex2f(x - 10, y + 140);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x - 20, y + 150);
	glVertex2f(x - 10, y + 150);
	glEnd();


	//Draw fishing row
	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 110, y + 105);
	glVertex2f(x - 75, y + 105);
	glVertex2f(x + 195, y + 105);
	glVertex2f(x + 195, y + 95);
	glEnd();
	radius = 10.0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 125, sin(i) * radius + y + 95);
	glEnd();
	
	//Draw Right palm
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 80, y + 85);
	glVertex2f(x + 80, y + 105);
	glVertex2f(x + 90, y + 105);
	glVertex2f(x + 90, y + 95);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 80, y + 105);
	glVertex2f(x + 80, y + 100);
	glVertex2f(x + 82.5, y + 105);
	glVertex2f(x + 82.5, y + 100);
	glVertex2f(x + 85, y + 105);
	glVertex2f(x + 85, y + 100);
	glVertex2f(x + 87, y + 105);
	glVertex2f(x + 87, y + 100);
	glVertex2f(x + 89.5, y + 105);
	glVertex2f(x + 89.5, y + 100);
	glEnd();

	//Draw left palm
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 65, y + 95);
	glVertex2f(x + 65, y + 105);
	glVertex2f(x + 75, y + 105);
	glVertex2f(x + 75, y + 95);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 65, y + 105);
	glVertex2f(x + 65, y + 100);
	glVertex2f(x + 67.5, y + 105);
	glVertex2f(x + 67.5, y + 100);
	glVertex2f(x + 70, y + 105);
	glVertex2f(x + 70, y + 100);
	glVertex2f(x + 72.5, y + 105);
	glVertex2f(x + 72.5, y + 100);
	glVertex2f(x + 74.5, y + 105);
	glVertex2f(x + 74.5, y + 100);
	glEnd();

}
