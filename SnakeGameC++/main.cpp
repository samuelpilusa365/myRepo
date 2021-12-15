#include "SnakeH.h"
#include "SnakeSource.cpp"
using namespace std;
//using namespace SnakeSpace;
int main()
{

    SnakeSpace::GameWorld game;//initializing the game world
    bool blnContinue=true; //whether to continue the game
    bool InIntermediate=false;
    char input=' ';
    int won=0;
    bool haswon=false;

    do{

            game.printGame();       //printing the game
            cin>>input;          //get input from user

            //if the game is not in the intermediate stage then move the snake
            if(!InIntermediate)
            {
                game.moveSnake(input);
            }

            //if the user decides to quit
            if(input=='x' || input=='X')
            {
                game.DeallocateWorld();
                blnContinue=false;
            }

            //if the user has won
            if(game.getWon())
            {
                cout<<"*******************************************"<<endl;
                cout<<"***********  YOU WON :-)!!! ***************"<<endl;
                cout<<"*******************************************"<<endl;
                game.IntermediateState(InIntermediate);
                cout<<endl;
                cout<<"Do you wishe to continue ?(n = no ,y = yes) :";
                char cont=' ';
                cin>>cont;
                switch(cont)
                {
                    case 'y':
                    case 'Y':
                        game.ReStartWorld();
                        InIntermediate=false;
                        blnContinue=true;
                    break;
                    case 'n':
                    case 'N':
                        game.DeallocateWorld();
                        blnContinue=false;
                    break;
                    default:
                    cerr<<"Error : invalid choice...please retry"<<endl;
                    break;
                }
            }

            //if the user has lost
            if(game.getLost())
            {
                cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                cout<<"%%%%%%%%%%%%% YOU LOST :((%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                game.IntermediateState(InIntermediate);
                cout<<endl;
                cout<<"Do you wishe to continue ?(n = no ,y = yes) :";
                char cont=' ';
                cin>>cont;
                switch(cont)
                {
                    case 'y':
                    case 'Y':
                        game.ReStartWorld();
                        blnContinue=true;
                        InIntermediate=false;
                    break;
                    case 'n':
                    case 'N':
                        game.DeallocateWorld();
                        blnContinue=false;
                    break;
                    default:
                        cerr<<"Error : invalid choice...please retry"<<endl;
                }
            }
        }while(blnContinue);
    return 0;
}
