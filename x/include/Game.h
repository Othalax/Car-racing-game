#ifndef GAME_H
#define GAME_H

#include <State.h>

class Game {
private:
    std::unique_ptr<sf::RenderWindow> window;

    sf::Clock dtClock;
    float dt;

    std::vector<std::unique_ptr<State>> states;

    void initWindow();
    void initStates();

public:
    Game();
    virtual ~Game();

    void endApp();
    void updateDT();
    void updateEvents();
    void update();
    void render();
    void run();
};

#endif // GAME_H
