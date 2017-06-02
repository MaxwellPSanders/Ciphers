//Maxwell Sanders
//Vigenere cipher decoder and encoder

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//main method to execute the commands
int main(int argv, char** argc){
    int tabula[26][26]; //tabula recta to hold all of the shifts in
    int i,j; //standard counter variables
    FILE *ifp, *ofp; //input file and output file pointers
    char buffer[100]; //buffer to hold the file input

    //iterate through the whole table
    for(i = 0; i < 26; i ++){
        for(j = 0; j < 26; j ++){
            //put the offsets into the table
            //mod 26 because the alphabet
            tabula[i][j] = i + j;
            tabula[i][j] %= 26;
            // debug printf("%c ", tabula[i][j] + 97);
        }
        // debug printf("\n");
    }
 
    //make sure they have enough arguments
    if(argv != 5){
        printf("Invalid input. Proper format:\n./program d/e input_file output_file keyword\n");
        return 0;
    }

    //input file can't match output file
    if(strcmp(argc[2], argc[3]) == 0){
        printf("Input and output files should not be the same.\n");
        return 0;
    } 

    //try to open the input file
    if(!(ifp = fopen(argc[2], "r"))){
        printf("Could not open the input file.\n");
        return 0;
    }    

    ofp = fopen(argc[3], "w");

    //check if it is encode or decode
    if(strcmp(argc[1],"e") == 0){
        //open the input file and read what is in it
        while( fgets( buffer, sizeof(buffer), ifp) != NULL){
            for( i = 0; i < buffer && buffer[i] != NULL; i ++){
                    
            }
            fprintf(ofp, "%s", buffer);    
        }            
    }
    else if(strcmp(argc[1], "d") == 0){
        while( fgets( buffer, sizeof(buffer), ifp) != NULL){
            fprintf(ofp, "%s", buffer);    
        }            
    }
    else{
        printf("Invalid input. Proper format:\n./program d/e input_file keyword\n");
        return 0;
    }
}
