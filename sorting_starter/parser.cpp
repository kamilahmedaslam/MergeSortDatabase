#include <iostream>
#include <string>
#include <fstream>
#include <json/json.h>
#include <json/value.h>
#include "jsoncpp.cpp"

using namespace std;

int main() {

    ifstream file("schema_example.json");

    Json::Reader reader;
    Json::Value actual;

    reader.parse(file, actual);

    cout << "Data: \n" << actual << endl; 
}