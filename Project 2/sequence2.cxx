// Name: William Ng
// Email: _____wng003@citymail.cuny.edu_____
// FILE: sequence2.cxx
// CLASS PROVIDED: sequence (part of the namespace main_savitch_4)
// Implementation File for sequence2
#include <algorithm>
#include "sequence2.h"
#include <cassert>

using namespace std;
namespace main_savitch_4
{
    sequence::sequence(sequence::size_type initial_capacity) //Constructor
    {
        data = new sequence::value_type[initial_capacity];
        capacity = initial_capacity;
        current_index = 0;
        used = 0;
    }
    sequence::sequence(const sequence &source) //Copy Constructor
    {
        if (this == &source)
            return; //Self Assignment statement Checked
        //delete [] data;
        data = new sequence::value_type[source.capacity];
        capacity = source.capacity;
        current_index = source.current_index;
        used = source.used;
        copy(source.data, source.data + source.used, data);
    }
    sequence::~sequence() //Destructor
    {
        delete [] data;
    }
    void sequence::resize(size_type new_capacity)
    {
        if(new_capacity > used)
        {
            value_type *new_data;
            capacity = new_capacity;
            new_data = new value_type[capacity];
            copy(data, data + used, new_data);
            delete [] data;
            data = new_data;
        }
    }
    void sequence::start()
    {
        current_index = 0;
    }
    void sequence::advance()
    {
        if(is_item())
            current_index++;
    }
    void sequence::insert(const value_type &entry)
    {
        if (capacity <= used) // Augment the size of capacity to ensure program doesn't crash
            resize(size()*1.1);

        if (!is_item())
        {
            if (used == 0) //When no items on array
                data[0] = entry;
            else
            {
                current_index = 0; //No current item, assign value to the front index
                for (sequence::size_type i = used; i > 0; i--)
                    data[i] = data[i - 1];
                current_index++;
                data[0] = entry;
            }
            used++;
        }
        else
        {
            for (sequence::size_type i = used; i > current_index; i--) // Current exists
                data[i] = data[i - 1];
            data[current_index] = entry;
            used++;
        }
    }
    void sequence::attach(const value_type &entry)
    {
        if (capacity <= size())
            resize(size()+1);

        if (!is_item())
            data[current_index] = entry;
        else
        {
            for(sequence::size_type i = used; i > current_index; i--)
                data[i] = data[i-1];
            data[++current_index] = entry;
        }
        used++;
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(sequence::size_type i = current_index; i < size(); i++)
            data[i] = data[i+1];
        used--;
    }
    void sequence::operator=(const sequence &source)
    {
        if(this == &source)
            return;
        delete [] data;
        data = new sequence::value_type[source.capacity];
        current_index = source.current_index;
        used = source.used;
        copy(source.data, source.data + used, data);
    }
    sequence::size_type sequence::size() const
    {
        return used;
    }
    bool sequence::is_item() const
    {
        return (current_index >= 0 && (current_index < size()));
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return data[current_index];
    }
}