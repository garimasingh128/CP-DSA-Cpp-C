#include <iostream>

using namespace std;

int main()
{
    int n, petya, vasya, tonya, counter = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2)
        {
            counter++;
        }
    }
    cout << counter;
    return 0;
}
