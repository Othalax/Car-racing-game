#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys)
    : State(window, supportedKeys)
{
    this->gamestate = new Button(150.f, 150.f, 150.f, 50.f, "Start", sf::Color::Magenta, sf::Color::Blue, sf::Color::Cyan);
    this->exit = new Button(150.f, 350.f, 150.f, 50.f, "Exit", sf::Color::Magenta, sf::Color::Blue, sf::Color::Cyan);
    this->wiwiwi.setFillColor(sf::Color(100, 100, 100));
    this->wiwiwi.setPosition({100.0f, 100.0f});
    this->wiwiwi.setSize({200.0f, 200.0f});
}

MenuState::~MenuState()
{
    delete this->gamestate;
    delete this->exit;
}

void MenuState::update(const float& dt){
    updateMousePos();
    this->gamestate->update(this->mousePosView);
    this->exit->update(this->mousePosView);

}

void MenuState::render(sf::RenderTarget& target){
    target.draw(this->wiwiwi);
    this->gamestate->render(target);
    this->exit->render(target);

    if(this->exit->isPressed())
    {
        window->close();
    }

}
