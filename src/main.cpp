#include <GL/glut.h>
#include<iostream>
#include "ball.h"
#include<pthread.h>
float x=-0.02;
int refresh=10;
bool f = false;

using namespace std;

ball b[40];

void physics()
{
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(pow((b[i].ballX - b[j].ballX),2)+pow((b[i].ballY- b[j].ballY),2)+pow((b[i].ballZ - b[j].ballZ),2)<= 4* pow(radius,2))
			{
				if(b[i].ballX>b[j].ballX)
				b[i].ballX =b[i].ballX+radius/8;
				else 
				b[j].ballX =b[j].ballX+radius/8;
				GLfloat a, c,d;
				a=b[i].xSpeed;
				c=b[i].ySpeed;
				d=b[i].zSpeed;
				b[i].xSpeed=b[j].xSpeed;
				b[i].ySpeed=b[j].ySpeed;
				b[i].zSpeed=b[j].zSpeed;
				b[j].xSpeed=a;
				b[j].ySpeed=c;
				b[j].zSpeed=d;
			}
		}
	}
}

void keyPressed (unsigned char key, int x, int y)
{
	if (key=='+')
	{
		for(i=0;i<n;i++)
		{
			b[i].xSpeed+=0.04;
			b[i].ySpeed+=0.04;
			b[i].zSpeed+=0.04;
		}
	}
	if (key=='*')
	{
		for(i=0;i<n;i++)
		{
			b[i].xSpeed=b[i].ran(0.01,0.05);
			b[i].ySpeed=b[i].ran(0.01,0.05);
			b[i].zSpeed=b[i].ran(0.01,0.05);
		}
	}

	if(key=='l')
	radius=0.2f;
	if(key=='s')
	radius=0.05f;
	if(key=='m')
	radius=0.15f;
	
	if(key=='p')
	{
		for(i=0;i<n;i++)
		{
			b[i].xSpeed=0;
			b[i].ySpeed=0;
			b[i].zSpeed=0;
		}
	}
	if (key=='r')
	{
		for(i=0;i<n;i++)
		{
			b[i].xSpeed=b[i].ran(0.01,0.05);
			b[i].ySpeed=b[i].ran(0.01,0.05);
			b[i].zSpeed=b[i].ran(0.01,0.05);
		}
	}
}

GLdouble clipAreaXLeft,clipAreaXRight,clipAreaYTop,clipAreaYBottom,clipAreaZFront,clipAreaZBack;
void display()
{

	glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(x<-1.8 || f)
	{
		x+=0.005;
		f = true;
		if(x>-0.1)
		f = false;
	}
	else x-=0.002;

        
	glTranslatef(x,0.0,0);
	glBegin(GL_QUADS);        
	glColor3f(0.5f,0.5f,0.5f);    // top   
	glVertex3f( 2.0, 0.2,-1.2);    
	glVertex3f(-0.2, 0.2,-1.2);    
	glVertex3f(-0.2f, 0.2f, -0.6f);    
	glVertex3f( 2.0f, 0.2f, -0.6f);

	glColor3f(0.8f,0.8f,0.8f);    //bottom    
	glVertex3f( 2.0f,-0.2f, -0.6f);         
	glVertex3f(-0.2f,-0.2f,-1.2f);   
	glVertex3f( 2.0f,-0.2f,-1.2f);
	glVertex3f(-0.2f,-0.2f, -0.6f);     
		 
	glColor3f(0.7f,0.7f,0.7f);    //left   
	glVertex3f(-0.2f, 0.2f, -0.6f);   
	glVertex3f(-0.2f, 0.2f,-1.2f);    
	glVertex3f(-0.2f,-0.2f,-1.2f);    
	glVertex3f(-0.2f,-0.2f, -0.6f);    
	  
	glColor3f(0.7f,0.7f,0.7f);    //right    
	glVertex3f( 2.0f, 0.2f,-1.2f);    
	glVertex3f( 2.0f, 0.2f, -0.6f);      
	glVertex3f( 2.0f,-0.2f,-1.2f);
	glVertex3f( 2.0f,-0.2f, -0.6f);     

	glColor3f(0.392, 0.584, 0.929);    // back 
	glVertex3f( 2.0f,-0.2f,-1.2f);    
	glVertex3f(-0.2f,-0.2f,-1.2f);    
	glVertex3f(-0.2f, 0.2f,-1.2f);    
	glVertex3f( 2.0f, 0.2f,-1.2f);   
	glEnd();

	for( i=0;i<n;i++)
	{
		b[i].position();

	}
	physics();
	glutSwapBuffers();  
   
}


void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;   
	glMatrixMode(GL_PROJECTION);  
	    
	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
	GLdouble aspect =(GLdouble) x/(GLdouble)y;
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,x,y);  //Use the whole window for rendering
	glLoadIdentity();
	if(x>=y)
	{
		clipAreaXLeft=-1.0*aspect;
		clipAreaXRight=1.0*aspect;
		clipAreaYBottom=-1.0;
		clipAreaYTop=1.0;
	}
	else
	{
		clipAreaXLeft=-1.0;
		clipAreaXRight=1.0;
		clipAreaYBottom=-1.0/aspect;
		clipAreaYTop=1.0/aspect;
	}

	gluOrtho2D(clipAreaXLeft,clipAreaXRight,clipAreaYBottom,clipAreaYTop);
	ballXMin =clipAreaXLeft -(radius*4);
	ballXMax =clipAreaXRight+(radius*4);
	ballYMin =clipAreaYBottom -(radius*4);
	ballYMax =clipAreaYTop +(radius*4);

}

void initGL()
{
	glClearColor(0.0,0.0,0.0,0.1);

}
void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refresh,Timer,0);
}

int main (int argc, char **argv)
{ 
	n=atoi(argv[1]);
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
	glutInitWindowSize(700,700);
	glutCreateWindow("Solid Sphere");
	initGL(); 
	glutDisplayFunc(display);
	glutTimerFunc(10,Timer,0);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed); 
	glutMainLoop();
	return 0;
}

