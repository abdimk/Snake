#include "MainMenu.hpp"
#include <SFML/Window/Event.hpp>


MainMenu::MainMenu(std::shared_ptr<Context> &context)
    :m_context(context),m_isPlayButtonSelected(true),m_isPlayButtonPressed(false),
     m_isEXitButtonPressed(false),m_isExitButtonSelected(false)
{

}

MainMenu::~MainMenu()
{

}


void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "utils/fonts/Pacifico-Regular.ttf");

    // Title
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString("Sanke Game");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                         m_gameTitle.getLocalBounds().height / 2);

    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 150.f);

    // Play Button
    m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                         m_playButton.getLocalBounds().height / 2);

    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 25.f);
    m_playButton.setCharacterSize(20);


    // Exit
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                         m_exitButton.getLocalBounds().height / 2);

    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 25.f);
    m_exitButton.setCharacterSize(20);



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
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    
    m_context->m_window->display();
}