#include <iostream>
using namespace std;

int main()
{
    int num, target;

    
    cin >> num;

    int nums[num];

    
    for(int i = 0; i < num; i++){
        cin >> nums[i];
    }

    
    cin >> target;

    
    for(int i = 0; i < num - 1; i++){
        for(int j = i + 1; j < num; j++){
            if(nums[i] + nums[j] == target){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}