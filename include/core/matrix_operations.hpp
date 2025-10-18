#ifndef MATRIX_OPERATIONS_HH
#define MATRIX_OPERATIONS_HH
#include <vector>
#include <stdexcept>
// 'MatrixOperations' class provides basic operations for matrices like addition, subtraction, and multiplication.
// The class uses std::vector to represent matrices and includes error handling for dimension mismatches.
// Note : The methods for subtraction and multiplication are declared but not defined in this snippet. 
// And needs improvement in the Big 0 notation and dealing with N dimensions matrices.

class MatrixOperations {
    public:
    
    std::vector<std::vector<int>> addingMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2)
    {  
         // Initialize the result matrix with zeros and the same dimensions as the input matrices
        auto sum_matrix = std::vector<std::vector<int>>(matrix1.size(), std::vector<int>(matrix1[0].size(), 0));
        if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }

        for (auto i = 0; i < matrix1.size(); ++i){
            for (auto j = 0; j < matrix2[0].size(); ++j){
                sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        return sum_matrix;
    };

    std::vector<std::vector<int>> subtractingMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2){
        

        auto difference_matrix = std::vector<std::vector<int>>(matrix1.size(), std::vector<int>(matrix1[0].size(),0));
        if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()){
            throw std::invalid_argument("Matrices must have the same dimensions");
        }

        for (auto i = 0; i < matrix1.size(); ++i){
            for (auto j = 0; j < matrix2[0].size(); ++j){
                difference_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        return difference_matrix;
    };

    void multiplyingMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2){
        if (matrix1[0].size() != matrix2.size()){
            throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        auto product_matrix = std::vector<std::vector<int>>(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));

        for (auto i = 0; i < matrix1.size(); ++i){
            for (auto j = 0; j < matrix2[0].size(); ++j){
                for (auto k = 0; k < matrix1[0].size(); ++k){
                    product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

    };
    
    void transposingMatrix(const std::vector<std::vector<int>>& matrix){
        auto transposed_matrix = std::vector<std::vector<int>>(matrix[0].size(), std::vector<int>(matrix.size(), 0));
        for (auto num_row = 0; num_row < matrix.size(); ++ num_row ){
            for (auto num_col = 0; num_col < matrix[0].size(); ++ num_col){
                transposed_matrix[num_col][num_row] = matrix[num_row][num_col];
            }
        }
    };

    std::vector<std::vector<int>> createZeroMatrix(int rows, int cols){
        std::vector<std::vector<int>> zero_matrix(rows, std::vector<int>(cols , 0));
        return zero_matrix;
    }

    std::vector<std::vector<int>> createOnesMatrix(int rows , int cols){
        std::vector<std::vector<int>> ones_matrix(rows , std::vector<int>(cols , 1));
        return ones_matrix;
    }
    
    std::vector<std::vector<int>> createIdentityMatrix(int size){
        std::vector<std::vector<int>> identityMatrix(size, std::vector<int>(size , 0));
        for (auto i = 0; i < size; ++i){
            identityMatrix[i][i] = 1;
        }
        return identityMatrix;   
    }


    // Implementing anothers operations like determinant, inverse, is_symmetric, is_identity, identity_matrix with same shape, etc.

    
};
#endif