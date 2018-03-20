//priority scheduling

#include <iostream>

using namespace std;

struct Program
{
	int arrival;
	int burst;
	int priority;
	int turnaround;
	int waiting;
	int completion;
	int id;
	int status;
};

void input(Program &p, int i, int a, int b, int pr)
{
	p.id = i;
	p.arrival = a;
	p.burst = b;
	p.priority = pr;
	p.turnaround = 0;
	p.waiting = 0;
	p.completion = 0;
	p.status = 0;
}

void swap(Program &p1, Program &p2)
{
	Program temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

void sort(Program *p, int n)
{
	//sorts the program with respect to the priority
	int min;	//stores the maximum priority program
	int lastCompletion;	//last completion time
	int counter = 0;
	//first Sort for same arrival time
	for(int i = 0; i < n; i++)
	{
		min = i;

		for(int j = i + 1; j < n; j++)
		{
			if(p[j].priority < p[min].priority && p[min].arrival == p[j].arrival)
			{
				min = j;
			}
		}
		swap(p[min], p[i]);
	}

	cout << endl;
	//second sort for correct program execution
	p[0].completion = p[0].arrival + p[0].burst;
	lastCompletion = p[0].completion;
	p[0].status = 1;
	min = 1;	//considering the first process has run
	counter++;

	while(counter < n)
	{
		for(int i = 0; i < n; i++)
		{
			if(p[i].status == 0 && p[i].priority < p[min].priority && p[i].arrival < lastCompletion)
			{
				min = i;
			}
		}

		//next process completion
		p[min].completion = lastCompletion + p[min].burst;
		lastCompletion = p[min].completion;
		p[min].status = 1;
		counter++;

		//get a non-executed program
		for(int i = 0; i < n; i++)
		{
			if(p[i].status == 0)
			{
				min = i;
				break;
			}
		}
	}
}

void calculateDetails(Program *p, int n)
{
	int min;

	for(int i = 0; i < n; i++)
	{
		p[i].turnaround = p[i].completion - p[i].arrival;
		p[i].waiting = p[i].turnaround - p[i].burst;
	}

	//sorting with respect to order of id
	for(int i = 0; i < n; i++)
	{
		min = i;

		for(int j = i + 1; j < n; j++)
		{
			if(p[j].id < p[min].id)
			{
				min = j;
			}
		}
		swap(p[min], p[i]);
	}

}

void formTable(Program *p, int n)
{
	sort(p, n);
	calculateDetails(p, n);

	cout << "\n\n\t\tPRIORITY BASED SCHEDULING\n";
	cout << "------------------------------------------------------------------------------"<< endl;
	cout << "------------------------------------------------------------------------------"<< endl;
	cout.width(7);
	cout << "PROCESS";

	cout.width(11);
	cout << "ARRIVAL";

	cout.width(9);
	cout << "BURST";

	cout.width(11);
	cout << "PRIORITY";

	cout.width(9);
	cout << "WAITING";

	cout.width(14);
	cout << "TURNAROUND";

	cout.width(14);
	cout << "COMPLETION\n";

	cout << "------------------------------------------------------------------------------"<< endl;
	cout << "------------------------------------------------------------------------------"<< endl;
	for(int i = 0; i < n; i++)
	{
		cout << "P" << p[i].id;
		cout.width(3);
		cout << "|";

		cout.width(11);
		cout << p[i].arrival;

		cout.width(9);
		cout << p[i].burst;

		cout.width(11);
		cout << p[i].priority;

		cout.width(11);
		cout << p[i].waiting;

		cout.width(14);
		cout << p[i].turnaround;

		cout.width(14);
		cout << p[i].completion;

		cout << endl;

		cout << "------------------------------------------------------------------------------"<< endl;
	}
}

int main()
{
	Program *p;	//program array
	int a, b, pr;	//arrival time, burst time and priority

	int n;	//gives the number of programs to be scheduled

	cout << "Enter the number of programs to be scheduled: ";
	cin >> n;

	p = new Program[n];

	for(int i = 0; i < n; i++)
	{
		cout << "Enter arrival, burst and priority of the process "<<i + 1<<" : ";
		cin >> a >> b >> pr;
		input(p[i], i + 1, a, b, pr);
	}

	formTable(p, n);
	return 0;
}
