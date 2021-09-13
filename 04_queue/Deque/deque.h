#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include "double_linked_list.h"

t_bool	insertHead(List* dq, Node* node);
Node	*deleteHead(List* dq);
t_bool	insertRear(List* dq, Node* node);
Node	*deleteRear(List* dq);

#endif
