#include <iostream>
#include <fstream>
using namespace std;

int main() {
    double m = 1.0;    // mass (kg)
    double g = 9.81;   // gravity (m/s^2)
    double x = 10.0;   // initial position (m)
    double v = 0.0;    // initial velocity (m/s)
    double dt = 0.01;  // time step (s)
    double tmax = 2.0; // total time (s)

    ofstream file("motion.txt");
    file << "t\tx\tv\n";

    for (double t = 0; t <= tmax; t += dt) {
        double a = -g;          // from Euler-Lagrange => acceleration
        v += a * dt;            // update velocity
        x += v * dt;            // update position
        file << t << "\t" << x << "\t" << v << "\n";
    }

    file.close();
    cout << "Simulation complete. Data saved to motion.txt\n";
    return 0;
}

