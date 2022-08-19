#include "Triangle.cpp"

int main()
{
    bool cont=true;
    char option=' ';
    do
    {
        system("cls");  //clearing the console screen first

        //variable to be used
        int *ints =new int[6];

        int sum=0;
        Triangle tr;
        cout<<"**************************** 3x3 magic-Triangle solver *************************"<<endl<<endl;
        cout<<"NB : If each number is -1 that means the answer doesnt exist"<<endl;
        cout<<"Enter your 6 numbers : "<<endl;
        cin>>ints[0]>>ints[1]>>ints[2]>>ints[3]>>ints[4]>>ints[5];
        cout<<"Enter the total :"<<endl;
        cin>>sum;
        tr.setNumbers(ints,sum);
        cout<<"The answer is . . ."<<endl;


        //calculating and displaying the answer
        tr.calcAnswer();
        tr.displayTriangle();

        //asking whether the user would like to continue
        cout<<endl;
        cout<<"Do you wishe to continue ? [y - yes , n - no]"<<endl;
        cin>>option;
        while(option!='y' && option!='Y' && option!='n' && option!='N')
        {
            cerr<<"Invalid option . . . . please retry"<<endl;
            cin>>option;
        }
        switch(option)
        {
        case 'y':
        case 'Y':
            cont=true;
            break;
        case 'n':
        case 'N':
            cout<<"Good-bey :-)"<<endl;
            cont=false;
            break;
        }
    }while(cont);

    return 0;
}
