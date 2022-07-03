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

/****************************** MAX CONSECUTIVE ONES ********************************
*************************************************************************************/
int findMaxConsecutiveOnes(std::vector<int>& nums) {
       int countConsecutiveNumberOnes = 0;
        int maxConsecutiveNumberOnes  = 0;

        for(auto it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it == 1)
            {
                ++countConsecutiveNumberOnes;
                if(maxConsecutiveNumberOnes < countConsecutiveNumberOnes)
                {
                    maxConsecutiveNumberOnes = countConsecutiveNumberOnes;
                }
            }
            else
            {
                countConsecutiveNumberOnes = 0;
            }
        }
    return maxConsecutiveNumberOnes;
}


int main()
{
    std::vector<int> nums1 = {1,1,0,1,1,1};
    std::cout << findMaxConsecutiveOnes(nums1) << std::endl;
    
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
