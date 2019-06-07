#include "vdb.hh"
#include <iostream>
#include <cstring>

using namespace std;
using namespace dbms2;

int main(int argc, char* argv[])
{
        VectorDbTable *db = new VectorDbTable();
        if(!db->loadCSV("default.csv")) {
                cout << "Error on reading CSV" << endl;
                delete db;
                return -1;// return if anything wrong
        }
        if(argc == 1) {
                cout << "No arguments" << endl;
                delete db;
                return 0;
        }
        char *firArg = argv[1];// get the first argument
        //check the argument if it is show()
        if(!strcmp(firArg, "showall")) {
                int i = 0;
                while(db->show(i++)){}//show from the first line
        }
        else if (!strcmp(firArg, "show")) {
                        try {
                                int secondArg = stoi(argv[2]);//convert the string into an integer
                                bool showing = db->show(secondArg);
                                if(!showing){
                                        cout << "Error Occurs to show the table" << endl;}
                        } catch (invalid_argument) {

                        }

        }

        else {
                cout << "Invalid argument" << endl;
        }

        delete db;
}
