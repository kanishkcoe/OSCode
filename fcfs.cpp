//first come first serve scheduling
#include <iostream>

#define SIZE 4
int main()
{
	int arrival[SIZE];
	int execution[SIZE];
	int turnaround[SIZE];
	int completed[SIZE];
	int waiting[SIZE];

	for(int i = 0; i < SIZE; i++)
	{
		cout << "Enter the arrival time and execution time of program P" << i + 1 << " : ";
		cin >> arrival[i];
		cin >> execution[i];
	}

	for(i = 0; i < SIZE; i++)
	{
		if(i == 0)
		{
			completed[i] = arrival[i] + execution[i];
			waiting[i] = 0;
		}
		else if(arrival[i] < completed[i - 1])
		{
			completed[i] = completed[i - 1] + execution[i];
			waiting[i] = completed[i - 1] - arrival[i];
		}
		else
		{
			completed[i] = arrival[i] + execution[i];
		}
		turnaround[i] = completed[i] - arrival[i];

	}

	cout << "\n\n\t\t\tFCFS SCHEDULINNG\n";
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

	for(i = 0; i < SIZE; i++)
	{

		cout << " P" << i + 1;
		cout.width(3);
		cout << "|";
		cout.width(11);
		cout << arrival[i];

		cout.width(9);
		cout << execution[i];

		cout.width(11);
		cout << waiting[i];

		cout.width(14);
		cout << turnaround[i];

		cout.width(14);
		cout << completed[i];

		cout << endl;
		cout <<"--------------------------------------------------------------------" << endl;
	}

	cout <<"--------------------------------------------------------------------" << endl;
	cout <<"--------------------------------------------------------------------" << endl;
	return 0;
}
