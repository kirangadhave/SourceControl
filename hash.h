#ifndef HASH_H
#define HASH_H

/*
    filename - Name of the file to be hashed.
    Return a string representing hash of contents of given files.
    Warning - The contents are prefixed with size and suffixed with null terminator before hashing.
*/
unsigned char* get_hash_from_file(const char* filename);

/*
    source - const unsigned char* which is to be hashed.
    Returns a char* representing hash of source.
    Warning - The contents are prefixed with size and suffixed with null terminator before hashing.
*/
unsigned char* get_hash(const unsigned char* source);

#endif
