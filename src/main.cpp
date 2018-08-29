#include <iostream>
#include "waver.h"
#include "WavGen.h"
#include <cmath>
#include <array>

#define RATE 8000  //Sample Rate
#define SEC  10    //Sample Length
#define AMP  32767 //Amplitude = Volume of Sample
#define CHANNELS 2
#define BPS 32

int main () {
    float freq = 1.0;
    float approxFreq = 2 * M_PI * freq / RATE; //makes our frequency compatible
                                               //better move this to waver
    int bufferSize = SEC * RATE; 
    double buf[bufferSize];
    Waver osc;
    WavGenerator gen(CHANNELS, BPS); 
    for (int i = 0; i < bufferSize; i++) {
        buf[i] = AMP * osc.Sine(i, approxFreq);
    };

    gen.SaveWav(buf, bufferSize, RATE);
    return 0;
}  