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
    const int SPACE=0;//1
    const int SNAKE=1;//1
    const int HEAD=2;//1
    const int FRUIT=3;//1
    const int WALL=4;//1

    //characters for the game
    const char CH_SPACE=' ';//1
    const char CH_SNAKE='0';//1
    const char CH_HEAD ='H';//1
    const char CH_FRUIT='F';//1
    const char CH_WALL='#';//1

    const int ROWS=8; //rows are fixed at 8 //1
    const int COLS=15;//column are fixed at 15//1
    const int MAX_LENGTH=7;//maximum length of snake is capped at 30//1


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
        ///set-up
            GameWorld(); //the constructor
            void InitializeWorld();
            void ReStartWorld();

        ///dynamic
            void printGame();
            void moveSnake(char chin);
            bool getWon();
            bool getLost();

        ///termination
            void DeallocateWorld();

        private:
        ///set-up
            int genRand(int lower,int upper);
            int** arrWorld;//the environment of the game
            int length;//length of the snake

        /// dynamic
            bool lost;//check if you lost
            bool won;//check if you won
            SnakeSegment snake[MAX_LENGTH];//the snake
            coordinates fruit;//the fruit
            void makeFruit();//put a fruit in new legal position on the world
            void CheckWon(int val);
            void CheckLost(int x,int y);

        ///termination
    };


}


#endif // SNAKEH_H_INCLUDED
