//Maxwell Sanders
//Substitution Cipher cracker

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Function: main 
 * Parameters: nothing
 * returns: nothing
 * Description: the main function, does everything
 */
int main(int argv, char* args[]){
    char swaps[26] = { 'e', 't', 'a', 'o', 'i', 'n', 's', 'h',
                       'r', 'd', 'l', 'c', 'u', 'm', 'w', 'f',
                       'g', 'y', 'p', 'b', 'v', 'k', 'j', 'x',
                       'q', 'z'}; 
    //array of characters that will hold the first run swaps

    char abet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                       'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                       'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                       'y', 'z'}; 
    //array of characters that will hold the alphabet

    int abet_counts[26] = {0}; //zero allocated counters for the alphabet

    int i,j; // standard counter variables

    //check to see if there is 1 extra argument
    if(argv != 2){
        printf("Improper syntax\n");
        printf("Program inputfile\n"); 
        return 0;
    }

    FILE *ifp; // file pointer to the input file that is to be ciphered
    //try to open input file
    ifp = fopen(args[1], "r");
    if(ifp == NULL){
        printf("Input file not found\n");
        return 0;
    }

    char *full_text = (char*) malloc(sizeof(char)*100); // this will hold the text from the input file for analysis
    char text[100]; // this will hold buffer
    int hundreds = 1; // this will hold the counter of how many hundreds of bytes the text will hold

    fgets( full_text, sizeof(text) - 1, ifp);

        //get through all the cahracters
        for(i = 0; i < 100; i++){
            //if it is a null character then that is the end of the file
            if(full_text[i] == 0){
                break;     
            }

            //if it is uppercase or lowercase consider different numbers
            if(isupper(full_text[i])){
                abet_counts[full_text[i] - 65] ++;
                continue;
            }
            if(islower(full_text[i])){
                abet_counts[full_text[i] - 97] ++;
                continue;
            }
        }
        
	//increment and reallocate more data
        hundreds ++;
        full_text = (char*) realloc(full_text, sizeof(char)*hundreds*100);

    //read all the text in the file and get counts of letters
    while( fgets(text, sizeof(text) - 1, ifp) != 0){
        //add on whatever the text was
        strcat(full_text, text);

        //get through all the cahracters
        for(i = 0; i < 100; i++){
            //if it is a null character then that is the end of the file
            if(text[i] == 0){
                break;     
            }

            //if it is uppercase or lowercase consider different numbers
            if(isupper(text[i])){
                abet_counts[text[i] - 65] ++;
                continue;
            }
            if(islower(text[i])){
                abet_counts[text[i] - 97] ++;
                continue;
            }
        }
        
	//increment and reallocate more data
        hundreds ++;
        full_text = (char*) realloc(full_text, sizeof(char)*hundreds*100);
    }           

    //debug to check the count of letters
    for(i = 0; i < 26; i ++){
        printf("%c - %d\n", i + 65, abet_counts[i]);
    } 
    

    //sort the array of letters based off of abet_counts
    int temp_count; //holds the temporary count
    char temp_char; //holds the temporary character
    for(i = 0; i < 25; i ++){
        for(j = i; j < 26; j ++){
            if(abet_counts[i] < abet_counts[j]){
                temp_count = abet_counts[i];
                temp_char = abet[i];
                abet_counts[i] = abet_counts[j];
                abet[i] = abet[j];
                abet_counts[j] = temp_count;
                abet[j] = temp_char;
            }
        }
        
    }

    printf("%s\n", abet);
    
    fclose(ifp);

    //go back through the text and display different letters
        //get the characters in text
        for(i = 0; full_text[i] != 0; i ++){
            //check if it is alphabetic
            if(isalpha(full_text[i])){
                if(islower(full_text[i])){
                    for(j = 0; j < 26; j ++){
                        if(abet[j] == full_text[i]){
                            full_text[i] = swaps[j];  
                            break;   
                        }       
                    }  
                }
                else{
                    for(j = 0; j < 26; j ++){
                        if(abet[j] - 32 == full_text[i]){
                            full_text[i] = swaps[j] - 32;   
                            break;   
                        }       
                    }
                }
            }
        }          

    printf("%s", full_text);
}
