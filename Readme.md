motor.c
=======

Simple 6-pin step motor position controlling code for AVR MCUs.

Usage
=====

```c

#include "motor.h"
// .. other stuff

int main(void) {
	
	motor_setup();
	timer_setup(); // << 
	
	while (1) {
		motor_target += MOTOR_STEPS_PER_REV; // turn 1 round forward
		delay_ms(1000);
		motor_target -= MOTOR_STEPS_PER_REV; // turn 1 round backwards
		delay_ms(1000);
	}
	
}

SIG timer_interrupt {  // every 2miliseconds
	motor_step(); // this checks if it needs to move the motor, moves motor_pos != motor_target
}

```

License
=======
None. Use it. Linking back won't hurt though.
