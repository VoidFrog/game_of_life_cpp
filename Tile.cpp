//
// Created by OEM on 10.06.2024.
//

#include "Tile.h"

void Tile::render(sf::RenderWindow &window) {
    if (color == 1) rect.setFillColor(sf::Color::Black);
    else rect.setFillColor(sf::Color::White);
    window.draw(rect);
}
