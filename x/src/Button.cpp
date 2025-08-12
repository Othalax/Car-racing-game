#include "Button.h"

Button::Button(float x, float y, float width, float height, std::string message, sf::Color defaultColor, sf::Color hoverColor, sf::Color pressedColor)
{
    this->state = idle;

    if (!this->font->openFromFile("textures/fonts/NicoPaint-Monospaced.ttf")) {
        std::cout << "Error loading font\n";
    }

    this->font = new sf::Font("textures/fonts/NicoPaint-Monospaced.ttf");
    this->button.setPosition(sf::Vector2f(x, y));
    this->button.setSize(sf::Vector2f(width, height));
    this->text->setFont(*this->font);
    this->text->setString(message);
    this->text->setFillColor(sf::Color::White);
    this->text->setCharacterSize(12);
    this->text->setPosition( sf::Vector2f(
        this->button.getPosition().x / 2.f - this->text->getGlobalBounds().getCenter().x,
        this->button.getPosition().y / 2.f - this->text->getGlobalBounds().getCenter().y
    ));

    this->defaultColor = defaultColor;
    this->hoverColor = hoverColor;
    this->pressedColor = pressedColor;

    this->button.setFillColor(this->defaultColor);

}

Button::~Button()
{
    //dtor
}

const bool Button::isPressed()
{
    if(this->state == pressed)
    {
        return true;
    }
    return false;
}

void Button::update(const sf::Vector2f mousePos){
    this->state = idle;
    if (this->button.getGlobalBounds().contains(mousePos))
    {
        this->state = hover;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            this->state = pressed;
        }
    }

    switch(this->state)
    {
    case idle:
        this->button.setFillColor(this->defaultColor);
        break;

    case hover:
        this->button.setFillColor(this->hoverColor);
        break;

    case pressed:
        this->button.setFillColor(this->pressedColor);
        break;

    default:
        this->button.setFillColor(sf::Color::Yellow);
        break;
    }
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->button);
}
