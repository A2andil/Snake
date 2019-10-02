#ifndef A_STAR_H
#define A_STAR_H
#include <priority_queue.h>
#include <cmath>
#include <stack>
#include <chrono>
#include <ctime>

#define MAXH 600
#define MAXW 1000

class a_star {
public:
    int length = 0;
    stack<node*> *solution = new stack<node*>();
    a_star(node *goal, node **snke, int l);
    void reset(node *goal, node **snke, int l);
protected:

private:
    int dx[4] = {0, 0, 20, -20};
    int dy[4] = {20, -20, 0, 0};
    node **snake;
    node *dest;
    priority_queue *lst = new priority_queue();
    void begin();
    void get_child(node *n);
    bool is_safe(int x, int y, node *nd);
};

#endif // A_STAR_H
