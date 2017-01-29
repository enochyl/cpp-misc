// thecircle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "math.h"
#include "iostream"
using namespace std;
#define pi = 3.1415;
#define SQR(x) (x)*(x);

void DrawCircle(int r, int xCenter, int yCenter);

int main()
{
	int circle_radius = 50; // or whatever you want

	for (int i = 0; i <= 2 * circle_radius; i++)
	{
		for (int j = 0; j <= 2 * circle_radius; j++)
		{
			float distance_to_centre = sqrt((i - circle_radius)*(i - circle_radius) + (j - circle_radius)*(j - circle_radius));
			if (distance_to_centre > circle_radius - 0.5 && distance_to_centre < circle_radius + 0.5)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	int a = SQR(3);
	cout << a << endl;

    return 0;
}

//void drawcircle(int r, int xcenter, int ycenter)
//{
//	for (float f = 0; f < pi * 2; f += 0.1)
//	{
//		setpixel(xcenter + cos(f) * r, ycenter + sin(f) * r);
//	}
//}