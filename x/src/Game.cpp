#include "Game.h"


Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    //dtor
}

void Game::initWindow(){
    std::ifstream ifs("config/window.ini");
    std::string title = "x";
    sf::VideoMode windowBounds({800, 600});
    int framerate = 120;
    bool verticalSync = false;

    if(ifs.is_open()){
        ifs >> title;
        ifs >> windowBounds.size.x >> windowBounds.size.y;
        ifs >> framerate;
        ifs >> verticalSync;
    }
    ifs.close();

    window.reset();
    window = std::make_unique<sf::RenderWindow>(windowBounds, title);
    window->setFramerateLimit(framerate);
    window->setVerticalSyncEnabled(verticalSync);
}

void Game::endApp(){
    std::cout<<"GameEndApp"<<std::endl;
}

void Game::initStates(){
    states.push_back(std::make_unique<State>(this->window.get()));

}

void Game::updateDT(){
    this->dt=this->dtClock.restart().asSeconds();
}

void Game::updateEvents(){
    while (const std::optional event = this->window->pollEvent()) {
        if (event->is<sf::Event::Closed>())
            this->window->close();
    }
}

void Game::update(){
    this->updateEvents();

    if(!this->states.empty()){
        this->states[0]->update(this->dt);

        if(this->states[0]->getEnd()){
            this->states[0]->ending();
            this->states.erase(states.begin());
        }
    }
    else{
        this->endApp();
        this->window->close();
    }
}

void Game::render(){
    this->window->clear();

    if(!this->states.empty()){
        this->states[0]->render(*this->window);
    }

    this->window->display();
}

void Game::run(){
    while (this->window->isOpen())
    {
        this->updateDT();
        this->update();
        this->render();
    }
}
