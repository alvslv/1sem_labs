#include <iostream>
#include <functional>


struct node {
    unsigned value;
    node* next = nullptr;

    node() {}
    node(node* next): next(next) {}
    node(unsigned value, node* next): value(value), next(next) {}

    ~node() {
        delete next;
    }
};


node* push_front(node* first, unsigned value) {
    auto new_element = new node(value, first);
    return new_element;
}


void erase_after(node* after, node* first, node* last) {
    if (after == last || after->next == last)
        throw std::range_error("can't erase the end of forward list");

    auto erasing_node = after->next;
    after->next = after->next->next;
    erasing_node->next = nullptr;
    delete erasing_node;
}


node* remove_if(node* first, node* last, std::function<bool(unsigned)> pred) {
    auto before_begin = new node(first);

    for (auto ptr = before_begin; ptr->next != last;)
        if (pred(ptr->next->value))
                erase_after(ptr, first, last);
            else
                ptr = ptr->next;

    auto tmp = before_begin->next;
    before_begin->next = nullptr;
    delete before_begin;

    return tmp;
}


void sort(node* first, node* last, std::function<bool(unsigned, unsigned)> pred) {
    for (auto i = first; i != last;) {
        for (auto j = i; j != last;) {
            if (pred(i->value, j->value))
                std::swap(i->value, j->value);

            j = j->next;
        }

        i = i->next;
    }
}
