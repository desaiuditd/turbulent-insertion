//
//  insertion-sort-c.c
//  Insertion Sort
//
//  Created by Cap'n Jacky on 30/09/15.
//
//

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "linked-list.h"

int main() {
	// initializing head pointer with null;
	head = NULL;

	int n, i, limit;

	printf( "\nFor how many numbers you want to run this Insertion Sort algorithm ?" );
	printf( "\nTo get enough verifiable statistical numbers, enter sufficiently large number.\nEnter the number: " );

	scanf( " %d", &n );

	printf("\nGenerating %d random numbers to test the Insertion Sort algorithm ....\n\n", n );

	// if total numbers are n then program will generate random numbers of n digits each.

	for( i = 1; i <= n; i++ ) {
		limit = (int) pow( 10, n );
		limit -= 1;
		insert_at_tail( rand() % limit );
	}

	printf( "Unsorted Array is generated. Now array is getting sorted with Insertion Sort ....\n\n" );

	time_t start,end;
	double diff;

	time( &start );

	// sort the numbers in the list
	sort_list();

	time( &end );
	diff = difftime( end, start );

	printf( "The array is sorted!\n" );

	printf( "It took %.4lf seconds to sort the array.\n", diff );
}
