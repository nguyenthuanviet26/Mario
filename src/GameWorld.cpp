#include "GameWorld.h"


GameWorld::GameWorld() : player(), interactiveTiles(map.getInteractiveTiles())
{
    // Trong GameWorld constructor, thêm:
    player = Mario(Vector2{100, 100}, 3, SMALL); // Đặt vị trí cụ thể
    map.LoadMap(0);
    camera.offset = Vector2{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    camera.target = player.GetPos();
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

GameWorld::~GameWorld()
{
    // Destructor logic if needed
}

// void GameWorld::UpdateWorld()
// {
//     player.UpdateStateAndPhysic();
//     for ( auto const &tile : interactiveTiles )
//     {
//         CollisionType collision = player.checkCollisionType(*tile);
//         if ( collision )
//         {
//             mediatorCollision.HandleCollision(&player, tile);
//         }

//         for ( auto &fireball : *player.GetFireballs() )
//         {
//             CollisionType fireballCollision = fireball->checkCollisionType(*tile);
//             if ( fireballCollision  )
//             {
//                 mediatorCollision.HandleCollision(fireball, tile);
//             }
//         }
//     }
    
// }
void GameWorld::UpdateWorld()
{
    player.UpdateStateAndPhysic();

    // Va chạm với interactive tiles
    for (auto const &tile : interactiveTiles)
    {
        CollisionType collision = player.checkCollisionType(*tile);
        if (collision)
        {
            mediatorCollision.HandleCollision(&player, tile);
        }

        for (auto &fireball : *player.GetFireballs())
        {
            CollisionType fireballCollision = fireball->checkCollisionType(*tile);
            if (fireballCollision)
            {
                mediatorCollision.HandleCollision(fireball, tile);
            }
        }
    }

//     
for (auto &block : map.getBlocks())
{
    block->Update();

    CollisionType collision = block->checkCollisionType(player);
    if( collision != COLLISION_TYPE_NONE && block->GetBlockType() == BLOCK_EYES_OPENED)
    {
        block->doHit(player, &map);
    }
    if (collision == COLLISION_TYPE_SOUTH && block->GetBlockType() == BLOCK_QUESTION)
    {   
        block->doHit(player, &map);
        player.SetVel({player.GetVel().x, 0});
    }
    
    mediatorCollision.HandleCollision(&player, block);
}


}
void GameWorld::DrawWorld()
{
    camera.target.y = GetScreenHeight() / 2;
    if ( player.GetPos().x > GetScreenWidth() / 2 && player.GetPos().x < map.GetWidth() - GetScreenWidth() / 2) {
        camera.target.x = player.GetPos().x;
    } else if (player.GetPos().x <= GetScreenWidth() / 2) {
        camera.target.x = GetScreenWidth() / 2;
    } else {
        camera.target.x = map.GetWidth() - GetScreenWidth() / 2;
    } 

    if ( camera.target.x - GetScreenWidth() / 2 >= currBackgroundStarX )
    {
        currBackgroundStarX = currBackgroundStarX + background.width * 1.3f;
    }
    if ( camera.target.x + GetScreenWidth() / 2 <= currBackgroundStarX + background.width * 1.3f )
    {
        currBackgroundStarX = currBackgroundStarX - background.width * 1.3f;
    }

    BeginMode2D(camera);
    DrawTextureEx(background, Vector2{currBackgroundStarX-background.width*1.3f,-200}, 0.0f, 1.3f, WHITE);
    DrawTextureEx(background,Vector2{currBackgroundStarX,-200},0.0f,1.3f,WHITE);
    DrawTextureEx(background,Vector2{currBackgroundStarX+background.width*1.3f,-200},0.0f,1.3f,WHITE);
    map.draw();
    player.draw();
    EndMode2D();
}

const float GameWorld::GetGravity()
{
    return gravity;
}

void GameWorld::Init()
{
    ResrcManager::GetInstance().loadResources();
}
