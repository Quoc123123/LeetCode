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

/********************* CHECK IF N AND ITS DOUBLE EXIST ******************************
*************************************************************************************/
bool checkIfExist(std::vector<int>& arr) {
    bool isExist = false;
    int lenght = arr.size();

    std::vector<int>arrAfterMultipleTwo(lenght);

    for(int i = 0; i < lenght; i++)
    {
        arrAfterMultipleTwo[i] = arr[i] * 2;
    }

    for(int i = 0; i < lenght; i++)
    {
        for(int j = 0; j < lenght; j++)
        {
            if(arr[i] == arrAfterMultipleTwo[j])
            {
                if(i != j)
                {
                    isExist = true;
                    break;
                }
            }
        }
        if(isExist)
        {
            break;
        }
    }

    return isExist;
}



int main()
{
    std::vector<int> nums1 = {10,2,5,3};
    std::cout << checkIfExist(nums1) << std::endl;

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
