#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct sixt
{
    int num[9];
};
class Triangle
{
public:
    Triangle();
    void setNumbers(int* ints,int sum);
    void calcAnswer();
    int getNCorrectTriangles();
    void displayTriangle();
    int getNTriangles();
    void rotateClockwise();
    void rotateAntiClockwise();

private:
    //variables utilized
    sixt* possibilities;
    int nums[9];
    int answer[9]; //for displaying the answer to ther user after some working has been done
    int ntriangles;
    int sum;

    //private methods
    void swapp(int &a,int &b);
    int random(int lowerbound,int upperbound);
};


#endif // TRIANGLE_H_INCLUDED
