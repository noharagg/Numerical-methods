#include "Galaxy.h"
using std::string;
Galaxy::Galaxy()
{
}


Galaxy::~Galaxy(){
}

Galaxy::Galaxy(string _name, double _distance, double _bias): name(_name) , distance(_distance) , bias(_bias){
}

Galaxy::Galaxy(string _name) : name(_name) {
}

