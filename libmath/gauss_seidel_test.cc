#include "libmath/gauss_seidel.h"

#include <vector>

#include "gtest/gtest.h"

namespace libmath::solvers {
namespace {

TEST(GaussSeidelSolverTests, WikipediaExampleFourVar) {
  std::vector<std::vector<double>> equation = {
    {10, -1,  2,  0,  6},   // 10a   - b  + 2c       =  6
    {-1, 11, -1,  3,  25},  //  -a + 11b   - c + 3d =  25
    { 2, -1, 10, -1, -11},  //  2a   - b + 10c  - d = -11
    { 0,  3, -1,  8,  15}   //        3b   - c + 8d =  15
  };

  GaussSeidel solver;
  std::vector<double> solution = solver.Solve(equation);

  EXPECT_FLOAT_EQ(solution[0], 1);
  EXPECT_FLOAT_EQ(solution[1], 2);
  EXPECT_FLOAT_EQ(solution[2], -1);
  EXPECT_FLOAT_EQ(solution[3], 1);
}

TEST(GaussSeidelSolverTests, TwoVar) {
  std::vector<std::vector<double>> equation = {
    {2, 1, 8}, // 2x + y = 8
    {1, 2, 1}  // x + 2y = 1
  };

  GaussSeidel solver;
  std::vector<double> solution = solver.Solve(equation);

  EXPECT_FLOAT_EQ(solution[0], 5);
  EXPECT_FLOAT_EQ(solution[1], -2);
}

TEST(GaussSeidelSolverTests, ThreeVar) {
  std::vector<std::vector<double>> equation = {
    {3, -1,  1, 1}, // 3x - 1y + 1z = 1
    {3,  6,  2, 0}, // 3x + 6y + 2z = 0
    {3,  3,  7, 4}  // 3x + 3y + 7z = 4
  };

  GaussSeidel solver;
  std::vector<double> solution = solver.Solve(equation);

  EXPECT_FLOAT_EQ(solution[0], 2.0 / 57);
  EXPECT_FLOAT_EQ(solution[1], -9.0 / 38);
  EXPECT_FLOAT_EQ(solution[2], 25.0 / 38);
}

}
}