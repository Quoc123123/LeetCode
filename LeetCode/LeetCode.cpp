// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


/****************************** MERGE SORTED ARRAY **********************************
************************************************************************************/
void insertIntoArraySortedNonDecs(std::vector<int>& arr, int element, int sizeCurrent)
{
    int lowPosition = 0;
    int highPosition = sizeCurrent - 1;
    int midPosition = 0;
    int lenght = arr.size();

    while(lowPosition < highPosition)
    {
        midPosition = (lowPosition + highPosition) / 2;
    
        if(arr[midPosition] < element)
        {
            lowPosition = midPosition + 1;
        }
        else
        {
            highPosition = midPosition;
        }
    }   

    if(lenght == 1)
    {
        arr[lowPosition] = element;
    }
    else
    {
        if((arr[lowPosition] > element) || (sizeCurrent == 0))
        {
            for(int i = lenght - 1; i > lowPosition; i--)
            {
                arr[i] = arr[i - 1];
            }
        }
        else
        {
            for(int i = lenght - 1; i > lowPosition + 1; i--)
            {
                arr[i] = arr[i - 1];
            }
            ++lowPosition;
        }
        arr[lowPosition] = element;
    }
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int totalElementsOfArrayOne = m;
    int totalElementsOfArrayTwo = n;

    int i = 0;
    int j = 0;
    int k = totalElementsOfArrayOne;

    while(((i < totalElementsOfArrayOne) && (j < totalElementsOfArrayTwo)) 
    || (i < totalElementsOfArrayOne) || (j < totalElementsOfArrayTwo))
    {
        if((i < totalElementsOfArrayOne) && (j < totalElementsOfArrayTwo))
        {
            if(nums1[i] < nums2[j])
            {
               insertIntoArraySortedNonDecs(nums1,  nums2[j], k);
               ++k;
               ++j;    
              
            }
            else
            {
               ++i; 
            }
        }
        else if(i < totalElementsOfArrayOne)
        {
           ++i;
        }
        else
        {
            insertIntoArraySortedNonDecs(nums1, nums2[j], k);
            ++j;
            ++k;
        }
    }
}


/****************************** INPUT/OUTPUT **********************************
************************************************************************************/
void printArray(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    merge(nums1, m, nums2, n);
    printArray(nums1);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
