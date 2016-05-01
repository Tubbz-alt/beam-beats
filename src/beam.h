
#pragma once

#include "ofxOpenCv.h" //ofxCvBlob
#include "ofxMidi.h"
#include "settings.h"
#include "hand.h"

#define sizeof_array(a) (sizeof(a)/sizeof(a[0]))

const int midi_velocities[] = { 32, 64, 96, 127 };
const int midi_scale[] = { 0, 3, 5, 7, 10, 12 }; //pentatonic


class BeamRegion
{
public:
    bool status = false;
    uint64_t time;
    Hand hand;
};


class Beam
{
public:
    Beam(int channel, int base_note, int color);
    void update(vector<Hand> hands, ofxMidiOut& midi_out);
    void draw(vector<Hand> hands, int width);

    const int base_note;
    const int channel;
    const int color;
private:

    //table of region statuses
    BeamRegion regions[sizeof_array(midi_scale)];

    size_t hand_to_region(Hand& hand);
    int region_to_note(size_t region);
    size_t speed_to_midi_velocity(float speed);
};
