#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
#include <map>
#include <memory>

class Car {
private:
    sf::Texture texture;
    sf::Sprite* car;
    float alfa;

public:
    Car();
    virtual ~Car();

    void ride(const float& dt, float direction);
    void veer(const float& dt, float direction);
    void update(const float& dt);
    void render(sf::RenderTarget& target);
};

#endif // CAR_H
