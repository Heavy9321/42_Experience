/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasen <kasen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:40:45 by kasen             #+#    #+#             */
/*   Updated: 2026/11/03 15:41:32 by kasen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_opt
{
	int		method;
	int		adaptive;
	int		benchmark;
	double	disorder;
	t_bench	bench;
}	t_opt;

void	set_total(t_opt *opt);

int		ft_printf(const char *str, int fd, ...);

t_stack	*create_node(int value);
t_stack	*add_to_stack(t_stack **stack, int value);
void	clear_stack(t_stack **stack);
int		stack_size(t_stack *stack);
int		rank_stack(t_stack *stack);

t_stack	*parse_input(int argc, char **argv, int start, t_stack **stack);
int		parse_params(int ac, char **av, t_opt *opt);

double	get_disorder(t_stack *stack);
void	write_bench(t_opt *opt);

void	pa(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	pb(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	sa(t_stack **stack_a, t_opt *opt);
void	sb(t_stack **stack_b, t_opt *opt);
void	ss(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	ra(t_stack **stack_a, t_opt *opt);
void	rb(t_stack **stack_b, t_opt *opt);
void	rr(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	rra(t_stack **stack_a, t_opt *opt);
void	rrb(t_stack **stack_b, t_opt *opt);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_opt *opt);

int		is_sorted(t_stack *stack);
void	sort_three(t_stack **stack_a, t_opt *opt);
void	small_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt);
void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_opt *opt);

void	skip_spaces(const char **cursor);
int		parse_number(const char **cursor, int *value);

#endif
