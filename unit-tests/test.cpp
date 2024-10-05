#include "pch.h"
#include "../static-lib-funcs/math-funcs.h"

class AddTest : public testing::TestWithParam<std::tuple<int32_t, int32_t, int64_t>> {};

TEST_P(AddTest, ParameterizedTests) {
	int32_t x = std::get<0>(GetParam());
	int32_t y = std::get<1>(GetParam());
	int64_t z = std::get<2>(GetParam());

	EXPECT_EQ(z, add(x,y));
}

INSTANTIATE_TEST_CASE_P(
	ParameterizedAddTests,
	AddTest,
	::testing::Values(
		std::make_tuple(1,1,2),
		std::make_tuple(1000, -150, 850),     
		std::make_tuple(INT32_MAX, 0, INT32_MAX),   
		std::make_tuple(INT32_MIN, 0, INT32_MIN)
	));

class MathTests : public ::testing::Test {
protected:
	Math instance;

	void SetUp() override {
		int32_t x = 15;
		int32_t y = 24;
		instance.setInputs(x, y);
	}
};

TEST_F(MathTests, initialization) {
	instance.setInputs(1024, 1024);
	instance.add();
	EXPECT_EQ(2048, instance.getResult());
}

TEST_F(MathTests, baseConfig) {
	instance.add();
	EXPECT_EQ(39, instance.getResult());
}

TEST(addTests, positiveNumbers) {
	EXPECT_EQ(1025, add(1, 1024));
	EXPECT_EQ(2048, add(1024,1024));
	EXPECT_EQ(100000000, add(50000000, 50000000));
}

TEST(addTests, negativeNumbers) {
	EXPECT_EQ(-1025, add(-1, -1024));
	EXPECT_EQ(-2048, add(-1024, -1024));
	EXPECT_EQ(-100000000, add(-50000000, -50000000));
	EXPECT_EQ(-1, add(INT32_MIN, INT32_MAX));
}

TEST(addTests, mixedNumbers) {
	EXPECT_EQ(0, add(-1024, 1024));
	EXPECT_EQ(0, add(1024, -1024));
	EXPECT_EQ(-256, add(256, -512));
}
TEST(addTests, zero) {
	EXPECT_EQ(1024, add(0, 1024));
	EXPECT_EQ(-1024, add(0, -1024));
	EXPECT_EQ(INT32_MAX, add(0, INT32_MAX));
	EXPECT_EQ(INT32_MIN, add(0, INT32_MIN));
}

TEST(addTests, overflow) {
	EXPECT_EQ(INT32_MAX - 1, add(-1, INT32_MAX));
	EXPECT_EQ(int64_t(INT32_MAX) + int64_t(1), add(1, INT32_MAX));
	EXPECT_EQ(2147483646, add(-1, INT32_MAX));
	EXPECT_EQ(2147483648, add(1, INT32_MAX));
	EXPECT_EQ(4294967294, add(INT32_MAX, INT32_MAX));
	EXPECT_EQ(int64_t(INT32_MAX) + int64_t(INT32_MAX), add(INT32_MAX, INT32_MAX));
}

TEST(addTests, expect) {
	EXPECT_PRED2(isEqual, 39+11, 17);
	EXPECT_TRUE(isEqual(15, 16));
}

