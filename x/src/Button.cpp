#include "Button.h"

Button::Button(std::string message, sf::Color defaultColor, sf::Color hoverColor, sf::Color pressedColor)
{
    if (!this->font->openFromFile("textures/fonts/NicoPaint-Monospaced.ttf")) {
        std::cout << "Error loading font\n";
    }

    this->font = new sf::Font("textures/fonts/NicoPaint-Monospaced.ttf");

}

Button::~Button()
{
    //dtor
}

void Button::update(const sf::Vector2f mousePos){

}

void Button::render(sf::RenderTarget* target){

}
