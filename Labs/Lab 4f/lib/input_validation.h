//Stuff related to input validation

#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

    using namespace std;

    #include <string>

    /**
     * Validate an email address
     * @param email The email address to validate
     * @return True if the email is valid, false if not
    */
    bool validateEmail(string email);

    /**
     * Validate a password
     * @param password The password to validate
     * @return True if the password is valid, false if not
    */
    bool validatePassword(string password);

#endif