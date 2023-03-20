#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ManagerVh;
class Vehicle;
class Vehicelapp;
class Vehicle
{
public:
	Vehicle(string n) : name(n) {};
	virtual void run() {
		cout << name << " is running\n";
	};
	/*void KhoiTao() {
		ManagerVh::getManager();
	}*/
private:
	const string name;
	string own;
	string licien;
};
 


class ManagerVh
{
public:
	void addVehicle(Vehicle *v) {
		Vehicles.push_back(v);
	}
	static ManagerVh* getManager() {
		if (manager == nullptr) manager = new ManagerVh;
		return manager;
	}

	void start() {
		for (auto itr : Vehicles) {
			itr->run();
		}
	}
private:
	static ManagerVh* manager;
	ManagerVh() {};
	vector<Vehicle *> Vehicles;
};

ManagerVh* ManagerVh::manager = nullptr;
class Vehicelapp
{
public:
	Vehicelapp() : version("3.10") {}
	void Init() {
		Vehicle * taxi = new Vehicle("taxi");
		Vehicle * lambo = new Vehicle("lambogini");
		ManagerVh::getManager()->addVehicle(taxi);
		ManagerVh::getManager()->addVehicle(lambo);
	}
	void start() {
		ManagerVh::getManager()->start();
	}
protected:
private:
	string version;
};
int main()
{
	Vehicelapp app;
	app.Init();
	app.start();
	system("pause");
	return 0;
}