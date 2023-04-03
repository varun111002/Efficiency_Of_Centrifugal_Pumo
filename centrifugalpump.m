function [Diffhead, phydraulic, efficiency, NPSH] = centrifugalpump(Q, p, SG, Psg, Pdg, Pv)
    % Q = massflowrate in m^3/hr
    % input Power in kilowatt
    % specific gravity of fluid
    % suction pressure in kg/cm^2 gauge
    % discharge pressure in kg/cm^2 gauge
    Psa = Psg + 1.03323; % suction pressure in kg/cm^2 absolute
    Pda = Pdg + 1.03323; % discharge pressure in kg/cm^2 absolute
    % vapour pressure in kg/cm^2 absolute
    Pdiff = Pda - Psa; % differential pressure in kg/cm^2
    density = SG * 1000; % density of fluid in kg/m^3
    g = 9.81; % acceleration due to gravity in m/s^2
    Diffhead = (Pdiff * 100000) / (density * g); % Differential head in m
    phydraulic = (Pdiff * Q * 10) / 367; % hydraulic power in kilowatt
    efficiency = (phydraulic * 100) / p; % efficiency of pump
    NPSH = ((Psa - Pv) * 100000) / (density * g); % NPSH in m
    fprintf('Differential Pressure: %f kg/cm2\n', Pdiff);
    fprintf('Hydraulic Power: %f kW\n', phydraulic);
    fprintf('Efficiency: %f%%\n', efficiency);
    fprintf('Differential head: %f m\n', Diffhead);
    fprintf('NPSH: %f m\n', NPSH);
    [ ~, ~, ~, ~] = centrifugalpump(200.4, 112.58, 0.52, 6.8, 19.8, 7.6);
end