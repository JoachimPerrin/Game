#ifndef MAP_MANAGER_HPP
#define MAP_MANAGER_HPP

#include <unordered_map>
#include <string>
#include "Map.hpp"

class MapManager
{
public:
    MapManager();
    ~MapManager();

    void AddMap(std::string mapID, std::string mapPath, int sizeX, int sizeY);
    void LoadMap(std::string tileMapID, std::string tileSetID);
    void ChangeMap(std::string newMapID, std::string newSetID);
    Map *GetCurrentMap() { return currentMap; }

private:
    std::unordered_map<std::string, std::tuple<std::string, int, int>> maps;
    //FIXME: Passer par des smart pointer (unique or shared?)
    Map *currentMap;
    std::string textureID;
    int mapScale;
    int tileSize;
};

#endif