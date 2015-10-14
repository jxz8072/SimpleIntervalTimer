#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "stringUtil.h"
#include "timer.h"
#include <thread>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

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


	return 0;
}