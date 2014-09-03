#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE  1
#define FALSE 0

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define my_assert(X,Y) ((X)?(void) 0:(printf("error:%s in %s at %d", Y, __FILE__, __LINE__), myabort()))
#define my_rnd ((double)rand() / (double)RAND_MAX)
#define dx 0.01

#define DELTA_TIME 10  /* defined to be 10 msec */

void myabort(void);
void glut_setup(void) ;
void gl_setup(void) ;
void my_setup(int argc, char **argv);
void my_display(void) ;
void my_reshape(int w, int h) ;
void my_keyboard(unsigned char key, int x, int y);
void my_mouse_drag(int x, int y);
void my_mouse(int button, int state, int mousex, int mousey);
void my_idle(void);


struct bullet{
    float x;
    float y;
};

void myabort(void) {
	abort();
	exit(1); /* exit so g++ knows we don't return. */
}

struct bullet b;


int main(int argc, char **argv) {
    // Setup seed
    srand(time(NULL));
    // Setup Bullet.
    b.y = my_rnd;
    b.x = -0.05;
	/* General initialization for GLUT and OpenGL
     Must be called first */
	glutInit( &argc, argv ) ;

	/* we define these setup procedures */
	glut_setup() ;
	gl_setup() ;
	my_setup(argc, argv);

	/* go into the main event loop */
	glutMainLoop() ;

	return(0) ;
}

/* This function sets up the windowing related glut calls */
void glut_setup(void) {

	/* specify display mode -- here we ask for a double buffer and RGB coloring */
	glutInitDisplayMode (GLUT_DOUBLE |GLUT_RGB);

	/* make a 400x300 window with the title of "GLUT Skeleton" placed at the top left corner */
	glutInitWindowSize(400,300);
	glutInitWindowPosition(0,0);
	glutCreateWindow("GLUT Demo 1");

	/*initialize callback functions */
	glutDisplayFunc( my_display );
	glutReshapeFunc( my_reshape );
	glutMouseFunc( my_mouse);
	glutMotionFunc( my_mouse_drag);
	glutKeyboardFunc (my_keyboard);
	glutIdleFunc( my_display );


	return ;
}

/* This function sets up the initial states of OpenGL related enivornment */
void gl_setup(void) {

	/* specifies a background color: black in this case */
	glClearColor(0,0,0,0) ;

	/* setup for simple 2d projection */
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	/* set the viewable portion  */
	gluOrtho2D(0, 1.0, 0, 1.0);
	return ;
}

void my_setup(int argc, char **argv) {
	return;
}

void my_reshape(int w, int h) {
	/* define viewport -- x, y, (origin is at lower left corner) width, height */
	glViewport (0, 0, w, h);
}

/* Sample keyboard callback function.
 This allows the user to quit the program
 by typing the letter q.
 */
void my_keyboard( unsigned char key, int x, int y ) {

	switch( key ) {
		case 'q':
		case 'Q':
			exit(0) ;
			break ;
		default: break;
	}
	return ;
}

/* currently doesn't do anything */
void my_mouse_drag(int x, int y) {
	return;
}

/* stubbed but doesn't do anything either
 (mousex, mousey) are in screen coordinates
 that is, (0,0) is at the upper left corner
 */
void my_mouse(int button, int state, int mousex, int mousey) {
}

void my_display(void) {
	/* clear the buffer */
	glClear(GL_COLOR_BUFFER_BIT) ;

	glColor3f(0,0, 0) ;

	/* draw something */
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,1);
	glVertex2f(1,1);
	glVertex2f(1,0);
	glEnd();

	glColor3f(0,1,0) ;

	/* draw something */
	glBegin(GL_POLYGON);
	glVertex2f(0.25,0.75);
	glVertex2f(0.75,0.75);
	glVertex2f(0.75,0.25);
	glVertex2f(0.25, 0.25);
	glEnd();

	// Rainbow
	// Red
	float x = 0.0;
	float y = 0.0;
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	while(x < 1.0){
        y = sqrt(0.25 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

    // Orange
	glColor3f(1, 0.5, 0);
	glBegin(GL_POLYGON);
	x = 0.05;
	while(x < 1.0){
        y = sqrt(0.2025 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	// Yellow
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	x = 0.05;
	while(x < 1.0){
        y = sqrt(0.2025 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	// Green
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	x = 0.1;
	while(x < 1.0){
        y = sqrt(0.16 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	//Blue
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	x = 0.15;
	while(x < 1.0){
        y = sqrt(0.1225 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	//Indego
	glColor3f(0.29, 0, 0.51);
	glBegin(GL_POLYGON);
	x = 0.20;
	while(x < 1.0){
        y = sqrt(0.09 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	// Violet
	glColor3f(0.56, 0, 1);
	glBegin(GL_POLYGON);
	x = 0.25;
	while(x < 1.0){
        y = sqrt(0.0625 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	// Black
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	x = 0.30;
	while(x < 1.0){
        y = sqrt(0.04 - (x-0.5)*(x-0.5));
        glVertex2f(x, y);
        x += 0.01;
	}
	glEnd();

	// Changed the Color to see things over background.
	glColor3f(0,0,1);

	// A simple "H"
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.25);
    glVertex2f(0.25, 0.75);
    glVertex2f(0.30, 0.75);
    glVertex2f(0.30, 0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.30, 0.525);
    glVertex2f(0.40, 0.525);
    glVertex2f(0.40, 0.475);
    glVertex2f(0.30, 0.475);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.40, 0.75);
    glVertex2f(0.45, 0.75);
    glVertex2f(0.45, 0.25);
    glVertex2f(0.40, 0.25);
    glEnd();

    // And now an "I"
    glBegin(GL_POLYGON);
    glVertex2f(0.50, 0.25);
    glVertex2f(0.70, 0.25);
    glVertex2f(0.70, 0.30);
    glVertex2f(0.50, 0.30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.575, 0.30);
    glVertex2f(0.575, 0.70);
    glVertex2f(0.625, 0.70);
    glVertex2f(0.625, 0.30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.50, 0.70);
    glVertex2f(0.70, 0.70);
    glVertex2f(0.70, 0.75);
    glVertex2f(0.50, 0.75);
    glEnd();

    // "!" Base.
    glBegin(GL_POLYGON);
    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75);
    glVertex2f(0.80, 0.75);
    glVertex2f(0.80, 0.25);
    glEnd();

    // Fixing the "!" to add a dot.
    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f(0.75, 0.30);
    glVertex2f(0.75, 0.35);
    glVertex2f(0.80, 0.35);
    glVertex2f(0.80, 0.30);
    glEnd();

    glColor3f(1, 1, 1);


    // Test
    /*
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.05);
    glVertex2f(x + 0.05, y + 0.05);
    glVertex2f(x + 0.05, y);
    glEnd();
    */

    b.x += dx;

    glBegin(GL_POLYGON);
    glVertex2f(b.x, b.y);
    glVertex2f(b.x, b.y + 0.05);
    glVertex2f(b.x + 0.05, b.y + 0.05);
    glVertex2f(b.x + 0.05, b.y);
    glEnd();

    if(b.x > 1){
        b.x = -0.10;
        b.y = my_rnd;
    }

	/* buffer is ready */
	glutSwapBuffers();

	return ;
}


void my_idle(void) {
	return ;
}
