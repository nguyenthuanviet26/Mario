#pragma once

#include "raylib.h"
#include "Drawable.h"

enum CollisionType {
    COLLISION_TYPE_NONE = 0,        // No collision occurred
    COLLISION_TYPE_NORTH,           // Collision occurred on the north (top) side of the sprite or probe
    COLLISION_TYPE_SOUTH,           // Collision occurred on the south (bottom) side of the sprite or probe
    COLLISION_TYPE_EAST,            // Collision occurred on the east (right) side of the sprite or probe
    COLLISION_TYPE_WEST,            // Collision occurred on the west (left) side of the sprite or probe
    COLLISION_TYPE_COLLIDED,        // General collision occurred (no specific direction, e.g., full overlap)
    COLLISION_TYPE_FIREBALL         // Collision involving a fireball (e.g., a projectile or special attack)
    
};

class CollisionProbe : public Drawable {
    private:
        Vector2 pos;
        Vector2 size;
        Color color;
    public:
        CollisionProbe();

        CollisionProbe(Vector2 pos, Vector2 size, Color color);

        ~CollisionProbe() override;

        void draw() override;

        bool checkCollision( const Rectangle &rect) const;

        //Getters
        void setPos( Vector2 pos );
        void setPos( float x, float y );
        void setX( float x );
        void setY( float y );
        void setSize( Vector2 dim );
        void setSize( float width, float height );
        void setWidth( float width );
        void setHeight( float height );
        void setColor( Color color );
        Vector2& getPos();
        float getX() const;
        float getY() const;
        Vector2& getSize();
        float getWidth() const;
        float getHeight() const;
        Color& getColor();
        Rectangle getRect() const;
};