'''
You should implement this script to generate test data for your
merge sort program.

The schema definition should be separate from the data generation
code. See example schema file `schema_example.json`.
'''
import sys
import csv
import random

def generate_data(schema, out_file, nrecords):
  '''
  Generate data according to the `schema` given,
  and write to `out_file`.
  `schema` is an list of dictionaries in the form of:
    [ 
      {
        'name' : <attribute_name>, 
        'length' : <fixed_length>,
        ...
      },
      ...
    ]
  `out_file` is the name of the output file.
  The output file must be in csv format, with a new line
  character at the end of every record.
  '''
  attrs = []
  alphanum = 'abcdefghijklmnopqrtsuvwxyz123456789'

  # Writing schema to csv out file
  f = open(out_file,'w')
  for i in schema:
    attrs.append(i['name'])
  f.write(','.join(attrs))
  f.write('\n')
  
  num = random.sample(range(100000000, 999999999), nrecords)
  print(num)
  name = [] 
  date = []
  cgpa = []
  for a in range(nrecords):
    name.append(''.join([random.choice(alphanum) for j in range(8)]))
    date.append(random.randint(1990, 2022))
    cgpa.append(round(random.uniform(1,4), 2))

  print(name)
  print(cgpa)

  for i in range(nrecords):
    f.write(str(num[i]) + ',' + str(name[i]) + ',' + str(date[i]) + ',' + str(cgpa[i]))
    f.write('\n')

  f.close()


  #print("Generating %d records", nrecords)

if __name__ == '__main__':
  import sys, json
  '''
  if not len(sys.argv) == 4:
    print("data_generator.py <schema json file> <output csv file> <# of records>")
    sys.exit(2)
  '''
  schema = json.load(open(sys.argv[1]))
  output = sys.argv[2]
  nrecords = int(sys.argv[3])
  #print(schema)
  
  generate_data(schema, output, nrecords)

