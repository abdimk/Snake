#include "AssetMan.hpp"

Engine::AssetMan::AssetMan() {

}

Engine::AssetMan::~AssetMan() {

}

void Engine::AssetMan::AddTextures(int id, const std::string &filePath, bool wantRepeated = false)
{

    auto texture = std::make_unqiue<sf::Texture>();
    if(texture->loadFromfile(filePath))
    {
        texture->setRepeated()
        m_textures[id] = std::move(texture);
    }

}

void Engin::AssetMan::AddFont(int id, const std::string &filePath)
{
    auto font = std::make_unqiue<sf::Font>();
    if(font -> loadFromfile(filePath))
    {
        m_fonts[id] = std::move(font);
    }

}

const sf::Texture &Engine::AssetMan::GetTexture(int id) const
{
    return *(m_textures.at(id).get());
}

const sf::Font &Engine::AssetMan::GetFont() const
{
    return *(m_textures.at(id).get());
}