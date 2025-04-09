/*
 * scheduler.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Admin
 */

#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

#include "stdint.h"
#include "main.h"
#include "global.h"

#define SCH_MAX_TASKS		10
#define NO_TASK_ID			0

#define TICKS				10

typedef struct {
	void (* pTask)(void);
	int32_t Delay;
	int32_t Period;
	int8_t RunMe;
	uint32_t TaskID;
} sTask;

extern sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void);
void SCH_Update(void);
unsigned char SCH_Add_Task(void (* pFunction) (), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */
