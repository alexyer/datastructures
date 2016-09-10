#include <gtest/gtest.h>
#include <vector>
#include <random>

using std::vector;

class SortTest : public ::testing::Test {
public:
    static const int SIZE = 42;
    vector<int> check;
    vector<int> sorted;
    vector<int> reversed;
    vector<int> random;

    void SetUp () {
        for (int i = 0; i < SIZE; ++i) {
            sorted.push_back(i);
            reversed.push_back(SIZE-i-1);
        }
        check = sorted;
        random = sorted;
        auto engine = std::default_random_engine();
        std::shuffle(std::begin(random), std::end(random), engine);
    }
};