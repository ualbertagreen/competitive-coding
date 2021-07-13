#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin>>T;
  for (;T;T--)
    {
      vector< vector<int> > tor;
      int N;
      cin>>N;
      tor.assign(N, vector<int>());
      for (int i = 0; i < N; i++)
	{
	  for (int j = 0; j < N; j++)
	    {
	      int temp;
	      cin>>temp;
	      tor[i].push_back(temp);
	    }
	  for (int j = 0; j < N; j++)
	    {
	      tor[i].push_back(tor[i][j]);
	    }
	}
      for (int i = 0; i < N; i++)
	tor.push_back(tor[i]);

      vector< vector<int> > range;
      range.assign(2*N, vector<int>());
      for (int i = 0; i < tor.size(); i++)
	{
	  int r = 0;
	  for (int j = 0; j < tor[0].size(); j++)
	    {
	      r += tor[i][j];
	      if (i)
		range[i].push_back(range[i-1][range[i].size()]+r);
	      else
		range[i].push_back(r);
	    }
	}


      int max = tor[0][0];

      for (int i = 0; i < range.size(); i++)
	for (int j = ::max(i - N + 1, 0); j <= i; j++)
	  for (int k = 0; k < range[0].size(); k++)
	    for (int l = ::max(k - N + 1, 0); l <= k; l++)
	      {
		int cur = range[i][k];
		if (j) cur -= range[j-1][k];
		if (l) cur -= range[i][l-1];
		if (j && l) cur += range[j-1][l-1];
		max = ::max(max,cur);
	      }
      //cout<<N<<endl;
      // for (int j = 0; j < range[0].size(); j++)
      // 	{
      // 	  //int j = 6;
      // 	  for (int k = ::max(j - N + 1, 0); k <= j; k++)
      // 	    {
      // 	      //cout<<j<<' '<<k<<endl;
      // 	      //int k = 4;
      // 	      int row = 0;
      // 	      int cur = 0;
      // 	      for (int i = 0; i < 2*N; i++)
      // 		{
      // 		  if (i == row + N)
      // 		    {
      // 		      do
      // 			{
      // 			  cur -= range[row][j];
      // 			  if (k) cur += range[row][k];
      // 			  row++;
      // 			}while(range[row][i] - range[row][k] <0);

      // 		    }
		    

      // 		  if (cur < 0)
      // 		    {
      // 		      cur = 0;
      // 		      row = i;
      // 		    }

      // 		  //cout<<cur<<" ";

      // 		  cur += range[i%N][j];
      // 		  //cout<<range[i%N][j]<<endl;
      // 		  //cout<<cur<<endl;
      // 		  if (k)
      // 		    {
      // 		      cur -= range[i%N][k-1];
      // 		      //cout<<cur<<endl;
      // 		    }
      // 		  max = ::max(max, cur);
      // 		}
      // 	      }
      // 	}
      cout<<max<<endl;
    }
}
