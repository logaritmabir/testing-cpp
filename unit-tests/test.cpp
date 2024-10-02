#include "pch.h"
#include "../static-lib-funcs/math-funcs.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
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
	EXPECT_EQ(int64_t(int64_t(INT32_MAX)+ int64_t(1)), add(1, INT32_MAX));
	EXPECT_EQ(2147483646, add(-1, INT32_MAX));
	EXPECT_EQ(2147483648, add(1, INT32_MAX));
	EXPECT_EQ(4294967294, add(INT32_MAX, INT32_MAX));
	EXPECT_EQ(int64_t(INT32_MAX) + int64_t(INT32_MAX), add(INT32_MAX, INT32_MAX));
}
