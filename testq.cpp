#include "q.h"

int main() {
  Q<int> q;
  q.enq(1);  q.enq(2);  q.enq(3);
  Q<int> q2(q), q3=q;
  assert( q.deq() == 1 );   assert( q.deq() == 2 );   assert( q.deq() == 3 );
  assert( q2.deq() == 1 );   assert( q2.deq() == 2 );   assert( q2.deq() == 3 );
  assert( q3.deq() == 1 );   assert( q3.deq() == 2 );   assert( q3.deq() == 3 );

};
