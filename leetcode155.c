#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct {
  int top;
  int min;
  int size;
  int* stack;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* p = malloc(sizeof(MinStack));
    p->top = 0;
    p->min = INT_MAX;
    p->size = maxSize;
    p->stack = malloc(sizeof(int)*maxSize);
    return p;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top == obj->size)
        return;
    obj->stack[(obj->top)++] = x;
    if (obj->min > x)
        obj->min = x;
}

void minStackPop(MinStack* obj) {
    if (obj->top == 0)
        return;
    if (obj->min == obj->stack[(obj->top)-1]) {
            obj->min = INT_MAX;
            for (int i = 0; i < (obj->top)-1; i++) {
	                if (obj->min > obj->stack[i])
	                    obj->min = obj->stack[i];
	            }
        }
    (obj->top)--;
}

int minStackTop(MinStack* obj) {
    return obj->top > 0? obj->stack[(obj->top)-1] :-1;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}

int main()
{
  return 0;
}
