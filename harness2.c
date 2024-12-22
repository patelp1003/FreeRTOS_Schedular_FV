#include "FreeRTOS.h"
#include "task.h"

// CBMC Harness for verifying idle task creation
extern TaskHandle_t pxCurrentTCB;

void vTask( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
    }
}

/* Function that creates a task. */

   
int main() {
    // Initialize the FreeRTOS kernel state
    vTaskResetState();

    // Assert that the idle task has not yet been created
    __CPROVER_assert(pxCurrentTCB == NULL, "Idle task should not exist before the scheduler starts.");

    // Call the scheduler start function
    int ret = vTaskStartScheduler();

    // Assert that the idle task is created after starting the scheduler
    // __CPROVER_assert(ret == 1, "Idle task must be created before the scheduler starts running.");
    __CPROVER_assert(pxCurrentTCB != NULL, "Task is NULL.");

    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;

    /* Create the task, storing the handle. */
     xReturned = xTaskCreate(
                     vTask,       /* Function that implements the task. */
                     "Test",          /* Text name for the task. */
                     1024,      /* Stack size in words, not bytes. */
                     ( void * ) 1,    /* Parameter passed into the task. */
                     2,/* Priority at which the task is created. */
                     &xHandle );  

    UBaseType_t numTasks = uxTaskGetNumberOfTasks();
     __CPROVER_printf(numTasks);
    __CPROVER_assert((unsigned int)numTasks == 2, "Task is not loaded.");  

   
    vTaskDelete( xHandle );
    numTasks = uxTaskGetNumberOfTasks();
    __CPROVER_assert((unsigned int)numTasks == 1, "Task is not deleted."); 
    return 0;
}