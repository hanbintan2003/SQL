#include "gtest/gtest.h"
#include <iomanip>
#include <iostream>

//------------------------------------------------------------------------------
// Files we are testing:
#include "../../includes/sql/sql.h"
//------------------------------------------------------------------------------

using namespace std;

bool sql_batch(bool debug = false)
{
    remove("studentSelect02.bin");
    remove("studentSelect02_fields.bin");
    remove("employeeSample02.bin");
    remove("employeeSample02_fields.bin");
    SQL sql;
    string s = "_!sample02.txt";
    sql.batch(s.c_str());

    remove("studentSelect02.bin");
    remove("studentSelect02_fields.bin");
    remove("employeeSample02.bin");
    remove("employeeSample02_fields.bin");
    return true;
}

// Lord help me!
const bool debug = false;

TEST(SQL_BASIC, SQLBatch)
{
    bool success = sql_batch(debug);
    EXPECT_EQ(success, true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "\n\n----------running test_batch2.cpp---------\n\n"
              << std::endl;
    return RUN_ALL_TESTS();
}