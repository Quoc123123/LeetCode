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

/********************* REMOVE DUPLICATES FROM SORTED ARRAY **************************
*************************************************************************************/
int removeDuplicates(std::vector<int>& nums) {
    int lenght = nums.size();
    int preValue = nums[0];
    int curValue = preValue;
    int j = 0;
    int i = 0;
    for(i = 0; i < lenght; i++)
    {
        curValue = nums[i];
        if(curValue != preValue)
        {
            nums[j++] = preValue;
            preValue = curValue;
        }
    }
    nums[j++] = preValue;
    return j;
}


int main()
{
    std::vector<int> nums1 = {1,1,2};
    int result = removeDuplicates(nums1);
    printArray(nums1);
    std::cout << result << std::endl;
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
