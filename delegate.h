#ifndef __INCL_delegate_h
#define __INCL_delegate_h

/* This is a simple struct with a "void* obj" pointer and a function pointer.  
   You can pass structs like this to a function, and then that function can 
   "call you back" later by invoking the function pointer, passing the obj.  
   This is a way to get asynchronous notification of events that have happened 
   on the OPSEC mainloop. */
typedef struct {
	void* obj;
	void (*meth)(void*);
} delegate;

delegate* make_delegate(void*obj, void (*meth)(void*));
void invoke(delegate* f);

#endif /* #ifndef __INCL_delegate_h */
