/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:44:56 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 06:30:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdbool.h>
# include "LIBFT/ternary.h"

/////////////////////////////////////////////////////////////
////////////     Minimum vector interface     ///////////////
/////////////////////////////////////////////////////////////

/**
 * @section This session describes the minimum interface to extend the use of
 * the vector data structure. The minimum interface consists of 5 functions,
 * each with a very clear goal in mind. To illustrate the use of this interface,
 * I would use create an imaginary implementation of a stack data structure,
 * each function corresponds to a function in the vector interface:
 * 
 * 1. stack_init (ft_vector_init) - How to initialize the data structure?
 * 2. stack_pop (ft_vector_get) - How to get element from the data structure?
 * 3. stack_push (ft_vector_set) - How to set element to the data structure?
 * 4. stack_resize (ft_vector_resize) - How to resize the data structure?
 * 5. stack_free (ft_vector_free) - How to free the data structure?
 * 
 * Furthermore, the function return types specified what should you be expecting
 * from the function:
 * 
 * - Returns void: The function never fails.
 * - Returns int: The function might fail, and will return EXIT_FAILURE when it
 * fails.
 * - Returns void *: Not only the function might fail, but it also returns a
 * pointer to the data that is stored with the data structure. When the function
 * fails, it will return NULL.
 * - Returns bool: The function checks some properties of the data structure.
*/

/**
 * @brief A vector copier is an assigment function to assign the value of
 * an item to the another item. It is equvalent to the assignment operator in
 * c++. Since the vector is a generic data structure, it needs to know how to
 * assign the value of an item to another item. When a vector needs to resize or
 * do insertion, it needs to copy the value of the items to the new buffer.
 * While using memcpy is a valid option, it is a very inefficient way to copy
 * items.
*/
typedef void	(*t_ft_vector_item_copier)(void *dest, void *src);

/**
 * @brief A vector is a dynamic array. It handles the memory allocation and
 * reallocation when the user want to expand the array. It is similar to the
 * std::vector in c++. When the array is full, it will automatically resize
 * itself to accomodate more items.
 * 
 * @param buffer The array that holds the items.
 * @param item_size The size of each item in the vector.
 * @param size The number of items in the vector.
 * @param capacity The number of items that the vector can hold.
 * @param copier The function that assigns the value of an item to another item.
*/
typedef struct s_ft_vector
{
	void					*buffer;
	size_t					item_size;
	size_t					size;
	size_t					capacity;
	t_ft_vector_item_copier	copier;
}				t_ft_vector;

int		ft_vector_init(t_ft_vector *vector, size_t item_size, \
size_t capacity, t_ft_vector_item_copier copier);

/**
 * @return The item at the given index.
*/
void	*ft_vector_get(const t_ft_vector *vector, size_t index);

/**
 * @brief Set a given data at an index of the vector.
 * @return The given data.
*/
void	*ft_vector_set(t_ft_vector *vector, size_t index, void *data);

int		ft_vector_resize(t_ft_vector *vector);

void	ft_vector_free(t_ft_vector *vector);

/////////////////////////////////////////////////////////
////////////     Additional interface     ///////////////
/////////////////////////////////////////////////////////

/**
 * @section Additional interface that is specific to the target data structure.
 * Since vector itself is a generic data structure, its additional interface
 * only includes very basic operations that might only be useful if the user
 * uses vector directly.
 * 
*/

/**
 * @brief Append the given data to the end of the vector.
 * @return The given data.
*/
void	*ft_vector_append(t_ft_vector *vector, void *data);

/**
 * @brief Insert the given data to the given index of the vector.
 * @return The given data.
*/
void	*ft_vector_insert(t_ft_vector *vector, void *data, size_t index);

int		ft_vector_remove(t_ft_vector *vector, size_t index);

//////////////////////////////////////////////////
////////////     Utilities kit     ///////////////
//////////////////////////////////////////////////

/**
 * @brief The following is a list of default vector_setter that is so
 * common that it is included in the utilities kit:
 * 
 * - ft_vector_copy_char: copier for a vector that stores char.
 * - ft_vector_copy_string: copier for a vector that stores string.
 * - ft_vector_copy_ptr: copier for a vector that stores pointer.
 * - ft_vector_copy_int: copier for a vector that stores int.
*/

void	ft_vector_copy_char(void *buffer, void *character);

void	ft_vector_copy_string(void *buffer, void *string);

void	ft_vector_copy_ptr(void *buffer, void *ptr);

void	ft_vector_copy_int(void *buffer, void *integer);

/**
 * @brief The following is two utility functions that helps you build your own
 * additional interface for your data structure.
*/

/**
 * @brief Select all the elements from a given index in the vector,
 * and move them to the given index.
*/
void	ft_vector_buffer_shift(t_ft_vector *vector, size_t to, size_t from);

/**
 * @brief Copy a given amount of data from the given buffer,
 * to the vector buffer at a given index.
*/
void	ft_vector_buffer_copy_from(t_ft_vector *vector, void *buffer, \
size_t index, size_t copy_amount);

/////////////////////////////////////////////
////////      vector iterator      //////////
/////////////////////////////////////////////

# define VECTOR_ITERATOR_RIGHT_END TERNARY_TRUE
# define VECTOR_ITERATOR_LEFT_END TERNARY_UNKNOWN
# define VECTOR_ITERATOR_NOT_END TERNARY_FALSE

/**
 * @brief A vector iterator is an iterator that iterates through the vector.
*/
typedef struct s_ft_vector_iterator
{
	const t_ft_vector	*vector;
	size_t				index;
	void				*current;
	t_ternary			is_end;
}				t_ft_vector_iterator;

void	ft_vector_iterator_begin(t_ft_vector_iterator *iterator, \
const t_ft_vector *vector);

void	ft_vector_iterator_end(t_ft_vector_iterator *iterator, \
const t_ft_vector *vector);

int		ft_vector_iterator_next(t_ft_vector_iterator *iterator);

int		ft_vector_iterator_prev(t_ft_vector_iterator *iterator);

bool	ft_vector_iterator_has_next(const t_ft_vector_iterator *iterator);

bool	ft_vector_iterator_has_prev(const t_ft_vector_iterator *iterator);

void	*ft_vector_iterator_current(t_ft_vector_iterator *iterator);

#endif