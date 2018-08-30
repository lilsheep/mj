#include <iostream>
#include "waver.h"
#include "WavGen.h"
#include <cmath>
#include <array>
#include <fstream>
#include <numeric>

#define RATE     8000   //Sample Rate
#define SEC      *2     //TODO: insert formula (dep. on bps & rate)
#define LENGTH   10 SEC //Sample Length
#define AMP_MAX  32767  
#define AMP      15000  //Amplitude = Volume of Sample
#define CHANNELS 2
#define BPS      16

float digitalizeFrequency (float freq, int sampleRate) {
    return freq / sampleRate;
}

int main () {
    std::fstream logFile("log.txt", std::ios::out);
    logFile.flush();
    float freq_c = 161.63;
    float freq_d_sh = 311.13;
    float freq_g = 392.0;
    float digitalFreq_c = digitalizeFrequency(freq_c, RATE);
    float digitalFreq_d_sh = digitalizeFrequency(freq_d_sh, RATE); 
    float digitalFreq_g = digitalizeFrequency(freq_g, RATE);
    int bufferSize = LENGTH * RATE; 
    double buf[bufferSize];
    double buf2[bufferSize];
    Waver osc;
    WavGenerator gen(CHANNELS, BPS); 
    int sineDot, sawDot, res;
    for (int i = 0; i < bufferSize; i++) {
        buf[i] = AMP * osc.Sine(i, digitalFreq_c);

        //logFile << buf[i] << std::endl;
    };
    gen.SaveWav(buf, bufferSize, RATE);
    return 0;
}  