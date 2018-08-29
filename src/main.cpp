#include <iostream>
#include "waver.h"
#include "WavGen.h"
#include <cmath>
#include <array>

#define RATE 8000 //Sample Rate
#define SEC 10 //Sample Length
#define AMP 32767 //Amplitude = Volume of Sample

int main () {
    float freq = 1.0;

    float approxFreq = 2 * M_PI * freq / RATE;
    //float freq = 260; //middle C
    int bufferSize = SEC * RATE;
    double buf[bufferSize];
    Waver osc;
    WavGenerator gen(2, 32);
    for (int i = 0; i < bufferSize; i++) {
        buf[i] = AMP * osc.Triangle(i, approxFreq);
        if (i < bufferSize / 2)approxFreq += 0.000001;
        else                   approxFreq -= 0.000001;
    };
    std::cout << buf[bufferSize];
    gen.SaveWav(buf, bufferSize, RATE);
    return 0;
}  