struct POINT {
    int x;
    int y;
    char name[12];
    char symbol;
};

int main() {
    /*
//* Version 1
struct POINT p0 = (0, 0, "origin", '*');

//* Version 2
struct POINT p0;
p0.x = 0;
p0.y = 0;
char *s1 = "origin";
char *s2 = p0.name;
while (*s2++ = *s1++)
    ;
p0.symbol = '*';
    */

    //* Version3
    struct POINT p0;
    p0.x = 0;
    p0.y = 0;
    p0.name[0] = 'o';
    p0.name[1] = 'r';
    p0.name[2] = 'i';
    p0.name[3] = 'g';
    p0.name[4] = 'i';
    p0.name[5] = 'n';
    p0.name[6] = '\0';
    p0.symbol = '*';

    return 0;
}


-32	: 
-28	: 	
-24	: 0		
-20	: 0
-16	: 'o'
-15	: 'r'
-14	: 'i'
-13	: 'g'
-12	: 'i'
-11	: 'n'
-10	: '\0'
-8	:
-4	: '*'


