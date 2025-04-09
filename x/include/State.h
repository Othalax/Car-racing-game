#ifndef STATE_H
#define STATE_H


#include <Car.h>

class State {
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool ifEnd;
    std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

public:
    State(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys);
    virtual ~State();

    const bool& getEnd() const;
    void ending();
    void endState();
    void updateMousePos();
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);

};

#endif // STATE_H
