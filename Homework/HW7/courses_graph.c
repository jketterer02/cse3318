// Jacob Ketterer, 1001793039
//Program is meant to read data from a file, and create an adjacency matrix out of that file, which can then show the sorted vertexes

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void run()
{
    int c,i=0,j=0,k=0,line=0;
    const char delim[3] =" \n";
    char array[100][31], input[100];
    char *firstcourse, *course;
    FILE* inputfile;

    //reading user input for file name
    printf("\nEnter the name of the course file (.txt is included): ");
    scanf("%s",input);
    inputfile = fopen(input,"r");
    //error checking for fopen
    if (inputfile == NULL)
    {
        //error messaging
        printf("Could not open file %s. Exiting....\n", input);
        exit(-1);
    }
    
    //Counts the number of vertices in the graph
    while((c = fgetc(inputfile)) != EOF)
    {
        ungetc(c, inputfile);
        fgets(input,100,inputfile);
        k++;
    }
    printf("Number of vertices in built graph:  N = %d\n", k);

    //Resets the file back to the start
    fseek(inputfile, 0, SEEK_SET);
    //Getting first courses from file
    while((c = fgetc(inputfile)) != EOF)
    {
        ungetc(c, inputfile);
        fgets(input,100,inputfile);
        firstcourse = strtok(input, delim);
        strcpy(array[i], firstcourse);
        printf("Vertex %d - %s\n", i,array[i]);
        i++;
    }
    int ROW_COL_SIZE = i;
    //creating the adjacency matrix
    int adjmaxtrix[i][i];
    //zeroing the adjacency matrix
    for(i=0;i<ROW_COL_SIZE;i++)
    {
        for(j=0;j<ROW_COL_SIZE;j++)
        {
            adjmaxtrix[i][j] = 0;
        }
    }
    
    printf("\n");
    //Resets the file back to the start
    fseek(inputfile, 0, SEEK_SET);

    //populates the adjacency matrix with the dependencies
    while((c = fgetc(inputfile)) != EOF)
    {
        ungetc(c, inputfile);
        fgets(input,100,inputfile);
        course = strtok(input, delim);
        //printf("Current Line: %d\n", line);
        while(course!=NULL)
        {
            course = strtok(NULL,delim);
            if(course!=NULL)
            {
                for(i=0;i<ROW_COL_SIZE;i++)
                {
                    //printf("Current course: %s\n", course);
                    //printf("Array Value: %s\n", array[i]);
                    if(!strcmp(course,array[i]))
                    {
                        adjmaxtrix[i][line] = 1;
                    }
                }
            }
        }
        //line is current column for adjacency matrix
        line++;
    }
    
    //prints the Adjacency matrix in the specific format required
    printf("Adjacency matrix:\n");
    printf("   |");
    for(i=0;i<ROW_COL_SIZE;i++)
    {
        printf("%6d ", i);
    }
    printf("\n");
    for(i=0;i<(ROW_COL_SIZE*8);i++)
    {
        printf("-");
    }
    printf("\n");
    for(i=0;i<ROW_COL_SIZE;i++)
    {
        printf("%3d|", i);
        for(j=0;j<ROW_COL_SIZE;j++)
        {   
            printf("%6d ",adjmaxtrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fclose(inputfile);
    //not sure how to do topological sorting
}

int main()
{
	run();
}
