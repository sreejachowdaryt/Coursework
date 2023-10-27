#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
int number_of_records; 


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main()
{
    char filename [] = "FitnessData";
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        perror("");
        return 1;
    }
    
    char date[11];
	char time[6];
	int steps;
    FITNESS_DATA record;

    tokeniseRecord(",", ",", date, time, steps);

    printf("Type Date:");
    scanf("%s", date);

    printf("Type time:");
    scanf("%s", time);

    printf("Type steps:");
     scanf("%d", &steps);
    
    for (int i = 0; i < number_of_records; i++)
    {
        fprintf(file, "%s", date);
        fprintf(file, "%s", time);
        fprintf(file, "%d", steps);
    }
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL){
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;  
}




