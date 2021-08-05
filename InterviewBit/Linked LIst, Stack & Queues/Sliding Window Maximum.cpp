vector<int> Solution::slidingMaximum(const vector<int> &arr, int B) {
    deque<int> q;
    int i;
    for (i = 0; i < B; i++)
    {
        while (q.size() && arr[i] >= arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }

    vector<int> result;
    for (; i < arr.size(); i++)
    {
        result.push_back(arr[q.front()]);

        while (q.size() && q.front() <= i - B)
            q.pop_front();

        while (q.size() && arr[i] >= arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }
    result.push_back(arr[q.front()]);

    return result;
}
