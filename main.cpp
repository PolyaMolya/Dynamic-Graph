#include <iostream>
#include <vector>
#include <algorithm>

class Map {
private:
	int size;
	std::vector<std::vector<int>> mainMap;
public:
	Map() {
		this->size = 0;
	}
	Map(int n) {
		this->size = n;
		for (int i = 0; i < this->size; i++) {
			mainMap.push_back(std::vector<int>());
			for (int j = 0; j < this->size; j++) {
				mainMap[i].push_back(0);
				mainMap[i][j] = 0;
			}
		}
	}
	Map(std::vector<std::vector<int>> M) {
		this->size = M.size();
		this->mainMap = M;
	}
	int returnSize() {
		return this->size;
	}
	std::vector<std::vector<int>> returnMap() {
		return this->mainMap;
	}	
};
// class of one unit (each vertex of dynamic graph)
class Unit {
private:
	double x;
	double y;
	double speed;
	double turningSpeed;
public:
	Unit() {
		this->x = 0.0;
		this->y = 0.0;
		this->speed = 0.0;
		this->turningSpeed = 0.0;
	}
	Unit(int a = 0) {
		this->x = 0.0;
		this->y = 0.0;
		this->speed = 0.0;
		this->turningSpeed = 0.0;
	}
	Unit(double x, double y, double speed,double turningS) {
		this->x = x;
		this->y = y;
		this->speed = speed;
		this->turningSpeed = turningS;
	}
	void setPosition(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void setSpeed(double speed) {
		this->speed = speed;
	}
	void setTurningSpeed(double turningS) {
		this->turningSpeed = turningS;
	}
	std::pair<double, double> givePosition() {
		std::pair<double, double> pos;
		pos.first = this->x;
		pos.second = this->y;
		return pos;
	}
	double giveSpeed() {
		return speed;
	}
	double giveTurningSpeed() {
		return turningSpeed;
	}
	void printUnitDataOnConsol() {
		std::cout << "Position: " << std::endl << "x = " << this->x << "; y = " << this->y << std::endl;
		std::cout << "Speed = " << this->speed << std::endl;
		std::cout << "Turning speed = " << this->turningSpeed << std::endl;
	}
};
// main unit located in 0[] 
// other vector elements - field cells next to the main unit [0] 
// and enemies / friends (may not be nearby)
class DynamicGraph {
private:
	std::vector<std::vector<int>> matrix;
	int size;
public:
		DynamicGraph() {
		Unit T(0);
		this->size = 10;
		for (int i = 0; i < this->size; i++) {
			this->currentUnit.push_back(T);
		}
	}
	DynamicGraph(int n, Unit U) {
		Unit T(0); //  cells around	current Unit [0]
		this->size = n;
		this->currentUnit.push_back(U);
		this->currentUnit.resize(this->size);
		for (int i = 0; i < this->size; i++) {
			this->currentUnit.push_back(T);
		}
	}
	int returnSize() {
		return this->size;
	}

	void insertVertex(Unit U) {
		this->size++;
		this->currentUnit.push_back(U);
	}
	void printGraphAboutCurrentUnit() {
		std::cout << std::endl;
		for (int i = 0; i < this->size; i++) {
			std::cout << "Unit namber " << i << std::endl;
			this->currentUnit[i].printUnitDataOnConsol();
			std::cout << "==========" << std::endl;
		}
	}

};