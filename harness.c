#include "FreeRTOS.h"
#include "task.h"

// CBMC Harness for verifying idle task creation
extern TaskHandle_t pxCurrentTCB;
int main() {
    // Initialize the FreeRTOS kernel state
    vTaskResetState();

    // Assert that the idle task has not yet been created
    __CPROVER_assert(pxCurrentTCB == NULL, "Idle task should not exist before the scheduler starts.");

    // Call the scheduler start function
    int ret = vTaskStartScheduler();

    // Assert that the idle task is created after starting the scheduler
    __CPROVER_assert(ret == 1, "Idle task must be created before the scheduler starts running.");

    return 0;
}