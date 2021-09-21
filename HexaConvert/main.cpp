#include <iostream>

using namespace std;
string hexaconvert(int num)
{
    if(num==0)
    {
        return "0";
    }
    string s="";
    int sum=0;
    int counter=0;
    int m=1;
    while(m<=num)
    {
        m=m*16;
        ++counter;
    }
    for(int i=0;i<counter;++i)
    {
        m=m/16;

        sum=sum+15*m;
        if(sum<=num)
        {
            s+="F";
            continue;
        }else
        {
            sum=sum-15*m;
        }
        sum=sum+14*m;
        if(sum<=num)
        {
            s+="E";
            continue;
        }else
        {
            sum=sum-14*m;
        }
        sum=sum+13*m;
        if(sum<=num)
        {
            s+="D";
            continue;
        }else
        {
            sum=sum-13*m;
        }
        sum=sum+12*m;
        if(sum<=num)
        {
            s+="C";
            continue;
        }else
        {
            sum=sum-12*m;
        }


        sum=sum+11*m;
        if(sum<=num)
        {
            s+="B";
            continue;
        }else
        {
            sum=sum-11*m;
        }
        sum=sum+10*m;
        if(sum<=num)
        {
            s+="A";
            continue;
        }else
        {
            sum=sum-10*m;
        }
        sum=sum+9*m;
        if(sum<=num)
        {
            s+="9";
            continue;
        }else
        {
            sum=sum-9*m;
        }
        sum=sum+8*m;
        if(sum<=num)
        {
            s+="8";
            continue;
        }else
        {
            sum=sum-8*m;
        }
        sum=sum+7*m;
        if(sum<=num)
        {
            s+="7";
            continue;
        }else
        {
            sum=sum-7*m;
        }
        sum=sum+6*m;
        if(sum<=num)
        {
            s+="6";
            continue;
        }else
        {
            sum=sum-6*m;
        }
        sum=sum+5*m;
        if(sum<=num)
        {
            s+="5";
            continue;
        }else
        {
            sum=sum-5*m;
        }
        sum=sum+4*m;
        if(sum<=num)
        {
            s+="4";
            continue;
        }else
        {
            sum=sum-4*m;
        }
        sum=sum+3*m;
        if(sum<=num)
        {
            s+="3";
            continue;
        }else
        {
            sum=sum-3*m;
        }
        sum=sum+2*m;
        if(sum<=num)
        {
            s+="2";
            continue;
        }else
        {
            sum=sum-2*m;
        }
        sum=sum+1*m;
        if(sum<=num)
        {
            s+="1";
            continue;
        }else
        {
            sum=sum-1*m;
        }
        sum=sum+0*m;
        if(sum<=num)
        {
            s+="0";
            continue;
        }
    }
    return s;

}
int main()
{

    char input;
    bool cont=true;
    do{
        system("cls");
        int number =0;

        cout << "Enter your decimal number :" << endl;
        cin>>number;

        cout<<"Your decimal number in hexadecimal form is : "<<hexaconvert(number)<<endl;
        cout<<endl;
        cout<<"Do you wish to continue...[yes=y][no=n]"<<endl;
        cin>>input;
        switch(input)
        {
        case 'n':
        case 'N':
            cont=false;
            break;
        case 'y':
        case 'Y':
            cont=true;

            break;
        default:
            while(input!='n' &&input!='N' && input!='y' && input!='Y')
            {
                cout<<"Please enter a valid option ...Do you wish to continue...[yes=y][no=n]"<<endl;
                cin>>input;
                if(input=='n' || input=='N')
                {
                    cont=false;
                }
            }


        }
    }while(cont);
    return 0;
}
