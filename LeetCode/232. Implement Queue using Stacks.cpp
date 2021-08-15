class MyQueue
{
public:
  stack<int> s1, s2;
  int count;
  /** Initialize your data structure here. */
  MyQueue()
  {
    count = 0;
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    while (s1.size())
    {
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(x);
    while (s2.size())
    {
      s1.push(s2.top());
      s2.pop();
    }

    count++;
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    if (count == 0)
      return -1;
    int x = s1.top();
    s1.pop();
    count--;
    return x;
  }

  /** Get the front element. */
  int peek()
  {
    if (count == 0)
      return -1;
    return s1.top();
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return (count == 0);
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */