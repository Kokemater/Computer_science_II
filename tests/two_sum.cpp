#include <iostream>
using namespace std;

void two_sum(int *list1, int target);
int main(void)
{
    int list1[5] = {1,2,3,4,5};
    int target = 7;
    two_sum(list1, target);
}
void two_sum(int *list1, int target)
{
    for(int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (list1[i] + list1[j] == target)
            {
                cout << "index: " << i << " " << j << endl;
                return;
            }
        }
    }
}