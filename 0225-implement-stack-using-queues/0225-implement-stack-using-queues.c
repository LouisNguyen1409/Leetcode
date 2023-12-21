typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
} Queue;

typedef struct stack {
    Queue* q1;
    Queue* q2;
} MyStack;

Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->val = value;
    node->next = NULL;
    return node;
}

MyStack* myStackCreate() {
    Queue* q1 = malloc(sizeof(Queue));
    q1->head = NULL;
    q1->tail = NULL;
    Queue* q2 = malloc(sizeof(Queue));
    q2->head = NULL;
    q2->tail = NULL; 
    MyStack* newStack = malloc(sizeof(MyStack));
    newStack->q1 = q1;
    newStack->q2 = q2;
    return newStack;
}

void myStackPush(MyStack* obj, int x) {
    Node* node = newNode(x);
    if (obj->q1->head == NULL) {
        obj->q1->head = node;
        node->next = obj->q2->head;
        obj->q1->tail = obj->q2->tail;
        obj->q2->head = NULL;
        obj->q2->tail = NULL;
    } else {
        obj->q2->head = node;
        node->next = obj->q1->head;
        obj->q2->tail = obj->q1->tail;
        obj->q1->head = NULL;
        obj->q1->tail = NULL;
    }
}

bool myStackEmpty(MyStack* obj) {
    if (obj->q1->head == NULL && obj->q2->head == NULL) {
        return true;
    }
    return false;
}

int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj)) {
        return NULL;
    } else if (obj->q1->head == NULL) {
        int val = obj->q2->head->val;
        Node* temp = obj->q2->head;
        obj->q2->head = obj->q2->head->next;
        free(temp);
        return val;
    } else {
        int val = obj->q1->head->val;
        Node* temp = obj->q1->head;
        obj->q1->head = obj->q1->head->next;
        free(temp);
        return val;
    }
}

int myStackTop(MyStack* obj) {
    if (myStackEmpty(obj)) {
        return NULL;
    } else if (obj->q1->head == NULL) {
        int val = obj->q2->head->val;
        return val;
    } else {
        int val = obj->q1->head->val;
        return val;
    }
}

void myStackFree(MyStack* obj) {
    if (myStackEmpty(obj)) {
        free(obj);
    } else if (obj->q1->head == NULL) {
        free(obj->q1);
        Node* curr = obj->q2->head;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        free(obj->q2);
        free(obj);
    } else {
        free(obj->q2);
        Node* curr = obj->q1->head;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        free(obj->q1);
        free(obj);
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/