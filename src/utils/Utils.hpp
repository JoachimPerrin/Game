#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

void ExitWithError(const std::string errorMessage, SDL_Window *activeWindow = nullptr, SDL_Renderer *activeRenderer = nullptr);

std::ostream &operator<<(std::ostream &stream, const SDL_Rect &rect);
std::ostream &operator<<(std::ostream &stream, const SDL_FRect &rect);

SDL_Rect FRectToRect(const SDL_FRect &fRect);

#endif