#ifndef FIRST_FILE_HPP
#define FIRST_FILE_HPP
#include <vector>
#include <stdexcept>

class DataManipulation {
public:
    void Gaussian2D(std::vector<std::vector<double>>& data) {
        // Implement Gaussian elimination formula for 2D data(x,y)

        if (data.empty() || data[0].empty()) {
            throw std::invalid_argument("Data cannot be empty.");
        }
    }
};

#endif