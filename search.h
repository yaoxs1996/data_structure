#progma once

#include<vector>

//二分查找的递归实现
int binary_search(vector<int> r, int key, int low, int high)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if(r[mid] == key)
            return mid;
        else if(r[mid] > key)
            return (binary_search(r, key, mid+1, high));
        else
            return (binary_search(r, key, low, mid-1));
    }
    else
        return 0;
}
