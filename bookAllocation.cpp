#include<bits/stdc++.h>

using namespace std;

int sumArr(vector<int> &arr)
{
    int sum = 0;

    for(int x : arr)
    {
        sum += x;
    }

    return sum;
}

bool isValidAllocation(vector<int> &arr , int limit, int n)
{
    int students = 1;
    int maxPages = 0;

    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(arr[i] > limit)
        {return false;}

        if(arr[i] + maxPages > limit)
        {
            students++;
            maxPages = arr[i];
        }else{
            maxPages += arr[i];
        }
    }

    return students <= n;
}


int maxPagesMinAllocation(vector<int> &arr, int n)
{

    int lo = *max_element(arr.begin(),arr.end());

    int hi = sumArr(arr);

    int res = 0;

    int n = arr.size();

    while(lo <= hi)
    {
        int mid = (lo + (hi - lo)/2);

        if(isValidAllocation(arr,mid,n))
        {
            res = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    return res;
}

int main()
{

}