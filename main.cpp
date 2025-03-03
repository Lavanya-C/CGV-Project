#include "declaration.h"
#include "header.h"


void myinit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
}


void mydisplay()
{
	if (windowFlag) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 0.0, 0.0);
		glRasterPos2f(115.0, 470.0);
		for (i = 0; i < strlen(str1); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
		glutPostRedisplay();

		/*glColor3f(0.0, 0.0, 1.0);
		glRasterPos2f(165.0, 445.0);
		for (i = 0; i < strlen(str2); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);
		glutPostRedisplay();      */

		glColor3f(1.0, 0.0, 1.0);
		glRasterPos2f(110.0, 410.0);
		for (i = 0; i < strlen(str3); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str3[i]);
		glutPostRedisplay();

		glColor3f(1.0, 0.0, 1.0);
		glRasterPos2f(140.0, 385.0);
		for (i = 0; i < strlen(str5); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str5[i]);
		glutPostRedisplay();

		glColor3f(1.0, 0.2, 0.1);
		glRasterPos2f(180.0, 340.0);
		for (i = 0; i < strlen(str4); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[i]);
		glutPostRedisplay();

		glColor3f(0.2, 0.8, 0.4);
		glRasterPos2f(210.0, 300.0);
		for (i = 0; i < strlen(str6); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str6[i]);
		glutPostRedisplay();

		glColor3f(0.2, 0.0, 0.9);
		glRasterPos2f(20.0, 150.0);
		for (i = 0; i < strlen(str8); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str8[i]);
		glutPostRedisplay();

		glColor3f(0.4, 0.0, 0.3);
		glRasterPos2f(20.0, 130.0);
		for (i = 0; i < strlen(str9); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str9[i]);
		glutPostRedisplay();

		glColor3f(0.4, 0.0, 0.3);
		glRasterPos2f(20.0, 110.0);
		for (i = 0; i < strlen(str10); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str10[i]);
		glutPostRedisplay();

		glColor3f(0.8, 0.0, 0.001);
		glRasterPos2f(20.0, 90.0);
		for (i = 0; i < strlen(str11); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str11[i]);
		glutPostRedisplay();

		/*glColor3f(0.2, 0.0, 0.9);
		glRasterPos2f(350.0, 150.0);
		for (i = 0; i < strlen(str12); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str12[i]);
		glutPostRedisplay();

		glColor3f(0.4, 0.0, 0.3);
		glRasterPos2f(350.0, 130.0);
		for (i = 0; i < strlen(str13); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str13[i]);
		glutPostRedisplay();

		glColor3f(0.4, 0.0, 0.3);
		glRasterPos2f(350.0, 110.0);
		for (i = 0; i < strlen(str14); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str14[i]);
		glutPostRedisplay();

		glColor3f(0.8, 0.0, 0.001);
		glRasterPos2f(350.0, 90.0);
		for (i = 0; i < strlen(str15); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str15[i]);
		glutPostRedisplay();    */

		if (j < 5)
		{

			glColor3f(0.2, 0.8, 0.4);
			glRasterPos2f(200.0, 20.0 + j);
			for (i = 0; i < strlen(str7); i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str7[i]);
			glutPostRedisplay();
			j = j + 0.01;
		}
		else
			j = 0.0;
	}
	glFlush();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080, 1100);
	glutInitWindowPosition(0, 0);
	firstWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(mydisplay);
	glutMouseFunc(click);
	myinit();
	createHelpWindow();
	PlaySound(TEXT("sing.wav"), NULL, SND_FILENAME | SND_ASYNC);
	glutMainLoop();
}

void click(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && windowFlag)
	{
		windowFlag = 0;
		createNewWindow();
	}
	glutPostRedisplay();
}


void keySecond(unsigned char key, int x, int y)
{
	if (key == 'x' || key == 'X')
		exit(0);
	if (key == 'd' || key == 'D')
		flag5 = 1;
	if (key == 'a' || key == 'A')
		flag5 = 0;
	if (key == 'w' && yMove < 50)
		yMove += 0.1;
	if (key == 's' && yMove > 0)
		yMove -= 0.1;
	if (key == 'f' || key == 'F')
	{
		flagThirdScene = 1;
		PlaySound(TEXT("Axe.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		//PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
}


void createNewWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(firstWindow);
	secondWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(mydisplaySecondWindow);
	glutKeyboardFunc(keySecond);
	initSecondWindow();
}


 void mydisplaySecondWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();

	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();
	drawTree();
	drawGrasses();
	drawStone();

	char str1[] = "A to stop";
	//char str2[] = "W to up";
	//char str3[] = "S to down";
	char str4[] = "D to Move";
	//char str5[] = "W to up";
	//char str6[] = "S to down";
	char str7[] = "Press F";
	//Motion to woodcutter that is 'd' or else 'a' stop
	//flag5 is set on 'd' and unset on 'a'
	if (j < 550 && flag5 == 1)
	{
		fisherMan(100 + j, 220 + yMove);
		j += 20.0;
		displayHelp(str1, 1000, 100);
		//displayHelp(str2, 1000, 70);
		//displayHelp(str3, 1000, 40);
	}
	else if (j < 550)
	{
		fisherMan(100 + j, 220 + yMove);
		displayHelp(str4, 1000, 100);
		//displayHelp(str5, 1000, 70);
		//displayHelp(str6, 1000, 40);
	}
	else
	{
		fisherMan(650, 220 + yMove);
		displayHelp(str7, 1000, 100);
	}
	glutPostRedisplay();

	if (j > 550.0 && flagThirdScene)
	{
		createThirdWindow();
	}
	glFlush();

}

void key(unsigned char key, int x, int y)
{
	if (key == 'x' || key == 'X')
		exit(0);
}

void initSecondWindow(void)
{

	glClearColor(0.7, 0.8, 0.98, 0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1300, 0, 700);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


/*void drawTreeEdges(void)
{

	float r = 50.0;
	float i;
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((300 + r * cos(i)), (525 + r * sin(i)));
	glEnd();


	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((275 + r * cos(i)), (450 + r * sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((250 + r * cos(i)), (425 + r * sin(i)));
	glEnd();
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((225 + r * cos(i)), (435 + r * sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((150 + r * cos(i)), (450 + r * sin(i)));
	glEnd();
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((150 + r * cos(i)), (500 + r * sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((150 + r * cos(i)), (525 + r * sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((200 + r * cos(i)), (600 + r * sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((150 + r * cos(i)), (550 + r * sin(i)));
	glEnd();
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((250 + r * cos(i)), (600 + r * sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((250 + r * cos(i)), (625 + r * sin(i)));
	glEnd();
}
*/

void createHelpWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 700);
	glutInitWindowPosition(1000, 0);
	secondWindow = glutCreateWindow("Help");
	glutDisplayFunc(displayHelpWindow);
	myinit();
	//glutKeyboardFunc(key);
}

void displayHelpWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	displayHelp(strD, 50.0, 475.0);
	displayHelp(strA, 50.0, 450.0);
	displayHelp(strS, 50.0, 425.0);
	displayHelp(strF, 50.0, 400.0);
	displayHelp(strT, 50.0, 375.0);
	displayHelp(strY, 50.0, 350.0);
	displayHelp(strB, 50.0, 325.0);
	displayHelp(strN, 50.0, 300.0);
	displayHelp(strJ, 50.0, 275.0);
	displayHelp(strK, 50.0, 250.0);
	glFlush();
}

void createThirdWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(secondWindow);
	thirdWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(mydisplayThirdWindow);
	//while(flagPlayAxe)
		//PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	initSecondWindow();
	glutKeyboardFunc(keyThird);
	glutMainLoop();
}

void keyThird(unsigned char key, int x, int y)
{
	if (key == 'x' || key == 'X')
		exit(0);
	if (key == 't' || key == 'T' && flagFourthScene)
	{
		flagFourthScene = 0;
		createFourthWindow();
		flagPlayRow = false;
		PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	//if(key=='r')
		//PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
}


void mydisplayThirdWindow()
{
	int count = 0;
	int flag = 0;
	////(TEXT("cow.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	////(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();
	drawStone();

	drawFisher(600.0, 190.0);

	glPushMatrix();

	if (theta >= 0.0 && theta < 20.0)
	{
		drawRowDown(630, 275);
		theta += 0.5;
	}
	else if (theta >= 20.0 && theta)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawRowUp(630, 265);
		glPopMatrix();
		theta += 0.5;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	if (theta > 500.0)
	{
		theta = 0.0;
	} 

	char str8[] = "Press T";
	displayHelp(str8, 1000, 100);
	glutPostRedisplay();
}


void drawRowDown(float x, float y)
{
	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 0, y + 10);
	glVertex2f(x + 0, y + 20);
	glVertex2f(x + 315, y + 20);
	glVertex2f(x + 85, y + 15);
	glEnd();
	float radius = 7.0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 65, sin(i) * radius + y + 13);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 295, y + 20);
	glVertex2f(x + 100, y - 100);
	glEnd();

}

void drawRowUp(float x, float y)
{
	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 0, y + 10);
	glVertex2f(x + 0, y + 20);
	glVertex2f(x + 315, y + 180);
	glVertex2f(x + 85, y + 65);
	glEnd();
	float radius = 7.0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 65, sin(i) * radius + y + 55);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 285, y + 165);
	glVertex2f(x + 450, y - 120);
	glEnd();	
}

void createFourthWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	fourthWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDestroyWindow(thirdWindow);
	glutDisplayFunc(mydisplayFourthWindow);
	PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	glutKeyboardFunc(keyFourth);
	initSecondWindow();

}

void keyFourth(unsigned char key, int x, int y)
{
	if (key == 't' || key == 'T' && flagFourthScene)
	{
		flagFourthScene = 0;
		createFourthWindow();
	}
	if (key == 'x' || key == 'X')
		exit(0);

	if (key == 'g' || key == 'G')
		flagMoveDownRow = 1;

	if (key == 'y' || key == 'Y')
		flagFifthScene = 1;
}

void mydisplayFourthWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();
	drawTree();
	drawGrasses();
	drawStone();

	drawFisher(550.0, 450.0);

	if (moveRowY < 200 && flagMoveDownRow)
	{
		moveDownRow(650.0, 450.0 - moveRowY);
		displayText();
		moveRowY += 1.0;
	}
	else if (moveRowY < 200)
	{
		moveDownRow(650.0, 450.0);
		char str9[] = "Press G";
		displayHelp(str9, 1000, 100);
	}
	else if (moveRowY >= 200 && flagFifthScene)
	{
		createFifthWindow();
		flagFifthScene = 0;
	}
	else if (moveRowY >= 200 && !flagFifthScene)
	{
		displayTextGod();
		char str10[] = "Press Y";
		displayHelp(str10, 1000.0, 100.0);
	}

	glutPostRedisplay();
	glFlush();
}

void displayText()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(700, 600);
	glVertex2f(750, 650);
	glVertex2f(850, 650);
	glVertex2f(850, 550);
	glVertex2f(750, 550);
	glEnd();
	char  str11[] = "What have I";
	char str12[] = "done...???";
	displayHelp(str11, 720, 600);
	displayHelp(str12, 750, 575);
}

void displayTextGod()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(700, 600);
	glVertex2f(750, 650);
	glVertex2f(850, 650);
	glVertex2f(850, 550);
	glVertex2f(750, 550);
	glEnd();
	char str13[] = "Oho God....";
	displayHelp(str13, 720, 600);

}

void moveDownRow(float x, float y)
{
	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 10, y);
	glVertex2f(x - 10, y + 100);
	glVertex2f(x, y + 100);
	glVertex2f(x, y);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 20, y + 10);
	glVertex2f(x - 20, y + 35);
	glVertex2f(x + 25, y + 35);
	glVertex2f(x + 25, y + 10);
	glEnd();
}

void keySixth(unsigned char key, int x, int y)
{
	if (key == 'b' || key == 'B')
	{
		createSeventhWindow();
	}
	if (key == 'x' || key == 'X')
		exit(0);
}

void createFifthWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(fourthWindow);
	fifthWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(mydisplayFifthWindow);
	initSecondWindow();
	glutKeyboardFunc(key);
}

void mydisplayFifthWindow(void)
{

	moveAxeInWater += 1.0;
	glClear(GL_COLOR_BUFFER_BIT);
	drawUnderWater();
	if (moveAxeInWater < 500)
	{
		moveDownRow(600, 750 - moveAxeInWater);
		moveAxeInWater += 1.0;
	}
	else if (moveAxeInWater > 500)
	{
		drawAxeInWater(600.0, 250.0);
	}
	drawFishes(moveFishes);
	moveFishes += 1.0;
	glutPostRedisplay();
	glFlush();

	if (moveFishes == 800.0)
		createSixthWindow();
}

void drawUnderWater(void)
{
	glClearColor(0.0, 0.4, 0.8, 1.0);
	drawFloorWater();
}

void drawFloorWater(void)
{
	glColor3f(0.862745, 0.862745, 0.862745);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 300);
	glVertex2f(300, 200);
	glVertex2f(500, 250);
	glVertex2f(600, 250);
	glVertex2f(1000, 350);
	glVertex2f(1300, 350);
	glVertex2f(1300, 0);
	glVertex2f(0, 0);
	glEnd();
}

void drawAxeInWater(float x, float y)
{
	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 150, y);
	glVertex2f(x - 150, y + 10);
	glVertex2f(x, y + 10);
	glVertex2f(x, y);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 35, y - 10);
	glVertex2f(x - 35, y + 35);
	glVertex2f(x - 10, y + 35);
	glVertex2f(x - 10, y - 10);
	glEnd();
}

void drawFishes(float xMove)
{
	glColor3f(1.0, 0.6, 0.0);
	drawFish(500.0 - xMove, 500.0);

	glColor3f(1.0, 0.85, 0.0);
	drawFish(700.0 - xMove, 600.0);

	glColor3f(0.8, 0.4, 0.0);
	drawFish(1200.0 - xMove, 650.0);

	glColor3f(0.0, 0.2, 0.98);
	drawFish(300.0 - xMove, 700.0);
}

void drawFish(float x, float y)
{
	float i = 0.0;
	float r = 5.0;

	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + 10, y + 10);
	glVertex2f(x + 50, y + 25);
	glVertex2f(x + 100, y + 25);
	glVertex2f(x + 150, y);
	glVertex2f(x + 100, y - 25);
	glVertex2f(x + 50, y - 25);
	glVertex2f(x + 10, y - 10);
	glVertex2f(x, y);
	glEnd();



	//glColor3f(1.0,0.6,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 110, y - 15);
	glVertex2f(x + 110, y + 15);
	glVertex2f(x + 155, y + 15);
	glVertex2f(x + 155, y - 15);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 155, y - 15);
	glVertex2f(x + 155, y + 15);
	glVertex2f(x + 175, y + 30);
	glVertex2f(x + 175, y - 30);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((x + 25 + r * cos(i)), (y + 5 + r * sin(i)));
	glEnd();
}


void createSixthWindow(void)
{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(fifthWindow);
	sixthWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(mydisplaySixthWindow);
	glutKeyboardFunc(keySixth);
	initSecondWindow();

}

void mydisplaySixthWindow(void)
{
	moveFishAxe += 0.5;
	//cout<<"moveFishAxe:"<<moveFishAxe<<"\n";
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0, -220.0, 0.0);
	drawWoodcutterOnRiverSide(550.0, 450.0);
	glPopMatrix();

	if (moveFishAxe < 250.0)
	{
		drawCutterInFish(850.0, 0.0 + moveFishAxe, 2);
		displayTextGold(moveFishAxe + 20.0);
	}
	else if (moveFishAxe >= 250.0)
	{
		drawCutterInFish(850.0, 250.0, 2);
		displayTextCutterOne();
		char str14[] = "Press B";
		displayHelp(str14, 1000.0, 100.0);
	}
	glFlush();
}

void displayTextGold(float y)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(900.0, y);
	glVertex2f(950.0, 50.0 + y);
	glVertex2f(1100.0, 50.0 + y);
	glVertex2f(1100.0, y - 50.0);
	glVertex2f(950.0, y - 50.0);
	glEnd();
	char str15[] = "Is this";
	char str16[] = "yours...???";
	displayHelp(str15, 950.0, y + 20.0);
	displayHelp(str16, 950.0, y - 10.0);
}

void displayTextCutterOne()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(700, 450);
	glVertex2f(750, 500);
	glVertex2f(950, 500);
	glVertex2f(950, 400);
	glVertex2f(750, 400);
	glEnd();
	char str17[] = "No!!!";
	char str18[] = "My one is not gold.";
	displayHelp(str17, 780, 460);
	displayHelp(str18, 720, 430);
}

void drawWoodcutterOnRiverSide(float x, float y)
{

	/* float radius = 35.0;
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


	//Hair of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 35, y + 150);
	glVertex2f(x - 35, y + 170);
	glVertex2f(x - 25, y + 195);
	glVertex2f(x + 40, y + 195);
	glVertex2f(x + 35, y + 175);
	glVertex2f(x + 20, y + 170);
	glEnd();


	//Draws the neck of the woodcutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0, y + 100.0);
	glVertex2f(x - 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 100.0);
	glEnd();


	//Draws the left hand of woodcutter
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y + 90);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 50, y + 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 75);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 75, y + 115);
	glVertex2f(x + 75, y + 105);
	glEnd();



	//Draws the red shirt of woodcutter
	glColor3f(0.8, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 10, y + 100);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y);
	glEnd();

	//Draws the mouth of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 25, y + 125);
	glVertex2f(x + 10, y + 125);
	glVertex2f(x + 10, y + 127);
	glEnd();

	//Draws the Nose of the woodcutter

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

	//Drwas the trousers of woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 30);
	glVertex2f(x + 25, y + 30);
	glVertex2f(x + 25, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 25, y);
	glVertex2f(x + 25, y + 26);
	glVertex2f(x + 50, y + 26);
	glVertex2f(x + 50, y);
	glEnd();


	//Draws the Right palm
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

	//Draws the left palm
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

	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 8);
	glVertex2f(x + 50, y + 18);
	glVertex2f(x + 75, y + 18);
	glVertex2f(x + 75, y + 8);
	glEnd();
	*/
}

void drawCutterInFish(float x, float y, int color)
{
	float r = 5.0;
	float i = 0.0;

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x - 25, y);
	glColor3f(1.0, 0.8, 0.1);
	glVertex2f(x - 25, y + 25);
	glColor3f(1.0, 0.843137, 0.0);
	glVertex2f(x - 15, y + 65);
	glColor3f(0.752941, 0.752941, 0.752941);
	glVertex2f(x, y + 75);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 15, y + 65);
	glColor3f(1.0, 0.843137, 0.0);
	glVertex2f(x + 25, y + 25);
	glColor3f(0.752941, 0.752941, 0.752941);
	glVertex2f(x + 25, y);
	glEnd();



	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((x + 7 + r * cos(i)), (y + 55 + r * sin(i)));
	glEnd();

	if (color == 1)
		glColor3f(0.8456, 0.684, 0.4424);
	else if (color == 2)
		glColor3f(1.0, 0.843137, 0.0);
	else if (color == 3)
		glColor3f(0.752941, 0.752941, 0.752941);

	glBegin(GL_POLYGON);
	glVertex2f(x - 75, y + 75);
	glVertex2f(x - 75, y + 85);
	glVertex2f(x + 75, y + 85);
	glVertex2f(x + 75, y + 75);
	glEnd();

	if (color == 1)
		glColor3f(0.0, 0.0, 0.0);
	else if (color == 2)
		glColor3f(1.0, 0.843137, 0.0);
	else if (color == 3)
		glColor3f(0.752941, 0.752941, 0.752941);
	glBegin(GL_POLYGON);
	glVertex2f(x - 70, y + 40);
	glVertex2f(x - 70, y + 95);
	glVertex2f(x - 45, y + 95);
	glVertex2f(x - 45, y + 40);
	glEnd();

}

void createSeventhWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(sixthWindow);
	seventhWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(mydisplaySeventhWindow);
	glutKeyboardFunc(keySeventh);
	initSecondWindow();
}

void mydisplaySeventhWindow()
{
	moveFishAxe2 += 0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0, -220.0, 0.0);
	drawWoodcutterOnRiverSide(550.0, 450.0);
	glPopMatrix();


	if (moveFishAxe2 < 250.0)
	{
		drawCutterInFish(850.0, 0.0 + moveFishAxe2, 3);
		displayTextGold(moveFishAxe2 + 20.0);
	}
	else if (moveFishAxe2 >= 250.0)
	{
		drawCutterInFish(850.0, 250.0, 3);
		displayTextCutterTwo();
		char str20[] = "Press N";
		displayHelp(str20, 1000.0, 100.0);
	}

	glFlush();
}

void displayTextCutterTwo()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(700, 450);
	glVertex2f(750, 500);
	glVertex2f(950, 500);
	glVertex2f(950, 400);
	glVertex2f(750, 400);
	glEnd();
	char str21[] = "No!!!";
	char str22[] = "My one is not silver.";
	displayHelp(str21, 780, 460);
	displayHelp(str22, 720, 430);
}

void keySeventh(unsigned char key, int x, int y)
{
	if (key == 'x' || key == 'X')
		exit(0);
	if (key == 'N' || key == 'n');
	createEigthWindow();
}

void createEigthWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(seventhWindow);
	eighthWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(displayEigthWindow);
	glutKeyboardFunc(keyEigth);
	initSecondWindow();

}

void keyEigth(unsigned char key, int x, int y)
{
	if (key == 'x' || key == 'X')
		exit(0);
	if (key == 'J' || key == 'j')
		createTenthWindow();
}

void displayEigthWindow()
{
	moveFishAxe3 += 0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0, -220.0, 0.0);
	drawWoodcutterOnRiverSide(550.0, 450.0);
	glPopMatrix();


	if (moveFishAxe3 < 250.0)
	{
		drawCutterInFish(850.0, 0.0 + moveFishAxe3, 1);
		displayTextGold(moveFishAxe3);
	}
	else if (moveFishAxe3 >= 250.0)
	{

		drawCutterInFish(850.0, 250, 1);
		displayTextThree();
		char str23[] = "Press J";
		displayHelp(str23, 1000.0, 100.0);
	}
	else if (moveFishAxe3 >= 300.0)
	{
		cout << "Hello\n";
		drawCutterInFish(850.0, 250, 1);
		displayTextGold(350.0);

	}
	glutPostRedisplay();

	glFlush();
}

void displayTextThree()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(700, 450);
	glVertex2f(750, 500);
	glVertex2f(950, 500);
	glVertex2f(950, 400);
	glVertex2f(750, 400);
	glEnd();
	char str24[] = "Yes!!!";
	char str25[] = "Yoo...This is";
	char str26[] = "mine!!!!";
	displayHelp(str24, 780, 460);
	displayHelp(str25, 780, 430);
	displayHelp(str26, 780, 410);

}


void displayHelp(char str[], float x, float y)
{
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(x, y);
	for (i = 0; i < strlen(str); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	glutPostRedisplay();
}

void createNinthWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(10, 10);
	ninthWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(displayNinthWindow);
	glutDestroyWindow(tenthWindow);
	initSecondWindow();
}

void displayNinthWindow()
{
	tCount += 0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	char str27[] = "Thank you...!";
	char str28[] = "Special Thanks to Mr.Sudharshan K";
	char str29[] = "Story:Sudharshan.A";
	char str30[] = "Design:Sudharshan.A";
	char str31[] = "Programming:Shreesha.M";
	char str32[] = "Guided by:Mr.Sudarshan K";
	char str33[] = "HONESTY IS THE BEST POLICY";
	if (tCount <= 100)
		displayHelp(str27, 200, 500);
	if (tCount > 100 && tCount <= 200)
		displayHelp(str28, 200, 500);

	else if (tCount > 200 && tCount <= 500)
	{
		displayHelp(str29, 200, 550);
		displayHelp(str30, 200, 500);
		displayHelp(str31, 200, 450);
		displayHelp(str32, 200, 600);
	}
	else if (tCount > 500)
	{
		displayHelp(str33, 300, 350);
	}

	else if (tCount == 750.0)
	{
		exit(0);
	}
	glFlush();
}

void createTenthWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(0, 0);
	glutDestroyWindow(eighthWindow);
	tenthWindow = glutCreateWindow("Human and Nature Interaction: Fishing");
	glutDisplayFunc(displayTenthWindow);
	glutKeyboardFunc(keyTenth);
	initSecondWindow();
	glutMainLoop();
}

void displayTenthWindow(void)
{
	moveFishAxe4 += 0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0, 200.0, 0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0, 300.0, 0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0, -220.0, 0.0);
	drawWoodcutterOnRiverSide(550.0, 450.0);
	glPopMatrix();


	if (moveFishAxe4 < 250.0)
	{
		drawCutterInFishThree(850.0, 0.0 + moveFishAxe4);
		displayTextAll(moveFishAxe4);
	}
	else if (moveFishAxe4 >= 250.0)
	{

		drawCutterInFishThree(850.0, 250);
		char str35[] = "Press K ";
		displayHelp(str35, 1000.0, 100.0);
	}
	glutPostRedisplay();

	glFlush();
}

void drawCutterInFishThree(float x, float y)
{
	float r = 5.0;
	float i = 0.0;

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x - 25, y);
	glColor3f(1.0, 0.8, 0.1);
	glVertex2f(x - 25, y + 25);
	glColor3f(1.0, 0.843137, 0.0);
	glVertex2f(x - 15, y + 65);
	glColor3f(0.752941, 0.752941, 0.752941);
	glVertex2f(x, y + 75);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 15, y + 65);
	glColor3f(1.0, 0.843137, 0.0);
	glVertex2f(x + 25, y + 25);
	glColor3f(0.752941, 0.752941, 0.752941);
	glVertex2f(x + 25, y);
	glEnd();



	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f((x + 7 + r * cos(i)), (y + 55 + r * sin(i)));
	glEnd();

	//Golden axe at front
	glColor3f(1.0, 0.843137, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 75, y + 75);
	glVertex2f(x - 75, y + 85);
	glVertex2f(x + 75, y + 85);
	glVertex2f(x + 75, y + 75);
	glEnd();


	glColor3f(1.0, 0.843137, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 70, y + 40);
	glVertex2f(x - 70, y + 95);
	glVertex2f(x - 45, y + 95);
	glVertex2f(x - 45, y + 40);
	glEnd();


	//Silver axe behind
	glColor3f(0.752941, 0.752941, 0.752941);
	glBegin(GL_POLYGON);
	glVertex2f(x - 75, y + 85);
	glVertex2f(x - 70, y + 85);
	glVertex2f(x - 70, y + 90);
	glVertex2f(x - 75, y + 90);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 70, y + 95);
	glVertex2f(x - 45, y + 95);
	glVertex2f(x - 45, y + 100);
	glVertex2f(x - 70, y + 100);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 45, y + 85);
	glVertex2f(x + 75, y + 85);
	glVertex2f(x + 75, y + 90);
	glVertex2f(x - 45, y + 90);
	glEnd();

	//Normal Axe behind

	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 75, y + 90);
	glVertex2f(x - 70, y + 90);
	glVertex2f(x - 70, y + 95);
	glVertex2f(x - 75, y + 95);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 70, y + 100);
	glVertex2f(x - 45, y + 100);
	glVertex2f(x - 45, y + 105);
	glVertex2f(x - 70, y + 105);
	glEnd();

	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 45, y + 90);
	glVertex2f(x + 75, y + 90);
	glVertex2f(x + 75, y + 95);
	glVertex2f(x - 45, y + 95);
	glEnd();

}

void displayTextAll(float y)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(900.0, y);
	glVertex2f(950.0, 50.0 + y);
	glVertex2f(1100.0, 50.0 + y);
	glVertex2f(1100.0, y - 50.0);
	glVertex2f(950.0, y - 50.0);
	glEnd();
	char str36[] = "These all";
	char str37[] = " for you...!!!";
	displayHelp(str36, 950.0, y + 20.0);
	displayHelp(str37, 950.0, y - 10.0);
}

void keyTenth(unsigned char key, int x, int y)
{
	if (key == 'k' || key == 'K')
	{
		createNinthWindow();
	}
}