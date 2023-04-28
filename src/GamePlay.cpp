#include "GamePlay.hpp"
#include <SFML/Window/Event.hpp>

#include <stdlib.h>
#include <time.h>


GamePlay::GamePlay(std::shared_ptr<Context> &context)
        : m_context(context), 
        m_snakeDirection({16.f, 0.f,}), 
        m_elapsedTime(sf::Time::Zero)
{
        srand(time(nullptr));

}

GamePlay::~GamePlay()
{

}

void GamePlay:: Init()
{

        // loading the textures in to the sprite 
        m_context->m_assets->AddTexture(GRASS, "utils/textures/grass.png", true);
        m_context->m_assets->AddTexture(FOOD, "utils/textures/food.png", false);
        m_context->m_assets->AddTexture(WALL, "utils/textures/wall.png", true);
        m_context->m_assets->AddTexture(SNAKE, "utils/textures/snake.png", false);
        
        //setting them on the sprite
        m_grass.setTexture(m_context->m_assets->GetTexture(GRASS));
        m_grass.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
        

        for(auto& wall : m_walls)
        {
                wall.setTexture(m_context->m_assets->GetTexture(WALL));
        }


        //set baundary for the walls
        m_walls[0].setTextureRect({0, 0, m_context->m_window->getSize().x, 16});
        m_walls[1].setTextureRect({0, 0, m_context->m_window->getSize().x, 16});
        m_walls[1].setPosition(0, m_context->m_window->getSize().y - 16);



        m_walls[2].setTextureRect({0, 0, 16, m_context->m_window->getSize().y});
        m_walls[3].setTextureRect({0, 0, 16, m_context->m_window->getSize().y});
        m_walls[3].setPosition(m_context->m_window->getSize().x - 16, 0);



        // Display the food
        m_food.setTexture(m_context->m_assets->GetTexture(FOOD));
        m_food.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2);


        // initalize the m_snake class of the init methoid
        m_snake.Init(m_context->m_assets->GetTexture(SNAKE));
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
                else if(event.type == sf::Event::KeyPressed)
                {
                        switch (event.key.code)
                        {
                                case sf::Keyboard::Up :
                                        m_snakeDirection = {0.f, -16.f};
                                        break;
                                case sf::Keyboard::Down :
                                        m_snakeDirection = {0.f, 16.f};
                                        break;
                                case sf::Keyboard::Left :
                                        m_snakeDirection = {-16.f, 0.f};
                                        break;
                                case sf::Keyboard::Right :
                                        m_snakeDirection = {16.f, 0.f};
                                        break;                                                                                                        
                                
                                default:
                                        break;
                        }

                }
        }
}
void GamePlay:: Update(sf::Time deltaTime)
{
        m_elapsedTime += deltaTime;
        if(m_elapsedTime.asSeconds() > 0.1)
        {

                bool isOnWall = false;

                for(auto& wall : m_walls)
                {
                        if(m_snake.IsOn(wall))
                        {
                                // Add Game over right here

                                break;
                        }
                }
                
                if(m_snake.IsOn(m_food))
                {
                        m_snake.Grow(m_snakeDirection);
                }else
                {
                        m_snake.Move(m_snakeDirection);

                }
                m_elapsedTime = sf::Time::Zero;
        }
        
        
}
void GamePlay:: Draw()
{
        m_context->m_window->clear();
        m_context->m_window->draw(m_grass);


        // darw the four walls(each wall on the render window)
        for(auto& wall : m_walls)
        {
                m_context->m_window->draw(wall);
        }
        m_context->m_window->draw(m_food);
        m_context->m_window->draw(m_snake);
        m_context->m_window->display();
}

void GamePlay:: Pause()
{
        
};
void GamePlay:: Start()
{
        
};