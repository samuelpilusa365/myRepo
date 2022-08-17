#include <iostream>
#include <fstream>
using namespace std;
void displayOptions()
{
    cout<<"options : a - Add a name and surname"<<endl;
    cout<<"          r - Remove a name(enter their name as their ID ,if there is only one name left it cannot be removed)"<<endl;
    cout<<"          x - Exit"<<endl;
}
void displayPeopleFromFile()
{
    fstream thefile;
        thefile.open("thefile.txt",ios::in); //input for reading
        if(thefile.is_open())
        {
            string line="";
            getline(thefile,line);
            cout<<"List of names : "<< line<< endl;

            while(getline(thefile,line))
            {
                cout<<"                "+line<<endl;
            }
            cout<<"                *****************"<<endl;
        }

        thefile.close();
        cout<<endl;
}
void runningOptionA()
{
    string name="";
    string surname="";
    fstream thefile;
    thefile.open("thefile.txt",ios::app);
    if(thefile.is_open())
    {
        cout<<"Enter name : "<<endl;
        cin>>name;
        cout<<"Enter surname : "<<endl;
        cin>>surname;

        name="\n"+name+" "+surname;

        thefile<<name;
    }
    thefile.close();
    system("cls");
}
void removeName(fstream& thefile,string name)
{
    if(thefile.is_open())
    {
        string line="";
        string strinput="";
        string s="";
        while(getline(thefile,line))
        {
            s="";
            for(int i=0;line[i]!=' ';++i)
            {
                s+=line[i];
            }
            if(s!=name)
            {
                strinput=strinput+line+"\n";
            }
        }
        thefile.close();
        thefile.open("thefile.txt",ios::out);//write to thefile.txt by overwriting into the text file
        strinput[strinput.length()-1]=' ';//changing "n" to empty space to avoid the extra newline command
        thefile<<strinput;//writing strinput into thefile file stream
        thefile.close();
    }
}
void runningOptionR()
{
    //variables
    string name="";
    fstream thefile;
    string strval="";
    int Nnames=0;

    thefile.open("thefile.txt",ios::in);//openning file thefile.txt in read mode
    while(getline(thefile,strval))
    {
        ++Nnames;
    }
    thefile.close();

    if(Nnames>1)
    {
        //get input from user
        cout<<"Enter name to be removed : "<<endl;
        cin>>name;
        thefile.open("thefile.txt",ios::in);
        removeName(thefile,name);

    }else
    {
        cout<<"Opss!! You cannot remove the last name"<<endl;
        system("pause");
    }

    system("cls");  //clearing the console
}
