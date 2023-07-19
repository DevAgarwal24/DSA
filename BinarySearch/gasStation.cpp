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

        // Instead of calculating, we can store the intial section lengths.
        // But that will lead to increased space complexity
        long double length = arr[idx+1] - arr[idx];

        long double sectionDistance = length / (long double)(howMany[tmp.second] + 1 + 1);
        pq.push({sectionDistance, tmp.second});

        howMany[tmp.second]++;
    }

    return pq.top().first;
}

int main()
{
    vector<int> v = {1, 13, 17, 23};

    cout << MinPossMaxDistanceBruteForce(v, 5) << endl;     // 3
    cout << MinPossMaxDistance(v, 5) << endl;

    cout << endl;

    v.clear();
    v = {1, 2, 3, 4, 5};
    cout << MinPossMaxDistanceBruteForce(v, 4) << endl;     // 0.5
    cout << MinPossMaxDistance(v, 4) << endl;

    cout << endl;

    return 0;
}