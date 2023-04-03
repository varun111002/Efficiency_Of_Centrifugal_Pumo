#include<iostream>
#include<cmath>

using namespace std;

struct PumpOutput {
    double differentialPressure;
    double hydraulicPower;
    double efficiency;
    double NPSH;
};

PumpOutput centrifugalpump(double Q, double p, double SG, double Psg, double Pdg, double Pv) {
    PumpOutput output;
    //Q = massflowrate in m^3/hr
    //imput Power in kilowatt
    //specific gravity of fluid
    //suction pressure in kg/cm^2 gauge
    //discharge pressure in kg/cm^2 gauge
    double Psa = Psg+1.03323; //suction pressure in kg/cm^2 absolute
    double Pda = Pdg+1.03323; //discharge pressure in kg/cm^2 absolute
    //vapour pressure in kg/cm^2 absolute
    double Pdiff = Pda-Psa; // differential pressure in kg/cm^2
    double density = SG*1000; // desnsity of fluid in kg/m^3
    double g = 9.81; // accleration due to gravity in m/s^2
    double Diffhead = (Pdiff*100000)/(density*g); // Differential head in m
    double phydraulic = (Pdiff*Q*10)/367; //hydraulic power in kilowatt # = (Diffhead*Q*SG*g)/3670
    double efficiency = (phydraulic*100)/p; // efficiency of pump
    double NPSH = ((Psa-Pv)*100000)/(density*g); // NPSH in m
    output.differentialPressure = Pdiff;
    output.hydraulicPower = phydraulic;
    output.efficiency = efficiency;
    output.NPSH = NPSH;
    return output;
}

int main() {
    PumpOutput output1 = centrifugalpump(200.4, 112.58, 0.52, 6.8, 19.8, 7.6);
    cout << "Design efficiency of P10:" << endl;
    cout << "Differential Pressure: " << output1.differentialPressure << " kg/cm2" << endl;
    cout << "Hydraulic Power: " << output1.hydraulicPower << " kW" << endl;
    cout << "Efficiency: " << output1.efficiency << "%" << endl;
    cout << "Differential head: " << output1.NPSH << " m" << endl;
    cout << "NPSH: " << output1.NPSH << " m" << endl << endl;

    PumpOutput output2 = centrifugalpump(167, 112.58, 0.52, 6.8, 19.8, 7.6);
    cout << "Normal efficiency of P10:" << endl;
    cout << "Differential Pressure: " << output2.differentialPressure << " kg/cm2" << endl;
    cout << "Hydraulic Power: " << output2.hydraulicPower << " kW" << endl;
    cout << "Efficiency: " << output2.efficiency << "%" << endl;
    cout << "Differential head: " << output2.NPSH << " m" << endl;
    cout << "NPSH: " << output2.NPSH << " m" << endl << endl;

        return 0;
}