#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  gluOrtho2D(0.0,600.0,0.0,600.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1

}

float p = 100;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(p<=600)
    {
        p+=.007;
        glutPostRedisplay();
    }
    else{
        p=0;
        glutPostRedisplay();
    }

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2i(p,75);
    glVertex2i(p+100,75);
    glVertex2i(p+125,150);
    glVertex2i(p-25,150);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0,0.7,0.0);
    glVertex2i(p+60,150);
    glVertex2i(p+80,150);
    glVertex2i(p+80,200);
    glVertex2i(p+60,200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(p+30,190);
    glVertex2i(p+80,170);
    glVertex2i(p+80,210);
    glEnd();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
