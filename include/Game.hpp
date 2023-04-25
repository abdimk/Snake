#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetMan.hpp"
#include "StateMan.hpp"

struct Context
{
    std::unqiue_ptr<Engine::AssetMan> m_assets;
    std::unqiue_ptr<Engine::StateMan> m_states;
    std::unqiue_ptr<sf::RenderWindow> m_window;

    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan> ();
        m_states = std::make_unique<Engine::StateMan> ();
        m_window = std::make_unique<sf::RenderWindow> ();


    }
    
};
class Game {
private:
    std::shared_ptr<Context> m_context;
    const sf:Time TIME_PER_SECOND = sf::seconds(1.f/60.f);

public:
    Game();
    ~Game();

    void Run();
};