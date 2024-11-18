/*
 * scheduler.h
 *
 *  Created on: Nov 18, 2024
 *      Author: Admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct{
	void (*pTask) (void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t 	RunMe;

	uint32_t	TaskID;
}sTasks;

#define SCH_MAX_TASKS 40

void SCH_Init (void);

// giong nhu set timer nhung lan nay ta co con tro lam delay va period
void SCH_Add_Task (	void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void); // giong timerRun

void SCH_Dispatch_Tasks(void); //kiem tra timerFlag

void SCH_Delete_Task (uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
