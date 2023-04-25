#include "MainMenu.hpp"
#include <SFML/Window/Event.hpp>


MainMenu::MainMenu(std::shared_ptr<Context> &context)
    :m_context(context)
{

}

MainMenu::~MainMenu()
{

}


void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "utils/fonts/Pacifico-Regular.ttf");
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString("Sanke Game");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                         m_gameTitle.getLocalBounds().height / 2);

    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2);

}
void MainMenu::ProcessInput() 
{

    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();
    }


}
void MainMenu::Update(sf::Time deltaTime)
{

}
void MainMenu::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->display();
}