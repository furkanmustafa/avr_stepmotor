/*
 * motor.h
 *
 *  Created on: Apr 9, 2014
 *      Author: furkanmustafa
 */

#ifndef MOTOR_H_
#define MOTOR_H_

void motor_setup();
void motor_step();

#define MOTOR_PORTR	DDRC
#define MOTOR_PORT	PORTC
#define MOTOR_A		3
#define MOTOR_B		2
#define MOTOR_C		1
#define MOTOR_D		0
#define MOTOR_PORT_MASK				((1<<MOTOR_A) | (1<<MOTOR_B) | (1<<MOTOR_C) | (1<<MOTOR_D))

#define TOTAL_SEQUENCES		4		// 4 = powerful | 8 = gentle, can also do half steps probably?

#if TOTAL_SEQUENCES == 4

#define MOTOR_STEPS_PER_REV			200
#define MOTOR_CALL_INTERVAL_MS		2		// means calling motor_step() every 2miliseconds

#define MOTOR_PORT_SEQ1				((1<<MOTOR_A) | (1<<MOTOR_D))
#define MOTOR_PORT_SEQ2				((1<<MOTOR_B) | (1<<MOTOR_D))
#define MOTOR_PORT_SEQ3				((1<<MOTOR_B) | (1<<MOTOR_C))
#define MOTOR_PORT_SEQ4				((1<<MOTOR_A) | (1<<MOTOR_C))

#elif TOTAL_SEQUENCES == 8

#define MOTOR_STEPS_PER_REV			400
#define MOTOR_CALL_INTERVAL_MS		1		// means calling motor_step() every 2miliseconds

#define MOTOR_PORT_SEQ1				(1<<MOTOR_A)
#define MOTOR_PORT_SEQ2				((1<<MOTOR_A) | (1<<MOTOR_D))
#define MOTOR_PORT_SEQ3				((1<<MOTOR_D))
#define MOTOR_PORT_SEQ4				((1<<MOTOR_B) | (1<<MOTOR_D))
#define MOTOR_PORT_SEQ5				((1<<MOTOR_B))
#define MOTOR_PORT_SEQ6				((1<<MOTOR_B) | (1<<MOTOR_C))
#define MOTOR_PORT_SEQ7				((1<<MOTOR_C))
#define MOTOR_PORT_SEQ8				((1<<MOTOR_A) | (1<<MOTOR_C))

#endif

extern volatile int32_t motor_pos;
extern volatile int32_t motor_target;

#endif /* MOTOR_H_ */
