/*
 * scheduler.c
 *
 *  Created on: Nov 18, 2024
 *      Author: Admin
 */

/*
 This set of parameters causes the function Do_X() to be executed once after 1,000 scheduler ticks:
SCH_Add_Task(Do_X,1000,0);
This does the same, but saves the task ID (the position in the task array) so that the task
may be subsequently deleted, if necessary (see SCH_Delete_Task() for further information
about the removal of tasks from the task array):
Task_ID = SCH_Add_Task(Do_X,1000,0);
This causes the function Do_X() to be executed regularly every 1,000 scheduler ticks; the
task will first be executed as soon as the scheduling is started:
SCH_Add_Task(Do_X,0,1000);
This causes the function Do_X() to be executed regularly every 1,000 scheduler ticks; task
will be first executed at T = 300 ticks, then 1,300, 2,300 etc:
SCH_Add_Task(Do_X,300,1000);
*/


/*Hardware fails; software is never perfect; errors are a fact of life. To report errors at any
part of the scheduled application, we can use an (8-bit) error code variable Error_code_G
unsigned char Error_code_G = 0;
To record an error we include lines such as:
• Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
• Error_code_G = ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK;
• Error_code_G = ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER;
• Error_code_G = ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START;
• Error_code_G = ERROR_SCH_LOST_SLAVE;
• Error_code_G = ERROR_SCH_CAN_BUS_ERROR;
• Error_code_G = ERROR_I2C_WRITE_BYTE_AT24C64;
To report these error codes, the scheduler has a function SCH_Report_Status(), which is
called from the Update function*/

/*2.3.8 Reducing power consumption
An important feature of scheduled applications is that they can lend themselves to lowpower operation. This is possible because all modern MCU provide an ‘idle’ mode, where
the CPU activity is halted, but the state of the processor is maintained. In this mode, the
power required to run the processor is typically reduced by around 50
This idle mode is particularly effective in scheduled applications because it may be entered under software control, and the MCU returns to the normal operating mode when
any interrupt is received. Because the scheduler generates regular timer interrupts as a
matter of course, we can put the system ‘ to sleep’ at the end of every dispatcher call: it
will then wake up when the next timer tick occurs.
This is an optional feature. Students can do by yourself by looking at the reference manual
of the MCU that is used.
1 void SCH_Go_To_Sleep ( ) {
2 // todo : Optional
3 }
Program 1.14: An implementation of the scheduler ‘go to sleep’ function*/
#include <scheduler.h>

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void Init (void){
	current_index_task = 0;
}

void SCH_Add_Task ( void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if (current_index_task < SCH_MAX_TASKS){
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period = PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
};

// duoc goi trong ngat timer, nhiem vu la de tru counter
void SCH_Update(void){

	for (int i = 0; i < current_index_task; i++){
		if (SCH_tasks_G[i].Delay > 0){
			SCH_tasks_G[i].Delay--;
		} else{
			SCH_tasks_G[i].Delay= SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

//As we have seen, the ‘Update’ function does not execute any tasks: the tasks that are due
//to run are invoked through the ‘Dispatcher’ function.
//The dispatcher is the only component in the Super Loop:
void SCH_Dispatch_Tasks(void){
	for (int i = 0; i < current_index_task; i++){
		if (SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
		}
	}
}

void SCH_Delete_Task (uint32_t ID){

}
