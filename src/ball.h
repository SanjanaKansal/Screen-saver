#include<math.h>
#include<cmath>
#define PI 3.14159265f
#include<unistd.h>
#include <GL/freeglut.h>
#include<random>
#include <chrono>
#include<iostream>
#include"ext.h"
int i,n;

using namespace std;
GLfloat ballXMax,ballXMin,ballYMax,ballYMin,ballZMax,ballZMin;
GLfloat radius;
class ball
{


	public:

	GLfloat xRotated;
	GLfloat yRotated;
	GLfloat zRotated;

	GLfloat ballX;
	GLfloat ballY;
	GLfloat ballZ;

	GLfloat xSpeed;
	GLfloat ySpeed;
	GLfloat zSpeed;


	float ran(float a, float b);
	ball();
	void position();

};




float ball::ran(float a, float b)
{
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

ball::ball()
{
	static bool seedi= false;
	if(!seedi)
	{
		srand(time(NULL));
		seedi = true;
	}
	ballX=ran(-0.2,2.0);
	ballY=ran(-0.2,0.2);
	ballZ=ran(-5.0,-6.0);
	xRotated=43;
	yRotated=30;
	zRotated=50;
	radius =0.15f;
	xSpeed=ran(0.01,0.05);
	ySpeed=ran(0.01,0.05);
	zSpeed=ran(0.01,0.05);
	
}



 void  ball:: position()

{
  
	glTranslatef(ballX,ballY,ballZ);
	glColor3f(ballX,ballY,ballZ); 
	glutWireSphere(radius,20,20);
	glScalef(1.0,1.0,1.0);
	glVertex2f(0.0f,0.0f);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	 
	int numSegments=100;
	GLfloat angle;
	for(int i=0;i<=numSegments;i++)
	{
		angle=i* 2.0f*PI/numSegments;
		glVertex2f(cos(angle)*radius,sin(angle)*radius);
	}
	ballX+=xSpeed;
	ballY+=ySpeed;
	ballZ+=zSpeed;


	if(ballX>ballXMax)
	{
		ballX=ballXMax;
		xSpeed = -xSpeed;
	}
	if(ballX<ballXMin)
	{
		ballX=ballXMin;
		xSpeed = -xSpeed;
	}
	if(ballY>ballYMax)
	{
		ballY=ballYMax;
		ySpeed = -ySpeed;
	}
	else if(ballY<ballYMin)
	{
		ballY=ballYMin;
		ySpeed = -ySpeed;
	}
	if(ballZ<-6.0f)
	{
		zSpeed=-zSpeed;
	}
	if(ballZ>-5.0f)
	{
	zSpeed=-zSpeed;
	}
}



