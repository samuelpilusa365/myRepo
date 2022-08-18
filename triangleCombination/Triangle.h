#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct sixt
{
    int* num=new int[9];
};
class Triangle
{
public:
    Triangle();
    void setNumbers(int* ints,int sum);
    void calcAnswer();
    void displayTriangle();
    int getNTriangles();
private:
    sixt* possibilities;
    int* nums;
    int* answer;
    int ntriangles;
    int sum;
    void rotateClockwise();
    void rotateAntiClockwise();
    void swapp(int &a,int &b);
    int random(int lowerbound,int upperbound);
};


#endif // TRIANGLE_H_INCLUDED
