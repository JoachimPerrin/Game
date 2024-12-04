#ifndef ANIMATION_HPP
#define ANIMATION_HPP

struct Animation
{
    int index;
    int frame;
    int speed;

    Animation();
    Animation(int i, int f, int s);
};

#endif