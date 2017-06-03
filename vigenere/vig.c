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

    //check to see if the keyword is all lowercase
    int keylen = strlen(argc[4]);
    for(i = 0; i < keylen; i ++){
        if(!islower(argc[4][i])){
            printf("Keyword has to be all lowercase!!!\n");
            return 0;
        }
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

    int keycount = 0; //counter for where you are at in the keyword

    //check if it is encode or decode
    if(strcmp(argc[1],"e") == 0){
        //open the input file and read what is in it
        while( fgets( buffer, sizeof(buffer), ifp) != NULL){
            //go through every letter and check if it is a letter
            //if it is then take the keyword and the letter and encrypt it
            for( i = 0; i < 100 && buffer[i] != 0; i ++){
                if(islower(buffer[i])){
                    buffer[i] = tabula[argc[4][keycount] - 97][buffer[i] - 97] + 97;
                    keycount ++;
                }               
                else if(isupper(buffer[i])){               
                    buffer[i] = tabula[argc[4][keycount] - 97][buffer[i] - 65] + 65;
                    keycount ++;
                }              
                keycount %= keylen;               
            }
            fprintf(ofp, "%s", buffer);    
        }            
    }
    else if(strcmp(argc[1], "d") == 0){
        while( fgets( buffer, sizeof(buffer), ifp) != NULL){
            //go through every letter and check if it is a letter
            //if it is then take the keyword and the letter and decrypt it
            for( i = 0; i < 100 && buffer[i] != 0; i ++){
                if(islower(buffer[i])){
                    if( (buffer[i] = 97 + buffer[i] - argc[4][keycount]) < 97){
                        buffer[i] += 26;
                    }
                    keycount ++;
                }               
                else if(isupper(buffer[i])){               
                    if( (buffer[i] = 65 + buffer[i] - argc[4][keycount] + 32) < 65){
                        buffer[i] += 26;
                    }
                    keycount ++;
                }              
                keycount %= keylen;               
            }           
            fprintf(ofp, "%s", buffer);    
        }            
    }
    else{
        printf("Invalid input. Proper format:\n./program d/e input_file keyword\n");
        return 0;
    }
}
