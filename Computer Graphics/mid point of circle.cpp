#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

void drawcircle(int xc, int yc, int r) {
	int x = 0;
	int y = r;
	int p = 1 - r;
	
	while(x<=y) {
		cout << "(" << xc + x << "," << yc + y << ") ";
        cout << "(" << xc - x << "," << yc + y << ") ";
        cout << "(" << xc + x << "," << yc - y << ") ";
        cout << "(" << xc - x << "," << yc - y << ") ";
        cout << "(" << xc + y << "," << yc + x << ") ";
        cout << "(" << xc - y << "," << yc + x << ") ";
        cout << "(" << xc + y << "," << yc - x << ") ";
        cout << "(" << xc - y << "," << yc - x << ") ";
        cout << endl;
        
		putpixel(xc + x, yc + y, GREEN);
		putpixel(xc - x, yc + y, WHITE);
		putpixel(xc + x, yc - y, RED);
		putpixel(xc - x, yc - y, YELLOW);
		putpixel(xc + y, yc + x, WHITE);
		putpixel(xc - y, yc + x, BROWN);
		putpixel(xc + y, yc - x, BLUE);
		putpixel(xc - y, yc - x, RED);
		delay(10);
		
		if(p < 0) {
			p = p + 2*x + 1;
		}
		else {
			y--;
			p = p + 2*x + 1 - 2*y;
		}
		x++;
	}
}
int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, " ");
	
	int xc, yc, r;
	cout<<"\nEnter center: ";
	cin>>xc>>yc;
	cout<<"\nEnter radius: ";
	cin>>r;
	
	drawcircle(xc, yc, r);
	getch();
	closegraph();
	return 0;
}
