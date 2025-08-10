/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:55:17 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 15:21:45 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* MACROS */
# define DEFAULT_DICT "dictionaries/default.dict"
# define DICT_ERR "DICT ERROR\n"
# define WORD_ERR "WORD TOO LONG\n"
# define ERROR "ERROR\n"
# define BUFFER_SIZE 1024
# define FILE_BUFFER 32678

/* STRUCT */

typedef struct s_index
{
	int	key_start;
	int	key_end;
	int	ref_start;
	int	ref_end;
	int	current;
}	t_index;

typedef struct s_num
{
	char			*str;
	char			*exponent;
	int				len;
	struct s_num	*next;
}	t_num;

typedef struct s_entry
{
	char			*key;
	char			*ref;
	int				ref_len;
	struct s_entry	*next;
}	t_entry;

/* MAKE NUMBER */
char	*get_number(int ac, char **av);

/* DICTIONARY */
int		load_dictionary(int ac, char **av, t_entry **dict);
void	translate(char *num, t_entry *dictionary, int fd);
void	write_entry(t_num *num, t_entry *dictionary, int fd);
void	write_key(char *num, int len, int fd);
void	write_to_fd(t_num *num_token, t_entry *dictionary, char *num, int fd);

t_num	*tokenize(char *num, int len, t_num **list);

/* UTILS */
int		ft_strlen(char *s);
int		ft_isdigit(char c);
int		ft_isop(char c);
int		ft_isspace(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char *s, int start, int len);
void	*ft_memcpy(void *dest, const void *src, int n);

void	ft_lstclear(t_entry *list);
t_entry *ft_lstsearch(t_entry *list, char *ref);
void	ft_numclear(t_num *list);

void	write_hundreds(char *num, t_entry *dictionary, int len, int fd);

int		ft_is_num_entry(char *str, t_index *index, int i);
int		ft_is_sign_entry(char *str, t_index *index, int i);
int		ft_findnewl(char *str, int index);

void	write_ref(char *num, t_entry *dictionary, int fd);


#endif