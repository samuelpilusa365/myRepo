#include <iostream>
#include <cmath>
using namespace std;
class plane
{
    private :
        const int ROWS=30;
        const int COLS=50;
        int rows ;
        int cols;
        char** p;

        //setting up variables

        const char CHSPACE=' ';
        const char CHHOR='-';
        const char CHVER='|';
        const char CHPOINT='@';
        const char CHWALL='#';

    public :
        plane();
        void printPlane() const;
        void plot(double x, double y);
        int getROWS();
        int getCOLS();
        void drawConstant(int c);
        void drawStraight(int a,int c);
        void drawQuadratic(int a,int b,int c);
        void drawQubic(int a,int b,int c,int d);
        void drawCircle(int r,int a,int b);
        void drawShadedCircle(int r,int a ,int b);
        int getInput();


};

//constructor
plane::plane()
{
    //making the number of rows and columns to be odd
    if(ROWS%2==0)
    {
        rows=ROWS+1;
    }else
    {
        rows=ROWS;
    }
    if(COLS%2==0)
    {
        cols=COLS+1;
    }else
    {
        cols=COLS;
    }

    p=new char*[rows];
    for(int i=0;i<rows;++i)
    {
        p[i]=new char[cols];
    }
    //populating the array
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            p[i][j]=CHSPACE;
        }
    }
    //draw a vertical line
    for(int i=0;i<rows;++i)
    {
        p[i][(cols-1)/2]=CHVER;
    }
    //draw a horizontal line
    for(int i=0;i<cols;++i)
    {
        p[(rows-1)/2][i]=CHHOR;
    }
    for(int i=0;i<cols;++i)
    {
        p[0][i]=CHWALL;
    }
    for(int i=1;i<rows-1;++i)
    {
        p[i][0]=CHWALL;
        p[i][cols-1]=CHWALL;
    }
    for(int i=0;i<cols;++i)
    {
        p[rows-1][i]=CHWALL;
    }

    //an attempt to put numbers on the number lines begins here
    int rowlength=(rows-1)/2;
    int collength=(cols-1)/2;
}

//printPlane function
void plane::printPlane() const
{
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<p[i][j];
        }
        cout<<endl;
    }
}

//plot function
void plane::plot(double x,double y)
{
    if((((cols-1)/2)+x>=0 &&((cols-1)/2)+x<cols) && (((rows-1)/2)-y>=0 && ((rows-1)/2)-y<rows))
    {
        int xcoord =(cols-1)/2+x;
        int ycoord= (rows-1)/2-y;
        p[ycoord][xcoord]=CHPOINT;
    }



}

//getROWS function
int plane::getROWS()
{
    return rows;
}

//getCOLS function
int plane::getCOLS()
{
    return cols;
}

//drawConstant function
void plane::drawConstant(int c)
{
    int xcoord=-(cols-1)/2;
    int ycoord=(rows-1)/2;
    while(xcoord<=(cols-1)/2 )
    {
        ycoord=c;
        this->plot(xcoord,ycoord);//this is where the function is defined by writting it in terms of xcoord on y-axis side of the plot method
        ++xcoord;
    }
}

//drawStraight function
void plane::drawStraight(int a,int c)
{
    int xcoord=-(cols-1)/2;
    int ycoord=(rows-1)/2;
    while(xcoord<=(cols-1)/2 )
    {
        ycoord=a*xcoord+c;
        this->plot(xcoord,ycoord);//this is where the function is defined by writting it in terms of xcoord on y-axis side of the plot method
        ++xcoord;
                //ycoord=xcoord*xcoord;
    }
}

//drawQuadratic function
void plane::drawQuadratic(int a,int b,int c)
{
    int xcoord=-(cols-1)/2;
    int ycoord=(rows-1)/2;
    while(xcoord<=(cols-1)/2 )
    {
        ycoord=a*xcoord*xcoord+b*xcoord+c;
        this->plot(xcoord,ycoord);//this is where the function is defined by writting it in terms of xcoord on y-axis side of the plot method
        ++xcoord;
                //ycoord=xcoord*xcoord;
    }
}

//drawQubic function
void plane::drawQubic(int a,int b,int c,int d)
{
    int xcoord=-(cols-1)/2;
    int ycoord=(rows-1)/2;
    while(xcoord<=(cols-1)/2 )
    {
        ycoord=a*xcoord*xcoord*xcoord+b*xcoord*xcoord+c*xcoord+d;
        this->plot(xcoord,ycoord);//this is where the function is defined by writting it in terms of xcoord on y-axis side of the plot method
        ++xcoord;
                //ycoord=xcoord*xcoord;
    }
}

//drawCircle function
void plane::drawCircle(int r,int a,int b)
{
    int xcoord=-(cols-1)/2;
    int ycoord=(rows-1)/2;
    int nums;

    while(xcoord<=(cols-1)/2 )
    {
        nums=r*r-(xcoord-a)*(xcoord-a);
        if(nums>=0)
        {
            ycoord=sqrt(nums)+b;
            this->plot(xcoord,ycoord);//this is where the function is defined by writting it in terms of xcoord on y-axis side of the plot method
            ycoord=-sqrt(nums)+b;
            this->plot(xcoord,ycoord);
        }

        ++xcoord;
                //ycoord=xcoord*xcoord;
    }
    this->plot(a,b);
}


//drawCircleShaded function
void plane::drawShadedCircle(int r,int a ,int b)
{
    int xcoord=-(cols-1)/2;
    int ycoord=(rows-1)/2;
    int nums;
    for(int i=r;i>0;--i)
    {
        drawCircle(i,a,b);

    }
    this->plot(a,b);
}

//getInput function
int plane::getInput()
{
    int option=0;
    cout<<"-------> Choose the grapg from the options below: <-------"<<endl;
    cout<<" 1. Constant function "<<endl;
    cout<<" 2. Straight-line function "<<endl;
    cout<<" 3. Quadratic function "<<endl;
    cout<<" 4. Qubic function "<<endl;
    cout<<" 5. Draw a circle "<<endl;
    cout<<" 6. Draw shaded circle "<<endl;
    cin>>option;
    while(option!=1 && option!=2 && option!=3 && option!=4 && option!=5 && option!=6 && option!=7)
    {
        system("cls");
        cout<<"Wrong option ! ,please retry "<<endl;
        cout<<"-------> Choose the grapg from the options below: <-------"<<endl;
        cout<<" 1. Constant function "<<endl;
        cout<<" 2. Straight-line function "<<endl;
        cout<<" 3. Quadratic function "<<endl;
        cout<<" 4. Qubic function "<<endl;
        cout<<" 5. Draw a circle "<<endl;
        cout<<" 6. Draw shaded circle "<<endl;
        cin>>option;
    }
    return option;
}
