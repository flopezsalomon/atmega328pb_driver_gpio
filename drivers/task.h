


#ifndef TASK_H
#define TASK_H

#include <avr/io.h>

typedef enum {BLOCKED, UNBLOCKED} states;

typedef struct {
	uint32_t ticks;
	uint32_t elapsedTime;	// Time since task's last tick
	void (*fct)(void);      // Function to call for task's tick
	states state;
}task_t;

void task_init(task_t *task,uint32_t ticks,uint32_t elapsed_time, void (*f)(), states s);
void task_change_period(task_t *task,uint32_t ticks);
void task_change_state(task_t *task, states s);
void task_delete();

#endif