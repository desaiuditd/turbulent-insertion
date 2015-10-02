/**
 * Here I'm defining a Doubly Linked List for integers
 * as I want to have dynamic array implementation for a very large set.
 * Which I will use in Insertion Sort Program.
 */


// Single Node Structure for a Linked List
struct node {
    // number to store
    int data;
    // address for next node
    struct node *next;
    // address for previous node
    struct node *prev;
}

// address for head node. Global Object.
struct node *head;

// get new node to save the data.
struct node * get_new_node( int value ) {
    struct node *new_node = (struct node *) malloc( sizeof( struct node ) );
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
}

// insert_at_head
void insert_at_head( int value ) {
    struct node *new_node = get_new_node( value );

    // if head is null, then list is empty. this is the first node. So assign the value of head and return.
    if ( head == NULL ) {
        head = new_node;
        return;
    }

    // linking of prev & next pointers
    head->prev = new_node;
    new_node->next = head;

    // since we are adding new node at the head, we will replace the new value of head.
    head = new_node;
}

// insert_at_tail
void insert_at_tail( int value ) {
    struct node *new_node = get_new_node( value );

    // if head is null, then list is empty. this is the first node. So assign the value of head and return.
    if ( head == NULL ) {
        head = new_node;
        return;
    }

    struct node *temp = head;

    while ( temp->next != NULL ) temp = temp->next;     // This loop will take 'temp' to the end of the list

    // linking of prev & next pointers
    temp->next = new_node;
    new_node->prev = temp;

    // there's no need to do anything else as we have already added the new node at the tail.
}

// insert_at_position
void insert_at_position( int position, int value ) {

    if ( head == NULL ) {
        struct node *new_node = get_new_node( value );
        head = new_node;
        return;
    }

    if ( position == 1 ) {
        insert_at_head( value );
        return;
    } else {

        struct node *temp = head;
        int i = 1;
        while ( temp->next != NULL && i != position - 1 )  {    // This loop will take 'temp' to the value of position
            temp = temp->next;
            i++;
        }

        // temp is at position-1 value. one node before the needed position.
        struct node *new_node = get_new_node( value );
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp-> next = new_node;
    }
}

// remove_from_position
void remove_from_position( int position ) {
    int i = 1;
    struct node *temp = head;
    while ( temp->next != NULL && i != position - 1 ) {     // This loop will take 'temp' to the value of position
        temp = temp->next;
        i++;
    }

    // temp is at position-1 value. one node before the needed position.
    stuct node *removal = temp->next;
    removal->next->prev = temp;
    temp->next = removal->next;

    free( removal );
}

// print
void print_list() {
    struct node *temp = head;
	while( temp != NULL ) {
		printf( "%d ", temp->data );
		temp = temp->next;
	}
	printf( "\n" );
}

// sort - insertion sort
void sort_list() {

}
