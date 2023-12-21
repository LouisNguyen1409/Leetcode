typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int min;
} MinStack;

Node* newNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = value;
    return newNode;
}
MinStack* minStackCreate() {
    MinStack* newStack = malloc(sizeof(MinStack));
    newStack->top = NULL;
    return newStack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == NULL || (val < obj->min)) {
        obj->min = val;
    }
    Node* node = newNode(val);
    node->next = obj->top;
    obj->top = node;
}

void minStackPop(MinStack* obj) {
    Node* temp = obj->top;
    obj->top = obj->top->next;
    free(temp);
    if (obj->top == NULL) {
        return;
    }
    Node* curr = obj->top;
    obj->min = obj->top->val;
    while (curr != NULL) {
        if (curr->val < obj->min) {
            obj->min = curr->val;
            
        }
        curr = curr->next;
    }
}

int minStackTop(MinStack* obj) {
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    if (obj->top != NULL) {
        Node* curr = obj->top;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/