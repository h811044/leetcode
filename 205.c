// 205. Isomorphic Strings

bool isIsomorphic(char* s, char* t) {
    int indexMappingS[256] = {0};
    int indexMappingT[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (indexMappingS[s[i]] != indexMappingT[t[i]]) {
            return false;
        } else {
            if (indexMappingS[s[i]] == 0) {
                // i + 1 prevents confusing index 0 with default value 0 
                indexMappingS[s[i]] = i + 1;
                indexMappingT[t[i]] = i + 1;
            }
        }
    }
    return true;
}

/*
Line 5: Char 51: runtime error: load of null pointer of type 'char' [solution.c]
i:0
s:0x602000000010 "12"
t:0x0
indexMappingS:{0 <repeats 256 times>}
indexMappingT:{0 <repeats 256 times>}
*/
