
#include <stdio.h>
#include <GLUT/glut.h>

float x[] = {20, 10, 20, 30};
float y[] = {20, 30, 40, 30};

void init()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,50,0,50);
}

void edgedetect(float x1, float y1, float x2, float y2, int le[], int re[])
{
    float mx, temp;

    if(y1 > y2)
    {
        temp=y1; y1=y2; y2=temp;
        temp=x1; x1=x2; x2=temp;
    }

    if(y1 == y2) return;

    mx = (x2-x1)/(y2-y1);

    for(int i=(int)y1; i<=(int)y2; i++)
    {
        if(x1 < le[i]) le[i] = (int)x1;
        if(x1 > re[i]) re[i] = (int)x1;

        x1 += mx;
    }
}

void scanfill()
{
    int le[500], re[500];

    for(int i=0; i<500; i++)
    {
        le[i]=500;
        re[i]=0;
    }

    for(int i=0; i<4; i++)
        edgedetect(x[i],y[i],x[(i+1)%4],y[(i+1)%4],le,re);

    glColor3f(0,1,0);
    glPointSize(3);

    glBegin(GL_POINTS);

    for(int j=0; j<500; j++)
        for(int i=le[j]; i<re[j]; i++)
            glVertex2i(i,j);

    glEnd();
    glFlush();
}

void display()
{
    scanfill();

    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);

    for(int i=0; i<4; i++)
        glVertex2f(x[i],y[i]);

    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    // glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Scan Line Filling");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
