#include "utility.h"

#include <iostream>
//simple hash function to store password
//improve later by salting hash and etc...
string Hash(string value) {
    char result[value.length()];
    for (long unsigned int i = 0; i < value.length(); i++) {
        result[i] = value[i] >> 1;
    }
    //cout << "Given: " << value << " Result: " <<result <<endl;
    return string(result);
}