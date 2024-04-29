#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int binarySearch (vector<int> arr, int find)
{
    int all{0}, element{0};
    int left {0};
    int right = arr.size() - 1;
    
    while (left <= right)
    {
        all++;
        int mid = (left + right) / 2;
        if (arr[mid] == find)
        {
            element++;
            all++;
            cout << element << all;
            return mid + 1;
        }
        else
        {
            if (arr[mid] < find)
            {
                all++;
                element++;
                left = mid + 1;
            }
            else
            {
                all++;
                element++;
                right = mid - 1;
            }
        }
    }
    cout << element << all;
    return -1;
}

int binarySearchWithRecurse (vector<int> arr, int find, int left, int right)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == find)
        {
            return mid + 1;
        }
        else
        {
            if (arr[mid] < find) return binarySearchWithRecurse(arr, find, mid + 1, right);
            else return binarySearchWithRecurse(arr, find, left, mid - 1);
        }
    }
    return -1;
}

/*void binarySearch2 (vector<vector<int>>& matrix, int find)
{
    bool trigger = false;
    int rows = matrix.size();
    
    for (int i = 0; i < rows; ++i)
    {
        int index = binarySearch(matrix[i], find);
        if (index != -1)
        {
            trigger = true;
            cout << i + 1 << " " << index;
        }
    }
    if (!trigger) cout << -1;
}*/

int binarySearch2 (vector<vector<int>>& matrix, int find)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    int left = 0;
    int right = rows * columns - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int midVec = matrix[mid / columns][mid % columns];

        if (midVec == find)
        {
            return true;
        } else
        {
            if (midVec < find) left = mid + 1;
            else right = mid - 1;
        }
    }
    return false;
}

int main()
{
    ifstream file ("input.txt");

    int rows{0}, columns{0};
    file >> rows >> columns;
    
    vector<vector<int>> arr(rows, vector<int> (columns));
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            file >> arr[i][j];
        }
    }

    cout << binarySearch2(arr,78);

    

    /*vector<int> arr(100000000);
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }

    binarySearch(arr, 0);*/

    
    return 0;
}
