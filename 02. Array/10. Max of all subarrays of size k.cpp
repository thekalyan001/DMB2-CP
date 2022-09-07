//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
         //https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
        //queue approach  O(n)
        
    // Create a Double Ended Queue,
    // Qi that will store indexes
    // of array elements
    // The queue will store indexes
    // of useful elements in every
    // window and it will
    // maintain decreasing order of
    // values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()]
    // are sorted in decreasing order
    deque<int> Qi(k);
    vector<int>res;
 
    /* Process first k (or first window)
     elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
        // For every element, the previous smaller elements are useless so remove them from Qi
        while ((!Qi.empty()) && arr[i] >=arr[Qi.back()])             
            Qi.pop_back();// Remove from rear
        
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {
     
        // The element at the front of
        // the queue is the largest element of
        // previous window, so print it
        //cout << arr[Qi.front()] << " ";
        res.push_back(arr[Qi.front()]);
 
        // Remove the elements which
        // are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)
           
            // Remove from front of queue
            Qi.pop_front();
 
        // Remove all elements
        // smaller than the currently
        // being added element (remove
        // useless elements)
        while ((!Qi.empty()) && arr[i] >=arr[Qi.back()])
            Qi.pop_back();
 
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element
    // of last window
    //cout << arr[Qi.front()];
    res.push_back(arr[Qi.front()]);
    return res;
    }