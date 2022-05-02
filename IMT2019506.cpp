#include "IMT2019506.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

//Constructor
IMT2019506::IMT2019506(string input, string output)
{
	this->input_file = input;
	this->output_file = output;
	this->input();
	this->run();
	this->output();
}

//Destructor
IMT2019506::~IMT2019506(){}

//A function which decides whether to take a character for the word count or not
bool IMT2019506::toTake(char ch)
{
	if(ch>='A' && ch<='Z') return true;
	else if(ch>='a' && ch<='z') return true;
	else if(ch>='0' && ch<='9') return true;
	else return false;
}

//Taking the input file
void IMT2019506::input()
{
	fin.open(this->input_file);
	if(!fin)
	{
		cout<<"The requested file could not be opened."<<endl;
	}
}

//Peforming the task
void IMT2019506::run()
{
	string line;
	vector<string> inputLines;
	while(getline(fin,line))
	{
		inputLines.push_back(line);
		this->lines = this->lines+1;;
	}

	vector<string>::iterator ptr;
	for(ptr = inputLines.begin(); ptr < inputLines.end(); ++ptr)
	{
		line = *ptr;
		
		line = line + '\n';
		this->bytes = this->bytes + line.length();
		int k=0;
		while(k < line.length()-1)
		{
			if(toTake(line[k]) && !toTake(line[k+1]))
			{
				this->words = this->words + 1;
			}
			if(line[k]==' ') this->spaces = this->spaces + 1;
			k++;
		}
	}
	this->bytes = this->bytes - 2;
	this->characters = this->bytes;
	this->charactersNoSpaces = this->bytes + 2 - this->spaces - 2*this->lines;
	fin.close();
}

//Generating the output .txt file with the document statistics as header and the text as the body of the output file
void IMT2019506::output()
{
	string line;
	fout.open(this->output_file);
	if(!fout)
	{
		cout<<"Unable to create the output file."<<endl;
	}

	fin.open(this->input_file);

	fout<<"DOCUMENT STATISTICS:"<<"\n";
	fout<<"Lines                  :"<<this->lines<<"\n";
	fout<<"Words                  :"<<this->words<<"\n";
	fout<<"Characters(with spaces):"<<this->characters<<"\n";
	fout<<"Characters(no spaces)  :"<<this->charactersNoSpaces<<"\n";
	fout<<"Bytes                  :"<<this->bytes<<"\n\n";
	while(getline(fin,line))
	{
		line = line + "\n";
		fout<<line;
	}
	fin.close();
	fout.close();
}
