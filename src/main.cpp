#include <iostream>
#include "waver.h"
#include "WavGen.h"
#include <cmath>
#include <array>

#define RATE 8000
#define SEC 5
#define VOL 320000

int main () {
    float freq = M_PI * 2 * 2.0 / RATE;
    std::cout << freq << std::endl;
    int bufferSize = SEC * RATE;
    std::cout << bufferSize << std::endl; 
    double buf[bufferSize];
    Waver osc;
    WavGenerator gen;
    for (int i = 0; i < bufferSize; i++) {
        buf[i] = VOL * osc.Sine(i, freq);
    };
    gen.SaveWav(buf, bufferSize, RATE);
    return 0;
}