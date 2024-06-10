//
// Created by OEM on 10.06.2024.
//

#ifndef GAME_OF_LIFE_GAMEOFLIFE_H
#define GAME_OF_LIFE_GAMEOFLIFE_H

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "vector"
#include "random"

class GameOfLife {
public:
    sf::RenderWindow window;
    GameOfLife(size_t, size_t, size_t);

    void render();
    void tick(size_t &);

private:
    size_t neighbours(size_t, size_t);
    std::vector<std::vector<Tile>> tiles;
    size_t w_cells, h_cells, tick_delay;
//    size_t w_cells=64, h_cells=36;

};


#endif //GAME_OF_LIFE_GAMEOFLIFE_H
