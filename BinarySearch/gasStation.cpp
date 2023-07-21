// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

long double MinPossMaxDistanceBruteForce(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> howMany(n-1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++) {
        long double maxVal = -1; int maxInd = -1;

        for (int i = 0; i < n-1; i++) {
            long double diff = (long double)(arr[i+1] - arr[i]) / (long double)(howMany[i] + 1);
            if (diff > maxVal) {
                maxVal = diff;
                maxInd = i;
            }
        }

        howMany[maxInd]++;
    }

    long double maxDist = -1;

    for (int i = 0; i < n-1; i++) {
        long double dist = (long double)(arr[i+1] - arr[i]) / (long double)(howMany[i] + 1);
        if (dist > maxDist) {
            maxDist = dist;
        }
    }

    return maxDist;
}

// This answer is good enough for the interviews
long double MinPossMaxDistance(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n-1; i++) {
        pq.push({arr[i+1]-arr[i], i});      // push the difference between two stations and the index
    }

    for (int gasStation = 1; gasStation <= k; gasStation++) {
        pair<long double, int> tmp = pq.top();
        pq.pop();

        int idx = tmp.second;
        howMany[idx]++;

        // Instead of calculating, we can store the intial section lengths.
        // But that will lead to increased space complexity
        long double length = arr[idx+1] - arr[idx];

        long double sectionDistance = length / (long double)(howMany[tmp.second] + 1);
        pq.push({sectionDistance, tmp.second});
    }

    return pq.top().first;
}

int noOfGasStationsRequired(vector<int>& arr, long double dist) {
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        int numberInBetween = (arr[i] - arr[i-1]) / dist;
        if ((arr[i] - arr[i-1]) / dist == numberInBetween * dist) {     // Fully divisible case
            numberInBetween--;
        }
        cnt += numberInBetween;
    }

    return cnt;
}

// All the binary search problems with long double will have this kind of pattern
// and not the pattern we have been using with the integers
// Here TC = NlogN. We optimise here in space by not using any extra memory
long double MinPossMaxDistanceBS(vector<int>& arr, int k) {
    int n = arr.size();

    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n-1; i++) {
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }

    long double diff = 1e-6;

    while (high - low > diff) {
        long double mid = low + (high - low)/2;

        int cnt = noOfGasStationsRequired(arr, mid);
        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return high;
}

int main()
{
    vector<int> v = {1, 13, 17, 23};

    cout << MinPossMaxDistanceBruteForce(v, 5) << endl;     // 3
    cout << MinPossMaxDistance(v, 5) << endl;
    cout << MinPossMaxDistanceBS(v, 5) << endl;

    cout << endl;

    v.clear();
    v = {1, 2, 3, 4, 5};
    cout << MinPossMaxDistanceBruteForce(v, 4) << endl;     // 0.5
    cout << MinPossMaxDistance(v, 4) << endl;
    cout << MinPossMaxDistanceBS(v, 4) << endl;

    cout << endl;

    return 0;
}