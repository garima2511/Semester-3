#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<sstream>
using namespace std;

int main() {
	int x, y;
	int gd = DETECT, gm;
	initgraph( &gd, &gm, " ");
	
	int A[3] = {100, 100, 1};
    int B[3] = {150,  50, 1};
    int C[3] = {200, 100, 1};
    
    cout<<"\nEnter pivot points(x, y): ";
    cin>>x>>y;
    
	int T[3][3] = {
        {1, 0, x},
        {0, 1, y},
        {0, 0, 1}
    };
    
    int A1[3], B1[3], C1[3];
    
    for (int i = 0; i < 3; i++) {
        A1[i] = T[i][0]*A[0] + T[i][1]*A[1] + T[i][2]*A[2];
        B1[i] = T[i][0]*B[0] + T[i][1]*B[1] + T[i][2]*B[2];
        C1[i] = T[i][0]*C[0] + T[i][1]*C[1] + T[i][2]*C[2];
    }
    
    setcolor(WHITE);
	line(A[0], A[1], B[0], B[1]);
	line(B[0], B[1], C[0], C[1]);
	line(C[0], C[1], A[0], A[1]);
	
	outtextxy(80, 120, "Original Triangle");
	
	setcolor(YELLOW);
	line(A1[0], A1[1], B1[0], B1[1]);
	line(B1[0], B1[1], C1[0], C1[1]);
	line(C1[0], C1[1], A1[0], A1[1]);
	
	outtextxy(A1[0], A1[1] + 20, "Translated Triangle");
	
	getch();
	closegraph();
	return 0;
}
