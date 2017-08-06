#include<stdio.h>
#include "hash.h"

int main(){
    unsigned char* temp = get_hash_from_file("Hello.txt");
    int i;
    for(i=0;i<sizeof(temp);i++){
        printf("%02x", temp[i]);
    }
    printf("\n");
    return 0;
}
