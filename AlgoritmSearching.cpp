#include <iostream>
#include <vector>
using namespace std;

void sequentialSearch(vector<int> arr, int key) // Линейный поиск
{
    bool found = false;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == key)
        {
            cout << key << " found in " << i + 1 << " cell\n";
            found = true;
        }
    }
    if (!found) cout << "Key is'n found\n";
}

int binarySearch(vector<int> arr, int key) //Бинарный поиск
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid + 1;
        } else if (arr[mid] < key)
        {
            left = mid + 1;
        } else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    vector<int> arr = {1, 2, 2, 4, 5, 6};
    int n = binarySearch(arr, 5);
    cout << n;
    
    return 0;
}
