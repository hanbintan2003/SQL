#ifndef FILE_RECORD_H
#define FILE_RECORD_H

#include <iostream>  // cout, endl
#include <iomanip>   // setw, right
#include <fstream>   // fstream
#include <cstring>   // strncpy
#include <vector>    // vector
#include <memory>    // unique_ptr

using namespace std;

class FileRecord{
public:
    // When construct a FileRecord, it's either empty or it contains a word
    FileRecord(){}
    FileRecord(string s);
    FileRecord(char str[]);
    FileRecord(vector<string> v);

    long write(fstream& outs);
    long read(fstream& ins, long recno);
    vector<char*> get_records();
    vector<string> get_records_string(){ return this->_records;}

    int column_size() { return this->_records.size(); }
    // Overload the << operator to print a FileRecord
    void resize(int size) { this->_records.resize(size); }

    friend ostream& operator << (ostream& outs, const FileRecord& r) {
        int i = 0;
        while (r._records[i][0] != '\0')
        {
            outs << setw(MAX / 4) << right << r._records[i];
            i++;
        }
        return outs;
        // return outs << setw(MAX / 4) << right << r._records[0] << setw(MAX / 4) << right << r._records[1] << setw(MAX / 4) << right << r._records[2];
    }

private:
    // The maximum size of the record
    static const int MAX = 100;
    // The record vector
    vector<string> _records;

};

#endif
