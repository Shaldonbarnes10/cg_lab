
#include <GLUT/glut.h>

void init()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

void draw(int x, int y)
{
    glClear(GL_COLOR_BUFFER_BIT);

    y = 500-y;

    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(x+10,y+10);
        glVertex2f(x-10,y+10);
        glVertex2f(x-10,y-10);
        glVertex2f(x+10,y-10);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        draw(x,y);
}

void display()
{
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Mouse Interaction");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
