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

/****************************** REMOVE ELEMENT ***************************************
*************************************************************************************/
int removeElement(std::vector<int>& nums, int val) {
    int i = 0;
    int j = 0;
    int lenght = nums.size();

    for(int i = 0; i < lenght; i++)
    {
        if(nums[i] != val)
        {
            nums[j++] = nums[i];
        }
        else
        {
            nums[i] = 0;
        }
    }

    return j;
}

int main()
{
    std::vector<int> nums1 = {3,2,2,3};
    int val = 3;
    std::cout << removeElement(nums1, val) << std::endl;
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
