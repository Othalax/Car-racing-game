#include "SettingState.h"

SettingState::SettingState(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys, std::vector<std::unique_ptr<State>>* states)
    : State(window, supportedKeys, states)
{
    //ctor
}

SettingState::~SettingState()
{
    //dtor
}

void SettingState::update(const float& dt){

}

void SettingState::render(sf::RenderTarget& target){

}
