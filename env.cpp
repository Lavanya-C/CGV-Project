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

//Draw Tree
void drawTree(void)
{
	//Draws the base of the tree
	glBegin(GL_POLYGON);
	glColor3f(0.5450, 0.2705, 0.0745);
	glVertex2f(300, 200);
	glColor3f(0.406374, 0.203187, 0);
	glVertex2f(500, 200);
	glColor3f(0.5450, 0.2705, 0.0745);
	glVertex2f(475, 240);
	glColor3f(0.406374, 0.203187, 0);
	glVertex2f(325, 240);
	glEnd();

	//Draws the stem of the tree
	glColor3f(0.5450, 0.2705, 0.0745);
	glBegin(GL_POLYGON);
	glVertex2f(475, 240);
	glColor3f(0.406374, 0.203187, 0);
	glVertex2f(325, 240);
	glVertex2f(325, 530);
	glColor3f(0.5450, 0.2705, 0.0745);
	glVertex2f(475, 530);
	glEnd();

	//Draws the left branch of the tree
	glBegin(GL_POLYGON);
	glColor3f(0.406374, 0.203187, 0);
	glVertex2f(560, 540);
	glColor3f(0.5450, 0.2705, 0.0745);
	glVertex2f(475, 410);
	glColor3f(0.5450, 0.2705, 0.0745);
	glVertex2f(475, 450);
	glColor3f(0.406374, 0.203187, 0);
	glVertex2f(545, 540);
	glEnd();

	//Draw  Tree Canopy
	int x = 545, y = 490;
	float radius = 140.0;
	glColor3f(0.0, 0.670, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();
	
	x = 270, y = 510;
	radius = 160.0;
	glColor3f(0.0, 0.665, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

	x = 400, y = 480;
	radius = 180.0;
	glColor3f(0.0, 0.655, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

}

//Draw Water
void drawWater(void)
{  
	glColor3f(0.0, 1.0,1.999);
	glBegin(GL_POLYGON);
	glVertex2f(1300, 175);
	glVertex2f(1300, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 50);
	glVertex2f(50, 50);
	glVertex2f(150, 75);
	glVertex2f(250, 100);
	glVertex2f(500, 100);
	
	glVertex2f(600, 90);
	glVertex2f(700, 125);
	glVertex2f(825, 175);
	glVertex2f(1300, 175);
	glEnd();  
	
	glColor3f(0.0, 1.0, 1.999);
	glBegin(GL_POLYGON);
	glVertex2f(1300, 175);
	glVertex2f(825, 175);
	glVertex2f(600, 250);
	glVertex2f(600, 300);
	glVertex2f(800, 450);
	glVertex2f(1300, 450);
	glEnd();

	int x = 810, y = 280;
	float radius = 30.0;
	glColor3f(0.0, 1.0, 1.999);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

	x = 810, y = 20;
	radius = 40.0;
	glColor3f(0.0, 1.0, 1.999);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

	x = 627, y = 127;
	radius = 40.0;
	glColor3f(0.0, 1.0, 1.999);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

}

//Draw Landscape
void drawLand(void)
{
	glColor3f(0.131075, 0.472549, 0.043137);
	glBegin(GL_POLYGON);
	glVertex2f(0, 50);
	glVertex2f(1300, 50);
	glVertex2f(1300, 550);
	glVertex2f(0, 550);
	glEnd(); 
}

//Draw Grass
void drawGrass(int x, int y)
{
	glColor3f(0.1, 0.6324, 0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + 25, y);
	glVertex2f(x - 25, y + 100);
	glVertex2f(x + 25, y);
	glVertex2f(x + 50, y);
	glVertex2f(x + 25, y + 100);
	glEnd();
}

void drawGrasses(void)
{
	drawGrass(50, -10);
	drawGrass(200, 210);
	drawGrass(50, 500);
	//drawGrass(600, 135);
	//drawGrass(700, 155);
	drawGrass(1000, 500);
	drawGrass(1200, 460);
}

//drawStone();

void drawStone(void)
{
	glColor3f(0.2, 0.0, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(640, 205);
	glVertex2f(660, 200);
	glVertex2f(660, 155);
	glVertex2f(570, 155);
	glVertex2f(570, 200);
	glVertex2f(580, 205);

	glEnd();
}
