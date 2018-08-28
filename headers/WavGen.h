#ifndef _WAVGEN_H_
#define _WAVGEN_H_

#include <fstream>
#include <iterator>
#include <algorithm>
#include <array>

class WavGenerator {
private:
    short frameSize = (short)(16/8);
public:
void SaveWav (double data[], int dataLength, int rate);


};



#endif