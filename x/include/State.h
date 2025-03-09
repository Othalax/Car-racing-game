#ifndef STATE_H
#define STATE_H


#include <Car.h>

class State {
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool ifEnd;
    Car player;

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getEnd() const;
    void ending();
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget& target);

};

#endif // STATE_H
