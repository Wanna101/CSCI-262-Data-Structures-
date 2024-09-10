#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "personality_test.h"

using namespace std;

void load_file(personality_test&);

/* main
 * Calls necessary functions in this file as well as functions in personality_test
 * @param None
 * @return None, Text to Console
 */
int main () {
    cout << "====================================" << endl;
    cout << "Welcome to CSCI262 Personality Test!" << endl;
    cout << "====================================" << endl << endl;

    personality_test test;

    // Uncomment the below methods as you complete them
    load_file(test);
    //test.printout();
    //test.run_test();

}

/* Load File Method
 * 1) Prompt the user for a file name. 
 * 2) Confirm that the file can be loaded
 * 3) Run personality_test::load to load in the data
 * 4) If personality_test::load fails, report this and retry
 * @param personality_test object (by reference)
 * @return None, Text to Console
 */
void load_file(personality_test& test) {
    while (true) {
        string fileName;
        cout << "Please enter the input file name, e.g., \"questions.txt\": ";
        break;
        //TODO
    }
}
