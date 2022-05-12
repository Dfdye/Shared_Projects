G28
G90					;	Use absolute coordinates
G0 x125 y125 z100 f3600					;	Move to center of bed, z=100mm
SET_FAN_SPEED FAN=nevermore SPEED=0		;	Set Nevermore to 0%
M106 S255 			;	Set PCF to 100%
g4 P600000			;	wait for 10 minutes
M140 S80			;	heat Bed to 100 deg
g4 P3600000			;	wait for 60 minutes
SET_FAN_SPEED FAN=nevermore SPEED=1		;	Set Nevermore to 100%
g4 P1800000			;	wait for 30 minutes
SET_FAN_SPEED FAN=nevermore SPEED=0		;	Set Nevermore to 0%
g4 P1800000			;	wait for 30 minutes
SET_FAN_SPEED FAN=nevermore SPEED=1		;	Set Nevermore to 100%
g4 P1800000			;	wait for 30 minutes
SET_FAN_SPEED FAN=nevermore SPEED=0		;	Set Nevermore to 0%
g4 P3600000			;	wait for 60 minutes
END_PRINT
