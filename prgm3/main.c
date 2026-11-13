
#include <GLUT/glut.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

double xmin=50, ymin=50, xmax=100, ymax=100;

void init()
{
    glClearColor(1,1,1,1);  
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

int code(double x, double y)
{
    int c=0;

    if(x<xmin) c|=LEFT;
    if(x>xmax) c|=RIGHT;
    if(y<ymin) c|=BOTTOM;
    if(y>ymax) c|=TOP;

    return c;
}

void clip(double x1,double y1,double x2,double y2)
{
    int c1=code(x1,y1), c2=code(x2,y2);
    double x,y;
    int c;

    while(1)
    {
        if(!(c1|c2))
            break;

        if(c1&c2)
            return;

        c = c1 ? c1 : c2;

        if(c&TOP)
        {
            x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
            y=ymax;
        }
        else if(c&BOTTOM)
        {
            x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
            y=ymin;
        }
        else if(c&RIGHT)
        {
            y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
            x=xmax;
        }
        else
        {
            y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
            x=xmin;
        }

        if(c==c1)
        {
            x1=x;
            y1=y;
            c1=code(x1,y1);
        }
        else
        {
            x2=x;
            y2=y;
            c2=code(x2,y2);
        }
    }

    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(4*xmin,4*ymin);
    glVertex2d(4*xmax,4*ymin);
    glVertex2d(4*xmax,4*ymax);
    glVertex2d(4*xmin,4*ymax);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(4*x1,4*y1);
    glVertex2d(4*x2,4*y2);
    glEnd();
}

void display()
{
    double x1=60,y1=20,x2=80,y2=120;

    // Original clipping window
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xmin,ymin);
    glVertex2d(xmax,ymin);
    glVertex2d(xmax,ymax);
    glVertex2d(xmin,ymax);
    glEnd();

    // Original line
    glBegin(GL_LINES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glEnd();

    // Clipped result
    clip(x1,y1,x2,y2);

    glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(800,800);
    glutCreateWindow("Cohen Sutherland Line Clipping");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
