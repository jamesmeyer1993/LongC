/* 
The following program demonstrates how in four lines or less we are able to
perform an effortless download by using one command line program, wget.

By looking into the man pages, we can create a more advanced wget command that
specifies the number of retries, refresh rates, and the name of the output file.
All of these commands can be assembed through simple string concatonation.

In my research I have yet to find a language that can do a download as
straight-forward and efficiently as C & bash.
*/

#include <string.h>
#include <stdlib.h>

int main(){

    char cmd[64] = "wget ";
    char page[] = "https://bitcoin.org";
    strcat(cmd, page);          // concatonate the strings
    int status = system(cmd);   // call the OS
    
    return(0);
}
