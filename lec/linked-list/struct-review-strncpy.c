#include <stdio.h>
#include <string.h>

struct address {
    char street[100];
    char state[3];
    int zip;
};

struct person {
    char name[100];
    int id;
    struct address addr;
};

int main(int argc, char const *argv[]) {
    struct person p1;
    p1.id = 123456;
    p1.addr.zip = 54321;

    // Assign strings to our struct
    strncpy(p1.name, "James", sizeof(p1.name));
    strncpy(p1.addr.street, "Main St.", sizeof(p1.addr.street));
    strncpy(p1.addr.state, "NY", sizeof(p1.addr.state));

    // Print the contents of the struct
    printf("Person: %s\nID: %i\n\nAddress\nStreet: %s\nState: %s\nZip: %i\n\n", p1.name, p1.id,
           p1.addr.street, p1.addr.state, p1.addr.zip);

    // Get the address of the struct
    struct person *pp = &p1;
    pp->id = 789;

    printf("Person: %s\nID: %i\n\nAddress\nStreet: %s\nState: %s\nZip: %i\n\n", p1.name, p1.id,
           p1.addr.street, p1.addr.state, p1.addr.zip);

    return 0;
}
