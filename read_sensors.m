function [zIR,zSonar,zMag,IR_raw] = read_sensors()
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
s1 = get_param('qbot2/IR', 'RuntimeObject');
zIR= s1.InputPort(1).Data;
zIR(zIR<=0.2)=0.2;
%
s1 = get_param('qbot2/Sonar', 'RuntimeObject');
zSonar= s1.InputPort(1).Data;
zSonar(zSonar<=0.1524)=0.1524;
%
s1 = get_param('qbot2/mag', 'RuntimeObject');
zMag=s1.InputPort(1).Data;

s1 = get_param('qbot2/IR1', 'RuntimeObject');
IR_raw= s1.InputPort(1).Data;

end

