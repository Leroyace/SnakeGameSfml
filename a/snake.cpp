//
//  snake.cpp
//  SnakeGameSfml
//
//  Created by Leroy Yu Tse on 23/09/15.
//  Copyright (c) 2015 Leroy Yu Tse. All rights reserved.
//

#include "snake.h"

void display::restart()
{
    Player2 = true;
    crash = false;
    gameOverSprite.setColor(sf::Color(255,255,255,0));
    text.setColor(sf::Color(255,255,255,0));
    disableP2.setColor(sf::Color(255,255,255,0));
    EnableCrash.setColor(sf::Color(255,255,255,0));
    P1win.setColor(sf::Color(255,255,255,0));
    P2win.setColor(sf::Color(255,255,255,0));
    Draw.setColor(sf::Color(255,255,255,0));
    scoreF.setColor(sf::Color(255,255,255,0));
    scoreF1.setColor(sf::Color(255,255,255,0));
    scoreF.setCharacterSize(25);
    scoreF1.setCharacterSize(25);
    snakeP1Sprite.setColor(sf::Color(255,255,255,0));
    snakeP2Sprite.setColor(sf::Color(255,255,255,0));
    Time.setColor(sf::Color::Black);
    TimeUp.setColor(sf::Color(255,255,255,0));
    scoreF.setPosition(955, 0);
    scoreF1.setPosition(60, 0);
    snakeP1Sprite.setPosition(920, 2);
    snakeP2Sprite.setPosition(25, 2);
    snakeP1Sprite.setScale(0.8, 0.8);
    snakeP2Sprite.setScale(0.8, 0.8);
    clock.restart();
}


void display::Display()
{
    // Create a graphical text to display
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    //Text for Restart the game
    text.setString("Press F5 to start a new game");
    text.setFont(font);
    text.setCharacterSize(43);
    text.setColor(sf::Color(255,255,255,0));
    //Disable P2
    disableP2.setString("Press F1 to disable P2");
    disableP2.setFont(font);
    disableP2.setCharacterSize(25);
    disableP2.setColor(sf::Color(255,255,255,0));
    //Enable crash
    EnableCrash.setString("Press F2 to enable Player can crash together");
    EnableCrash.setFont(font);
    EnableCrash.setCharacterSize(25);
    EnableCrash.setColor(sf::Color(255,255,255,0));
    //win massage
    P1win.setString("Player    win!!!");
    P1win.setFont(font);
    P1win.setCharacterSize(45);
    P1win.setColor(sf::Color(255,255,255,0));
    
    P2win.setString("Player    win!!!");
    P2win.setFont(font);
    P2win.setCharacterSize(45);
    P2win.setColor(sf::Color(255,255,255,0));
    //Draw
    Draw.setString("Draw!!!");
    Draw.setFont(font);
    Draw.setCharacterSize(70);
    Draw.setColor(sf::Color(255,255,255,0));
    //TimeUp
    TimeUp.setString("Time's Up!!!");
    TimeUp.setFont(font);
    TimeUp.setCharacterSize(75);
    TimeUp.setColor(sf::Color(255,255,255,0));
    //Timer
    Time.setFont(font);
    Time.setCharacterSize(30);
    Time.setColor(sf::Color::Black);
    Time.setPosition(440, 0);
    
    //Score
    scoreF.setFont(font);
    scoreF.setCharacterSize(25);
    scoreF.setColor(sf::Color::Black);
    scoreF.setPosition(955, 0);
    
    scoreF1.setFont(font);
    scoreF1.setCharacterSize(25);
    scoreF1.setColor(sf::Color::Black);
    scoreF1.setPosition(60, 0);
    
    //PlayerImage
    snakeP1.loadFromFile(resourcePath() + "head.png");
    snakeP1Sprite.setTexture(snakeP1);
    snakeP1Sprite.setTextureRect(sf::IntRect(80,0,40,40));
    snakeP1Sprite.setScale(0.8, 0.8);
    snakeP1Sprite.setPosition(920, 2);
    snakeP1Sprite.setColor(sf::Color(255,255,255,0));
    
    snakeP2.loadFromFile(resourcePath() + "head1.png");
    snakeP2Sprite.setTexture(snakeP2);
    snakeP2Sprite.setTextureRect(sf::IntRect(80,0,40,40));
    snakeP2Sprite.setScale(0.8, 0.8);
    snakeP2Sprite.setPosition(25, 2);
    snakeP2Sprite.setColor(sf::Color(255,255,255,0));
    
}

void display::timer()
{
    //timer
    int timeOver = 120;
    sf::Time elapsed1 = clock.getElapsedTime();
    t = timeOver - elapsed1.asSeconds();
    convertTime << (int)t;
    Timer = "Timer: " + convertTime.str();
    convertTime.str("");
}

void display::Player1win()
{
    P1win.setColor(sf::Color::Black);
    P1win.setPosition(350, 120);
    snakeP1Sprite.setColor(sf::Color::White);
    snakeP1Sprite.setPosition(480, 135);
    snakeP2Sprite.setColor(sf::Color::White);
    snakeP2Sprite.setScale(0.5, 0.5);
    snakeP2Sprite.setPosition(430, 242);
    scoreF.setColor(sf::Color::Black);
    scoreF.setCharacterSize(40);
    scoreF.setPosition(410, 180);
    convert << (int)Score;
    finalScore = "Score: " + convert.str();
    convert.str("");
    scoreF1.setColor(sf::Color::Black);
    scoreF1.setCharacterSize(20);
    scoreF1.setPosition(452, 240);
    convert1 << (int)Score1;
    finalScore1 = "Score: " + convert1.str();
    convert1.str("");
}

void display::Player2win()
{
    P2win.setColor(sf::Color::Black);
    P2win.setPosition(350, 120);
    snakeP2Sprite.setColor(sf::Color::White);
    snakeP2Sprite.setPosition(480, 135);
    snakeP1Sprite.setColor(sf::Color::White);
    snakeP1Sprite.setScale(0.5, 0.5);
    snakeP1Sprite.setPosition(430, 242);
    scoreF1.setColor(sf::Color::Black);
    scoreF1.setCharacterSize(40);
    scoreF1.setPosition(410, 180);
    convert1 << (int)Score1;
    finalScore1 = "Score: " + convert1.str();
    convert1.str("");
    scoreF.setColor(sf::Color::Black);
    scoreF.setCharacterSize(20);
    scoreF.setPosition(452, 240);
    convert << (int)Score;
    finalScore = "Score: " + convert.str();
    convert.str("");
}

void display::draw()
{
    snakeP2Sprite.setColor(sf::Color::White);
    snakeP2Sprite.setScale(0.7, 0.7);
    snakeP2Sprite.setPosition(390, 235);
    snakeP1Sprite.setColor(sf::Color::White);
    snakeP1Sprite.setScale(0.7, 0.7);
    snakeP1Sprite.setPosition(420, 235);
    Draw.setColor(sf::Color::Black);
    Draw.setPosition(385, 120);
    scoreF.setColor(sf::Color::Black);
    scoreF.setCharacterSize(30);
    scoreF.setPosition(450, 230);
    convert << (int)Score;
    finalScore = "Score: " + convert.str();
    convert.str("");
}


void display::time()
{
    Time.setColor(sf::Color(255,255,255,0));
    TimeUp.setColor(sf::Color::Black);
    TimeUp.setPosition(295, 310);
    text.setColor(sf::Color::Red);
    text.setPosition(230, 500);
    disableP2.setColor(sf::Color::Red);
    disableP2.setPosition(380, 570);
    EnableCrash.setColor(sf::Color::Red);
    EnableCrash.setPosition(255, 610);
}

void display::gameoverDraw()
{
    gameOverText.loadFromFile(resourcePath() + "GameOver1.png");
    gameOverSprite.setTexture(gameOverText);
    gameOverSprite.setScale(0.61,0.61);
    gameOverSprite.setColor(sf::Color::White);
    gameOverText.setSmooth(true);
    text.setColor(sf::Color::Red);
    text.setPosition(230, 500);
    disableP2.setColor(sf::Color::Red);
    disableP2.setPosition(380, 570);
    EnableCrash.setColor(sf::Color::Red);
    EnableCrash.setPosition(255, 610);
    snakeP2Sprite.setColor(sf::Color::White);
    snakeP2Sprite.setScale(0.7, 0.7);
    snakeP2Sprite.setPosition(390, 235);
    snakeP1Sprite.setColor(sf::Color::White);
    snakeP1Sprite.setScale(0.7, 0.7);
    snakeP1Sprite.setPosition(420, 235);
    Draw.setColor(sf::Color::Black);
    Draw.setPosition(385, 120);
    scoreF.setColor(sf::Color::Black);
    scoreF.setCharacterSize(30);
    scoreF.setPosition(450, 230);
    convert << (int)Score;
    finalScore = "Score: " + convert.str();
    convert.str("");
}

void display::gameoverP2win()
{   gameOverText.loadFromFile(resourcePath() + "GameOver1.png");
    gameOverSprite.setTexture(gameOverText);
    gameOverSprite.setScale(0.61,0.61);
    gameOverSprite.setColor(sf::Color::White);
    gameOverText.setSmooth(true);
    text.setColor(sf::Color::Red);
    text.setPosition(230, 500);
    disableP2.setColor(sf::Color::Red);
    disableP2.setPosition(380, 570);
    EnableCrash.setColor(sf::Color::Red);
    EnableCrash.setPosition(255, 610);
    P2win.setColor(sf::Color::Black);
    P2win.setPosition(350, 120);
    snakeP2Sprite.setColor(sf::Color::White);
    snakeP2Sprite.setPosition(480, 135);
    snakeP1Sprite.setColor(sf::Color::White);
    snakeP1Sprite.setScale(0.5, 0.5);
    snakeP1Sprite.setPosition(430, 242);
    scoreF1.setColor(sf::Color::Black);
    scoreF1.setCharacterSize(40);
    scoreF1.setPosition(410, 180);
    convert1 << (int)Score1;
    finalScore1 = "Score: " + convert1.str();
    convert1.str("");
    scoreF.setColor(sf::Color::Black);
    scoreF.setCharacterSize(20);
    scoreF.setPosition(452, 240);
    convert << (int)Score;
    finalScore = "Score: " + convert.str();
    convert.str("");
}
void display::gameoverP1win()
{
    gameOverText.loadFromFile(resourcePath() + "GameOver1.png");
    gameOverSprite.setTexture(gameOverText);
    gameOverSprite.setScale(0.61,0.61);
    gameOverSprite.setColor(sf::Color::White);
    gameOverText.setSmooth(true);
    text.setColor(sf::Color::Red);
    text.setPosition(230, 500);
    disableP2.setColor(sf::Color::Red);
    disableP2.setPosition(380, 570);
    EnableCrash.setColor(sf::Color::Red);
    EnableCrash.setPosition(255, 610);
    P1win.setColor(sf::Color::Black);
    P1win.setPosition(350, 120);
    snakeP1Sprite.setColor(sf::Color::White);
    snakeP1Sprite.setPosition(480, 135);
    snakeP2Sprite.setColor(sf::Color::White);
    snakeP2Sprite.setScale(0.5, 0.5);
    snakeP2Sprite.setPosition(430, 242);
    scoreF.setColor(sf::Color::Black);
    scoreF.setCharacterSize(40);
    scoreF.setPosition(410, 180);
    convert << (int)Score;
    finalScore = "Score: " + convert.str();
    convert.str("");
    scoreF1.setColor(sf::Color::Black);
    scoreF1.setCharacterSize(20);
    scoreF1.setPosition(452, 240);
    convert1 << (int)Score1;
    finalScore1 = "Score: " + convert1.str();
    convert1.str("");
}

void Snake::restart()
{
    asnake.clear();
    asnake.push_front(Block(475,400));
    grow();
    direction = Right;
}

Block::Block(int x, int y)
{
    ax = x;
    ay = y;
}

int Block::getX()
{
    return ax;
}

int Block::getY()
{
    return ay;
}

void Snake::Move(int NewDirection)
{
    int move = 25;
    shrink();
    //Right
    if (asnake.front().getX() >= 1000 || (asnake.front().getX() >= 1000 && (NewDirection == Up || NewDirection == Down))) {
        shrink();
        asnake.push_front(Block(asnake.front().getX()-1000,asnake.front().getY()));
        NewDirection = Right;
    }
    //Left
    if (asnake.front().getX() <= -25 || (asnake.front().getX() <= -25 && (NewDirection == Up || NewDirection == Down))) {
        shrink();
        asnake.push_front(Block(asnake.front().getX()+1000,asnake.front().getY()));
        NewDirection = Left;
    }
    //Down
    if (asnake.front().getY() >= 700 || (asnake.front().getY() >= 700 && (NewDirection == Left || NewDirection == Right))) {
        shrink();
        asnake.push_front(Block(asnake.front().getX(),asnake.front().getY()-700));
        NewDirection = Down;
    }
    //Up
    if (asnake.front().getY() <= -25 || (asnake.front().getY() <= -25 && (NewDirection == Left || NewDirection == Right))) {
        shrink();
        asnake.push_front(Block(asnake.front().getX(),asnake.front().getY()+700));
        NewDirection = Up;
    }
    if(NewDirection == Up)
    {
        
        if(adirection != Down)
        {
            asnake.push_front(Block(asnake.front().getX(), asnake.front().getY() - move));
            adirection = Up;
        }
        else
        {
            asnake.push_front(Block(asnake.front().getX(), asnake.front().getY() + move));
        }
    }
    else if(NewDirection == Right)
    {
        
        if(adirection != Left)
        {
            asnake.push_front(Block(asnake.front().getX() + move, asnake.front().getY()));
            adirection = Right;
        }
        else
        {
            asnake.push_front(Block(asnake.front().getX() - move, asnake.front().getY()));
            
        }
    }
    else if(NewDirection == Down)
    {
        if(adirection != Up)
        {
            asnake.push_front(Block(asnake.front().getX(), asnake.front().getY() + move));
            adirection = Down;
        }
        else
        {
            asnake.push_front(Block(asnake.front().getX(), asnake.front().getY() - move));
        }
        
    }
    else if(NewDirection == Left)
    {
        if(adirection != Right)
        {
            asnake.push_front(Block(asnake.front().getX() - move, asnake.front().getY()));
            adirection = Left;
        }
        else
        {
            asnake.push_front(Block(asnake.front().getX() + move, asnake.front().getY()));
        }
    }
    
}

void Snake::grow()
{
    asnake.push_back(Block(asnake.back().getX(), asnake.back().getY()));
}
void Snake::shrink()
{
    asnake.pop_back();
}

std::deque<Block> Snake::getBlocks()
{
    return asnake;
}
int Snake::getX()
{
    return asnake.front().getX();
}

int Snake::getY()
{
    return asnake.front().getY();
}

Snake::Snake()
{
    asnake.push_front(Block(475,400));
}

void Snake::setdirection()
{
    adirection = Up;
}

//SnakeP2
void Snake1::restart1()
{
    bsnake.clear();
    bsnake.push_front(Block1(475,300));
    grow1();
    direction1 = Left;
}

Block1::Block1(int x, int y)
{
    ax = x;
    ay = y;
}

int Block1::getX1()
{
    return ax;
}

int Block1::getY1()
{
    return ay;
}

void Snake1::Move1(int NewDirection1)
{
    shrink1();
    //Right
    if (bsnake.front().getX1() >= 1000 || (bsnake.front().getX1() >= 1000 && (NewDirection1 == Up || NewDirection1 == Down))) {
        shrink1();
        bsnake.push_front(Block1(bsnake.front().getX1()-1000,bsnake.front().getY1()));
        NewDirection1 = Right;
    }
    //Left
    if (bsnake.front().getX1() <= -25 || (bsnake.front().getX1() <= -25 && (NewDirection1 == Up || NewDirection1 == Down))) {
        shrink1();
        bsnake.push_front(Block1(bsnake.front().getX1()+1000,bsnake.front().getY1()));
        NewDirection1 = Left;
    }
    //Down
    if (bsnake.front().getY1() >= 700 || (bsnake.front().getY1() >= 700 && (NewDirection1 == Left || NewDirection1 == Right))) {
        shrink1();
        bsnake.push_front(Block1(bsnake.front().getX1(),bsnake.front().getY1()-700));
        NewDirection1 = Down;
    }
    //Up
    if (bsnake.front().getY1() <= -25 || (bsnake.front().getY1() <= -25 && (NewDirection1 == Left || NewDirection1 == Right))) {
        shrink1();
        bsnake.push_front(Block1(bsnake.front().getX1(),bsnake.front().getY1()+700));
        NewDirection1 = Up;
    }
    if(NewDirection1 == Up)
    {
        
        if(adirection1 != Down)
        {
            bsnake.push_front(Block1(bsnake.front().getX1(), bsnake.front().getY1() - 25));
            adirection1 = Up;
        }
        else
        {
            bsnake.push_front(Block1(bsnake.front().getX1(), bsnake.front().getY1() + 25));
        }
    }
    else if(NewDirection1 == Right)
    {
        
        if(adirection1 != Left)
        {
            bsnake.push_front(Block1(bsnake.front().getX1() + 25, bsnake.front().getY1()));
            adirection1 = Right;
        }
        else
        {
            bsnake.push_front(Block1(bsnake.front().getX1() - 25, bsnake.front().getY1()));
            
        }
    }
    else if(NewDirection1 == Down)
    {
        if(adirection1 != Up)
        {
            bsnake.push_front(Block1(bsnake.front().getX1(), bsnake.front().getY1() + 25));
            adirection1 = Down;
        }
        else
        {
            bsnake.push_front(Block1(bsnake.front().getX1(), bsnake.front().getY1() - 25));
        }
        
    }
    else if(NewDirection1 == Left)
    {
        if(adirection1 != Right)
        {
            bsnake.push_front(Block1(bsnake.front().getX1() - 25, bsnake.front().getY1()));
            adirection1 = Left;
        }
        else
        {
            bsnake.push_front(Block1(bsnake.front().getX1() + 25, bsnake.front().getY1()));
        }
    }
    
}

void Snake1::grow1()
{
    bsnake.push_back(Block1(bsnake.back().getX1(), bsnake.back().getY1()));
    
}
void Snake1::shrink1()
{
    bsnake.pop_back();
}

std::deque<Block1> Snake1::getBlocks1()
{
    return bsnake;
}
int Snake1::getX1()
{
    return bsnake.front().getX1();
}

int Snake1::getY1()
{
    return bsnake.front().getY1();
}

Snake1::Snake1()
{
    bsnake.push_front(Block1(475,300));
}

void Snake1::setdirection1()
{
    adirection1 = Up;
}
