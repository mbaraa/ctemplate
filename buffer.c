#include "buffer.h"
#include <string.h>

buffer *buffer_create(size_t initial_capacity) {
  buffer *buf = malloc(sizeof(buffer));
  if (buf == NULL) {
    return NULL;
  }
  buf->data = malloc(initial_capacity);
  if (buf->data == NULL) {
    safe_free(buf);
    return NULL;
  }
  buf->index = 0;
  buf->capacity = initial_capacity;
  return buf;
}

void buffer_destroy(buffer *buf) {
  safe_free(buf->data);
  safe_free(buf);
}

int buffer_write(buffer *buf, const char *data, size_t len) {
  if (buf->index + len > buf->capacity) {
    size_t new_capacity = buf->capacity * 2;
    if (new_capacity < buf->index + len) {
      new_capacity = buf->index + len;
    }
    char *new_data = realloc(buf->data, new_capacity);
    if (new_data == NULL) {
      return -1;
    }
    buf->data = new_data;
    buf->capacity = new_capacity;
  }
  memcpy(buf->data + buf->index, data, len);
  buf->index += len;
  return 0;
}

/**
 * @brief Writes a single byte to the Buffer.
 *
 * If the buffer does not have enough capacity, it will be reallocated.
 *
 * @param buffer The Buffer to write to.
 * @param byte The byte to write.
 * @return 0 on success, -1 on reallocation failure.
 */
int buffer_write_byte(buffer *buf, char byte) {
  if (buf->index + 1 > buf->capacity) {
    size_t new_capacity = buf->capacity * 2;
    if (new_capacity < buf->index + 1) {
      new_capacity = buf->index + 1;
    }
    char *new_data = realloc(buf->data, new_capacity);
    if (new_data == NULL) {
      return -1;
    }
    buf->data = new_data;
    buf->capacity = new_capacity;
  }
  buf->data[buf->index] = byte;
  buf->index += 1;
  return 0;
}

size_t buffer_read(buffer *buf, char *dest, size_t len) {
  size_t bytes_to_read = (len > buf->index) ? buf->index : len;
  memcpy(dest, buf->data, bytes_to_read);
  memmove(buf->data, buf->data + bytes_to_read, buf->index - bytes_to_read);
  buf->index -= bytes_to_read;
  return bytes_to_read;
}

void buffer_reset(buffer *buf) {
  buf->index = 0;
  memset(buf->data, 0, buf->capacity);
}

char *buffer_data(buffer *buf) {
  char *data = (char *)malloc(buf->index);
  strncpy(data, buf->data, buf->index);
  return data;
}

size_t buffer_size(buffer *buf) { return buf->index; }

void safe_free(void *ptr) {
  free(ptr);
  ptr = NULL;
}
