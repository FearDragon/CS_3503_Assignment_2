#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Imports methods
void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int n, char *out);
void to_ones_complement(int n, char *out);
void to_twos_complement(int n, char *out);

int main(void) {
    // Opens the test file
    FILE * file = fopen ("a2_test.txt", "r") ;
    if ( file == NULL ) {
        printf (" Error : Could not open file \n") ;
        return 1;
        }

    // Counters
    int test_counter = 0;
    int tests_passed = 0;

    // Buffer
    char line [256];
    char method[256];

    while ( fgets ( line , sizeof ( line ) , file ) != NULL ) {
        if (line[0] == '\n' || line[0] == '\0') {
            continue;
        }
        // Get the method
        sscanf(line, "%s", method);
        // Process each line
        if (strcmp(method, "oct_to_bin") == 0) {
            test_counter++;
            int n;
            char char_input[33];
            // Get values from the test file
            sscanf(line, "%*s" "%d", &n);
            sprintf(char_input, "%d", n);
            char *token = strtok(line, " ");
            char *answer;
            char result[65];
            // Get the expected result
            for (int i = 1; i <= 3; i++) {
                if (i == 3) {
                    answer = token;
                }
                token = strtok(NULL, " ");
            }
            // Run oct_to_bin
            oct_to_bin(char_input, result);
            // Compare the answer to the method result
            answer[strcspn(answer, "\n")] = 0;

            // Print the output
            printf ("Test %d: oct_to_bin (\"%d\") -> Expected: \"%s\", Got: \"%s\" ", test_counter, n, answer, result);
            if (strcmp(result, answer) == 0) {
                tests_passed++;
                printf ("[PASS]\n\n") ;
            } else {
                printf ("[FAIL]\n\n") ;
            }
        } else if (strcmp(method, "oct_to_hex") == 0) {
            test_counter++;
            int n;
            char char_input[33];
            // Get values from the test file
            sscanf(line, "%*s" "%d", &n);
            sprintf(char_input, "%d", n);
            char *token = strtok(line, " ");
            char *answer;
            char result[65];
            // Get the expected result
            for (int i = 1; i <= 3; i++) {
                if (i == 3) {
                    answer = token;
                }
                token = strtok(NULL, " ");
            }
            // Run oct_to_hex
            oct_to_hex(char_input, result);
            // Compare the answer to the method result
            answer[strcspn(answer, "\n")] = 0;

            // Print the output
            printf ("Test %d: oct_to_hex (\"%d\") -> Expected: \"%s\", Got: \"%s\" ", test_counter, n, answer, result);
            if (strcmp(result, answer) == 0) {
                tests_passed++;
                printf ("[PASS]\n\n") ;
            } else {
                printf ("[FAIL]\n\n") ;
            }
        } else if (strcmp(method, "hex_to_bin") == 0) {
            test_counter++;
            char *char_input;
            char *token = strtok(line, " ");
            char *answer;
            token = strtok(NULL, " ");
            char result[65];
            // Get the expected result
            for (int i = 1; i <= 3; i++) {
                if (i == 2) {
                    char_input = token;
                    token = strtok(NULL, " ");
                }
                if (i == 3) {
                    answer = token;
                }
            }
            // Run hex_to_bin
            hex_to_bin(char_input, result);
            // Compare the answer to the method result
            answer[strcspn(answer, "\n")] = 0;

            // Print the output
            printf ("Test %d: hex_to_bin (\"%s\") -> Expected: \"%s\", Got: \"%s\" ", test_counter, char_input, answer, result);
            if (strcmp(result, answer) == 0) {
                tests_passed++;
                printf ("[PASS]\n\n") ;
            } else {
                printf ("[FAIL]\n\n") ;
            }
        } else if (strcmp(method, "to_sign_magnitude") == 0) {
            test_counter++;
            int n;
            char char_input[33];
            // Get values from the test file
            sscanf(line, "%*s" "%d", &n);
            char *token = strtok(line, " ");
            char *answer;
            char result[65];
            // Get the expected result
            for (int i = 1; i <= 3; i++) {
                if (i == 3) {
                    answer = token;
                }
                token = strtok(NULL, " ");
            }
            // Run to_sign_magnitude
            to_sign_magnitude(n, result);
            // Compare the answer to the method result
            answer[strcspn(answer, "\n")] = 0;

            // Print the output
            printf ("Test %d: to_sign_magnitude (\"%d\") -> Expected: \"%s\", Got: \"%s\" ", test_counter, n, answer, result);
            if (strcmp(result, answer) == 0) {
                tests_passed++;
                printf ("[PASS]\n\n") ;
            } else {
                printf ("[FAIL]\n\n") ;
            }
        } else if (strcmp(method, "to_ones_complement") == 0) {
            test_counter++;
            int n;
            char char_input[33];
            // Get values from the test file
            sscanf(line, "%*s" "%d", &n);
            char *token = strtok(line, " ");
            char *answer;
            char result[65];
            // Get the expected result
            for (int i = 1; i <= 3; i++) {
                if (i == 3) {
                    answer = token;
                }
                token = strtok(NULL, " ");
            }
            // Run to_ones_complement
            to_ones_complement(n, result);
            // Compare the answer to the method result
            answer[strcspn(answer, "\n")] = 0;

            // Print the output
            printf ("Test %d: to_ones_complement (\"%d\") -> Expected: \"%s\", Got: \"%s\" ", test_counter, n, answer, result);
            if (strcmp(result, answer) == 0) {
                tests_passed++;
                printf ("[PASS]\n\n") ;
            } else {
                printf ("[FAIL]\n\n") ;
            }
        } else if (strcmp(method, "to_twos_complement") == 0) {
            test_counter++;
            int n;
            char char_input[33];
            // Get values from the test file
            sscanf(line, "%*s" "%d", &n);
            char *token = strtok(line, " ");
            char *answer;
            char result[65];
            // Get the expected result
            for (int i = 1; i <= 3; i++) {
                if (i == 3) {
                    answer = token;
                }
                token = strtok(NULL, " ");
            }
            // Run to_twos_complement
            to_twos_complement(n, result);
            // Compare the answer to the method result
            answer[strcspn(answer, "\n")] = 0;

            // Print the output
            printf ("Test %d: to_twos_complement (\"%d\") -> Expected: \"%s\", Got: \"%s\" ", test_counter, n, answer, result);
            if (strcmp(result, answer) == 0) {
                tests_passed++;
                printf ("[PASS]\n\n") ;
            } else {
                printf ("[FAIL]\n\n") ;
            }
        }

    }
    fclose ( file ) ;
    printf ( "Summary: %d/%d tests passed", tests_passed, test_counter ) ;
    return 0;
}