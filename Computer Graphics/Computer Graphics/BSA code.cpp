#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void BSAalgo(int x1, int y1, int x2, int y2) {
	int dx, dy, x, y;
	
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
  		
	x = x1;
    y = y1;
    
    int sx = (x2 >= x1) ? 1 : -1; // step direction for x
    int sy = (y2 >= y1) ? 1 : -1; // step direction for y

    // If slope < 1
    if (dx >= dy) {
        int p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);
            delay(50);
            cout << "Plotting point: (" << x << ", " << y << ")\n";

            x += sx;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y += sy;
                p += 2 * (dy - dx);
            }
        }
    } 
    // If slope > 1
    else {
        int p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);
            delay(50);
            cout << "Plotting point: (" << x << ", " << y << ")\n";

            y += sy;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x += sx;
                p += 2 * (dx - dy); 
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    initgraph(&gd, &gm, "");

    BSAalgo(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
