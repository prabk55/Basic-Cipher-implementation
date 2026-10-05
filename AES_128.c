#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned char multiplication(int a, unsigned char x);
unsigned char multiplication(int a, unsigned char x)
{
    int i;
    if (a == 2)
    {
        if (x & 0x80)
        {
            return (x << 1) ^ 0x1B;
        }
        else
        {
            return x << 1;
        }
    }
    if (a == 4)
    {
        return multiplication(2, multiplication(2, x));
    }
    if (a == 8)
    {
        return multiplication(2, multiplication(2, multiplication(2, x)));
    }
    else if (a == 3)
    {
        return multiplication(2, x) ^ x;
    }
    else if (a == 11)
    {
        return multiplication(8, x) ^ multiplication(2, x) ^ x;
    }
    else if (a == 9)
    {
        return multiplication(8, x) ^ x;
    }
    else if (a == 14)
    {
        return multiplication(8, x) ^ multiplication(4, x) ^ multiplication(2, x);
    }
    else if (a == 13)
    {
        return multiplication(8, x) ^ multiplication(4, x) ^ x;
    }
}

int main(int no_of_arg, char *arg[])
{
    if (strcmp(arg[2], "-aes") == 0)
    {
        unsigned char sbox[256] = {
            0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5,
            0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
            0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0,
            0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
            0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC,
            0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
            0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A,
            0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
            0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0,
            0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
            0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B,
            0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
            0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85,
            0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
            0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5,
            0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
            0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17,
            0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
            0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88,
            0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
            0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C,
            0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
            0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9,
            0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
            0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6,
            0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
            0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E,
            0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
            0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94,
            0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
            0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68,
            0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16};

        unsigned char inverse_sbox[256] = {
            0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38,
            0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
            0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87,
            0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
            0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D,
            0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
            0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2,
            0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
            0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16,
            0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
            0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA,
            0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
            0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A,
            0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
            0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02,
            0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
            0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA,
            0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
            0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85,
            0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
            0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89,
            0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
            0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20,
            0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
            0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31,
            0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
            0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D,
            0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
            0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0,
            0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
            0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26,
            0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D};

        int Rcon[10] = {
            0x01, 0x02, 0x04, 0x08, 0x10,
            0x20, 0x40, 0x80, 0x1B, 0x36};

        unsigned char key[16];
        memcpy(key, arg[3], 16); // memcpy will take exactly 16 bytes no need to put null character at the end
        unsigned keys[11][4][4];
        unsigned char key_0[4][4];

        for (int j = 0; j < 16; j++)
        {

            if (j <= 3)
            {
                keys[0][j][0] = key[j];
            }
            else if (j > 3 && j <= 7)
            {
                keys[0][j - 4][1] = key[j];
            }
            else if (j > 7 && j <= 11)
            {
                keys[0][j - 8][2] = key[j];
            }
            else if (j > 11 && j <= 15)
            {
                keys[0][j - 12][3] = key[j];
            }
        }
        for (int i = 1; i <= 10; i++)
        {

            // ADD ROUND KEY

            unsigned char tempK[4][1];
            // ROT WORD
            tempK[0][0] = keys[i - 1][1][3];
            tempK[1][0] = keys[i - 1][2][3];
            tempK[2][0] = keys[i - 1][3][3];
            tempK[3][0] = keys[i - 1][0][3];

            // SUB WORD

            for (int m = 0; m < 4; m++)
            {

                tempK[m][0] = sbox[tempK[m][0]];
            }
            // RCON

            tempK[0][0] ^= Rcon[i - 1];
            for (int m = 1; m < 4; m++)
            {
                tempK[m][0] ^= 0;
            }

            unsigned char w3[4][1], w2[4][1], w1[4][1], w0[4][1];

            for (int m = 0; m < 4; m++)
            {

                w0[m][0] = keys[i - 1][m][0];
                w1[m][0] = keys[i - 1][m][1];
                w2[m][0] = keys[i - 1][m][2];
                w3[m][0] = keys[i - 1][m][3];
            }

            // w4,w5,w6,w7
            unsigned char w4[4][1], w5[4][1], w6[4][1], w7[4][1];

            for (int n = 0; n < 4; n++)
            {

                w4[n][0] = tempK[n][0] ^ w0[n][0];
            }
            for (int n = 0; n < 4; n++)
            {

                w5[n][0] = w1[n][0] ^ w4[n][0];
            }
            for (int n = 0; n < 4; n++)
            {

                w6[n][0] = w2[n][0] ^ w5[n][0];
            }
            for (int n = 0; n < 4; n++)
            {

                w7[n][0] = w3[n][0] ^ w6[n][0];
            }
            for (int m = 0; m < 4; m++)
            {
                keys[i][m][0] = w4[m][0];
                keys[i][m][1] = w5[m][0];
                keys[i][m][2] = w6[m][0];
                keys[i][m][3] = w7[m][0];
            }
        }

        if (strcmp(arg[1], "-e") == 0)
        {

            unsigned char state_0[4][4];
            unsigned char plaintext[128];
            unsigned char ciphertext[128];

            unsigned char state_1[4][4];

            FILE *f = fopen(arg[4], "r");
            if (f != NULL)
            {
                fread(plaintext, 1, 99, f);
                plaintext[99] = '\0';
            }
            else
            {
                strcpy(plaintext, arg[4]);
            }
            int pt_len = strlen(plaintext);

            int padding = 16 - (pt_len % 16);
            for (int i = 0; i < padding; i++)
            {
                plaintext[pt_len + i] = padding;
            }
            int padded_len = pt_len + padding;

            for (int i = 0; i < padded_len; i += 16) // ECB loop
            {

                for (int j = 0; j < 16; j++)
                {

                    if (j <= 3)
                    {
                        state_0[j][0] = plaintext[i + j];

                        state_1[j][0] = keys[0][j][0] ^ state_0[j][0];
                    }
                    else if (j > 3 && j <= 7)
                    {
                        state_0[j - 4][1] = plaintext[i + j];

                        state_1[j - 4][1] = keys[0][j - 4][1] ^ state_0[j - 4][1];
                    }
                    else if (j > 7 && j <= 11)
                    {
                        state_0[j - 8][2] = plaintext[i + j];

                        state_1[j - 8][2] = keys[0][j - 8][2] ^ state_0[j - 8][2];
                    }
                    else if (j > 11 && j <= 15)
                    {
                        state_0[j - 12][3] = plaintext[i + j];

                        state_1[j - 12][3] = keys[0][j - 12][3] ^ state_0[j - 12][3];
                    }
                }

                for (int k = 0; k < 9; k++) // ROUND 1 to 9
                {
                    for (int l = 0; l < 4; l++) // SUB BYTES
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            state_1[l][m] = sbox[state_1[l][m]];
                        }
                    }

                    // SHIFT ROWS

                    unsigned char temp1[] = {state_1[1][1], state_1[1][2], state_1[1][3], state_1[1][0]};
                    unsigned char temp2[] = {state_1[2][2], state_1[2][3], state_1[2][0], state_1[2][1]};
                    unsigned char temp3[] = {state_1[3][3], state_1[3][0], state_1[3][1], state_1[3][2]};

                    for (int m = 0; m < 4; m++)
                    {

                        state_1[1][m] = temp1[m];
                        state_1[2][m] = temp2[m];
                        state_1[3][m] = temp3[m];
                    }
                    // MIX COLUMNS
                    unsigned char tempM[4][4];

                    for (int m = 0; m < 4; m++)
                    {

                        tempM[0][m] = multiplication(2, state_1[0][m]) ^ multiplication(3, state_1[1][m]) ^ state_1[2][m] ^ state_1[3][m];
                        tempM[1][m] = state_1[0][m] ^ multiplication(2, state_1[1][m]) ^ multiplication(3, state_1[2][m]) ^ state_1[3][m];
                        tempM[2][m] = state_1[0][m] ^ state_1[1][m] ^ multiplication(2, state_1[2][m]) ^ multiplication(3, state_1[3][m]);
                        tempM[3][m] = multiplication(3, state_1[0][m]) ^ state_1[1][m] ^ state_1[2][m] ^ multiplication(2, state_1[3][m]);
                    }
                    memcpy(state_1, tempM, sizeof(tempM));

                    // XOR WITH KEY

                    for (int m = 0; m < 4; m++)
                    {

                        for (int n = 0; n < 4; n++)
                        {

                            state_1[m][n] ^= keys[k + 1][m][n];
                        }
                    }
                }

                // ROUND 10
                // subbytes
                for (int l = 0; l < 4; l++) // SUB BYTES
                {
                    for (int m = 0; m < 4; m++)
                    {
                        state_1[l][m] = sbox[state_1[l][m]];
                    }
                }
                // shift rows
                unsigned char temp1[] = {state_1[1][1], state_1[1][2], state_1[1][3], state_1[1][0]};
                unsigned char temp2[] = {state_1[2][2], state_1[2][3], state_1[2][0], state_1[2][1]};
                unsigned char temp3[] = {state_1[3][3], state_1[3][0], state_1[3][1], state_1[3][2]};

                for (int m = 0; m < 4; m++)
                {

                    state_1[1][m] = temp1[m];
                    state_1[2][m] = temp2[m];
                    state_1[3][m] = temp3[m];
                }

                // XOR WITH KEY

                for (int m = 0; m < 4; m++)
                {

                    for (int n = 0; n < 4; n++)
                    {

                        state_1[m][n] ^= keys[10][m][n];
                    }
                }

                for (int m = 0; m < 4; m++)
                {
                    for (int n = 0; n < 4; n++)
                    {
                        ciphertext[i + m * 4 + n] = state_1[n][m];
                    }
                }
            }
            for (int i = 0; i < padded_len; i++)
            {
                printf("%02X", ciphertext[i]);
            }
        }

        // DECRYPTION CODE

        else if (strcmp(arg[1], "-d") == 0)
        {
            unsigned char state_0[4][4];
            unsigned char plaintext[128];
            unsigned char ciphertext[256];

            unsigned char state_1[4][4];

            FILE *f = fopen(arg[4], "r");
            if (f != NULL)
            {
                fread(ciphertext, 1, 99, f);
                ciphertext[99] = '\0';
            }
            else
            {
                strcpy(ciphertext, arg[4]);
            }

            //converting ciphertext into hex bytes
            unsigned char cipher_bytes[128];
            int ct_len = strlen(ciphertext)/2;
            char str[3];

            for (int i = 0; i < 2*ct_len; i += 2)
            {
                str[0] = ciphertext[i];
                str[1] = ciphertext[i + 1];
                str[2] = '\0';

                cipher_bytes[i / 2] = (unsigned char)strtol(str, NULL, 16);
            }

            for (int i = 0; i < ct_len; i += 16) // ECB loop
            {

                for (int j = 0; j < 16; j++)
                {

                    if (j <= 3)
                    {
                        state_0[j][0] = cipher_bytes[i + j];

                        state_1[j][0] = keys[10][j][0] ^ state_0[j][0];
                    }
                    else if (j > 3 && j <= 7)
                    {
                        state_0[j - 4][1] = cipher_bytes[i + j];

                        state_1[j - 4][1] = keys[10][j - 4][1] ^ state_0[j - 4][1];
                    }
                    else if (j > 7 && j <= 11)
                    {
                        state_0[j - 8][2] = cipher_bytes[i + j];

                        state_1[j - 8][2] = keys[10][j - 8][2] ^ state_0[j - 8][2];
                    }
                    else if (j > 11 && j <= 15)
                    {
                        state_0[j - 12][3] = cipher_bytes[i + j];

                        state_1[j - 12][3] = keys[10][j - 12][3] ^ state_0[j - 12][3];
                    }
                }
                // ROUND 10

                // shift rows inverse
                unsigned char temp1[] = {state_1[1][3], state_1[1][0], state_1[1][1], state_1[1][2]};
                unsigned char temp2[] = {state_1[2][2], state_1[2][3], state_1[2][0], state_1[2][1]};
                unsigned char temp3[] = {state_1[3][1], state_1[3][2], state_1[3][3], state_1[3][0]};

                for (int m = 0; m < 4; m++)
                {

                    state_1[1][m] = temp1[m];
                    state_1[2][m] = temp2[m];
                    state_1[3][m] = temp3[m];
                }

                // sub bytes inverse
                for (int l = 0; l < 4; l++) // SUB BYTES
                {
                    for (int m = 0; m < 4; m++)
                    {
                        state_1[l][m] = inverse_sbox[state_1[l][m]];
                    }
                }

                // ROUND 9 TO 1

                // reversing xor with key
                for (int i = 9; i != 0; i--)
                {

                    for (int l = 0; l < 4; l++)
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            state_1[l][m] ^= keys[i][l][m];
                        }
                    }
                    // mix column reverse

                    unsigned char tempM[4][4];

                    for (int m = 0; m < 4; m++)
                    {
                        tempM[0][m] = multiplication(0x0E, state_1[0][m]) ^ multiplication(0x0B, state_1[1][m]) ^ multiplication(0x0D, state_1[2][m]) ^ multiplication(0x09, state_1[3][m]);
                        tempM[1][m] = multiplication(0x09, state_1[0][m]) ^ multiplication(0x0E, state_1[1][m]) ^ multiplication(0x0B, state_1[2][m]) ^ multiplication(0x0D, state_1[3][m]);
                        tempM[2][m] = multiplication(0x0D, state_1[0][m]) ^ multiplication(0x09, state_1[1][m]) ^ multiplication(0x0E, state_1[2][m]) ^ multiplication(0x0B, state_1[3][m]);
                        tempM[3][m] = multiplication(0x0B, state_1[0][m]) ^ multiplication(0x0D, state_1[1][m]) ^ multiplication(0x09, state_1[2][m]) ^ multiplication(0x0E, state_1[3][m]);
                    }

                    memcpy(state_1, tempM, sizeof(tempM));

                    // shift rows reverse
                    unsigned char temp1[] = {state_1[1][3], state_1[1][0], state_1[1][1], state_1[1][2]};
                    unsigned char temp2[] = {state_1[2][2], state_1[2][3], state_1[2][0], state_1[2][1]};
                    unsigned char temp3[] = {state_1[3][1], state_1[3][2], state_1[3][3], state_1[3][0]};

                    for (int m = 0; m < 4; m++)
                    {

                        state_1[1][m] = temp1[m];
                        state_1[2][m] = temp2[m];
                        state_1[3][m] = temp3[m];
                    }

                    // sub bytes reverse
                    for (int l = 0; l < 4; l++) // SUB BYTES
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            state_1[l][m] = inverse_sbox[state_1[l][m]];
                        }
                    }
                }
                for (int n = 0; n < 4; n++)
                {
                    for (int o = 0; o < 4; o++)
                    {

                        state_1[n][o] ^= keys[0][n][o];
                    }
                }
                for (int m = 0; m < 4; m++)
                {
                    for (int n = 0; n < 4; n++)
                    {
                        plaintext[i + m * 4 + n] = state_1[n][m];
                    }
                }
            }
            int c = (int)plaintext[ct_len - 1];
            for (int i = 0; i < ct_len - c; i++)
            {
                printf("%c", plaintext[i]);
            }
        }
    }
}