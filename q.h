#ifndef Q_H_
#define Q_H_

#include <cassert> // assert
// link list implementation of a queue.

template < class Data > class Q {
  struct Link {
    Data data;
    Link *oldest; // the oldest link newer than this one
    Link ( Data d ):data(d), oldest(0){};
  };
  Link *oldest;
  Link *newest;
 public:
 Q(): oldest(0), newest(0){};
  bool invariant() {
    return (this->oldest == 0) == (this->newest == 0);
  };
  bool empty() {
    assert(this->invariant());
    return this->newest == 0;
  };
  void enq ( Data d ) {
    Link *l = new Link ( d );
    if ( this->empty() ) {
      this->oldest = l;
    }
    else {
      this->newest->oldest = l;
    }
    this->newest = l;
    assert(this->invariant());
  };
  Data deq () {
    assert (! this->empty() );
    Link *l = this->oldest;
    Data d = l->data;
    this->oldest = l->oldest;
    if ( this->oldest == 0 ) {
      assert ( this->newest == l );
      this->newest = 0;
    }
    delete l;
    assert ( this->invariant() ); 
    return d;
  };
};
  
#endif // Q_H_
