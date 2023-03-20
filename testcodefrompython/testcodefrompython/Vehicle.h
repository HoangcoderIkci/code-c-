#pragma once
#include <iostream>

using namespace std;
class Vehicle
{
private:
	/* data */
public:
	Vehicle(/* args */)
	{
		cout << "Vehicle \n"
			<< endl;
	}
	void run()
	{
		cout << "Vehicle run\n"
			<< endl;
	}
};

class car : public Vehicle
{
private:
	/* data */
public:
	car(/* args */)
	{
		cout << "car is constructed\n";
	}
	void run()
	{
		cout << "car is running\n";
	}
};

class motor : public Vehicle
{
private:
	/* data */
public:
	motor(/* args */)
	{
		cout << "motor is constructed\n";
	}
	void run()
	{
		cout << "motor is running\n";
	}
};