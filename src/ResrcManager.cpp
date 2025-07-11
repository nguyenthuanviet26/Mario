#include "ResrcManager.h" 

ResrcManager* ResrcManager::instance = nullptr;

ResrcManager::~ResrcManager() {
    // Clean up resources if necessary
    unloadResources();
    
    instance = nullptr;
}

void ResrcManager::loadTextures() {
    // SMall Mario textures
    {
    textures["SMALLMARIO_0_RIGHT"] = LoadTexture("resources/images/Object/mario/SmallMario_0.png");
    textures["SMALLMARIO_0_LEFT"] = FlipTextureHorizontal(textures["SMALLMARIO_0_RIGHT"]);

    textures["SMALLMARIO_1_RIGHT"] = LoadTexture("resources/images/Object/mario/SmallMario_1.png");
    textures["SMALLMARIO_1_LEFT"] = FlipTextureHorizontal(textures["SMALLMARIO_1_RIGHT"]);

    textures["SMALLMARIO_JUMPING_RIGHT"] = LoadTexture("resources/images/Object/mario/SmallMarioJumping_0.png");
    textures["SMALLMARIO_JUMPING_LEFT"] = FlipTextureHorizontal(textures["SMALLMARIO_JUMPING_RIGHT"]);
    textures["SMALLMARIO_DUCKING_RIGHT"] = LoadTexture("resources/images/Object/mario/SmallMarioDucking_0.png");
    textures["SMALLMARIO_DUCKING_LEFT"] = FlipTextureHorizontal(textures["SMALLMARIO_DUCKING_RIGHT"]);
    textures["SMALLMARIO_FALLING_RIGHT"] = LoadTexture("resources/images/Object/mario/SmallMarioFalling_0.png");
    textures["SMALLMARIO_FALLING_LEFT"] = FlipTextureHorizontal(textures["SMALLMARIO_FALLING_RIGHT"]);
    }

    textures["SUPER_MARIO_0_RIGHT"] = LoadTexture("resources/images/Object/mario/SuperMario_0.png");
    textures["SUPER_MARIO_1_RIGHT"] = LoadTexture("resources/images/Object/mario/SuperMario_1.png");
    textures["SUPER_MARIO_2_RIGHT"] = LoadTexture("resources/images/Object/mario/SuperMario_2.png");
    textures["SUPER_MARIO_0_LEFT"] = FlipTextureHorizontal(textures["SUPER_MARIO_0_RIGHT"]);
    textures["SUPER_MARIO_1_LEFT"] = FlipTextureHorizontal(textures["SUPER_MARIO_1_RIGHT"]);
    textures["SUPER_MARIO_2_LEFT"] = FlipTextureHorizontal(textures["SUPER_MARIO_2_RIGHT"]);

    textures["SUPER_MARIO_JUMPING_0_RIGHT"] = LoadTexture("resources/images/Object/mario/SuperMarioJumping_0.png");
    textures["SUPER_MARIO_JUMPING_0_LEFT"] = FlipTextureHorizontal(textures["SUPER_MARIO_JUMPING_0_RIGHT"]);
    textures["SUPER_MARIO_FALLING_0_RIGHT"] = LoadTexture("resources/images/Object/mario/SuperMarioFalling_0.png");
    textures["SUPER_MARIO_FALLING_0_LEFT"] = FlipTextureHorizontal(textures["SUPER_MARIO_FALLING_0_RIGHT"]);

    textures["SUPER_MARIO_DUCKING_0_RIGHT"] = LoadTexture("resources/images/Object/mario/SuperMarioDucking_0.png");
    textures["SUPER_MARIO_DUCKING_0_LEFT"] = FlipTextureHorizontal(textures["SUPER_MARIO_DUCKING_0_RIGHT"]);

    
    textures["SUPER_MARIO_VICTORY"] = LoadTexture("resources/images/Object/mario/SuperMarioVictory_0.png");

    textures["TRANSITIONING_MARIO_0_RIGHT"] = LoadTexture("resources/images/Object/mario/TransitioningMario_0.png");
    textures["TRANSITIONING_MARIO_0_LEFT"] = FlipTextureHorizontal(textures["TRANSITIONING_MARIO_0_RIGHT"]);
    textures["TRANSITIONING_MARIO_1_RIGHT"] = LoadTexture("resources/images/Object/mario/TransitioningMario_1.png");
    textures["TRANSITIONING_MARIO_1_LEFT"] = FlipTextureHorizontal(textures["TRANSITIONING_MARIO_1_RIGHT"]);
    textures["TRANSITIONING_MARIO_2_RIGHT"] = LoadTexture("resources/images/Object/mario/TransitioningMario_2.png");
    textures["TRANSITIONING_MARIO_2_LEFT"] = FlipTextureHorizontal(textures["TRANSITIONING_MARIO_2_RIGHT"]);
    //FIRE MARIO
    textures["FIRE_MARIO_0_RIGHT"] = LoadTexture("resources/images/Object/mario/FireMario_0.png");
    textures["FIRE_MARIO_1_RIGHT"] = LoadTexture("resources/images/Object/mario/FireMario_1.png");
    textures["FIRE_MARIO_2_RIGHT"] = LoadTexture("resources/images/Object/mario/FireMario_2.png");
    textures["FIRE_MARIO_0_LEFT"] = FlipTextureHorizontal(textures["FIRE_MARIO_0_RIGHT"]);
    textures["FIRE_MARIO_1_LEFT"] = FlipTextureHorizontal(textures["FIRE_MARIO_1_RIGHT"]);
    textures["FIRE_MARIO_2_LEFT"] = FlipTextureHorizontal(textures["FIRE_MARIO_2_RIGHT"]);

    textures["FIRE_MARIO_JUMPING_0_RIGHT"] = LoadTexture("resources/images/Object/mario/FireMarioJumping_0.png");
    textures["FIRE_MARIO_JUMPING_0_LEFT"] = FlipTextureHorizontal(textures["FIRE_MARIO_JUMPING_0_RIGHT"]);
    textures["FIRE_MARIO_FALLING_0_RIGHT"] = LoadTexture("resources/images/Object/mario/FireMarioFalling_0.png");
    textures["FIRE_MARIO_FALLING_0_LEFT"] = FlipTextureHorizontal(textures["FIRE_MARIO_FALLING_0_RIGHT"]);

    textures["FIRE_MARIO_DUCKING_0_RIGHT"] = LoadTexture("resources/images/Object/mario/FireMario_Ducking_0.png");
    textures["FIRE_MARIO_DUCKING_0_LEFT"] = FlipTextureHorizontal(textures["FIRE_MARIO_DUCKING_0_RIGHT"]);
    textures["FIRE_MARIO_VICTORY"] = LoadTexture("resources/images/Object/mario/FireMarioVictory_0.png");

    {
    textures["FIRE_BALL_0_RIGHT"] = LoadTexture("resources/images/Object/mario/FlowerMarioFireball_0.png");
    textures["FIRE_BALL_1_RIGHT"] = LoadTexture("resources/images/Object/mario/FlowerMarioFireball_1.png");
    textures["FIRE_BALL_2_RIGHT"] = LoadTexture("resources/images/Object/mario/FlowerMarioFireball_2.png");
    textures["FIRE_BALL_3_RIGHT"] = LoadTexture("resources/images/Object/mario/FlowerMarioFireball_3.png");
    textures["FIRE_BALL_0_LEFT"] = FlipTextureHorizontal(textures["FIRE_BALL_0_RIGHT"]);
    textures["FIRE_BALL_1_LEFT"] = FlipTextureHorizontal(textures["FIRE_BALL_1_RIGHT"]);
    textures["FIRE_BALL_2_LEFT"] = FlipTextureHorizontal(textures["FIRE_BALL_2_RIGHT"]);
    textures["FIRE_BALL_3_LEFT"] = FlipTextureHorizontal(textures["FIRE_BALL_3_RIGHT"]);
    }
    //BACKGROUND
    {
    textures["BACKGROUND_0"] = LoadTexture("resources/images/backgrounds/background1.png");
    }
    //TILES
    for (int i = 0; i < 104; ++i) {
        std::string keyStr = "tile_" + std::to_string(i);
        textures[keyStr] = LoadTexture(("resources/images/tiles/tile_" + std::to_string(i) + ".png").c_str());
    }

    //Blocks
    textures["BLOCK_QUESTION_0"] = LoadTexture("resources/images/Object/blocks/Question_0.png");
    textures["BLOCK_QUESTION_1"] = LoadTexture("resources/images/Object/blocks/Question_1.png");
    textures["BLOCK_QUESTION_2"] = LoadTexture("resources/images/Object/blocks/Question_2.png");
    textures["BLOCK_QUESTION_3"] = LoadTexture("resources/images/Object/blocks/Question_3.png");
    textures["BLOCK_STONE"] = LoadTexture("resources/images/Object/blocks/Stone_0.png");
    textures["BLOCK_CLOUD"] = LoadTexture("resources/images/Object/blocks/Cloud_0.png");
    textures["BLOCK_WOOD"] = LoadTexture("resources/images/Object/blocks/Wood_0.png");
    textures["BLOCK_MESSAGE"] = LoadTexture("resources/images/Object/blocks/Message_0.png");
    textures["BLOCK_GLASS"] = LoadTexture("resources/images/Object/blocks/Glass_0.png");
    textures["BLOCK_EXCLAMATION"] = LoadTexture("resources/images/Object/blocks/Exclamation_0.png");
    textures["BLOCK_EYE_CLOSED"] = LoadTexture("resources/images/Object/blocks/EyesClosed_0.png");
    textures["BLOCK_EYE_OPEN_0"] = LoadTexture("resources/images/Object/blocks/EyesOpened_0.png");
    textures["BLOCK_EYE_OPEN_1"] = LoadTexture("resources/images/Object/blocks/EyesOpened_1.png");
    textures["BLOCK_EYE_OPEN_2"] = LoadTexture("resources/images/Object/blocks/EyesOpened_2.png");
    textures["BLOCK_EYE_OPEN_3"] = LoadTexture("resources/images/Object/blocks/EyesOpened_3.png");
    textures["BASE"] = LoadTexture("resources/images/Object/blocks/base/tiles.png");
}

void ResrcManager::loadSounds(){
    sounds["MARIO_JUMP"] = LoadSound("resources/SFX/smw_jump.wav");
    sounds["MARIO_FIREBALL"] = LoadSound("resources/SFX/smw_fireball.wav");
    sounds["MARIO_POWERUP"] = LoadSound("resources/SFX/smw_power-up_appears.wav");
}

void ResrcManager::loadMusics(){
    musics["Test"]= LoadMusicStream("resources/musics/test.mp3");
}

void ResrcManager::loadResources() {
    loadTextures();
    loadSounds();
    loadMusics();
}

void ResrcManager::unloadTextures() {
    for (auto &pair : textures) {
        UnloadTexture(pair.second);
    }
    textures.clear();
}

void ResrcManager::unloadSounds() {
    for (auto &pair : sounds) {
        UnloadSound(pair.second);
    }
    sounds.clear();
}

void ResrcManager::unloadMusics() {
    for (auto &pair : musics) {
        UnloadMusicStream(pair.second);
    }
    musics.clear();
}

ResrcManager &ResrcManager::GetInstance() {
    if (instance == nullptr) {
        instance = new ResrcManager();
    }
    return *instance;
}

Texture2D& ResrcManager::getTexture(const std::string &name) {
    return textures[name];
}

Sound& ResrcManager::getSound(const std::string &name) {
    return sounds[name];
}

Music& ResrcManager::getMusic(const std::string &name) {
    return musics[name];
}

void ResrcManager::unloadResources() {
    unloadTextures();
    unloadSounds();
    unloadMusics();
}

Texture2D FlipTextureHorizontal(const Texture2D &texture) {
    Image image = LoadImageFromTexture(texture); // Load image from texture
    ImageFlipHorizontal(&image); // Flip the image horizontally
    Texture2D flippedTexture = LoadTextureFromImage(image); // Create a new texture from the flipped image
    UnloadImage(image); // Unload the image to free memory
    return flippedTexture;
}






