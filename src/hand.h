
#pragma once

#include <math.h>
#include <ofPoint.h>

//sane bounds for how fast a hand can travel
#define HAND_MAX_VX 0.1
#define HAND_MAX_VY 0.05


class Hand
{
public:
    ofPoint pos;
    ofPoint vel;
    ofPoint pixel_pos; //location of the hand in the cameras frame
    ofPoint pixel_intersection; //location of the hand in the center of the beam

    Hand() { };
    Hand(ofPoint _pos, ofPoint _pixel_pos, ofPoint _pixel_intersection)
    {
        pos = _pos;
        pixel_pos = _pixel_pos;
        pixel_intersection = _pixel_intersection;
    };

    void compute_velocity(Hand& old_hand)
    {
        vel = old_hand.pos - pos;
    };

    bool same_hand_as(Hand& other)
    {
        return (abs(pos.x - other.pos.x) <= HAND_MAX_VX &&
                abs(pos.y - other.pos.y) <= HAND_MAX_VY);
    };
};
