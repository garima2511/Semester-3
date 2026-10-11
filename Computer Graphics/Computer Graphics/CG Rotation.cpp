#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    initwindow(900, 650, "Triangle Rotation about Arbitrary Point");

    // Original triangle points
    int Ax = 40, Ay = 70;
    int Bx = 50, By = 50;
    int Cx = 30, Cy = 60;

    // Pivot point
    int h = 30, k = 30;

    // Angle in degrees
    float angle = 45;
    float rad = angle * 3.14159 / 180;

    // Draw original triangle
    setcolor(WHITE);
    line(Ax, Ay, Bx, By);
    line(Bx, By, Cx, Cy);
    line(Cx, Cy, Ax, Ay);
    outtextxy(20, 20, (char*)"Original Triangle");

    // Draw pivot point
    setcolor(YELLOW);
    circle(h, k, 3);
    outtextxy(300, 50, (char*)"Pivot (30,30)");

    int A1x = h + (Ax - h) * cos(rad) - (Ay - k) * sin(rad);
    int A1y = k + (Ax - h) * sin(rad) + (Ay - k) * cos(rad);

    int B1x = h + (Bx - h) * cos(rad) - (By - k) * sin(rad);
    int B1y = k + (Bx - h) * sin(rad) + (By - k) * cos(rad);

    int C1x = h + (Cx - h) * cos(rad) - (Cy - k) * sin(rad);
    int C1y = k + (Cx - h) * sin(rad) + (Cy - k) * cos(rad);

    // Draw rotated triangle
    setcolor(CYAN);
    line(A1x, A1y, B1x, B1y);
    line(B1x, B1y, C1x, C1y);
    line(C1x, C1y, A1x, A1y);
    outtextxy(20, 70, (char*)"Rotated Triangle (45 deg CCW)");

    // -------- Rotation Matrix Display --------
    setcolor(GREEN);
    outtextxy(550, 60, (char*)"Rotation Matrix (3x3)");

    char buffer[60];
    sprintf(buffer, "[ cos45  -sin45   %d ]", h);
    outtextxy(550, 90, buffer);
    sprintf(buffer, "[ sin45   cos45   %d ]", k);
    outtextxy(550, 120, buffer);
    sprintf(buffer, "[   0          0        1    ]");
    outtextxy(550, 150, buffer);

    getch();
    closegraph();
    return 0;
}
