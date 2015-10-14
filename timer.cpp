#include "timer.h"
#include "playsound.h"
#include <iostream>
#include <iomanip>

#include <unistd.h>

using namespace std;

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

