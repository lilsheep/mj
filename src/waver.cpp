#include "waver.h"

double Waver::Sine (int index, double freq){
    return sin(freq * index);
};
double Waver::Saw (int index, double freq) {
    return 2.0 * (index * freq - floor(index * freq)) -1.0;
};
double Waver::Triangle (int index, double freq) {
    return 2.0 * std::abs (2.0 * (index * freq - floor(index * freq + 0.5))) - 1.0;
};
double Waver::Square (int index, double freq) {
    if (sin(freq * index ) > 0) return 1;
	else return -1;
};

