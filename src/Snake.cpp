#include "Snake.hpp"

Snake::Snake() : m_body(std::list<sf::Sprite>(4))
{
    m_head = --m_body.end();
    m_tail = m_body.begin();
}

Snake::~Snake() 
{

}

void Snake::Init(const sf::Texture &texture)
{
    float x = 16.f;
    for(auto& piece : m_body)
    {
        piece.setTexture(texture);
        piece.setPosition({x, 16.f});
        x += 16.f;
    }

}
void Snake::Move(const sf::Vector2f &direction)
{

}
bool IsOn(const sf::Sprite &other) 
{

}
void Snake::Grow(const sf::Vector2f &direction)
{

}
void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
    for(auto& piece : m_body)
    {
        target.draw(piece);
    }

}