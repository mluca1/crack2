/*
*  Matt L Lab 10 Cracking Passwords
*  April 23, 2019
*  Last Edit: April 25, 2019 @ 2:09am
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


//------------------------------

char** read_dictionary(char *filename) {

         struct stat st;
         if (stat(filename, &st) == -1) 
         {
         fprintf (stderr, "cant get info about, %s\n", filename);
         exit (1);
         }
         
         int len = st.st_size;
         char *file = malloc(len);
        
         //Read entire file into memory (alloc)
        FILE *f = fopen (filename, "r");
            if (!f) 
            {
                printf ("cant open %s for read\n", filename);
            exit(1);
            }
            
        fread(file, 1, len, f);
        fclose(f);
    
         //Replace new lines "\n" with nulls "\0"
        int count = 0;
            
            for (int i = 0; i < len; i++) 
            {
                if (file[i] == '\n')
                {
                    file[i] = '\0';
                    file[i] = '\0';
                    count ++;
            } 
                }

//------------------------------

        //space for array of pointers
        char** line = malloc((count +1) * sizeof(char *)); 

        //Fill in addresses
        int word = 0;
        line[word] = file; //the first word in the file
        word++;
        
            for (int i = 1; i < len; i++)
            {
                if( file[i] =='\0' && i+1 < len) 
                {
                    line[word] = &file[i+1]; //or &file [i+1];
                     word++;
            }
                }
        line[word] = NULL;

             //Return address of second array
            return line;
            }
    

//------------------------------

    int main () 
    {
        char ** x = read_dictionary("rockyou100.txt");
        //printf("%s\n", x[3]);
        int i = 0;
        
        while (x[i]!= NULL)
        {
            printf("%s\n", x[i]);
            i++;
        }
        free(x[0]); //second array
        free(x);
     }