/*
 * scheduler.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Admin
 */

#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];


void SCH_Init(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
}

void SCH_Update(void) {
	unsigned char Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].pTask) {
			SCH_tasks_G[Index].Delay -= 1;
			if (SCH_tasks_G[Index].Delay <= 0) {
				SCH_tasks_G[Index].RunMe += 1;
				if (SCH_tasks_G[Index].Period) {
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
		}
	}
}

unsigned char SCH_Add_Task(void (* pFunction) (), unsigned int DELAY, unsigned int PERIOD) {
	unsigned char Index = 0;
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
		Index++;
	}
	if (Index == SCH_MAX_TASKS) {
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY / TICKS;
	SCH_tasks_G[Index].Period = PERIOD / TICKS;
	SCH_tasks_G[Index].RunMe = 0;
	return Index;
}

unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX) {
	unsigned char Return_code = 0;
	if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
			Return_code = 1;
	} else {
		Return_code = 0;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	return Return_code;
}

void SCH_Dispatch_Tasks(void) {
	unsigned char Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (!(SCH_tasks_G[Index].pTask)) continue;
		if (SCH_tasks_G[Index].RunMe > 0) {
			(* SCH_tasks_G[Index].pTask)();
			SCH_tasks_G[Index].RunMe -= 1;
			if (SCH_tasks_G[Index].Period == 0) {
				SCH_Delete_Task(Index);
			}
		}
	}
}
