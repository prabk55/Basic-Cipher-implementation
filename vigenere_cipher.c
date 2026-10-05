#include <stdio.h>
#include <string.h>

int main(int no_of_arg, char *arg[])
{

    if (strcmp(arg[2], "-vig") == 0)
    {

        if (strcmp(arg[1], "-e") == 0)
        {
            char plaintext[100];
            int vkey_len = strlen(arg[3]);
            int plaintext_len = strlen(arg[4]);
            char encrypted_text[100];
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

            char vkey[100];
            
            strcpy(vkey,arg[3]);

            label1:
            if(vkey_len <= plaintext_len)
            {
                strcat(vkey, arg[3]); 
                vkey_len=strlen(vkey);

                goto label1;
            }
            for(int i=0; i < plaintext_len; i++){
              
                int a = (int)vkey[i];
                int b = (int)plaintext[i];
                int c=(a+b-65*2)%26;
                encrypted_text[i]=(char)(c+65);
                
            }
            encrypted_text[plaintext_len]= '\0';
            printf("%s",encrypted_text);

        }
        else if (strcmp(arg[1], "-d") == 0)  {

            
            char ciphertext[100];
            int vkey_len = strlen(arg[3]);
            int ciphertext_len = strlen(arg[4]);
            char decrypted_text[100];
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

            char vkey[100];
            
            strcpy(vkey,arg[3]);

            label2:
            if(vkey_len <= ciphertext_len)
            {
                strcat(vkey, arg[3]); 
                vkey_len=strlen(vkey);

                goto label2;
            }
            for(int i=0; i < ciphertext_len; i++){
              
                int a = (int)vkey[i];
                int b = (int)ciphertext[i];
                int c=(b-a+26)%26;
                decrypted_text[i]=(char)(c+65);
                
            }
            decrypted_text[ciphertext_len]= '\0';
            printf("%s",decrypted_text);

        }  
    }
}