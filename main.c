#include <stdio.h>
#include <string.h> 
#define VERSION 0.1
/* Vars */
long unsigned int digit; // initial user-input
unsigned char confirm;
int digits[14]; // buffer array to store and inspect and do stuff

/*func prototype*/
int get_input(void);
int check_basic();
int check_luhn();
int check_extensive(void);

int main() {

    // banner i.e info
    printf("Basic CCF Detector\n");
    fprintf(stdin, "Version %f\n", VERSION);
    printf("Enter the number:");
    //take input
    get_input();

    do {
    printf("\nIs this correct? : %lu\n", digit);
    printf("y/n?");
    printf(""); 
    scanf(" %c", &confirm); // because \n of prev one causes logic bug
    if (confirm == 'n') {
     printf("Enter the number:\n");
     get_input();
    }
    }
    while(confirm == 'n');  

    return 0;
}

// Get input and ensure it is valid, to be used
// removes newline and handles input errors
// before calling check_basic() or other funcs
int get_input() {
char line[50];
fgets(line, sizeof(line), stdin);
line[strcspn(line, "\n")] = '\0'; // remove new-line
sscanf(line, "%lu", &digit);
/* digit = atoi(line); */ // using sscanf due for need for extensive input validation
return 0;
             }

                             

