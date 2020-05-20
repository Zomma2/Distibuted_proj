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

struct protein
{
	string name;
	int count;
	string codon[6]; 


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
	ProteinsVector[6].codon[2] = "ccg";


	
	
	ProteinsVector[7].name = "Thr";
	ProteinsVector[7].codon[0] = "act";
	ProteinsVector[7].codon[1] = "acc";
	ProteinsVector[7].codon[2] = "aca";
	ProteinsVector[7].codon[2] = "acg";


	ProteinsVector[8].name = "Ala";
	ProteinsVector[8].codon[0] = "gct";
	ProteinsVector[8].codon[1] = "gcc";
	ProteinsVector[8].codon[2] = "gca";
	ProteinsVector[8].codon[2] = "gcg";






	
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
	








	ProteinsVector[19].name = "Gly";
	ProteinsVector[19].codon[0] = "ggt";
	ProteinsVector[19].codon[1] = "ggc";
	ProteinsVector[19].codon[2] = "gga";
	ProteinsVector[19].codon[3] = "ggg";



	if (!isForParallel)
	{

		for (int i = 0; i < 20; i++)
		{
			ProteinsVector[i].count = 0;

		}
	}


	else

	{
#pragma omp  parallel for 
		for (int i = 0; i < 20; i++)
		{
			ProteinsVector[i].count = 0;

		}


	
	}





}



















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










void printResults(vector<codon> &CondonsVector)
{
	 
	cout << "Final Results  ..........." << endl;

	for (unsigned int k = 0; k < CondonsVector.size(); k++)
	{
		cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;


	}

}








void serialExecution(string FILE, vector<codon> &CondonsVector, vector<protein>&ProteinsVector)
{



int count = getNumberOfLines(FILE);

cout << "There's "<<count << "Lines" << endl;
const int line_count = count ;

vector<string> my_vector(line_count);
get_lines(FILE , my_vector);



CondonsVector_Intialization(CondonsVector ,false);
ProteinsVector_Intialization(ProteinsVector, false);


string temp;
unsigned int i, j, k;
cout << "please wait making data is being analyzed ..........." << endl;



for (i = 0; i < my_vector.size(); i++)
{
	temp = "---";
	string cuurent_line;

	
		int tid = omp_get_thread_num();
		cuurent_line = my_vector[i];

	
	for (j = 0; j < cuurent_line.size(); j += 3)
	{




		
			temp[0] = cuurent_line[j];
			temp[1] = cuurent_line[(j)+1];
			temp[2] = cuurent_line[(j)+2];
		

		for (k = 0; k < CondonsVector.size(); k++)
		{
			if (temp == CondonsVector[k].name)
			{


					CondonsVector[k].count += 1;

				
			}

		}



	}







}



cout << "Final Results  ..........." << endl;
int Sum = 0;

for (unsigned int k = 0; k < CondonsVector.size(); k++)
{

	cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;
	Sum += CondonsVector[k].count;
	
}



for (int j = 0; j < 20; j++)
{
	for (int k = 0; k < 64; k++)
	{

		i = 0;
		while (i < 6)
		{
			if (ProteinsVector[j].codon[i] == CondonsVector[k].name)
			{

					ProteinsVector[j].count += CondonsVector[k].count;
				
			}
			i++;
		}


	}


		cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;
	


}





}

	




void TrySections(string FILE, vector<codon> &CondonsVector, vector<protein>&ProteinsVector)
{
	
	int count;
	
	
	
#pragma omp parallel 
	{
#pragma omp sections 
		{
# pragma omp section 
			{

				count = getNumberOfLines(FILE);
			}
		}
	}
			const int line_count = count;
			vector<string> my_vector(line_count);

#pragma omp parallel 
			{
#pragma omp sections 
				{
# pragma omp section 
			{

				get_lines(FILE, my_vector);

			}
	
		
#pragma omp section
			{


				CondonsVector_Intialization(CondonsVector ,false);

			}

#pragma omp section
			{

				ProteinsVector_Intialization(ProteinsVector , false);


			}

		
		
		
		
		}
	
	
	
	}
	cout << "please wait making data is being analyzed ..........." << endl;




#pragma omp parallel 
	{

#pragma omp sections 
		{

#pragma omp section
			{ unsigned int i, j, k;
				string temp = "---";
				for (i = 0; i < my_vector.size()/4; i++)
				{
					temp = "---";
					int tid = omp_get_thread_num();
					string cuurent_line = my_vector[i];
					cout << cuurent_line << " is catched by thread : " << tid << endl;

					for (j = 0; j < cuurent_line.size(); j += 3)
					{

						temp[0] = cuurent_line[j];
						temp[1] = cuurent_line[(j)+1];
						temp[2] = cuurent_line[(j)+2];
						for (k = 0; k < CondonsVector.size(); k++)
						{
							if (temp == CondonsVector[k].name)
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;

								}
							}

						}



					}

				}


			}
		
#pragma omp section
			{
				unsigned int i, j, k;
				for (i = my_vector.size() / 4; i < my_vector.size() / 2; i++)
				{
					
					string temp = "---";
					temp = "---";
					int tid = omp_get_thread_num();
					string cuurent_line = my_vector[i];
					cout << cuurent_line << " is catched by thread : " << tid << endl;

					for (j = 0; j < cuurent_line.size(); j += 3)
					{

						temp[0] = cuurent_line[j];
						temp[1] = cuurent_line[(j)+1];
						temp[2] = cuurent_line[(j)+2];
						for (k = 0; k < CondonsVector.size(); k++)
						{
							if (temp == CondonsVector[k].name)
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;

								}
							}

						}



					}

				}


			}
		
		

#pragma omp section
			{
				unsigned int i, j, k;
				for (i = my_vector.size() / 2; i < (3*my_vector.size()) / 4; i++)
				{
				
					string temp = "---";
					temp = "---";
					int tid = omp_get_thread_num();
					string cuurent_line = my_vector[i];
					cout << cuurent_line << " is catched by thread : " << tid << endl;

					for (j = 0; j < cuurent_line.size(); j += 3)
					{

						temp[0] = cuurent_line[j];
						temp[1] = cuurent_line[(j)+1];
						temp[2] = cuurent_line[(j)+2];
						for (k = 0; k < CondonsVector.size(); k++)
						{
							if (temp == CondonsVector[k].name)
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;

								}
							}

						}



					}

				}


			}
		
#pragma omp section
			{
				unsigned int i, j, k;
				for (i = (3 * my_vector.size()) / 4 ; i <  my_vector.size() / 4; i++)
				{	
					string temp = "---";
					temp = "---";
					int tid = omp_get_thread_num();
					string cuurent_line = my_vector[i];
					cout << cuurent_line << " is catched by thread : " << tid << endl;

					for (j = 0; j < cuurent_line.size(); j += 3)
					{

						temp[0] = cuurent_line[j];
						temp[1] = cuurent_line[(j)+1];
						temp[2] = cuurent_line[(j)+2];
						for (k = 0; k < CondonsVector.size(); k++)
						{
							if (temp == CondonsVector[k].name)
							{

#pragma omp critical
								{
									CondonsVector[k].count += 1;

								}
							}

						}



					}

				}


			}
		
		
		
		
		}



	}




	cout << "Final Results  ..........." << endl;
	int Sum = 0;
	for (unsigned int k = 0; k < CondonsVector.size(); k++)
	{

		cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;
		Sum += CondonsVector[k].count;

	}





#pragma omp parallel 
	{

#pragma omp sections 
		{

#pragma omp section
			{
				int i;
       	for (int j = 0; j < 20 / 4; j++)
				{
					for (int k = 0; k < 64; k++)
					{

						i = 0;
						while (i < 6)
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name)
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count;
								}
							}
							i++;
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;
					}


				}
			}


		
		
#pragma omp section
			{
				int i;
				for (int j = 20/4; j < 20 / 2; j++)
				{
					for (int k = 0; k < 64; k++)
					{

						i = 0;
						while (i < 6)
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name)
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count;
								}
							}
							i++;
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;
					}


				}
			}




	#pragma omp section
			{
				int i;
       	for (int j = 20/2; j < (3*20) / 4; j++)
				{
					for (int k = 0; k < 64; k++)
					{

						i = 0;
						while (i < 6)
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name)
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count;
								}
							}
							i++;
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;
					}


				}
			}


		
			
#pragma omp section
			{
				int i;
				for (int j = (3 * 20) / 4 ; j < 20 ; j++)
				{
					for (int k = 0; k < 64; k++)
					{

						i = 0;
						while (i < 6)
						{
							if (ProteinsVector[j].codon[i] == CondonsVector[k].name)
							{
#pragma omp critical
								{
									ProteinsVector[j].count += CondonsVector[k].count;
								}
							}
							i++;
						}


					}









#pragma omp critical
					{
						cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;
					}


				}
			}



		
		
		
		
		
		
		
		
		
		
		
		
		}
	
	
	}








}















void OpenMPParallelExecutionSections(string FILE , vector<codon> &CondonsVector , vector<protein>&ProteinsVector)
{

	int count;
	count = getNumberOfLines(FILE);
	const int line_count = count;
	vector<string> my_vector(line_count);
	get_lines(FILE, my_vector);
	CondonsVector_Intialization(CondonsVector, true);
	ProteinsVector_Intialization(ProteinsVector, true);
	
	
	
	
	string temp;
	 int i, j, k;
	cout << "please wait making data is being analyzed ..........." << endl;

	
#pragma omp  parallel for private(j,k,temp)
	for (i = 0; i < (int)my_vector.size(); i++)
	{
		 temp = "---";
		 string cuurent_line;
#pragma omp critical
		 {
			 int tid = omp_get_thread_num();
			  cuurent_line = my_vector[i];
		 
		 }
		for (j = 0; j < (int)cuurent_line.size(); j += 3)
		{
			


#pragma omp critical
			{
				temp[0] = cuurent_line[j];
				temp[1] = cuurent_line[(j)+1];
				temp[2] = cuurent_line[(j)+2];
			}

			for (k = 0; k < (int)CondonsVector.size(); k++)
			{
				if (temp == CondonsVector[k].name)
				{
					
					#pragma omp critical
					{
						CondonsVector[k].count += 1;
					
					}
					}

			}



		}



		



	}



	cout << "Final Results  ..........." << endl;
	int Sum = 0;
#pragma omp  parallel for 

	for ( k = 0; k < (int)CondonsVector.size(); k++)
	{
		
		cout << CondonsVector[k].name << " |" << " count :" << CondonsVector[k].count << endl;
#pragma omp critical
		{
			Sum += CondonsVector[k].count;
		}
	}


#pragma omp  parallel for  private (k , i)
	for ( j = 0; j < 20; j++)
	{
		for ( k = 0; k < 64; k++)
		{
			
			i = 0;
			while (i < 6)
			{
				if (ProteinsVector[j].codon[i] == CondonsVector[k].name)
				{
#pragma omp critical
					{
						ProteinsVector[j].count += CondonsVector[k].count;
					}
				}
				i++;
			}
		
		
		}
	
#pragma omp critical
		{
			cout << ProteinsVector[j].name << " |" << " count :" << ProteinsVector[j].count << " | Frequency : " << float(ProteinsVector[j].count) / float(Sum) * 100 << endl;
		}

	
	}







}









int main()
{
	int fileSize = 0; 
	string FILE = "InputSeq.dat.txt";
	vector<codon> CondonsVector(64);
	vector<protein> ProteinsVector(20);
	
	
	
	TrySections(FILE, CondonsVector, ProteinsVector);

	OpenMPParallelExecutionSections(FILE, CondonsVector, ProteinsVector);
	
	serialExecution(FILE, CondonsVector, ProteinsVector);
	
	
	
	





}

