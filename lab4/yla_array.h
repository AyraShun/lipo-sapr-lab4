/*
 * yla_array.h
 *
 *  Created on: Dec 25, 2015
 *      Author: aura
 */

#include "yla_vm.h"
#include "yla_stack.h"

#define TYPE_ARRAY 38454

#ifndef YLA_ARRAY_H_
#define YLA_ARRAY_H_

int yla_vm_stack_push_array(yla_vm *vm);
int yla_vm_stack_array_add_right(yla_vm *vm, yla_int_type *value);
int yla_vm_stack_array_add_left(yla_vm *vm, yla_int_type *value);
int yla_vm_stack_array_concat(yla_vm *vm);

#endif /* YLA_ARRAY_H_ */
