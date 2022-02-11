// Physics Pandemic project v1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    double P1 = 0.98;
    double P2 = 1.0-P1;
    double P3 = 0;
    double P4 = 0;
    double R = .90;
    double T1 = 4.0;
    double T2 = 10.0;
    double dt = 0.1;
    double t = 0;
    int Nt = 1000;
    double dP1dt = 0;
    double dP2dt = 0;
    double dP3dt = 0;
    double dP4dt = 0;
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    //ofstream out;
    std::ofstream out ("C:\\Users\\cochr\\Desktop\\Data For Model.txt");
    for (int n = 1; n <= 1000000;  n++) {
        dP1dt = -(P1 * P2) / T1;
        dP2dt = +(P1 * P2) / T1  - (P2 / T2);
        dP3dt = (P2 / T2) * R;
        dP4dt = (P2 / T2) * (1-R);
        
        t = t + dt;

        P1 = P1 + dP1dt * dt;
        P2 = P2 + dP2dt * dt;
        P3 = P3 + dP3dt * dt;
        P4 = P4 + dP4dt * dt;

        if (n % 10 == 0) {
            out << " Trial # " << n
                << "\n Time = " << t
                << "\n " << fixed << setprecision(4) << P1 * 100 << " % of the population is healthy."
                << "\n " << fixed << setprecision(4) << P2 * 100 << " % of the population is sick."
                << "\n " << fixed << setprecision(4) << P3 * 100 << " % of the population is recovered."
                << "\n " << fixed << setprecision(4) << P4 * 100 << " % of the population has died." //<< fixed << setprecision(5) might use for rounding if needed
                << "\n Total population is equal to " << (P1 + P2 + P3 + P4) * 100 << " %"
                << "\n\n";
            }

    }
    out.close(); 
    return 0;
}