#ifndef _WAVGEN_H_
#define _WAVGEN_H_

#include <fstream>
#include <iterator>
#include <algorithm>
#include <array>

class WavGenerator {
private:
    int channelNum = 2; 
    int bps        = 32;//bits per sample 

public:
WavGenerator(int channels, int bitsPerSample );
void SaveWav (double data[], int dataLength, int rate);
};



#endif