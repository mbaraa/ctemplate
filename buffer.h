#ifndef _BUFFER_H
#define _BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t size;
  size_t capacity;
} buffer;

/**
 * @brief Creates a new Buffer with the specified initial capacity.
 *
 * @param initial_capacity The initial capacity of the buffer.
 * @return A pointer to the newly created Buffer, or NULL on allocation failure.
 */
buffer *buffer_create(size_t initial_capacity);

/**
 * @brief Destroys the Buffer and frees its allocated memory.
 *
 * @param buffer The Buffer to destroy.
 */
void buffer_destroy(buffer *buf);

/**
 * @brief Writes data to the Buffer.
 *
 * If the buffer does not have enough capacity, it will be reallocated.
 *
 * @param buffer The Buffer to write to.
 * @param data A pointer to the data to write.
 * @param len The length of the data to write.
 * @return 0 on success, -1 on reallocation failure.
 */
int buffer_write(buffer *buf, const char *data, size_t len);

/**
 * @brief Writes a single byte to the Buffer.
 *
 * If the buffer does not have enough capacity, it will be reallocated.
 *
 * @param buffer The Buffer to write to.
 * @param byte The byte to write.
 * @return 0 on success, -1 on reallocation failure.
 */
int buffer_write_byte(buffer *buffer, char byte);

/**
 * @brief Reads data from the Buffer.
 *
 * Reads up to 'len' bytes from the buffer into the destination 'dest'.
 *
 * @param buffer The Buffer to read from.
 * @param dest A pointer to the destination where the data will be written.
 * @param len The maximum number of bytes to read.
 * @return The number of bytes actually read.
 */
size_t buffer_read(buffer *buf, char *dest, size_t len);

/**
 * @brief Resets the Buffer, clearing its contents.
 *
 * @param buffer The Buffer to reset.
 */
void buffer_reset(buffer *buf);

/**
 * @brief Returns a pointer to the underlying data of the Buffer.
 *
 * @param buffer The Buffer.
 * @return A pointer to the buffer's data.
 */
char *buffer_data(buffer *buf);

/**
 * @brief Returns the current size of the Buffer.
 *
 * @param buffer The Buffer.
 * @return The current size of the buffer in bytes.
 */
size_t buffer_size(buffer *buf);

/**
 * @brief Frees the given pointer, and sets it to null to prevent usage after
 * being freed.
 */
void safe_free(void *ptr);

#endif // !_BUFFER_H
