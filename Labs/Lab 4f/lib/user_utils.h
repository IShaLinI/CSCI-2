//Stuff related to users

#ifndef USER_UTILS_H
#define USER_UTILS_H

    using namespace std;

    #include <string>
    #include <map>
    #include <vector>

    //Uses a map to store users
    class UserDatabase{
        private:
            //The map of users to be accessed at runtime
            map<string, User> users;
            string databasePath = "data/database.txt";
        public:

            /**
             * Create an empty user database
            */
            UserDatabase();

            /**
             * Add a user to the database
             * @param user The user to add
            */
            void addUser(User user);

            /**
             * Remove a user from the database
             * 
             * Changes the username to "Deleted User #USERID", as to not break the message system
             * 
             * @param username The username of the user to remove
            */
            void removeUser(string username);

            /**
             * Get a user from the database
             * @param userID The id of the user to get
             * @return The user
            */
            User getUser(int userID);

            /**
             * Get a user from the database
             * @param username The username of the user to get
             * @return The user
            */
            User getUser(string username);

            /**
             * Check if a user exists in the database
             * @param username The username of the user to check
             * @return True if the user exists, false if not
            */
            bool userExists(string username);

            /**
             * Check if the login credentials were correct, and if so, log the user in
             * @param username The username of the user to log in
             * @param password The password of the user to log in
             * 
             * @return True if the login was successful, false if not
             */
            bool attempLogin(string username, string password);

            /**
             * Get a list of all users in the database in alphabetical order
             * @return A vector of all users
            */
            vector<User> getUserListAZ();

            /**
             * Save the database to a file
            */
            void saveDatabase();

            /**
             * Load the database from a file
            */
            void loadMessages();
    };

    class Message{
        private:
            int senderID; //The ID of the sender
            int recipientID; //The ID of the recipient
            string subject = "No Subject"; //The subject of the message
            string message = "No Message"; //The message
            time_t dateSent; //The timestamp of when the message was sent
        public:
            /**
             * Create a new message
             * @param sender The ID of the sender
             * @param recipient The ID of the recipient
             * @param message The message
             * @param subject The subject of the message
            */
            Message(string sender, string recipient, string subject, string message);

            /**
             * Get the sender of the message
             * @return The sender's user id
            */
            int getSender();

            /**
             * Get the recipient of the message
             * @return The recipient's user id
            */
            int getRecipient();

            /**
             * Get the subject of the message
             * @return The subject
            */
            string getSubject();

            /**
             * Get the message
             * @return The message
            */
            string getMessage();

            /**
             * Get the date the message was sent
             * @return The timestamp the message was sent
            */
            time_t getDateSent();

    };

    class User{
        private:
            int id; //Numerical ID of the user
            string username; //The username of the user
            string password; //The password of the user
            string email; //The email of the user
            time_t joinDate; //The date the user joined
            time_t lastLogin; //The date the user last logged in
            vector<Message> messages; //The messages the user has received
        public:
            User(string name, string password, string email, time_t joinDate); //For creating new users
            User(string name, string password, string email, time_t joinDate, time_t lastLogin, vector<Message> messages); //For loading existing users
            string getName(); //Get the name of the user
            string getPassword(); //Get the password of the user
            string getEmail(); //Get the email of the user
            time_t getJoinDate(); //Get the date the user joined
            time_t getLastLogin(); //Get the date the user last logged in
            vector<Message> getMessages(); //Get the messages the user has received
            void setName(string name); //Change the name of the user
    };

#endif