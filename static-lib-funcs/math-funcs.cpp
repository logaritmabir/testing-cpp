#include "math-funcs.h"

int64_t add(const int32_t x, const int32_t y) {
	return int64_t(x) + int64_t(y);
}

Math::Math() : x(0), y(0), res(0) {};

void Math::setInputs(const int32_t x, const int32_t y) {
	Math::x = x;
	Math::y = y;
}

int64_t Math::getResult() {
	return Math::res;
}

void Math::add() {
	Math::res = int64_t(Math::x) + int64_t(Math::y);
}