#include <iostream>
#include <cmath>
using namespace std;

// Example: L = T - V = (1/2)*m*x_dot^2 - m*g*x

double L(double x, double xdot, double m, double g) {
    return 0.5 * m * xdot * xdot - m * g * x;
}

int main() {
    double m = 1.0;   // mass
    double g = 9.81;  // gravity
    double x = 1.0;   // position
    double xdot = 2.0; // velocity
    double dt = 0.001; // small time step

    // Partial derivatives (approximation)
    double dL_dx  = (L(x+dt, xdot, m, g) - L(x-dt, xdot, m, g)) / (2*dt);
    double dL_dxdot_plus  = (L(x, xdot+dt, m, g) - L(x, xdot-dt, m, g)) / (2*dt);
    double d_dt_dL_dxdot = (dL_dxdot_plus - dL_dxdot_plus) / dt; // ~0 for constant velocity

    double euler_lagrange = d_dt_dL_dxdot - dL_dx;

    cout << "Euler-Lagrange result: " << euler_lagrange << endl;
    cout << "(If ~0 → equation satisfied)" << endl;

    return 0;
}

