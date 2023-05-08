// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/********************************** INPUT/OUTPUT ************************************
************************************************************************************/
template <typename T>
void print_output(vector<T> &input)
{
    for (const auto &iteration : input)
    {
        cout << iteration << " ";
    }
    cout << endl;
}

vector<string> fizzBuzz(int n)
{
    vector<string> result;
    bool is_divisible_by3 = false;
    bool is_divisible_by5 = false;

    for (uint16_t i = 1; i <= n; i++)
    {
        is_divisible_by3 = i % 3 == 0 ? true : false;
        is_divisible_by5 = i % 5 == 0 ? true : false;

        if (is_divisible_by3 && is_divisible_by5)
        {
            result.push_back("FizzBuzz");
        }
        else if (is_divisible_by3)
        {
            result.push_back("Fizz");
        }
        else if (is_divisible_by5)
        {
            result.push_back("Buzz");
        }
        else
        {
            result.push_back(to_string(i));
        }
    }

    return result;
}

// Time complexity = O(n2)
// Space complexity = O(1)
void sortColors(vector<int> &nums)
{
    uint16_t len = nums.size();
    uint16_t min_index = 0;

    for (uint16_t i = 0; i < len; i++)
    {
        min_index = i;
        for (uint16_t j = i + 1; j < len; j++)
        {
            if (nums[min_index] > nums[j])
            {
                min_index = j;
            }
        }

        int temp_value = nums[min_index];
        nums[min_index] = nums[i];
        nums[i] = temp_value;
    }
}

int main()
{
    // vector<int> result = {2, 0, 2, 1, 1, 0};
    vector<int> result = {0, 1};

    sortColors(result);
    print_output(result);

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
