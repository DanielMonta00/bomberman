#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include <iostream>
#include "Board.hpp"

// #include <filesystem>

const int TILE_SIZE = 16; // Size of each tile in pixels
const int BOARD_WIDTH = 15; // Number of tiles in width
const int BOARD_HEIGHT = 13; // Number of tiles in height
const int WINDOW_WIDTH = BOARD_WIDTH * TILE_SIZE; // Window width in pixels
const int WINDOW_HEIGHT = BOARD_HEIGHT * TILE_SIZE; // Window height in pixels


int main() {
    srand(time(nullptr)); 
    // Create a window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Bomberman Board");
    // Load the texture from file
    sf::Texture assets;
    if (!assets.loadFromFile("../assets/tiles/Tiles.png")) {
        return -1;
    }
    // Set the texture rect for each tile type
    std::map<TileType, sf::IntRect> tileMap;
    tileMap[TileType::Empty] = sf::IntRect(294, 461, TILE_SIZE, TILE_SIZE);
    tileMap[TileType::SolidWall] = sf::IntRect(311, 461, TILE_SIZE, TILE_SIZE);
    tileMap[TileType::Destructible] = sf::IntRect(328, 461, TILE_SIZE, TILE_SIZE);

    // Create the corresponding sprites for each tile type

    sf::Sprite emptySprite(assets, tileMap[TileType::Empty]);
    sf::Sprite solidWallSprite(assets, tileMap[TileType::SolidWall]);
    sf::Sprite destructibleSprite(assets, tileMap[TileType::Destructible]);

    // Create a vector of sprites to hold the tile sprites
    std::vector<sf::Sprite> sprites;
    sprites.push_back(emptySprite);
    sprites.push_back(solidWallSprite);
    sprites.push_back(destructibleSprite);

    // create the corresponding tiles
    Tile emptyTile(TileType::Empty, emptySprite);
    Tile solidWallTile(TileType::SolidWall, solidWallSprite);
    Tile destructibleTile(TileType::Destructible, destructibleSprite);

    std::vector<Tile> tiles;
    tiles.push_back(emptyTile);
    tiles.push_back(solidWallTile);
    tiles.push_back(destructibleTile);

    // Create a board
    Board board(BOARD_HEIGHT, BOARD_WIDTH, TILE_SIZE,sprites);
    // get back sprites from the board
    std::vector<sf::Sprite> boardSprites = board.getSprites();


    board.generateRandomBoard(); // Generate a random board with half of the tiles filled
    // Set some tiles on the board

    // Add tiles to a vector

    // Set the position of the tiles
    for (size_t i = 0; i < tiles.size(); ++i) {
        tiles[i].getSprite().setPosition(i * TILE_SIZE, 0);
    }
    // set the position of board sprites
    for (size_t i = 0; i < boardSprites.size(); ++i) {
        boardSprites[i].setPosition(i * TILE_SIZE, TILE_SIZE);
    }

    // //print size of the vector
    // std::cout << "Size of tiles vector: " << tiles.size() << std::endl;

    //just draw the tiles one witout a board for debug

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Draw the board
        
        board.draw(window);

        // draw the tiles original tiles
        for (int i = 0; i < tiles.size(); ++i) {
            window.draw(tiles[i].getSprite());
        }
        //  draw the board sprites
        for (int i = 0; i < boardSprites.size(); ++i) {
            window.draw(boardSprites[i]);
        }
        window.display();
    }

    return 0;
}
