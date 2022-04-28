#include <cstdio>
#include <string>

using namespace std;

/**
 * An attribute schema. You should probably modify
 * this to add your own fields.
 */
typedef struct {
  char *name;
  int length;
} Attribute;

/**
 * A record schema contains an array of attribute
 * schema `attrs`, as well as an array of sort-by 
 * attributes (represented as the indices of the 
 * `attrs` array).
 */
typedef struct {
  int nattrs;
  int n_sort_attrs;
  Attribute* attrs[4];
  int sort_attrs[];
} Schema;

/**
 * A record can defined as a struct with a pointer
 * to the schema and some data. 
 */
typedef struct {
  Schema* schema;
  char* data;
} Record;

/**
 * Creates sorted runs of length `run_length` in
 * the `out_fp`.
 */
void mk_runs(string in_fp, string out_fp, long run_length, Schema *schema);


/**
 * Merge runs given by the `iterators`.
 * The number of `iterators` should be equal to the `num_runs`.
 * Write the merged runs to `out_fp` starting at position `start_pos`.
 * Cannot use more than `buf_size` of heap memory allocated to `buf`.
 */
void merge_runs(int num_runs, FILE *out_fp,
                long start_pos, char *buf, long buf_size);


