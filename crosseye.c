#include <stdlib.h>
#include <math.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

static int width;
static int height;

static double angle;

static void display(void) {

	float eye_dist = 0.5f;

	float eye_offset = (sin(angle/100.0)+1.0)/2.0;
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    glViewport(width/4-eye_offset*width/4, 0, width/2, height);
    glLoadIdentity();
    gluLookAt(eye_offset*eye_dist, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0f, 2*eye_offset-1, -1.0f);
    glRotatef(angle, 0.0f, 1.0f, 1.0f);
    glutSolidTeapot(1);
    glPopMatrix();

    glViewport(width/2+eye_offset*width/4-width/4, 0, width/2, height);
    glLoadIdentity();
    gluLookAt(-eye_offset*eye_dist, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0f, 2*eye_offset-1, -1.0f);
    glRotatef(angle, 0.0f, 1.0f, 1.0f);
    glutSolidTeapot(1);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();

}

static void reshape(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

static void animate () {
    angle += 1.0;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(animate);
    
    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    angle = 0;
    
    glutMainLoop();
    return EXIT_SUCCESS;
}
