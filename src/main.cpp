#include <iostream>
#include "waver.h"
#include "WavGen.h"
#include <cmath>
#include <array>
#include <fstream>

#define RATE     8000   //Sample Rate
#define SEC      *2     //TODO: insert formula (dep. on bps & rate)
#define LENGTH   10 SEC //Sample Length
#define AMP_MAX  32767  
#define AMP      15000  //Amplitude = Volume of Sample
#define CHANNELS 2
#define BPS      16

int main () {
    std::fstream logFile("log.txt", std::ios::out);
    logFile.flush();
    float freq = 262.0;
    float digitalFreq = freq / RATE; //makes analogue freq digital
    int bufferSize = LENGTH * RATE; 
    double buf[bufferSize];
    Waver osc;
    WavGenerator gen(CHANNELS, BPS); 
    for (int i = 0; i < bufferSize; i++) {
        buf[i] = AMP * osc.Saw(i, digitalFreq);
        logFile << buf[i] << std::endl;
    };
    gen.SaveWav(buf, bufferSize, RATE);
    return 0;
}  