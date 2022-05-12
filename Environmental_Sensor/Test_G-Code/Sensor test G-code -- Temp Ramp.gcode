G28
G90									;	Use absolute coordinates
G0 x175 y175 z100 f3600						;	Move to center of bed, z=100mm
SET_FAN_SPEED FAN=nevermore SPEED=0					;	Set Nevermore to 0%
M106 S255 								;	Set PCF to 100%
G4 P600000								;	wait for 10 minutes
M140 S50								;	heat Bed to 50 deg
G4 P1800000								;	wait for 30 minutes
M140 S60								;	heat Bed to 60 deg
G4 P1800000								;	wait for 30 minutes
M140 S70								;	heat bed to 70 deg
G4 P1800000								;	wait for 30 minutes
M140 S80								;	heat bed to 80 deg
G4 P1800000								;	wait for 30 minutes
M140 S90								;	heat bed to 90 deg
G4 P1800000								;	wait for 30 minutes
M140 S100								;	heat bed to 100 deg
G4 P1800000								;	wait for 30 minutes
M140 S110								;	heat bed to 110 deg
G4 P3600000								;	wait for 60 minutes
SET_FAN_SPEED FAN=nevermore SPEED=1					;	Set Nevermore to 100%
G4 P3600000								;	wait for 60 minutes
SET_FAN_SPEED FAN=nevermore SPEED=0					;	Set Nevermore to 100%
G4 P3600000								;	wait for 60 minutes
END_PRINT
