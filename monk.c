#include <stdio.h>

int main(){
    int i = 1;
    //int j = 1;
    for ( int j = 1; j < 10; j++)
    {
        i++;
        i= 2 * i;
    }
    printf("The monkey picked %d peaches.", i);

}
