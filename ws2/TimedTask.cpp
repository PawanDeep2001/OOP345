/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :05/29/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <chrono>
#include "TimedTask.h"
using namespace std;
namespace sdds {
	TimedTask::TimedTask() {
		;
	}
	void TimedTask::startClock() {
		start = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock() {
		end = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* nameTask) {
		auto timer = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		if (recordsNum<maxTask)
		{
			task[recordsNum].Name = nameTask;
			task[recordsNum].Units = "nanoseconds";
			task[recordsNum].duration = timer;
		}
		recordsNum = recordsNum + 1;
	}
	ostream& operator<<(ostream& os, const TimedTask& T) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < T.recordsNum; i++)
		{
			os << left << setw(21) << T.task[i].Name << right << setw(14) << T.task[i].duration.count() << " " << T.task[i].Units << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}