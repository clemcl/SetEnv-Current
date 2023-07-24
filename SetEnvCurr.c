#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    static int fileopen = 0;   // If 1, then environment
                               // variable sets output file
    static char * envaddr;

    FILE *putsymsfile;          // Create a file pointer.


// Define the send function
int send_string(char *string) {
    int i;

//   putenv("PANELSYMS=SetSymsExt.bat");



// Check if we have already opened the file to write to.
    if (fileopen) goto writefile;

// Check to see if we are writing a file, or filling the keyboard
    envaddr = getenv("PANELSYMS");       /* If the environment is set, write
                                            to a file */

    if (envaddr == NULL)
       envaddr="SetSymsExt.bat";

    // Open the file in write mode.
    putsymsfile = fopen(envaddr, "w");

    // Check if the file was successfully opened.
    if (putsymsfile == NULL) {
      printf("Error opening file Symbolic SET file: %s\n", envaddr);
      return 20;
    }
    fileopen=1;

writefile:

    fprintf(putsymsfile, string);     // Write a line of text to the file.

    return 0;
}


setenvext(char *name, char *value, int posn)
{

/* Here, we are just going to copy the SET values to the keyboard
   so that whn the program terminates, the value will becomae an
   environment variable */

int      i;
char *   px;
char     store_sym[32];    /* Name stored and padded with blanks */
char     to_key_brd[200]; /* The SET and value */



    px=strchr(name,' ');
    if (px != NULL)
       *px='\0';      // Shorten name string

    strcpy(to_key_brd,"SET ");
    strcat(to_key_brd,name);

/* if the value part of the string has a blank in it,
   add quotes, else just store in the environment.  */

    px=strchr(value,' ');
    if (px != NULL)
    {
       strcat(to_key_brd,"=\"");
       strcat(to_key_brd,value);
       strcat(to_key_brd,"\"\n");
    }
    else
    {
       strcat(to_key_brd,"=");
       strcat(to_key_brd,value);
       strcat(to_key_brd,"\n");
    }


    send_string(to_key_brd);

    return 0;

}


//#if 0
int main() {

    setenvext("testsym", "99", 0);
    setenvext("Sysdate", "99 99", 0);

//    char string[] = "Hello World!\ncvc\n";
//    send_string(string);
    return 0;
}
// Close file is done automatically at program termination
// Close the file.
//    fclose(putsymsfile);

//#endif

