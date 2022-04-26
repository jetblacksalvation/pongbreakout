#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
class square {
public:             // Access specifier
    int x ;  
    int y ;          // Attribute (int variable)
    float dial ;
    float f ;
    float ydil;
    float frmOrigin = true;
    sf::VertexArray linesCenter;
    sf::VertexArray linesLeft;
    std::string name;


    square(int xpos, int ypos, float dialation, float fdis, bool origi) {
        x = xpos;
        y = ypos;
        dial = dialation;
        f = fdis;
        frmOrigin = origi;



        ydil = sqrt(dial * pow(f, 2) - pow(f, 2));

        linesCenter.setPrimitiveType(sf::PrimitiveType::Quads);

        linesCenter.append(sf::Vertex(sf::Vector2f(x - f, y - ydil / 2), sf::Color::White));
        linesCenter.append(sf::Vertex(sf::Vector2f(x + f, y - ydil / 2), sf::Color::White));
        linesCenter.append(sf::Vertex(sf::Vector2f(x + f, y + ydil / 2), sf::Color::White));
        linesCenter.append(sf::Vertex(sf::Vector2f(x - f, y + ydil / 2), sf::Color::White));

        linesLeft.setPrimitiveType(sf::PrimitiveType::Quads);

        linesLeft.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
        linesLeft.append(sf::Vertex(sf::Vector2f(x + f, y), sf::Color::White));
        linesLeft.append(sf::Vertex(sf::Vector2f(x + f, y + ydil), sf::Color::White));
        linesLeft.append(sf::Vertex(sf::Vector2f(x, y + ydil), sf::Color::White));
    }
    void update() {
        if (frmOrigin == true) {
            linesCenter[0].position = sf::Vector2f(x - f / 2, y - ydil / 2);
            linesCenter[1].position = sf::Vector2f(x + f / 2, y - ydil / 2);
            linesCenter[2].position = sf::Vector2f(x + f / 2, y + ydil / 2);
            linesCenter[3].position = sf::Vector2f(x - f / 2, y + ydil / 2);
        }
        else {

            linesLeft[0].position = sf::Vector2f(x, y), sf::Color::White;
            linesLeft[1].position = sf::Vector2f(x + f, y), sf::Color::White;
            linesLeft[2].position = sf::Vector2f(x + f, y + ydil), sf::Color::White;
            linesLeft[3].position = sf::Vector2f(x, y + ydil), sf::Color::White;
        }

    }
    void add(int xs, int ys) {
        x += xs;
        y += ys;

    }
    void setorigin(int xs, int ys) {
        x = xs;
        y = ys;
    }
    void draw(sf::RenderWindow& wind) {
        if (frmOrigin == true) {
            wind.draw(linesCenter);
        }
        else {
            wind.draw(linesLeft);
        }

    }
    bool shapecolide() {

    }

};