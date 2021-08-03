void increment(int *x) { *x = *x + 1; }

int main() {
    int f = 10;
    increment(&f);
    return 0;
}