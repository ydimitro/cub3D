/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:08:11 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/17 19:48:07 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int x);
int				ft_isalpha(int x);
int				ft_isascii(int x);
int				ft_isdigit(int x);
int				ft_isprint(int x);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memdel(void *ptr);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_nbrlen(long n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
int				ft_power(int nbr, int pow);
void			ft_skip_space(const char *str, int *i);
void			ft_skip_spacenl(const char *str, int *i);
char			**ft_split(char *s, char c);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strncpy(char *dst, char *src, int n);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *bg, const char *sm, size_t len);
char			*ft_strrchr(char *s, int c);
char			*ft_strcpy(char *dest, char *src);
int				ft_strisnum(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnstr(const char *bg, const char *sm, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
// GNL
size_t			ft_gnl_strlen(char *str);
char			*ft_gnl_strchr(char *s, int c);
char			*ft_gnl_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
/* Bonus functions */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif
