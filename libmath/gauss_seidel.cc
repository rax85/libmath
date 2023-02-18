#include "libmath/gauss_seidel.h"

#include <cassert>
#include <vector>

namespace libmath::solvers {
namespace {

/**
 * @brief A single solution step solves the kth equation for Xk using the other values from the solution.
 * @return double The new approximate value for Xk.
 */
double SolveSingle(const std::vector<std::vector<double>>& equations, const std::vector<double>& solution, size_t idx) {
  assert(idx < equations.size());
  const std::vector<double>& equation = equations[idx];

  // ax1 + bx2 = k is specified as [a, b, k].
  // or x1 = k/a - bx2/a
  double x_coeff = equation[idx];
  double result = equation.back() / x_coeff;
  for (size_t i = 0; i < solution.size(); i++) {
    if (i == idx) {
      continue;
    }
    result -= equation[i] * solution[i] / x_coeff;
  }
  return result;
}

}

std::vector<double> GaussSeidel::Solve(const std::vector<std::vector<double>>& equations) {
  assert(equations.size() == equations[0].size() - 1);
  std::vector<double> solution(equations.size());
  std::vector<double> prev_solution(solution.size());

  // Initialize the solution with 0 to start with.
  std::fill(solution.begin(), solution.end(), 0);

  // Iterate till convergence is achieved or max_iterations is exceeded.
  for (int i = 0; i < max_iterations_; i++) {
    // Recalculate each coefficient using the other solution values, including the values calculated
    // in the current iteration for efficiency.
    for (size_t var_idx = 0; var_idx < solution.size(); var_idx++) {
      solution[var_idx] = SolveSingle(equations, solution, var_idx);
    }

    // Convergence check.
    bool converged = true;
    for (size_t i = 0; i < solution.size(); i++) {
      converged &= std::abs(solution[i] - prev_solution[i]) < convergence_tolerance_;
    }
    if (converged) {
      break;
    }
    prev_solution = solution;
  }

  return solution;
}

}