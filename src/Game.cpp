#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Event.hpp>

Game::Game() 
{
    m_context -> m_window->create(sf::VideoMode(400, 400), "Snake!", sf::style::close);


}

Game::~Game() {

}

void Game::Run()
{
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);

    while (m_context->m_window->isOpen())
    {
        sf::Event event;
        while (m_context->m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_context->m_window->close();
        }

        m_context->m_window->clear();
        m_context->m_window->draw(shape);
        m_context->m_window->display();
    }


}