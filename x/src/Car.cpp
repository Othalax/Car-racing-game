#include "Car.h"

Car::Car(float x, float y, float angle, float length, float max_steering, float max_acceleration)
{
    position = sf::Vector2f(x, y);
    velocity = sf::Vector2f(0.0f, 0.0f);
    this->angle = angle;
    this->length = length;
    this->max_acceleration = max_acceleration;
    this->max_steering = max_steering;
    max_velocity = 100.0f;
    brake_deceleration = 20.0f;
    free_deceleration = 40.0f;
    acceleration = 0.0f;
    steering = 0.0f;

    if (!texture.loadFromFile("textures/pinkcar.png", false, sf::IntRect({10, 10}, {32, 32})))
    {
        std::cout<<"error\n";
    }

    this->texture = sf::Texture("textures/pinkcar.png");
    this->car = new sf::Sprite(texture);
    this->car->setOrigin({100.f, 50.f});
    this->car->setPosition({x, y});
    this->car->rotate(sf::degrees(90));
}

Car::~Car()
{
    delete this->car;
}

void Car::ride(const float& dt, float direction){

}

void Car::veer(const float& dt, float direction){

}

void Car::update(const float& dt) {

    velocity.x += acceleration * dt;
    velocity.x = std::clamp(velocity.x, -max_velocity, max_velocity);

    float angular_velocity = 0.0f;
    if (std::abs(steering) > 0.01f) {
        float turning_radius = length / std::tan(steering * M_PI / 180.0f);
        angular_velocity = velocity.x / turning_radius;
    }

    position.x += velocity.x * std::cos(angle * M_PI / 180.0f) * dt;
    position.y += velocity.x * std::sin(angle * M_PI / 180.0f) * dt;
    angle += angular_velocity * dt * (180.0f / M_PI);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        acceleration = std::min(acceleration + 50.0f * dt, max_acceleration);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        acceleration = std::max(acceleration - 50.0f * dt, -max_acceleration);
    } else {
        if (std::abs(velocity.x) > dt * free_deceleration)
            acceleration = -std::copysign(free_deceleration, velocity.x);
        else
            acceleration = -velocity.x / dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        acceleration = -std::copysign(brake_deceleration, velocity.x);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        steering = std::max(steering - 50 * dt, -max_steering);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        steering = std::min(steering + 50 * dt, max_steering);
    } else {
        steering *= 0.8f;
    }

    this->car->setPosition(position);
    this->car->setRotation(sf::degrees(angle));
}

void Car::render(sf::RenderTarget& target){
    target.draw(*this->car);
}
