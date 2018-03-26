#include <iostream>
#include <thread>

#define N 10

using namespace std;

static int p_finished = 0;
static int c_finished = 0;

//semaphores
int S = 1;  //turn semaphore
int E = N;  //gives the number of empty slots in the buffer
int F = 0;  //gives the number of filled slots in the buffer

			//semaphore functions
void wait(int *);
void signal(int *);

//key problem functions
void producer();
void consumer();

//working functions
void produce(); //produces process
void put(); //puts the process in the buffer
void take();  //takes the process from the buffer to execute
void consume(); //consumes the process

int main()
{
	cout << "Producer and consumer are now executing concurrently." << endl;

	thread first(producer);
	thread second(consumer);	

	//synchronising threads
	cin.get();
	first.join();
	second.join();
	cout << "producer and consumer functions completed." << endl;
	cin.get();

	return 0;
}

void wait(int *s)
{
	while (*s <= 0);
	*s = *s - 1;
}

void signal(int *s)
{
	*s = *s + 1;
}

void producer()
{
	while (p_finished < 10)
	{
		produce();
		wait(&E);
		wait(&S);
		put();
		signal(&S);
		signal(&F);
		p_finished++;
	}
}

void consumer()
{
	while (c_finished < 10)
	{
		wait(&F);
		wait(&S);
		take();
		signal(&S);
		signal(&E);
		consume();
		c_finished++;
	}
}

void produce()
{
	cout << "Producer producing the process." << endl;
}

void put()
{
	cout << "Process is put in the buffer. E = " << E << endl;
}

void take()
{
	cout << "Process taken from the buffer. F = " << F << endl;
}

void consume()
{
	cout << "Consumer is consuming the  the process." << endl;
}
