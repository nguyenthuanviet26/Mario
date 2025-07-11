#include "Map.h"

Map::~Map()
{
    for (Tile* tile : interactiveTiles) {
        delete tile;
        tile = nullptr;
    }
    nonInteractiveTiles.clear();
}

std::vector<Tile *> &Map::getInteractiveTiles()
{
    
    return interactiveTiles;
}

std::vector<Tile*> &Map::getNonInteractiveTiles()
{
    return nonInteractiveTiles;
}

std::vector<std::shared_ptr<Coin>> &Map::getInteractiveCoins()
{
    
    return interactiveCoins;
}

std::vector<std::shared_ptr<FireFlower>> &Map::getInteractiveFireFlowers()
{
    
    return interactiveFireFlowers;
}

std::vector<std::shared_ptr<CourseClearToken>>& Map::getInteractiveCourseClearTokens()
{
    return interactiveCourseClearTokens;
}

float Map::GetWidth() const
{
    return width;
}

void Map::nextMap()
{
    
}

void Map::LoadMap(int mapIndex)
{
    char* map = nullptr;
    std::string mapFileName = "resources/maps/map" +std::to_string(mapIndex) + ".json";
    std::ifstream file(mapFileName);
    if (!file) {
        std::cerr << "Could not open json file " << mapFileName << std::endl;
        return;
    }
    nlohmann::json mapJson;
    file >> mapJson;

    int width = mapJson["width"];
    int height = mapJson["height"];
    this->width = (float) width * 32.0f;
    int tilewidth = mapJson["tilewidth"];
    std::vector<int> data = mapJson["layers"][0]["data"];

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int tileId = data[y * width + x];
            if (tileId == 0)
                continue;
            else if(tileId == 201) {
                blocks.push_back(new QuestionBlock({(float)x * 32, (float)y * 32}, {32, 32}, WHITE));
                interactiveCoins.push_back(std::make_shared<Coin>((float)x * 32, (float)y * 32 - 32));
            }
            else if (tileId == 200) {
                blocks.push_back(new CloudBlock({(float)x * 32, (float)y * 32}, {32, 32}, WHITE));
            }
            else if (tileId == 202) {
                blocks.push_back(new WoodBlock({(float)x * 32, (float)y * 32}, {32, 32}, WHITE));
            }
            else if (tileId == 203) {
                blocks.push_back(new GlassBlock({(float)x * 32, (float)y * 32}, {32, 32}, WHITE));
            }
            else if (tileId == 204) {
                blocks.push_back(new EyesOpenedBlock({(float)x * 32, (float)y * 32}, {32, 32}, WHITE));
            }
            else if (tileId == 205) {
                blocks.push_back(new EyesClosedBlock({(float)x * 32, (float)y * 32}, {32, 32}, WHITE));
            }
            // else if (tileId == 1) {
            //     nonInteractiveTiles.push_back(new Tile({(float)x * 32, (float)y * 32}, mapIndex, tileId - 1, TILE_TYPE_SOLID));
            // }
            else {
                interactiveTiles.push_back(new Tile({(float)x * 32, (float)y * 32}, mapIndex, tileId - 1, TILE_TYPE_SOLID));
            }
            }
        }
}

void Map::draw()
{
    for (auto tile : interactiveTiles) {
        tile->draw();
    }

    for (auto tile : nonInteractiveTiles) {
        tile->draw();
    }

    for (const auto& block : blocks) {
        block->draw();
    }
}

Map::Map()
{
    currBackgroundStarX = 0.0f;
    background = ResrcManager::GetInstance().getTexture("BACKGROUND_0");
}

std::vector<Block*>& Map::getBlocks(){
        return blocks;
    };