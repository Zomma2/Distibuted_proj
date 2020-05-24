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
#include <math.h> 

using namespace std;

///// Global Variables ////



int counter[64] = {}; // Generate a 64 element coounter array intialized with  zeros at the begining 
struct codon
{
	string name; //Codon name 
	int count;  // number of times that codon appears
};

struct protein
{
	string name; // name of the protein 
	int count; // the number of times that protein appears
	string codon[6];  // The names of condon representing that protein 


};







/*
This function remove from a given string all spaces and numbers leaving only letters 

*/

string removeSpaces(string str)
{
	// To keep track of non-space character count 
	int count = 0;
	string temp;
	// Traverse the given string. If current character 
	// is not space or numbers , then place it at index 'count++' 
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




/*
This function takes a filname of a file that contain number of lines of 
Strings then count the number of lines in that given txt file
returning the number of lines in .txt file
*/

int getNumberOfLines(string filename) 
{
	string line;
	int count = 0 ;  // intialize count of lines in txt file intially by zero 
	ifstream file(filename);
	if (file.is_open())
	{
		while (!file.eof()) // while not reaching the end of file 
		{
			getline(file, line); 
			count++; // increase count of lines 
		
		}
		file.close(); // close the file 
	}
	return count; 




	

}

/*
This function get a vector of strings and file name that represent a txt file 
the function place each line inside the file to a string inside the vector of strings 
so at the end of the function the passed vector will have all the lines of txt each line in one string of the 
vector strings


*/

void get_lines(string filename , vector<string> &bar)
{
	
	int count = 0;// intialize count of lines in txt file intially by zero 
	string temp; // intalize a temporary string  
	ifstream file(filename);
	if (file.is_open()) 
	{
		while (!file.eof())  // while not reaching the end of file 
		{
			getline(file, temp); // get the line from file to temp string 
			
			temp = removeSpaces(temp); // pass that temp string to removespaces function to remove any numbers or spaces fromthat string
			bar.insert(bar.begin ()+count ,temp); // insert the string in temp to the string  in vector passed
			
			cout << bar[count] << endl;  // print the string we got at the vector 
			count++; // increment the count by one 
			
		}
		file.close(); // close the file 
	} 





}





/*

Intialize the proteins function take a vector of type protein and fill it with the given 21 protein and thier asociated codons 
then intailize it's count to zero , the function also take a boolean that indicate wether we should use for-parallelism
or not 



*/



void ProteinsVector_Intialization(vector<protein> &ProteinsVector , bool isForParallel)
{

	ProteinsVector[0].name = "Phe";
	ProteinsVector[0].codon[0] = "ttt";
	ProteinsVector[0].codon[1] = "ttc";


	ProteinsVector[1].name = "Leu";
	ProteinsVector[1].codon[0] = "tta";
	ProteinsVector[1].codon[1] = "ttg";
	ProteinsVector[1].codon[2] = "ctt";
	ProteinsVector[1].codon[3] = "ctc";
	ProteinsVector[1].codon[4] = "cta";
	ProteinsVector[1].codon[5] = "ctg";




	ProteinsVector[2].name = "Lle";
	ProteinsVector[2].codon[0] = "att";
	ProteinsVector[2].codon[1] = "atc";
	ProteinsVector[2].codon[2] = "ata";
	


	ProteinsVector[3].name = "Met";
	ProteinsVector[3].codon[0] = "atg";
	

	ProteinsVector[4].name = "Val";
	ProteinsVector[4].codon[0] = "gtt";
	ProteinsVector[4].codon[1] = "gtc";
	ProteinsVector[4].codon[2] = "gta";
	ProteinsVector[4].codon[3] = "gtg";


	ProteinsVector[5].name = "Ser";
	ProteinsVector[5].codon[0] = "tct";
	ProteinsVector[5].codon[1] = "tcc";
	ProteinsVector[5].codon[2] = "tca";
	ProteinsVector[5].codon[3] = "tcg";
	ProteinsVector[5].codon[4] = "agt";
	ProteinsVector[5].codon[5] = "agc";





	ProteinsVector[6].name = "Pro";
	ProteinsVector[6].codon[0] = "cct";
	ProteinsVector[6].codon[1] = "ccc";
	ProteinsVector[6].codon[2] = "cca";
	ProteinsVector[6].codon[3] = "ccg";


	
	
	ProteinsVector[7].name = "Thr";
	ProteinsVector[7].codon[0] = "act";
	ProteinsVector[7].codon[1] = "acc";
	ProteinsVector[7].codon[2] = "aca";
	ProteinsVector[7].codon[3] = "acg";


	ProteinsVector[8].name = "Ala";
	ProteinsVector[8].codon[0] = "gct";
	ProteinsVector[8].codon[1] = "gcc";
	ProteinsVector[8].codon[2] = "gca";
	ProteinsVector[8].codon[3] = "gcg";






	
	ProteinsVector[9].name = "Tyr";
	ProteinsVector[9].codon[0] = "tat";
	ProteinsVector[9].codon[1] = "tac";
	


	ProteinsVector[10].name = "His";
	ProteinsVector[10].codon[0] = "cat";
	ProteinsVector[10].codon[1] = "cac";
	


	ProteinsVector[11].name = "Gln";
	ProteinsVector[11].codon[0] = "caa";
	ProteinsVector[11].codon[1] = "cag";
	

	ProteinsVector[12].name = "Asn";
	ProteinsVector[12].codon[0] = "aat";
	ProteinsVector[12].codon[1] = "aac";



	

	
	
	ProteinsVector[13].name = "Lys";
	
	ProteinsVector[13].codon[0] = "aaa";
	ProteinsVector[13].codon[1] = "aag";

	
	
	
	ProteinsVector[14].name = "Asp";
	ProteinsVector[14].codon[0] = "gat";
	ProteinsVector[14].codon[1] = "gac";



	
	
	
	ProteinsVector[15].name = "Glu";
	ProteinsVector[15].codon[0] = "gaa";
	ProteinsVector[15].codon[1] = "gag";


	
	
	
	ProteinsVector[16].name = "Cys";
	ProteinsVector[16].codon[0] = "tgt";
	ProteinsVector[16].codon[1] = "tgc";




	ProteinsVector[17].name = "Trp";
	ProteinsVector[17].codon[0] = "tgg";




	ProteinsVector[18].name = "Arg";
	ProteinsVector[18].codon[0] = "aga";
	ProteinsVector[18].codon[1] = "agg";
	ProteinsVector[18].codon[2] = "cgt";
	ProteinsVector[18].codon[3] = "cgc";
	ProteinsVector[18].codon[4] = "cga";
	ProteinsVector[18].codon[5] = "cgg";
	









	ProteinsVector[19].name = "Gly";
	ProteinsVector[19].codon[0] = "ggt";
	ProteinsVector[19].codon[1] = "ggc";
	ProteinsVector[19].codon[2] = "gga";
	ProteinsVector[19].codon[3] = "ggg";




	ProteinsVector[20].name = "Stop";
	ProteinsVector[20].codon[0] = "taa";
	ProteinsVector[20].codon[1] = "tag";
	ProteinsVector[20].codon[2] = "tga";














	if (!isForParallel)
	{

		for (int i = 0; i < 21; i++)
		{
			ProteinsVector[i].count = 0;

		}
	}


	else

	{
#pragma omp  parallel for 
		for (int i = 0; i < 21; i++)
		{
			ProteinsVector[i].count = 0;

		}


	
	}





}














/*

Intialize the codons  function take a vector of type codon and fill it with the given condons
then intailize the codon counts to zero , the function also take a boolean that indicate wether we should use for-parallelism
or not



*/







void CondonsVector_Intialization(vector<codon> &CondonsVector , bool isForParallel )
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


	if (!isForParallel)
	{
		for (int i = 0; i < 64; i++)
		{
			CondonsVector[i].count = 0;

		}
	}

	else
	{

#pragma omp  parallel for 
		for (int i = 0; i < 64; i++)
		{
			CondonsVector[i].count = 0;

		}

	
	
	
	}


}



/*
The printResults function takes in  a condon  vector and print each codon of the codons 
and its count that represent how many times that codon is represented in the txt file 
*/






void printResults(vector<codon> &CondonsVector)
{
	 
	cout << "Final Results  ..........." << endl;

	for (unsigned int k = 0; k < CondonsVector.size(); k++)
	{
		cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;


	}

}





/*
SerialExecution function takes in file name , vector of codons and vector of proteins 
the function read the file andextract condons and thier counts and then compute
proteins freqencies and it does that in a serial manner without parallelism 
*/



void serialExecution(string FILE, vector<codon> &CondonsVector, vector<protein>&ProteinsVector)
{



int count = getNumberOfLines(FILE); // intialize thte count with the number of lines in the given file 

cout << "There's "<<count << "Lines" << endl; // print out the number of lines in the given file 
const int line_count = count ; // create a constant containing the number of lines in the given  file 

vector<string> my_vector(line_count);  // Intialize the String vector with the number of lines in the file
get_lines(FILE , my_vector); // For each line in the file we put it without numbers and spaces in an element
								//of the vector string



CondonsVector_Intialization(CondonsVector ,false); // intialize condons vector , disabling for loop parallelism 
ProteinsVector_Intialization(ProteinsVector, false); // intialize protein vector , disabling for loop parallelism 


string temp; //create a temporary string 
unsigned int i, j, k; // create the variables i,j,k

cout << "please wait While data is being analyzed ..........." << endl;



for (i = 0; i < my_vector.size(); i++) // For every line in the String vector
{
	temp = "---"; //create a temporary string with three dashes 
	string cuurent_line; // Create variable current_line to place the current line of the string vector in it 

	
		int tid = omp_get_thread_num(); // get the number of thread in tid variable 
		cuurent_line = my_vector[i]; // place current  line from string vector  in the current line variable 

	
	for (j = 0; j < cuurent_line.size(); j += 3) // for every three characters in the current line
	{




		
			temp[0] = cuurent_line[j]; // put the first letter in temp string 
			temp[1] = cuurent_line[(j)+1]; // put the  second letter in temp string
			temp[2] = cuurent_line[(j)+2]; // put the third letter in temp string
		

		for (k = 0; k < CondonsVector.size(); k++) // for every codon of the codons stored in codons vector 
		{
			if (temp == CondonsVector[k].name) // if the three letters represent  specific condon k 
			{


					CondonsVector[k].count += 1; // increment condon k count by one 

				
			}

		}



	}







}



cout << "Final Results  ..........." << endl; 
int Sum = 0; // INtialize sum to zero

for (unsigned int k = 0; k < CondonsVector.size(); k++) // for every condon in codon vector 
{

	cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;  // Print out the codon and its count 
	Sum += CondonsVector[k].count; // increment the count Sum with each codon count , in other words Sum variable will be equal to sum
										//of all condons appearnce
	
}



for (int j = 0; j < 21; j++) // for every on of the 21 Proteins
{
	for (int k = 0; k < 64; k++) // for every on in the 64 Condons 
	{

		i = 0; // intialize i equal to zero 
		while (i < 6) // for every codon in the codon list of every protein 
		{
			if (ProteinsVector[j].codon[i] == CondonsVector[k].name) // if the codon representing the protein is detected 
			{

					ProteinsVector[j].count += CondonsVector[k].count; // increment that protein count withe the codon count 
				
			}
			i++; // increment i by one 
		}


	}


		cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl; // Print out 
																																					//The proteins with thier frequencies 
	


}





}

	

/*
The ParallelSection function takes in a string representing the file name and vector of codons and vector of proteins 
The function use openmp section parallelism technique to compute the proteins frequecny and count  



*/


void ParallelSection(string FILE, vector<codon> &CondonsVector, vector<protein>&ProteinsVector)
{
	
	int count; // create count variable 
	
	
	
#pragma omp parallel 
	{
#pragma omp sections 
		{
# pragma omp section 
			{

				count = getNumberOfLines(FILE);// intialize the count with the number of lines in the given file 
			}
		}
	}
			const int line_count = count; // create a constant containing the number of lines in the given  file 
			vector<string> my_vector(line_count); // Intialize the String vector with the number of lines in the file

#pragma omp parallel 
			{
#pragma omp sections 
				{
# pragma omp section 
			{

				get_lines(FILE, my_vector);// For each line in the file we put it without numbers and spaces in an element
								//of the vector string

			}
	
		
#pragma omp section
			{


				CondonsVector_Intialization(CondonsVector ,false);// intialize condons vector , disabling for loop parallelism 

			}

#pragma omp section
			{

				ProteinsVector_Intialization(ProteinsVector , false);// intialize protein vector , disabling for loop parallelism


			}

		
		
		
		
		}
	
	
	
	}
	cout << "please wait while  data is being analyzed ..........." << endl;




#pragma omp parallel 
	{

#pragma omp sections 
		{

#pragma omp section
			{ unsigned int i, j, k; // create the variables i,j,k
				string temp = "---"; //create a temporary string 
				for (i = 0; i < my_vector.size()/4; i++) // For every line in the String vector
				{
					temp = "---"; //create a temporary string with three dashes 
					int tid = omp_get_thread_num(); // get the number of thread in tid variable 
					string cuurent_line = my_vector[i];// Create variable current_line to place the current line of the string vector in it 
					cout << cuurent_line << " is catched by thread : " << tid << endl; // print out the current line and the thread that catched it

					for (j = 0; j < cuurent_line.size(); j += 3)// for every three characters in the current line
					{

						temp[0] = cuurent_line[j];// put the first letter in temp string 
						temp[1] = cuurent_line[(j)+1]; // put the  second letter in temp string
						temp[2] = cuurent_line[(j)+2]; // put the third letter in temp string
						for (k = 0; k < CondonsVector.size(); k++) // for every codon of the codons stored in codons vector 
						{
							if (temp == CondonsVector[k].name) // if the three letters represent  specific condon k 
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;// increment condon k count by one 

								}
							}

						}



					}

				}


			}
		
#pragma omp section
			{
				unsigned int i, j, k; // create the variables i,j,k
				for (i = my_vector.size() / 4; i < my_vector.size() / 2; i++)
				{
					
					string temp = "---"; //create a temporary string with three dashes 
					temp = "---"; //create a temporary string with three dashes 
					int tid = omp_get_thread_num(); // get the number of thread in tid variable 
					string cuurent_line = my_vector[i];// Create variable current_line to place the current line of the string vector in it 
					cout << cuurent_line << " is catched by thread : " << tid << endl; // print out the current line and the thread that catched it

					for (j = 0; j < cuurent_line.size(); j += 3)// for every three characters in the current line
					{

						temp[0] = cuurent_line[j];// put the first letter in temp string 
						temp[1] = cuurent_line[(j)+1];// put the  second letter in temp string
						temp[2] = cuurent_line[(j)+2];// put the third letter in temp string
						for (k = 0; k < CondonsVector.size(); k++) // for every codon of the codons stored in codons vector 
						{
							if (temp == CondonsVector[k].name) // if the three letters represent  specific condon k 
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;// increment condon k count by one 

								}
							}

						}



					}

				}


			}
		
		

#pragma omp section
			{
				unsigned int i, j, k; // create the variables i,j,k
				for (i = my_vector.size() / 2; i < (3*my_vector.size()) / 4; i++)
				{
				
					string temp = "---";//create a temporary string with three dashes 
					temp = "---"; //create a temporary string with three dashes 
					int tid = omp_get_thread_num();  // get the number of thread in tid variable 
					string cuurent_line = my_vector[i]; // Create variable current_line to place the current line of the string vector in it 
					cout << cuurent_line << " is catched by thread : " << tid << endl;// print out the current line and the thread that catched it

					for (j = 0; j < cuurent_line.size(); j += 3) // for every three characters in the current line
					{

						temp[0] = cuurent_line[j];  // put the first letter in temp string 
						temp[1] = cuurent_line[(j)+1]; // put the  second letter in temp string
						temp[2] = cuurent_line[(j)+2]; // put the third letter in temp string
						for (k = 0; k < CondonsVector.size(); k++) // for every codon of the codons stored in codons vector 
						{
							if (temp == CondonsVector[k].name)// if the three letters represent  specific condon k 
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;// increment condon k count by one 

								}
							}

						}



					}

				}


			}
		
#pragma omp section
			{
				unsigned int i, j, k; // create the variables i,j,k
				for (i = (3 * my_vector.size()) / 4 ; i <  my_vector.size() / 4; i++)
				{	
					string temp = "---";//create a temporary string with three dashes 
					temp = "---";//create a temporary string with three dashes 
					int tid = omp_get_thread_num();// get the number of thread in tid variable 
					string cuurent_line = my_vector[i]; // Create variable current_line to place the current line of the string vector in it 
					cout << cuurent_line << " is catched by thread : " << tid << endl;// print out the current line and the thread that catched it

					for (j = 0; j < cuurent_line.size(); j += 3)// for every three characters in the current line
					{

						temp[0] = cuurent_line[j]; // put the first letter in temp string 
						temp[1] = cuurent_line[(j)+1]; // put the  second letter in temp string
						temp[2] = cuurent_line[(j)+2];// put the third letter in temp string
						for (k = 0; k < CondonsVector.size(); k++)// for every codon of the codons stored in codons vector 
						{
							if (temp == CondonsVector[k].name)// if the three letters represent  specific condon k 
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;// increment condon k count by one 

								}
							}

						}



					}

				}


			}
		
		
		
		
		}



	}




	cout << "Final Results  ..........." << endl;


	int Sum = 0; // INtialize sum to zero

#pragma omp parallel 
	{

#pragma omp sections 
		{

#pragma omp section
			{

				for (unsigned int k = 0; k < CondonsVector.size()/4; k++)// for every condon in codon vector 
				{

					cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;   // Print out the codon and its count 
					Sum += CondonsVector[k].count; // increment the count Sum with each codon count , in other words Sum variable will be equal to sum
										//of all condons appearnce
	

				}

			}







#pragma omp section
			{

				for (unsigned int k = CondonsVector.size() / 4; k < CondonsVector.size()/2; k++) // for every condon in codon vector 
				{

					cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;  // Print out the codon and its count 
					Sum += CondonsVector[k].count; // increment the count Sum with each codon count , in other words Sum variable will be equal to sum
										//of all condons appearnce
	

				}

			}













#pragma omp section
			{

				for (unsigned int k = CondonsVector.size() / 2 ; k < (3*CondonsVector.size())/4; k++)// for every condon in codon vector 
				{

					cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl; // Print out the codon and its count 
					Sum += CondonsVector[k].count;// increment the count Sum with each codon count , in other words Sum variable will be equal to sum
										//of all condons appearnce
	

				}

			}










#pragma omp section
			{

				for (unsigned int k = (3 * CondonsVector.size()) / 4; k < CondonsVector.size(); k++) // for every condon in codon vector  // for every condon in codon vector 
				{

					cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl; // Print out the codon and its count 
					Sum += CondonsVector[k].count; // increment the count Sum with each codon count , in other words Sum variable will be equal to sum
										//of all condons appearnce


				}

			}








		}
	}



#pragma omp parallel 
	{

#pragma omp sections 
		{

#pragma omp section
			{
				int i;
       	for (int j = 0; j < 21 / 4; j++) // for every on of the 21 Proteins
				{
					for (int k = 0; k < 64; k++)// for every on in the 64 Condons 
					{

						i = 0; // intialize i equal to zero 
						while (i < 6) // for every codon in the codon list of every protein 
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name)  // if the codon representing the protein is detected 
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count; // increment that protein count withe the codon count 
								}
							}
							i++; // increment i by one 
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl; // Print out 
																																					//The proteins with thier frequencies 
					}


				}
			}


		
		
#pragma omp section
			{
				int i;
				for (int j = 21/4; j < 21 / 2; j++) // for every on of the 21 Proteins
				{ 
					for (int k = 0; k < 64; k++) // for every on in the 64 Condons 
					{

						i = 0; // intialize i equal to zero 
						while (i < 6) // for every codon in the codon list of every protein 
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name) // if the codon representing the protein is detected 
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count;// increment that protein count withe the codon count 
								}
							}
							i++; // increment i by one 
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl; // Print out 
																																					//The proteins with thier frequencies 
					}


				}
			}




	#pragma omp section
			{
				int i;
       	for (int j = 21/2; j < (3*21) / 4; j++) // for every on of the 21 Proteins
				{ 
					for (int k = 0; k < 64; k++) // for every on in the 64 Condons 
					{

						i = 0; // intialize i equal to zero 
						while (i < 6) // for every codon in the codon list of every protein  
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name) // if the codon representing the protein is detected
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count;// increment that protein count withe the codon count 
								}
							}
							i++;  // increment i by one
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl; // Print out 
																																					//The proteins with thier frequencies 
					}


				}
			}


		
			
#pragma omp section
			{
				int i;
				for (int j = (3 * 21) / 4 ; j < 21 ; j++)// for every on of the 21 Proteins
				{
					for (int k = 0; k < 64; k++) // for every on in the 64 Condons 
					{

						i = 0;  // intialize i equal to zero 
						while (i < 6) // for every codon in the codon list of every protein 
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name) // if the codon representing the protein is detected

							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count; // increment that protein count withe the codon count 
								}
							}
							i++; // increment i by one
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;  // Print out 
																																					//The proteins with thier frequencies 
					}


				}
			}



		
		
		
		
		
		
		
		
		
		
		
		
		}
	
	
	}








}








/*
The ForParallel function takes in a string representing the file name and vector of codons and vector of proteins
The function use openmp for loop  parallelism technique to compute the proteins frequecny and count



*/







void ForParallel(string FILE , vector<codon> &CondonsVector , vector<protein>&ProteinsVector)
{

	int count; // create count variable
	count = getNumberOfLines(FILE); // intialize thte count with the number of lines in the given file
	const int line_count = count;// create a constant containing the number of lines in the given  file 
	vector<string> my_vector(line_count); // Intialize the String vector with the number of lines in the file
	get_lines(FILE, my_vector);// For each line in the file we put it without numbers and spaces in an element
								//of the vector string
	CondonsVector_Intialization(CondonsVector, true); // intialize condons vector , Enabling for loop parallelism 
	ProteinsVector_Intialization(ProteinsVector, true); // intialize protein vector , Enabling for loop parallelism 
	
	
	
	
	string temp; //create a temporary string 
	 int i, j, k; // create the variables i,j,k
	cout << "please wait making data is being analyzed ..........." << endl;

	
#pragma omp  parallel for private(j,k,temp)
	for (i = 0; i < (int)my_vector.size(); i++) // For every line in the String vector
	{
		 temp = "---";//create a temporary string with three dashes 
		 string cuurent_line;// Create variable current_line to place the current line of the string vector in it 
#pragma omp critical
		 {
			 int tid = omp_get_thread_num(); /// Create variable current_line to place the current line of the string vector in it 
			  cuurent_line = my_vector[i]; // place current  line from string vector  in the current line variable 
		 
		 }
		for (j = 0; j < (int)cuurent_line.size(); j += 3)// for every three characters in the current line
		{
			


#pragma omp critical
			{
				temp[0] = cuurent_line[j]; // for every three characters in the current line
				temp[1] = cuurent_line[(j)+1];  // put the  second letter in temp string
				temp[2] = cuurent_line[(j)+2]; // put the third letter in temp string
			}

			for (k = 0; k < (int)CondonsVector.size(); k++) // for every codon of the codons stored in codons vector 
			{
				if (temp == CondonsVector[k].name) // if the three letters represent  specific condon k 
				{
					
					#pragma omp critical
					{
						CondonsVector[k].count += 1;// increment condon k count by one 
					
					}
					}

			}



		}



		



	}



	cout << "Final Results  ..........." << endl;
	int Sum = 0; // INtialize sum to zero
#pragma omp  parallel for 
	 
	for ( k = 0; k < (int)CondonsVector.size(); k++) // for every condon in codon vector 
	{
		
		cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl; // Print out the codon and its count 
#pragma omp critical
		{
			Sum += CondonsVector[k].count;  // increment the count Sum with each codon count , in other words Sum variable will be equal to sum
										//of all condons appearnce
		}
	}


#pragma omp  parallel for  private (k , i)
	for ( j = 0; j < 21; j++)  // for every on of the 21 Proteins
	{
		for ( k = 0; k < 64; k++)  // for every on in the 64 Condons 
		{
			
			i = 0;  // intialize i equal to zero 
			while (i < 6) // for every codon in the codon list of every protein 
			{
				if (ProteinsVector[j].codon[i] == CondonsVector[k].name) // if the codon representing the protein is detected 
				{
#pragma omp critical
					{
						ProteinsVector[j].count += CondonsVector[k].count; // increment that protein count withe the codon count 
					}
				}
				i++;// increment i by one 
			}
		
		
		}
	
#pragma omp critical
		{
			cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;  // Print out 
																																					//The proteins with thier frequencies 
	
		}

	
	}


}









int main()
{
	double start;
	double end;
	int fileSize = 0;  // intiate file size to zero at first
	string FILE = "InputSeq.dat.txt"; // put file name to a string 
	vector<codon> CondonsVector(64); // create vector of type codon containing th 64 codon we have
	vector<protein> ProteinsVector(21); // create a vector of type protein containing the 21 protein that we have
	int num_of_the_threads = 0; // create variable  num_of_the_threads and itialize it to zero 
	double time_serial[4] = { 0 }; // create double array of 4 elements to map serial time 
	double time_for[4] = { 0 }; // create double array of 4 elements to map for-loop time 
	double time_sections[4] = { 0 }; // create double array of 4 elements to map Seection-parallelism  time 
	
	omp_set_dynamic(0);    // set dynamic to zero to enforce the number of threads wanted 
	
	for (int M = 1; M < 5; M++) { // make a for loop with four iternations one for 2,4,8,16 threads configurations 


		num_of_the_threads = (int)pow((double)2,(double)M); // put number of threads as 2 power M to get results 2,4,8,16 recpectilvly in the four iterations 
		omp_set_num_threads(num_of_the_threads); // set number of threads equal to num_of_the_threads
		cout << "----------------------------------------" << endl; 
		cout << "Executing " << num_of_the_threads << " Threads " << endl;
		start = omp_get_wtime(); // Count time from that point until the end point 
		ParallelSection(FILE, CondonsVector, ProteinsVector); // Run using sections parallelism 
		end = omp_get_wtime();//stop counting time 
		time_sections[M - 1] = end - start; // put time in sctions time array 
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		printf("Sections parallelism using %d threads  took %f seconds\n", num_of_the_threads,end - start); // print out the result 



		start = omp_get_wtime();  // Count time from that point until the end point 
		ForParallel(FILE, CondonsVector, ProteinsVector); //Run using for lopp parallelism
		end = omp_get_wtime(); //stop counting time 
		time_for[M - 1] = end - start;// put time in for-loop parallelism time array 
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		printf("For loop parallelism using %d threads  took %f seconds\n", num_of_the_threads, end - start); // print out the result 




		start = omp_get_wtime();  // Count time from that point until the end point 
		serialExecution(FILE, CondonsVector, ProteinsVector); // Run in series 
		end = omp_get_wtime();//stop counting time 
		time_serial[M - 1] = end - start; // put time in Serial time array 
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		cout << "----------------------------------------" << endl;
		printf("Serial Execution  using %d threads  took %f seconds\n", num_of_the_threads, end - start); // print out the result 






	}
	
	
	cout << "Time" << "      " << "Serial" << "      " << "For-Parallelism" << "      " << "Sections" << endl; 

	for (int R = 0; R < 4; R++)
	{
	
	
		cout << pow(2 , R+1 )<< "      " <<time_serial[R] << "      " << time_for[R] << "      " << time_sections[R] << endl; // print out the results from differnt methods to make 
																															// a table like shape to compare results 
	
	
	}














}

