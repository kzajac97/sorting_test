#include "array.hh"

template<typename type_t>
void print(std::vector<type_t> array)
{
    for(unsigned int i=0; i<array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

template<typename type_t>
const bool isSorted(std::vector<type_t> array)
{
    for(unsigned int i=0; i<(array.size()-1); i++)
    {
        if(array[i] > array[i+1])
            return false;
    }
    return true;
}

template <typename type_t>
void randomArrayGenerator(std::vector<type_t> &array, int size, float sorted)
{
    //class constructor
    std::default_random_engine generator(seed_t);
    //random numbers from 0 to 10 times size with possible duplicates
    std::uniform_int_distribution<int> distribution(0,100);
    
    for(int i=0; i<size; i++)
    {
        //casting float to int
        if(i < (int)size*sorted)
            array[i] = i;
        else
            array[i] = distribution(generator);
    }
}

template <typename type_t>
inline void arrayGenerator(std::vector<type_t> &array, int size)
{
    for(int i=0; i<size; i++)
        array.push_back(i);
}