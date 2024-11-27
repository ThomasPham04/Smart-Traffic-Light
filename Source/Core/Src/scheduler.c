/*
 * scheduler.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Phuc Le
 */

#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void){
	unsigned char Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++){
		SCH_Delete_Task(Index);
	}
}

void SCH_Update(){
	unsigned char Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++){
		if (SCH_tasks_G[Index].pTask){
			SCH_tasks_G[Index].Delay--;
			if (SCH_tasks_G[Index].Delay <= 0){
				SCH_tasks_G[Index].RunMe++;
				if (SCH_tasks_G[Index].Period){
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
		}
	}
}

unsigned char SCH_Add_Task (void (* pFunction) (), unsigned int DELAY, unsigned int PERIOD){
	unsigned char Index;
	while ()
}

void SCH_Dispatch_Tasks(void){

}

unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX){

}
