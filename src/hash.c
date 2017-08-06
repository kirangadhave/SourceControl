#include<openssl/sha.h>
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

// int main(int argc, char const *argv[]) {
//     if(argc!=2){
//         printf("Error in CL parameters. Please pass only the file name.\n");
//         return -1;
//     }
//
//     unsigned char* t = get_hash_from_file(argv[1]);
//
//     if(t==NULL){
//         printf("Error opening file.\n");
//         return -1;
//     }
//
//     int i;
//     char hash[40];
//     for(i=0; i<sizeof(t); i++){
//         sprintf(&hash[i*2], "%02x", t[i]);
//     }
//     printf("%s\n", hash);
//
//     return 0;
// }

unsigned char* get_hash_from_file(const char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp==NULL)
        return NULL;
    char* buffer = malloc(255);
    unsigned char* hash = malloc(40);

    SHA_CTX ctx;
    SHA1_Init(&ctx);

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        SHA1_Update(&ctx, buffer, sizeof(buffer));
    }

    SHA1_Final(hash, &ctx);

    free(buffer);
    return hash;
}

unsigned char* get_hash(const unsigned char* source){
    unsigned char* hash = malloc(20);
    char* new_source = malloc(sizeof(source)+2);
    new_source[0] = sizeof(source);

    SHA1(source, sizeof(source), hash);
    return hash;
}
