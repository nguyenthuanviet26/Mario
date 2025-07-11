#include "GameWorld.h"
#include "Coin.h"

float GameWorld::gravity = 200.0f;

GameWorld::GameWorld() : player(), interactiveTiles(map.getInteractiveTiles()), interactiveCoins(map.getInteractiveCoins()), interactiveCourseClearTokens(map.getInteractiveCourseClearTokens()), interactiveFireFlowers(map.getInteractiveFireFlowers())
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

void GameWorld::UpdateWorld()
{
    player.UpdateStateAndPhysic();
    for ( auto const &tile : interactiveTiles )
    {
        CollisionType collision = player.checkCollisionType(*tile);
        if ( collision )
        {
            mediatorCollision.HandleCollision(&player, tile);
        }

        for ( auto &fireball : *player.GetFireballs() )
        {
            CollisionType fireballCollision = fireball->checkCollisionType(*tile);
            if ( fireballCollision  )
            {
                mediatorCollision.HandleCollision(fireball, tile);
            }
        }
    }

    for( auto const coin : interactiveCoins){
        CollisionType collision = player.checkCollisionType(*coin);
        if(collision){
            mediatorCollision.HandleCollision(&player, coin.get());
        }
        coin->Update();//animation
    }
    
    for (auto& course : interactiveCourseClearTokens) {
    CollisionType collision = player.checkCollisionType(*course);
    if (collision) {
        mediatorCollision.HandleCollision(&player, course.get());
    }

    course->Update();  // BẮT BUỘC để token xoay
    // course->draw();    // vẽ theo rotationAngle
    }

    for( auto const fire : interactiveFireFlowers){
        CollisionType collision = player.checkCollisionType(*fire);
        if(collision){
            mediatorCollision.HandleCollision(&player, fire.get());
        }
        fire->Update();//animation
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
    for(auto coin : interactiveCoins){
        coin->draw();
    }

    for(auto course : interactiveCourseClearTokens){
        course->draw();
    }

    for( auto const fire : interactiveFireFlowers){
        fire->draw();
    }

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
