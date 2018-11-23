#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct my_Interval {
  int start;
  int end;
  struct my_Interval* next;
};

typedef struct {
  struct my_Interval* head;
} RangeModule;

RangeModule* rangeModuleCreate()
{
  RangeModule* obj = malloc(sizeof(RangeModule));
  obj->head = NULL;

  return obj;
}

void rangeModuleAddRange(RangeModule* obj, int left, int right)
{
  struct my_Interval* ptr;
  struct my_Interval* new;
  struct my_Interval* prev;

  if (obj->head == NULL) {
    obj->head = malloc(sizeof(struct my_Interval));
    obj->head->start = left;
    obj->head->end = right;
    obj->head->next = NULL;
    return;
  }

  ptr = obj->head;
  prev = NULL;
  new = malloc(sizeof(struct my_Interval));
  // Find the first interval which has intersection with new interval
  while (ptr != NULL && left > ptr->end) {
    prev = ptr;
    ptr = ptr->next;
  }

  if (ptr == NULL) {
    // No intersection, append to the tier
    new->start = left;
    new->end = right;
    new->next = NULL;
    prev->next = new;
  } else {
    if (right < ptr->start) {
      // No intersection, become the new head or insert into list.
      new->start = left;
      new->end = right;
      new->next = ptr;
      if (prev == NULL)
	obj->head = new;
      else
	prev->next = new;
    } else {
      // Insert into list, and delete all intervals which has intersection with.
      new->start = left < ptr->start? left: ptr->start;
      new->end = right > ptr->end? right: ptr->end;
      if (prev == NULL)
	obj->head = new;
      else
	prev->next = new;
      while (ptr != NULL && new->end > ptr->end) {
	prev = ptr;
	ptr = ptr->next;
	free(prev);
      }
      if (ptr != NULL && new->end >= ptr->start) {
	new->end = ptr->end;
	new->next = ptr->next;
	free(ptr);
      } else {
	new->next = ptr;
      }
    }
  }

  return;
}

bool rangeModuleQueryRange(RangeModule* obj, int left, int right)
{
  struct my_Interval* ptr = obj->head;
  while (ptr != NULL) {
    if (left >= ptr->start && right <= ptr->end)
      return true;
    ptr = ptr->next;
  }
  return false;
}

void rangeModuleRemoveRange(RangeModule* obj, int left, int right)
{
  struct my_Interval* ptr;
  struct my_Interval* new;
  struct my_Interval* prev;
  struct my_Interval* tmp;

  if (obj->head == NULL)
    return;

  ptr = obj->head;
  prev = NULL;
  // Find the first interval which has intersection with deletion interval
  while (ptr != NULL && left > ptr->end) {
    prev = ptr;
    ptr = ptr->next;
  }
  
  // Have intersection with deletion interval
  if (ptr != NULL && right > ptr->start) {
    // If deletion within current interval, split it.
    if (left > ptr->start) {
      new = malloc(sizeof(struct my_Interval));
      new->start = ptr->start;
      new->end = left;
      new->next = ptr;
      if (prev == NULL)
	obj->head = new;
      else
	prev->next = new;

      prev = new;
    }
    // Remove all intervals covered by deletion interval.
    while (ptr != NULL && right >= ptr->end) {
      tmp = ptr;
      ptr = ptr->next;
      free(tmp);
    }
    // The interval has partial intersection with deletion
    if (ptr != NULL && right > ptr->start)
      ptr->start = right;

    if (prev == NULL)
      obj->head = ptr;
    else
      prev->next = ptr;
  }
  return;
}

void rangeModuleFree(RangeModule* obj)
{
  struct my_Interval* ptr = obj->head;
  struct my_Interval* prev;

  while (ptr != NULL) {
    prev = ptr;
    ptr = ptr->next;
    free(prev);
  }
  free(obj);
}

int main()
{
  return 0;
}
