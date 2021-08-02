int strange(int *a, int b){
   int c = *a * b;
   *a = *a + b;
   return c; 
}


int main() {
    int x = 3;
    int y = 4;  
    int z = strange(&x, y);
    return 0;
}
