// Name:______ william Ng________
//FILE: pqueue2.cxx
// IMPLEMENTS: PriorityQueue (See pqueue2.h for documentation.)
// IMPLEMENTED BY: (wng003@citymail.cuny.edu)
//
// NOTE: You will need -lm at the end of your compile line to pick up
// the math library!

// INVARIANT for the PriorityQueue Class:
//   1. The member variable many_items is the number of items in the
//      PriorityQueue.
//   2. The items themselves are stored in the member variable heap,
//      which is a partially filled array organized to follow the usual
//      heap storage rules from Chapter 11 of the class notes.
// NOTE: Private helper functions are implemented at the bottom of this
// file along with their precondition/postcondition contracts.
 
#include <cassert>    // Provides assert function
#include <iomanip>    // Provides setw
#include <iostream>   // Provides cin, cout
#include <cmath>      // Provides log2
#include "pqueue2.h"
using namespace std;

PriorityQueue::PriorityQueue( ) // Constructor
{
    // -- Student will implement this.
    many_items = 0;
}
// Modification Member Function
void PriorityQueue::insert(const Item& entry, unsigned int priority)
{
    // -- Student will implement this.
    heap[many_items].data = entry;
    heap[many_items].priority = priority;

    size_t current_index = many_items;
    while(current_index>0)
    {
        if(heap[current_index].priority > heap[parent_index(current_index)].priority)
            swap_with_parent(current_index);
            current_index= parent_index(current_index);
    }
    many_items++;
}

PriorityQueue::Item PriorityQueue::get_front()
{
    assert (size() > 0); // precondition for function execution
    Item front_index;
    front_index = heap[0].data;
    size_t last_index = many_items-1;
    
    heap[0].data = heap[last_index].data;
    heap[0].priority = heap[last_index].priority;
    many_items--; 
    size_t current_index = 0;
    if(size() > 1)
        {
            while(!is_leaf(current_index))
            {
                if(heap[current_index].priority < heap[big_child_index(current_index)].priority)
                {
                size_t temp_index = big_child_index(current_index);
                swap_with_parent(temp_index);
                current_index = temp_index;
                }
                else{
                    break; // break is necessary otherwise test F will fail
                }
            }
        }
    return front_index;
}
// start of PRIVATE HELPER FUNCTION
bool PriorityQueue::is_leaf(size_t i) const
// Precondition: (i < many_items)
// Postcondition: If heap[i] has no children in the heap, then the function
// returns true. Otherwise the function returns false.
{
    // -- Student will implement this.
    assert (i < many_items);
    size_t left_child = 2*i + 1;
    size_t right_child = 2*i + 2;
    return ((left_child >= many_items) && (right_child >= many_items));
}

size_t PriorityQueue::parent_index(size_t i) const
// Precondition: (i > 0) && (i < many_items)
// Postcondition: The return value is the index of the parent of heap[i].
{
    // -- Student will implement this.
    //assert ((i>0) &&(i< many_items));
    return (i-1)/2 ; // should be the index of the item
}

unsigned int PriorityQueue::parent_priority(size_t i) const
// Precondition: (i > 0) && (i < many_items)
// Postcondition: The return value is the priority of the parent of heap[i].
{
    // -- Student will implement this.
    //assert((i>0) && (i< many_items));
    return heap[parent_index(i)].priority;
}

size_t PriorityQueue::big_child_index(size_t i) const
// Precondition: !is_leaf(i)
// Postcondition: The return value is the index of one of heap[i]'s children.
// This is the child with the larger priority.
{
    // -- Student will implement this.
    assert(!is_leaf(i));
    if(heap[(2*i)+1].priority > heap[(2*i)+2].priority)
    {
        return (2*i)+1;
    }
    else
    {
        return (2*i)+2;
    }
}

unsigned int PriorityQueue::big_child_priority(size_t i) const
// Precondition: !is_leaf(i)
// Postcondition: The return value heap[big_child_index(i)].priority
{
    // -- Student will implement this.
    assert(!is_leaf(i));
    return heap[big_child_index(i)].priority;
}

void PriorityQueue::swap_with_parent(size_t i)
// Precondition: (i > 0) && (i < many_items)
// Postcondition: heap[i] has been swapped with heap[parent_index(i)]
{
    // -- Student will implement this.
    //assert((i>0) && (i< many_items));
    OneItemInfo temp_index;
    temp_index = heap[parent_index(i)];
    heap [parent_index(i)] = heap[i];
    heap[i] = temp_index;
}
// end of PRIVATE HELPER FUNCTION

// remove print_tree as instructed after finish testing all the other function