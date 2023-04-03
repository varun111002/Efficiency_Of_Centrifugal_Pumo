public class CentrifugalPump {
    public static void main(String[] args) {
        System.out.println("Design efficiency of P10 " + centrifugalpump(200.4, 112.58, 0.52, 6.8, 19.8, 7.6));
        System.out.println("Normal efficiency of P10 " + centrifugalpump(167, 112.58, 0.52, 6.8, 19.8, 7.6));
        System.out.println("Design efficiency of P202 " + centrifugalpump(266.1, 238, 0.61, 0.881, 22.981, 1.64));
    System.out.println("Design efficiency of P202 " + centrifugalpump(241, 238, 0.61, 0.881, 22.981, 1.64));
}

public static double[] centrifugalpump(double Q, double p, double SG, double Psg, double Pdg, double Pv) {
    double Psa = Psg + 1.03323; //suction pressure in kg/cm^2 absolute
    double Pda = Pdg + 1.03323; //discharge pressure in kg/cm^2 absolute
    double Pdiff = Pda - Psa; //differential pressure in kg/cm^2
    double density = SG * 1000; //density of fluid in kg/m^3
    double g = 9.81; //acceleration due to gravity in m/s^2
    double Diffhead = (Pdiff * 100000) / (density * g); //differential head in m
    double phydraulic = (Pdiff * Q * 10) / 367; //hydraulic power in kilowatt # = (Diffhead*Q*SG*g)/3670
    double efficiency = (phydraulic * 100) / p; //efficiency of pump
    double NPSH = ((Psa - Pv) * 100000) / (density * g); //NPSH in m

    System.out.println("Differential Pressure: " + Pdiff + " kg/cm2");
    System.out.println("Hydraulic Power: " + phydraulic + " kW");
    System.out.println("Efficiency: " + efficiency + "%");
    System.out.println("Differential head: " + Diffhead + " m");
    System.out.println("NPSH: " + NPSH + " m");

    return new double[] {Diffhead, phydraulic, efficiency, NPSH};
}
}