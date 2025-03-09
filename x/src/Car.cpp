#include "Car.h"

Car::Car()
{

    if (!texture.loadFromFile("textures/pinkcar.png", false, sf::IntRect({10, 10}, {32, 32})))
    {
        std::cout<<"error\n";
    }

    this->texture = sf::Texture("textures/pinkcar.png");
    this->car = new sf::Sprite(texture);
    this->car->setOrigin({100.f, 0.f});
    this->car->setPosition({200.f, 200.f});
    alfa = 0;
}

Car::~Car()
{
    delete this->car;
}

void Car::ride(const float& dt, float direction){
    //std::cout<<"CarRide\n";
    float sina = round(sin((direction+this->alfa)*3.14/180)*100.00)/100.00, cosa = round(cos((direction+this->alfa)*3.14/180)*100.00)/100.00;
    if(round(sina)==0){
        this->car->move({0.f, (-60.f/cosa)*dt});
    }
    else if(round(cosa)==0){
        this->car->move({(60.f/sina)*dt, 0.f});
    }
    else{
        this->car->move({(60.f/sina)*dt, (-60.f/cosa)*dt});
    }
}

void Car::veer(const float& dt, float direction){
    //std::cout<<alfa<<'\n';
    float degrees = round(30*dt*direction*100.00)/100.00;
    this->car->rotate(sf::degrees(degrees));
    this->alfa+=degrees;
}

void Car::update(const float& dt){
    //std::cout<<"CarUpdate\n";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->ride(dt, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->ride(dt, 180.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->veer(dt, -1.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->veer(dt, 1.f);
    }
}

void Car::render(sf::RenderTarget& target){
    target.draw(*this->car);
}
