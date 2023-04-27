#include "GamePlay.hpp"

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
        m_context->m_assets->AddTexture(FOOD, "utils/textures/heart.jpg");
        m_context->m_assets->AddTexture(WALL, "utils/textures/wall.png", true);
        m_context->m_assets->AddTexture(SNAKE, "utils/textures/snake.jpg");
        
        //setting them on the sprite
        m_grass.setTexture(m_context->m_assets->GetTexture(GRASS));
        m_grass.setTextureRect(m_context->m_window->getviewport(m_context->m_window->getDefaultview()));
        
}
void GamePlay:: ProcessInput()
{
        
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