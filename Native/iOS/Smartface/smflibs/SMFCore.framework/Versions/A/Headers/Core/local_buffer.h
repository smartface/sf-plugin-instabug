//
// This implements automatic refcounting for a heap block of memory.
//
// The use case is for passing some heap block without worrying about
// which scope *should* be freeing the block. If you decide to pass
// pointers to the block, you are possibly doing the wrong thing because
// the whole point is to use this as a stack variable and get the automatic
// benefits of the copy constructor and the scope destructor.
//
// When a block is passed by value, the copy constructor is
// called and that increases the reference count for the block.
//
// Once a block's scope exits, the destructor of stack values is
// automatically called, thereby decreasing the reference count.
//
// When there are 0 references to a block, the memory is freed.
//
// This is not a thread-safe implementation.
// For a thread-safe implementation, please use LocalBuffer_R not included here.
//
// Author: ewanas
//

#ifndef __LOCAL_BUFFER_HDR__
#define __LOCAL_BUFFER_HDR__

#include <stdio.h>
#include <stdlib.h>

#ifdef BUFFER_DEBUGGING
#include <assert.h>
#undef NDEBUG
#define buflog(msg...) (printf("BUFFER LOG: ") && printf(msg))
#define buffail(msg...) (printf("BUFFER ERROR: ") && printf(msg)); assert(false)
#else
#define buflog(msg...)
#define buffail(msg...)
#endif

template<typename T>
class LocalBuffer {
  private:
    unsigned int copies;

  public:
    T* internal;

		LocalBuffer(const LocalBuffer& b) : copies(b.copies), internal(b.internal) {
			copies = copies + 1;
			buflog ("Copied a buffer at %p. Copies are:%u\n", internal, copies);
		}

		~LocalBuffer() {
			if (copies == 0) {
				if (internal != NULL) {
					buflog ("Freeing buffer at %p\n", internal);
					delete[] internal;
				} else {
					buffail ("Deleting a buffer reference that points to NULL memory");
				}
			} else {
				buflog ("Didn't destroy the heap memory at %p yet, there are %u copies\n", internal, copies);
			}

			copies--;
		}

    LocalBuffer(unsigned int size) {
      internal = new T[size];

      if (internal == NULL) {
        buffail ("Couldn't allocate memory for a buffer");
      } else {
        buflog ("Created a buffer with size:%d at %p\n", size, internal);
        copies = 0;
      }
    }

		T* operator*() {
			return internal;
		}
};

#endif
