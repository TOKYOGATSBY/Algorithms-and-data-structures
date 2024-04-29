#include <iostream>
#include <vector>
using namespace std;

vector<int> EvenOdd (vector<int> arr)
{
    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        } else
        {
            odd.push_back(arr[i]);
        }
    }
    arr.clear();

    for (int i = 0; i < even.size(); ++i)
    {
        arr.push_back(even[i]);
    }

    for (int i = 0; i < odd.size(); ++i)
    {
        arr.push_back(odd[i]);
    }

    return arr;
}

int main()
{
    vector<int> arr {5, 6, 9, 1, 3, 0, 4, 7, 2, 8};

    vector<int> new_arr = EvenOdd(arr);

    for (int i = 0; i < new_arr.size(); ++i)
    {
        cout << new_arr[i] << " ";
    }
    
    return 0;
}
