
#include <GLUT/glut.h>

#define maxx 20
#define maxy 30
#define dx 10
#define dy 15

float x[maxx], y[maxy];
int i, j;

void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    glColor3f(0, 0, 1);

    // Calculate x coordinates
    for(i = 0; i < maxx; i++)
        x[i] = 50 + i * dx;

    // Calculate y coordinates
    for(j = 0; j < maxy; j++)
        y[j] = 50 + j * dy;

    // Draw rectangular mesh
    for(i = 0; i < maxx-1; i++)
    {
        for(j = 0; j < maxy-1; j++)
        {
            glBegin(GL_LINE_LOOP);
            glVertex2f(x[i], y[j]);
            glVertex2f(x[i], y[j+1]);
            glVertex2f(x[i+1], y[j+1]);
            glVertex2f(x[i+1], y[j]);
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rectangular Mesh");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
