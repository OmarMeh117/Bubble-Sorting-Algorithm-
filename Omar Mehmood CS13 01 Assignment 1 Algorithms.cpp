//Omar Mehmood 13A0 01 Advanced Programming Techniques Assignment 1 Bubble Sorting Algorithms 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void plain (int array[] , int size);
void efficient (int array[] , int size);

int main()
{	
	int sort, t;
	double duration;
	clock_t start, end;
	
	cout << "\nHow many items do you wish to sort: ";
	cin >> sort;
	
	ofstream bestcase("Bestcase.txt");
	for (int i = 1 ; i <= sort ; i++)
	bestcase << i << "\n";
	
	ofstream averagecase("Averagecase.txt");
	for (int i = 1 ; i <= sort ; i++)
	averagecase << rand()%sort << "\n";
	
	ofstream worstcase("Worstcase.txt");
	for (int i = sort ; i >= 1 ; i--)
	worstcase << i << "\n";

	{
	cout << "\nHere is the time it took to sort your data with both bubble sorts\n-----------------------------------------------------------------\n";
	int data [sort];
	//best case plain 
	ifstream bestcase("Bestcase.txt");
	for (int i = 1; i < sort ; i++)
	bestcase >> data[i];
	start = clock();
	plain (data, sort);
	end = clock();
	duration=((double)(end - start))/CLOCKS_PER_SEC;
	cout << "\nBest case with plain sort: " << fixed<<setprecision(3)<<duration;
	
	
	//average case plain
	ifstream averagecase("Averagecase.txt");
	for (int i = 1; i < sort ; i++)
	averagecase >> data[i];
	start = clock();
	plain (data, sort);
	end = clock();
	duration=((double)(end - start))/CLOCKS_PER_SEC;
	cout << "\nAverage case with plain sort: " << fixed<<setprecision(3)<<duration;
	
	//worst case plain
	ifstream worstcase("Worstcase.txt");
	for (int i = 0; i < sort ; i++)
	worstcase >> data[i];
	start = clock();
	plain (data, sort);
	end = clock();
	duration=((double)(end - start))/CLOCKS_PER_SEC;
	cout << "\nWorst case with plain sort: " << fixed<<setprecision(3)<<duration;
		
	//best case efficient
	ifstream("Bestcase.txt");
	start= clock();
	efficient(data, sort);
	end = clock();
	duration=((double)(end - start))/CLOCKS_PER_SEC;
	cout << "\n\nBest case with efficient sort: " << fixed<<setprecision(3)<<duration;
	
	
	//average case efficient
	ifstream("Averagecase.txt");
	start= clock();
	efficient(data, sort);
	end = clock();
	duration=((double)(end - start))/CLOCKS_PER_SEC;
	cout << "\nAverage case with efficient sort: " << fixed<<setprecision(3)<<duration;

	
	//worst case efficient
	ifstream("Worstcase.txt");
	start= clock();
	efficient(data, sort);
	end = clock();
	duration=((double)(end - start))/CLOCKS_PER_SEC;
	cout << "\nWorst case with efficient sort: " << fixed<<setprecision(3)<<duration;
	}

	return 0;
}

void plain (int array[] , int size) 
{
	
	for(int pass = 1 ; pass<=(size-1) ; pass++)
	 	 for(int index=1; index<=(size-1) ; index++)
	    if(array[index]<array[index+1])
	      {int t=array[index];  
	       array[index]=array[index+1];
	       array[index+1]=t;}	
	
}

void efficient (int array[] , int size)
{
		for(int pass=1; pass<=(size-1); pass++)
	{
		int swap=0;
		for(int i=0; i<=(size); i++)
		{
			if(array[i]>array[i+1])
			{	swap=1; 
				int t=array[i];
				array[i]=array[i+1];
				array[i+1]=t;
			}
		} 
		if(swap==0) break;	
	}
	
}


