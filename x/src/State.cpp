#include "State.h"

State::State(sf::RenderWindow* window)
{
    this->window = window;
    this->ifEnd = false;
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

void State::update(const float& dt){
    this->player.update(dt);
    //std::cout<<"StateUpdate"<<std::endl;
}

void State::render(sf::RenderTarget& target){
    this->player.render(*this->window);
    //std::cout<<"StateRender"<<std::endl;
}

