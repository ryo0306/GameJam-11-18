#include "FoodObject.hpp"

FoodObjcet::FoodObjcet(){

}

FoodObjcet::~FoodObjcet(){

}

void FoodObjcet::AddGauge(const int _add, int *_gauge){
	_gauge += _add;
}