//This is the caesar/shift cipher
//Maxwell Sanders
//Popularized by the Roman Empire

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function: main
 * Parameters: args
 * Returns: nothing
 * Description: This is the main
 */
int main(int argv, char** args){
    //check to see if there are 3 extra arguments
    if(argv != 4){
        printf("Improper syntax\n");
        printf("Program shift inputfile outputfile/\"print\"\n"); 
        return 0;
    }

    int counter; //counter for the for loop
    int shift = atoi(args[1])%26;
    //check to see if argument 2 is a number
    if(shift == 0){
        printf("Number is a 26*n letter shift or is not a number.\n");
        return 0;
    }

    FILE *ifp; // file pointer to the input file that is to be ciphered
    //try to open input file
    ifp = fopen(args[2], "r");
    if(ifp == NULL){
        printf("Input file not found\n");
        return 0;
    }

    //check if the input file is the same as the output file
    if(!strcmp(args[2],args[3])){
        printf("Input file cannot match output file!\n");
        return 0;
    }

    char text[100]; // string to hold and encode
    //check to see if the user wants it printed to screen
    //otherwise try to open file and print to that
    if(!strcmp(args[3], "print")){
        while(fgets(text, sizeof(text) - 1, ifp) != NULL){
            //check to see if char is alphabetic, if so, shift it
            for(counter = 0; counter < 100; counter ++){
                //check if it is lowercase
                if(islower(text[counter])){
                    text[counter] += shift;
                    //if it is now not lower, reshift depending on the operation
                    if(!islower(text[counter])){
                       if(shift >= 0){ 
                           text[counter] -= 26;
                       } 
                       else{
                           text[counter] += 26;
                       }
                    }
                }
                else if(isupper(text[counter])){
                    text[counter] += shift;
                    //if it is now not upper, reshift depending on the operation
                    if(!isupper(text[counter])){
                       if(shift >= 0){ 
                           text[counter] -= 26;
                       } 
                       else{
                           text[counter] += 26;
                       }
                    }
                }
            }
            printf("%s", text);
        }
        printf("\n");
        return 0;
    }
    else{
  

    }
    //place into output file
}
