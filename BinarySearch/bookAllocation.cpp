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

using namespace std;

// Try allocating the pages (books) between m students such that no student gets more than n pages
// If allocation is possible, return true, otherwise false
bool isPossibleSolution(vector<int>& v, int m, int n) {
    int studentCount = 1;
    int pageSum = 0;    // Indicates the number of pages allocated to a student

    for (int i = 0; i < v.size(); i++) {
        if (pageSum + v[i] <= n) {  // Check if next book (pages) can be allocated to a student
            pageSum += v[i];
        } else {    // The next book couldn't be allocated. Move to the next student
            studentCount++;
            // If we are trying to allocate books to more students than available or
            // if the pages in the current book is greater than our maximum pages to allocate
            // In both the cases, the number of pages we have assumed is not a possible solution
            if (studentCount > m || v[i] > n) {
                return false;
            }

            pageSum = v[i];
        }
    }

#if 0
    // Another possible way to write the above condition
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > n) {
            return false;
        }

        if (pageSum + v[i] > n) {
            studentCount++;
            if (studentCount > m) {
                return false;
            }
            pageSum = v[i];
        } else {
            pageSum += v[i];
        }
    }
#endif

    return true;
}

int allocateBook(vector<int>& v, int m) {
    int low = 0;
    int high = accumulate(v.begin(), v.end(), 0);   // Tsum of all the pages in books

    int ans = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        // If a certain number of pages(books) can be allocated to the students
        // then any number of pages that is greater than that number of pages can also be allocated.
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