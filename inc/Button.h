#pragma once
#include "Drawable.h"
#include "raylib.h"
#include <string>
class Button : public Drawable {
    private:
        Rectangle ConstButton;
        Rectangle CurButton;
        Rectangle TextureButton;

        Vector2 pos;
        Vector2 Textpos;
        Vector2 size;
        float zoom;
        int Text_Size;
        std::string text;
        Texture2D* texture;

        bool isPressed;
    public:
        Button();
        Button(Vector2 pos, Vector2 size, std::string text, int Text_Size = 20, float zoom = 1.0f);
        ~Button() override;

        void draw() override;
        void Update();
        void HandleInput();

        bool IsPressed() const;
        bool IsHovered() const;

        void SetPosition(Vector2 pos);
        void SetSize(Vector2 size);
        void SetText(std::string text);
        void SetTextPosition(Vector2 posText);
        void SetTextSize(int size);

        void SetTexture(const Texture2D& texture);
        void SetTexturePosition(Vector2 pos);
        void SetTextureSize(Vector2 size);
};

        
