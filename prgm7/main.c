
#include <GLUT/glut.h>
#include <stdio.h>

float house[2][9] = {
    // {100,100,175,250,250,150,150,200,200},
    // {100,300,400,300,100,100,150,150,100}
    {100,100,200,400,400,200,200,300,300},{100,300,400,300,100,100,200,200,100}
};

float angle;
float h = 100, k = 100;

void init()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,499,0,499);
}

void drawHouse()
{
    // House body
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][0],house[1][0]);
        glVertex2f(house[0][1],house[1][1]);
        glVertex2f(house[0][3],house[1][3]);
        glVertex2f(house[0][4],house[1][4]);
    glEnd();

    // Roof
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][1],house[1][1]);
        glVertex2f(house[0][2],house[1][2]);
        glVertex2f(house[0][3],house[1][3]);
    glEnd();

    // Door
    glColor3f(1,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][5],house[1][5]);
        glVertex2f(house[0][6],house[1][6]);
        glVertex2f(house[0][7],house[1][7]);
        glVertex2f(house[0][8],house[1][8]);
    glEnd();
}

void display()
{
    // Original house
    drawHouse();

    // Rotated house about fixed point (100,100)
    glPushMatrix();
        glTranslatef(h,k,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-h,-k,0);
        drawHouse();
    glPopMatrix();

    glFlush();
}

int main(int argc,char **argv)
{
    printf("Enter rotation angle: ");
    scanf("%f",&angle);

    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);  //can be (500,500) also
    glutCreateWindow("House Rotation");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
