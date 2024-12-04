#include "Animation.hpp"

Animation::Animation()
    : index(0), frame(1), speed(100)
{}

Animation::Animation(int i, int f, int s)
    : index(i), frame(f), speed(s)
{}
