#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
/*
Problem:

Given a set of arrays of size N and an integer K,
you have to find the maximum integer for each and every 
contiguous subarray of size K for each of the given arrays.

example input: 3 4 5 8 1 4 10

the contiguous subarrays of size 4 are:
{3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. 
The 4 maximum element of subarray of size 4 are: 8 8 8 10.

This is the final O(n) solution which uses a deque to 
store the index of the largest value in each window,
and removes this value from queue as soon as it is out of the 
current window.

*/



void printKMax(int arr[], int n, int k){
    deque<int> d(k);
    int i;
    for(i = 0; i < k; i++){
        //find the index of the max value of the first window
        while((!d.empty()) && arr[i] >= arr[d.back()] ){ d.pop_back();}
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


