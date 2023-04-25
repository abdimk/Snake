#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine ::State
{

private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;


public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();


    virtual void Init() override;
    virtual void ProcessInput() override;
    virtual void Update(sf::Time deltaTime) override; // the game runs on time same fps
    virtual void Draw() override;

};