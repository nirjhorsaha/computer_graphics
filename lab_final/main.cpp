#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void CarBody()
{
    //body
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glBegin(GL_POLYGON);
    glVertex2f(140, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(240, 127);
    glVertex2f(240, 92);
    glVertex2f(110, 92);
    glVertex2f(110, 127);
    glVertex2f(130, 127);
    glVertex2f(140, 152);
    glEnd();

    glBegin(GL_POLYGON); //window
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    glVertex2f(140, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(120, 127);
    glVertex2f(130, 127);
    glEnd();

    glBegin(GL_POLYGON); //window-Divider
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(170, 152);
    glVertex2f(165, 152);
    glVertex2f(165, 127);
    glVertex2f(170, 127);
    glEnd();

    glBegin(GL_POLYGON); //roof-plate
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(140, 152);
    glVertex2f(190, 152);
    glVertex2f(185, 157);
    glVertex2f(140, 157);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-front
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(185, 152);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-back
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(140, 157);
    glVertex2f(115, 127);
    glVertex2f(125, 127);
    glVertex2f(140, 152);
    glEnd();

    glBegin(GL_POLYGON); //foot-holder
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(242, 92);
    glVertex2f(110, 92);
    glVertex2f(110, 97);
    glVertex2f(242, 97);
    glEnd();

    glBegin(GL_POLYGON);      //Yellow-headlight
    glColor3f(0.5f, 0.5f, 0.5f);//Violet
    glVertex2f(210.5+28, 134.5-10);
    glVertex2f(203.5+28, 135.5-10);
    glVertex2f(203.5+28, 129-10);
    glVertex2f(210.5+28, 127-10);
    glEnd();

    glBegin(GL_POLYGON); //window-opener-1
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(150-15-5, 127-5-3);
    glVertex2f(155-5-5, 127-5-3);
    glVertex2f(155-5-5, 129-5);
    glVertex2f(150-15-5, 129-5);
    glEnd();

    glBegin(GL_POLYGON); //window-opener-2
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(150-15+40, 127-5-3);
    glVertex2f(155-5+40, 127-5-3);
    glVertex2f(155-5+40, 129-5);
    glVertex2f(150-15+40, 129-5);
    glEnd();
}

void init()
{
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

float TireRotateAngle = 0.0f;

void CarTire(int xx, int yy, float r)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    glRotatef(TireRotateAngle, 0.0f, 0.0f,1.0f);
    glTranslatef(-0.0f,-0.0f,0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);//black-rim
    glVertex2f(-0.075,0);
    glVertex2f(0.075,0);
    glVertex2f(-0.05,-0.075);
    glVertex2f(0.05,0.075);
    glVertex2f(0.05,-0.075);
    glVertex2f(-0.05,0.075);
    glVertex2f(0,-0.1);
    glVertex2f(0,0.1);
    glEnd();

    glPopMatrix();

}
void ScaledTire()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(140.1,95,0);
    glScalef(80,80,0);
    glColor3ub(0,0,0);//black-tire
    CarTire(0, 0, 0.2);
    glPopMatrix();
}

void fullCar()
{
    CarBody();
    ScaledTire();
    glPushMatrix();
    glTranslatef(65,0,0);
    ScaledTire();
    glPopMatrix();

}

void CarReverse()
{
    glLineWidth(1);
    glTranslatef(-100.5, 0, 0);
    fullCar();
}

void ScaledCarReverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(300,140,0);
    glScalef(-0.5,0.5,0);
    CarReverse();
    glPopMatrix();
}

void MovingScaledCarReverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    ScaledCarReverse();
    glPopMatrix();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    MovingScaledCarReverse();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitWindowSize(1040, 800);     // Set the window's initial width & height
    glutCreateWindow("Car 191-15-12207"); // Create a window with the given title
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);     // Register display callback handler for window re-paint
    glutMainLoop();               // Enter the event-processing loop
    return 0;
}
