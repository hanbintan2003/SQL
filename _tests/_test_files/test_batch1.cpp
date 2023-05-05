#include "gtest/gtest.h"
#include <iomanip>
#include <iostream>

//------------------------------------------------------------------------------
// Files we are testing:
#include "../../includes/sql/sql.h"
//------------------------------------------------------------------------------

using namespace std;

bool sql_batch(bool debug = false){
    remove("employeeSample01.bin");
    remove("employeeSample01_fields.bin");
    remove("studentSample01.bin");
    remove("studentSample01_fields.bin");

    SQL sql;
    string s = "_!sample01.txt";
    sql.batch(s.c_str());

    remove("employeeSample01.bin");
    remove("employeeSample01_fields.bin");
    remove("studentSample01.bin");
    remove("studentSample01_fields.bin");
    return true;
}

// Lord help me!
const bool debug = false;

TEST(SQL_BASIC, SQLBatch){
    bool success = sql_batch(debug);
    EXPECT_EQ(success, true);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "\n\n----------running test_batch1.cpp---------\n\n"
              << std::endl;
    return RUN_ALL_TESTS();
}