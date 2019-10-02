#include "a_star.h"

a_star::a_star(node *goal, node **snke, int l) {
    lst->insert(snke[0]);
    snake = snke, dest = goal, length = l;
    begin();
}

void a_star::reset(node *goal, node **snke, int l) {
       lst->reset();
       solution = new stack<node*>();
       lst->insert(snke[0]);
       snake = snke, dest = goal, length = l;
       begin();
}

void a_star::begin() {
       auto start = chrono::system_clock::now();
       while(!lst->isEmpty()) {
              node* top = lst->top();
              lst->pop();
              if (top->x == dest->x && top->y == dest->y) {
                     while (top->parent != nullptr) {
                            solution->push(top);
                            top = top->parent;
                     }
                     return;
              }
              auto now = chrono::system_clock::now();
              chrono::duration<double> t = now - start;
              if (t.count() > 1.0) return;
              get_child(top);
       }
}

void a_star::get_child(node *top) {
    for(int i = 0; i < 4; i++) {
        if ((top->x + dx[i] >= 0 && top->y + dy[i] >= 0)
              && is_safe(top->x + dx[i], top->y + dy[i], top)) {
                     node *c = new node(top->x + dx[i],
                                        top->y + dy[i], top->level + 1);
                    c->d = abs(c->x - dest->x) + abs(c->y - dest->y)
                            , c->parent = top; // |x1-x2| + |y1 - y2|
                     lst->insert(c);
        }
    }
}

bool a_star::is_safe(int x, int y, node *nd) {
       if (x > MAXW - 20 || y > MAXH - 20) return false;
       node *temp = new node(x, y, nd->level + 1);
       int step = min(temp->level, length);
       for (int i = 0; i < length - temp->level; i++)
              if (snake[i]->x == temp->x && snake[i]->y == temp->y)
                     return false;
       while (step > 0) {
              if (temp->x == nd->x && temp->y == nd->y) return false;
              nd = nd->parent, step -= 1;
       }
       if (length == 2 && temp->level == 1
              && x == snake[1]->x && snake[1]->y == y) return false;
       return true;
}
