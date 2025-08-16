#include "State.h"

State::State(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys, std::vector<std::unique_ptr<State>>* states)
:states(states)
{
    this->window = window;
    this->supportedKeys = supportedKeys;
}

State::~State()
{
    //dtor
}

void State::ending(){

}

void State::endState(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        std::cout<<"StateEnd"<<std::endl;
    }
}

void State::updateMousePos(){
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void State::update(const float& dt){

}

void State::render(sf::RenderTarget& target){

}


