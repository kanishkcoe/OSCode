#include <iostream>

using namespace std;

struct Program
{
  int arrival;
  int waiting;
  int completed;
  int turnaround;
  int burst;
  int burstVal;
  int status;
  int id;
};

void input(Program &, int, int, int);
void printTable(Program*, int);
void calculateDetails(Program*, int);

int main()
{
  int n;
  int a, b;

  cout << "Enter the number of processes to be scheduled : ";
  cin >> n;

  Program *p;
  p = new Program[n];

  for(int i = 0; i < n; i++)
	{
		cout << "Enter the arrival time and execution time of program P" << i + 1 << " : ";
		cin >> a;
		cin >> b;
    input(p[i], i + 1, a, b);
	}

  calculateDetails(p, n);
  printTable(p, n);
  return 0;
}

void input(Program &p, int i, int a, int b)
{
  p.id  = i;
  p.arrival = a;
  p.burst = b;
  p.burstVal = b;
  p.status = 0;
  p.waiting = 0;
  p.completed = 0;
  p.turnaround = 0;
}

void calculateDetails(Program *p, int n)
{
  int complete = 0, comp = 0;
  int t;
  cout << "Enter the time quantum : ";
  cin >> t;
  for(int i = 0; complete != n; i++)
  {
    if(p[i % n].status == 1)
    {
      continue;
    }

    if(p[i % n].burst >= t)
    {
      p[i % n].burst -= t;
      comp += t;
      p[i % n].completed = comp;
    }

    if(p[i % n].burst <= 0)
    {
      p[i % n].status = 1;
      complete++;
    }
  }

  for(int i = 0; i < n; i++)
	{
		p[i].waiting = p[i].completed - p[i].arrival - p[i].burstVal;
    p[i].turnaround = p[i].completed - p[i].arrival;
	}
}

void printTable(Program * p, int size)
{
  cout << "\n\n\t\t\tROUND ROBIN SCHEDULINNG\n";
	cout <<"--------------------------------------------------------------------" << endl;
	cout <<"--------------------------------------------------------------------" << endl;

	cout.width(7);
	cout << "PROCESS";

	cout.width(11);
	cout << "ARRIVAL";

	cout.width(9);
	cout << "BURST";

	cout.width(11);
	cout << "WAITING";

	cout.width(14);
	cout << "TURNAROUND";

	cout.width(14);
	cout << "COMPLETION";

	cout << endl;
	cout <<"--------------------------------------------------------------------" << endl;
	cout <<"--------------------------------------------------------------------" << endl;

	for(int i = 0; i < size; i++)
	{

		cout << " P" << p[i].id;
		cout.width(3);
		cout << "|";
		cout.width(11);
		cout << p[i].arrival;

		cout.width(9);
		cout << p[i].burstVal;

		cout.width(11);
		cout << p[i].waiting;

		cout.width(14);
		cout << p[i].turnaround;

		cout.width(14);
		cout << p[i].completed;

		cout << endl;
		cout <<"--------------------------------------------------------------------" << endl;
	}

	cout <<"--------------------------------------------------------------------" << endl;
	cout <<"--------------------------------------------------------------------" << endl;
}
