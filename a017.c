/* structure and strcmp */
#include <stdio.h>
#include <string.h>

typedef struct{
	char name[10];
} human_being;

int main(){

	human_being person1, person2;

	strcpy( person1.name, "Sam");
	strcpy( person2.name, "Tom");

if ( strcmp (person1.name, person2.name) ){
	printf("The two people do not habe the same name\n");
}
else {
	printf("The two pelple have the same name\n");
}

	return 0;

}
