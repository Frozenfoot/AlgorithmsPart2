#include <iostream>
#define PI 3.1415926537
#include <cmath>

using namespace std;

struct Coordinate
{
    int x;
    int y;
    double angle;
};

void setFirstDot(Coordinate *dots, int length);
void setAngles(Coordinate *dots, int length);
void insertionSort(Coordinate *dots, int length);

int main()
{
    int n;
    cin >> n;

    Coordinate *dots = new Coordinate[n];

    for(auto i = 0; i < n; ++i)
    {
        cin >> dots[i].x;
        cin >> dots[i].y;
    }

    setFirstDot(dots, n);

    setAngles(dots, n);

    insertionSort(dots, n);

   for(auto i = 0; i < n; ++i)
        cout << dots[i].x << " " << dots[i].y << endl;

    delete[] dots;
    return 0;
}


void setFirstDot(Coordinate *dots, int length)
{
    int firstIndex = 0;

    for(auto i = 0; i < length; ++i)
    {
        if(dots[i].x < dots[firstIndex].x || (dots[i].x == dots[firstIndex].x && dots[i].y < dots[firstIndex].y) )
            firstIndex = i;
    }

    swap(dots[0], dots[firstIndex]);
}

void setAngles(Coordinate *dots, int length)
{
    dots[0].angle = 6.28;

    for(auto i = 1; i < length; ++i)
    {
        if(dots[i].x == dots[0].x)
            dots[i].angle = 1.67;

        else
            dots[i].angle = atan2(dots[i].y - dots[0].y, dots[i].x - dots[0].x);
    }
}

void insertionSort(Coordinate *dots, int length)
{
    for(auto i = 1; i < length; ++i)
    {
        int tempX = dots[i].x;
        int tempY = dots[i].y;
        int tempAngle = dots[i].angle;

        for(auto j = i - 1; j >= 0 && dots[j].angle < tempAngle; --j)
        {
            dots[j + 1].x = dots[j].x;
            dots[j + 1].y = dots[j].y;
            dots[j + 1].angle = dots[j].angle;

            dots[j].x = tempX;
            dots[j].y = tempY;
            dots[j].angle = tempAngle;
        }
    }
}
