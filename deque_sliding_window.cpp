#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void printKMax(int arr[], int n, int k){
   //Write your code here.
    deque<int> d(k);
    int i;
    for(i = 0; i < k; i++){
        while((!d.empty()) && arr[i] >= arr[d.back()] ){//find the index of the max value of the first window
            d.pop_back();
        }
        d.push_back(i);
    }
    for(;i < n + 1; i++){
        cout << arr[d.front()] << " "; // print the biggest value of the previous window     
        //checks to see if the current max value is still in the current window
        if((!d.empty()) && d.front() <= i - k){d.pop_front();}
            
        while((!d.empty()) && arr[i] >= arr[d.back()] ){//find the index of the max value of the current window
            d.pop_back();//remove elements in window who are smaller than arr[i]
        }
        d.push_back(i); //place i in back of max queue, if queue is empty, i is new max.  
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}


