#include <iostream>
#include <fstream>
#include <cmath>
#include <array>

using namespace std;

double * diffeq(double P[], double t) {
	double dPdtP[4]; 
	double TD[3] = { 4.0, 8.0, 4.0 };
	dPdtP[0] = -((P[0] * P[1]) / TD[0]);
	dPdtP[1] = +((P[0] * P[1]) / TD[0]) - (P[1] / TD[1]) - (P[1] / TD[2]);
	dPdtP[2] = +((P[1]) / TD[1]);
	dPdtP[3] = +((P[1]) / TD[2]);
	return dPdtP;
}
int main() {
	double P[4] = { .98, .02, 0.0, 0.0 };
	double K1[4] = { 0.0 };
	double K2[4] = { 0.0 };
	double K3[4] = { 0.0 };
	double K4[4] = { 0.0 };
	double dt = .01;
	double t;
	t = 0;
	//double *k = diffeq(P, T);
	double K1[4] = { (*diffeq(P, t )) * dt };
	double K2[4] = { (*diffeq((P + K1[4]) / 2, (t + dt / 2) * dt))};
	double K3[4] = {(*diffeq((P + K2[4]) / 2, (t + dt) / 2)) * dt};
	double K4[4] = { (*diffeq(P + K3[4], t + dt)) * dt };
	P[4] = P[4] + (1 / 6) * (K1[4] + 2 * K2[4] + 2 * K3[4] + K4[4]);
	return 0;
}

