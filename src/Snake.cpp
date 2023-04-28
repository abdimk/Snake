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
    m_tail->setPosition(m_head->getPosition() + direction);
    m_head = m_tail;
    ++m_tail;

    if(m_tail == m_body.end())
    {
        m_tail = m_body.begin();
    }

}
bool Snake::IsOn(const sf::Sprite &other) const
{
    // implementation of ison class 
    return other.getGlobalBounds().intersects(m_head->getGlobalBounds());

    /*
    to detect colusion we just have to detect 
    if the head of snake is on the other sprite
    
    */

}
void Snake::Grow(const sf::Vector2f &direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*(m_body.begin()->getTexture()));
    newPiece.setPosition(m_head->getPosition() + direction);

    m_head = m_body.insert(++m_head, newPiece);

}
void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
    for(auto& piece : m_body)
    {
        target.draw(piece);
    }

}