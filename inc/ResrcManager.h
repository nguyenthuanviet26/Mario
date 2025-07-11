#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>

class ResrcManager { // using Singleton Pattern
    private:
        ResrcManager() = default;
        ~ResrcManager();

        static ResrcManager* instance; // Singleton instance

        std::unordered_map<std::string, Texture2D> textures;
        std::unordered_map<std::string, Sound> sounds;
        std::unordered_map<std::string, Music> musics;

        void loadTextures();
        void loadSounds();
        void loadMusics();
        void unloadTextures();
        void unloadSounds();
        void unloadMusics();
    public:
        static ResrcManager &GetInstance(); // Singleton instance generator

        void loadResources();
        void unloadResources();

        // Getters

        Texture2D &getTexture(const std::string &name) ; 
        Sound &getSound(const std::string &name) ;
        Music &getMusic(const std::string &name) ;

};

// Utility function declaration
Texture2D FlipTextureHorizontal(const Texture2D &texture);


