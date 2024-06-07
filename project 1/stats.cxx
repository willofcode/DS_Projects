//Name: William Ng
// email: wng003@citymail.cuny.edu
// FILE: stats.cxx
// CLASS IMPLEMENTATION: statistician
#include <iostream>
#include <cassert>
#include "stats.h"
using namespace std;
namespace main_savitch_2C {

statistician::statistician() {
    count = 0;
    total = 0;
    smallest = 0;
    largest = 0;
    recent_num = 0;
    }

void statistician::next(double r) {
    if (count == 0) {
        smallest = r;
        largest = r;
    } 
    else if (r < smallest) {
        smallest = r;
    }
    else if (r > largest) {
        largest = r;
    }

    count++;
    total += r;
    recent_num = r;
    }

void statistician::reset() {    // Reset the statistician to its initial state
    count = 0;
    total = 0;
    smallest = 0;
    largest = 0;
    }

int statistician::length() const {
    return count;
    }

double statistician::recent() const {
    return recent_num;
    }

double statistician::sum() const {
    return total;
    }

double statistician::mean() const {
    assert(count > 0);      // assert statement while its true
    return total / count;
    }

double statistician::minimum() const {
    assert(count > 0);      // assert statement while its true
    return smallest;
    }

double statistician::maximum() const {
    assert(count > 0);      // assert statement while its true
    return largest;
    }

// Overloaded + operator
statistician operator +(const statistician& s1, const statistician& s2)   {
    if (s1.length()== 0) // set s1 lenght to zero to return s2
        return s2;
    if (s2.length()== 0) // set s2 lenght to zero to return s1
        return s1;
    statistician result; // lenght are equal

    // Combine the counts and total sums of the two statisticians
    result.count = s1.count + s2.count;
    result.total = s1.total + s2.total;

    // Determine the minimum and maximum of the combined statisticians
    if (s1.smallest < s2.smallest) 
        result.smallest = s1.smallest;
    else 
        result.smallest = s2.smallest;
    if (s1.largest > s2.largest)    
        result.largest = s1.largest;
    else 
        result.largest = s2.largest;
    
    return result;
}

// Overloaded * operator to scale a statistician by a constant factor
statistician operator *(double scale, const statistician& s)    {
    statistician result;

    // Scale the count, total, smallest, and largest of the statistician
    result.count = s.count;
    result.total = scale * s.total;
    result.smallest = scale * s.smallest;
    result.largest = scale * s.largest;

    if (scale > 0) {
        result.smallest = scale * s.smallest;
        result.largest = scale * s.largest;
    }
    if (scale < 0) {
        result.largest = scale * s.smallest; 
        result.smallest = scale * s.largest;
    }

    return result;
    }

// Overloaded == operator to check if two statisticians are equal
bool operator ==(const statistician& s1, const statistician& s2)    {
    if (s1.length() != s2.length())
        return false;

    if (s1.length() == 0)
        return true;

    // Check if the means, minimums, maximums, and sums of both statisticians are equal
    return s1.mean() == s2.mean() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum() && s1.sum() == s2.sum();
    }
}