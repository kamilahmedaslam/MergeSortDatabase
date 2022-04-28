#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ostream>
#include <string>
#include <json/json.h>
#include <json/value.h>
#include "jsoncpp.cpp"

using namespace std;

// 2 ints, 1 string, 1 double -> 2(4) + 1(8) + 8 = 24
int sizeofRec = 24;


class Student {
	public:
		int snum;
		string sname;
		int year;
		double gpa;
		
		Student() {
		}
};

bool ValueCmp(Student const& a, Student const& b) {
	return a.snum < b.snum;
}

Student students[101];
Student firstS[30];	
Student secondS[101-30];
Student sorted[101];

void readInputFile(string input) {
	ifstream file;

	file.open(input);
	
	string snum;
	string sname;
	string year;
	string gpa;

	int idx = 0;

	while (idx < 101) {
		getline(file, snum, ',');
		getline(file, sname, ',');
		getline(file, year, ',');
		getline(file, gpa, '\n');

		Student student;
		student.snum = stoi(snum);
		student.sname = sname;
		student.year = stoi(year);
		student.gpa = std::stod(gpa);

		students[idx] = student;

		idx += 1;
	}

	file.close();
}

void p1_firstRead(int memory) {
	
	for (int i = 0; i < memory; i++) {
		firstS[i] = students[i];
	}

	std::sort(firstS, firstS + memory, ValueCmp);

}

void p1_secondRead(int memory) {
	int idx = 0;

	for (int i = memory; i < 101; i++) {
		secondS[idx] = students[i];
		idx += 1;
	}

	std::sort(secondS, secondS + (101-memory), ValueCmp);
}

void p2_merge(Student a[], Student b[], int x, int y) {

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < x && j < y) {
		if (a[i].snum < b[j].snum) {
			sorted[k++] = a[i++];
		}
		else {
			sorted[k++] = b[j++];
		}
	}

	for (; i < x; i++) {
		sorted[k++] = a[i];
	}

	for (; j < y; j++) {
		sorted[k++] = b[j]; 
	}
}


void write2out(string out, Student a[]) {

	std::ofstream file;
	file.open(out, std::ios_base::app);

	for (int i = 0; i < 100; i++) {
		file << a[i].snum << "," << a[i].sname << "," << a[i].year << "," << a[i].gpa << std::endl;
	}
        
	file.close();
}



int main(int argc, const char* argv[]) {
	
/*	if (argc < 7) {
    		cout << "ERROR: invalid input parameters!" << endl;
    		cout << "Please enter <schema_file> <input_file> <output_file> <mem_capacity> <k> <sorting_attributes>" << endl;
    		exit(1);
  	}
  
*/

  	  
  	string schema_file(argv[1]);
  	int memory = std::stoi(argv[4]);
	string input = argv[2];
      	string output = argv[3];
	
	readInputFile(input);

	p1_firstRead(memory);
	p1_secondRead(memory);

	p2_merge(firstS, secondS, memory, 101-memory);

	write2out(output, sorted);

 	// Parse the schema JSON file
  	Json::Value schema;
  	Json::Reader json_reader;
  	// Support for std::string argument is added in C++11
  	// so you don't have to use .c_str() if you are on that.
  
  	ifstream schema_file_istream(schema_file.c_str(), ifstream::binary);
  	bool successful = json_reader.parse(schema_file_istream, schema, false);
  
	if (!successful) {
    		cout << "ERROR: " << json_reader.getFormatedErrorMessages() << endl;
    		exit(1);
	}



/*  	// Print out the schema
  	string attr_name;
  	int attr_len;
  	for (int i = 0; i < schema.size(); ++i) {
    		attr_name = schema[i].get("name", "UTF-8" ).asString();
    		attr_len = schema[i].get("length", "UTF-8").asInt();
    		cout << "{name : " << attr_name << ", length : " << attr_len << "}" << endl;
  	}
*/

  	return 0;
}
