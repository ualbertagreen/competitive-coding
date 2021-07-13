#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;

  for (int i = 0; i < n; i++)
    {
      int p,q;
      cin>>p>>q;
      long long out = 0;
      if (q > (p/2) && p%2 == 1)
	{
	  out = 1;
	  p--;
	}
      while (p)
	{
	  if (q > 0 && p > 1)
	    {
	      out = out<<3;
	      out += 5;
	      p-=2;
	      q-=1;
	    }
	  else
	    {
	      out = out<<1;
	      out+=1;
	      p-=1;
	    }
	}
      cout<<out<<endl;
    }
  return 0;
}
