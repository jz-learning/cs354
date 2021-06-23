// James Zhang
// WISC NETID
// jzhang924
// WISC ID NUMBER
// SUBMISSION DATE (MADISON TIME ZONE)
// COMMENTS FOR THE GRADER (OPTIONAL)

#include <stdio.h>

#define USER_NAME_LENGTH 256
#define EMAIL_LENGTH 512
#define PASSWORD_LENGTH 256

void Get_User_Data(char *message, char *username, const int MAX_LENGTH);
/* add your function prototypes here */
int Is_Letter(char c);


int main(void) {
    char username[USER_NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char password_1[PASSWORD_LENGTH];
    char password_2[PASSWORD_LENGTH];

    // ################################################
    // #####  VERIFY USERNAME  #####
    // ################################################
    Get_User_Data("Enter username: ", username, USER_NAME_LENGTH);
    // username must begin with letter [A-Z, a-z]
    /* Add your code here */
    if (!Is_Letter(username[0])) {
        printf("Invalid username starting character\n");
    }

    // max 32 charcters
    /* Add your code here */
    printf("Max 32 charcters\n");

    // may contain only letters, underscore, or digits [A-Z, a-z, _, 0-9]
    /* Add your code here */
    printf("Invalid character in username\n");

    printf("Username formatting is correct\n");

    // ################################################
    // #####  VERIFY EMAIL ADDRESS  #####
    // ################################################
    Get_User_Data("Enter email address: ", email, EMAIL_LENGTH);
    printf("The username is: %s\n", &username[0]);
    // email address have 4 parts in this order
    // name
    // max 32 characters
    // must start with letter
    // may contain [letters or digits]
    // @ symbol
    // domain name
    // max of 64 characters
    // consists of a domain name and subdomains separated by .
    // each domain or subdomain  must begin with a letter
    // domain and subdomains may contain only [letters, digits]
    // top-level domain
    // must be [.edu, .com, .net]

    // Error messages
    // name
    printf("Name missing\n");  // example @domain.com
    printf("Name must begin with letter\n");
    printf("Name must have fewer than 32 characters\n");
    printf("Invalid character in name\n");
    // @ symbol
    printf("missing @\n");
    // domain name
    printf("Domain missing\n");  // example mike@.edu
    printf("Maximum of 64 characters in domain\n");
    printf("Domain or subdomain must begin with letter\n");
    printf("Invalid character in domain\n");
    // top level domain
    printf("Top level domain must be .edu, .com, or .net\n");

    printf("Email formatting is correct\n");
    // ################################################
    // #####  VERIFY PASSWORD  #####
    // ################################################
    Get_User_Data("Enter password: ", password_1, PASSWORD_LENGTH);
    Get_User_Data("Confirm password: ", password_2, PASSWORD_LENGTH);
    // May use any character except spaces // example "my password" is invalid
    // passwords must contain at least 8 characters // example "Password" has 8 characters and is valid
    // passwords have at most 16 characters // example "1234567890Abcdef" has 16 characters and is valid
    // Must contain at least one upper case character [A-Z]
    // Must contain at least one lower case character [a-z]
    // Original Password and the Reentered Password must match

    // Error messages
    printf("Password may not contain spaces\n");
    printf("Password must have at least 8 characters\n");
    printf("Password may have at most 16 character\n");
    printf("Password must contain at least one upper case character\n");
    printf("Password must contain at least one lower case character\n");
    printf("Passwords do not match\n");

	// Checking two passwords
	if (password_1 != password_2)
	    printf("Passwords match\n");


	return 0;
}

void Get_User_Data(char *message, char *data, const int MAX_LENGTH) {
    printf("%s", message);
    fgets(data, MAX_LENGTH, stdin);
    return;
}

/* add your function definitions here */
int Is_Letter(char c) {
    if (c >= 'A' && c <= 'Z')
        return 1;

    if (c >= 'a' && c <= 'z')
        return 1;

    return 0;
}
