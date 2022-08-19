#include "Triangle.h"

Triangle::Triangle()
{
    ntriangles=0;
}
void Triangle::setNumbers(int* ints,int sum)
{
    for(int i=0;i<6;++i)
    {
        nums[i]=ints[i];
        answer[i]=ints[i];
    }
    this->sum=sum;
    int counter=0;
    ntriangles=0;

    for(int a=0;a<6;++a)
    {
        for(int b=0;b<6;++b)
        {
            for(int c=0;c<6;++c)
            {
                for(int d=0;d<6;++d)
                {
                    for(int e=0;e<6;++e)
                    {
                        for(int f=0;f<6;++f)
                        {
                            if(a!=b && a!=c && a!=d && a!=e && a!=f && b!=c && b!=d && b!=e && b!=f && c!=d && c!=e && c!=f && d!=e && d!=f && e!=f )
                            {
                                possibilities[counter].num[0]=nums[a];
                                possibilities[counter].num[1]=nums[b];
                                possibilities[counter].num[2]=nums[c];
                                possibilities[counter].num[3]=nums[d];
                                possibilities[counter].num[4]=nums[e];
                                possibilities[counter].num[5]=nums[f];
                                ++counter;
                                ++ntriangles;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Triangle::calcAnswer()
{
    int sum1=0;
    int sum2=0;
    int sum3=0;
    bool change=false;
    for(int i=0;i<ntriangles;++i)
    {
        sum1=possibilities[i].num[0]+possibilities[i].num[1]+possibilities[i].num[2];
        sum2=possibilities[i].num[2]+possibilities[i].num[3]+possibilities[i].num[4];
        sum3=possibilities[i].num[4]+possibilities[i].num[5]+possibilities[i].num[0];
        if(sum1==sum && sum2==sum && sum3==sum)
        {
            answer[0]=possibilities[i].num[0];
            answer[1]=possibilities[i].num[1];
            answer[2]=possibilities[i].num[2];
            answer[3]=possibilities[i].num[3];
            answer[4]=possibilities[i].num[4];
            answer[5]=possibilities[i].num[5];

            change=true;
            break;
        }
    }
    if(!change)
    {
        for(int i=0;i<6;++i)
        {
            answer[i]=-1;
        }
    }
}
int Triangle::getNCorrectTriangles()
{
    int total=0;
    int sum1=0;
    int sum2=0;
    int sum3=0;
    for(int i=0;i<ntriangles;++i)
    {
        sum1=possibilities[i].num[0]+possibilities[i].num[1]+possibilities[i].num[2];
        sum2=possibilities[i].num[2]+possibilities[i].num[3]+possibilities[i].num[4];
        sum3=possibilities[i].num[4]+possibilities[i].num[5]+possibilities[i].num[0];
        if(sum1==sum && sum2==sum && sum3==sum)
        {
            ++total;
        }
    }
    return total;
}
void Triangle::displayTriangle()
{
    cout<<"             ("<<answer[0]<<")"<<endl;
    cout<<endl;
    cout<<"      ("<<answer[5]<<")          ("<<answer[1]<<")"<<endl;
    cout<<endl;
    cout<<"("<<answer[4]<<")          ("<<answer[3]<<")        ("<<answer[2]<<")"<<endl;
    cout<<endl;
    cout<<"The total number of possible unique triangles is : "<<ntriangles<<endl;
    cout<<"The number of correct triangles is               : "<<getNCorrectTriangles()<<endl;
}

int Triangle::getNTriangles()
{
    return ntriangles;
}
void Triangle::rotateClockwise()
{
    int* temp= new int[6];
    //copying nums into ints
    for(int i=0;i<6;++i)
    {
        temp[i]=nums[i];
    }

    //rotating
    answer[0]=temp[5];
    for(int i=1;i<6;++i)
    {
        answer[i]=temp[i-1];
    }


}
void Triangle::rotateAntiClockwise()
{

    int* temp=new int[6];
    //copying nums into ints
    for(int i=0;i<6;++i)
    {
        temp[i]=nums[i];
    }
    //rotating
    for(int i=1;i<6;++i)
    {
        answer[i-1]=temp[i];
    }
    answer[5]=temp[0];

}

void Triangle::swapp(int& a,int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
int Triangle::random(int lowerbound,int upperbound)
{
    srand(time(0));

    int range=upperbound-lowerbound+1;
    return rand()%range+lowerbound;
}
