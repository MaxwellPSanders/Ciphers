//Maxwell Sanders
//Vigenere cipher decoder and encoder

#include <stdio.h>

//main method to execute the commands
int main(void){
    int tabula[26][26]; //tabula recta to hold all of the shifts in
    int i,j; //standard counter variables

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

    
}
