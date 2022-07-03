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

/******************* FIND NUMBERS WITH EVEN NUMBER OF DIGITS *************************
*************************************************************************************/
bool isNumberOven(const int &input_num)
{
    int value = input_num;
    int countNumberOfValue = 0;
    
    do
    {
        value = value / 10;
        ++countNumberOfValue;
    } while (value != 0);
    
    if((countNumberOfValue % 2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findNumbers(std::vector<int>& nums) {
    int contNumberOven = 0;

    for(auto it = nums.begin(); it != nums.end(); ++it)
    {
        if(true == isNumberOven(*it))
        {
            ++contNumberOven;
        }
    }

    return contNumberOven;
}


int main()
{
    std::vector<int> nums1 = {12,345,2,6,7896};
    std::cout << findNumbers(nums1) << std::endl;
    
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
