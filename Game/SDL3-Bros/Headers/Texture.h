#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <string>

// Texture wrapper. Reuse for sprites
class Texture
{
public:
  Texture();
  ~Texture();
  bool createTextTexture(const std::string& textureText);
  bool loadFromFile(const std::string& path);
  // Draws texture
  void render(float x, float y, const SDL_FRect* clip = nullptr) const;
  void destroy();
  int getHeight() const;
  int getWidth() const;

private:
  SDL_Texture* texture_;
  int width_;
  int height_;
};

#endif
