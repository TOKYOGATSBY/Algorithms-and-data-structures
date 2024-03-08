#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int random_number = rand();

    int const lines {4};
    int const columns {4};
    int arr [lines][columns];

    for (int i = 0; i < lines; ++i) //создание двумерного массива с рандомными значениями
    {
        for (int j = 0; j < columns; ++j)
        {
            arr[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < lines; ++i) //вывод двумерного массива на консоль
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 

    int count {0}, max{0}, max_second{0}, lines_max{0}, lines_max_2{0};
    bool one_line {false};

    for (int i = 0; i < lines; ++i) //нахождение максимального элемента
    {
        for (int j = 0; j < columns; ++j)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                lines_max = i + 1;
            }
        }
    }

    for (int i = 0; i < lines; ++i) //нахоождение второго по величине максимального элемента
    {
        for (int j = 0; j < columns; ++j)
        {
            if (arr[i][j] > max_second && arr[i][j] < max)
            {
                max_second = arr[i][j];
                lines_max_2 = i + 1;
            }
        }
    }

    cout << max << " " << max_second << endl;
    cout << lines_max << " " << lines_max_2 << endl;

    if (lines_max == lines_max_2) one_line = true; //проверка находятся ли оба максимальных элемента в одной строке
    if (one_line) //замена всех симметричных элементов отосительно главной диагонали на нули
    {
        for (int i = 0; i < lines; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (arr[i][j] == arr[j][i] && i != j)
                {
                    arr[i][j] = 0;
                    arr[j][i] = 0;
                }
            }
        }

        int count_zero_lines{0};
        int number_of_lines{0};
        for (int i = 0; i < lines; ++i) //нахождение количества строк в которых первый элемент делится на количество строк(lines)
        {
            if (arr[i][1] % lines == 0)
            {
                count_zero_lines++;
                number_of_lines = arr[i][1];
            }
        }
        int **arr_with_zero  = new int *[lines + count_zero_lines]; //создание нового динамического массива для строк с нулями
        for (int i = 0; i < lines + count_zero_lines; ++i)
        {
            arr_with_zero[i] = new int[columns];
        }
        
        for (int i = 0; i < lines + count_zero_lines; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                arr_with_zero[number_of_lines - 1][j] = 0;
                arr_with_zero[i][j] = rand() % 100;
            }
        }

        for (int i = 0; i < lines + count_zero_lines; ++i) //вывод двумерного массива на консоль
        {
            for (int j = 0; j < columns; ++j)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } 

    return 0;
}
