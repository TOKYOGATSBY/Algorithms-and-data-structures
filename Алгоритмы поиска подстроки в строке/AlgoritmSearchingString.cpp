#include <iostream>
#include <string>
using namespace std;

int directSearch(const string& str, const string& substr) //Прямой поиск
{
    int n = str.length();
    int m = substr.length();

    for (int i = 0; i <= n - m; ++i)
    {
        bool found = true;

        for (int j = 0; j < m; ++j)
        {
            if (str[i + j] != substr[j])
            {
                found = false;
                break;
            }
        }

        if (found) return i + 1;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    string str = "abcbcacabacbababac";
    string substr = "abc";

    int n = directSearch(str, substr);
    cout << n;
    
    return 0;
}
