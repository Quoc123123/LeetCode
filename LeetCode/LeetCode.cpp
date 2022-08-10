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

void moveZeroes(std::vector<int>& nums) 
{
    int i = 0;
    int j = 0;
    int lenght = nums.size();

    for(i = 0; i < lenght; i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }    

    for(i = j; i < lenght; i++)
    {
        nums[i] = 0;
    }
}

bool isEvenNumber(int number)
{
    if((number % 2) == 0)
    {
        return true;    
    }

    return false;
}

void swapNumber(std::vector<int>& nums, int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] =  nums[index2];
    nums[index2] = temp;
}

std::vector<int> sortArrayByParity(std::vector<int>& nums) {
    int lenght = nums.size();
    int leftIndex = 0;
    int rightIndex = lenght - 1;

    bool leftValue = false;
    bool rightValue = false;

    
    while(leftIndex < rightIndex)
    {
        leftValue = isEvenNumber(nums[leftIndex]);
        rightValue = isEvenNumber(nums[rightIndex]);

        if((false == leftValue) && (true == rightValue))
        {
    
            swapNumber(nums, leftIndex, rightIndex);
            leftIndex++;
            rightIndex--;

        }
        else if((true == leftValue) && (true == rightValue))
        {
            leftIndex++;
        }
         else if((true == leftValue) && (false == rightValue))
        {
            leftIndex++;
        }
        else
        {
            rightIndex--;
        }
    }

   
    return nums;
}


int heightChecker(std::vector<int>& heights) 
{
    int lenght = heights.size();
    int temp = 0; 
    int count = 0;
    std::vector<int> copy_heights = heights;

    for(int i = 0; i < lenght - 1; i++)
    {
        for (int j = i; j < lenght; j++)
        {
            if(heights[i] > heights[j])
            {
                temp = heights[i];
                heights[i] = heights[j];
                heights[j] = temp;
            }
        }
    }

    for(int i = 0; i < lenght; i++)
    {
        if(copy_heights[i] != heights[i])
        {
            ++count;
        }
        
    }

    return count;
}


int thirdMax(std::vector<int>& nums) {
    int result = 0;
    int temp = 0;
    int lenght = nums.size();

    // sort input
    for(int i = 0; i < lenght - 1; i++)
    {
        for (int j = i; j < lenght; j++)
        {
            if(nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    // remove duplicate
    int new_lenght = removeDuplicates(nums);
    
    if(new_lenght < 3)
    {
        result = nums[new_lenght - 1];
    }
    else
    {
        result = nums[new_lenght - 1 - 2];
    }
    return result;
}

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    int lenght = nums.size();
    std::vector<int> result;
    int current_value = 0;
    
    for(int i = 0; i < lenght ; i++)
    {
        current_value = abs(nums[i]);
        nums[current_value - 1] = -abs(nums[current_value - 1]);
    }

    for(int i = 0; i < lenght; i++)
    {
        if(nums[i] > 0)
        {
            result.push_back(i + 1);
        }
    }
    
    return result;
}


struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
private:
    SinglyListNode  *head_node;

public:
    MyLinkedList() {
        head_node = NULL;
    }
    
    int getLenght(void)
    {
        SinglyListNode  *cur_node = head_node;
        int count = 0;
        
        while(NULL != cur_node)
        {
            cur_node = cur_node->next;
            ++count;
        }

        return count;
    }
    
    
    int get(int index) {
        SinglyListNode  *cur_node = head_node;
        int count = 0;
        
        if(head_node == NULL)
        {
            return -1;
        }

        while(NULL != cur_node)
        {
            if(count == index)
            {
                return cur_node->val;
            }
            cur_node = cur_node->next;
            ++count;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        SinglyListNode  *new_node = new SinglyListNode(val);
        if(NULL == head_node)
        {
            head_node = new_node;
        }
        else
        {
            new_node->next = head_node;
            head_node = new_node;
        }
    }
    
    void addAtTail(int val) {
        SinglyListNode  *new_node = new SinglyListNode(val);
        SinglyListNode  *cur_node = head_node;

        if(NULL == head_node)
        {
            head_node = new_node;
        }
        else
        {
            while(NULL != cur_node->next)
            {
                cur_node = cur_node->next;
            }
            cur_node->next = new_node;
        }
    }
    
    void addAtIndex(int index, int val) {
         int lenght = getLenght();

        if(lenght == index)
        {
            addAtTail(val);
        }
        else if(0 == index)
        {
            addAtHead(val);
        }
        else if(index < lenght)
        {
            SinglyListNode  *new_node = new SinglyListNode(val);
            SinglyListNode  *cur_node = head_node;
            SinglyListNode  *pre_node = head_node;
            int count = 0;
            
            while(NULL != cur_node)
            {
                if(count == index)
                {
                    new_node->next = pre_node->next;
                    pre_node->next = new_node;
                    return;
                }
                pre_node = cur_node;
                cur_node = cur_node->next;
                ++count;
            }
        }
        else
        {
            // Do nothing
        }
    }
    
    void deleteAtIndex(int index) 
    {
        SinglyListNode  *cur_node = head_node;

        if(head_node == NULL)
        {
            return;
        }

        int lenght = getLenght();

        if(0 == index)
        {
            head_node = head_node-> next;
            delete cur_node;
        }
        else if(index < lenght)
        {
            SinglyListNode  *cur_node = head_node;
            SinglyListNode  *pre_node = head_node;
            SinglyListNode  *temp_node;
            int count = 0;
            
            while(NULL != cur_node)
            {
                if(count == index)
                {
                    temp_node = cur_node;
                    pre_node->next = cur_node->next;
                    delete cur_node;
                    return;
                }
                pre_node = cur_node;
                cur_node = cur_node->next;
                ++count;
            }
        }
        else 
        {
            // Do nothing
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

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
