#pragma once
#include <cstdint>

int64_t add(const int32_t x, const int32_t y);

class Math {
private:
	int32_t x;
	int32_t y;
	int64_t res;
public:
	Math();
	void setInputs(const int32_t x, const int32_t y);
	int64_t getResult();
	void add();
};