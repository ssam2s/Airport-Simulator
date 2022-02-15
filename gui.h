#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Def.h"
#define MAX 4

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DrawGUI()
{
	for (int i = 0; i < 101; i++)
	{
		printf("■");
	}

	for (int i = 0; i < 60; i++)
	{
		if (i == 20)
		{
			GotoXY(0, 20);
			for (int j = 0; j < 101; j++)
			{
				printf("■");
			}
			continue;
		}

		if (i == 40)
		{
			GotoXY(0, 40);
			for (int j = 0; j < 101; j++)
			{
				printf("■");
			}
			continue;
		}
		GotoXY(0, i);
		printf("■");
		GotoXY(198, i);
		printf("■");
	}

	for (int i = 0; i < 100; i++)
	{
		printf("■");
	}

	for (int i = 4; i < 60; i += 4)
	{
		GotoXY(0, i);
		for (int j = 0; j < 12; j++)
		{
			printf("■");
		}
	}

	for (int i = 1; i < 60; i++)
	{
		GotoXY(150, i);
		printf("■");
	}

	for (int i = 1; i < 60; i++)
	{
		GotoXY(122, i);
		printf("■");
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	GotoXY(170, 2);
	printf("※ ISSUE ※");

	GotoXY(170, 22);
	printf("※ ISSUE ※");

	GotoXY(170, 42);
	printf("※ ISSUE ※");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	GotoXY(7, 2);
	printf("활주로 ( 1 )");

	GotoXY(7, 22);
	printf("활주로 ( 2 )");

	GotoXY(7, 42);
	printf("활주로 ( 3 )");

	GotoXY(30, 2);
	printf("활주로 대기열 [ 착륙 - 1 ]");

	GotoXY(66, 2);
	printf("활주로 대기열 [ 착륙 - 2 ]");

	GotoXY(99, 2);
	printf("활주로 대기열 [ 이륙 ]");

	GotoXY(30, 22);
	printf("활주로 대기열 [ 착륙 - 1 ]");

	GotoXY(66, 22);
	printf("활주로 대기열 [ 착륙 - 2 ]");

	GotoXY(99, 22);
	printf("활주로 대기열 [ 이륙 ]");

	GotoXY(27, 42);
	printf("활주로 대기열 [ 이륙 ]");

	GotoXY(29, 5);
	printf("큐 번호");

	GotoXY(65, 5);
	printf("큐 번호");

	GotoXY(101, 5);
	printf("큐 번호");

	GotoXY(29, 25);
	printf("큐 번호");

	GotoXY(65, 25);
	printf("큐 번호");

	GotoXY(101, 25);
	printf("큐 번호");

	GotoXY(29, 45);
	printf("큐 번호");

	GotoXY(40, 5);
	printf("식별자");

	GotoXY(76, 5);
	printf("식별자");

	GotoXY(113, 5);
	printf("식별자");

	GotoXY(40, 25);
	printf("식별자");

	GotoXY(76, 25);
	printf("식별자");

	GotoXY(113, 25);
	printf("식별자");

	GotoXY(40, 45);
	printf("식별자");

	GotoXY(51, 5);
	printf("연료");

	GotoXY(87, 5);
	printf("연료");

	GotoXY(51, 25);
	printf("연료");

	GotoXY(87, 25);
	printf("연료");

	GotoXY(132, 3);
	printf("이착륙 현황");

	GotoXY(132, 23);
	printf("이착륙 현황");

	GotoXY(132, 43);
	printf("이착륙 현황");

	GotoXY(54, 43);
	printf("평균 착륙 대기 시간 : ");

	GotoXY(54, 48);
	printf("평균 이륙 대기 시간 :");

	for (int i = 1; i <= 60; i++)
	{
		GotoXY(24, i);
		printf("■");
	}

	for (int i = 1; i < 40; i++)
	{
		GotoXY(60, i);
		printf("■");
	}

	for (int i = 40; i <= 60; i++)
	{
		GotoXY(50, i);
		printf("■");
	}

	for (int i = 1; i <= 60; i++)
	{
		GotoXY(96, i);
		printf("■");
	}
}

void DrawBlock(int x)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = 2; j < 23; j ++)
		{
			GotoXY(j, i);
			printf("□");
		}
	}
}

void EraseBlock(int x)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = 2; j < 24; j++)
		{
			GotoXY(j, i);
			printf(" ");
		}
	}
}

void DrawQueue(queue *q, int opt)
{
	int q_count = 0;
	int q_count_ = 0;
	int q_count__ = 0;

	if (opt == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			GotoXY(32, i * 3 + 8);
			printf("                      ");

			GotoXY(68, i * 3 + 8);
			printf("                      ");

			GotoXY(32, i * 3 + 8);
			printf("%d         %d        %d", 1, q[0].p[i].id, q[0].p[i].fuel);

			GotoXY(68, i * 3 + 8);
			printf("%d         %d        %d", 2, q[1].p[i].id, q[1].p[i].fuel);
		}
		
		q_count = q[0].count + q[1].count;
		q_count_ = q[2].count + q[3].count;

		if (q_count < 2)
		{
			EraseBlock(17);
		}
		else if (q_count >= 2 && q_count < 4)
		{
			EraseBlock(13);
			DrawBlock(17);
		}
		else if (q_count >= 4 && q_count < 6)
		{
			EraseBlock(9);
			DrawBlock(13);
			DrawBlock(17);
		}
		else if (q_count >= 6 && q_count < 8)
		{
			EraseBlock(5);
			DrawBlock(9);
			DrawBlock(13);
		}
		else if (q_count == 8)
		{
			DrawBlock(5);
			DrawBlock(9);
		}

		if (q_count_ < 2)
		{
			EraseBlock(37);
		}
		else if (q_count_ >= 2 && q_count_ < 4)
		{
			EraseBlock(33);
			DrawBlock(37);
		}
		else if (q_count_ >= 4 && q_count_ < 6)
		{
			EraseBlock(29);
			DrawBlock(33);
			DrawBlock(37);
		}
		else if (q_count_ >= 6 && q_count_ < 8)
		{
			EraseBlock(25);
			DrawBlock(29);
			DrawBlock(33);
		}
		else if (q_count_ == 8)
		{
			DrawBlock(25);
			DrawBlock(29);
		}
		
		for (int i = 0; i < 4; i++)
		{
			GotoXY(32, i * 3 + 28);
			printf("                      ");

			GotoXY(68, i * 3 + 28);
			printf("                      ");

			GotoXY(32, i * 3 + 28);
			printf("%d         %d        %d", 1, q[2].p[i].id, q[2].p[i].fuel);

			GotoXY(68, i * 3 + 28);
			printf("%d         %d        %d", 2, q[3].p[i].id, q[3].p[i].fuel);
		}
	}
	else if (opt == 2)
	{
		q_count__ = q[2].count;

		if (q_count__ < 1)
		{
			EraseBlock(57);
		}
		else if (q_count__ == 1)
		{
			EraseBlock(53);
			DrawBlock(57);
		}
		else if (q_count__ == 2)
		{
			EraseBlock(49);
			DrawBlock(53);
			DrawBlock(57);
		}
		else if (q_count__ == 3)
		{
			EraseBlock(45);
			DrawBlock(49);
			DrawBlock(53);
			DrawBlock(57);
		}
		else if (q_count__ == 4)
		{
			DrawBlock(45);
			DrawBlock(49);
			DrawBlock(53);
			DrawBlock(57);
		}

		for (int i = 0; i < 4; i++)
		{
			GotoXY(104, i * 3 + 8);
			printf("                  ");

			GotoXY(104, i * 3 + 28);
			printf("                  ");

			GotoXY(32, i * 3 + 48);
			printf("                  ");

			GotoXY(104, i * 3 + 8);
			printf("%d         %d", 1, q[0].p[i].id);

			GotoXY(104, i * 3 + 28);
			printf("%d         %d", 1, q[1].p[i].id);

			GotoXY(32, i * 3 + 48);
			printf("%d         %d", 1, q[2].p[i].id);
		}
	}
}