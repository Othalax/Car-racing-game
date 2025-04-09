#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <State.h>

class MenuState
    : public State
{
    public:
        MenuState(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys);
        virtual ~MenuState();

        void update(const float& dt);
        void render(sf::RenderTarget& target);

    protected:
        sf::RectangleShape wiwiwi;

    private:
};

#endif // MENUSTATE_H
