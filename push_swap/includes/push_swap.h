/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:40 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:41 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_spin
{
	int		i;
	int		turns;
}	t_spin;

typedef struct s_list
{
	int				number;
	int				index;
	int				save_index;
	struct s_list	*past;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			amount;
	char		*str;
	int			max_index;
	int			min_index;
	int			block_size;
	int			holy_crutch;
}	t_stack;

void	invalid_input(void);
void	error_exit(void);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
t_stack	min_and_max_index(t_stack stacks, int selected_index);
t_stack	sa(t_stack stacks);
t_stack	sb(t_stack stacks);
t_stack	ss(t_stack stacks);
t_stack	pa(t_list *stack_a, t_list *stack_b, t_stack stacks);
t_stack	pb(t_list *stack_a, t_list *stack_b, t_stack stacks);
t_stack	ra(t_stack stacks);
t_stack	rb(t_stack stacks);
t_stack	rr(t_stack stacks);
t_stack	rra(t_stack stacks);
t_stack	rrb(t_stack stacks);
t_stack	rrr(t_stack stacks);
t_stack	first_pb(t_list *stack_a, t_stack stacks);
t_stack	case_1(t_stack stacks);
t_stack	case_2(t_stack stacks);
t_stack	case_3(t_stack stacks);
t_stack	case_4(t_stack stacks);
t_stack	case_5(t_stack stacks);
t_spin	direction_of_rotation(t_stack stacks);
t_spin	direction_of_rotation_2(t_stack stacks);
t_spin	direction_of_rotation_3(t_stack stacks, int block);
int		direction_of_rotation_final(t_stack stacks);
void	stack_index(t_list *stack, int	amount);
void	index_save(t_list *stack, int amount);
void	index_return(t_list *stack, int	amount);
t_stack	case_return(t_stack stacks);
t_stack	final_touch(t_stack stacks);
t_stack	case_go_to_stack_b(t_stack stacks);
t_stack	case_go_to_stack_b_2(t_stack stacks, int i);
t_stack	crutch(t_stack stacks);
int		check_for_sorting(t_list *stack, int amount);
int		check_repeat(t_list *stack, int amount);
void	check_input(int argc, char **argv);
t_stack	push_swap_3(t_stack stacks);
t_stack	push_swap_5(t_stack stacks);
t_stack	push_swap_100(t_stack stacks);
t_stack	push_swap_500(t_stack stacks);
int		amount_of_elements(char *str);
char	**check_input_str(char *str);
void	stack_init(int amount, int numbers[amount], t_list *stack);
t_stack	create(int argc, char **argv);
void	show_stack(t_list *select, int i);
#endif