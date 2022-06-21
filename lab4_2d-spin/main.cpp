/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
//#include<stdarg.h>

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glTranslatef(tx,ty,0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();


	glFlush();
}

void spinDisplay_left(void)
{
   spin = spin + 10;

   glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - 10;

   glutPostRedisplay();
}


void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0,100.0, -1.0, 1.0);
}


void my_keyboard(unsigned char key,int x, int y)//In main(), To register a callback to the keyboard function,
{

	switch (key) {

		case 'l':
			spinDisplay_left();
			break;

		case 'r':
			spinDisplay_right();
			break;

		case 's':
			 glutIdleFunc(NULL); //idle callback is continuously called when events are not being received
			 break;

	  default:
			break;
	}
}

void spe_key(int key, int x, int y) // glutSpecialFunc sets the special keyboard callback for the current window
{

	switch (key) {

		case GLUT_KEY_UP:
				ty +=5;
				PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
				glutPostRedisplay();
				break;


		case GLUT_KEY_DOWN:
		    PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
				ty -=5;
				glutPostRedisplay();
				break;


        case GLUT_KEY_RIGHT:
            PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
				tx +=5;
				glutPostRedisplay();
				break;


		case GLUT_KEY_LEFT:
		    PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
				tx -=5;
				glutPostRedisplay();
				break;


	  default:
			break;
	}
}


void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;

      case GLUT_MIDDLE_BUTTON:

      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);
         break;

      default:
         break;
   }
}

int main()
{
	//PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("LAB3");
	init();

    glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}
