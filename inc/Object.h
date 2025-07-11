#pragma once

#include "raylib.h"
#include "Drawable.h"
#include "CollisionProbe.h"
#include "GameClock.h"
enum ObjectState {
    OBJECT_STATE_IDLE = 0,
    OBJECT_STATE_ACTIVE,
    OBJECT_STATE_TO_BE_REMOVED,

    OBJECT_STATE_ON_GROUND,
    OBJECT_STATE_JUMPING,
    OBJECT_STATE_FALLING,
    OBJECT_STATE_DYING,
    OBJECT_STATE_DEAD,
};

enum Direction {
    DIRECTION_LEFT = 0,
    DIRECTION_RIGHT,
    DIRECTION_UP,
    DIRECTION_DOWN,
};

class Object : public Drawable {
    protected:
        Vector2 pos;
        Vector2 size;
        Vector2 vel;
        float angle;
        Color color;
        Direction direction;
        Texture2D* sprite;


        ObjectState state;
        ObjectState AdditionalState;
        
        CollisionProbe cpN;         
        CollisionProbe cpS;         
        CollisionProbe cpE;         
        CollisionProbe cpW;

        float frameTime;
        float frameAcumulator;
        int currentFrame;
        int maxFrames;

        virtual void Update() = 0;
        virtual void UpdateCollisionProbes();
        virtual void UpdateStateAndPhysic();
    public:
        Object();
        Object(Vector2 pos, Vector2 size,Vector2 vel, Color color,float frameTime, int maxFrames,  Direction direction);
        Object(Vector2 pos, Vector2 size, Color color);
        Object(Vector2 pos, Vector2 size,Vector2 vel, Color color,float frameTime, int maxFrames);

        virtual ~Object() override;

        virtual void draw() = 0;

        CollisionType checkCollisionType(const Object& other) const;

        void SetPos(Vector2 Pos);
        void SetSize(Vector2 size);
        void SetAngle(float angle);
        void SetState(ObjectState state);
        void SetColor(Color color);
        void SetDirection(Direction direction);
        void SetVel(Vector2 vel);

        void setFrameTime(float frameTime);
        void setFrameAcum(float frameAcum);
        void setCurrFrame(int currFrame);
        void setMaxFrame(int maxFrame);

        void SetCollisionProbesTop(CollisionProbe Top );
        void SetCollisionProbesBottom(CollisionProbe Bottom );
        void SetCollisionProbesRight(CollisionProbe Right );
        void SetCollisionProbesLeft(CollisionProbe Left );

        // Getters
        Vector2 GetPos() const ;
        Vector2 GetSize() const ;
        float GetAngle() const;
        ObjectState GetState() const;
        Color GetColor() const ;
        Direction GetDirection() const;
        Vector2 GetVel() const;

        float GetFrameTime() const;
        float GetFrameAcum() const;
        int GetCurrFrame() const;
        int GetMaxFrame() const;

};