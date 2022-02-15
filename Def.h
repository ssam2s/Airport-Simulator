#pragma once
#define MAX 4

/*---------- Struct Definition ---------- */
typedef struct plane		// Airplane Struct
{
	int id;
	int fuel;
	int prior;
} plane;

typedef struct queue	// Queue Struct
{
	int count;
	int front;
	int rear;
	plane p[MAX];
} queue;

/*---------- Queue Functions ---------- */
void initqueue(queue *, int);				// Initializing Queue
void enqueue(queue *, plane, int);	// Push the Data in Queue
plane dequeue(queue *, int);			// Pop the Data in Queue
int size(queue);									// Return Size of Queue
int empty(queue);								// Check Queue is Empty
int full(queue);									// Check Queue is Full

/*--------- Simulation Functions -------- */
int random_opt_way();						// Choose Runway Number
int random_opt_type();						// Choose Departure or Arrival
int random_opt_count();					// Choose Number of Airplanes
plane random_info(plane, int);			// Set Airplane's Data ( ID, FUEL )
void use_fuel(queue *);						// Decrease Airplane's Fuel
int check_zero(queue *q, int count); // Check Accident Count

/*---------- Drawing Functions --------- */
void GotoXY(int, int);						// Set Console Cursor Position
void DrawGUI();								// Draw Frame of Console Graphics
void DrawQueue(queue *, int);			// Draw Appearance of Queues
void DrawBlock(int);							// Draw Appearance of Queues with Graphics
void EraseBlock(int);							// Erase Appearance of Queues with Graphics

/*---------- Global Variables --------- */
int count_empty = 0;						// + 1 If Queue is Empty When Dequeue
int count_full = 0;								// + 1 If Queue is Full When Enqueue
queue *land;										// Pointer Array of Landing
queue *takeoff;								// Pointer Array of Taking off