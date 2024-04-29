#include <iostream>
#include <vector>
using namespace std;

void SimpleChoise (vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i) swap(arr[i], arr[min_index]);
    }   
}

void SimpleExchange (vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = 0; j < arr.size() - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> arr {7, 3, 8, 4, 2, 1, 0, 9, 5, 6};

    SimpleExchange(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
