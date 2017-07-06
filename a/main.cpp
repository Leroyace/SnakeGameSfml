#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include <deque>
#include <sstream>
#include "snake.h"
#include "snake.cpp"

int main()
{
    sf::Event event;
    
    display display;
    display.Display();
    
    Snake snake;
    snake.setdirection();
    snake.grow();
    
    
    Snake1 snake1;
    snake1.setdirection1();
    snake1.grow1();
    
    const int window_width = 1000;
    const int window_height = 700;
    
    
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Snake game");
    window.setFramerateLimit(20);
    
    //Food
    
    sf::Texture applet;
    sf::Sprite appleSprite;
    applet.loadFromFile(resourcePath() + "apple.png");
    appleSprite.setTexture(applet);
    appleSprite.setPosition(100, 500);
    
    
    sf::Texture applet1;
    sf::Sprite apple1Sprite;
    applet1.loadFromFile(resourcePath() + "apple.png");
    apple1Sprite.setTexture(applet1);
    apple1Sprite.setPosition(500, 100);
    
    sf::Texture appleP1;
    sf::Sprite appleP1Sprite;
    appleP1.loadFromFile(resourcePath() + "Apple1.png");
    appleP1Sprite.setTexture(appleP1);
    appleP1Sprite.setPosition(750, 200);
    
    sf::Texture appleP2;
    sf::Sprite appleP2Sprite;
    appleP2.loadFromFile(resourcePath() + "Apple2.png");
    appleP2Sprite.setTexture(appleP2);
    appleP2Sprite.setPosition(700, 600);
    
    
    sf::VertexArray lines1(sf::Lines, 100);
    sf::VertexArray lines2(sf::Lines, 100);
    
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    
    for(int i = 0; i < 100; i++) {
        if ( i%2 == 0) {
            y1 += 25;
            x1 = 0;
        }
        else {
            x1 += 1000;
        }
        lines1[i].position = sf::Vector2f(x1,y1);
        lines1[i].color = sf::Color(255,(i)*50,255,255);//sf::Color::White;
    }
    for(int i = 0; i < 100; i++) {
        if ( i%2 == 0) {
            y2 = 0;
            x2 += 25;
        }
        else {
            y2 += 1000;
        }
        lines2[i].position = sf::Vector2f(x2,y2);
        lines2[i].color = sf::Color(255,(i)*50,255,255);//sf::Color::White;
    }
  
    // Start the game loop
    while (window.isOpen())
    {
        display.timer();
        if (t < 0) {
            display.time();
            if (Score > Score1) {
                display.Player1win();
                snake.restart();
                snake1.restart1();
            }
            if (Score < Score1) {
                display.Player2win();
                snake.restart();
                snake1.restart1();
            }
            if (Score == Score1) {
                display.draw();
                snake.restart();
                snake1.restart1();
            }
            
        }
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            int Speed = 15;
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1) {
                Player2 = false;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2) {
                crash = true;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F9) {
                if (Speed < 35) {
                    Speed += 5;
                }
                window.setFramerateLimit(Speed);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F7) {
                if (Speed > 10) {
                    Speed -= 5;
                }
                window.setFramerateLimit(Speed);
            }
            //Restart the game
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                snake.restart();
                snake1.restart1();
                display.restart();
                Score = 0;
                Score1 = 0;
            }
            
        }
        
        
        //Movement for SnakeP1
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direction = Left;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction = Right;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            direction = Down;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            direction = Up;
        }
        if(direction == Left)
        {
            snakeSprite.setTextureRect(sf::IntRect(120,0,40,40));
            snakeSprite2.setTextureRect(sf::IntRect(20,20,20,20));
            snake.Move(direction);
        }
        if(direction == Right)
        {
            snakeSprite.setTextureRect(sf::IntRect(40,0,40,40));
            snakeSprite2.setTextureRect(sf::IntRect(20,0,20,20));
            snake.Move(direction);
        }
        if(direction == Down)
        {
            snakeSprite.setTextureRect(sf::IntRect(80,0,40,40));
            snakeSprite2.setTextureRect(sf::IntRect(0,20,20,20));
            snake.Move(direction);
        }
        if(direction == Up)
        {
            snakeSprite.setTextureRect(sf::IntRect(0,0,40,40));
            snakeSprite2.setTextureRect(sf::IntRect(0,0,20,20));
            snake.Move(direction);
        }
        
        //Movement for SnakeP2
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction1 = Left;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction1 = Right;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction1 = Down;
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction1 = Up;
        }
        if(direction1 == Left)
        {
            snake1Sprite.setTextureRect(sf::IntRect(120,0,40,40));
            snake1Sprite2.setTextureRect(sf::IntRect(20,20,20,20));
            snake1.Move1(direction1);
        }
        if(direction1 == Right)
        {
            snake1Sprite.setTextureRect(sf::IntRect(40,0,40,40));
            snake1Sprite2.setTextureRect(sf::IntRect(20,0,20,20));
            snake1.Move1(direction1);
        }
        if(direction1 == Down)
        {
            snake1Sprite.setTextureRect(sf::IntRect(80,0,40,40));
            snake1Sprite2.setTextureRect(sf::IntRect(0,20,20,20));
            snake1.Move1(direction1);
        }
        if(direction1 == Up)
        {
            snake1Sprite.setTextureRect(sf::IntRect(0,0,40,40));
            snake1Sprite2.setTextureRect(sf::IntRect(0,0,20,20));
            snake1.Move1(direction1);
            
        }
        
        
        //apple position
        int x;
        int y;
        sf::Vector2f direction(x, y);
        sf::Vector2f direction1(x, y);
        sf::Vector2f snakeP(snake.getX(),snake.getY());
        sf::Vector2f snakeP1(snake1.getX1(),snake1.getY1());
        const auto applePos = appleSprite.getPosition();
        const auto applePos1 = apple1Sprite.getPosition();
        const auto applePos2 = appleP1Sprite.getPosition();
        const auto applePos3 = appleP2Sprite.getPosition();
        const auto snakePos = snakeP;
        const auto snakePos1 = snakeP1;
        
        int nx = 0;
        int ny = 0;

        int array1[40];
        int array2[28];
        
        for(int i = 0; i < 40; i++){
            array1[i] = nx;
            nx += 25;
        }
        for(int i = 0; i < 28; i++){
            array2[i] = ny;
            ny += 25;
        }
        //SnakeP1 eat food
        if(applePos == snakePos){
            int RandIndex1 = rand() % 40;
            int RandIndex2 = rand() % 28;
            direction.x = array1[RandIndex1];
            direction.y = array2[RandIndex2];
            appleSprite.setPosition(direction.x,direction.y);
            snake.grow();
            //ScoreText
            snakeP1Sprite.setColor(sf::Color::White);
            scoreF.setColor(sf::Color::Black);
            Score += 1;
            convert << (int)Score;
            finalScore = ": " + convert.str();
            convert.str("");
        }
        
        if(applePos1 == snakePos){
            int RandIndex3 = rand() % 40;
            int RandIndex4 = rand() % 28;
            direction1.x = array1[RandIndex3];
            direction1.y = array2[RandIndex4];
            apple1Sprite.setPosition(direction1.x, direction1.y);
            snake.grow();
            //ScoreText
            snakeP1Sprite.setColor(sf::Color::White);
            scoreF.setColor(sf::Color::Black);
            Score += 1;
            convert << (int)Score;
            finalScore = ": " + convert.str();
            convert.str("");
            
        }
        if (snakePos == applePos2) {
            int RandIndex3 = rand() % 40;
            int RandIndex4 = rand() % 28;
            direction1.x = array1[RandIndex3];
            direction1.y = array2[RandIndex4];
            appleP1Sprite.setPosition(direction1.x, direction1.y);
            snake.grow();
            snake.grow();
            //ScoreText
            snakeP1Sprite.setColor(sf::Color::White);
            scoreF.setColor(sf::Color::Black);
            Score += 2;
            convert << (int)Score;
            finalScore = ": " + convert.str();
            convert.str("");
        }
        if (snakePos == applePos3) {
            int RandIndex1 = rand() % 40;
            int RandIndex2 = rand() % 28;
            direction.x = array1[RandIndex1];
            direction.y = array2[RandIndex2];
            appleP2Sprite.setPosition(direction.x,direction.y);
            snake.grow();
            //ScoreText
            snakeP1Sprite.setColor(sf::Color::White);
            scoreF.setColor(sf::Color::Black);
            Score -= 1;
            convert << (int)Score;
            finalScore = ": " + convert.str();
            convert.str("");
        }
        //SnakeP2 eat food
        if(applePos == snakePos1){
            int RandIndex1 = rand() % 40;
            int RandIndex2 = rand() % 28;
            direction.x = array1[RandIndex1];
            direction.y = array2[RandIndex2];
            appleSprite.setPosition(direction.x,direction.y);
            snake1.grow1();
            //ScoreText
            snakeP2Sprite.setColor(sf::Color::White);
            scoreF1.setColor(sf::Color::Black);
            Score1 += 1;
            convert1 << (int)Score1;
            finalScore1 = ": " + convert1.str();
            convert1.str("");
        }
        
        if(applePos1 == snakePos1){
            int RandIndex3 = rand() % 40;
            int RandIndex4 = rand() % 28;
            direction1.x = array1[RandIndex3];
            direction1.y = array2[RandIndex4];
            apple1Sprite.setPosition(direction1.x, direction1.y);
            snake1.grow1();
            //ScoreText
            snakeP2Sprite.setColor(sf::Color::White);
            scoreF1.setColor(sf::Color::Black);
            Score1 += 1;
            convert1 << (int)Score1;
            finalScore1 = ": " + convert1.str();
            convert1.str("");
            
        }
        
        if (snakePos1 == applePos3) {
            int RandIndex3 = rand() % 40;
            int RandIndex4 = rand() % 28;
            direction1.x = array1[RandIndex3];
            direction1.y = array2[RandIndex4];
            appleP2Sprite.setPosition(direction1.x, direction1.y);
            snake1.grow1();
            snake1.grow1();
            //ScoreText
            snakeP2Sprite.setColor(sf::Color::White);
            scoreF1.setColor(sf::Color::Black);
            Score1 += 2;
            convert1 << (int)Score1;
            finalScore1 = ": " + convert1.str();
            convert1.str("");
        }
        if (snakePos1 == applePos2) {
            int RandIndex1 = rand() % 40;
            int RandIndex2 = rand() % 28;
            direction.x = array1[RandIndex1];
            direction.y = array2[RandIndex2];
            appleP1Sprite.setPosition(direction.x,direction.y);
            snake1.grow1();
            //ScoreText
            snakeP2Sprite.setColor(sf::Color::White);
            scoreF1.setColor(sf::Color::Black);
            Score1 -= 1;
            convert1 << (int)Score1;
            finalScore1 = ": " + convert1.str();
            convert1.str("");
        }
        
        
        window.clear(sf::Color::White);
        //GameOver
        //P1
        for(unsigned int i = 1; i < (snake.getBlocks()).size(); i++)
        {
            float x = (snake.getBlocks())[i].getX();
            float y = (snake.getBlocks())[i].getY();
            sf::Vector2f direction(x, y);
            if (snakeP == direction) {
                display.gameoverP2win();
                snake.restart();
                snake1.restart1();
            }
        }
        //P2
        for(unsigned int i = 1; i < (snake1.getBlocks1()).size(); i++)
        {
            float x = (snake1.getBlocks1())[i].getX1();
            float y = (snake1.getBlocks1())[i].getY1();
            sf::Vector2f direction(x, y);
            if (snakeP1 == direction) {
                display.gameoverP1win();
                snake.restart();
                snake1.restart1();
            }
        }
        
        int snakeSize = snake.getBlocks().size();
        int snake1Size = snake1.getBlocks1().size();
        int getSize;
        
        if(snakeSize >= snake1Size)
        {
            getSize = snakeSize;
        }
        if (snake1Size >= snakeSize)
        {
            getSize = snake1Size;
        }
        
        if (crash == true) {
            for(unsigned int i = 1; i < getSize; i++)
            {
                //P1
                float x = (snake.getBlocks())[i].getX();
                float y = (snake.getBlocks())[i].getY();
                sf::Vector2f direction(x, y);
                //P2
                float x1 = (snake1.getBlocks1())[i].getX1();
                float y1 = (snake1.getBlocks1())[i].getY1();
                sf::Vector2f direction1(x1, y1);
                //Draw
                if (snakeP == snakeP1 && Score == Score1) {
                    display.gameoverDraw();
                    snake.restart();
                    snake1.restart1();
                    
                }
                //
                if (snakeP == direction1 || (snakeP == snakeP1 && Score < Score1)){
                    
                    display.gameoverP2win();
                    snake.restart();
                    snake1.restart1();
                
                }
                if (snakeP1 == direction || (snakeP1 == snakeP && Score1 < Score)) {
                   
                    display.gameoverP1win();
                    snake.restart();
                    snake1.restart1();
                    
                }
        
            }
        }
    
        //SnakeP1
        for(unsigned int i = 1; i < (snake.getBlocks()).size(); i++)
        {
            
            float x = (snake.getBlocks())[i].getX();
            float y = (snake.getBlocks())[i].getY();
            
            float x1 = (snake.getBlocks())[i-1].getX();
            float y1 = (snake.getBlocks())[i-1].getY();
           
            
            if (i == 1) {
                snakehead.loadFromFile(resourcePath() + "head.png");
                snakeSprite.setTexture(snakehead);
                snakeSprite.setScale(0.6, 0.6);
                snakeSprite.setPosition(x, y);
                window.draw(snakeSprite);
                
            }
            if (i == 2){
                snaketail.loadFromFile(resourcePath() + "tail.png");
                snakeSprite2.setTexture(snaketail);
                snakeSprite2.setPosition(x, y);
                window.draw(snakeSprite2);
            }
            if (i > 2)
            {
                snakebody.loadFromFile(resourcePath() + "body.png");
                snakeSprite1.setTexture(snakebody);
                snakeSprite1.setTextureRect(sf::IntRect(0,20,20,20));
                snakeSprite1.setPosition(x1, y1);
                window.draw(snakeSprite1);
                snaketail.loadFromFile(resourcePath() + "tail.png");
                snakeSprite2.setTexture(snaketail);
                snakeSprite2.setPosition(x, y);
                window.draw(snakeSprite2);
            }
            
         
        }
        
        //SnakeP2
        if (Player2 == true) {
            for(unsigned int i = 1; i < (snake1.getBlocks1()).size(); i++)
            {
                float x = (snake1.getBlocks1())[i].getX1();
                float y = (snake1.getBlocks1())[i].getY1();
            
                float x1 = (snake1.getBlocks1())[i-1].getX1();
                float y1 = (snake1.getBlocks1())[i-1].getY1();
            
                if (i == 1) {
                    snakehead1.loadFromFile(resourcePath() + "head1.png");
                    snake1Sprite.setTexture(snakehead1);
                    snake1Sprite.setScale(0.6, 0.6);
                    snake1Sprite.setPosition(x, y);
                    window.draw(snake1Sprite);
                }
                if (i == 2){
                    snaketail1.loadFromFile(resourcePath() + "tail1.png");
                    snake1Sprite2.setTexture(snaketail1);
                    snake1Sprite2.setPosition(x, y);
                    window.draw(snake1Sprite2);
                }
                if (i > 2)
                {
                    snakebody1.loadFromFile(resourcePath() + "body1.png");
                    snake1Sprite1.setTexture(snakebody1);
                    snake1Sprite1.setTextureRect(sf::IntRect(0,20,20,20));
                    snake1Sprite1.setPosition(x1, y1);
                    window.draw(snake1Sprite1);
                    snaketail1.loadFromFile(resourcePath() + "tail1.png");
                    snake1Sprite2.setTexture(snaketail1);
                    snake1Sprite2.setPosition(x, y);
                    window.draw(snake1Sprite2);
                }
            }
        }
        
        window.draw(lines1);
        window.draw(lines2);
        window.draw(appleSprite);
        window.draw(apple1Sprite);
        window.draw(appleP1Sprite);
        window.draw(appleP2Sprite);
        //
        window.draw(gameOverSprite);
        window.draw(text);
        window.draw(disableP2);
        window.draw(EnableCrash);
        window.draw(TimeUp);
        window.draw(snakeP1Sprite);
        window.draw(snakeP2Sprite);
        //
        window.draw(P1win);
        window.draw(P2win);
        window.draw(Draw);
        //
        scoreF.setString(finalScore);
        window.draw(scoreF);
        scoreF1.setString(finalScore1);
        window.draw(scoreF1);
        //
        Time.setString(Timer);
        window.draw(Time);
        //
        window.display();
    }
    return 0;
}


