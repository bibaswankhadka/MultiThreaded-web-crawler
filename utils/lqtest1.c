/* lqtest1.c --- 
 * 
 * 
 * Author: Jack F. Vasu
 * Created: Mon Nov  4 16:59:27 2019 (-0500)
 * Version: 
 * 
 * Description: 
 * 
 */
#include "locked-queue.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("making a LQ, testing put and get\n");
	lqueue_t* locked = lqopen();
	printf("putting an element in lockedQ\n");
	int x = 2;
	int* ptr = &x;
	lqput(locked, ptr);
	printf("putting another element in lockedQ\n");
	int y = 2;
	int* ptr2 = &y;
	lqput(locked, ptr2);
	printf("getting elements \n");
	int* z = lqget(locked);
	printf("first element is %p\n",(void*)z);
	int* j = lqget(locked);
	printf("second element is %p\n",(void*)j);
	if (j == NULL || z == NULL){
		exit(EXIT_FAILURE);
	}
	lqclose(locked);
	exit(EXIT_SUCCESS);
}
