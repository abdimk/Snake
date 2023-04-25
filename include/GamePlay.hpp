#pragma once

#include <memory>
#include <array>
#include <SFML/Graphics/Sprite.hpp>

#include "State.hpp"
#include "Game.hpp"

class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    std::Sprite m_grass;
    sf::Sprite m_food;
    std::array<sf::Sprite, 4> m_walls;

    //To do 
    // Added Snake
    
public:
    GamePlay(std::shared_ptr<Context> &context);
    ~GamePlay();
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;

    void Pause() override;
    void Start() override;
}; 



