#include "Tile.hpp"

Tile::Tile(TileType type, sf::Sprite spriteFile)
    : type(type) {
    sprite.setTexture(*spriteFile.getTexture());
    sprite.setTextureRect(spriteFile.getTextureRect());
}

bool Tile::isWalkable() const {
    return type == TileType::Empty;
}

bool Tile::isDestructible() const {
    return type == TileType::Destructible;
}

bool Tile::isSolidWall() const {
    return type == TileType::SolidWall;
}


