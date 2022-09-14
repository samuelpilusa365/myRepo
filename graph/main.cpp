#include "plane.cpp"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{

    /*
        Clarifying some of the maths
        some known things about this kind of cartesian plane set up are that:
        -The lowest x value is (-(COLS-1)/2)
        -The highest x value is (COLS-1)/2

        -The lowest y value is (ROWS-1)/2
        -The highest y value is (-(ROWS-1)/2)
    */
    bool cont=true;
    char opt=' ';
    do
    {
        plane pl;
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        int r=0;
        int height=0;
        int bredth=0;
        int option=pl.getInput();
        switch(option)
        {
        case 1:
            cout<<"Enter value for 'c' : ";
            cin>>c;
            system("cls");
            pl.drawConstant(c);
            pl.printPlane();
            break;
        case 2:
            cout<<"Enter value for 'a' : ";
            cin>>a;
            cout<<"Enter value for 'c' : ";
            cin>>c;
            system("cls");
            pl.drawStraight(a,c);
            pl.printPlane();
            break;
        case 3:
            cout<<"Enter value for 'a' : ";
            cin>>a;
            cout<<"Enter value for 'b' : ";
            cin>>b;
            cout<<"Enter value for 'c' : ";
            cin>>c;
            system("cls");
            pl.drawQuadratic(a,b,c);
            pl.printPlane();
            break;
        case 4:
            cout<<"Enter value for 'a' : ";
            cin>>a;
            cout<<"Enter value for 'b' : ";
            cin>>b;
            cout<<"Enter value for 'c' : ";
            cin>>c;
            cout<<"Enter value for 'd' : ";
            cin>>d;
            system("cls");
            pl.drawQubic(a,b,c,d);
            pl.printPlane();
            break;


        case 5:
            cout<<"Enter value for 'r' : ";
            cin>>r;
            cout<<"Enter value for 'a' : ";
            cin>>a;
            cout<<"Enter value for 'b' : ";
            cin>>b;

            system("cls");
            pl.drawCircle(r,a,b);
            pl.printPlane();
            break;
        case 6:
            cout<<"Enter value for 'r' : ";
            cin>>r;
            cout<<"Enter value for 'a' : ";
            cin>>a;
            cout<<"Enter value for 'b' : ";
            cin>>b;

            system("cls");
            pl.drawShadedCircle(r,a,b);
            pl.printPlane();
            break;
        }


        cout<<endl;
        cout<<"Do you wishe to repeat? [y = Yes , n = No]"<<endl;
        cin>>opt;
        int i=1;   //to make the number of re-tries to reach 5 before exiting
        bool exitt=false;
        while(opt!='y' && opt!='Y' && opt!='n' && opt!='N')
        {
            cerr<<"Wrong input ...please retry : [y = Yes , n = No]"<<endl;
            cin>>opt;
            ++i;
            if(i==5)
            {
                exitt=true;
                break;
            }
        }
        if(exitt)
        {
            cout<<"You reached the maximum number of tries, Good-bey :-) "<<endl;
            return 0;
        }
        switch(opt)
        {
        case 'y':
        case 'Y':
            system("cls");
            break;
        case 'n':
        case 'N':
            cout<<"You have exited the program . . ."<<endl;
            cont=false;
            break;
        }
    }while(cont);
    return 0;
}
