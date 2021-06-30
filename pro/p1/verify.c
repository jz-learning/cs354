// James Zhang
// WISC NETID
// jzhang924
// WISC ID NUMBER
// SUBMISSION DATE (MADISON TIME ZONE)
// COMMENTS FOR THE GRADER (OPTIONAL)

#include <stdio.h>
#include <string.h>

#define USER_NAME_LENGTH 256
#define EMAIL_LENGTH 512
#define PASSWORD_LENGTH 256

void Get_User_Data(char *message, char *username, const int MAX_LENGTH);

/* add your function prototypes here */
int Is_Letter(char c);
int Is_Valid_Username(char *arr);
int Is_Good_Char(char c);
void Cleanup(char *arr);
int Is_Valid_Email(char *arr);
int Is_Valid_Pass(char *arr);
int Is_Upper(char c);
int Is_Lower(char c);
int Has_Lower(char *arr);
int Has_Upper(char *arr);
int Pass_Match(char *password_1, char *password_2);
void printarr(char *arr);
int Is_Top_Dom(char *TD);
int streql(char *str1, char *str2);

int main(void) {
    char username[USER_NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char password_1[PASSWORD_LENGTH];
    char password_2[PASSWORD_LENGTH];

    // ################################################
    // #####  VERIFY USERNAME  #####
    // ################################################
    Get_User_Data("Enter username: ", username, USER_NAME_LENGTH);
    Cleanup(username);

    // checks for good username
    if (!Is_Valid_Username(username)) return 0;

    // ################################################
    // #####  VERIFY EMAIL ADDRESS  #####
    // ################################################
    Get_User_Data("Enter email address: ", email, EMAIL_LENGTH);
    Cleanup(email);

    printf("Checking email......\n");

    if (!Is_Valid_Email(email)) return 0;

    printf("Email formatting is correct\n");

    // ################################################
    // #####  VERIFY PASSWORD  #####
    // ################################################
    Get_User_Data("Enter password: ", password_1, PASSWORD_LENGTH);
    Cleanup(password_1);
    if (!Is_Valid_Pass(password_1)) return 0;

    // check for entering the right password twice
    Get_User_Data("Confirm password: ", password_2, PASSWORD_LENGTH);
    Cleanup(password_2);
    
    if(!Pass_Match(password_1, password_2)) return 0;

    printf("Passwords match\n");
    return 0;
}

void Get_User_Data(char *message, char *data, const int MAX_LENGTH) {
    printf("%s", message);
    fgets(data, MAX_LENGTH, stdin);
    return;
}

/* add your function definitions here */

/**
 * returns 1 if: a-z, A-Z
 */
int Is_Letter(char c) {
    if (c >= 'A' && c <= 'Z')
        return 1;

    if (c >= 'a' && c <= 'z')
        return 1;

    return 0;
}

/**
 * returns 1 if: a-z, A-Z, 0-9, _
 **/
int Is_Good_Char(char c) {
    if (Is_Letter(c) || (c >= '0' && c <= '9') || (c == '_')) {
        return 1;
    }
    return 0;
}

int Is_Letter_Digit(char c) {
    if (Is_Letter(c) || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

int Is_Valid_Username(char *arr) {
    int len = 0;
    int sym = 0;
    char *p = arr;

    // loops through the username to get length and check for symbols
    while (*p) {
        // printf("%c \t %i\n", *p, *p);
        if (!Is_Good_Char(*p))
            sym = 1;
        len++;
        p++;
    }

    // if username has good starting letter
    if (!Is_Letter(*arr)) printf("Invalid username starting character\n");

    // if username is longer than 32 chars
    else if (len > 32)
        printf("Max 32 charcters\n");

    // if username has a symbol
    else if (sym)
        printf("Invalid character in username\n");

    // if passes all tests
    else {
        printf("Username formatting is correct\n");
        return (1);
    }
    return 0;
}

/**
 * Goes through each input array of chars and removes '\n' at the end
 **/
void Cleanup(char *arr) {
    while (*arr) {
        if (*arr == '\n') *arr = '\0';
        arr++;
    }
}

int Is_Valid_Email(char *arr) {
    int len = 0;
    char *head = arr;
    char *at = 0;
    char *dot = 0;
    char *end = 0;

    // check conditions
    int has_at = 0;

    // check first letter
    if (*arr == '@' || *arr == '.') {
        printf("Name missing\n");  // example @domain.com
        return 0;
    } else if (!Is_Letter(*arr)) {
        printf("Name must begin with letter\n");
        return 0;
    }

    // get pointer to each important stuff
    while (*arr) {
        // prints each char
        printf("%c\t %p\n", *arr, arr);

        // finds location of @
        if (*arr == '@') {
            at = arr;
            has_at = 1;
        }

        // finds location of first dot
        else if (*arr == '.' && !dot)
            dot = arr;

        // finds location of secont dot
        // if(*arr == '.' && )

        // length of domain
        //if (has_at)

        arr++;
    }
    // location of endstring
    end = arr++;

    printf("\n===========================================\n\n");

    printf("@ at: %p\n", at);
    printf("first . at: %p\n", dot);
    printf("ends at: %p\n", end);
    printf("size is: %d\n\n", end - head);

    // testing name lenth if there's no @
    if (!at && !dot && (end - head > 32)) {
        printf("Name must have fewer than 32 characters\n");
        return 0;
    } else if (!at && dot && (dot - head > 32)) {
        printf("Name must have fewer than 32 characters\n");
        return 0;
    }

    // test name length if there is @
    else if (at && at - head > 32) {
        printf("Name must have fewer than 32 characters\n");
        return 0;
    }

    // check if name valid
    char *temp = head;
    if (at) {
        while (*temp != '@') {
            if (!Is_Letter_Digit(*temp)) {
                printf("Invalid character in name\n");
                return 0;
            }
            temp++;
        }
    } else {
        printf("missing @\n");
        return 0;
    }

    // check if has domain
    if (*(at + 1) == '.') {
        printf("Domain missing\n");
        return 0;
    }

    if (end - at - 5 > 64) {
        printf("Maximum of 64 characters in domain\n");
        return 0;
    }

    // getting all of the dots/sudomains
    char *dot_loc[64];
    char *curr = head;
    int ct = 0;

    while (*curr) {
        if (*curr == '.') {
            dot_loc[ct] = curr;
            ct++;
        }
        curr++;
    }

    printf("Checks the one char right after each dot to be a letter\n");
    // Checks the one char right after each dot to be a letter
    for (int i = 0; i < ct; i++) {
        printf("%c \t %p\n", *dot_loc[i], dot_loc[i]);
        // incriments 1 from a dot position
        if (!Is_Letter(*(dot_loc[i] + 1)) || !Is_Letter(*(at + 1))) {
            printf("Domain or subdomain must begin with letter\n");
            return 0;
        }
    }


    printf("Subdomains all good\n");


    char *temp2 = head;
    while (*temp2) {
        if (temp2 > at && temp2 < end) {
            if (!(Is_Letter_Digit(*temp2) || '.')) {
                printf("Invalid character in domain, %c\n", *temp2);
                return 0;
            }
        }
        temp2++;
    }

    // check top level domain
    if (!Is_Top_Dom(end - 4))
        return 0;

    return 1;
}

int Is_Top_Dom(char *TD) {
    char net[] = ".net";
    char com[] = ".com";
    char edu[] = ".edu";

    if (streql(TD, net) || streql(TD, com) || streql(TD, edu))
        return 1;
    else {
        printf("Top level domain must be .edu, .com, or .net\n");
        return 0;
    }
}

int Is_Valid_Pass(char *arr) {
    int space = 0;
    int len = 0;
    char *p1 = arr;

    while (*arr) {
        // printf("%c \t %i\n", *p, *p);
        if (*arr == ' ')
            space = 1;
        len++;
        arr++;
    }

    if (space)
        printf("Password may not contain spaces\n");

    else if (len < 8)
        printf("Password must have at least 8 characters\n");

    else if (len > 16)
        printf("Password may have at most 16 character\n");

    else if (!Has_Upper(p1))
        printf("Password must contain at least one upper case character\n");

    else if (!Has_Lower(p1))
        printf("Password must contain at least one lower case character\n");

    else
        return 1;
    return 0;
}

int Pass_Match(char *pass1, char *pass2) {
    if (strcmp(pass1, pass2)){
        printf("Passwords do not match\n");
        return 0;
    }else
        return 1;
}

int Is_Upper(char c) {
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int Is_Lower(char c) {
    if (c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;
}

int Has_Lower(char *arr) {
    while (*arr) {
        if (Is_Lower(*arr)) return 1;
        arr++;
    }
    return 0;
}

int Has_Upper(char *arr) {
    while (*arr) {
        if (Is_Upper(*arr)) return 1;
        arr++;
    }
    return 0;
}

void printarr(char *arr) {
    printf("\n[");
    while (*arr) {
        printf("%c, ", *arr);
        arr++;
    }
    printf("]\n");
}

int streql(char *str1, char *str2) {
    return !strcmp(str1, str2);
}