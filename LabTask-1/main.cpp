#include <windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<GL/gl.h>

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,300.0,0.0,300.0);
}

float a = 50.0;
float b = 250.0;
float p = 50.0;
float q = 250.0;
float x = 20.0;

void Draw(){

    glClear(GL_COLOR_BUFFER_BIT);

    if (x<= 300)
    x = x+.009;
    else
    x=0;

    if (b <= 270)
        b = b + .002;

    else
        b = 250.0;

    if (a <= 80)
        a = a + .002;

    else
        a = 50.0;

    if (p <= 58)
        p=p+.002;

    else
        p=49;


    glutPostRedisplay();


    //Code of kite
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.0,1.0);
    glVertex2i(a+145,b-10);
    glVertex2i(a+140,b-50);
    glVertex2i(a+175,b-70);
    glVertex2i(a+180,b-30);
    glEnd();


    //Code of kite edge
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,0.1);
    glVertex2i(a+145,b-10);
    glVertex2i(a+175,b-70);
    glEnd();

    //Code of kite edge
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,0.1);
    glVertex2i(a+140,b-50);
    glVertex2i(a+180,b-30);
    glEnd();


    // code of kite tail
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,0.1);
    glVertex2i(a+140,b-50);
    glVertex2i(a+120,b-90);
    glEnd();


    //Code of lines or rope
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2i(a+160,b-40);
    glVertex2i(a+140,b-100);
    glVertex2i(a+140,b-100);
    glVertex2i(a+110,b-140);
    glVertex2i(a+110,b-140);
    glVertex2i(a+90,b-170);
    glVertex2i(a+90,b-170);
    glVertex2i(a+20,b-190);

    glEnd();


    //code of human body
    glBegin(GL_POLYGON);

    glColor3f(0.1,1.0,1.0);

    glVertex2i(p,q-150);
    glVertex2i(p,q-200);
    glVertex2i(p+50,q-200);
    glVertex2i(p+50,q-150);

    glEnd();


    //Code for lower head part
    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);

    glVertex2i(p+20,q-133);
    glVertex2i(p+20,q-150);
    glVertex2i(p+30,q-150);
    glVertex2i(p+30,q-133);

    glEnd();




    //code for upper head part
    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);

    glVertex2i(p+15,q-128);
    glVertex2i(p+15,q-138);
    glVertex2i(p+20,q-141);
    glVertex2i(p+30,q-141);
    glVertex2i(p+35,q-138);
    glVertex2i(p+35,q-128);
    glVertex2i(p+30,q-125);
    glVertex2i(p+20,q-125);

    glEnd();

    // Code for leg

    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);

    glVertex2i(p+5,q-200);
    glVertex2i(p+5,q-220);
    glVertex2i(p+15,q-220);
    glVertex2i(p+15,q-200);

    glEnd();

    glBegin(GL_POLYGON);        //Code for shoe
    glColor3f(0.1,1.0,1.0);

    glVertex2i(p+2,q-220);
    glVertex2i(p+2,q-230);
    glVertex2i(p+18,q-230);
    glVertex2i(p+18,q-220);

    glEnd();



    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);

    glVertex2i(p+35,q-200);
    glVertex2i(p+35,q-220);
    glVertex2i(p+45,q-220);
    glVertex2i(p+45,q-200);

    glEnd();


    glBegin(GL_POLYGON);        //Code for shoe

    glColor3f(0.1,1.0,1.0);

    glVertex2i(p+32,q-220);
    glVertex2i(p+32,q-230);
    glVertex2i(p+48,q-230);
    glVertex2i(p+48,q-220);

    glEnd();

glutSwapBuffers();

}

int main(int argc, char**argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Task 1");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
