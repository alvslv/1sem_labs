#include <iostream>


int** read_matrix(unsigned n) {
    int** matrix = new int*[n];

    for (unsigned i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (unsigned j = 0; j < n; ++j)
            std::cin >> matrix[i][j];
    }

    return matrix;
}


bool have_35(int number) {
    for (; number > 0; number /= 10)
        if (number % 10 == 3 || number % 10 == 5)
            return true;
    return false;
}


unsigned pow(unsigned number) {
    return number * number;
}


void proccess_matrix(int** matrix, unsigned n) {
    bool condition = true;
    for (unsigned i = 0; i < n; ++i)
        if (matrix[i][i] < 0 || !have_35(matrix[i][i])) {
            condition = false;
            break;
        }

    if (condition) {
        for (unsigned i = 0; i < n; ++i) {
            unsigned min = UINT_MAX, min_index = 0;
            for (int j = 0; j < n; ++j)
                if (matrix[j][i] < min) {
                    min = matrix[j][i];
                    min_index = j;
                }

            unsigned square_sum = 0;
            for (unsigned j = 0; j < n; ++j)
                square_sum += pow(matrix[j][i]);
            
            matrix[min_index][i] = square_sum;
        }
    }
}


void write_matrix(int** matrix, unsigned n) {
    std::cout << std::endl;

    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


void delete_matrix(int** matrix, unsigned n) {
    for (; n > 0; --n)
        delete[] matrix[n];
}