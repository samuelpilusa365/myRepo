#ifndef SNAKEH_H_INCLUDED
#define SNAKEH_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cassert>
namespace SnakeSpace
{
    //game characters expressed in numbers
    const int SPACE=0;
    const int SNAKE=1;
    const int HEAD=2;
    const int FRUIT=3;
    const int WALL=4;

    //characters for the game
    const char CH_SPACE=' ';
    const char CH_SNAKE='0';
    const char CH_HEAD ='H';
    const char CH_FRUIT='F';
    const char CH_WALL='#';

    const int ROWS=8; //rows are fixed at 8
    const int COLS=15;//column are fixed at 15
    const int MAX_LENGTH=5;//maximum length of snake is capped at 30


    struct coordinates//to store coordinates of the world for navigation
    {
        int intx;
        int inty;
    };
    struct SnakeSegment//each snake segment
    {
            coordinates currentpos;
            coordinates prevpos;
    };
    class GameWorld
    {
        public:
            GameWorld();//calls the InitializeWorld method(contructor)
            void InitializeWorld();//make the initial environment
            void printGame();//changes the numbers into characters;
            void moveSnake(char chin);//move the snake - this is where the action happens
            bool getWon();//get the win status of the player
            bool getLost();//get the lose status of the player
            void ReStartWorld();
            void DeallocateWorld();
            void IntermediateState(bool &blnInt);

        private:
            int genRand(int lower,int upper);
            int** arrWorld;//the environment of the game
            int length;//length of the snake
            bool lost;//check if you lost
            bool won;//check if you won
            SnakeSegment snake[MAX_LENGTH];//the snake
            coordinates fruit;//the fruit

            void CheckWon(int val);
            void CheckLost(int x,int y,int a,int b);
            void makeFruit();//put a fruit in new legal position on the world

    };


}


#endif // SNAKEH_H_INCLUDED
