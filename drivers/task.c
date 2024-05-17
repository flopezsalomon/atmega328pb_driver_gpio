#include "task.h"

void task_init(task_t *task, uint32_t ticks, uint32_t elapsed_time, void (*f)(), states s)
{
	task->ticks		    = ticks;
	task->elapsedTime	= elapsed_time;
	task->fct		    = f;
	task->state			= s;
}

void task_change_period(task_t *task, uint32_t ticks)
{
	task->ticks		    = ticks;
	task->elapsedTime   = 0;
}

void task_change_state(task_t *task, states s)
{
	task->state = s;
	task->elapsedTime   = 0;
}

void task_delete(void)
{
	
}
