#include <graphics.h>
#include <iostream>
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
    for(int i=0;i<4;i++)
    {
        line(cube[i][0],cube[i][1],cube[(i+1)%4][0],cube[(i+1)%4][1]);
        line(cube[i+4][0],cube[i+4][1],cube[((i+1)%4)+4][0],cube[((i+1)%4)+4][1]);
        line(cube[i][0],cube[i][1],cube[i+4][0],cube[i+4][1]);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    drawCube(cube);

    float sx,sy,sz;
    cout<<"Enter scaling factors: ";
    cin>>sx>>sy>>sz;

    float sCube[8][3];

    // Fixed point (center of cube)
    float fx = 150;
    float fy = 150;
    float fz = 150;

    for(int i=0;i<8;i++)
    {
        sCube[i][0] = fx + (cube[i][0] - fx) * sx;
        sCube[i][1] = fy + (cube[i][1] - fy) * sy;
        sCube[i][2] = fz + (cube[i][2] - fz) * sz;
    }

    setcolor(CYAN);
    drawCube(sCube);

    getch();
    closegraph();
}
