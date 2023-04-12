#include "input_fields.h"
#include <iostream>
#include <fstream>

void promptUser(string templateFilePath, vector<string>* output) {
    // Open the template file for reading
    ifstream templateFile(templateFilePath);
    if (!templateFile) {
        cerr << "Error: Could not open template file '" << templateFilePath << "'." << endl;
        return;
    }

    bool linemodified = false;

    // Read the template file line by line
    string line;
    while (getline(templateFile, line)) {

        linemodified = false;

        // Search for placeholder strings in the line and replace them with user input
        size_t pos = line.find("{{");
        while (pos != string::npos) {
            size_t endPos = line.find("}}", pos);
            if (endPos != string::npos) {
                // Extract the placeholder name and prompt the user for input
                string placeholder = line.substr(pos + 2, endPos - pos - 2);
                cout << placeholder << ": ";
                string userInput;
                getline(cin, userInput);

                //Push the user input into the output vector
                output->push_back(userInput);

                linemodified = true;
                
            } else {
                break;  // Placeholder end not found, stop searching
            }
            pos = line.find("{{", endPos);
        }

        // Output the unmodified line
        if(!linemodified){cout << line << endl;}
    }

    // Close the template file
    templateFile.close();

}
