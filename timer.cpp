#include "timer.h"
#include "playsound.h"
#include <iostream>
#include <iomanip>

#include <unistd.h>

using namespace std;

atomic_bool stop(false);
atomic_bool pause_timer(false);

void countdown(CountdownParams context){

	//struct CountdownParams *params = (struct CountdownParams *) context;
	int hours = context.hours;
	int minutes = context.minutes;
	int seconds = context.seconds;

	int total_seconds = (hours * 3600) + (minutes * 60) + seconds;

	for( int s = total_seconds; s >= 0; s--)
	{

		int hours_remain = s / 3600;
		int minutes_remain = (s - (hours_remain * 3600)) / 60;
		int seconds_remain = (s - (hours_remain * 3600) - (minutes_remain * 60));
		
		cout << "\r" << setfill('0') << setw(2) << hours_remain << ":";
		cout << setfill('0') << setw(2) << minutes_remain << ":";
		cout << setfill('0') << setw(2) << seconds_remain << flush;
		
		sleep(1);
	}

	const char* chi = "chi.wav";
	play_audio(chi);
}

void countup(){
	int s = 0;
	while(!stop)
	{
		sleep(1);
		int hours = s / 3600;
		int minutes = (s - (hours * 3600)) / 60;
		int seconds = (s - (hours * 3600) - (minutes * 60));
		cout << "\r" << setfill('0') << setw(2) << hours << ":";
		cout << setfill('0') << setw(2) << minutes << ":";
		cout << setfill('0') << setw(2) << seconds << flush;
		
		if( pause_timer == false ) {
			s++;
		}
		
	}
}

void stopTimer() {
	stop = true;
}

void pauseTimer(bool setPause){
	pause_timer = setPause;
}