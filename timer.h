#ifndef TIMER_H
#define TIMER_H

struct CountdownParams{

	int hours;
	int minutes;
	int seconds;

};

void countdown(CountdownParams context);
void countup();
void stopTimer();
void pauseTimer(bool setPause);

#endif