//program 7
//banker's algorithm
#include <iostream>

using namespace std;

struct Allocation
{
	int id;
	int a;
	int b;
	int c;
};

struct Max
{
	int id;
	int a;
	int b;
	int c;
};

struct Available
{
	int a;
	int b;
	int c;
};

struct Work
{
	int a;
	int b;
	int c;
};


struct Need
{
	int id;
	int a;
	int b;
	int c;
};

struct Request
{
	int id;
	int a;
	int b;
	int c;
};

void finishTheProcess(bool *finish, Work *work, Allocation *allocation, int index)
{
	finish[index] = true;
	cout << "Process " << index << " can get the resources." << endl;
	work->a = work->a + allocation[index].a;
	work->b = work->b + allocation[index].b;
	work->c = work->c + allocation[index].c;
}

bool notAllAllocated(bool *finish, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(!finish[i])
		return true;
	}
	return false;
}

int main()
{
	int n;	//number of processes
	cout << "Enter the number of processes requesting for the resources : ";
	cin >> n;

	//tables required to compute safe sequence
	Allocation *allocation = new struct Allocation[n];
	Max *max = new struct Max[n];
	Available available;
	Need *need = new Need[n];

	int totalA, totalB, totalC;
	int mainA, mainB, mainC;

	cout << "Enter number of instances of resource A : ";cin >> mainA;
	cout << "Enter number of instances of resource B : ";cin >> mainB;
	cout << "Enter number of instances of resource C : ";cin >> mainC;

	totalA = totalB = totalC = 0;

	for(int i = 0; i < n; i++)
	{
		//formation of allocation table
		cout << "Enter the resources allocated to the process " << i << " : " << endl;
		allocation[i].id = need[i].id = max[i].id = i;
 		cout << "A : "; cin >> allocation[i].a;
		cout << "B : "; cin >> allocation[i].b;
		cout << "C : "; cin >> allocation[i].c;
		totalA += allocation[i].a;
		totalB += allocation[i].b;
		totalC += allocation[i].c;

		//formation of maximum resource required table
		cout << "Enter the maximum resources required by the process " << i << " : " << endl;
 		cout << "A : "; cin >> max[i].a;
		cout << "B : "; cin >> max[i].b;
		cout << "C : "; cin >> max[i].c;

		//calculation for the need matrix
		need[i].a = max[i].a - allocation[i].a;
		need[i].b = max[i].b - allocation[i].b;
		need[i].c = max[i].c - allocation[i].c;
	}

	available.a = mainA - totalA;
	available.b = mainB - totalB;
	available.c = mainC - totalC;

	// banker's algorithm
	Request request;

	cout << "Enter the process id and its request : " << endl;
	cout << "ID : "; cin >> request.id;
	cout << "A : "; cin >> request.a;
	cout << "B : "; cin >> request.b;
	cout << "C : "; cin >> request.c;

	if(request.a > need[request.id].a || request.b > need[request.id].b || request.c > need[request.id].c)
	{
		cout << "ERROR! Request is exceeding the required limit." << endl;
	}
	else
	{
		if(request.a > available.a || request.b > available.b || request.c > available.c)
		{
			cout << "ERROR! Request is exceeding the available limit." << endl;
		}
		else
		{
			//change the available matrix
			available.a = available.a - request.a;
			available.b = available.b - request.b;
			available.c = available.c - request.c;

			//change the allocation matrix
			allocation[request.id].a = allocation[request.id].a + request.a;
			allocation[request.id].b = allocation[request.id].b + request.b;
			allocation[request.id].c = allocation[request.id].c + request.c;

			//change the need matrix
			need[request.id].a = need[request.id].a - request.a;
			need[request.id].b = need[request.id].b - request.b;
			need[request.id].c = need[request.id].c - request.c;
		}
	}

	//checking if the new state is a safe state or not
	//safety algorithm
	bool *finish = new bool[n];
	Work work;
	bool flag;

	//initialization
	work.a = available.a;
 	work.b = available.b;
	work.c = available.c;

	for(int i = 0; i < n; i++)
	{
		finish[i] = false;
	}

	//sequence check
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			flag = false;	//considering no process is allocated
			if(!finish[j] && need[j].a <= work.a  && need[j].b <= work.b && need[j].c <= work.c)
			{
				flag = true;	//there is such process
				finishTheProcess(finish, &work, allocation, j);
			}
		}
		if(!flag)	//no resource allocation takes place
		{
			if(notAllAllocated(finish, n))
			{
				cout << "DeadLock present" << endl;
				break;
			}
		}
	}

	if(!notAllAllocated(finish, n))
	{
		cout << "Processes are in the safe sequence!" << endl;
	}
	return 0;
}
