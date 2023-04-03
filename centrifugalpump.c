#include <stdio.h>

double centrifugalpump(double Q, double p, double SG, double Psg, double Pdg, double Pv) {
    double Psa = Psg + 1.03323; // suction pressure in kg/cm^2 absolute
    double Pda = Pdg + 1.03323; // discharge pressure in kg/cm^2 absolute
    double Pdiff = Pda - Psa; // differential pressure in kg/cm^2
    double density = SG * 1000; // density of fluid in kg/m^3
    double g = 9.81; // acceleration due to gravity in m/s^2
    double Diffhead = (Pdiff * 100000) / (density * g); // Differential head in m
    double phydraulic = (Pdiff * Q * 10) / 367; // hydraulic power in kilowatt
    double efficiency = (phydraulic * 100) / p; // efficiency of pump
    double NPSH = ((Psa - Pv) * 100000) / (density * g); // NPSH in m
    printf("Differential Pressure: %lf kg/cm2\n", Pdiff);
    printf("Hydraulic Power: %lf kW\n", phydraulic);
    printf("Efficiency: %lf%%\n", efficiency);
    printf("Differential head: %lf m\n", Diffhead);
    printf("NPSH: %lf m\n", NPSH);
    return Diffhead, phydraulic, efficiency, NPSH;
}

int main() {
    printf("Design efficiency of P10: ");
    centrifugalpump(200.4, 112.58, 0.52, 6.8, 19.8, 7.6);
    printf("\nNormal efficiency of P10: ");
    centrifugalpump(167, 112.58, 0.52, 6.8, 19.8, 7.6);
    printf("\nDesign efficiency of P202: ");
    centrifugalpump(266.1, 238, 0.61, 0.881, 22.981, 1.64);
    printf("\nNormal efficiency of P202: ");
    centrifugalpump(241, 238, 0.61, 0.881, 22.981, 1.64);
    return 0;
}