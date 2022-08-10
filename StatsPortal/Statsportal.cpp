#include <iostream>

using namespace std;

class Statsportal
{
private :
    int* nums;
    int* ascend;
    int* descend;
    int* uniques;
    int length;
    int uniquesSize;
    int* ascendSort(int* ints);
    int* descendSort(int* ints);
    double mean;
    double variance;
    double stddev;
public :
    Statsportal();
    void displayNumbers(int option);
    void dispalyWrittenStats();
    int getMin();
    int getMax();
    int getMode();
    double getMean();
    int getRange();
    double getVariance();
    double getSD();
};
//A constructor
Statsportal::Statsportal()
{
    cout<<"*************** Welcome to StatsPortal *******************"<<endl;
    cout<<endl;
    cout<<" How many numbers will you input : ";
    cin>>length;
    system("cls");
    nums=new int[length];
    for(int i=0;i<length;++i)
    {
        cout<<" You are inputing "<<length<<" number(s)"<<endl;
        if(i==length-1)
        {
           cout<<" Enter the LAST number : ";
           cin>>nums[i];
           system("cls");
        }else
        {
            cout<<" Enter number "<<(i+1)<<" : ";
            cin>>nums[i];
            system("cls");
        }
    }
    ascend=new int[length];
    descend=new int[length];
    for(int i=0;i<length;++i)
    {
        ascend[i]=nums[i];
        descend[i]=nums[i];
    }
    ascend=ascendSort(ascend);
    descend=descendSort(descend);
    uniquesSize=1;
    for(int i=0;i<length-1;++i)
    {
        if(ascend[i]!=ascend[i+1])
        {
            ++uniquesSize;
        }
    }
    uniques=new int[uniquesSize];
    int counter=0;
    uniques[counter]=ascend[0];
    for(int i=0;i<length-1;++i)
    {
        if(ascend[i]!=ascend[i+1])
        {
            ++counter;
            uniques[counter]=ascend[i+1];
        }
    }
}
void Statsportal::displayNumbers(int option)
{
    if(option==0)
    {
        cout<<" The numbers are : "<<endl;
        if(length<2)
        {
            cout<<nums[0]<<endl;
        }else
        {
            for(int i=0;i<length-2;++i)
            {
                if(i==0)
                {
                    cout<<" "<<nums[i]<<" ,";
                }else
                {
                   cout<<nums[i]<<" ,";
                }

            }
            if(length==2)
            {
                cout<<" "<<nums[length-2];
                cout<<" and "<<nums[length-1]<<endl;
            }else
            {
                cout<<nums[length-2];
                cout<<" and "<<nums[length-1]<<endl;
            }

        }
    }else if(option==1)
    {
        cout<<" The numbers(in ascending order) are : "<<endl;
        if(length<2)
        {
            cout<<ascend[0]<<endl;
        }else
        {
            for(int i=0;i<length-2;++i)
            {
                cout<<ascend[i]<<" ,";
            }
            cout<<ascend[length-2];
            cout<<" and "<<ascend[length-1]<<endl;
        }
    }else if(option==2)
    {
        cout<<" The numbers(in descending order) are : "<<endl;
        if(length<2)
        {
            cout<<descend[0]<<endl;
        }else
        {
            for(int i=0;i<length-2;++i)
            {
                cout<<descend[i]<<" ,";
            }
            cout<<descend[length-2];
            cout<<" and "<<descend[length-1]<<endl;
        }

    }else if(option==3)
    {
        cout<<" The unique numbers are : "<<endl;
        if(uniquesSize<2)
        {
            cout<<uniques[0]<<endl;
        }else
        {
            for(int i=0;i<uniquesSize-2;++i)
            {
                cout<<uniques[i]<<" ,";
            }
            cout<<uniques[uniquesSize-2];
            cout<<" and "<<uniques[uniquesSize-1]<<endl;
        }
    }else
    {
        cout<<"Wrong option !!"<<endl;
    }
}
int* Statsportal::ascendSort(int* ints)
{
    bool isSorted=false;
    while(isSorted==false)
    {
        isSorted=true;
        for(int i=0;i<length-1;++i)
        {
            if(ints[i]>ints[i+1])
            {
                int temp=ints[i];
                ints[i]=ints[i+1];
                ints[i+1]=temp;
                isSorted=false;
            }
        }
    }
    return ints;
}
int* Statsportal::descendSort(int* ints)
{
    bool isSorted=false;
    while(isSorted==false)
    {
        isSorted=true;
        for(int i=0;i<length-1;++i)
        {
            if(ints[i]<ints[i+1])
            {
                int temp=ints[i];
                ints[i]=ints[i+1];
                ints[i+1]=temp;
                isSorted=false;
            }
        }
    }
    return ints;
}
int Statsportal::getMin()
{
    return ascend[0];
}
int Statsportal::getMax()
{
    return ascend[length-1];
}
int Statsportal::getRange()
{
    return ascend[length-1]-ascend[0];
}
int Statsportal::getMode()
{
    struct number
    {
        int num;
        int freq;
    };
    number n[uniquesSize];
    for(int i=0;i<uniquesSize;++i)
    {
        n[i].num=uniques[i];
        n[i].freq=0;
    }
    for(int i=0;i<uniquesSize;++i)
    {
        for(int j=0;j<length;++j)
        {
            if(ascend[j]==n[i].num)
            {
                ++n[i].freq;
            }
        }
    }
    int freq=n[0].freq;
    int mode=n[0].num;
    for(int i=0;i<uniquesSize;++i)
    {
        if(freq<n[i].freq)
        {
           freq=n[i].freq;
           mode=n[i].num;
        }
    }
    return mode;
}
double Statsportal::getMean()
{
    int total=0;
    for(int i=0;i<length;++i)
    {
        total+=nums[i];
    }
    mean=total/length;
    return mean;
}
double Statsportal::getVariance()
{
    int sum=0;
    for(int i=0;i<length;++i)
    {
        sum+=(mean-nums[i])*(mean-nums[i]);
    }
    variance=sum/length;
    return variance;
}
double Statsportal::getSD()
{
    stddev=sqrt(variance);
    return stddev;
}





