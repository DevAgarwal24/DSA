// https://leetcode.com/problems/single-number/
// https://www.codingninjas.com/studio/problems/find-the-single-element_6680465

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Pick up every number and check how many times it appears
// Return the number that appears only once
// T.C = O(N*N)
// S.C = O(1)

// Better solution
// Hashing approach
// Find the maximum value
// Create an array of MaxVal + 1 size to store the count of each element
// Return the number which count == 1
// T.C = O(3N)
// S.C = O(N)
// We cannot use the hash array for negative or bigger number. In those cases it's better to use a map.
// T.C = O(NlogM) + O(M + 1)  for ordered map and M = N/2 + 1 
// S.C = O(N)

// Optimal Solution
// XOR all the elements of the array
// T.C = O(N)
// S.C = O(1)
int findSingleElement(vector<int> &arr){
	int n = arr.size();
	int xor1 = 0;
	for (int i = 0; i < n; i++) {
		xor1 = xor1 ^ arr[i];
	}

	return xor1;
}

// There is an even better approach to solve this but for that we need the array to be sorted
// We can use binary search to find the solution in O(log N) time complexity
// That appraoch is in Binary_Search section

int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout << findSingleElement(v) << endl;

    return 0;
}