class disJoint
{
private:
  int *parent, n;

public:
  disJoint(int n)
  {
    parent = new int[n + 1];
    this->n = n;

    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int find(int &a)
  {
    if (parent[a] == a)
    {
      return a;
    }

    return parent[a] = find(parent[a]);
  }

  void make_union(int &a, int &b)
  {
    parent[b] = a;
  }
};