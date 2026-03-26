#include "Texture.h"
#include "../Headers/Globals.h"
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

Texture::Texture() : texture_{nullptr}, width_{0}, height_{0} {}

Texture::~Texture()
{
    destroy();
}

void Texture::destroy()
{
    SDL_DestroyTexture(texture_);
    texture_ = nullptr;
    width_ = 0;
    height_ = 0;
}

bool Texture::createTextTexture(const std::string& textureText)
{
    destroy();
    constexpr SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Blended(font, textureText.c_str(), textureText.size(), textColor);
    if (surface == nullptr)
    {
        SDL_Log("loadFromRenderedText: surface is null");
        return false;
    }

    texture_ = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture_ == nullptr)
    {
        SDL_Log("loadFromRenderedText: texture null");
        return false;
    }

    width_ = surface->w;
    height_ = surface->h;

    SDL_DestroySurface(surface);
    return true;
}

bool Texture::loadFromFile(const std::string& path)
{
    destroy();

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface)
    {
        SDL_Log("loadFromFile: surface is null");
        return false;
    }

    texture_ = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture_)
    {
        SDL_Log("loadFromFile: surface is null");
        return false;
    }

    width_ = surface->w;

    height_ = surface->h;

    SDL_DestroySurface(surface);
    return true;
}

void Texture::render(const float x, const float y, const SDL_FRect* clip) const
{
    // Set texture position
    SDL_FRect dstRect{x, y, static_cast<float>(width_), static_cast<float>(height_)};

    if (clip != nullptr)
    {
        dstRect.w = clip->w;
        dstRect.h = clip->h;
    }

    // Render texture
    SDL_RenderTexture(renderer, this->texture_, clip, &dstRect);
}

int Texture::getHeight() const
{
    return height_;
}

int Texture::getWidth() const
{
    return width_;
}
