#include <stdlib.h>
#include <stdio.h>

int update_hare(int current_position)
{
    // generates a number between 0 and 1
    float val = ((float)rand() / (float)(RAND_MAX));
    // check every possible outcome
    if (current_position < 0)
    {
        current_position = 0;
    }
    if((0 <= val) && (val < .25)){
        current_position += 0;
    }
    else if ((0.25 <= val) && (val < 0.45))
    {
        current_position += 9;
    }
    else if ((0.45 <= val) && (val < 0.55))
    {
        current_position -= 10;
    }
    else if ((0.55 <= val) && (val < 0.8))
    {
        current_position += 2;
    }
    else if ((0.8 <= val) && (val < 1))
    {
        current_position -= 3;
    }
    // if the current position is less than zero, rest it to zero
    if (current_position < 0)
    {
        current_position = 0;
    }
    return current_position;
}

int update_tortoise(int current_position)
{
    if (current_position < 0)
    {
        current_position = 0;
    }
    // generates a number between 0 and 1
    float val = ((float)rand() / (float)(RAND_MAX));
    // check every possible outcome
    if ((0 <= val) && (val < 0.45))
    {
        current_position += 3;
    }
    else if ((0.45 <= val) && (val < 0.65))
    {
        current_position -= 5;
    }
    else if ((0.65 <= val) && (val < 1))
    {
        current_position += 1;
    }
    // check if the current position is less than zero, if it is,
    // reset it to zero
    if (current_position < 0)
    {
        current_position = 0;
    }
    
    // return the current position
    return current_position;
}

int update_bee(int current_position)
{
    float val = ((float)rand() / (float)(RAND_MAX));
    // check every possible outcome
    if (current_position < 0)
    {
        current_position = 0;
    }
    if ((0 <= val) && (val < 0.30))
    {
        current_position += 2;
    }
    else if ((0.30 <= val) && (val < 0.50))
    {
        current_position += 1;
    }
    // check if the current position is less than zero, if it is,
    // reset it to zero
    if (current_position < 0)
    {
        current_position = 0;
    }
    // return the current position
    return current_position;
}