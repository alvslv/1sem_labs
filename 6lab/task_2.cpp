// var 3: 2. Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
// Упорядочить последовательность по неубыванию первой цифры числа,
// числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наибольшей цифры числа,
// числа с одинаковыми первыми цифрами и одинаковыми наибольшими цифрами дополнительно упорядочить по неубыванию самого числа.
#include <iostream>
#include <algorithm>
using namespace std;


unsigned get_first(int number) {
    while (number > 9)
        number /= 10;

    return number;
}


unsigned get_max(int number) {
    int max = INT_MIN;

    for (; number > 0; number /= 10)
        max = number > max? number : max;

    return max;
}


bool compare(int a, int b) {
    if (get_first(a) == get_first(b))
        if (get_max(a) == get_max(b))
            return a < b;
        else
            return get_max(a) < get_max(b);

    return get_first(a) < get_first(b);
}


int main() {
    unsigned n;
    cout << "n: ";
    cin >> n;

    bool has_sum_14 = false;

    int array[n];

    cout << "sequence: ";
    for (unsigned i = 0; i < n; i++)
        cin >> array[i];

    sort(array, array + n, compare);

    cout << "answer:   ";
    for (int number : array)
        cout << number << ' ';
    cout << endl;
}