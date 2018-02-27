/*
 * nqmtt_atomic.h
 *
 *  Created on: Sep 15, 2015
 *      Author: a
 */

#ifndef NQMTT_ATOMIC_H_
#define NQMTT_ATOMIC_H_

/*__ATOMIC_RELAXED
No barriers or synchronization.
__ATOMIC_CONSUME
Data dependency only for both barrier and synchronization with another thread.
__ATOMIC_ACQUIRE
Barrier to hoisting of code and synchronizes with release (or stronger) semantic stores from another thread.
__ATOMIC_RELEASE
Barrier to sinking of code and synchronizes with acquire (or stronger) semantic loads from another thread.
__ATOMIC_ACQ_REL
Full barrier in both directions and synchronizes with acquire loads and release stores in another thread.
__ATOMIC_SEQ_CST
Full barrier in both directions and synchronizes with acquire loads and release stores in all threads.
*/

/*— Built-in Function: type __atomic_load_n (type *ptr, int memmodel)
This built-in function implements an atomic load operation. It returns the contents of *ptr.*/
#define atomic_load_n(ptr) (__atomic_load_n(ptr, __ATOMIC_SEQ_CST))


/*— Built-in Function: void __atomic_load (type *ptr, type *ret, int memmodel)
This is the generic version of an atomic load. It returns the contents of *ptr in *ret.*/
#define atomic_load(ptr,ret) (__atomic_load(ptr, ret,  __ATOMIC_SEQ_CST))

/*— Built-in Function: void __atomic_store_n (type *ptr, type val, int memmodel)
This built-in function implements an atomic store operation. It writes val into *ptr.*/
#define atomic_store_n(ptr,val) (__atomic_load(ptr, val, __ATOMIC_SEQ_CST))


/*— Built-in Function: void __atomic_store (type *ptr, type *val, int memmodel)
This is the generic version of an atomic store. It stores the value of *val into *ptr.*/
#define atomic_store(ptr,val) (__atomic_store(ptr, val, __ATOMIC_SEQ_CST))

/*— Built-in Function: type __atomic_exchange_n (type *ptr, type val, int memmodel)
This built-in function implements an atomic exchange operation. It writes val into *ptr, and returns the previous contents of *ptr.*/
#define atomic_exchange_n(ptr,val) (__atomic_exchange_n(ptr, val, __ATOMIC_SEQ_CST))


/*— Built-in Function: void __atomic_exchange (type *ptr, type *val, type *ret, int memmodel)
This is the generic version of an atomic exchange. It stores the contents of *val into *ptr. The original value of *ptr is copied into *ret.*/
#define atomic_exchange(ptr,val,ret) (__atomic_exchange_n(ptr, val, ret, __ATOMIC_SEQ_CST))


/*— Built-in Function: bool __atomic_compare_exchange_n (type *ptr, type *expected, type desired, bool weak, int success_memmodel, int failure_memmodel)
This built-in function implements an atomic compare and exchange operation. This compares the contents of *ptr with the contents of *expected and if equal, writes desired into *ptr.
If they are not equal, the current contents of *ptr is written into *expected. weak is true for weak compare_exchange, and false for the strong variation.
Many targets only offer the strong variation and ignore the parameter. When in doubt, use the strong variation.
True is returned if desired is written into *ptr and the execution is considered to conform to the memory model specified by success_memmodel. There are no restrictions on what memory model can be used here.
False is returned otherwise, and the execution is considered to conform to failure_memmodel. This memory model cannot be __ATOMIC_RELEASE nor __ATOMIC_ACQ_REL. It also cannot be a stronger model than that specified by success_memmodel.*/

/*— Built-in Function: bool __atomic_compare_exchange (type *ptr, type *expected, type *desired, bool weak, int success_memmodel, int failure_memmodel)
This built-in function implements the generic version of __atomic_compare_exchange. The function is virtually identical to __atomic_compare_exchange_n, except the desired value is also a pointer.*/



/*These built-in functions perform the operation suggested by the name, and return the result of the operation. That is,

          { *ptr op= val; return *ptr; }
.*/

/*— Built-in Function: type __atomic_add_fetch (type *ptr, type val, int memmodel)*/
#define atomic_add(ptr,val) (__atomic_add_fetch(ptr, val, __ATOMIC_SEQ_CST))

/*— Built-in Function: type __atomic_sub_fetch (type *ptr, type val, int memmodel)*/
#define atomic_sub(ptr,val) (__atomic_sub_fetch(ptr, val, __ATOMIC_SEQ_CST))

/*— Built-in Function: type __atomic_and_fetch (type *ptr, type val, int memmodel)*/
#define atomic_and(ptr,val) (__atomic_and_fetch(ptr, val, __ATOMIC_SEQ_CST))

/*— Built-in Function: type __atomic_xor_fetch (type *ptr, type val, int memmodel)*/
#define atomic_xor(ptr,val) (__atomic_xor_fetch(ptr, val, __ATOMIC_SEQ_CST))

/*— Built-in Function: type __atomic_or_fetch (type *ptr, type val, int memmodel)*/
#define atomic_or(ptr,val) (__atomic_or_fetch(ptr, val, __ATOMIC_SEQ_CST))

/*— Built-in Function: type __atomic_nand_fetch (type *ptr, type val, int memmodel)*/
#define atomic_nand(ptr,val) (__atomic_nand_fetch(ptr, val, __ATOMIC_SEQ_CST))




/*— Built-in Function: type __atomic_fetch_add (type *ptr, type val, int memmodel)*/
/*— Built-in Function: type __atomic_fetch_sub (type *ptr, type val, int memmodel)*/
/*— Built-in Function: type __atomic_fetch_and (type *ptr, type val, int memmodel)*/
/*— Built-in Function: type __atomic_fetch_xor (type *ptr, type val, int memmodel)*/
/*— Built-in Function: type __atomic_fetch_or (type *ptr, type val, int memmodel)*/
/*— Built-in Function: type __atomic_fetch_nand (type *ptr, type val, int memmodel)*/
/*These built-in functions perform the operation suggested by the name, and return the value that had previously been in *ptr. That is,

          { tmp = *ptr; *ptr op= val; return tmp; }
.*/

/*— Built-in Function: bool __atomic_test_and_set (void *ptr, int memmodel)
This built-in function performs an atomic test-and-set operation on the byte at *ptr.
The byte is set to some implementation defined nonzero “set” value and the return value is true if and only if the previous contents were “set”.
 It should be only used for operands of type bool or char. For other types only part of the value may be set.*/


/*— Built-in Function: void __atomic_clear (bool *ptr, int memmodel)
This built-in function performs an atomic clear operation on *ptr. After the operation, *ptr contains 0.
It should be only used for operands of type bool or char and in conjunction with __atomic_test_and_set.
 For other types it may only clear partially. If the type is not bool prefer using __atomic_store.*/


/*— Built-in Function: void __atomic_thread_fence (int memmodel)
This built-in function acts as a synchronization fence between threads based on the specified memory model.*/


/*— Built-in Function: void __atomic_signal_fence (int memmodel)
This built-in function acts as a synchronization fence between a thread and signal handlers based in the same thread.*/


/*— Built-in Function: bool __atomic_always_lock_free (size_t size, void *ptr)
This built-in function returns true if objects of size bytes always generate lock free atomic instructions for the target architecture.
size must resolve to a compile-time constant and the result also resolves to a compile-time constant.

ptr is an optional pointer to the object that may be used to determine alignment. A value of 0 indicates typical alignment should be used. The compiler may also ignore this parameter.

          if (_atomic_always_lock_free (sizeof (long long), 0))
— Built-in Function: bool __atomic_is_lock_free (size_t size, void *ptr)
This built-in function returns true if objects of size bytes always generate lock free atomic instructions for the target architecture. If it is not known to be lock free a call is made to a runtime routine named __atomic_is_lock_free.

ptr is an optional pointer to the object that may be used to determine alignment. A value of 0 indicates typical alignment should be used. The compiler may also ignore this parameter.
*/
#endif /* NQMTT_ATOMIC_H_ */
