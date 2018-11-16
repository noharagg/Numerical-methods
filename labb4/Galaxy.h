
#ifndef _GALAXY
#define _GALAXY
#include <string>


class Galaxy{
private:
	std::string name;
	double distance;
	double bias;
public:
	Galaxy();
	Galaxy(std::string name,double distance, double bias);
	Galaxy(std::string name);
	~Galaxy();
	double getDistance() {
		return distance;
	}
	double getBias() {
		return bias;
	}

	std::string getName() {
		return name;
	}

	void setDistance(double _distance) {
		distance = _distance;
	}

	void setBias(double _bias) {
		bias = _bias;
	}

};



#endif // !_GALAXY
