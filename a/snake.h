//
//  snake.h
//  SnakeGameSfml
//
//  Created by Leroy Yu Tse on 23/09/15.
//  Copyright (c) 2015 Leroy Yu Tse. All rights reserved.
//

#ifndef SnakeGameSfml_snake_h
#define SnakeGameSfml_snake_h

enum Direction { Up, Down, Right, Left};
int direction = Right;


bool Player2 = true;
bool crash = false;

int Score = 0;
int Score1 = 0;

int t;


sf::Texture snakehead;
sf::Sprite snakeSprite;

sf::Texture snakebody;
sf::Sprite snakeSprite1;

sf::Texture snaketail;
sf::Sprite snakeSprite2;

sf::Texture snakehead1;
sf::Sprite snake1Sprite;

sf::Texture snakebody1;
sf::Sprite snake1Sprite1;

sf::Texture snaketail1;
sf::Sprite snake1Sprite2;

sf::Texture snakeP1;
sf::Sprite snakeP1Sprite;

sf::Texture snakeP2;
sf::Sprite snakeP2Sprite;

sf::Texture gameOverText;
sf::Sprite gameOverSprite;

std::string finalScore;
std::stringstream convert;

std::string finalScore1;
std::stringstream convert1;

std::string Timer;
std::stringstream convertTime;
sf::Text Time;

sf::Text scoreF;
sf::Text scoreF1;


sf::Text text;
sf::Text disableP2;
sf::Text EnableCrash;
sf::Text P1win;
sf::Text P2win;
sf::Text Draw;
sf::Text TimeUp;
sf::Font font;

class display
{
private:
    sf::Clock clock; // starts the clock
    
public:
    void Display();
    void restart();
    void Player1win();
    void Player2win();
    void draw();
    void timer();
    void time();
    void gameoverP1win();
    void gameoverP2win();
    void gameoverDraw();
};


class Block
{
private:
    int ax, ay;
    
public:
    Block(int, int);
    int getX();
    int getY();
    
};

class Snake
{
private:
    std::deque<Block> asnake;
    int adirection;
    
public:
    void Move(int Right);
    void grow();
    void shrink();
    void restart();
    std::deque<Block> getBlocks();
    int getX();
    int getY();
    Snake();
    void setdirection();
};
//SnakeP2
int direction1 = Left;

class Block1
{
private:
    int ax, ay;
    
public:
    Block1(int, int);
    int getX1();
    int getY1();
    
};


class Snake1
{
private:
    std::deque<Block1> bsnake;
    int adirection1;
    
public:
    void Move1(int Left);
    void grow1();
    void shrink1();
    void restart1();
    std::deque<Block1> getBlocks1();
    int getX1();
    int getY1();
    Snake1();
    void setdirection1();
};
#endif
