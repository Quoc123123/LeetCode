// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

/********************************** INPUT/OUTPUT ************************************
************************************************************************************/
void printArray(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**************************** VALID MOUNTAIN ARRAY **********************************
*************************************************************************************/
int getIndexMaxValueOfArray(std::vector<int>& arr)
{
    int maxValue = arr[0];
    int lenght = arr.size();
    int index = 0;
    
    for(int i = 1; i < lenght; i++)
    {
        if(maxValue < arr[i])
        {
            maxValue = arr[i];
            index = i;
        }
    }

    return index;
}    
    
bool validMountainArray(std::vector<int>& arr) {
    bool isMountainArray = false;
    int maxValueIndex = getIndexMaxValueOfArray(arr);
    int lenght = arr.size();


    for(int i = 0; i <= maxValueIndex - 1; i++)
    {
        if(arr[i] >= arr[i + 1])
        {
            isMountainArray = false;
            break;
        }
        else
        {
            isMountainArray = true;
        }
    }

    if(isMountainArray)
    {
        isMountainArray = false;
        for(int i = maxValueIndex; i < lenght - 1; i++)
        {
            if(arr[i] <= arr[i + 1])
            {
                isMountainArray = false;
                break;
            }
            else
            {
                isMountainArray = true;
            }
        }
    }
    return isMountainArray;
}

std::vector<int> replaceElements(std::vector<int>& arr) 
{
    // int lenght = arr.size();
    // int a = -1, b = 0;
    // for(int i = lenght - 1; i >= 0; i--)
    // {
    //     b = arr[i];
    //     arr[i] = a;
    //     if(a < b)
    //     {
    //         a = b;
    //     }
    // }

    int lenght = arr.size();
    int maxValue = 0;
    int i = 0;

    for(i = 0; i < lenght - 1; i++)
    {
        for(int j = i + 1; j < lenght; j++)
        {
            if(maxValue < arr[j])
            {
                maxValue = arr[j];
            }
        }
        arr[i] = maxValue;
        maxValue = 0; 
    }

    arr[i] = -1;

    return arr;
}

int main()
{
    std::vector<int> nums1 = {2,1};
    std::cout << validMountainArray(nums1) << std::endl;

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
