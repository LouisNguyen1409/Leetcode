typedef struct node {
    int val;
    struct node* pre;
    struct node* next;
} Node;

typedef struct stack {
    Node* tail;
} Stack;

Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->val = value;
    node->next = NULL;
    node->pre = NULL;
    return node;
}
Stack* newStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->tail = NULL;
    return stack;
}

void push(Stack* obj, int value) {
    Node* new = newNode(value);
    if (obj->tail == NULL) {
        obj->tail = new;
        return;
    }
    new->pre = obj->tail;
    obj->tail->next = new;
    obj->tail = new;
}

int pop(Stack* obj) {
    int temp = obj->tail->val;
    Node* tempNode = obj->tail;
    obj->tail = obj->tail->pre;
    if (obj->tail != NULL) {
        obj->tail->next = NULL;
    }
    free(tempNode);
    return temp;
}

bool isEmpty(Stack* obj) {
    if (obj->tail == NULL) {
        return true;
    }
    return false;
}

bool allOpen(int* rooms, int size) {
    for (int i = 0; i < size; i++) {
        if (rooms[i] == 0) {
            return false;
        }
    }
    return true;
}

void freeStack(Stack* obj) {
    if (!isEmpty(obj)) {
        Node* curr = obj->tail;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->pre;
            free(curr);
        }
    }
    free(obj);
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* openRooms = calloc(sizeof(int), roomsSize);
    openRooms[0] = 1;
    Stack* stack = newStack();
    for (int i = 0; i < roomsColSize[0]; i++) {
        push(stack, rooms[0][i]);
    }
    
    while (!allOpen(openRooms, roomsSize) && !isEmpty(stack)) {
        int temp = pop(stack);
        if (openRooms[temp] != 1) {
            openRooms[temp] = 1;
            for (int i = 0; i < roomsColSize[temp]; i++) {
                push(stack, rooms[temp][i]);
            }
        }
    }
    // freeStack(stack);
    return allOpen(openRooms, roomsSize);
}