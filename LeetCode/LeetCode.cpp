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

/*************************** SQUARES OF A SORTED ARRAY ******************************
*************************************************************************************/
std::vector<int> sortedSquares(std::vector<int>& nums) {
        int leftPosition = 0;
        int rightPosition = nums.size() - 1;
        std::vector<int> result(nums.size());
        

        int leftValue = 0;
        int rightValue = 0;

        for(int i = rightPosition; i >= 0; i--)
        {
            leftValue = nums[leftPosition] * nums[leftPosition];
            rightValue = nums[rightPosition] * nums[rightPosition];
            if(leftValue > rightValue)
            {
                result[i] = leftValue;
                ++leftPosition;
            }
            else
            {
                result[i] = rightValue;
                --rightPosition;
            }
        }
        return result;
}


int main()
{
    std::vector<int> nums1 = {-4,-1,0,3,10};
    std::vector<int> result = sortedSquares(nums1);
    printArray(result);
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
