#include "SnakeH.h"
#include "SnakeSource.cpp"
using namespace std;
using namespace SnakeSpace;
int main()
{

    GameWorld game;

    bool blnContinue=true;
    bool InIntermediate=false;
    char input=' ';
    int won=0;
    bool haswon=false;

    do{
            game.printGameWorld();
            cin>>input;
            if(!InIntermediate)
            {
                game.moveSnake(input);
            }

            if(input=='x' || input=='X')
            {
                game.DeallocateWorld();
                blnContinue=false;
            }

            if(game.getWon())
            {

                cout<<"*******************************************"<<endl;
                cout<<"***********  YOU WON :-)!!! ******************"<<endl;
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
                    break;
                }


            }


    }while(blnContinue);

    return 0;
}
