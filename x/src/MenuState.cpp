#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys)
    : State(window, supportedKeys)
{
    this->wiwiwi.setFillColor(sf::Color(100, 100, 100));
    this->wiwiwi.setPosition({100.0f, 100.0f});
    this->wiwiwi.setSize({200.0f, 200.0f});
}

MenuState::~MenuState()
{
    //dtor
}

void MenuState::update(const float& dt){
    updateMousePos();
}

void MenuState::render(sf::RenderTarget& target){
    target.draw(this->wiwiwi);

}
