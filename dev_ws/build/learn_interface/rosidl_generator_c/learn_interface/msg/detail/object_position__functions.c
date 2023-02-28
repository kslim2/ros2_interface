// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from learn_interface:msg/ObjectPosition.idl
// generated code does not contain a copyright notice
#include "learn_interface/msg/detail/object_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
learn_interface__msg__ObjectPosition__init(learn_interface__msg__ObjectPosition * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
learn_interface__msg__ObjectPosition__fini(learn_interface__msg__ObjectPosition * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
learn_interface__msg__ObjectPosition__are_equal(const learn_interface__msg__ObjectPosition * lhs, const learn_interface__msg__ObjectPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
learn_interface__msg__ObjectPosition__copy(
  const learn_interface__msg__ObjectPosition * input,
  learn_interface__msg__ObjectPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

learn_interface__msg__ObjectPosition *
learn_interface__msg__ObjectPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  learn_interface__msg__ObjectPosition * msg = (learn_interface__msg__ObjectPosition *)allocator.allocate(sizeof(learn_interface__msg__ObjectPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(learn_interface__msg__ObjectPosition));
  bool success = learn_interface__msg__ObjectPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
learn_interface__msg__ObjectPosition__destroy(learn_interface__msg__ObjectPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    learn_interface__msg__ObjectPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
learn_interface__msg__ObjectPosition__Sequence__init(learn_interface__msg__ObjectPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  learn_interface__msg__ObjectPosition * data = NULL;

  if (size) {
    data = (learn_interface__msg__ObjectPosition *)allocator.zero_allocate(size, sizeof(learn_interface__msg__ObjectPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = learn_interface__msg__ObjectPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        learn_interface__msg__ObjectPosition__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
learn_interface__msg__ObjectPosition__Sequence__fini(learn_interface__msg__ObjectPosition__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      learn_interface__msg__ObjectPosition__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

learn_interface__msg__ObjectPosition__Sequence *
learn_interface__msg__ObjectPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  learn_interface__msg__ObjectPosition__Sequence * array = (learn_interface__msg__ObjectPosition__Sequence *)allocator.allocate(sizeof(learn_interface__msg__ObjectPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = learn_interface__msg__ObjectPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
learn_interface__msg__ObjectPosition__Sequence__destroy(learn_interface__msg__ObjectPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    learn_interface__msg__ObjectPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
learn_interface__msg__ObjectPosition__Sequence__are_equal(const learn_interface__msg__ObjectPosition__Sequence * lhs, const learn_interface__msg__ObjectPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!learn_interface__msg__ObjectPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
learn_interface__msg__ObjectPosition__Sequence__copy(
  const learn_interface__msg__ObjectPosition__Sequence * input,
  learn_interface__msg__ObjectPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(learn_interface__msg__ObjectPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    learn_interface__msg__ObjectPosition * data =
      (learn_interface__msg__ObjectPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!learn_interface__msg__ObjectPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          learn_interface__msg__ObjectPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!learn_interface__msg__ObjectPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
