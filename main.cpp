#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "stringUtil.h"
#include "timer.h"
#include <thread>
#include <vector>

using namespace std;

static void show_usage(string name)
{
	cerr << "Usage: " << name << "\n"
         << "Options:\n"
         << "\t-h --help\t\tShow this help message\n"
         << "\t-d,--countdown\t\tswitch to countdown interval timer mode\n"
         << endl;
}

int main(int argc, char* argv[]){

	if (argc > 2) {
		show_usage(argv[0]);
		return 1;
	}

	if (argc == 2) {
		if(strncmp(argv[1], "-h", 2) == 0 || strncmp(argv[1], "--help",6) == 0) {
			show_usage(argv[0]);
			return 0;
		}
		else if (strncmp(argv[1], "-d", 2) == 0 || 
				 strncmp(argv[1], "--countdown", 11) == 0) {

			cout << "Enter s to set or enter time interval in the form of: H M S";
			cout << endl; 

			vector<CountdownParams> intervals;

		 	string rawInput;
		 	getline(std::cin, rawInput);
		 	while (rawInput != "s" ) {
		 		intervals.push_back(CountdownParams());
		 		vector<string> parts;
		 		split(rawInput, parts, ' ');
		 		intervals[intervals.size() - 1].hours = atoi(parts[0].c_str());
		 		intervals[intervals.size() - 1].minutes = atoi(parts[1].c_str());
		 		intervals[intervals.size() - 1].seconds = atoi(parts[2].c_str());

		 		getline(std::cin, rawInput);
		 	}

		 	for( int i = 0; i < intervals.size(); i++ ) {
		 		thread cd(countdown, intervals[i]);
				cd.join();
		 	}
		}
	} 
	else {
		// Using detach instead of join, because I want the main thread to act
		// independently of the countup thread. 
		thread cu(countup);
		cu.detach();
		cout << "This is the countup timer, press q to quit or p to ";
		cout << "pause/unpause" << endl;
		char input = cin.get();
		bool pause = false;
		while (input != 'q') 
		{
			if(input == 'p' && pause == true) 
			{
				pause = false;
				pauseTimer(pause);
			}
			else if(input == 'p' && pause == false)
			{
				pause = true;
				pauseTimer(pause);
			}
			input = cin.get();
		}
		stopTimer();
	}

	return 0;
}