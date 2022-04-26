#include <iostream>
#include<SFML\Graphics.hpp>
#include<math.h>
#include<vector>
#include <ctime>
#include "squares.h"


bool keys[] = { false, false };
enum DIRECTIONS {RIGHT,LEFT}; //left is 0, right is 1, up is 2, down is 3

int vx, vy2,vx2;
bool kill = false;
int score = 0;

int ballx = 4;
int bally = 4;
std::vector<square*> paddles;

int main()
{
    srand(time(NULL));
    square player(400, 700, 1.0125, 200, true);
    square ball(400, 650, 2, 20, true);
    for (int x = 0; x <= 10; x++) {
        paddles.push_back(new square(0,0,1.05,100,true));//no DEFAULT constructor, sorta meant for new, otherwise manually do it

        paddles[x]->setorigin(110 * x, 100);

        paddles[x]->update();
    }
    int rando;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Platformer");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;
        }
        if (keys[RIGHT] == true) {

            vx = -4;
        }

        else if (keys[LEFT] == true) {

            vx = 4;
        }
        else vx = 0;
        player.x += vx;

        //why no work??-fixed thanks critical hex:)
        if (ball.x + ball.f/2 >= 800 || ball.x - ball.f/2 <= 0) {
            ballx *= -1;
        }
        if (ball.y + ball.ydil/2 >= 800 || ball.y - ball.ydil/2 <= 0) {
            bally *= -1;
        }
            //sus collision disgusting collision code, copy and paste it for brick class
        if (player.x + player.f/2 >= ball.x + ball.f/2 and
            player.x - player.f/2 <=ball.x-ball.f/2 and
            player.y +  player.ydil >= ball.y + ball.ydil and
            player.y - player.ydil <= ball.y - ball.ydil
            ) {
            std::cout << "bounce\n";
            ballx *= -1;
            bally *= -1;
            rando = rand() % 1;
            if (rando == false) {
                ballx *= -1;
            }
            else {
                ballx * 1;
            }
        }
        for (int x = 0; x <= 10; x++) {

            paddles[x]->draw(window);
            if (paddles[x]->x + paddles[x]->f >= ball.x + ball.f / 2 and
                paddles[x]->x - paddles[x]->f <= ball.x - ball.f / 2 and
                paddles[x]->y + paddles[x]->ydil >= ball.y + ball.ydil and
                paddles[x]->y - paddles[x]->ydil <= ball.y - ball.ydil) {
                std::cout << "bounce\n";
                ballx *= -1;
                bally *= -1;
                paddles[x]->x = -100;//basically dele
                paddles[x]->y = 0;
                paddles[x]->update();
                score += 1;
            }
            
        }
        ball.x += ballx;
        ball.y += bally;
        ball.update();
        ball.draw(window);
        player.update();
        player.draw(window);
        window.display();
        window.clear();
        if (score >= 4) {
            std::cout << "you win \n";
            return 0;
        }
    }
}
