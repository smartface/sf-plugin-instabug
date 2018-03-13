/**
 * This represents a fast static list, for lack of a better name.
 *
 * Given a NULL-terminated array of strings, the corresponding
 * FastARray is one that takes logarithmic time for lookups, except
 * for the first lookup, (n+1)(log(n)).
 *
 * The way this works is that the array is first unsorted and is of unknown
 * length. During the first lookup, the array length is calculated, the
 * array is sorted in-place and the lookup is performed with binary search.
 * Subsequent lookups will continue to use binary search, given that the
 * array didn't change.
 *
 * If an array element is modified or if the array length is modified,
 * behaviour is undefined.
 */

#ifndef __FAST_ARRAY_HDR__
#define __FAST_ARRAY_HDR__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct fast_array FastArray;

/**
 * Creates a new unsorted fast array of unknown length.
 */
FastArray* newFastArray (char**);

/**
 * For the first run of this function, a traversal occurs until NULL is found.
 * The resulting count is stored internally for later retreival in subsequent calls.
 */
int fastArrayLength (FastArray*);

/**
 * If the enclosed array is of known length and sorted, a binary search is performed
 * to check for the existence of the given string.
 */
int fastArrayExists(FastArray*, const char*);

/**
 * Runs the function, f, on every element of the array.
 */
void fastArrayForEach (FastArray*, void (*f)(char*));

/**
 * Returns the underlying array, please don't mutate it.
 */
char** fastArrayContents(FastArray*);

#ifdef __cplusplus
}
#endif

#endif
