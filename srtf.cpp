#include <iostream>
#include <string>

#define min(a, b) (a < b) ? a : b

using namespace std;

//stores data about the programs to be executed
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
void sortPrograms(Program*, int);
void printTable(Program*, int);
void calculateDetails(Program*, int);
void resolveTable(Program*, int);

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

void sortPrograms(Program *p, int size)
{
  int lastArrived;
  lastArrived = p[0].arrival;
  Program temp;
  int min;

  for(int i = 0; i < size; i++)
  {
    min = i;
    lastArrived = p[i].arrival;

    for(int j = i + 1; j < size; j++)
    {
      if(p[j].arrival <= lastArrived && p[j].burst < p[min].burst && p[j].status == 0)
      {
        min = j;
      }
    }

    temp = p[i];
    p[i] = p[min];
    p[min] = temp;
  }

  calculateDetails(p, size);
}

void calculateDetails(Program * p, int size)
{
  int counter = 0;
  int lastComplete = 0;

  resolveTable(p, size);
}

void resolveTable(Program * p, int size)
{
  for(int i = 0; i < size; i++)
  {
		p[i].waiting = p[i].completed - p[i].arrival - p[i].burstVal;
    p[i].turnaround = p[i].completed - p[i].arrival;
  }
}

void printTable(Program * p, int size)
{
  sortPrograms(p, size);
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
