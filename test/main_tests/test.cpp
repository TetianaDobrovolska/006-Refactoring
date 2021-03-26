#include "gtest/gtest.h"
#include "../../src/tic_tac_toe.h"

using namespace ::std;

//TEST(TestSet, Test) {
//    ASSERT_TRUE(1);
//}

TEST(TestSet, TestCellIdOutOfRange) {
    bool ret;

    ret = is_out_of_range(11);
    ASSERT_TRUE(ret);

    ret = is_out_of_range(-1);
    ASSERT_TRUE(ret);
  }


TEST(TestSet, TestCellIsOccupied) {
    bool ret;
    cells[0] = 'X';

    ret = is_occupied(1);
    ASSERT_TRUE(ret);
}
