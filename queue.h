#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Def.h"
#define MAX 4

void initqueue(queue *q, int size)
{
	for (int i = 0; i < size; i++)
	{
		q[i].count = 0;
		q[i].front = 0;
		q[i].rear = -1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			q[i].p[j].id = 0;
			q[i].p[j].fuel = -1;
			q[i].p[j].prior = 0;
		}
	}
}

void enqueue(queue *q, plane p, int index)
{
	if (q[index].count >= MAX)
	{
		count_full++;
	}
	else
	{
		(q[index].count)++;
		q[index].rear = (q[index].rear + 1) % MAX;
		q[index].p[q[index].rear] = p;
	}
}

plane dequeue(queue *q, int index)
{
	plane p;

	if (q[index].count <= 0)
	{
		count_empty++;
		p.id = 0;
		p.fuel = -1;
		return p;
	}
	else
	{
		(q[index].count)--;

		for (int i = 0; i < MAX; i++)
		{
			if (q[index].p[i].prior == 1)
			{
				p = q[index].p[i];
				q[index].p[i].id = 0;
				q[index].p[i].fuel = -1;
				q[index].p[i].prior = -1;
				return p;
			}
		}

		p = q[index].p[q[index].front];
		q[index].p[q[index].front].id = 0;
		q[index].p[q[index].front].fuel = -1;
		q[index].p[q[index].front].prior = 0;
		q[index].front = (q[index].front + 1) % MAX;
		return p;
	}
}

int size(queue q)
{
	return q.count;
}

int empty(queue q)
{
	if (q.count <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int full(queue q)
{
	if (q.count >= MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}