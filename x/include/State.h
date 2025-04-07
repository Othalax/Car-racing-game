#ifndef STATE_H
#define STATE_H


#include <Car.h>

class State {
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool ifEnd;
    //Car* player = new Car("textures/pinkcar.png",200.f, 200.f, 0.f, 100.f, 30.f, 200.f);

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getEnd() const;
    void ending();
    void endState();
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);

};

#endif // STATE_H
