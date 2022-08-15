#include "SnakeSource.cpp"
using namespace std;
//*************game optimizatiion notes*******************
/**    main game divisions
   1. set-up section - what happens when the game is booted and no player input is processed yet.
   2. dynamic section - this is where thegame gets to be played.
   3. termination section - this is last state of the game as the player exits the game.

**/
using namespace SnakeSpace;
int main()
{
   GameWorld game;//initializing the game world

    bool blnContinue=true; //whether to continue the game
    bool InIntermediate=false;
    char input=' ';     //to store the player's choice or move
    bool haswon=false;

    do{

            game.printGame();       //printing the game


            //if the game is not in the intermediate stage then move the snake and chnange arrayWorld
            if(!InIntermediate)
            {
                cin>>input;     //get input from player
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
                system("cls");
                cout<<"*******************************************"<<endl;
                cout<<"***********  YOU WON :-)!!! ***************"<<endl;
                cout<<"*******************************************"<<endl;
                InIntermediate=true;
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
                system("cls");
                cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                cout<<"%%%%%%%%%%%%% YOU LOST :((%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                InIntermediate=true;
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
