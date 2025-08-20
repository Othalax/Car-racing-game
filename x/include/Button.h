#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

enum buttonStates {idle = 0, hover, pressed, change};

class Button
{
    public:
        Button(sf::RenderWindow* window, float x, float y, float width, float height, std::string message, sf::Color defaultColor, sf::Color hoverColor, sf::Color pressedColor);
        virtual ~Button();

        bool isPressed();
        void update(const sf::Vector2f mousePos);
        void render(sf::RenderTarget& target);

    protected:

    private:
        sf::RenderWindow* window;
        short unsigned state;
        bool isStatePressed;

        sf::RectangleShape button;
        sf::Font font;
        sf::Text* text;

        sf::Color defaultColor;
        sf::Color pressedColor;
        sf::Color hoverColor;
};

#endif // BUTTON_H
