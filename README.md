# cppQ
Linked list implementation of a FIFO queue in c++.

Example:

    #include "q.h"

    int main() {
      Q<int> q;
      q.enq(1);  q.enq(2);  q.enq(3);
      assert( q.deq() == 1 );   assert( q.deq() == 2 );   assert( q.deq() == 3 );
    };
