#include "sort.hh"

template <typename type_t>
int split(std::vector<type_t> &array, int first, int last)
{
    //array's indexes
    unsigned int i=first, j=last;
    
    while(true)
    {
        while (array[j] > array[first])
            j--;
        
        while (array[i] < array[first])
            i++;
    
        if (i<j)
            //swap and then increment indexes
            std::iter_swap(array.begin()+i++,array.begin()+j--);
        else
            //returns index as new pivot
            return j;
    }
}

template <typename type_t>
void merge(std::vector<type_t> &array, int first, int middle, int last)
{
    //dynamic array is faster than vector becasue 
    //method push_back takes quite a long time to allocate memory
    type_t *tmpArray = new type_t[last+1];
    
    //copying array 
    for (int i=first; i<=last; i++) 
        tmpArray[i] = array[i];
    
    //array's indexes 
    int i=first, j=first, k=middle+1; 

    //comparing arrays and sorting
    while(i <= middle && k <= last)  
        tmpArray[i] > tmpArray[k] ? array[j++] = tmpArray[k++] : array[j++] = tmpArray[i++];

    //copying sorted array
    while(i <= middle)
        array[j++] = tmpArray[i++];

    delete [] tmpArray;
}

template<typename type_t>
void mergesort(std::vector<type_t> &array, int first, int last)
{
    int middle;
    
    if(first < last)
    {
        middle = first +(last-first)/2;
        //splitting array on two equaly size arrays
        mergesort(array, first, middle);
        mergesort(array, middle+1,last);
        //merging arrays
        merge(array,first,middle,last);
    }
    else 
        return;
}

template <typename type_t>
void quicksort(std::vector<type_t> &array, int first, int last)
{
    int pivot;

    if(first < last)
    {
        pivot = split(array,first,last);
        quicksort(array,first,pivot);
        quicksort(array,pivot+1,last);
    }
    else
        return;
}

template <typename type_t>
void insertionsort(std::vector<type_t> &array, int first, int last)
{
    type_t tmp;
    int j;
    //first element is already sorted
    for(int i=first; i<(last-first); ++i)
    {
        tmp = array[i];
        j = i;
        //while element is smaller than current value
        while(j>0 && array[j-1] > tmp)
        {
            //insert element before current value
            array[j] = array[j-1];
            j--;
        }
        //if no smaller elements insert after current value
        array[j] = tmp;
    }
}

template <typename type_t>
void heapsort(std::vector<type_t> &array, int first, int last)
{
    //building max heap from an array
    buildHeap(array,first,last);
    //sorting array
    for(int i=last-1; i>first; --i)
    {
        //put largest element at the back of an array
        std::iter_swap(array.begin()+first,array.begin()+first+i);
        //heap properties could be violated, but children
        //are max heaps, calling heapify fixes this
        heapify(array,first,last,0);
    }
}

template <typename type_t>
void buildHeap(std::vector<type_t> &array, int first, int last) 
{
    //all elements from n/2 to n are leafs
    for(int i=last/2 - 1; i>=first; --i)
        heapify(array,first,last,i);
}

template <typename type_t>
void heapify(std::vector<type_t> &array, int first, int last, int index)
{
    //left and right indexes of an array based heap
    int leftIndex = getLeftIndex(index) + first;
    int rightIndex = getRightIndex(index) + first;
    int maxIndex = 0;
    
    //if left child is greater than current index
    if(leftIndex < (last-first) && array[leftIndex] > array[index]) 
        maxIndex = leftIndex;
    else 
        maxIndex = index;
    //if right child is greater than current index
    if(rightIndex < (last-first) && array[rightIndex] > array[maxIndex]) 
        maxIndex = rightIndex;

    //if largest value isn't current index swap
    if(index != maxIndex) 
    {   
        std::iter_swap(array.begin()+first+maxIndex,array.begin()+first+index);
        //fix heap's properties
        heapify(array, first, last, maxIndex);
    }
}

template <typename type_t>
void introsort(std::vector<type_t> &array, int first, int last, int depth)
{
    int pivot;

    if(first < last)
    {
        //worst quicksort case
        if(depth == 0)
        {
            //std::cout << "heap\n";
            heapsort(array,first,last);
        }

        //recusrively calling introsort and decrementing depth
        else
        {
            pivot = split(array,first,last);
            introsort(array,first,pivot,depth--);
            introsort(array,pivot+1,last,depth--);
        }

        if(last-first < introSortConstant)
        {
            
            insertionsort(array,first,last);
        }
    }

    else
        return;
}