
#include <GLUT/glut.h>
#include <stdio.h>

int x0,y0,x1,y1;

void init()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
}

void writepixel(int x,int y)
{
    glPointSize(5);
    glBegin(GL_POINTS);          //WRITE PIXEL
    glColor3f(0,0,0);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void display()
{
    int i,j;

    float dx=x1-x0 , dy = y1-y0;
    float d = 2*dy-dx;

    float incrE = dy;
    float incrNE = dy - dx;

    int x=x0,y=y0;

    writepixel(x,y);

    while(x<x1)
    {
        if(d<=0)
        {
            d=d+2*incrE;
            x=x+1;
        }
        else
        {
            d=d+2*incrNE;
            x=x+1;
            y=y+1;
        }

        writepixel(x,y);
    }
}

int main(int argc,char *argv[])
{
    printf("Enter the values \n");
    printf("x0="); scanf("%d",&x0);
    printf("y0="); scanf("%d",&y0);
    printf("x1="); scanf("%d",&x1);
    printf("y1="); scanf("%d",&y1);

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("MIDPOINT LINE ALGORITHM");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
