#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int dfs(int j, bool (&graph)[26][26], bool (&nodes)[26])
{
  int out = 1;
  for (int k = 0; k < 26; k++)
    {
      if (graph[j][k])
	if (nodes[k])
	  {
	    nodes[k] = false;
	    out+=dfs(k, graph, nodes);
	  }
    }

  return out;
}

int main()
{
  int n;
  cin>>n;
  for (int i = 0; i < n; i++)
    {
      bool graph[26][26];
      bool nodes[26];
      for (int j = 0; j < 26; j++)
	{
	  nodes[j] = false;
	  for (int k = 0; k < 26; k++)
	    graph[j][k] = false;
	}
      char a,b;
      while(cin >> a && a == '(')
	{
	  cin>>a;
	  cin>>b>>b;
	  char temp;
	  cin.get();
	  graph[(int)a-(int)'A'][(int)b-(int)'A'] = true;
	  graph[(int)b-(int)'A'][(int)a-(int)'A'] = true;
	}
      string temp;
      getline(cin, temp);
      do
	{
	  cin>>a;
	  b = cin.get();
	  nodes[(int)a - (int)'A'] = true;
	}while(b !='\n');

      int trees = 0;
      int acorns = 0;
      
      for (int j = 0; j < 26; j++)
	{
	  if (nodes[j])
	    {
	      if (dfs(j, graph, nodes) > 1)
		trees++;
	      else 
		acorns++;
	    }
	}
      printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }
  return 0;
}
