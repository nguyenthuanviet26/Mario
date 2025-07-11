#include "Button.h"
Button::Button() = default;
Button::Button(Vector2 pos, Vector2 size, std::string text, int Text_Size, float zoom)
    : pos(pos), size(size), text(text), Text_Size(Text_Size), zoom(zoom), isPressed(false) {
    ConstButton = {pos.x, pos.y, size.x, size.y};
    CurButton = ConstButton;
    Textpos = {pos.x + size.x / 2 - MeasureText(text.c_str(), Text_Size) / 2 , pos.y + size.y / 2 - Text_Size / 2 };
    CurButton = ConstButton;
    TextureButton = {pos.x, pos.y, size.x, size.y};
    texture = nullptr;    
}

Button::~Button() {
    if (texture) {
        UnloadTexture(*texture);
        delete texture;
    }
}

void Button::HandleInput() {
    if (!isPressed&&IsHovered() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isPressed = true;
    } 

    if (isPressed) {
        //
    }
}

void Button::Update() {
    HandleInput();
    if (isPressed) {
        zoom = 1.2;
    } else if (IsHovered()) {
        zoom = 1.1;
    } else {
        zoom = 1.0;
    }
    CurButton.width = ConstButton.width * zoom;
    CurButton.height = ConstButton.height * zoom;
    size.x = CurButton.width;
    size.y = CurButton.height;
}

void Button::draw() {
    // Draw the button background
    DrawRectangleRounded(CurButton, 0.5f, 360, WHITE); 
    DrawRectangleRoundedLinesEx(CurButton, 0.5f, 360, 3.0f, BLACK);

    // Draw the texture if it exists
    if (texture) {
        TextureButton = {CurButton.x, CurButton.y, CurButton.width, CurButton.height}; // Ensure TextureButton matches CurButton
        DrawTexturePro(*texture, Rectangle{0, 0, (float)texture->width, (float)texture->height}, TextureButton, Vector2{0, 0}, 0.0f, WHITE);
    }

    // Draw the text if it exists
    if (!text.empty()) {
        Textpos = {CurButton.x + CurButton.width / 2 - MeasureText(text.c_str(), Text_Size) / 2, 
                   CurButton.y + CurButton.height / 2 - Text_Size / 2}; // Update text position
        DrawText(text.c_str(), Textpos.x, Textpos.y, Text_Size, BLACK);
    }
}

bool Button::IsPressed() const  {
    // Chỉ trả về true đúng 1 lần khi click chuột vào button
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsHovered()) {
        return true;
    }
    return false;
}

bool Button::IsHovered() const {
    Vector2 mousePos = GetMousePosition();
    return CheckCollisionPointRec(mousePos, CurButton);
}

void Button::SetPosition(Vector2 pos) {
    this->pos = pos;
    ConstButton = {pos.x, pos.y, size.x, size.y};
    CurButton = ConstButton;
    Textpos = {pos.x + size.x / 2 - MeasureText(text.c_str(), Text_Size) / 2, pos.y + size.y / 2 - Text_Size / 2};
    TextureButton = {pos.x, pos.y, size.x, size.y};
}

void Button::SetSize(Vector2 size)
{
    this->size = size;
    ConstButton = {pos.x, pos.y, size.x, size.y};
    CurButton = ConstButton;
}

void Button::SetText(std::string text) {
    this->text = text;
    Textpos = Vector2{pos.x + size.x / 2 - MeasureText(text.c_str(), Text_Size) / 2, pos.y + size.y / 2 - Text_Size / 2};
}

void Button::SetTextPosition(Vector2 posText) {
    Textpos = posText;
}

void Button::SetTextSize(int size) {
    Text_Size = size;
}

void Button::SetTexture(const Texture2D& texture) {
    if (this->texture) {
        UnloadTexture(*this->texture);
        delete this->texture;
    }
    this->texture = new Texture2D(texture);
}

void Button::SetTexturePosition(Vector2 pos) {
    TextureButton.x = pos.x;
    TextureButton.y = pos.y;
}

void Button::SetTextureSize(Vector2 size) {
    TextureButton.width = size.x;
    TextureButton.height = size.y;
}





