/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :05/29/2022
*/

#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>
#define maxTask 10

namespace sdds {
	class TimedTask
	{
		int recordsNum=0;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		struct Task
		{
			std::string Name;
			std::string Units;
			std::chrono::steady_clock::duration duration;
		}task[10];
	public:
		TimedTask();
		~TimedTask() {};
		void startClock();
		void stopClock();
		void addTask(const char* nameTask);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& T);
	};
}
#endif