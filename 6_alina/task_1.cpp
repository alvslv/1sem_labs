// var 3: 1. Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
// Если в последовательности есть хотя бы одно число, сумма цифр которого равна 14, 
// упорядочить последовательность по неубыванию.
#include <iostream>
using namespace std;


int digits_sum(int number) {
    number = number > 0? number : -number; // то же самое, что сверху

    int sum = 0;

    for (; number > 0; number /= 10)
        sum += number % 10;

    return sum;
}


void sort(int* array, unsigned n) {
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (array[i] >= array[j])
                swap(array[i], array[j]);
}


int main() {
    unsigned n;
    cout << "n: ";
    cin >> n;

    bool has_sum_14 = false;

    int array[n];

    cout << "sequence: ";
    for (unsigned i = 0; i < n; i++) {
        cin >> array[i];

        if (digits_sum(array[i]) == 14)
            has_sum_14 = true;
    }

    if (has_sum_14)
        sort(array, n);

    cout << "answer:   ";
    for (int number : array)
        cout << number << ' ';
    cout << endl;
}