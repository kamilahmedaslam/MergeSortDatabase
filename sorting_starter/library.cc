#include "library.h"

void mk_runs(string in_fp, string out_fp, long run_length, Schema *schema)
{
  // Your implementation
  	ifstream csv_file(in_fp);
    
    string line;
    int count = 1;
    while(getline(csv_file, line)){
        if(count % run_length == 0){
          
        }
    }


}

void merge_runs(RunIterator* iterators[], int num_runs, FILE *out_fp,
                long start_pos, char *buf, long buf_size)
{
  // Your implementation
}


