// DistributedProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//////////the Includes ///////
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <vector>

using namespace std;

///// Global Variables ////



int counter[64] = {}; // Generate a 64 element coounter array intialized with  zeros at the begining 
struct codon
{
	string name; 
	int count; 
};











string removeSpaces(string str)
{
	// To keep track of non-space character count 
	int count = 0;
	string temp;
	// Traverse the given string. If current character 
	// is not space, then place it at index 'count++' 
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4'
			&& str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '0')
		{
			str[count++] = str[i]; // here count is 
		}						   // incremented 
	str[count] = '\0';
	str.erase(count , str.size() - 1);
	
	return str;
}


int getNumberOfLines(string filename) 
{
	string line;
	int count = 0 ; 
	ifstream file(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			count++;
		
		}
		file.close();
	}
	return count; 




	

}


void get_lines(string filename , vector<string> &bar)
{
	
	int count = 0;
	string temp; 
	ifstream file(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, temp);
			
			temp = removeSpaces(temp);
			bar.insert(bar.begin ()+count ,temp);
			
			cout << bar[count] << endl; 
			count++;
			
		}
		file.close();
	}





}


void CondonsVector_Intialization(vector<codon> &CondonsVector)
{

	CondonsVector[0].name = "ttt";
	CondonsVector[1].name = "tac";
	CondonsVector[2].name = "tta";
	CondonsVector[3].name = "ttg";
	CondonsVector[4].name = "tct";
	CondonsVector[5].name = "tcc";
	CondonsVector[6].name = "tca";
	CondonsVector[7].name = "tcg";
	CondonsVector[8].name = "tat";
	CondonsVector[9].name = "tac";
	CondonsVector[10].name = "taa";
	CondonsVector[11].name = "tag";
	CondonsVector[12].name = "tgt";
	CondonsVector[13].name = "tgc";
	CondonsVector[14].name = "tga";
	CondonsVector[15].name = "tgg";


	CondonsVector[16].name = "ctt";
	CondonsVector[17].name = "ctc";
	CondonsVector[18].name = "cta";
	CondonsVector[19].name = "ctg";
	CondonsVector[20].name = "cgg";
	CondonsVector[21].name = "cct";
	CondonsVector[22].name = "ccc";
	CondonsVector[23].name = "cca";
	CondonsVector[24].name = "ccg";
	CondonsVector[25].name = "cat";
	CondonsVector[26].name = "cac";
	CondonsVector[27].name = "caa";
	CondonsVector[28].name = "cag";
	CondonsVector[29].name = "cgt";
	CondonsVector[30].name = "cgc";
	CondonsVector[31].name = "cga";




	CondonsVector[32].name = "att";
	CondonsVector[33].name = "atc";
	CondonsVector[34].name = "ata";
	CondonsVector[35].name = "atg";
	CondonsVector[36].name = "act";
	CondonsVector[37].name = "acc";
	CondonsVector[38].name = "aca";
	CondonsVector[39].name = "acg";
	CondonsVector[40].name = "aat";
	CondonsVector[41].name = "aac";
	CondonsVector[42].name = "aaa";
	CondonsVector[43].name = "aag";
	CondonsVector[44].name = "agt";
	CondonsVector[45].name = "agc";
	CondonsVector[46].name = "aga";
	CondonsVector[47].name = "agg";

	CondonsVector[48].name = "gtt";
	CondonsVector[49].name = "gtc";
	CondonsVector[50].name = "gta";
	CondonsVector[51].name = "gtg";
	CondonsVector[52].name = "gct";
	CondonsVector[53].name = "gcc";
	CondonsVector[54].name = "gca";
	CondonsVector[55].name = "gcg";
	CondonsVector[56].name = "gat";
	CondonsVector[57].name = "gac";
	CondonsVector[58].name = "gaa";
	CondonsVector[59].name = "gag";
	CondonsVector[60].name = "ggt";
	CondonsVector[61].name = "ggc";
	CondonsVector[62].name = "gga";
	CondonsVector[63].name = "ggg";




	for (int i = 0; i < 64; i++)
	{
		CondonsVector[i].count = 0;

	}



}




void printResults(vector<codon> &CondonsVector)
{
	 
	cout << "Final Results  ..........." << endl;

	for (int k = 0; k < CondonsVector.size(); k++)
	{
		cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;


	}

}








void serialExecution(vector<codon> &CondonsVector, vector<string> &my_vector)
{

	cout << "Please wait while data is being analyzed ..........." << endl;

	string temp = "---";

	for (int i = 0; i < my_vector.size(); i++)
	{
		
		string cuurent_line = my_vector[i];
		

		for (int j = 0; j < cuurent_line.size(); j += 3)
		{
			temp[0] = cuurent_line[j];
			temp[1] = cuurent_line[(j)+1];
			temp[2] = cuurent_line[(j)+2];
			
			for (int k = 0; k < CondonsVector.size(); k++)
			{
				if (temp == CondonsVector[k].name)
				{
					CondonsVector[k].count += 1;
					
				}

			}



		}

	}

	printResults(CondonsVector);

}

	








void OpenMPParallelExecution(vector<codon> &CondonsVector, vector<string> &my_vector)
{

	int i, j, k;
	cout << "please wait making data is bieng analyzed ..........." << endl;


	string temp = "---";





	for (i = 0; i < my_vector.size(); i++)
	{
		int tid = omp_get_thread_num();
		string cuurent_line = my_vector[i];
		cout << cuurent_line << " is catched by thread : " << tid << endl;



		for (j = 0; j < cuurent_line.size(); j += 3)
		{
			tid = omp_get_thread_num();
			temp[0] = cuurent_line[j];
			temp[1] = cuurent_line[(j)+1];
			temp[2] = cuurent_line[(j)+2];
			cout << temp << " is catched by thread : " << tid << endl;



			for (k = 0; k < CondonsVector.size(); k++)
			{
				if (temp == CondonsVector[k].name)
				{
					tid = omp_get_thread_num();
					CondonsVector[k].count += 1;
					cout << CondonsVector[k].name << " is catched by thread : " << tid << "and incremented by one" << endl;
				}

			}



		}

	}


	printResults(CondonsVector);

}






void OpenMPParallelExecutionSections(vector<codon> &CondonsVector, vector<string> &my_vector)
{

	int i, j, k;
	cout << "please wait making data is bieng analyzed ..........." << endl;

	string temp = "---";
#pragma omp parallel  for  private(i) shared(CondonsVector)
	for (i = 0; i < my_vector.size(); i++)
	{
		int tid = omp_get_thread_num();
		string cuurent_line = my_vector[i];
		cout << cuurent_line << " is catched by thread : " << tid << endl;
#pragma omp  parallel for private(j) shared(CondonsVector)
		for (j = 0; j < cuurent_line.size(); j += 3)
		{
			tid = omp_get_thread_num();
			temp[0] = cuurent_line[j];
			temp[1] = cuurent_line[(j)+1];
			temp[2] = cuurent_line[(j)+2];
			cout << temp << " is catched by thread : " << tid << endl;
#pragma omp parallel for  private(k) shared(CondonsVector)
			for (k = 0; k < CondonsVector.size(); k++)
			{
				if (temp == CondonsVector[k].name)
				{
					tid = omp_get_thread_num();
					#pragma omp critical 
					CondonsVector[k].count += 1;
					cout << CondonsVector[k].name << " is catched by thread : " << tid << "and incremented by one" << endl;
				}

			}



		}

	}


	printResults(CondonsVector);

}



























int main()
{
	int fileSize = 0; 
	string FILE = "InputSeq.dat.txt";


	int  i;
	//cout << "Enter the name of the text file containg the array with .txt\n";
	//cin >> FILE;



	int count = getNumberOfLines(FILE); 

	cout << "There's "<<count << "Lines" << endl;
	const int line_count = count ;
	
	vector<string> my_vector(line_count);
	get_lines(FILE , my_vector);


	vector<codon> CondonsVector(64);
	CondonsVector_Intialization(CondonsVector);
	OpenMPParallelExecutionSections(CondonsVector, my_vector);











}
