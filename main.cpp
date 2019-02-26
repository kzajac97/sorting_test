#include <iostream>
#include <chrono>
#include <algorithm>
#include <cassert>
#include <array>
#include <thread>
#include <vector>
#include <functional>
#include "sort.hh"
#include "sort.cpp"
#include "array.hh"
#include "array.cpp"

using namespace std;

int main(void)
{
    //number of tests performed on every array size
    const int testNumber = 100;
    //sizes of tested arrays
    const array<int,5> arraySizes = {10000,50000,100000,500000,1000000};
    //sorted part of tested arrays number beetween 0 and 1
    const array<float,8> sorted = {0,0.25,0.5,0.75,0.95,0.99,0.997,1};
    //file stream variable
    fstream outFile ("data.txt");
    //vector for storing sorting times
    vector<double> timesMeasured;
    vector<int> array;

    arrayGenerator(array,1000000);
    arrayShuffle(array,0);
    //print(array);
    introsortCaller(array);
    if(isSorted(array))
        cout << "sorted\n";
    else
        cout << "not sorted\n";
    
    /*
    for(unsigned int i=0; i<arraySizes.size(); i++)
    {  
        //allocate array with size passed as parameter
        arrayGenerator(array,arraySizes[i]);
        //ensuring vector has enough memory
        array.reserve(arraySizes[i]);
        for(unsigned int j=0; j<sorted.size(); j++)
        {
            for(unsigned int k=0; k<testNumber; k++)
            {
                //shuffle elements in array with sorted %
                arrayShuffle(array,sorted[j]);
                if(sorted[j] == 1)
                    //reverse case
                    reverse(array.begin(),array.end());

                //set timer
                chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
                //mergesortCaller(array); 
                //quicksortCaller(array); 
                introsortCaller(array);
                //sort(array.begin(),array.end());
                //heapsortCaller(array);
                chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
                //casting chrono time point type to double and computing time function took to sort an array
                chrono::duration<double,micro> diff = chrono::duration_cast<chrono::duration<double,micro>> (end-start);
                cout << arraySizes[i] << " " << sorted[j] *100<< "% " <<diff.count() << "\u03BCs\n"; 
                //if array is sorted save time to vector 
                if(isSorted(array))
                    timesMeasured.push_back(diff.count()); 
                else
                    assert(0);
            }

            //write to file
            if(outFile.is_open())
            {
                //saving size
                outFile << arraySizes[i] << " ";
                //saving sorted percentage
                outFile << sorted[j] * 100 << " ";
                //saving an average of all times measured
                outFile << average(timesMeasured) << "\n";
            }
            timesMeasured.clear();
        } 
        array.clear();
    }
outFile.close();
//*/
}