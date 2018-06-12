//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef AsteroidS_CPP_
#define AsteroidS_CPP_
#include "Board.h"
#include "NormalAsteroid.h"
#include "complexAsteroid.h"
#include "Base.h"
#include "Shooter.h"
#include<iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/*void DrawAsteroid(const int & cx, const int &cy, const ColorNames & cname=RED) // center of Asteroid
		{
	int radius = 50; // sample radius
	int rndpoint = GetRandInRange(0, 9);
	int npoints = MAX(4, rndpoint);
	cout << npoints << endl;
	int dtheta = 360 / npoints;
	// using the formula rcostheta and rsin theta;
	float theta = GetRandInRange(0, dtheta);
	int sx = cx + radius * cos(Deg2Rad(theta)), sy = cy
			+ radius * sin(Deg2Rad(theta));
	int x1 = sx;
	int y1 = sy;
	int stheta = dtheta;
	for (int i = 0; i < npoints - 1; ++i) {
		theta = GetRandInRange(stheta, stheta + dtheta);
		int x2 = cx + radius * cos(Deg2Rad(theta)), y2 = cy
				+ radius * sin(Deg2Rad(theta));
		DrawLine(x1, y1, x2, y2, 10, colors[cname]);
		x1 = x2;
		y1 = y2;
		stheta += dtheta;
	}
	DrawLine(x1, y1, sx, sy, 10, colors[cname]);

}
void DrawAsteroid(int x/*starting x, int y/*starting y*/
	//	ColorNames color/*color*/, float radius = 6/*Asteroid radius in Units*/,
	//	const int corners = 7/*Asteroid corners*/) {
	/*int ogr = 6, ogh = 7;

	glPushMatrix();
	float sx = (float) radius / ogr;
	//glTranslatef(x, y, 1);
	//glScalef(sx, 1, 1);

	// Draw Asteroid here
	const int nvertices = 722;
	GLfloat vertices[nvertices][2];
	float hdegree = M_PI / (corners / 2);
	float angle = 0;
	for (int i = 0; i < nvertices; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}

	glColor3fv(colors[color]); // set the circle color
	glBegin (GL_TRIANGLE_FAN);
	glVertex4f(x, y, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(x + vertices[i][0], y + vertices[i][1], 0, 1);
	glEnd();

	glPopMatrix();
}
*/
/*
 * Main Canvas drawing function.
 * */
Board *b;
//Base** basee;

//NormalAsteroid *as[4];
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the backgound play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	// draw four asteroids
	//int numAst=4;
	/*for(int i=0;i<4;i++)
	{
		cout<<basee[4]->collision(basee[i]->getXCo(),basee[i]->getYCo(),basee[i]->getRad(),i,0)
	}*/
	
	/*for(int i=11+(b->getLevel()*2);i<11+(b->getLevel()*2)+(2+(2*b->getLevel()));i++)
	{
		if(b->base[10]->collision(b->base[i]->getXCo(),b->base[i]->getYCo(),b->base[i]->getRad()))
		{
			b->Hit();
			b->base[10]->Destroy();
			break;
		}
	}*/
	/*for(int i=0;i<10;i++)
	{
		if(b->base[i]->BulletAttack())
			b->base[i]->Shoot(b->base[10]->getXCo(),b->base[10]->getYCo(),b->base[10]->getDx(),b->base[10]->getDy());
	}*/
	
	/*for(int i=11+(b->getLevel()*2)+(2+(b->getLevel()*2));i<(11+(b->getLevel()*2)+(2+(b->getLevel()*2)))+(b->getDestroy()*2);i++)
	{
		b->base[i]->Draw();
		b->base[i]->Move();
		if(b->base[10]->collision(b->base[i]->getXCo(),b->base[i]->getYCo(),b->base[i]->getRad()))
		{
			
			float xx,yy;
			xx=b->base[i]->getXCo();
			yy=b->base[i]->getYCo();
			b->Hit();
			b->base[10]->Destroy();
			if(b->base[i]->getSize()=='m')
			{
				b->SmallSplit(xx,yy);
				b->Destroy();
				b->base[i]->Destroy();
			}
			else
			{
				b->base[i]->Destroy();
				b->smallDestroy();
			}
		}
		
	}*/
	b->Draw();
	if(b->getMenu()==0)
	{
		b->StartScreen();
	}
	else
	{
		b->MoveAsteroid();
		b->ShooterAsteCheck();
		b->ShooterAsteCheck();
		b->BulletShoot();
		b->BulletAsteCheck();
		b->DrawSaucer();
		b->SaucerHit();
		b->SaucerAsteCheck();
		b->SaucerEntry();
		b->ShooterMedAsteCheck();
		b->SaucerBullet();
		b->DrawShooter();
		b->nextLevel();
		b->SaucerShooterCheck();
	}
	if(b->getMenu()==2)
	{
		b->EndScreen();
	}
	//b->DrawSaucer();
	//b->base[10]->Draw();
	//b->sh->Stars();
	/*if(b->sh->getMenu())
	{
	/*for(int i=0;i<numAst;i++)
	{
		sh->as[i]->Move();
	}
	//b->sh->DrawScore("Score: ");
	}*/
	//b->sh->DrawShooter();
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		b->base[10]->Move(1);

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
				b->base[10]->Move(2);

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
				if(b->getMenu()==2)
				{
					b->TryAgain(1);
				}
				else
				{
					b->base[10]->Thrust();
				}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
				if(b->getMenu()==2)
				{
					b->TryAgain(2);
				}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		b->base[b->base[0]->getAttack()]->Attack();
		

	}
	if(key == 13)
	{
		if(b->getMenu()==0)
		{
			b->setMenu(b->getMenu()+1);
		}
		if(b->getMenu()==2)
		{
			b->Choice();
		}
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
		MousePressedAndMoved(x,y);

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
//	srand(time(NULL));
//	int seeed=rand();
	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	//srand(seeed);
	//NormalAsteroid as(rand()%1024,rand()%840,'l');
	//basee=new Base*[15];
	/*for(int i=0;i<4;i++)
	{
		srand(seeed);
		as[i]=new NormalAsteroid(rand()%1024,rand()%840,'l');
		seeed+=2510;
	}*/
	//for(int i=0;i<4;i++)
	/*for(int i=0;i<4;i++)
	{
		srand(seeed);
		basee[i]=new NormalAsteroid(rand()%1024,rand()%840,'l');
		seeed+=34343;
	}*/
	//basee[4]=new Shooter(512,420);
	//for(int i=5;i<15;i++)
	//basee[i]=new Bullet();
	//sh=new Shooter(512,420);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Asteroids"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
