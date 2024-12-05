// var 3: 4.Сначала введите последовательность. Затем удалите и продублируйте элементы.
// Затем выведите полученную последовательность (каждый элемент по одному разу). 
// Используйте в программе только один массив.

// Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
// Удалить из последовательности числа, содержащие хотя бы пару одинаковых цифр, 
// а среди оставшихся продублировать числа,   содержащие цифру 5.
#include <iostream>
using namespace std;


bool has_repeat(unsigned number) {
    for (unsigned digit1 = number; digit1 > 0; digit1 /= 10)
        for (unsigned digit2 = digit1 / 10; digit2 > 0; digit2 /= 10)
            if ((digit1 % 10) == (digit2 % 10))
                return true;
    return false;
}


bool has_5(unsigned number) {
    for (; number > 0; number /= 10)
        if (number % 10 == 5)
            return true;
    return false;
}


int main() {
    unsigned n;
    cout << "n: ";
    cin >> n;

    unsigned array[n * 2];

    cout << "sequence: ";
    for (unsigned i = 0; i < n * 2; i++) {
        if (i < n)
            cin >> array[i];
        else
            array[i] = 0;
    }

    for (unsigned i = 0; i < n * 2; i++) {
        if (has_repeat(array[i])) {
            array[i] = 0;
            continue;
        }

        if (array[i] > 0 && has_5(array[i]))
            array[n * 2 - i - 1] = array[i];
    }

    cout << "answer:   ";
    for (unsigned number : array) {
        if (number > 0)
            cout << number << ' ';
    }
    cout << endl;
}