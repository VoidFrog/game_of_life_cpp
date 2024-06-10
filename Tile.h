//
// Created by OEM on 10.06.2024.
//

#ifndef GAME_OF_LIFE_TILE_H
#define GAME_OF_LIFE_TILE_H

#include <SFML/Graphics.hpp>

class Tile {
    float width, height, x, y;
    sf::RectangleShape rect;

public:
    Tile(float w, float h, float x, float y, size_t row, size_t col, unsigned short color): width(w), height(h), x(x), y(y), row(row), col(col), color(color) { rect.setSize(sf::Vector2f(w, h)); rect.setPosition(x, y); }
    void render(sf::RenderWindow&);

    size_t row, col;
    unsigned short color;
};


#endif //GAME_OF_LIFE_TILE_H
