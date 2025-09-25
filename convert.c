#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void oct_to_bin(const char *oct, char *out) {
    strcpy(out, "");
    // All possible octal to binary conversions
    for (int i = 0; i < strlen(oct); i++) {
        switch (oct[i]) {
            case '0':
                strcat(out, "000");
                break;
            case '1':
                strcat(out, "001");
                break;
            case '2':
                strcat(out, "010");
                break;
            case '3':
                strcat(out, "011");
                break;
            case '4':
                strcat(out, "100");
                break;
            case '5':
                strcat(out, "101");
                break;
            case '6':
                strcat(out, "110");
                break;
            case '7':
                strcat(out, "111");
                break;
            default:
                // Error handling
                strcpy(out, "Not an Octal");
                return;
        }
    }
}
void oct_to_hex(const char *oct, char *out) {
    // Initialize variables and get binary conversion
    char bin[33] = "";
    char hex[33] = "";
    oct_to_bin(oct, bin);
    if (strcmp(bin, "Not an Octal") == 0) {
        strcpy(out, "Not an Octal");
        return;
    }
    // Get the padded binary
    char bin_padded[48];
    if (strlen(bin) % 4 != 0) {
        strcpy(bin_padded, "0");
        for (int i = 0; i < 4 - ((strlen(bin) % 4) + 1); i++) {
            strcat(bin_padded, "0");
        }
        strcat(bin_padded, bin);
    } else {
        strcpy(bin_padded, bin);
    }
    strcpy(hex, "");
    // Hex index
    int j = 0;
    // Group binary into groups of 4 and convert to hex
    for (int i = 0; i < strlen(bin_padded); i += 4) {
        char group [5];
        memcpy(group, &bin_padded[i], 4);
        group[4] = '\0';
        int num = strtol(group, NULL, 2);
        if ( num < 10)
            hex[j++] = '0' + num ;
        else
            hex[j++] = 'A' + ( num - 10) ;
    }
    // Remove leading zeros
    int k = 0;
    while (hex[k] == '0' && k < j - 1) {
        k++;
    }
    strcpy(out, hex + k);
}
void hex_to_bin(const char *hex, char *out) {
    // All possible hex to binary conversions
    const char *hex_table[16] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };
    // Clear output
    out[0] = '\0';
    int num = 0;
    // Convert hex to binary using the hex_table
    for (int i = 0; i < strlen(hex); i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            num = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            num = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            num = hex[i] - 'a' + 10;
        } else {
            strcpy(out, "Not an Hexadecimal");
            return;
        }
        strcat(out, hex_table[num]);
    }
}
void to_sign_magnitude(int n, char *out) {
    char binary[33];
    // Get the magnitude
    uint32_t magnitude = abs(n);
    // Convert the magnitude to binary
    int index = 31;
    while (magnitude > 0) {
        binary[index--] = (magnitude % 2) + '0';
        magnitude /= 2;
    }
    // Add leading zeros
    for (int i = 0; i <= index; i++) {
        binary[i] = '0';
    }
    // Add sign bit
    if (n >= 0) {
        out[0] = '0';
    } else {
        out[0] = '1';
    }
    // Combine the sign bit and binary and output the result
    binary[32] = '\0';
    strncpy(out + 1, binary + 1, 31);
    out[32] = '\0';
}
void to_ones_complement(int n, char *out) {
    char binary[33];
    // Get 32 bit binary
    to_sign_magnitude(n, binary);
    // Flip all bits except the sign bit if its negative
    if (n >= 0) {
        strcpy(out, binary);
    } else {
        out[0] = '1';
        for (int i = 1; i < 32; i++) {
            out[i] = (binary[i] == '0') ? '1' : '0';
        }
    }
    out[32] = '\0';
}
void to_twos_complement(int n, char *out) {
    char binary[33];
    // Get 32 bit binary
    to_sign_magnitude(n, binary);
    // Flip all bits except the sign bit if its negative
    if (n >= 0) {
        strcpy(out, binary);
    } else {
        out[0] = '1';
        for (int i = 1; i < 32; i++) {
            out[i] = (binary[i] == '0') ? '1' : '0';
        }
        // Adds 1 to the flipped binary
        for (int i = 31; i >= 1; i--) {
            if (out[i] == '0') {
                out[i] = '1';
                break;
            } else {
                out[i] = '0';
            }
        }
    }
    out[32] = '\0';
}