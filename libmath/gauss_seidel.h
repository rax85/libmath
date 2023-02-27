#pragma once

#include <vector>

namespace libmath::solvers {

/** @brief Gauss Seidel solver for simultaneous equations. */
class GaussSeidel {
  public:
    GaussSeidel(int max_iterations = 64, double convergence_tolerance = 1e-9)
        : max_iterations_(max_iterations), convergence_tolerance_(convergence_tolerance) {}

    /**
     * @brief Solve the specified system of equations.
     * ax1 + bx2 = k
     * cx1 + dx2 = l
     * Equations are specified as :
     * {
     *  {a, b, k},
     *  {c, d, l},
     * }
     * 
     * @param equations The equations to solve as specified above.
     * @return A vector of solutions, equal to the number of variables.
     */
    std::vector<double> Solve(const std::vector<std::vector<double>>& equations);

  private:
    int max_iterations_;
    double convergence_tolerance_;
};

}