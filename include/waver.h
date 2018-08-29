#ifndef _WAVER_H_
#define _WAVER_H_

#include <cmath>
//Basic interface for oscillation 
class Waver {
private:

public:

double Sine (int index, double freq);
double Saw (int index, double freq);
double Triangle (int index, double freq);
double Square (int index, double freq);

};



#endif