/**
 * @file Animation.hpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the Animation struct.
 * @version 0.1
 * @date 2025-02-24
 *
 * @copyright Copyright (c) 2025
 *
 */
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