#include <iostream>
#include "waver.h"
#include "WavGen.h"
#include <cmath>
#include <array>

#define RATE 8000 //Sample Rate
#define SEC 5 //Sample Length
#define AMP 75 //Amplitude = Volume of Sample

int main () {
    //float freq = 2 * M_PI * SEC / RATE;
    float freq = 261.626; //middle C
    int bufferSize = SEC * RATE;
    double buf[bufferSize];
    Waver osc;
    WavGenerator gen;
    for (int i = 0; i < bufferSize; i++) {
        buf[i] = AMP * osc.Sine(i, freq);
    };
    gen.SaveWav(buf, bufferSize, RATE);
    return 0;
}