#include "Tile.hpp"
#include <vector>
// #include <SFML/Graphics.hpp>

class Board {
private:
    std::vector<std::vector<Tile>> grid; // 2D vector to represent the board
    int rows; // Number of rows in the board
    int cols; // Number of columns in the board
    int tileSize; // Size of each tile
    std::vector<sf::Sprite>& sprites; // Vector to hold the tile sprites

public:
    Board(int rows, int cols, int tileSize, std::vector<sf::Sprite>& sprites);
    void setTile(int row, int col, TileType type);
    Tile getTile(int row, int col) const;
    void draw(sf::RenderWindow& window);
    void setTileType(int row, int col, TileType type);
    void setTileSprite(int row, int col, const sf::Sprite& sprite);
    void generateRandomBoard();

    std::vector<std::vector<Tile>>& getGrid() { return grid; }
    
    //get sprites
    std::vector<sf::Sprite>& getSprites() { return sprites; }

};