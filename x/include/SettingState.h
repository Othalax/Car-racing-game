#ifndef SETTINGSTATE_H
#define SETTINGSTATE_H

#include <State.h>


class SettingState
    : public State
{
    public:
        SettingState(sf::RenderWindow* window, std::unordered_map<std::string,sf::Keyboard::Key> supportedKeys, std::vector<std::unique_ptr<State>>* states);
        virtual ~SettingState();

        void update(const float& dt);
        void render(sf::RenderTarget& target);
    protected:

    private:
};

#endif // SETTINGSTATE_H
