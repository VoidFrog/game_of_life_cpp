//
// Created by OEM on 10.06.2024.
//

#include <iostream>
#include "GameOfLife.h"

GameOfLife::GameOfLife(size_t w_cells, size_t h_cells, size_t tick_delay): window(sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Conways game of life")),
                                                                           w_cells(w_cells),
                                                                           h_cells(h_cells),
                                                                           tick_delay(tick_delay){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

    auto width = float(window.getSize().x);
    auto height = float(window.getSize().y);

    for (size_t row=0; row<h_cells; row++){
        for (size_t col=0; col<w_cells; col++){
            float t_h = height/h_cells;
            float t_w = width/w_cells;
            float x = float(col)*t_w;
            float y = float(row)*t_h;

            std::vector<Tile> new_vector;
            tiles.push_back(new_vector);
            tiles[row].push_back(Tile(t_h, t_w, x, y, row, col, dist(rng)));
        }
    }
}

void GameOfLife::render() {
    window.clear();
    for (auto &row : tiles){
        for (auto &tile : row){
            tile.render(window);
        }
    }
    window.display();
}

size_t GameOfLife::neighbours(size_t row, size_t col) {
    size_t count = 0;
    constexpr int offsets[8][2] = {
            {-1, 0},   //up
            {1, 0},    //down
            {0, -1},   //left
            {0, 1},    //right
            {-1, -1},  //up-left
            {-1, 1},   //up-right
            {1, -1},   //down-left
            {1, 1},    //down-right
    };

//    std::cout << "-------------tile[" << row << "][" << col << "]------------\n";
    for (auto &offset : offsets){
        int rw = row + offset[0];
        int cl = col + offset[1];


        if (rw >= 0 and cl >= 0 and rw < h_cells and cl < w_cells){
            count += tiles[rw][cl].color;
//            std::cout << "row: " << rw << " | col: " << cl << " | color: " << tiles[rw][cl].color <<  "\n";
        }
    }

//    std::cout << "-------------["<< count <<"]------------\n";
    return count;
}

void GameOfLife::tick(size_t &ticks) {
//Any live cell with fewer than two live neighbors dies, as if by underpopulation.
//Any live cell with two or three live neighbors lives on to the next generation.
//Any live cell with more than three live neighbors dies, as if by overpopulation.
//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
    if(ticks < tick_delay) return;
    else ticks=0;

    unsigned short colors[h_cells][w_cells];
    for (auto &row : tiles){
        for (auto &tile : row){
            size_t count = neighbours(tile.row, tile.col);

            if (tile.color == 1){
                if (count < 2 or count > 3) colors[tile.row][tile.col] = 0;
                else colors[tile.row][tile.col] = 1;
            }
            else if (count == 3) colors[tile.row][tile.col] = 1;
            else colors[tile.row][tile.col] = 0;
        }
    }

    for (size_t i=0; i < h_cells; i++){
        for (size_t j=0; j < w_cells; j++){
            tiles[i][j].color = colors[i][j];
//            std::cout << colors[i][j];
        }
    }

}