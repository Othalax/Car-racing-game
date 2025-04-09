#include "State.h"

State::State(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys)
{
    this->window = window;
    this->ifEnd = false;
    this->supportedKeys = supportedKeys;
}

State::~State()
{
    //dtor
}

const bool& State::getEnd() const{
    return this->ifEnd;
}

void State::ending(){

}

void State::endState(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        this->ifEnd = true;
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


