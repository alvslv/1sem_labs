#include <iostream>
#include "forward_list.cpp"


unsigned get_digits_count(unsigned number) {
    unsigned sum = 0;
    for (; number > 0; number /= 10)
        sum += 1;

    return sum;
}


bool number_condition(unsigned number) {
    if (number >= 100 && number <= 999) {
        for (; number > 0; number /= 10)
            if ((number % 10) % 2 != 0)
                return false;
    } else
        return false;

    return true;
}


unsigned get_first(unsigned number) {
    while (number >= 10)
        number /= 10;

    return number;
}


int main() {
    unsigned n;
    std::cin >> n;

    node* last = new node();
    node* first = last;

    unsigned number;
    bool condition = false;

    for (int i = 0; i < n; i++) {
        std::cin >> number;
        first = push_front(first, number);
        if (number_condition(number))
            condition = true;
    }

    if (condition) {
        sort(first, last, [](unsigned a, unsigned b) {
            return get_first(a) > get_first(b);
        });
    } else {
        first = remove_if(first, last, [](unsigned number) {
            return get_digits_count(number) % 2 == 0;
        });

        for (node* i = first; i != last;) {
            first = push_front(first, i->value);
            i = i->next;
        }
    }

    for (node* i = first; i != last;) {
        std::cout << i->value << ' ';
        i = i->next;
    }
    std::cout << std::endl;

    delete first;
}
