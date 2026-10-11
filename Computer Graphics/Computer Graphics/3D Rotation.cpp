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

    float angle;
    cout<<"Enter rotation angle: ";
    cin>>angle;

    float rad = angle * 3.1416 / 180;

    float rCube[8][3];

    int choice;
    cout<<"1. Rotation about X-axis\n";
    cout<<"2. Rotation about Y-axis\n";
    cout<<"3. Rotation about Z-axis\n";
    cout<<"Enter choice: ";
    cin>>choice;

    for(int i=0;i<8;i++)
    {
        float x = cube[i][0];
        float y = cube[i][1];
        float z = cube[i][2];

        if(choice==1) // X-axis
        {
            rCube[i][0] = x;
            rCube[i][1] = y*cos(rad) - z*sin(rad);
            rCube[i][2] = y*sin(rad) + z*cos(rad);
        }

        else if(choice==2) // Y-axis
        {
            rCube[i][0] = x*cos(rad) + z*sin(rad);
            rCube[i][1] = y;
            rCube[i][2] = -x*sin(rad) + z*cos(rad);
        }

        else if(choice==3) // Z-axis
        {
            rCube[i][0] = x*cos(rad) - y*sin(rad);
            rCube[i][1] = x*sin(rad) + y*cos(rad);
            rCube[i][2] = z;
        }
    }

    setcolor(CYAN);
    drawCube(rCube);

    getch();
    closegraph();
}
