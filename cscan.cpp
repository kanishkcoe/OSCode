#include <iostream>

using namespace std;

int mod(int a)
{
    if(a < 0)
        return -1 * a;
    return a;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void process(int *memory, int n, int header)
{
    int max, min = 0;
    bool there = false;

    for(int i = 0; i < n; i++)
    {
      if(memory[min] > memory[i])
        min = i;
    }

    for(int i = 0; i < n; i++)
    {
        max = i;
        there = false;
        for(int j = i + 1; j < n; j++)
        {
            if(memory[j] > memory[min] && memory[j] < header)
            {
                max = j;
                there = true;
            }
        }
        if(there)
        {
            swap(memory[max], memory[i]);
        }
        else
            break;
    }

    swap(memory[max++], memory[min]);

    for(int i = max; i < n; i++)
    {
        max = i;
        for(int j = i + 1; j < n; j++)
        {
            if(memory[j] > memory[max])
            {
                max = j;
            }
        }
        swap(memory[max], memory[i]);
    }
}

void printSequence(int *memory, int n, int header)
{
    cout << header;
    for(int i = 0; i < n; i++)
    {
      cout << " -> " << memory[i] ;
    }
    cout << endl;
}

int calculateTotal(int *memory, int n, int header)
{
    int total = mod(memory[0] - header);

    for(int i = 1; i < n; i++)
    {
      total += mod(memory[i] - memory[i - 1]);
    }

    return total;
}

void input(int *memory, int n)
{
    cout << "Insert the process memory requirement : " << endl;
    for (int i = 0; i < n; i++ )
    {
        cout << "Process " << i + 1 << " : ";
        cin >> memory[i];
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes  : " << endl;
    cin >> n;
    int header;

    cout << "Enter header location : ";
    cin >> header;

    int *memory = new int[n];

    input(memory, n);
    process(memory, n, header);
    printSequence(memory, n, header);
    cout << "Total total head movement = " << calculateTotal(memory, n, header) << endl;
    return 0;
}
