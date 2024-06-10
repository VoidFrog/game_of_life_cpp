#include <SFML/Graphics.hpp>
#include "GameOfLife.h"

int main()
{

    size_t ticks = 0;
    GameOfLife game(160, 90, 0);

    while (game.window.isOpen())
    {
        sf::Event event{};
        while (game.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.window.close();
        }

        game.render();
        game.tick(ticks);
        ticks += 1;
    }

    return 0;
}