#include <iostream>

using namespace std;

int main()
{
  long long in[20][20][20];
  long long ans[20][20][20];

  int T;
  cin>>T;

  for (;T;T--)
    {
      int A,B,C;
      cin>>A>>B>>C;
      for (int i = 0; i < A; i++)
	for (int j = 0; j < B; j++)
	  for (int k = 0; k < C; k++)
	    cin>>in[i][j][k];

      for (int i = 0; i < A; i++)
	for (int j = 0; j < B; j++)
	  {
	    long long running = 0;
	    for (int k = 0; k < C; k++)
	      {
		running += in[i][j][k];
		if (j == 0)
		  ans[i][0][k] = running;
		else
		  ans[i][j][k] = ans[i][j-1][k] + running;
		//cout<<ans[i][j][k]<<' ';
	      }
	  }
      //cout<<endl;
      long long sum = ans[0][0][0];
      for (int j = 0; j < B; j++)
	for (int k = 0; k < C; k++)
	  for (int l = 0; l <= j; l++)
	    for (int m = 0; m <= k; m++)
	      {
		long long run = 0;
		for (int i = 0; i < A; i++)
		  {
		    run += ans[i][j][k];
		    if (l)
		      run -= ans[i][l-1][k];
		    if (m)
		      run -= ans[i][j][m-1];
		    if (l && m)
		      run += ans[i][l-1][m-1];
		    //cout<<j<<k<<l<<m<<i<<run<<' '<<sum<<endl;
		    sum = max(run,sum);
		    if (run < 0)
		      run = 0;
		  }
	      }

      cout<<sum<<endl<<endl;

    }
  return 0;
}
