#include "Board.hpp"
#include <iostream>

Board::Board (int rows, int cols, int tileSize, std::vector<sf::Sprite>& sprites)
    : rows(rows), cols(cols), tileSize(tileSize), sprites(sprites) {
    // Initialize the grid with empty tiles
    grid.resize(rows, std::vector<Tile>(cols, Tile(TileType::Empty, sprites[0])));
    // Set the size of each tile
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j].getSprite().setPosition(j * tileSize, i * tileSize);
        }
    }
}
void Board::setTile (int row, int col, TileType type) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        grid[row][col].setType(type);
    } else {
        std::cerr << "Invalid tile position: (" << row << ", " << col << ")" << std::endl;
    }
}
Tile Board::getTile (int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return grid[row][col];
    } else {
        std::cerr << "Invalid tile position: (" << row << ", " << col << ")" << std::endl;
        return Tile(TileType::Empty, sf::Sprite());
    }
}
void Board::draw (sf::RenderWindow& window) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            window.draw(grid[i][j].getSprite());
        }
    }
}
void Board::setTileType (int row, int col, TileType type) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        grid[row][col].setType(type);
    } else {
        std::cerr << "Invalid tile position: (" << row << ", " << col << ")" << std::endl;
    }
}
void Board::setTileSprite (int row, int col, const sf::Sprite& sprite) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        grid[row][col].setSprite(sprite);
    } else {
        std::cerr << "Invalid tile position: (" << row << ", " << col << ")" << std::endl;
    }
}
void Board::generateRandomBoard () {
    // Fill the board with random tiles
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Randomly select a tile type
            int randomType = rand() % 3; // Assuming 3 types of tiles
            TileType type = static_cast<TileType>(randomType);
            grid[i][j].setType(type);
            grid[i][j].setSprite(this->sprites[(randomType)]); // Set the sprite for the tile
        }
    
        // TileType type = static_cast<TileType>(rand() % 3); // Randomly select a tile type
        // grid [row][col].setType(type);
    }
}