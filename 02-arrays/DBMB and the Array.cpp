#include <iostream>
using namespace std;

int main()
{
    int n, s, x;
    cin >> n >> s >> x;

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        sum += val;
    }

    if(sum > s)
    {
        cout << "NO" << endl;
    }
    else if((s - sum) % x == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}