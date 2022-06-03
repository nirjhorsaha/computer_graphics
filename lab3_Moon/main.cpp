#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>
float rx , ry ,cx, cy;

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  gluOrtho2D(-15.0,15.0,-15.0,15.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

void Circle(GLfloat rx, GLfloat ry,GLfloat cx, GLfloat cy)
   {
       glBegin(GL_TRIANGLE_FAN);
       glVertex2f(cx,cy);
       for(int i=0; i<=100;i++){
        float angle = -2 * 3.1416 * i/100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
       }
       glEnd();

   }
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1.0f , 0.0f, 1.0f);
    Circle(3,3,-0,0);
    glColor3f( 0.0f , 0.0f, 0.0f);
    Circle(3,3,1,1 );

// Write your Code


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
