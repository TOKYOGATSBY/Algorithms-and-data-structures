#include <iostream>
#include <vector>
using namespace std;

void sortAlg (vector<int> arr, int max)
{
    vector<int> new_arr;
    for (int i = 0; i <= max; ++i)
    {
        int count{0};
        for (int j = 0; j < arr.size(); ++j)
        {
            if (arr[j] == i) count++;
            while (count != 0)
            {
                new_arr.push_back(i);
                count--;
            }
        }
    }
    for (int i = 0; i < new_arr.size(); ++i)
    {
        cout << new_arr[i] << " ";
    }
}

int main()
{
    vector<int> arr{7, 3, 8, 1, 2, 5, 1, 4, 2, 9};

    sortAlg(arr, 9);


    
    return 0;
}
