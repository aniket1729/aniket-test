#include <stdio.h>

const int N = 8;

void print_second_larget_general(int* arr)
{

	int compares = 0;

	int max = 0;
	int max2 = 0;
	for(int i = 0 ; i < N ; ++i)
	{
		compares += 2;
		if( max < arr[i] )	{ max2 = max; max = arr[i]; --compares; }
		else if( max2 < arr[i] ) { max2 = arr[i]; }
	}
	for( int i = 0 ; i < N ; ++i )
		printf(" %d", arr[i]);
	printf("\n max= %d, max2= %d, compares= %d\n", max, max2, compares);
}

void get_max_pair(int* arr, int count);

int global_compares;
void print_second_larget_short(int* arr)
{
	global_compares = 0;

	int max = get_max(arr, N);
	
	int max2 = 0;
	for(int i = 0 ; i < N ; ++i)
	{
		compares += 1;
		if( max < arr[i] )	{ max2 = max; max = arr[i]; --compares; }
		else if( max2 < arr[i] ) { max2 = arr[i]; }
	}

	for( int i = 0 ; i < N ; ++i )
		printf(" %d", arr[i]);
	printf("\n max is %d, second-max is %d compares= %d\n", arr[1], arr[0], global_compares);
}

int get_max(int* arr, int count)
{
	if( count == 1 )
		return arr[0];

	int* new_arr = new int[(count+1)/2];
	for( int i = 0 ; i < (count+1)/2 ; ++i )
	{
		++global_compares;
		if( arr[i] > arr[count-1-i] ) 	new_arr[i] = arr[i];
		else				new_arr[i] = arr[count-1-i];
	}
	int max = get_max_pair(new_arr, (count+1)/2);
	delete[] new_arr;
	return max;
}
int main()
{
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int arr2[] = {8, 7, 6, 5, 4, 3, 2, 1};
	int arr3[] = {4, 3, 2, 1, 5, 6, 7, 8};
	int arr4[] = {4, 3, 2, 1, 8, 7, 6, 5};
	int arr5[] = {8, 7, 6, 5, 1, 2, 3, 4};
	int arr6[] = {5, 6, 7, 8, 1, 2, 3, 4};
	int arr7[] = {5, 6, 3, 4, 7, 8, 1, 2};
	int arr8[] = {5, 6, 1, 2, 7, 8, 3, 4};
	int arr9[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int arr10[] = {1, 3, 5, 7, 8, 6, 4, 2};

	print_second_larget_short(arr1);
	print_second_larget_short(arr2);
	print_second_larget_short(arr3);
	print_second_larget_short(arr4);
	print_second_larget_short(arr5);
	print_second_larget_short(arr6);
	print_second_larget_short(arr7);
	print_second_larget_short(arr9);
	print_second_larget_short(arr10);

	return 0;
}
