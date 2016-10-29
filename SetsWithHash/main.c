/* 
 * Abstract Data Structure whith Hash
 * @author: Gustavo Schwantz Oliveira
 *
 * See hashset.c
 *
 */

#include <stdio.h>
#include "hashset.h"

void menu ();

int main(int argc, char const *argv[])
{
	menu ();
	return 0;
}

void menu ()
{
	char option;
	int input0, input1;

	do {
		
        printf("CHOOSE A OPTION:\n");
        printf("c. create a set\n");
        printf("i. insert a element in a set\n");
        printf("v. verify if a element is in a set\n");
        printf("d. delete a element of a set\n");
        printf("j. join two sets\n");
        printf("l. list the elements of a set\n");
        printf("e. finish the program\n");
        printf("option: ");
        scanf (" %c", &option);

        switch (option) {

        	case 'c':
        	    printf("\n%d\n\n", create ());
        	    break;

        	case 'i':
        	    printf("Enter with a set: ");
        	    scanf (" %d", &input0);
        	    printf("Enter with a element: ");
        	    scanf (" %d", &input1);
        	    printf("\n%d\n\n", insert (input1, input0));
        	    break;    

            case 'v':
                printf("Enter with a set: ");
        	    scanf (" %d", &input0);
        	    printf("Enter with a element: ");
        	    scanf (" %d", &input1);
        	    printf("\n%d\n\n", verify (input1, input0));
        	    break;
            
            case 'd':
                printf("Enter with a set: ");
        	    scanf (" %d", &input0);
        	    printf("Enter with a element: ");
        	    scanf (" %d", &input1);
        	    printf("\n%d\n\n", delete (input1, input0));
        	    break;
            
            case 'j':
                printf("Enter with a set: ");
        	    scanf (" %d", &input0);
        	    printf("Enter with a another set: ");
        	    scanf (" %d", &input1);
        	    printf("\n%d\n\n", join (input0, input1));
        	    break;

        	case 'l':
        	    printf("Enter with a set: ");
        	    scanf (" %d", &input0);
        	    printf("\n");
        	    list (input0);
        	    printf("\n\n");
        	    break;

        	case 'e':
        	    end ();
        	    break;

        	default:
        	    printf("\nINVALID INPUT! TRY AGAIN.\n\n");    
        	    break;
        }

	} while (option != 'e');

}