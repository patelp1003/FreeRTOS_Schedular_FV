# CSEE 6863

# Formal Verification of FreeRTOS Scheduler using CBMC

### Aim

The main objective of the project is to verify various safety and liveness properties of the preemptive priority scheduler in the FreeRTOS kernel for single core processors. Using CBMC we will generate customized assertions to ensure these properties are held true by default, as well as introduce bugs in the kernel to ensure our model checker is able to catch when a property is violated. We are also using CLANG for fuzzing on core functions of FreeRTOS.

### Properties Verified

1. Memory Safety

The Memory Safety Property ensures that in a real-time operating system like FreeRTOS, all tasks created during runtime are correctly assigned to their respective priority-based ready lists. This property is crucial for maintaining system consistency and preventing task mismanagement, which could lead to undefined behavior, missed deadlines, or system crashes.

2. Highest Priority Task Property Verification

The Highest Priority Task Property ensures that in a real-time operating system like FreeRTOS, the scheduler always selects and executes the task with the highest priority when multiple tasks are ready to run. This property is essential for guaranteeing the deterministic behavior expected in priority-based scheduling systems.

3. Idle Task Creation Verification

The Idle Task Creation Property ensures that FreeRTOS correctly creates the idle task when the scheduler starts. This task is fundamental to FreeRTOS's operation, as it runs when no other tasks are ready to execute. Verifying this property ensures proper initialization and functioning of the scheduler.

4. Deletion of Task from Queue

When vTaskDelete() is called, task is removed from queue.

Function calls from:

- Harness()->()->pvCreateIdleTasks()->vTaskCreate()->pvTaskCreate()->pvMalloc()

- Harness()->vTaskDelete()->uxListRemove()->prvDeleteTask()->pvPortFree()

## Steps to install and run the code

### 1. Clone the repository


git clone https://github.com/shvam0000/OS-Scheduler-Verification


### 2. Install CBMC on your system

For mac


brew install cbmc


For unix


git clone https://github.com/diffblue/cbmc.git
cd cbmc


```
make



bin/cbmc --version


Properties file -

1. Idle Task -
2. Deletion of Task from queue -

### How to run the property files.

1. Idle Task
```
cbmc tasks.c harness_start_scheduler.c -I ./include/ --function main --trace
```

2. Deletion of Task from queue
```
cbmc tasks.c harness_task_delete.c --unwind 100 -I ./include/ --function main --trace
```
