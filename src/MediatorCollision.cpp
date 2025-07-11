#include "MediatorCollision.h"

void MediatorCollision::HandleMarioWithTile(Mario* &mario, Tile * &tile, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;

    switch (AtoB)
    {
        
        case COLLISION_TYPE_SOUTH:
        {
            mario->SetPos(Vector2{mario->GetPos().x, tile->GetPos().y - mario->GetSize().y});
            mario->SetState(OBJECT_STATE_ON_GROUND);
            mario->SetVel(Vector2{mario->GetVel().x, 0});
            break;
        }
        
        case COLLISION_TYPE_NORTH:
        {
            mario->SetPos(Vector2{mario->GetPos().x, tile->GetPos().y + tile->GetSize().y});
            mario->SetVel(Vector2{mario->GetVel().x, 0});
            break;
        }

        case COLLISION_TYPE_EAST:
        {
            mario->SetPos(Vector2{tile->GetPos().x - mario->GetSize().x, mario->GetPos().y});
            mario->SetVel(Vector2{0, mario->GetVel().y}); // Reverse the x velocity
            break;
        }
        
        case COLLISION_TYPE_WEST:
        {
            mario->SetPos(Vector2{tile->GetPos().x + tile->GetSize().x, mario->GetPos().y});
            mario->SetVel(Vector2{0, mario->GetVel().y}); // Reverse the x velocity
            break;
        }
        default:
            break;
    }
}
void MediatorCollision::HandleFireballWithTile(Fireball *&fireball, Tile *&tile, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;
    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
    {
        fireball->SetPos(Vector2{fireball->GetPos().x, tile->GetPos().y - fireball->GetSize().y});
        fireball->SetVel(Vector2{fireball->GetVel().x, -500});
        break;
    }
    case COLLISION_TYPE_NORTH:
    {
        fireball->SetPos(Vector2{fireball->GetPos().x, tile->GetPos().y + tile->GetSize().y});
        fireball->SetVel(Vector2{fireball->GetVel().x, 0});
        break;
    }
    case COLLISION_TYPE_EAST:
    {
        fireball->SetPos(Vector2{tile->GetPos().x - fireball->GetSize().x, fireball->GetPos().y});
        fireball->SetVel(Vector2{-fireball->GetVel().x, fireball->GetVel().y}); // Reverse the x velocity
        if (fireball->GetCurrFrame() == 0)
        {
            fireball->setCurrFrame(3);
        }
        else
            fireball->setCurrFrame(fireball->GetCurrFrame() - 1);
        break;
    }
    case COLLISION_TYPE_WEST:
    {
        fireball->SetPos(Vector2{tile->GetPos().x + fireball->GetSize().x + tile->GetSize().x, fireball->GetPos().y});
        fireball->SetVel(Vector2{-fireball->GetVel().x, fireball->GetVel().y}); // Reverse the x velocity
        if (fireball->GetCurrFrame() == 0)
        {
            fireball->setCurrFrame(3);
        }
        else
            fireball->setCurrFrame(fireball->GetCurrFrame() - 1);
        break;
    }
    }
}
void MediatorCollision::HandleCollision(Object *ObjectA, Object *ObjectB)
{

    Mario* isAmario = dynamic_cast<Mario*>(ObjectA);
    Mario* isBmario = dynamic_cast<Mario*>(ObjectB);
    Fireball* isAfireball = dynamic_cast<Fireball*>(ObjectA);
    Fireball* isBfireball = dynamic_cast<Fireball*>(ObjectB);
    Tile* isAtile = dynamic_cast<Tile*>(ObjectA);
    Tile* isBtile = dynamic_cast<Tile*>(ObjectB);
    Item* isAitem = dynamic_cast<Item*>(ObjectA); 
    Item* isBitem = dynamic_cast<Item*>(ObjectB);
    if (isAmario && isBtile|| isBmario&& isAtile)
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBtile) : isBmario->checkCollisionType(*isAtile);
        if (isAmario)
            HandleMarioWithTile(isAmario, isBtile, AtoB);
        else
            HandleMarioWithTile(isBmario, isAtile, AtoB);
    }
    else if (isAfireball && isBtile || isBfireball && isAtile)
    {
        CollisionType AtoB = isAfireball ? isAfireball->checkCollisionType(*isBtile) : isBfireball->checkCollisionType(*isAtile);
        if (isAfireball)
            HandleFireballWithTile(isAfireball, isBtile, AtoB);
        else
            HandleFireballWithTile(isBfireball, isAtile, AtoB);
    }

    else if ((isAmario && isBitem) || (isBmario && isAitem))
    {
        Mario* mario = isAmario ? isAmario : isBmario;
        Item* item = isAitem ? isAitem : isBitem;

        if (item->checkCollision(*mario) == COLLISION_TYPE_COLLIDED)
        {
            item->updateMario(*mario);      
            item->playCollisionSound();//sound
        }
    }

}