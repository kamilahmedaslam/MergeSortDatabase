#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sys/timeb.h>

#include "leveldb/db.h"
#include "json/json.h"
#include <fstream>
#include "library.h"

using namespace std;


int main(int argc, const char* argv[]) {

	if (argc != 4) {
		cout << "ERROR: invalid input parameters!" << endl;
		cout << "Please enter <schema_file> <input_file> <out_index>" << endl;
		exit(1);
	}

	//get inputs
	string input_name = argv[1];
	string output_name = argv[2];
	vector <string> attributes;

    for(int i = 3 ; i < argc; i++){
        string curr = argv[i];
        attributes.push_back(curr);
    }


	//create database
	leveldb::DB *db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "./leveldb_dir", &db);


	//get schema here to find out the number of attributes;

	///...

	//we found out that we need to look at attributes... ex(first and third attributes in the list)

	ifstream input_file(input_name);

	long start = 0;
    long finish = 0;
    long time = 0;

    struct timeb timer;
    ftime(&timer);
    start = timer.time*1000 + timer.millitm;

	//write things to the tree
	string line;
	while(getline(input_file, line)){
		if(!line.empty()){
			if(status.ok()){
				//need to add custom comparator for bottom line to work
				// status = db->Put(leveldb::WriteOptions(), attributes, line);
			}
		}
	}

	ftime(&timer);
    finish = timer.time*1000 + timer.millitm;
    time = finish - start;
    fprintf(stdout, "\nTIME: %ld milliseconds\n", time);

	//now to iterate through each one and write it to file
	ofstream output_file(output_name);

	leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
	for (it->SeekToFirst(); it->Valid(); it->Next()) {
		cout << it->value().ToString() << endl;
	}



	
	return 0;
}


