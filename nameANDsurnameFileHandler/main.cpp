#include "Functions.cpp"
/**
 OBJECTIVES
**/
/*
APPLICATION FEATURES
- list peoples names from an external text file
- list options to add a name or remove a name or exit the program
- remove a name by entering the name of the person as their ID
- avoid removing a name when it is the last on the list
- get the user's input through the getline function
*/
/*
**************** test list ^^^^^^^^^^^^^^^^^^
samuel pilusa
lesli lamport
alan turing
margareth humilton
john vonnaumann
kurt godel
charles babage
steve wozniak
bill gates
*/

int main()
{

    bool cont=true;
    char option=' ';
    do
    {
        //function for listing people's names is below(by reading from thefile.txt file)
        displayPeopleFromFile();
        //function for displaying options
        displayOptions();

        //code taking in user's input
        cout<<endl<<"Choose your option from the above : ";
        cin>>option;
        int attempts=3;    //total number of wrong input before automatic exit
        int Nattempts=0;

        //handling a situation in which an invalid input is entered
        for(int i=0;option!='a' && option!='A' && option!='X' && option!='r' && option!='R' && option!='x' && i<attempts;++i)
        {
            cout<<"Invalid option ,please choose a valid option : ";
            cin>>option;
            ++Nattempts;
        }
        if(option=='a' || option=='A')
        {
            runningOptionA();
        }
        if(option=='r' || option=='R')
        {
            runningOptionR();
        }
        if(option=='x' || option=='X' || Nattempts==3)
        {
            cont=false;
            cout<<"**********************  good-bey :)  ******************************"<<endl;
        }



    }while(cont);

    return 0;
}
