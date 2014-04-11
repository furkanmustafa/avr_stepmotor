/*
 * motor.c
 *
 *  Created on: Apr 9, 2014
 *      Author: furkanmustafa
 */

#include "motor.h"

volatile int32_t motor_pos = 0;
volatile int32_t motor_target = 0;

volatile uint8_t current_seq = 0;
volatile char was_moving = 0;

#if TOTAL_SEQUENCES == 4
char motor_seq[4] = { MOTOR_PORT_SEQ1, MOTOR_PORT_SEQ2, MOTOR_PORT_SEQ3, MOTOR_PORT_SEQ4 };
#elif TOTAL_SEQUENCES == 8
char motor_seq[8] = {
	MOTOR_PORT_SEQ1, MOTOR_PORT_SEQ2, MOTOR_PORT_SEQ3, MOTOR_PORT_SEQ4,
	MOTOR_PORT_SEQ5, MOTOR_PORT_SEQ7, MOTOR_PORT_SEQ7, MOTOR_PORT_SEQ8
};
#endif

void motor_setup() {
	// Set pins as output
	MOTOR_PORTR |= MOTOR_PORT_MASK;
	// Clear outputs
	MOTOR_PORT &= ~MOTOR_PORT_MASK;
}
void motor_step() {
	// No need to move anything
	if (motor_pos == motor_target) {
		// Clear outputs if necessary
		if (was_moving) {
			MOTOR_PORT &= ~MOTOR_PORT_MASK;
			was_moving = 0;
		}
		return;
	}
	// Backwards
	if (motor_pos > motor_target) {
		if (current_seq == 0)
			current_seq = TOTAL_SEQUENCES;
		current_seq--;
		
		MOTOR_PORT = (MOTOR_PORT & ~MOTOR_PORT_MASK) | motor_seq[current_seq];
		
		motor_pos--;
		was_moving = 1;
	} else 
	
	// Forward
	if (motor_pos < motor_target) {
		current_seq++;
		if (current_seq == TOTAL_SEQUENCES)
			current_seq = 0;
		
		MOTOR_PORT = (MOTOR_PORT & ~MOTOR_PORT_MASK) | motor_seq[current_seq];
		
		motor_pos++;
		was_moving = 1;
	}
}
