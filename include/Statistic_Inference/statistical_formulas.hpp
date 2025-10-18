#ifndef STATISTICAL_FORMULAS_HPP
#define STATISTICAL_FORMULAS_HPP   
#include <vector>
#include <stdexcept>



namespace name
{
    class StatisticalFormulas {

    public:
        double BayesTheorem(double prior, double likelihood, double evidence) {
            // Implement Bayes' Theorem: P(A|B) = (P(B|A) * P(A)) / P(B)
            if (evidence == 0) {
                throw std::invalid_argument("Evidence cannot be zero.");
            }
            return (likelihood * prior) / evidence;
        }

};
} 


#endif