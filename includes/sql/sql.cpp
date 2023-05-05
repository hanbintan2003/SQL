#include "sql.h"

// Constructor
SQL::SQL(){
    this->_table=Table();
    this->_parser=Parser();
}
// Process commands from a file
SQL::SQL(const char* file): SQL(){this->batch(file);}

// Process a command and return the result table
Table SQL::command(const string& cmd){

    this->_parser.set_string(cmd);
    MMap<string, string> parsed_tree = this->_parser.parse_tree();
    this->_ptree = parsed_tree;

    if (_ptree.empty())return _table;

    string table_name = parsed_tree["table_name"][0];
    string command = parsed_tree["command"][0];

    if (command == "create"){
        vector<string> fields = parsed_tree["fields"];
        _table = Table(table_name, fields);

    }else if (command == "insert"){
        _table = Table(table_name);
        _table.insert_into(parsed_tree["values"]);

    }else if (command == "select"){
      
        bool where_exists = parsed_tree.contains("where");
        // update for select *
        vector<string> selected_fields = parsed_tree["fields"];
        Table t = Table(table_name);
        if (selected_fields[0] == "*") selected_fields = t.get_fields();

        // basic select
        if (!where_exists){_table = t.select(selected_fields);
        }else{_table = t.select(selected_fields, parsed_tree["condition"]);}

    }
    return _table;

}


void SQL::batch(const char* file){
    ifstream f;
    string temp = file;
    string input_file_path = "../../batch/" + temp;

    f.open(input_file_path.c_str());

    if (f.fail()){
        cout << "No file named " << file << " exists." << endl;
        return;
    }

    cout << "------------------------------Batch Begins------------------------------" << endl;
    while (!f.eof()){
        string str;
        getline(f, str);

        if(str[0] != '/' && !str.empty()){
            cout << "command:" << str << endl;
            this->_table = this->command(str);

            cout << this->_table << endl;
            //this._table.print_lookup();
            cout << "records selected: " << select_recnos() << endl;
            cout << endl;
        }
    }

    f.close();
    cout << "------------------------------DONE------------------------------" << endl;

}