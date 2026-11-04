#include "tasks.h"

// Calculates the area of a rectangle
// Example: calc_area(2, 3) -> 6
long calc_area(int width, int height) {
    return (long) width * height;
}

// Checks if an integer is odd
// Example: is_odd(5) -> 1
// Example: is_odd(6) -> 0
int is_odd(int n) {
    return abs(n % 2);
}

// Counts the sum of integers between 1 and n
// Example: range_sum(5) -> 15
long range_sum(int n) {
    long x = n;
    return x * (x + 1) / 2;
}

// Counts the sum of squares between 1 and n
// Example: squared_sum(5) -> 55
long squared_sum(int n) {
    long res = 0;

    for (long x = 1; x <= n; x++) {
        res += x * x;
    }

    return res;
}

// Divides n apples evenly for two persons
// Example: divide_apples(5) -> 2.5
// Example: divide_apples(6) -> 3
double divide_apples(int n) {
    return (double) n / 2;
}

// Calculates rectangle area and perimeter
//   - Results are returned through pointers
// Example: analyze_rectangle(3, 4, &area, &perimeter)
//   - area -> 12
//   - perimeter -> 14
void analyze_rectangle(int width, int height, long *area, long *perimeter) {
    *area = (long) width * height;
    *perimeter = (long) (width + height) * 2;
}

// Counts the steps in the following process:
//   - If n is even, divide it by two
//   - If n is odd, subtract one
//   - If n is zero, stop
// Example: count_steps(10) -> 5 (10 -> 5 -> 4 -> 2 -> 1 -> 0)
int count_steps(int n) {
    int steps = 0;
    while (1) {
        if (!n) break;
    
        if (n % 2 == 0) n /= 2;
        else n--;

        steps++;
    }
    
    return steps;
}

// Returns the week day name in English
//   - day is between 1 and 7
// Example: week_day_name(1) -> "Monday"
// Example: week_day_name(2) -> "Tuesday"
char* week_day_name(int day) {
    const char *wkdays[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    return wkdays[day - 1];
}

// Counts the number of digits in the given integer
//   - You can assume that n is nonnegative
// Example: digit_count(123) -> 3
int digit_count(int n) {
    int count = 0;

    if (!n) return 1;

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

// Calculates the Manhattan distance between two positions
//   - Formula: |x1 - x2| + |y1 - y2| where |...| is absolute value
// Example: p1 = {2, 3}, p2 = {1, 5} -> |2 - 1| + |3 - 5| = 3
int manhattan_distance(struct Position p1, struct Position p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Calculates the sum of two fractions
//   - Return the result in simplest form
// Example: f1 = {1, 4}, f2 = {1, 12} -> {1, 3}
struct Fraction fraction_sum(struct Fraction f1, struct Fraction f2) {
    if (f1.b != f2.b) {
        int den1 = f1.b;
        int den2 = f2.b;
        f1.a *= den2;
        f1.b *= den2;
        f2.a *= den1;
        f2.b = f1.b;
    }

    struct Fraction res = {f1.a + f2.a, f1.b};

    int bigger = res.a > res.b ? res.a : res.b;
    int smaller = res.a < res.b ? res.a : res.b;

    for (int n = smaller; smaller >= 1; n--) {
        if (smaller % n == 0 && bigger % n == 0) {
            res.a /= n;
            res.b /= n;
            break;
        }
    }

    return res;
}

// Counts the number of even numbers in the array
// Example: {2, 1, 2, 4, 5} -> 3
int array_even_count(int *array, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        count += array[i] % 2 == 0 ? 1 : 0;
    }

    return count;
}

// Finds the minimum value in the array
// Example: {2, 1, 2, 4, 5} -> 1
int array_min_value(int *array, int n) {
    int min = array[0];

    for (int i = 0; i < n; i++) {
        min = array[i] < min ? array[i] : min;
    }

    return min;
}

// Checks if the given array is sorted
// Example: {1, 3, 2, 4} -> 0
// Example: {1, 2, 2, 5} -> 1
int array_is_sorted(int *array, int n) {
    for (int i = 1; i < n; i++) {
        if (array[i-1] > array[i]) return 0;
    }

    return 1;
}

// Converts all array values to absolute values
// Example: {1, -1, -5, 0} -> {1, 1, 5, 0}
void convert_array(int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = abs(array[i]);
    }
}

// Counts the number of distinct values in the array
// Example: {1, 2, 1, 5, 2} -> 3
int cmp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    if (x < y) return -1;
    if (x == y) return 0;
    if (x > y) return 1;
}

int array_distinct_count(int *array, int n) {
    int count = 0;
    if (n) {
        if (n > 1) qsort(array, n, sizeof(int), cmp);

        count++;
        int init = array[0];
        for (int i = 1; i < n; i++) {
            count += array[i-1] != array[i] ? 1 : 0;
        }
    }

    return count;
}

// Counts the number of times a letter appears in a string
// Example: count_letters("aybabtu", 'a') -> 2
int count_letters(char *string, char letter) {
    int count = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] == letter) count++;
    }

    return count;
}

// Counts the number of words in the given string
//   - Each word consists of letters a..z
//   - There is a single space between each consecutive words
// Example: count_words("all your base") -> 3
int count_words(char *words) {
    int count = 1;

    for (int i = 0; words[i]; i++) {
        if (words[i] == ' ') count++;
    }

    return count;
}

// Finds the maximum word length in the given string
//   - Each word consists of letters a..z
//   - There is a single space between each consecutive words
// Example: count_words("all your base") -> 4
int max_word_length(char *words) {
    int max = 0;
    int cur = 0;

    for (int i = 0; words[i]; i++) {
        if (words[i] != ' ') {
            cur++;
        } else {
            max = cur > max ? cur : max;
            cur = 0;
        }
    }

    max = cur > max ? cur : max;

    return max;
}

// Checks if the given word is a palindrome
//   - The word consists of letters a..z
// Example: is_palindrome("abba") -> 1
// Example: is_palindrome("abca") -> 0
int is_palindrome(char *word) {
    int i = 0;
    int j = strlen(word) - 1;

    while (i < j) {
        if (word[i] != word[j]) return 0;
        i++;
        j--;
    }

    return 1;
}

// Counts the number of times any letter appears in a string
// Example: count_letters("aybabtu", "au") -> 3
int count_letters_set(char *string, char *letters) {
    int count = 0;
    
    for (int j = 0; letters[j]; j++) {
        for (int i = 0; string[i]; i++) {
            if (letters[j] == string[i]) count++;
        }
    }

    return count;
}

// Checks if two words are anagrams of each other
//   - The words consist of letters a..z
// Example: check_anagrams("abca", "aacb") -> 1
// Example: check_anagrams("abca", "abcb") -> 0
int cmp_str(const void *a, const void *b) {
    char x = *(char*)a, y = *(char*)b;
    if (x < y) return -1;
    if (x == y) return 0;
    if (x > y) return 1;
}

int check_anagrams(char *word1, char *word2) {
    char a[strlen(word1) + 1];
    char b[strlen(word2) + 1];

    strcpy(a, word1);
    strcpy(b, word2);
    
    qsort(a, strlen(a), sizeof(char), cmp_str);
    qsort(b, strlen(b), sizeof(char), cmp_str);
    
    if (strcmp(a, b) == 0) return 1;
    
    return 0;
}

// Checks a University of Helsinki student number
//   - The number consists of nine digits 0-9 and the first digit is 0
//   - The last digit is a checksum calculated from other digits
//   - The checksum is calculated as a sum using the weights {3,7,1,3,7,1,3,7}
//   - If the result is divisible by 10, the checksum is 0
//   - Otherwise the checksum is the distance to the next multiple of ten
// Example: consider 012749139
//   - The format of the number is correct (nine digits, first digit 0)
//   - Let's calculate the checksum: 3*0+7*1+1*2+3*7+7*4+1*9+3*1+7*3 = 91
//   - The distance to the next multiple of ten is 9
//   - The checksum matches the last digit, so the number is valid
int valid_student_number(char *number) {
    const int weights[] = {3,7,1,3,7,1,3,7};

    if (strlen(number) != 9 || number[0] != '0') return 0;

    for (int i = 0; number[i]; i++) {
        if (number[i] < '0' || number[i] > '9') return 0;
    }

    int checksum = 0;
    int last_digit = number[8] - '0';

    for (int i = 0; i < 8; i++) {
        checksum += weights[i] * (number[i] - '0');
    }
    
    if (checksum % 10 == 0 && last_digit == checksum % 10) return 1; 

    if (last_digit == 10 - checksum % 10) return 1;

    return 0;
}
