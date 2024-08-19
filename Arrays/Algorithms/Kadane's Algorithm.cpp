#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum( vector<int> arr, int n ) {
    long long sum = 0;
    long long Max = 0;
    
    for (auto x: arr) {
        sum += x;
        Max = max(Max, sum);
        if (sum < 0) 
            sum = 0;
    }

    return Max;
}

// Getting Index of array with maximum Sum
pair<int, int> maximumSubarray( vector<int> arr, int n ) {
    long long sum = 0;
    long long Max = 0;
    
    int start = 0;
    int tempStart = 0;
    int end = 0;

    for (int i=0; i<n; i++) {
        sum += arr[i];

        if (sum > Max) {
            Max = sum;
            start = tempStart;
            end = i;
        }
        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
            
    }

    return {start, end};
}