class MyStack
{
public:
  /** Initialize your data structure here. */
  queue<int> q1, q2;
  int count;

  MyStack()
  {
    count = 0;
  }

  /** Push element x onto stack. */
  void push(int x)
  {
    count++;
    while (q1.size())
    {
      q2.push(q1.front());
      q1.pop();
    }

    q1.push(x);
    while (q2.size())
    {
      q1.push(q2.front());
      q2.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    if (count == 0)
      return -1;
    int x = q1.front();
    q1.pop();
    count--;
    return x;
  }

  /** Get the top element. */
  int top()
  {
    if (count == 0)
      return -1;
    return q1.front();
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return (count == 0);
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */