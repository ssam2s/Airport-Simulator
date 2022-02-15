#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Def.h"
#define MAX 4

int random_opt_way()
{
	int way;

	way = rand() % 4;

	return way;
}

int random_opt_type()
{
	int type;

	type = rand() % 2;

	return type;
}

int random_opt_count()
{
	int count;

	count = rand() % 4;

	return count;
}

plane random_info(plane p, int type)
{
	p.fuel = rand() % 30;

	if (type == 0)
	{
		p.id = rand() % 20 * 2 + 2;
	}
	else if (type == 1)
	{
		p.id = rand() % 20 * 2 + 1;
	}

	return p;
}

void use_fuel(queue *land)
{
	int order;
	int index;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (land[i].p[j].fuel > 0)
			{
				land[i].p[j].fuel--;
			}
			else if (land[i].p[j].fuel == 0)
			{
				order = i;
				switch (i)
				{
				case 0:
					order = 1;
					index = 1;
					break;
				case 1:
					index = 2;
					break;
				case 2:
					index = 1;
					break;
				case 3:
					order = 2;
					index = 2;
					break;
				}

				if (order == 1)
				{
					GotoXY(160, 4);
				}
				else if (order == 2)
				{
					GotoXY(160, 24);
				}
				printf("%d번째 큐 %d번째 비행기 연료 고갈\n", index, j + 1);
				land[i].p[j].prior = 1;
			}
		}
	}
}

int check_zero(queue *q, int count)
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (q[i].p[j].prior == 1)
			{
				count++;
				return count;
			}
		}
	}

	return count;
}