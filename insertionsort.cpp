#include <iostream>
#include <time.h>
#define MAX 100000
using namespace std;

void generate_numbers(int A[MAX], int n, string order)
{


    if (order == "crescente")
    {
        for (int i = 0; i < n; ++i)
            A[i] = 1 + i;
    }
    else if (order == "decrescente")
    {
        for (int i = 0; i < n; ++i)
            A[i] = n - i;
    }
    else if (order == "aleatorio")
    {
        for (int i = 0; i < n; ++i)
            A[i] = rand() % n;
    }
}

int main(int argc, char *argv[])
{
            
    clock_t tempo;
	tempo = clock();

    int array[MAX], tempArray[MAX];

    int size = atoi(argv[1]);
    string order = argv[2];

    generate_numbers(array, size, order);

    for (int i = 0; i < size; ++i)
        cout << array[i] << ",";
    cout << endl;

    tempArray[0] = array[0];
    // Loop on all numbers
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        // insert to the array until find number smaller than current one.
        while ((tempArray[j] > temp) && (j >= 0))
        {
            tempArray[j + 1] = tempArray[j];
            j--;
        }
        tempArray[j + 1] = temp;
    }

    for (int k = 0; k < size; k++)
        array[k] = tempArray[k];

    cout << "Insertion sorting is done..." << endl;
    cout << "The sorted numbers are" << endl;

    for (int z = 0; z < size; z++)
        cout << array[z] << " ";
    cout << endl;

    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);

    return 0;


}
