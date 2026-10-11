#include <graphics.h>
#include <iostream>
using namespace std;

void drawCube(float cube[8][3])
{
    int x[8], y[8];

    // simple isometric projection
    for(int i=0;i<8;i++)
    {
        x[i] = cube[i][0] + cube[i][2]*0.5;
        y[i] = cube[i][1] - cube[i][2]*0.5;
    }

    // front face
    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[3],y[3]);
    line(x[3],y[3],x[0],y[0]);

    // back face
    line(x[4],y[4],x[5],y[5]);
    line(x[5],y[5],x[6],y[6]);
    line(x[6],y[6],x[7],y[7]);
    line(x[7],y[7],x[4],y[4]);

    // connections
    for(int i=0;i<4;i++)
        line(x[i],y[i],x[i+4],y[i+4]);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float x, y, z;
    float width, height, depth;

    cout<<"Enter starting point (x y z): ";
    cin>>x>>y>>z;

    cout<<"Enter width height depth: ";
    cin>>width>>height>>depth;

    float cube[8][3] =
    {
        {x, y, z},
        {x + width, y, z},
        {x + width, y + height, z},
        {x, y + height, z},

        {x, y, z + depth},
        {x + width, y, z + depth},
        {x + width, y + height, z + depth},
        {x, y + height, z + depth}
    };

    drawCube(cube);

    getch();
    closegraph();
}
