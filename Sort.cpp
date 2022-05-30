#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

void bubble(std::vector<int> &nums);
void selection(std::vector<int> &nums);
void insertion(std::vector<int> &nums);
template<typename T>
void merge(std::vector<T> &a, int left, int mid, int right);
template<typename T>
void merge_sort(std::vector<T> &a, int left, int right);
template<typename T>
void printVector(std::vector<T> v);

int main()
{
    std::vector<double> nums{5.1, 2.3, 4.5, 7.6, 1.4, 3.2, 6.4, 1.44};

    merge_sort<double>(nums, 0, nums.size() - 1);
    printVector<double>(nums);
    return 0;
}

void bubble(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < nums.size() - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swapped = true;
                std::swap(nums[j], nums[j + 1]);
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void selection(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIdx])
            {
                minIdx = j;
            }
        }
        // Swap the found minimum element
        // with the first element
        std::swap(nums[minIdx], nums[i]);
    }
}

void insertion(std::vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i; j > 0; --j)
        {
            if (nums[j] < nums[j - 1])
            {
                std::swap(nums[j - 1], nums[j]);
            }
        }
    }
}

template<typename T>
void merge(std::vector<T> &Array, int left, int mid, int right)
{
    std::vector<T> LeftSubArray(Array.begin() + left, Array.begin() + mid + 1);
    std::vector<T> RightSubArray(Array.begin() + mid + 1, Array.begin() + right + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), std::numeric_limits<T>::max());
    RightSubArray.insert(RightSubArray.end(), std::numeric_limits<T>::max());
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = left; i <= right; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight])
        {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

template<typename T>
void merge_sort(std::vector<T> &a, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort<T>(a, left, mid);
    merge_sort<T>(a, mid + 1, right);

    merge<T>(a, left, mid, right);
}

template<typename T>
void printVector(std::vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}