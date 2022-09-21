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
};
class DynamicGraph {
private:
	std::vector<std::vector<int>> matrix;
	int size;
public:
	DynamicGraph(int n) {
		this->size = n;
		for (int i = 0; i < this->size; i++) {
			matrix.push_back(std::vector<int>());
			for (int j = 0; j < this->size; j++) {
				matrix[i].push_back(0);
				matrix[i][j] = 0;
			}
		}
	}

	std::vector<int>& operator [](int i) {  // return one vector from matrix
		return this->matrix[i];
	}
	int returnSize() {
		return this->size;
	}
	void insertVertex() {
		this->size++;
		this->matrix.push_back(std::vector<int>());
		for (int i = 0; i < this->size; i++) {
			this->matrix[i].resize(this->size, 0);
		}
	}

	void printMatrixOnConsol() {
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}
};