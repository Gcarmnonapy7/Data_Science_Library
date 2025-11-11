#ifndef MATRIX_OPERATIONS_HH
#define MATRIX_OPERATIONS_HH

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T> // Template of a generic example of code (Many types can be used)

class Matrix {
private:
    int rows, cols;
    T** data; // Pointer to 2D array for matrix data
    
public:
    // Constructor 
    Matrix();
    Matrix(int rows, int cols);
    Matrix(int rows,int cols, T initValues);
    Matrix(const Matrix<T>& other); // Copy constructor

    // Destructor
    ~Matrix();

    // Methods for matrix operations

    bool resize(int newRows , int newCols);

    int getRows() const;
    
    int getCols() const;

    bool operator==(const Matrix<T>& other) const; // Equality operator

    T getValue(int row, int col) const;

    void setValue(int row, int col, T value);

    void print() const;

    Matrix<T> transpose() const;
 
    // Overloaded operators for matrix operations (friend functions)
    friend Matrix<T> operator+(const Matrix<T>& other) const;  // friend function for addition

    friend Matrix<T> operator-(const Matrix<T>& other) const;

    friend Matrix<T> operator*(const Matrix<T>& other) const;

    friend Matrix<T> operator*(T scalar) const;

    friend Matrix<T> operator/(T scalar) const;

    friend Matrix<T>& operator=(const Matrix<T>& other);

};

#endif // MATRIX_OPERATIONS_HH