#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

		vector<int> counts(n+1, 0);

		vector<int> output(n+1, 0);

		int counter = 0;

		counts = nums;

		sort(counts.begin(), counts.end());

		int i = 0;
		for(auto v : nums){
			while(v != counts[i]){
				counter++;
				i++;
			}
			output.emplace_back(counter);
			counter = 0;
			i = 0;
		}
		

        return output;
    }

};

int main(){
	vector<int> input = {5, 2, 6, 1};

	Solution sol;
	vector<int> output = sol.countSmaller(input);
	
	
	for(auto v : output) {
		cout << v << "\n";
	}

	return 0;
}