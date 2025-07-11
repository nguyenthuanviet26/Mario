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
    Block* isAquestionBlock = dynamic_cast<QuestionBlock*>(ObjectA);
    Block* isBquestionBlock = dynamic_cast<QuestionBlock*>(ObjectB);
    CloudBlock* isAcloudBlock = dynamic_cast<CloudBlock*>(ObjectA);
    CloudBlock* isBcloudBlock = dynamic_cast<CloudBlock*>(ObjectB);
    WoodBlock* isAwoodBlock = dynamic_cast<WoodBlock*>(ObjectA);
    WoodBlock* isBwoodBlock = dynamic_cast<WoodBlock*>(ObjectB);
    GlassBlock* isAglassBlock = dynamic_cast<GlassBlock*>(ObjectA);
    GlassBlock* isBglassBlock = dynamic_cast<GlassBlock*>(ObjectB);
    EyesOpenedBlock* isAeyesOpenedBlock = dynamic_cast<EyesOpenedBlock*>(ObjectA);
    EyesOpenedBlock* isBeyesOpenedBlock = dynamic_cast<EyesOpenedBlock*>(ObjectB);
    EyesClosedBlock* isAeyesClosedBlock = dynamic_cast<EyesClosedBlock*>(ObjectA);
    EyesClosedBlock* isBeyesClosedBlock = dynamic_cast<EyesClosedBlock*>(ObjectB);  
    if ((isAmario && isBtile) || (isBmario && isAtile))
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBtile) : isBmario->checkCollisionType(*isAtile);
        if (isAmario)
            HandleMarioWithTile(isAmario, isBtile, AtoB);
        else
            HandleMarioWithTile(isBmario, isAtile, AtoB);
    }
    else if ((isAfireball && isBtile) || (isBfireball && isAtile))
    {
        CollisionType AtoB = isAfireball ? isAfireball->checkCollisionType(*isBtile) : isBfireball->checkCollisionType(*isAtile);
        if (isAfireball)
            HandleFireballWithTile(isAfireball, isBtile, AtoB);
        else
            HandleFireballWithTile(isBfireball, isAtile, AtoB);
    }
    else if (isAmario && isBquestionBlock || isBmario && isAquestionBlock)
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBquestionBlock) : isBmario->checkCollisionType(*isAquestionBlock);

        if (isAmario)
            HandleMarioWithQuestionBlock(isAmario, isBquestionBlock, AtoB);
        else
            HandleMarioWithQuestionBlock(isBmario, isAquestionBlock, AtoB);
    }
    else if ((isAmario && isBcloudBlock) || (isBmario && isAcloudBlock))
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBcloudBlock) : isBmario->checkCollisionType(*isAcloudBlock);
        if (isAmario)
            HandleMarioWithCloudBlock(isAmario, isBcloudBlock, AtoB);
        else
            HandleMarioWithCloudBlock(isBmario, isAcloudBlock, AtoB);
    }
    else if ((isAmario && isBwoodBlock) || (isBmario && isAwoodBlock))
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBwoodBlock) : isBmario->checkCollisionType(*isAwoodBlock);
        if (isAmario)
            HandleMarioWithWoodBlock(isAmario, isBwoodBlock, AtoB);
        else
            HandleMarioWithWoodBlock(isBmario, isAwoodBlock, AtoB);
    }
    else if ((isAmario && isBglassBlock) || (isBmario && isAglassBlock))
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBglassBlock) : isBmario->checkCollisionType(*isAglassBlock);
        if (isAmario)
            HandleMarioWithGlassBlock(isAmario, isBglassBlock, AtoB);
        else
            HandleMarioWithGlassBlock(isBmario, isAglassBlock, AtoB);
    }
    else if ((isAmario && isBeyesOpenedBlock) || (isBmario && isAeyesOpenedBlock))
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBeyesOpenedBlock) : isBmario->checkCollisionType(*isAeyesOpenedBlock);
        if (isAmario)
            HandleMarioWithEyesOpenedBlock(isAmario, isBeyesOpenedBlock, AtoB);
        else
            HandleMarioWithEyesOpenedBlock(isBmario, isAeyesOpenedBlock, AtoB);
    }
    else if ((isAmario && isBeyesClosedBlock) || (isBmario && isAeyesClosedBlock))
    {
        CollisionType AtoB = isAmario ? isAmario->checkCollisionType(*isBeyesClosedBlock) : isBmario->checkCollisionType(*isAeyesClosedBlock);
        if (isAmario)
            HandleMarioWithEyesClosedBlock(isAmario, isBeyesClosedBlock, AtoB);
        else
            HandleMarioWithEyesClosedBlock(isBmario, isAeyesClosedBlock, AtoB);
    }

}
void MediatorCollision::HandleMarioWithQuestionBlock(Mario* &mario, Block *&questionBlock, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;

    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
    {
        mario->SetPos(Vector2{mario->GetPos().x, questionBlock->GetPos().y - mario->GetSize().y});
        mario->SetState(OBJECT_STATE_ON_GROUND);
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    }
    case COLLISION_TYPE_NORTH:
    {
        mario->SetPos(Vector2{mario->GetPos().x, questionBlock->GetPos().y + questionBlock->GetSize().y});
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    }
    case COLLISION_TYPE_EAST:
    {
        mario->SetPos(Vector2{questionBlock->GetPos().x - mario->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    }
    case COLLISION_TYPE_WEST:
    {
        mario->SetPos(Vector2{questionBlock->GetPos().x + questionBlock->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    }
    default:
        break;
    }
}

void MediatorCollision::HandleMarioWithCloudBlock(Mario* &mario, CloudBlock *&cloudBlock, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;
    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
        if(mario->GetState() == OBJECT_STATE_FALLING)
        mario->SetPos(Vector2{mario->GetPos().x, cloudBlock->GetPos().y - mario->GetSize().y});
        mario->SetState(OBJECT_STATE_ON_GROUND);
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_NORTH:
        // mario->SetPos(Vector2{mario->GetPos().x, cloudBlock->GetPos().y + cloudBlock->GetSize().y});
        // mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_EAST:
        // mario->SetPos(Vector2{cloudBlock->GetPos().x - mario->GetSize().x, mario->GetPos().y});
        // mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    case COLLISION_TYPE_WEST:
        // mario->SetPos(Vector2{cloudBlock->GetPos().x + cloudBlock->GetSize().x, mario->GetPos().y});
        // mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    default:
        break;
    }
}

void MediatorCollision::HandleMarioWithWoodBlock(Mario* &mario, WoodBlock *&woodBlock, CollisionType AtoB){
    if (AtoB == COLLISION_TYPE_NONE)
        return;
    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
        mario->SetPos(Vector2{mario->GetPos().x, woodBlock->GetPos().y - mario->GetSize().y});
        mario->SetState(OBJECT_STATE_ON_GROUND);
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_NORTH:
        mario->SetPos(Vector2{mario->GetPos().x, woodBlock->GetPos().y + woodBlock->GetSize().y});
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_EAST:
        mario->SetPos(Vector2{woodBlock->GetPos().x - mario->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    case COLLISION_TYPE_WEST:
        mario->SetPos(Vector2{woodBlock->GetPos().x + woodBlock->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    default:
        break;
    }
}

void MediatorCollision::HandleMarioWithGlassBlock(Mario* &mario, GlassBlock *&glassBlock, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;

    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
        mario->SetPos(Vector2{mario->GetPos().x, glassBlock->GetPos().y - mario->GetSize().y});
        mario->SetState(OBJECT_STATE_ON_GROUND);
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_NORTH:
        mario->SetPos(Vector2{mario->GetPos().x, glassBlock->GetPos().y + glassBlock->GetSize().y});
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_EAST:
        mario->SetPos(Vector2{glassBlock->GetPos().x - mario->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    case COLLISION_TYPE_WEST:
        mario->SetPos(Vector2{glassBlock->GetPos().x + glassBlock->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    default:
        break;
    }
}

void MediatorCollision::HandleMarioWithEyesOpenedBlock(Mario* &mario, EyesOpenedBlock *&eyesOpenedBlock, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;
    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
        mario->SetPos(Vector2{mario->GetPos().x, eyesOpenedBlock->GetPos().y - mario->GetSize().y});
        mario->SetState(OBJECT_STATE_ON_GROUND);
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_NORTH:
        mario->SetPos(Vector2{mario->GetPos().x, eyesOpenedBlock->GetPos().y + eyesOpenedBlock->GetSize().y});
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;  
    case COLLISION_TYPE_EAST:
        mario->SetPos(Vector2{eyesOpenedBlock->GetPos().x - mario->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    case COLLISION_TYPE_WEST:
        mario->SetPos(Vector2{eyesOpenedBlock->GetPos().x + eyesOpenedBlock->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break; 
    default:
        break;
    }
}

void MediatorCollision::HandleMarioWithEyesClosedBlock(Mario* &mario, EyesClosedBlock *&eyesClosedBlock, CollisionType AtoB)
{
    if (AtoB == COLLISION_TYPE_NONE)
        return;

    switch (AtoB)
    {
    case COLLISION_TYPE_SOUTH:
        mario->SetPos(Vector2{mario->GetPos().x, eyesClosedBlock->GetPos().y - mario->GetSize().y});
        mario->SetState(OBJECT_STATE_ON_GROUND);
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_NORTH:
        mario->SetPos(Vector2{mario->GetPos().x, eyesClosedBlock->GetPos().y + eyesClosedBlock->GetSize().y});
        mario->SetVel(Vector2{mario->GetVel().x, 0});
        break;
    case COLLISION_TYPE_EAST:
        mario->SetPos(Vector2{eyesClosedBlock->GetPos().x - mario->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    case COLLISION_TYPE_WEST:
        mario->SetPos(Vector2{eyesClosedBlock->GetPos().x + eyesClosedBlock->GetSize().x, mario->GetPos().y});
        mario->SetVel(Vector2{0, mario->GetVel().y});
        break;
    default:
        break;
    }
}
