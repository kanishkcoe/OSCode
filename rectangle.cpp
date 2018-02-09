#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int c = n;
  for (int i = 0; i < n; i++)
  {
    c = n;
    for (int j = 0; j < n; j++)
    {
      if(j < i)
      {
        cout << c;
        c -= 1;
      }
      else
      {
        cout << c;
      }
    }
    for (int k = 0; k < n - 1; k++)
    {
      if(k < n-i-1)
      {
        cout << c;
      }
      else
      {
        c += 1;
        cout << c;
      }
    }
    cout << endl;
  }
  for (int i = 0; i < n-1; i++)
  {
    c = n;
    for (int j = 0; j < n; j++)
    {
      if(j < n-i-2)
      {
        cout << c;
        c -= 1;
      }
      else
      {
        cout << c;
      }
    }
    for (int k = 0; k < n - 1; k++)
    {
      if(k >= i)
      {
        cout << c;
        c++;
      }
      else
      {
        cout << c;
      }
    }
    cout << endl;
  }
  return 0;
}
