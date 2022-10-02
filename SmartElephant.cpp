#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elephants
{
	int weight;
	int iq;
	int idx;

}elephant;

elephant e[10000];
elephant temp;

/*
	sort function
	Input : num(int type)
	function : sort by weight. When the weights are same, sort by IQ.
*/
void sort(int num) {

	for (int i = 0; i < num - 1; i++) { 
		for (int j = i + 1; j < num; j++) {	
			if (e[i].weight > e[j].weight) {
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
			else if (e[i].weight == e[j].weight)
			{
				if (e[i].iq > e[j].iq) {
					temp = e[i];
					e[i] = e[j];
					e[j] = temp;
				}
			}
		}
	}
}

/*
	run_algorithm function
	Input : filename(char), num(int)
	function : Compute and print results output file
*/
void run_algorithm(char* filename, int num) {

	FILE* outFile;
	outFile = fopen(filename, "w");
	
	int i, j;
	int length = 1;
	int tmp_iq = 0;
	int max_seq = 0;
	int max_index = 0;
	int maxidx_iq;
	int table[10000];

	for (i = 0; i < num; i++)
	{
		tmp_iq = e[i].iq;

		//Find the number of cases where iq is larger and store it in the table.
		for (j = i; j < num - 1; j++)
		{
			if (tmp_iq > e[j + 1].iq)
			{
				length++;
				tmp_iq = e[j + 1].iq;
			}
		}
		table[i] = length;
		length = 1;		//initialize length again.
		
		//Find the sequence with the longest sequence.
		if (max_seq < table[i])
		{
			max_seq = table[i];
			max_index = i;
		}
	}

	//Prints longest sequence length
	fprintf(outFile, "%d\n", max_seq);

	//Prints sequence's index
	fprintf(outFile, "%d ", e[max_index].idx);

	maxidx_iq = e[max_index].iq;
	for (i = max_index; i < num - 1; i++)
	{
		if (maxidx_iq > e[i + 1].iq)
		{
			maxidx_iq = e[i + 1].iq;
			fprintf(outFile, "%d ", e[i + 1].idx);
		}
	}
	
	fclose(outFile);
}

int main()
{
	char inFileName[5][20] = { "Input_1.txt", "Input_2.txt", "Input_3.txt", "Input_4.txt", "Input_5.txt" };
	char outFileName[5][20] = { "Output_1.txt", "Output_2.txt", "Output_3.txt", "Output_4.txt", "Output_5.txt" };
	
	for (int i = 0; i < 5; i++)
	{
		FILE* inFile;
		int j = 0;
		inFile = fopen(inFileName[i], "r");
		if (inFile == NULL)
			printf("\nInput File Could Not Be Opened\n");

		//Receive values(weight, IQ) from Input file
		while (fscanf(inFile, "%d %d", &e[j].weight, &e[j].iq) != EOF)
		{
			e[j].idx = j + 1;
			j++;
		}
		fclose(inFile);

		sort(j);
		run_algorithm(outFileName[i], j);
	}
	
	return 0;
}

