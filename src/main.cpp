#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include <iostream>
// #include <filesystem>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(480/2, 416/2), "Bomberman Board");
   
    sf::Texture assets;
    if (!assets.loadFromFile("../assets/tiles/Tiles.png")) {
        return -1;
    }

    int tileSize = 16;

    std::map<TileType, sf::IntRect> tileMap;
    tileMap[TileType::Empty] = sf::IntRect(294, 461, tileSize, tileSize);
    tileMap[TileType::SolidWall] = sf::IntRect(311, 461, tileSize, tileSize);
    tileMap[TileType::Destructible] = sf::IntRect(328, 461, tileSize, tileSize);

    // Create the corresponding sprites for each tile type

    sf::Sprite emptySprite(assets, tileMap[TileType::Empty]);
    sf::Sprite solidWallSprite(assets, tileMap[TileType::SolidWall]);
    sf::Sprite destructibleSprite(assets, tileMap[TileType::Destructible]);
    

    // create the corresponding tiles
    Tile emptyTile(TileType::Empty, emptySprite);
    Tile solidWallTile(TileType::SolidWall, solidWallSprite);
    Tile destructibleTile(TileType::Destructible, destructibleSprite);


    // Add tiles to a vector

    std::vector<Tile> tiles;
    tiles.push_back(emptyTile);
    tiles.push_back(solidWallTile);
    tiles.push_back(destructibleTile);

    // Set the position of the tiles
    for (size_t i = 0; i < tiles.size(); ++i) {
        tiles[i].getSprite().setPosition(i * tileSize, 0);
    }

    // print size of the vector
    std::cout << "Size of tiles vector: " << tiles.size() << std::endl;

    //just draw the tiles one witout a board for debug

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Draw the tiles
        for (auto& tile : tiles) {
            window.draw(tile.getSprite());
        }
        window.display();
    }

    return 0;
}
