#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Pair {
        int value;
        int index;
    };
    
    vector<int> counts;

    void merge(vector<Pair>& pairs, int start, int mid, int end) {
        vector<Pair> temp;
        temp.reserve(end - start + 1);

        int i = start;
        int j = mid + 1;
        int right_count = 0;

        while (i <= mid && j <= end) {
            if (pairs[i].value > pairs[j].value) {
                right_count++;
                temp.push_back(pairs[j]);
                j++;
            } else {
                counts[pairs[i].index] += right_count;
                temp.push_back(pairs[i]);
                i++;
            }
        }

        while (i <= mid) {
            counts[pairs[i].index] += right_count;
            temp.push_back(pairs[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(pairs[j]);
            j++;
        }

        copy(temp.begin(), temp.end(), pairs.begin() + start);
    }

    void mergeSort(vector<Pair>& pairs, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        
        mergeSort(pairs, start, mid);
        mergeSort(pairs, mid + 1, end);
        
        merge(pairs, start, mid, end);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        counts.assign(n, 0);

        vector<Pair> pairs;
        pairs.reserve(n);
        for (int i = 0; i < n; ++i) {
            pairs.push_back({nums[i], i});
        }

        mergeSort(pairs, 0, n - 1);

        return counts;
    }
};