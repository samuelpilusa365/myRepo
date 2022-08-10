#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

/** ***************************************************** VARIABLES ********************************************************************* **/

//const int A_SIZE=58          //constant integer variable used to store the number of letter and indexes as well as other characters
//const Alphabet* _ALPHABETS   //constant Alphabet* variable to store a letter and its index to be used by encrypt and decrypt functions

/** ************************************************************************************************************************************* **/

/** ****************************************** ALL FUNCTIONS (listed sequentially) ****************************************************** **/
/*
* 1. bool isLast()
* 2. int exp(int base,int exponent)       //for calculating exponennts
* 3. int convertToInt(string s)           //to convert a string value into an integer value
* 4. string convertToString(int intn)     //to convert an integer value into a string
* 5. Alphabet* initializeAlphabets()       //set the alphabets to be used by const Alphabet* _ALPHABETS
* 6. string encrypt(string str)         //take a string of numbers and turn them into letters and words that can be read.uses fnction number 4.
* 7. string removeFrontSpaces(string s)
* 8. string removeBackSpaces(string s)
* 9. string removeEndSpaces(string s)
* 10. int numOfWords(string s,char c)    //calculates the number of devided string a string has .is used by a function at number 11.
* 11. string* stringSplit(string s,char c) //splits a single string into multiple strings given the dividing character c.uses function at number 10.
* 12. string decrypt(string s)             //take a string and turns it into a series of numbers separated by spaces
* 13. void appendToCodeTXT(string str)
* 14. void readAndDecodeCodeTXT()   //reads information from text file named code.txt and then decode is using a function at number 12.
* 15. void readCodeTXT()   //read information from text file code.txt the way it is.
* 16. string getLast()     //opens and reads text file code.txt and returns the last line.
* 17. void removeLast()    //removes the last line of code.txt text file .uses function at number 16.
* 18. void runOptionA()     //uses function number 13.
* 19. void runOptionR()     //uses function number17.
* 20. void displayOptions()
*/
/** ************************************************************************************************************************************* **/

/** ******************************************************* ABOUT ASCII ***************************************************************** **/
/*  ASCII for numbers
    '0'=48
    '1'=49
    '2'=50
    '3'=51
    '4'=52
    '5'=53
    '6'=54
    '7'=55
    '8'=56
    '9'=57

    ASCII for letters
    A=65    | a=97
    Z=90    | z=122
*/
/** ************************************************************************************************************************************* **/

struct Alphabet
{
    char letter;
    int index;
};
Alphabet* initializeAlphabets();//declaring the initializeAlphabet for const Alphabet* _ALPHABETS

const int A_SIZE=58;
const Alphabet* _ALPHABETS=initializeAlphabets();


//bool isLast()
bool isLast()
{

    fstream thefile;
    string strval="";
    int Nnames=0;

    thefile.open("code.txt",ios::in);//openning file thefile.txt in read mode
    while(getline(thefile,strval))
    {
        ++Nnames;
    }
    thefile.close();

    if(Nnames>1)
    {
        return false;

    }else
    {
        return true;
    }
}

//int exp(int base,int exponent)
int exp(int base,int exponent)
{
    int ans=1;
    for(int i=0;i<exponent;++i)
    {
        ans=ans*base;
    }
    return ans;
}

//int convertToInt(string s)
int convertToInt(string s)
{
    int ans=0;
    int counter=s.length();
    for(int i=0;i<s.length();++i)
    {
        --counter;
        ans=ans+((int)s[i]-48)*exp(10,counter);

    }
    return ans;
}

//string convertToString(int intn)
string convertToString(int intn)
{
    string str="";
    int counter=1;

    //calculating number of digits
    while(intn-exp(10,counter)>=0)
    {
        ++counter;
    }

    //This is done using the ASCII table(refer to the notes on top)
    for(int i=counter-1;i>=0;--i)
    {
        if((intn-9*exp(10,i))>=0)
        {
            str=str+'9';
            intn=intn-9*exp(10,i);

        }else if((intn-8*exp(10,i))>=0)
        {
            str=str+'8';
            intn=intn-8*exp(10,i);
        }else if((intn-7*exp(10,i))>=0)
        {
            str=str+'7';
            intn=intn-7*exp(10,i);
        }else if((intn-6*exp(10,i))>=0)
        {
            str=str+'6';
            intn=intn-6*exp(10,i);
        }else if((intn-5*exp(10,i))>=0)
        {
            str=str+'5';
            intn=intn-5*exp(10,i);
        }else if((intn-4*exp(10,i))>=0)
        {
            str=str+'4';
            intn=intn-4*exp(10,i);
        }else if((intn-3*exp(10,i))>=0)
        {
            str=str+'3';
            intn=intn-3*exp(10,i);
        }else if((intn-2*exp(10,i))>=0)
        {
            str=str+'2';
            intn=intn-2*exp(10,i);
        }else if((intn-1*exp(10,i))>=0)
        {
            str=str+'1';
            intn=intn-1*exp(10,i);
        }else if((intn-0*exp(10,i))>=0)
        {
            str=str+'0';
            intn=intn-0*exp(10,i);
        }
    }
    return str;
}

//Alphabet* initializeAlphabets()
Alphabet* initializeAlphabets()
{
    Alphabet* letters=new Alphabet[A_SIZE];
    for(int i = A_SIZE+7;i < A_SIZE+33;++i)
    {
        //This is done using the ASCII table(refer to the notes on top)
        letters[i-39].letter=(char)i;
        letters[i-39].index=i-38;
        letters[i-65].letter=(char)(i+32);
        letters[i-65].index=i-64;
    }

    letters[52].letter=' ';
    letters[52].index=53;

    letters[53].letter='.';
    letters[53].index=54;

    letters[54].letter=',';
    letters[54].index=55;

    letters[55].letter=':';
    letters[55].index=56;

    letters[56].letter=';';
    letters[56].index=57;

    letters[57].letter='!';
    letters[57].index=58;

    return letters;
}

//string encrypt(string str)
string encrypt(string str)
{
    string encrypted="";
    for(int i=0;i<str.length();++i)
    {
        for(int j=0;j<A_SIZE;++j)
        {
            if(_ALPHABETS[j].letter==str[i])
            {
                encrypted=encrypted+convertToString(_ALPHABETS[j].index)+" ";
            }
        }
    }
    return encrypted;
}

//string removeFrontSpaces(string s)
string removeFrontSpaces(string s)
{
    int num=0;
    string ss="";
    for(int i=0;i<s.length();++i)
    {
        if(s[i]==' ')
        {
            ++num;
        }else
        {
            break;
        }
    }
    for(int i=num;i<s.length();++i)
    {
        ss+=s[i];
    }
    return ss;
}

//string removeBackSpaces(string s)
string removeBackSpaces(string s)
{
    string ss="";
    int num=0;
    for(int i=s.length()-1;i>=0;--i)
    {
        if(s[i]==' ')
        {
            ++num;
        }else
        {
            break;
        }
    }
    for(int i=0;i<s.length()-num;++i)
    {
        ss+=s[i];
    }
    return ss;
}

//string removingEndSpaces(string s)
string removeEndSpaces(string s)
{
    //removig the initial spaces
    s=removeFrontSpaces(s);
    //removing the spaces in the end of the string
    s=removeBackSpaces(s);
    return s;
}

//int numOfWords(string s,char c)
int numOfWords(string s,char c)
{
    s=removeEndSpaces(s);

    string ss="";
    for(int i=0;i<s.length();++i)
    {
        ss+=s[i];
    }
    int size=0;

    for(int i=0;i<ss.length();++i)
    {
        if(i==0)
        {
            ++size;
        }
        if(s[i]==c)
        {
            ++size;
            if(i+1<ss.length())
            {
                if(ss[i]==ss[i+1])
                {
                    --size;
                }
            }
        }
    }
    return size;

}

//string* stringSplit(string s,char c)
string* stringSplit(string s,char c)
{
    s=removeEndSpaces(s); //preprocessing the string to remove spaces
    string ss="";
    for(int i=0;i<s.length();++i)
    {
        ss+=s[i];
    }
    int size=0;

    for(int i=0;i<ss.length();++i)
    {
        if(i==0)
        {
            ++size;
        }
        if(s[i]==c)
        {
            ++size;
            if(i+1<ss.length())
            {
                if(ss[i]==ss[i+1])
                {
                    --size;
                }
            }
        }
    }
    int counter=0;
    string* str=new string[size];
    for(int i=0;i<ss.length();++i)
    {
        if(ss[i]==c)
        {
            ++counter;
            if(i+1<ss.length())
            {
                if(ss[i]==ss[i+1])
                {
                    --counter;
                }
            }
        }else
        {
            str[counter]+=ss[i];
        }
    }
    return str;
}

//string decrypt(string s)
string decrypt(string s)
{
    string* str=stringSplit(s,' ');
    int numWords=numOfWords(s,' ');
    string cleartext="";
    for(int i=0;i<numWords;++i)
    {
        for(int j=0;j<A_SIZE;++j)
        {
            if(_ALPHABETS[j].index==convertToInt(str[i]))
            {
                cleartext=cleartext+_ALPHABETS[j].letter;
            }
        }
    }
    return cleartext;
}

//void appendToCodeTXT(string str)
void appendToCodeTXT(string str)
{
    fstream fi;
    fi.open("code.txt",ios::app);
    if(fi.is_open())
    {
        fi<<str;
    }
    fi.close();
}

//void readAndDecodeCodeTXT()
void readAndDecodeCodeTXT()
{
    fstream fi;
    fi.open("code.txt",ios::in);
    string line;
    string str="";
    cout<<"  Decoded Text from code.txt below : "<<endl;
    if(fi.is_open())
    {
       while(getline(fi,line))
       {
           cout<<"    "<<decrypt(line)<<endl;
       }
    }
    fi.close();
}

//void readCodeTXT()
void readCodeTXT()
{
    fstream fi;
    fi.open("code.txt",ios::in);
    string line;
    string str="";
    cout<<"  Actual Text from code.txt below : "<<endl;
    if(fi.is_open())
    {
       while(getline(fi,line))
       {
           cout<<"    "<<line<<endl;
       }
    }
    fi.close();
}

//string getLast()
string getLast()
{
    string line="";
    fstream fil;
    string last;
    fil.open("code.txt",ios::in);
    if(fil.is_open())
    {
        while(getline(fil,line))
        {
            last=line;
        }
    }
    fil.close();
    return last;

}

//void removeLast()
void removeLast()
{
    fstream thefile;
    string name=getLast();
    string line="";
    string strinput="";
    thefile.open("code.txt",ios::in);
    if(thefile.is_open())
    {
        while(getline(thefile,line))
        {
            if(line!=name)
            {
                strinput=strinput+line+'\n';
            }
        }
        thefile.close();
        thefile.open("code.txt",ios::out);//write to thefile.txt by overwriting into the text file
        thefile<<strinput;//writing strinput into thefile file stream
        thefile.close();
    }
}

//void runOptionA()
void runOptionA()
{
    string str="";
    cout<<"Enter your word :"<<endl;
    getline(cin,str);
    string s=encrypt(str);
    s=s+'\n';
    appendToCodeTXT(s);

}

//void runOptionR()
void runOptionR()
{
    removeLast();
}

//void displayOptions()
void displayOptions()
{
    cout<<"Options : "<<endl;
    cout<<"a --> Add a word "<<endl;
    cout<<"r --> Remove last line"<<endl;
    cout<<"x --> Exit "<<endl;
}

