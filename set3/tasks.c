#include "tasks.h"

// Counts the number of times pattern occurs in string
// Example: count("aybabtu", "bab") -> 1
// Example: count("aaaaaa", "aa") -> 5
int count(char *string, char *pattern) {
    int count = 0;

    // for (int j = 0; string[j]; j++) {
    //     count++;
    //     for (int i = 0; pattern[i]; i++) {
    //         if (pattern[i] != string[j + i]) {
    //             count--;
    //             break;
    //         }
    //     }
    // }

    int n = strlen(pattern);

    for (int i = 0; string[i]; i++) {
        if (strncmp(&string[i], pattern, n) == 0) {
            count++;
        }
    }

    return count;
}

// Checks if string starts with prefix
// Example: starts_with("aybabtu", "ayb") -> 1
// Example: starts_with("aybabtu", "lol") -> 0
int starts_with(char *string, char *prefix) {
    int n = strlen(prefix);

    if (strncmp(string, prefix, n) == 0) {
        return 1;
    }

    // for (int i = 0; prefix[i]; i++) {
    //     if (prefix[i] != string[i]) {
    //         return 0;
    //     }
    // }

    return 0;
}

// Checks if string ends with suffix
// Example: ends_with("aybabtu", "btu") -> 1
// Example: ends_with("aybabtu", "lol") -> 0
int ends_with(char *string, char *suffix) {
    int n = strlen(suffix);
    int m = strlen(string);

    if (n > m) return 0;
    
    if (strncmp(&string[m - n], suffix, n) == 0) {
        return 1;
    }

    return 0;
}

// Concatenates the strings in the array into a single string
// Example: {"apina", "banaani", "cembalo"} -> "apinabanaanicembalo"
char* concat(char **array, int n) {
    int size = 0;

    for (int i = 0; i < n; i++) {
        size += strlen(array[i]);
    }

    size += 1;
    
    char *res = malloc(size);

    res[0] = '\0';

    for (int i = 0; i < n; i++) {
        strncat(res, array[i], strlen(array[i]));
    }

    return res;
}

// Returns the first position where pattern occurs in string
//   - If pattern doesn't occur in string, return -1
// Example: find("aybabtu", "bab") -> 2
// Example: find("aybabtu", "lol") -> -1
int find(char *string, char *pattern) {
    int pat_len = strlen(pattern);

    for (int i = 0; string[i]; i++) {
        if (strncmp(&string[i], pattern, pat_len) == 0) return i;
    }

    return -1;
}

// Creates a string that repeats pattern n times
// Example: repeat("abc", 4) -> "abcabcabcabc"
char* repeat(char *pattern, int n) {
    int pat_len = strlen(pattern);
    char* res = malloc(pat_len * n + 1);

    res[0] = '\0';

    for (int i = 0; i < n; i++) {
        strncat(res, pattern, pat_len);
    }

    return res;
}

// Removes spaces around the string
// Example: trim(" aybabtu   ") -> "aybabtu"
char* trim(char *string) {
    int len = strlen(string);
    int first = -1;
    int last = -1;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ' ') {
            first = i;
            break;
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        if (string[i] != ' ') {
            last = i;
            break;
        }
    }

    
    char* res = malloc((last - first) + 2);
    
    if (first == -1) {
        res[0] = '\0';
        return res;
    }

    strncpy(res, &string[first], 1 + last - first);

    res[1 + last - first] = '\0';

    return res;
}

// Replaces characters a-z with A-Z in string
// Example: upper("aybabtu") -> "AYBABTU"
// Example: upper("AyBaBtU") -> "AYBABTU"
char* upper(char *string) {
    char* res = malloc(strlen(string) + 1);
    
    res[strlen(string)] = '\0';

    for (int i = 0; string[i]; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') 
            res[i] = string[i] - 32;
        else 
            res[i] = string[i];
    }

    return res;
}

// Replaces characters A-Z with a-z in string
// Example: upper("AYBABTU") -> "aybabtu"
// Example: upper("AyBaBtU") -> "aybabtu"
char* lower(char *string) {
    char* res = malloc(strlen(string) + 1);
    
    res[strlen(string)] = '\0';

    for (int i = 0; string[i]; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') 
            res[i] = string[i] + 32;
        else 
            res[i] = string[i];
    }

    return res;
}

// Returns a substring from the string
//   - Stop if the position goes past the end of the string
// Example: substr("aybabtu", 2, 3) -> "bab"
// Example: substr("aybabtu", 10, 3) -> ""
// Example: substr("aybabtu", 2, 10) -> "babtu"
char* substr(char *string, int start, int length) {
    char* res;
    int len = strlen(string);

    if (start + 1 > len) {
        res = malloc(1);
        res[0] = '\0';
        return res;    
    }
    
    int last_index = start + length;

    int cpy_len = last_index + 1 > len
        ? len - start
        : length;
    
    res = malloc(length + 1);
    res[cpy_len] = '\0';

    strncpy(res, &string[start], cpy_len);

    return res;
}

// Replaces all occurrences of old with new in string
//   - Don't replace an already replaced character
// Example: replace("aybabtu", "bab", "lol") -> "ayloltu"
// Example: replace("aa", "a", "aa") -> "aaaa"
char* replace(char *string, char *old, char *new) {
    int len = strlen(string);
    int old_len = strlen(old);
    int new_len = strlen(new);

    char* temp_str = malloc(len * new_len + 1);
    
    int i = 0;
    int j = 0;

    while (i <= len) {
        if (strncmp(&string[i], old, old_len) == 0) {
            strncpy(&temp_str[j], new, new_len);
            i += old_len;
            j += new_len;
        } else {
            temp_str[j] = string[i];
            i++;
            j++;
        }
    }

    char* res = malloc(j);

    strncpy(res, temp_str, j);

    free(temp_str);

    return res;
}

// Applies ROT13 transformation to string
//   - Rotate each letter (a-z and A-Z) 13 steps
//   - More information: https://en.wikipedia.org/wiki/ROT13
// Example: rot13("aybabtu") -> "nlonogh"

char* rot13(char *string) {
    const int CHARS = 'z' - 'a' + 1;
    
    int len = strlen(string);
    
    char* res = malloc(len + 1);

    for (int i = 0; i <= len; i++) {
        char c = string[i];

        if ('a' <= c && c <= 'z')
            res[i] = (c + 13 - 'a') % CHARS + 'a';
        else if ('A' <= c && c <= 'Z')
            res[i] = (c + 13 - 'A') % CHARS + 'A';
        else
            res[i] = c;
    }

    return res;
}

// Concatenates the strings into a single string using a delimiter
// Example: {"apina", "banaani", "cembalo"} '|' -> "apina|banaani|cembalo"
char* join(char **array, int n, char delimiter) {
    int size = 0;

    for (int i = 0; i < n; i++) {
        size += strlen(array[i]);
    }
    
    char *res = malloc(size + (n - 1) + 1);

    res[0] = '\0';

    char* del_str[2];
    del_str[0] = delimiter;
    del_str[1] = '\0';

    for (int i = 0; i < n; i++) {
        strncat(res, array[i], strlen(array[i]));
        
        if (i < n - 1)
            strncat(res, del_str, 1);
    }

    return res;
}

// Splits the string into an array using a delimiter
//   - Return the array length
//   - Reserve memory for the array
// Example: "apina|banaani|cembalo" '|' -> {"apina", "banaani", "cembalo"}
int split(char* string, char delimiter, char*** array) {
    int str_len = strlen(string);

    int temp_arr[str_len];
    memset(temp_arr, 0, sizeof(temp_arr));

    int j = 0;
    for (int i = 0; string[i]; i++) {
        if (string[i] == delimiter) {
            j++;
        } else {
            temp_arr[j]++;
        }
    }

    int arr_len = j + 1;
    int string_i = 0;

    *array = malloc(arr_len * sizeof(char *));

    for (int i = 0; i < arr_len; i++) {
        int l = temp_arr[i];
        (*array)[i] = malloc(l + 1);
        
        strncpy((*array)[i], &string[string_i], l);

        (*array)[i][l] = '\0';
        string_i += (l + 1);
    }

    return arr_len;
}

// Sorts the given array of strings
//   - Use strcmp to compare the strings
// Example: {"all", "your", "base", "are", "belong", "to", "us"} ->
//          {"all", "are", "base", "belong", "to", "us", "your"}
int cmp(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

void sort_strings(char **array, int n) {
    qsort(array, n, sizeof(char *), cmp);
}
