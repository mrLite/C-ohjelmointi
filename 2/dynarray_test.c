#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int main(void) {
	printf("Ex. 14. Create and destroy a dyn_array.\n");
	dyn_array* arr = create();
	destroy(arr);
	printf("End of ex. 14\n");
	
	printf("Ex. 15. Append 100 elements to the dyn_array.\n");
	dyn_array* arr2 = create();
	for(int i = 0; i < 100; i++) {
		append(arr2, i);
	}
	printf("End of ex. 15\n");
	
	int ret = get(arr2, 66);
	printf("%d\n", ret);
	destroy(arr2);
	return EXIT_SUCCESS;
}