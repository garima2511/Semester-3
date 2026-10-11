#include <GL/glut.h>

float angleX = 0.0f, angleY = 0.0f;

// Draw cube with grayscale shades
void drawCube() {
    glBegin(GL_QUADS);

    // Front (Light Gray)
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(1, 1, 1); glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1); glVertex3f(1, -1, 1);

    // Back (Dark Gray)
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(1, 1, -1); glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1); glVertex3f(1, -1, -1);

    // Top (Medium Gray)
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(1, 1, 1); glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1); glVertex3f(1, 1, -1);

    // Bottom (Darker Gray)
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(1, -1, 1); glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1); glVertex3f(1, -1, -1);

    // Right (Medium-Light Gray)
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(1, 1, 1); glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1); glVertex3f(1, 1, -1);

    // Left (Gray)
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-1, 1, 1); glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1); glVertex3f(-1, 1, -1);

    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Move cube into view
    glTranslatef(0.0f, 0.0f, -6.0f);

    // Rotate cube
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    drawCube();

    glutSwapBuffers();
}

// Arrow key controls
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) angleX -= 5;
    else if (key == GLUT_KEY_DOWN) angleX += 5;
    else if (key == GLUT_KEY_LEFT) angleY -= 5;
    else if (key == GLUT_KEY_RIGHT) angleY += 5;

    glutPostRedisplay();
}

// Projection setup
void reshape(int w, int h) {
    if (h == 0) h = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Initialization
void init() {
    glClearColor(0, 0, 0, 1); // black background
    glEnable(GL_DEPTH_TEST);  // enable depth
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Rotating Cube - Grayscale");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
