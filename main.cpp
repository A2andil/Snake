#include <vector>
#include <a_star.h>
#include <deque>
#include <stdlib.h>

node *get_goal(node **snake, int l) {
       vector<node*> goal;
       for (int i = 0; i < MAXH; i += 20)
              for (int j = 0; j < MAXW; j+= 20) {
                     bool add = true;
                     for (int n = 0; n < l; n++) {
                            if (snake[n]->x == j && snake[n]->y == i) {
                                   add = false;
                                   break;
                            }
                     }
                     if (add == true) {
                            node *nd = new node(j, i, 0);
                            goal.push_back(nd);
                     }
              }
              cout << goal.size() << " " << rand() % goal.size()<< endl;
              srand(time(NULL));
      return goal[rand() % goal.size()];
}

void move(node **snake, int l, stack<node*> *solution, a_star *s) {
       if (!solution->size()) {
           // code here to end game
           cout << "failed to get solution" << endl;
           return;
       }
       int i, j, idx = 0;
       deque<node*> *dq = new deque<node*>();
       for (i = 0; i < l; i++) dq->push_back(snake[i]);
       while (solution->size() > 1) {
              dq->push_front(solution->top()), solution->pop();
              dq->pop_back();
       }
       dq->push_front(solution->top()), l++;
       while (idx < l) {
              snake[idx] = dq->front();
              dq->pop_front(), idx++;
       }
       //print
       cout <<"snake ================ size = " << l << endl;
       //for (int j = 0; j < l; j++)
              // cout << snake[j]->x << " " << snake[j]->y << endl;
       node *dest = get_goal(snake, l);
       cout << dest->x << " " << dest->y << endl;
       s->reset(dest, snake, l);
       move(snake, l, s->solution, s);
}

int main() {
       node **snake = new node*[MAXH/20 * MAXW/20];
       node *c = new node(20, 20, 0), *dest = new node(100, 20, 0)
               , *d = new node(40, 20, 0);
       snake[0] = c, snake[1] = d;
       a_star *s = new a_star(dest, snake, 2);
       move(snake, 2, s->solution, s);
       return 0;
}

