#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cout<<"PERFECTION OUTPUT"<<endl;
  while (cin>>n && n) {
    int sum = 0;
    cout<<right<<setw(5)<<n<<"  ";
    for (int i = 1; i < n; i++) {
      if (!(n % i))
	sum += i;
    }
    if (sum < n)
      cout<<"DEFICIENT"<<endl;
    else if (sum == n)
      cout<<"PERFECT"<<endl;
    else
      cout<<"ABUNDANT"<<endl;
  }
  cout<<"END OF OUTPUT"<<endl;
  return 0;
}
