https://leetcode.com/problems/minimum-number-of-refueling-stops/

Priority Queue, O(NlogN)
i is the index of next stops to refuel.
res is the times that we have refeuled.
pq is a priority queue that we store all available gas.

We initial res = 0 and in every loop:

We add all reachable stop to priority queue.
We pop out the largest gas from pq and refeul once.
If we cant refuel, means that we can not go forward and return -1



int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int i=0, idx=0;
    priority_queue<int>pq;

    while(startFuel<target){
        while(i<stations.size() && stations[i][0]<=startFuel){
            pq.push(stations[i][1]);i++;
        }
        if(pq.empty())return -1;
        startFuel+=pq.top();pq.pop();


        idx++;
    }
    return idx;
}


int printTour()
{
    int start = 0, deficit = 0, capacity = 0;
    for (int i = 0; i < n; i++) {
        capacity += petrol[i] - distance[i];
        if (capacity < 0) {
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
}