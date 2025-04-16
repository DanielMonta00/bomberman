#pragma once
#include <SFML/Graphics.hpp>

enum class TileType {
    Empty,          // Represents an empty tile that can be walked on.
    SolidWall,      // Represents a solid wall that cannot be destroyed or walked through.
    Destructible    // Represents a destructible tile that can be destroyed by an explosion.
};

class Tile {

private:
    TileType type;
    sf::Sprite sprite;
    // float positionX;
    // float positionY;
    // // The position of the tile in the grid
    // // The position of the tile in the grid (row, column)
    // int row;
    // int col;

public:
    Tile(TileType type,  sf::Sprite sprite);
    bool isWalkable() const;
    bool isDestructible() const;
    bool isSolidWall() const;

    // Getters for the sprite and type
    sf::Sprite& getSprite() { return sprite; }
    // Return a reference to the sprite for modification
    // Return a const reference to the sprite for read-only access
    // const sf::Sprite& getSprite() const { return sprite; }
    TileType getType() const { return type; }
    // Setters for the sprite and type
    void setSprite(const sf::Sprite& newSprite) { sprite = newSprite; }
    void setType(TileType newType) { type = newType; }

};
