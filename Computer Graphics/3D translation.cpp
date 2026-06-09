#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

float cube[8][3] = {
    {100,100,100},
    {200,100,100},
    {200,200,100},
    {100,200,100},
    {100,100,200},
    {200,100,200},
    {200,200,200},
    {100,200,200}
};

void drawCube(float cube[8][3])
{
    // front
    line(cube[0][0], cube[0][1], cube[1][0], cube[1][1]);
    line(cube[1][0], cube[1][1], cube[2][0], cube[2][1]);
    line(cube[2][0], cube[2][1], cube[3][0], cube[3][1]);
    line(cube[3][0], cube[3][1], cube[0][0], cube[0][1]);

    // back
    line(cube[4][0], cube[4][1], cube[5][0], cube[5][1]);
    line(cube[5][0], cube[5][1], cube[6][0], cube[6][1]);
    line(cube[6][0], cube[6][1], cube[7][0], cube[7][1]);
    line(cube[7][0], cube[7][1], cube[4][0], cube[4][1]);

    // connections
    for(int i=0;i<4;i++)
        line(cube[i][0], cube[i][1], cube[i+4][0], cube[i+4][1]);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);

    drawCube(cube);

    float tx,ty,tz;
    cout<<"Enter translation (tx ty tz): ";
    cin>>tx>>ty>>tz;

    float tCube[8][3];

    for(int i=0;i<8;i++)
    {
        tCube[i][0] = cube[i][0] + tx;
        tCube[i][1] = cube[i][1] + ty;
        tCube[i][2] = cube[i][2] + tz;
    }

    setcolor(CYAN);
    drawCube(tCube);

    getch();
    closegraph();
}
