#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle (White)
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glBegin(GL_TRIANGLES);
    	glVertex2f(-0.5f, -0.5f);
    	glVertex2f(0.0f, 0.5f);
    	glVertex2f(0.5f, -0.5f);
	glEnd();	

    // Translated triangle (Cyan)
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan
	glBegin(GL_TRIANGLES);
    	glVertex2f(0.0f, 0.0f);
    	glVertex2f(0.5f, 1.0f);
    	glVertex2f(1.0f, 0.0f);
	glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Triangle Translation");
    gluOrtho2D(-1, 1, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
}

