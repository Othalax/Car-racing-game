#include "Button.h"

Button::Button(sf::RenderWindow* window, float x, float y, float width, float height, std::string message, sf::Color defaultColor, sf::Color hoverColor, sf::Color pressedColor)
{
    this->window = window;
    isStatePressed = false;

    if (!this->font.openFromFile("textures/fonts/NicoPaint-Monospaced.ttf")) {
        std::cout << "Error loading font\n";
    }

    this->button.setPosition(sf::Vector2f(x, y));
    this->button.setSize(sf::Vector2f(width, height));
    this->text = new sf::Text(this->font, message, 20);
    this->text->setFillColor(sf::Color::White);

    this->text->setPosition( sf::Vector2f(
        this->button.getPosition().x + width / 2.f - this->text->getGlobalBounds().getCenter().x,
        this->button.getPosition().y + height / 2.f - this->text->getGlobalBounds().getCenter().y
    ));

    this->defaultColor = defaultColor;
    this->hoverColor = hoverColor;
    this->pressedColor = pressedColor;

    this->button.setFillColor(this->defaultColor);

}

Button::~Button()
{

    delete this->text;
}

bool Button::isPressed()
{
    if(isStatePressed && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return true;
    }
    return false;
}

void Button::update(const sf::Vector2f mousePos){
    if (isStatePressed)
    {
        this->state = pressed;
    }
    else if (this->button.getGlobalBounds().contains(mousePos))
    {
        this->state = hover;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            this->state = pressed;
            isStatePressed = true;
        }

    }
    else
    {
        this->state = idle;
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

void Button::render(sf::RenderTarget& target)
{
    target.draw(this->button);
    target.draw(*this->text);
}
