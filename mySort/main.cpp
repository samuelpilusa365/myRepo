#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int* mySort(int* Nums,int length)
{
    int* Ordered=new int[length];//and then initialize an array that stores the sorted array of numbers
    int intCounter=0; //a variable for storing the index as the comparing process takes place for each element
    int intEqual=0; //a variable for storing how many times a values repeats in the array
    for(int i=0;i<length;++i)
    {
        intCounter=0;
        intEqual=0;
        for(int j=0;j<length;++j)
        {
            if(Nums[i]>Nums[j]) //comparing each value with each value
            {
                ++intCounter;  //incrementing if the selected value is greater than the value it is compared to
            }
            if(Nums[i]==Nums[j]) //searching for repeating values in the array
            {
                ++intEqual; //incrementing each time the value selected comes up in some other place in the array
            }
        }
        for(int k=0;k<intEqual;++k)
        {
            Ordered[intCounter+k]=Nums[i];  //if a value repeats then its copied on the consecutive places ahead in the array that stores the sorted values
        }
        Ordered[intCounter]=Nums[i];
    }
    return Ordered;
}
int main()
{
    int length=5;
    int* nums=new int[length];
    nums[0]=45;
    nums[1]=12;
    nums[2]=-3;
    nums[3]=22;
    nums[4]=15;
    cout<<"Unsorted integer array : "<<endl;
    for(int i=0;i<length;++i)
    {
        cout<<nums[i]<<endl;
    }
    cout<<endl;
    nums=mySort(nums,length);
    cout<<"Sorted integer array (ascending order) : "<<endl;
    for(int i=0;i<length;++i)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}
