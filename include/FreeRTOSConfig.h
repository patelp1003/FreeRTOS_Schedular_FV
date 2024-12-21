#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * FreeRTOS Kernel Configuration
 *-----------------------------------------------------------*/

/* The configUSE_PREEMPTION setting determines whether or not FreeRTOS uses 
   preemption. Set to 1 for preemptive multitasking, 0 for cooperative multitasking. */
#define configUSE_PREEMPTION                1
#define configNUMBER_OF_CORES               1
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP 0
// #define configSUPPORT_STATIC_ALLOCATION     0
/* The configUSE_IDLE_HOOK setting determines whether or not the idle task hook 
   function is called when the idle task is running. Set to 1 to enable the hook. */
#define configUSE_IDLE_HOOK                 1

#define configTICK_TYPE_WIDTH_IN_BITS              TICK_TYPE_WIDTH_64_BITS

/* The configUSE_TICK_HOOK setting enables the tick hook function, which is called 
   every time the RTOS tick interrupt occurs. */
#define configUSE_TICK_HOOK                 0

/* Set to 1 to enable the trace facility for FreeRTOS. This is used for performance 
   analysis and debugging. */
#define configUSE_TRACE_FACILITY            0

/* The configUSE_TIMERS setting enables or disables the use of software timers. */
#define configUSE_TIMERS                    0

/* The maximum number of priorities the RTOS scheduler will support. */
#define configMAX_PRIORITIES                5

/* The size of the stack allocated to each task. Increase or decrease based on your needs. */
#define configMINIMAL_STACK_SIZE            128

/* The total heap size for FreeRTOS's memory allocation. */
#define configTOTAL_HEAP_SIZE               (32 * 1024) /* 32 KB */

/* The number of tasks that can be created. */
#define configMAX_TASK_NAME_LEN             16

/* The maximum number of event groups that can be used. */
#define configMAX_EVENT_GROUPS              5

/* The maximum number of software timers. */
#define configTIMER_TASK_PRIORITY           (configMAX_PRIORITIES - 1)

/* The priority of the idle task. */
#define configIDLE_SHOULD_YIELD             1

/* The tick rate in Hz (typically 1000 Hz or 100 Hz for most systems). */
#define configTICK_RATE_HZ                  1000

/* The maximum delay value that can be used in FreeRTOS functions. */
#define configMAX_DELAY                     (TickType_t) 0xffffffffUL

/* Enable/disable the tickless idle feature (useful for low-power systems). */
#define configUSE_TICKLESS_IDLE             0

/*-----------------------------------------------------------
 * Memory Management Configuration
 *-----------------------------------------------------------*/

/* Memory allocation scheme. Set to 1 to use heap_4.c, 2 for heap_5.c, etc. */
#define configFRTOS_MEMORY_SCHEME           4

/*-----------------------------------------------------------
 * Task Management Configuration
 *-----------------------------------------------------------*/

/* Enable/disable the task delete API. Set to 1 to enable. */
#define configUSE_TASK_NOTIFICATIONS        1

/* Enable/disable the mutex functionality. */
#define configUSE_MUTEXES                   1

/* Enable/disable the recursive mutex functionality. */
#define configUSE_RECURSIVE_MUTEXES         1

/* Enable/disable the task notification API for event notification. */
#define configUSE_TASK_NOTIFICATIONS        1

/*-----------------------------------------------------------
 * Tick Timer Configuration
 *-----------------------------------------------------------*/

/* Defines the number of clock ticks per second. */
#define configCPU_CLOCK_HZ                  (16000000UL) /* 16 MHz clock */

/* The tick interrupt priority. Lower values indicate higher priority. */
#define configKERNEL_INTERRUPT_PRIORITY     255

/* The priority of the interrupt used for the tick timer. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 191

/*-----------------------------------------------------------
 * Optional features
 *-----------------------------------------------------------*/

/* Include the printf() function in FreeRTOS, useful for debugging. */
#define configPRINTF(x)                     printf x

/* Enable or disable the inclusion of the runtime statistics API. */
#define configGENERATE_RUN_TIME_STATS       0

/* Enable or disable the stack overflow checking feature. */
#define configCHECK_FOR_STACK_OVERFLOW      1

/*-----------------------------------------------------------
 * Co-routine settings
 *-----------------------------------------------------------*/

/* Enable/disable co-routines. Set to 1 to enable, 0 to disable. */
#define configUSE_CO_ROUTINES               0

/* The maximum number of co-routines. */
#define configMAX_CO_ROUTINE_PRIORITIES     2

/*-----------------------------------------------------------
 * API function prototypes
 *-----------------------------------------------------------*/

void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationMallocFailedHook(void);

#endif /* FREERTOS_CONFIG_H */
