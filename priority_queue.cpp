#include "priority_queue.h"

priority_queue::priority_queue() {
    lst = new node*[(int)1e7];
}

void priority_queue::insert(node* n) {
    lst[s++] = n;
    int i = s - 1;
    while (i && lst[(i - 1) / 2]->d > lst[i]->d) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void priority_queue::pop() {
    lst[0] = lst[--s];
    update(0);
}

node* priority_queue::top() {
    return lst[0];
}

bool priority_queue::isEmpty() {
    return !s;
}

void priority_queue::update(int i) {
    int sm = i, l = 2*i + 1, r = 2*i + 2;
    if (l < s && lst[l]->d < lst[sm]->d) sm = l;
    if (r < s && lst[r]->d < lst[sm]->d) sm = r;
    if (i != sm) {
        swap(sm, i), update(sm);
    }
}

void priority_queue::swap(int x, int y) {
    node* tmp = lst[x];
    lst[x] = lst[y], lst[y] = tmp;
}
