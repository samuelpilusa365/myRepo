#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Statsportal.cpp"
using namespace std;

int main()
{
    bool cont=true;
    char option=' ';
    do
    {

        Statsportal sp;
        sp.displayNumbers(0);
        cout<<endl;
        cout<<" Written stats is as follows : "<<endl<<endl;

        cout<<" PARAMETER          |        VALUE                    "<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Minimum            |         "<<sp.getMin()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Maximum            |         "<<sp.getMax()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Range              |         "<<sp.getRange()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Mode               |         "<<sp.getMode()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Mean               |         "<<sp.getMean()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Variance           |         "<<sp.getVariance()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<" Standard Deviation |         "<<sp.getSD()<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"Do you wishe to repeat? [y = Yes , n = No]"<<endl;
        cin>>option;
        while(option!='y' && option!='Y' && option!='n' && option!='N')
        {
            cerr<<"Wrong input ...please retry : [y = Yes , n = No]"<<endl;
            cin>>option;
        }
        switch(option)
        {
        case 'y':
        case 'Y':
            system("cls");
            break;
        case 'n':
        case 'N':
            cout<<"Thank you for running StatsPorta :)"<<endl;
            cont=false;
           break;


        }

    }while(cont);


    return 0;
}
