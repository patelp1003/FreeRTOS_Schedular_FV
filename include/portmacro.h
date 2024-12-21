#ifndef PORTMACRO_H
#define PORTMACRO_H

#include <stdint.h>

/*-----------------------------------------------------------
 * Port-specific definitions.
 *-----------------------------------------------------------
 */

/* Type definitions */
#define portCHAR       char
#define portFLOAT      float
#define portDOUBLE     double
#define portLONG       long
#define portSHORT      short
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE  int32_t

typedef portSTACK_TYPE StackType_t;
typedef int32_t        BaseType_t;
typedef uint32_t       UBaseType_t;

#if configUSE_16_BIT_TICKS == 1
    typedef uint16_t TickType_t;
    #define portMAX_DELAY (TickType_t) 0xffff
#else
    typedef uint32_t TickType_t;
    #define portMAX_DELAY (TickType_t) 0xffffffffUL
#endif

/*-----------------------------------------------------------
 * Critical section management
 *-----------------------------------------------------------
 */

#define portDISABLE_INTERRUPTS() __asm volatile ("cpsid i" ::: "memory")
#define portENABLE_INTERRUPTS()  __asm volatile ("cpsie i" ::: "memory")

#define portENTER_CRITICAL()    vPortEnterCritical()
#define portEXIT_CRITICAL()     vPortExitCritical()

/*-----------------------------------------------------------
 * Architecture-specific settings
 *-----------------------------------------------------------
 */

#define portSTACK_GROWTH      (-1)
#define portTICK_PERIOD_MS    ((TickType_t) 1000 / configTICK_RATE_HZ)
#define portBYTE_ALIGNMENT    8
#define portNOP()             __asm volatile ("nop")

/*-----------------------------------------------------------
 * Scheduler utilities
 *-----------------------------------------------------------
 */

#define portYIELD() __asm volatile ("svc 0" ::: "memory")

#define portEND_SWITCHING_ISR(xSwitchRequired) \
    if (xSwitchRequired)                       \
    {                                          \
        portYIELD();                           \
    }

#define portYIELD_FROM_ISR(x) portEND_SWITCHING_ISR(x)

/*-----------------------------------------------------------
 * Functions
 *-----------------------------------------------------------
 */

void vPortEnterCritical(void);
void vPortExitCritical(void);

#endif /* PORTMACRO_H */
