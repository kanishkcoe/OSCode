#include <iostream>

using namespace std;

struct Program
{
  int arrival;
  int waiting;
  int completed;
  int turnaround;
  int burst;
  int status;
  int id;
};

void sortPrograms(Program*, int);
void input(Program &, int, int, int);
void calculateDetails(Program*, int);
void printTable(Program*, int);

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

  sortPrograms(p, n);
  printTable(p, n);
}

void sortPrograms(Program *p, int size)
{
  int lastcompleted;
  lastcompleted = p[0].arrival + p[0].burst;
  p[0].completed = lastcompleted;
  Program temp;
  int min;

  for(int i = 1; i < size; i++)
  {
    min = i;

    for(int j = i + 1; j < size; j++)
    {
      if(p[j].arrival <= lastcompleted && p[j].burst < p[min].burst && p[j].status == 0)
      {
        min = j;
        p[min].status = 1;
      }
    }

    temp = p[i];
    p[i] = p[min];
    p[min] = temp;
    lastcompleted = p[i].burst + lastcompleted;
    p[i].completed = lastcompleted;
  }

  calculateDetails(p, size);
}

void input(Program &p, int i, int a, int b)
{
  p.id  = i;
  p.arrival = a;
  p.burst = b;
  p.status = 0;
}

void calculateDetails(Program * p, int size)
{
  p[0].waiting = 0;
  p[0].turnaround = p[0].completed - p[0].arrival;

  for(int i = 1; i < size; i++)
	{
		p[i].turnaround = p[i].completed - p[i].arrival;
    p[i].waiting = p[i - 1].completed - p[i].arrival;
	}
}

void printTable(Program * p, int size)
{
  cout << "\n\n\t\t\tSJF SCHEDULINNG\n";
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
		cout << p[i].burst;

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
