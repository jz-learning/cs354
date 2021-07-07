#include <stdio.h>

struct STUDENT {
    char *name;
    int id;
};

void Print_Struct_Pointer(struct STUDENT *s);
void Print_Struct(struct STUDENT s);

int main(int argc, char const *argv[]) {
    struct STUDENT sd;
    sd.name = "James";
    sd.id = 123456;

    printf("Struct at: %p\n", &sd);
    printf("Name is: %s, at: %p\n", sd.name, &sd.name);
    printf("ID is: %d, at: %p\n", sd.id, &sd.id);
    printf("String at: %p\n\n", sd.name);

    Print_Struct(sd);
    Print_Struct_Pointer(&sd);

    return 0;
}

void Print_Struct(struct STUDENT s){
    printf("Struct at: %p\n", &s);
    printf("Name is: %s, at: %p\n", s.name, &s.name);
    printf("ID is: %d, at: %p\n", s.id, &s.id);
	printf("String at: %p\n\n", s.name);
}

void Print_Struct_Pointer(struct STUDENT *s){
    printf("Struct at: %p\n", &s);
    printf("Name is: %s, at: %p\n", s->name, &s->name);
    printf("ID is: %d, at: %p\n", s->id, &s->id);
    printf("String at: %p\n\n", s->name);
}