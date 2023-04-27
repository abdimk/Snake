#include "GamePlay.hpp"
#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context)
        : m_context(context)
{

}

GamePlay::~GamePlay()
{

}

void GamePlay:: Init()
{

        // loading the textures in to the sprite 
        m_context->m_assets->AddTexture(GRASS, "utils/textures/grass.png", true);
        m_context->m_assets->AddTexture(FOOD, "utils/textures/grass.png", false);
        m_context->m_assets->AddTexture(WALL, "utils/textures/grass.png", true);
        m_context->m_assets->AddTexture(SNAKE, "utils/textures/grass.png", false);
        
        //setting them on the sprite
        m_grass.setTexture(m_context->m_assets->GetTexture(GRASS));
        m_grass.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
        
}
void GamePlay:: ProcessInput()
{
        sf::Event event;
        while (m_context->m_window->pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                {
                        m_context->m_window->close();
                }
        }
}
void GamePlay:: Update(sf::Time deltaTime)
{
        
}
void GamePlay:: Draw()
{
        m_context->m_window->clear();
        m_context->m_window->draw(m_grass);
        m_context->m_window->display();
}

void GamePlay:: Pause()
{
        
};
void GamePlay:: Start()
{
        
};