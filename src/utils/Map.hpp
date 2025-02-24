#ifndef __MAP__
#define __MAP__

#include "Vector2.hpp"
#include <vector>
#include <string>

class Map
{
public:
    Map(std::string texID, int mScale, int tSize);
    ~Map() = default;

    void LoadMap(std::string path, int sizeX, int sizeY);
    void AddTile(int srcX, int srcY, int xpos, int ypos);
    Vector2 GetBounds() { return bounds; }

    void SpawnEntities(); // TODO: à faire

private:
    const std::string textureID;
    int tileSize;
    int mapScale;
    int scaledTileSize;
    Vector2 bounds = {0, 0};

    // TODO: ajouter un std::vector comportant les info pour spawn les entités qu'on veut sur la carte
};

#endif