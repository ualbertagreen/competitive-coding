#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class node
{
public:
  int neg;
  int zero;

  node(){neg = 0; zero = 0;}
};

class tree
{
public:
  vector<node> ft;

  node rsq(int b)
  {
    //cout<<b<<endl;
    node out;
    for (; b; b -= b & (-b)) 
      {
	out.neg += ft[b].neg; 
	out.zero += ft[b].zero;
      }
    return out;
  }

  node rsq(int a, int b)
  {
    //cout<<a<<b<<endl;
    node out;
    if (a == 1)
      out = rsq(b);
    else
      {
	out.neg = rsq(b).neg - rsq(a-1).neg;
	out.zero = rsq(b).zero - rsq(a-1).zero;
      }
    return out;
  }

  void adjust (int k, int n, int z)
  {
    for (; k < ft.size(); k += k & (-k))
      {
	ft[k].neg += n;
	ft[k].zero += z;
      }
  }

  tree(int N)
  {
    ft.assign(N,node());
  }
};

int main()
{
  int N,K;
  while(cin>>N>>K)
    {
      tree Fen(N+1);
      for (int i = 1; i <= N; i++)
	{
	  int temp;
	  assert(cin>>temp);
	  if (temp < 0)
	    Fen.adjust(i, 1, 0);
	  else if (temp == 0)
	    Fen.adjust(i, 0, 1);
	}
      for (int i = 0; i < K; i++)
	{
	  char c;
	  int a,b;
	  cin>>c>>a>>b;

	  if (c == 'C')
	    {
	      node temp = Fen.rsq(a,a);
	      //cout<<temp.neg<<' '<<temp.zero<<endl;
	      if (temp.neg == 0 && b < 0)
		{
		  if (temp.zero == 1)
		    Fen.adjust(a, 1, -1);
		  else Fen.adjust(a, 1, 0);
		}
	      else if (b > 0)
		{
		  if (temp.zero)
		    Fen.adjust(a, 0, -1);
		  else if (temp.neg)
		    Fen.adjust(a, -1, 0);
		}
	      else if (temp.zero == 0 && b == 0)
		{
		  if (temp.neg)
		    Fen.adjust(a, -1, 1);
		  else Fen.adjust(a, 0, 1);
		}
	      //temp = Fen.rsq(a,a);
	      //cout<<temp.neg<<' '<<temp.zero<<endl;
	    }
	  else
	    {
	      //cout<<a<<b<<endl;
	      node out = Fen.rsq(a,b);
	      if (out.zero) cout<<'0';
	      else if (out.neg & 1) cout<<'-';
	      else cout<<'+';
	    }
	}
      cout<<endl;
    }

  return 0;
}
