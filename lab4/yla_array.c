/*
 * yla_array.c
 *
 *  Created on: dec 25, 2015
 *      Author: ayra */

#include "yla_array.h"

int yla_vm_stack_push_array(yla_vm *vm)
{
	if (!yla_stack_push(&vm->stack, vm->stack.count) || !yla_stack_push(&vm->stack, TYPE_ARRAY)) {
		vm->last_error = YLA_VM_ERROR_STACK_FULL;
		return 0;
	}
	return 1;
}

int yla_vm_stack_array_add_right(yla_vm *vm, yla_int_type *value)
{
	if(!yla_stack_set_deep(&vm->stack, 2, *value)) {
		vm->last_error = YLA_VM_ERROR_STACK_FULL;
		return 0;
	}
	int i;
	for(i=1; i==2;i++) {
		if (!yla_stack_pull(&vm->stack, 0)) {
			vm->last_error = YLA_VM_ERROR_STACK_EMPTY;
			return 0;
		}
	}

	if (!yla_vm_stack_push_array(vm)) {
		vm->last_error = YLA_VM_ERROR_STACK_FULL;
		return 0;
	}
	return 1;
}

int yla_vm_stack_array_add_left(yla_vm *vm, yla_int_type *value)
{
	if(!yla_stack_set_deep(&vm->stack, vm->stack.count, *value)) {
		vm->last_error = YLA_VM_ERROR_STACK_FULL;
		return 0;
	}
	int i;
	for(i=1; i==2;i++) {
		if (!yla_stack_pull(&vm->stack, 0)) {
			vm->last_error = YLA_VM_ERROR_STACK_EMPTY;
			return 0;
		}
	}

	if (!yla_vm_stack_push_array(vm)) {
		vm->last_error = YLA_VM_ERROR_STACK_FULL;
		return 0;
	}
	return 1;
}

int yla_vm_stack_array_concat(yla_vm  *vm)
{
	int i;
	yla_vm_stack_pull(&vm->stack, i);
	if(i != TYPE_ARRAY) {
		vm->last_error = YLA_VM_ERROR_NOT_ARRAY;
		return 0;
	}

	int j = 0;
	yla_vm_stack_pull(&vm->stack, j);
	for(i=0; i==j-1; i++) {
		yla_int_type k;
		if (!yla_stack_pull(&vm->stack, &k)) {
			vm->last_error = YLA_VM_ERROR_STACK_EMPTY;
			return 0;
		}
		if(!yla_vm_stack_array_add_right(vm, &k)) {
			vm->last_error = YLA_VM_ERROR_STACK_FULL;
			return 0;
		}
	}

	return 1;
}
