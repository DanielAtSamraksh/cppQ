#ifndef Q_H_
#define Q_H_
#include <algorithm> // std::swap
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

  friend void swap ( Q& x, Q& y ) {
    std::swap(x.oldest, y.oldest); // repeat for all elements
    std::swap(x.newest, y.newest);
  };
    
  /** Copy constructor */
  Q (const Q& other) {
    this->oldest = 0; this->newest = 0;
    for (Link *l = other.oldest; l; l = l->oldest ) {
      this->enq ( l->data );
    }
  };
  /** Copy assignment operator */
  Q& operator= ( Q other ) {
    this->swap ( *this, other); 
    return *this;
  };
  /** Destructor */
  ~Q() /* noexcept */ { /* explicitly specified destructors should be
		       annotated noexcept as best-practice */
    while ( ! this->empty() ) this->deq();
  };

  // C++11
  /* /\** Move constructor *\/ */
  /* Q (Q&& other) noexcept { /\* noexcept needed to enable optimizations in containers *\/ */
  /*   this->oldest = other.oldest; */
  /*   this->newest = other.newest; */
  /*   other.oldest = 0; other.newest = 0; */
  /* }; */
  /* /\** Copy assignment operator *\/ */
  /* Q& operator= (const Q& other) { */
  /*   Q tmp(other); // re-use copy-constructor */
  /*   *this = std::move(tmp); // re-use move-assignment */
  /*   return *this; */
  /* }; */
  /* /\** Move assignment operator *\/ */
  /* Q& operator= (Q&& other) noexcept { */
  /*   // simplified move-constructor that also protects against move-to-self. */
  /*   std::swap(this->oldest, other.oldest); // repeat for all elements */
  /*   std::swap(this->newest, other.newest); */
  /*   return *this; */
  /* }; */
 
};
  
#endif // Q_H_
