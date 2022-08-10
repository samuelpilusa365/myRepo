#include "Functions.cpp"

/*
    ****************************** SOME NOTES ********************************************
    Important to note! :
    - for getline(istream s,string str) to work one needs to never use cin>>str at any point in the code
    - Switch-statement dont seem to work with string variables.

    basic design(in order) :
    - take string and make each character into numbers between 1 and 58(this includes
      capitals and symbols)  inclusive to map the alphabets.
    - when turning a string into numbers between 1 and 26 inclusive include spaces
      between the numbers.
    - read the numebers and decrypt them in letters and display them for the user
*/


int main()
{
    bool cont=true;
    string option=" ";

    do
    {
        system("cls");
        bool islast=isLast();               //checking the external text file named code.txt to see if it has one of information
        cout<<"Your information from code.txt : "<<endl<<endl;
        readCodeTXT();      //displaying the coded information
        cout<<endl;
        readAndDecodeCodeTXT();             //displaying the decoded information

        cout<<endl;
        displayOptions();           //displaying options the user can choose from

        getline(cin,option);            //getting a choice from the user

        //this while-loop ensures that a correct option is chosen
        while(option!="a" && option!="A" && option!="x" && option!="X" && option!="r" && option!="R")
        {
            cerr<<"Option doesn't exist ,please retry"<<endl;
            getline(cin,option);
        }

        //a switch-statement to go to a branch of code that is determined by the option the user chose
        if(option=="A" || option=="a")
        {
            runOptionA();
        }else if(option=="r" || option=="R")
        {
            if(!islast) //checking if the line is the last line in code.txt and if not to not allow the runOptionR() subroutine to run
            {
                runOptionR();
            }else
            {
                cout<<"Opss!! You cannot remove the last line"<<endl;
                system("pause");
            }
        }else if(option=="x" || option=="X")
        {
            cont=false;
            cout<<"Good-bey :) . . ."<<endl;
        }
    }while(cont);

    return 0;
}

