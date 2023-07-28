// https://www.codingninjas.com/studio/problems/allocate-books_1090540
// https://leetcode.com/problems/split-array-largest-sum/description/

// Given an array where each entry represents the number of pages in a book
// There are m students in total
//
// Each student gets atleast one book
// Each book should be allocated
// Book allocation should be in a contiguous manner
//
// Allocate books to 'm' students in such a way that maximum number of pages assigned to a student is minium

// We binary search?
// we need to think in terms of how to use a search space in this problem. Having an increasing or decreasing
// search space will allow us the use binary search on it.
// In the worst case, the minimum value that can be allocated will be the number of pages from the book with least number of pages. arr = [12, 12, 12, 12], students = 4
// The maximum value that can be allocated will the sum of all the pages. arr = [10, 20, 30], students = 1
//
// So as we're able to form a search space for the question, we can use binary search.

// This can also be done using recursion and DP, but check why we don't do it.

// Time complexity = O(log(sumPages)) * O(number of books)
// Space complexity = O(1)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Try allocating the books between m students such that no student gets more than n pages
// If allocation is possible, return true, otherwise false
bool isPossibleSolution(vector<int>& v, int m, int n) {
    int studentCount = 1;
    int pageSum = 0;    // Indicates the number of pages allocated to a student

    for (int i = 0; i < v.size(); i++) {
        if (pageSum + v[i] <= n) {  // Check if next book (pages) can be allocated to a student
            pageSum += v[i];
        } else {    // The next book couldn't be allocated. Move to the next student
            studentCount++;

			// If the number of students exceed m to which books can be allocated, then it means that all the books are not being allocated to m students and we need more students to allocate the threshold pages
			// and the number of pages should be increased
            if (studentCount > m) {
                return false;
            }

            pageSum = v[i];
        }
    }

	// This can both mean our answer or a number for which we can allocate books to lesser number of student
	// and we should decrease the barrier
	// E.g. [10, 10, 10, 10]
	// If n = 20, then we can only allocate to 2 students and hence should reduce the number of pages per student
	// Only at n = 10, can we allocate to all the 4 students
    return true;
}

int allocateBook(vector<int>& v, int m) {
	// If we allocate the minimum number of pages book as the maximum, then only one book will be taken and other books won't be used at all
	// We have to atleast take the maximum number of pages book as the lowest possible
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);   // Sum of all the pages in books

    int ans = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

		// mid is the maximum number of pages that should be allocated to a student without any books left
		// Here the number of students to whom books are allocated could be less
        if (isPossibleSolution(v, m, mid)) {   
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    cout << allocateBook(v, 3) << std::endl;    // 60

    v.clear();
    v = {10, 20, 30};
    cout << allocateBook(v, 2) << std::endl;    // 30

    v.clear();
    v = {10, 20, 30, 40};
    cout << allocateBook(v, 2) << std::endl;    // 60

    v.clear();
    v = {12, 34, 67, 90};
    cout << allocateBook(v, 2) << std::endl;    // 113

    return 0;
}
