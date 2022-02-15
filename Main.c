#include "Def.h"		// Simple Definitions list of Headers
#include "gui.h"			// Functions of Drawing Graphic
#include "queue.h"	// Functions of Realizing Queue
#include "simul.h"		// Functions of Working Simulator

int main(void)
{
	srand((unsigned)time(NULL));

	system("mode con: cols=200 lines=61");
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	DrawGUI();

	land = (queue*)malloc(sizeof(queue) * 4);
	takeoff = (queue*)malloc(sizeof(queue) * 3);

	plane p;
	p.fuel = -1;
	p.id = 0;

	int way;
	int type;
	int type_;
	int p_count;

	initqueue(land, 4);
	initqueue(takeoff, 3);

	double start = 0;
	double end = 50;

	int emer_count = 0;
	int accident = 0;

	double process_land = 0;
	double process_takeoff = 0;
	double avg_fuel = 0;
	double avg_wait_land = 0;
	double avg_wait_takeoff = 0;
	double sum_fuel = 0;

	while (start < end)
	{
		way = random_opt_way();
		type = random_opt_type();
		type_ = random_opt_type();
		p = random_info(p, type);
		p_count = random_opt_count();

		/*------ Arrival, Departure Queue Decision ------*/
		if (type == 0)
		{
			if (!full(land[way]))
			{
				for (int i = 0; i < p_count; i++)
				{
					enqueue(land, p, way);
					p = random_info(p, type);
				}
			}
		}
		else if (type == 1)
		{
			if (way == 3)
			{
				continue;
			}

			if (!full(takeoff[way]))
			{
				for (int i = 0; i < p_count; i++)
				{
					enqueue(takeoff, p, way);
					p = random_info(p, type);
				}
			}
		}
		/*-----------------------------------------*/

		/*------ Arrival, Departure Process Decision ------*/
		if (type_ == 0)
		{
			process_land++;
			if (!empty(land[0]))
			{
				p = dequeue(land, 0);
				if (p.prior == -1)
				{
					emer_count++;
				}
			}
			else
			{
				p = dequeue(land, 1);
				if (p.prior == -1)
				{
					emer_count++;
				}
			}
			GotoXY(125, 13);
			printf("1¹ø È°ÁÖ·Î Âø·ú Ã³¸® - %d\n", p.id);

			sum_fuel += p.fuel;

			if (!empty(land[2]))
			{
				p = dequeue(land, 2);
				if (p.prior == -1)
				{
					emer_count++;
				}
			}
			else
			{
				p = dequeue(land, 3);
				if (p.prior == -1)
				{
					emer_count++;
				}
			}
			GotoXY(125, 33);
			printf("2¹ø È°ÁÖ·Î Âø·ú Ã³¸® - %d\n", p.id);

			sum_fuel += p.fuel;
			sum_fuel /= 2;

			avg_fuel += sum_fuel;
			sum_fuel = 0;

			GotoXY(76, 43);
			printf("%.2lf ÃÊ", avg_wait_land);

			GotoXY(54, 54);
			printf("Æò±Õ ÀÜ¿© ¿¬·á : %.2lf", avg_fuel / process_land);

			accident = check_zero(land, accident);
		}
		else if (type_ == 1)
		{
			process_takeoff++;
			p = dequeue(takeoff, 0);
			GotoXY(125, 7);
			printf("1¹ø È°ÁÖ·Î ÀÌ·ú Ã³¸® - %d\n", p.id);
			
			p = dequeue(takeoff, 1);
			GotoXY(125, 27);
			printf("2¹ø È°ÁÖ·Î ÀÌ·ú Ã³¸® - %d\n", p.id);
			
			p = dequeue(takeoff, 2);
			GotoXY(125, 47);
			printf("3¹ø È°ÁÖ·Î ÀÌ·ú Ã³¸® - %d\n", p.id);

			GotoXY(76, 48);
			printf("%.2lf ÃÊ", avg_wait_takeoff);
		}
		/*-----------------------------------------*/
		DrawQueue(land, 1);
		DrawQueue(takeoff, 2);
		use_fuel(land);
		Sleep(500);
		start++;
		if (start != 0 && process_land != 0 && process_takeoff != 0)
		{
			avg_wait_land = start / process_land;
			avg_wait_takeoff = start / process_takeoff;
		}
	}

	system("cls");
	printf("- - - - ½Ã¹Ä·¹ÀÌ¼Ç °á°ú - - - -\n\n");
	printf("»ç°í È½¼ö : %d\n", accident);
	printf("»ç°í ºñÀ² : %.2lf\n\n", accident / end * 100);
	printf("±ä±Þ Âø·ú È½¼ö : %d\n", emer_count);
	printf("±ä±Þ Âø·ú ºñÀ² : %.2lf\n\n", emer_count / process_land * 100);
	printf("Æò±Õ Âø·ú ´ë±â ½Ã°£ : %.2lf\n", avg_wait_land);
	printf("Æò±Õ ÀÌ·ú ´ë±â ½Ã°£ : %.2lf\n", avg_wait_takeoff);
}