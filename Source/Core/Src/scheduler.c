/*
 * scheduler.c
 *
 *  Created on: Nov 20, 2024
 *      Author: Admin
 */

#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
//unsigned char Error_code_G = 0;

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
	return Return_code;	// return status
}

void SCH_Init(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
	// Reset the global error variable
	// - SCH_Delete_Task() will generate an error code,
	// (because the task array is empty)
	//Error_code_G = 0;
	//Timer_init();
	//Watchdog_init();
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
//
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
//			HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "Task %d is dispatched at %d: Runme = %d\r\n", Index, time_stamp, SCH_tasks_G[Index].RunMe), 1000);
		}
	}
	// Report system status
	//SCH_Report_Status();
	// The scheduler enters idle mode at this point
	//SCH_Go_To_Sleep();
}

/*
void SCH_Go_To_Sleep() {
	// TO DO: Optional
}

void SCH_Report_Status(void) {
#ifdef SCH_REPORT_ERRORS
	// ONLY APPLIES IF WE ARE REPORTING ERRORS
	// Check for a new error code
	if (Error_code_G != Last_error_code_G)) {
		Error_port = 255 - Error_code_G;
		if (Error_code_G != 0) {
			Error_tick_count_G = 60000;
		} else {
			Error_tick_count_G = 0;
		}
	} else {
		if (Error_tick_count_G != 0) {
			if (--Error_tick_count_G == 0) {
				Error_code_G = 0;	// Reset error code
			}
		}
	}
#endif
}
*/
