#pragma once
#include <SFML/System/Time.hpp>

namespace Engine
{
    // simple state game engine 

    class State
    {

    public:
        Sate(){};
        virtual ~State(){};
        virtual void Init() = 0;
        virtual void ProcessInput() = 0;
        virtual void Update(sf::Time deltaTime) = 0; // the game runs on time same fps
        virtual void Draw() = 0;

        virtual void Pause(){};
        virtual void Start(){};
        

    };

}