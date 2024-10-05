#include "math-funcs.h"

int64_t add(const int32_t x, const int32_t y) {
	return int64_t(x) + int64_t(y);
}

bool isEqual(const int32_t x, const int32_t y) {
	return x == y;
}

Math::Math() : x(0), y(0), res(0) {};

void Math::setInputs(const int32_t x, const int32_t y) {
	this->x = x;
	this->y = y;
}

int64_t Math::getResult() const{
	return this->res;
}

bool Math::isAllZero(const int32_t x, const int32_t y) const {
	return (x == 0 && y == 0);
}

void Math::add() {
	this->res = int64_t(this->x) + int64_t(this->y);
}