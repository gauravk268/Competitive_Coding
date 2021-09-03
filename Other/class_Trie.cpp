#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  bool isEnd;
  TrieNode *child[26];
};

TrieNode *getNode()
{
  TrieNode *pNode = new TrieNode();
  pNode->isEnd = false;
  for (int i = 0; i < 26; i++)
  {
    pNode->child[i] = NULL;
  }
  return pNode;
}

void insert(TrieNode *root, string s)
{
  TrieNode *p = root;
  for (int i = 0; i < s.size(); i++)
  {
    int k = s[i] - 'a';
    if (p->child[k] == NULL)
      p->child[k] = getNode();

    p = p->child[k];
  }
  p->isEnd = true;
}

bool search(TrieNode *root, string s)
{
  TrieNode *p = root;
  for (int i = 0; i < s.size(); i++)
  {
    int k = s[i] - 'a';
    if (p->child[k] == NULL)
      return false;

    p = p->child[k];
  }
  return p->isEnd;
}

void solution()
{
  vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

  TrieNode *root = getNode();
  for (int i = 0; i < keys.size(); i++)
  {
    insert(root, keys[i]);
  }

  search(root, "the") ? cout << "Yes\n" : cout << "No\n";
  search(root, "these") ? cout << "Yes\n" : cout << "No\n";
  search(root, "there") ? cout << "Yes\n" : cout << "No\n";
  search(root, "thaw") ? cout << "Yes\n" : cout << "No\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  while (t--)
  {
    solution();
  }

  return 0;
}

/*



*/