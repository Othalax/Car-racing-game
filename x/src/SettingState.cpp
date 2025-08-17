#include "SettingState.h"

SettingState::SettingState(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys, std::vector<std::unique_ptr<State>>* states)
    : State(window, supportedKeys, states)
{
    this->buttons["menu"] = std::make_unique<Button>(150.f, 150.f, 150.f, 50.f, "Main menu", sf::Color::Magenta, sf::Color::Blue, sf::Color::Cyan);
}

SettingState::~SettingState()
{
    //dtor
}

void SettingState::updateButtons()
{
    if (this->buttons["menu"]->isPressed())
    {
        this->states->push_back(std::make_unique<MenuState>(this->window, supportedKeys, states));
    }
}

void SettingState::update(const float& dt)
{
    updateMousePos();
    for(auto &itr : this->buttons)
    {
        itr.second->update(mousePosView);
    }
    updateButtons();
}

void SettingState::render(sf::RenderTarget& target)
{
    for(auto &itr : this->buttons)
    {
        itr.second->render(target);
    }
}
