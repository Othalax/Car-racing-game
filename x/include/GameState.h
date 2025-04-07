#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <State.h>


class GameState : public State
{
    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        void update(const float& dt);
        void render(sf::RenderTarget& target);

    protected:

        Car* player1;
        Car* player2;

    private:
};

#endif // GAMESTATE_H
