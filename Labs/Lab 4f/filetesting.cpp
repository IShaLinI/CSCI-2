#include <string>
#include <vector>
#include "lib\input_fields.h"

int main() {
    string templateFilePath = "menus/login.txt";
    vector<string> output;
    promptUser(templateFilePath, output);

    return 0;
}
