/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Car.h"
using namespace std;
namespace sdds {
	Car::Car(istream& is) {
		string tag;
		string speed;
		string str;
		getline(is, str, '\n');
		tag = str.substr(0, str.find(","));
		tag.erase(tag.find_last_not_of(' ') + 1);
		tag.erase(0, tag.find_first_not_of(' '));
		str.erase(0, str.find(',') + 1);
		Maker= str.substr(0, str.find(","));
		Maker.erase(Maker.find_last_not_of(' ') + 1);
		Maker.erase(0, Maker.find_first_not_of(' '));
		str.erase(0, str.find(',') + 1);
		Condition =str.substr(0, str.find(","));
		Condition.erase(Condition.find_last_not_of(' ') + 1);
		Condition.erase(0, Condition.find_first_not_of(' '));
		str.erase(0, str.find(',') + 1);
		if(Condition!="n"&& Condition != "u"&& Condition != "b" && Condition!="") {
			throw "invalid condition";
		}
		try
		{
			speed = str.substr(0, str.find(","));
			speed.erase(speed.find_last_not_of(' ') + 1);
			speed.erase(0, speed.find_first_not_of(' '));
			for (char& sp : speed) {
				if (isdigit(sp) == 0)
				{
					throw "Invalid Record!";
				}
			}
			stringstream s_speed(speed);
			s_speed >> TopSpeed;
		}
		catch (char* msg)
		{
			throw "Invalid Record!";
		}
		is.seekg(0);
	}
	Car::~Car() {
		;
	}
	string Car::condition()const { 
		string temp;
		if (Condition == "n"|| Condition=="") {
			temp = "new";
		}
		else if (Condition == "u") {
			temp = "used";
		}
		else if (Condition == "b") {
			temp = "broken";
		}
		return temp;
	}
	double Car::topSpeed()const { 
		return TopSpeed; 
	}
	void Car::display(ostream& out)const {
		out << "| "<< setw(10) <<right << Maker << " | "<< setw(6) << left << condition()<< " | " << setw(6)<< fixed << setprecision(2) << topSpeed() << " |";
	}
}
