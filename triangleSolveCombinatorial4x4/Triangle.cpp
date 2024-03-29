#include "Triangle.h"

Triangle::Triangle()
{
    ntriangles=0;
    possibilities=new sixt[362880];
}
void Triangle::setNumbers(int* ints,int sum)
{
    for(int i=0;i<9;++i)
    {
        nums[i]=ints[i];
        answer[i]=ints[i];
    }
    this->sum=sum;
    int counter=0;
    //setting all possible triangle to variable named possibilities
    for(int a=0;a<9;++a)
    {
        for(int b=0;b<9;++b)
        {
            for(int c=0;c<9;++c)
            {
                for(int d=0;d<9;++d)
                {
                    for(int e=0;e<9;++e)
                    {
                        for(int f=0;f<9;++f)
                        {
                            for(int g=0;g<9;++g)
                            {
                                for(int h=0;h<9;++h)
                                {
                                   for(int i=0;i<9;++i)
                                   {
                                       if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i && d!=e && d!=f && d!=g && d!=h && d!=i && e!=f && e!=g && e!=h && e!=i && f!=g && f!=h && f!=i && g!=h && g!=i && h!=i)
                                        {
                                            possibilities[counter].num[0]=nums[a];
                                            possibilities[counter].num[1]=nums[b];
                                            possibilities[counter].num[2]=nums[c];
                                            possibilities[counter].num[3]=nums[d];
                                            possibilities[counter].num[4]=nums[e];
                                            possibilities[counter].num[5]=nums[f];
                                            possibilities[counter].num[6]=nums[g];
                                            possibilities[counter].num[7]=nums[h];
                                            possibilities[counter].num[8]=nums[i];
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
        }
    }
}

void Triangle::calcAnswer()
{
    int sum1=0;
    int sum2=0;
    int sum3=0;
    bool change=false;
    for(int i=0;i<362880;++i)
    {
        sum1=possibilities[i].num[0]+possibilities[i].num[1]+possibilities[i].num[2]+possibilities[i].num[3];
        sum2=possibilities[i].num[3]+possibilities[i].num[4]+possibilities[i].num[5]+possibilities[i].num[6];
        sum3=possibilities[i].num[6]+possibilities[i].num[7]+possibilities[i].num[8]+possibilities[i].num[0];
        if(sum1==sum && sum2==sum && sum3==sum)
        {
            answer[0]=possibilities[i].num[0];
            answer[1]=possibilities[i].num[1];
            answer[2]=possibilities[i].num[2];
            answer[3]=possibilities[i].num[3];
            answer[4]=possibilities[i].num[4];
            answer[5]=possibilities[i].num[5];
            answer[6]=possibilities[i].num[6];
            answer[7]=possibilities[i].num[7];
            answer[8]=possibilities[i].num[8];
            change=true;
            break;
        }
    }
    if(!change)
    {
        for(int i=0;i<9;++i)
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
    for(int i=0;i<362880;++i)
    {
        sum1=possibilities[i].num[0]+possibilities[i].num[1]+possibilities[i].num[2]+possibilities[i].num[3];
        sum2=possibilities[i].num[3]+possibilities[i].num[4]+possibilities[i].num[5]+possibilities[i].num[6];
        sum3=possibilities[i].num[6]+possibilities[i].num[7]+possibilities[i].num[8]+possibilities[i].num[0];
        if(sum1==sum && sum2==sum && sum3==sum)
        {
            ++total;
        }
    }
    return total;
}
void Triangle::displayTriangle()
{
    cout<<"                    ("<<answer[0]<<")"<<endl;
    cout<<endl;
    cout<<"            ("<<answer[8]<<")           ("<<answer[1]<<")"<<endl;
    cout<<endl;
    cout<<"      ("<<answer[7]<<")                        ("<<answer[2]<<")"<<endl;
    cout<<endl;
    cout<<"("<<answer[6]<<")         ("<<answer[5]<<")           ("<<answer[4]<<")          ("<<answer[3]<<")"<<endl;
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
    //rotating
    answer[0]=nums[8];
    for(int i=1;i<9;++i)
    {
        answer[i]=nums[i-1];
    }

}
void Triangle::rotateAntiClockwise()
{
    //rotating
    for(int i=1;i<9;++i)
    {
        answer[i-1]=nums[i];
    }
    answer[8]=nums[0];

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
