// Provided by:   ____________(William Ng)__________
// Email Address: ____________(wng003@citymail.cuny.edu)________
// FILE: stats.h
// CLASS PROVIDED: statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the statistician class:
//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.            
//
// PUBLIC CONSTANT member functions for the statistician class:
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions for the statistician class:
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum,
//     the same maximum, and the same sum.
//
// VALUE SEMANTICS for the statistician class:
// Assignments and the copy constructor may be used with statistician objects.

#ifndef wng003_STATS_H 
#define wng003_STATS_H
#include <iostream>

namespace main_savitch_2C {

class statistician {
    
    public: 
        statistician();         // CONSTRUCTOR for the statistician class
        void next(double r);     // PUBLIC MODIFICATION member functions for the statistician class
        void reset();
        int length() const;     // PUBLIC CONSTANT member functions for the statistician class
        double recent() const;  
        double sum() const;
        double mean() const;
        double minimum() const;
        double maximum() const;

        friend statistician operator +   // FRIEND FUNCTION
            (const statistician& s1, const statistician& s2);
        friend statistician operator *
            (double scale, const statistician& s);

    private:
        int count;              // count how many numbers in the sequence
        double total;           // represent sum of all the numbers in the sequence
        double smallest;        // store smallest number in the sequence
        double largest;         // store largest number in the sequence
        double recent_num;      // store most recent number in the sequence
        };  

        bool operator == (const statistician& s1, const statistician& s2); // NON-MEMBER functions for the statistician class
}

#endif
