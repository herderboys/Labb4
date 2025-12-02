// Alexander Herder

//  Trad.h
//  labb4_tree


#ifndef TRAD_H
#define TRAD_H

#include <iostream>

class Trad {
  
public:
  Trad() : rot(0) {};                    // default konstruktor
  Trad( int d ) { rot= new Nod(d); };
  Trad( const Trad& t ) { kopiera(t); };   // kopieringskonstruktor
  ~Trad() { delete rot; };
  
  bool tomt() const { return !rot; };
  int& varde() const
  {
    koll();
    return rot->data;
  };
  Trad& v_barn() const
  {
    koll();
    return *rot->vanster;
  };
  Trad& h_barn() const
  {
    koll();
    return *rot->hoger;
  };
  Trad& operator= ( const Trad& );
  bool operator== ( const Trad& ) const;
  void skriv_ut() const;
  
private:
  class Nod {
    friend class Trad;
    int data;
    Trad *vanster, *hoger;
    Nod( int d ) : data( d ), vanster( new Trad ), hoger( new Trad ) {};
    ~Nod()
    {
      delete vanster;
      delete hoger;
    };
  }; // end class Nod

  Nod *rot;
  void koll() const
  {
    if ( tomt() )
      throw std::range_error( "Trad" );
  }
  void kopiera( const Trad& t );
};

#endif /* Trad_h */
