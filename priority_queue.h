#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
using namespace std;

struct node {
public:
    int x, y, level = 0;
    double d = 0;
    node *parent = nullptr;
    node(int n, int m, int l) {
        x = n, y = m, level = l;
    }
};

class priority_queue {
public:
    int s = 0;
    priority_queue();
    void insert(node* n);
    void pop();
    node* top();
    bool isEmpty();
    void reset() {
        s = 0;
    }
private:
    node** lst;
    void update(int i);
    void swap(int x, int y);
};

#endif // PRIORITY_QUEUE_H
