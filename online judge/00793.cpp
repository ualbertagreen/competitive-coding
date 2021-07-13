#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
public:
  vector<int> p;
  vector<int> rank;

  UnionFind(int n)
    {
      p.assign(n,0);
      rank.assign(n,0);
      for (int i = 0; i < n; i++)
	{
	  p[i] = i;
	}
    }

  int findSet(int i) {return p[i]==i? i : (p[i] = findSet(p[i]));}
  bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
  void Union(int a, int b)
  {
    if (!isSameSet(a,b))
      {
	int i,j;
	i = findSet(a); j = findSet(b);
	if (rank[i] < rank[j]) p[i] = j;
	else if (rank[i] > rank[j]) p[j] = i;
	else {p[i] = j; rank[j]++;}
      }
  }
};

int main()
{
  int n;
  while(cin>>n)
    {

  UnionFind set(n);

  int Succ = 0;
  int Fail = 0;
  char c;

  while (true)
    {
      cin.get();
      c = cin.peek();
      if (c != 'c' && c != 'q')
	break;
      else cin.get();
      int a,b;
      cin>>a>>b;
      if (c == 'c')
	{
	  set.Union(a,b);
	}
      else if (c == 'q')
	{
	  if(set.isSameSet(a,b))
	    Succ++;
	  else Fail++;
	}
    }
  cout<<Succ<<','<<Fail<<endl;
    }
  return 0;
}
