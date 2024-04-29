#include <iostream>
#include <vector>
using namespace std;

void linearSearch(int arr[], int size, int find)
{
    bool trigger = false;
    int number {0};
    for (int i = 0; i < size; ++i)
    {
        if (find == arr[i])
        {
            trigger = true;
            number = i;
            break;
        }
    }
    if (trigger == false) cout << "Not found";
    else cout << number + 1;
}

void linearSearchWithBarrier (int arr[], int size, int find)
{
    int last = arr[size - 1];
    arr[size - 1] = find;

    int i = 0;
    while (arr[i] != find)
    {
        i++;
    }
    arr[size - 1] = last;

    if (i < (size - 1) || arr[size - 1] == find) cout << i + 1;
    else cout << "Not found";
}

void linearSearchTwoDem (int **arr, int rows, int columns, int find)
{
    bool trigger = false;
    int x {0}, y{0};
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if(arr[i][j] == find)
            {
                x = i;
                y = j;
                trigger = true;
                break;
            }
        }
    }
    if (trigger == false) cout << "Not found";
    else cout << x + 1 << " " << y + 1;
}

void linearSearchWithBarrierTwoDem (int **arr, int rows, int columns, int find)
{
    bool trigger = false;
    int x{0}, y{0};
    for (int i = 0; i < rows; ++i)
    {
        arr[i][columns] = find;
        int j = 0;

        while (arr[i][j] != find)
        {
            j++;
        }

        if (j < columns)
        {
            trigger = true;
            x = i + 1;
            y = j + 1;
        }
    }
    if (trigger) cout << x << " " << y;
    else cout << "Not found";
}

int main()
{
    int rows = 3;
    int columns = 3;
        
    int **arr = new int *[rows];

    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int [columns];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            arr[i][j] = i * 3 + j + 2;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //linearSearchTwoDem(arr, rows, columns, 6);
    //linearSearchWithBarrierTwoDem(arr, rows, columns, 10);

    //int arr_linear[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //linearSearch(arr_linear, 10, 9);
    return 0;
}
