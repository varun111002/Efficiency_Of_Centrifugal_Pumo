def centrifugalpump(Q, p, SG, Psg, Pdg, Pv):
    #Q = massflowrate in m^3/hr
    #imput Power in kilowatt
    #specific gravity of fluid
    #suction pressure in kg/cm^2 gauge
    #discharge pressure in kg/cm^2 gauge
    Psa = Psg+1.03323 #suction pressure in kg/cm^2 absolute
    Pda = Pdg+1.03323 #discharge pressure in kg/cm^2 absolut
    #vapour pressure in kg/cm^2 absolute
    Pdiff = Pda-Psa # differential pressure in kg/cm^2
    density = SG*1000 # desnsity of fluid in kg/m^3
    g = 9.81 # accleration due to gravity in m/s^2
    Diffhead = (Pdiff*100000)/(density*g) # Differential head in m
    phydraulic = (Pdiff*Q*10)/367 #hydraulic power in kilowatt # = (Diffhead*Q*SG*g)/3670
    efficiency = (phydraulic*100)/p # efficiency of pump
    NPSH = ((Psa-Pv)*100000)/(density*g) # NPSH in m
    print("Differential Pressure:",Pdiff,"kg/cm2" )
    print("Hydraulic Power:",phydraulic,"kW" )
    print("Efficiency:",efficiency,"%" )
    print("Differential head:",Diffhead,"m")
    print("NPSH:",NPSH,"m")
    return Diffhead, phydraulic, efficiency, NPSH
print("Design efficiency of P10", centrifugalpump(200.4, 112.58, 0.52, 6.8, 19.8, 7.6))
print("Normal efficiency of P10", centrifugalpump(167, 112.58, 0.52, 6.8, 19.8, 7.6))
print("Design efficiency of P202", centrifugalpump(266.1, 238, 0.61, 0.881, 22.981, 1.64))
print("Design efficiency of P202", centrifugalpump(241, 238, 0.61, 0.881, 22.981, 1.64))