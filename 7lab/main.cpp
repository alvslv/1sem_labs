#include "source.hpp"
#include <iostream>


int main() {
    unsigned n;
    std::cin >> n;

    auto matrix = read_matrix(n);
    proccess_matrix(matrix, n);
    write_matrix(matrix, n);
    delete_matrix(matrix, n);
}