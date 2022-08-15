#include "SnakeH.h"
using namespace std;
namespace SnakeSpace
{
    GameWorld::GameWorld()
    {
        InitializeWorld();
    }

    void GameWorld::InitializeWorld()
    {
        length=1;

        arrWorld=new int*[ROWS];//creating memory for rows

        for(int i=0;i<ROWS;++i)
        {
            arrWorld[i]=new int[COLS];//create memory for columns in each row
        }
        //top wall
        for(int i=0;i<COLS;++i)
        {
            arrWorld[0][i]=WALL;
        }

        //bottom wall
        for(int i=0;i<COLS;++i)
        {
            arrWorld[ROWS-1][i]=WALL;

        }

        //side walls
        for(int i=1;i<ROWS-1;++i)
        {
            arrWorld[i][0]=WALL; //the first side wall
            arrWorld[i][COLS-1]=WALL;//the second side wall
        }

        for(int i=1;i<ROWS-1;++i)
        {
            for(int j=1;j<COLS-1;++j)
            {
                arrWorld[i][j]=SPACE;//creating space within the game world
            }
        }
        //now we are creating the coordinates for the head of the snake through a randomized process
        snake[0].currentpos.intx=genRand(1,ROWS-2);
        snake[0].currentpos.inty=genRand(1,COLS-2);

        //placing the head of the snake the game world
        arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]=HEAD;

        //creating and placing the fruit into the game world
        makeFruit();
    }
    void GameWorld::makeFruit()
    {

        fruit.intx=genRand(1,ROWS-2);
        fruit.inty=genRand(1,COLS-2);
        while(arrWorld[fruit.intx][fruit.inty]==SNAKE || arrWorld[fruit.intx][fruit.inty]==HEAD)
        {
            fruit.intx=genRand(1,ROWS-2);
            fruit.inty=genRand(1,COLS-2);
        }
        arrWorld[fruit.intx][fruit.inty]=FRUIT;

    }
    void GameWorld::printGame()
    {
        system("cls");
        for(int i=0;i<ROWS;++i)
        {
            for(int a=0;a<COLS;++a)
            {
                if(arrWorld[i][a]==SPACE)
                {
                    cout<<CH_SPACE<<" ";
                }
                if(arrWorld[i][a]==SNAKE)
                {
                    cout<<CH_SNAKE<<" ";
                }
                if(arrWorld[i][a]==HEAD)
                {
                    cout<<CH_HEAD<<" ";
                }
                if(arrWorld[i][a]==FRUIT)
                {
                    cout<<CH_FRUIT<<" ";
                }
                if(arrWorld[i][a]==WALL)
                {
                    cout<<CH_WALL<<" ";
                }


            }
            cout<<endl;
        }

        cout<<endl;
        cout<<"Target length = "<<MAX_LENGTH<<endl;
        cout<<"Current length = "<<length<<endl;
        cout<<"Warning ! eat yourself ,you die !!!!"<<endl;
        cout<<endl;
        cout<<"Enter your input : ";


    }

    void GameWorld::moveSnake(char input)
    {

        //before motion begins set previous position to current position for each segment
        for(int i=0;i<length;++i)
        {
            snake[i].prevpos.intx=snake[i].currentpos.intx;
            snake[i].prevpos.inty=snake[i].currentpos.inty;
        }
        //motion is focused on the head segment
        switch(input)
        {
            //moving up by reducing the x coordinate
            case 'w':
            case 'W':
                --snake[0].currentpos.intx;
                if(arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]==WALL)
                {
                    ++snake[0].currentpos.intx;
                }
                break;

            //moving left by reducing the y coordinate
            case 'a':
            case 'A':
                --snake[0].currentpos.inty;
                if(arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]==WALL)
                {
                    ++snake[0].currentpos.inty;
                }
                break;

            //moving down by adding the x coordinate
            case 's':
            case 'S':
                ++snake[0].currentpos.intx;
                if(arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]==WALL)
                {
                    --snake[0].currentpos.intx;
                }
                break;

            //moving right by adding the y coordinate
            case 'd':
            case 'D':
                ++snake[0].currentpos.inty;
                if(arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]==WALL)
                {
                    --snake[0].currentpos.inty;
                }
                break;

            default :
                cerr<<"Error : Invalid input ... please retry "<<endl;
                system("pause");
                break;

        }
        //if the head has different coordinates for current and previous position then do this
        if(snake[0].currentpos.intx!=snake[0].prevpos.intx || snake[0].currentpos.inty!=snake[0].prevpos.inty)
        {
            for(int i=1;i<length;++i)
            {
                snake[i].currentpos.intx=snake[i-1].prevpos.intx;
                snake[i].currentpos.inty=snake[i-1].prevpos.inty;
            }
        }
        //checking if the fruit will be eaten
        if(arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]==FRUIT)
        {
            makeFruit();//the fruit is now eaten so create another fruit
            length=length+1;//once the fruit is eaten then increase the length of the snake by one to grow the snake
            snake[length-1].currentpos.intx=snake[length-2].prevpos.intx;
            snake[length-1].currentpos.inty=snake[length-2].prevpos.inty;
            snake[length-1].prevpos.intx=snake[length-1].currentpos.intx;
            snake[length-1].prevpos.inty=snake[length-1].currentpos.inty;
        }


        //moving the head of the snake forward
        arrWorld[snake[0].prevpos.intx][snake[0].prevpos.inty]=SPACE;
        arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]=HEAD;

        //moving the body of the snake forward
        for(int i=1;i<length;++i)
        {
            arrWorld[snake[i].prevpos.intx][snake[i].prevpos.inty]=SPACE;
            arrWorld[snake[i].currentpos.intx][snake[i].currentpos.inty]=SNAKE;
        }
        arrWorld[snake[0].currentpos.intx][snake[0].currentpos.inty]=HEAD;

        //code for making sure there is a fruit in the gameWorld
        bool theresFruit=false;
        for(int i=1;i<ROWS-1;++i)
        {
            for(int j=1;j<COLS-1;++j)
            {
                if(arrWorld[i][j]==FRUIT)
                {
                    theresFruit=true;
                }
            }
        }
        //if there is no fruit then make the fruit
        if(!theresFruit)
        {
            makeFruit();
        }

        //checking the result of the current move in terms of win and lose
        CheckWon(length);//checking if the snake has reached maximum length
        CheckLost(snake[0].currentpos.intx,snake[0].currentpos.inty);
    }
    void GameWorld::CheckLost(int x,int y)
    {
        if(arrWorld[x][y]==WALL)
        {
            lost=true;
        }else if(arrWorld[x][y]==SNAKE )
        {
            lost=true;
        }else
        {
            lost=false;
        }
    }
    void GameWorld::CheckWon(int intval)
    {
        if(intval==MAX_LENGTH)
        {
            won=true;
        }
    }
    bool GameWorld::getLost()
    {
        return lost;
    }
    bool GameWorld::getWon()
    {
        return won;
    }
    void GameWorld::ReStartWorld()
    {
        InitializeWorld();
        length=1;
        lost=false;
        won=false;
    }

    void GameWorld::DeallocateWorld()
    {
        for(int i=0;i<ROWS;++i)
        {
            delete[] arrWorld[i];
        }
        delete[] arrWorld;
        arrWorld=nullptr;
    }

    int GameWorld::genRand(int lower,int upper)
    {
        srand(time(0));
        int range=upper-lower+1;
        return (rand()%range)+lower;
    }

}
