/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:42:50 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/29 16:45:48 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

# define BUFFER_SIZE 1024
# define FT_HEX_BASE_LOW "0123456789abcdef"
# define FT_HEX_BASE_UP "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// check
bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isalnum(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);

// print
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//  printf
int		ft_printf(const char *s, ...);
int		ft_parse_char(char c);
int		ft_parse_str(char *str);
int		ft_parse_void(void *addr);
int		ft_parse_int(int nbr);
int		ft_parse_udec(unsigned int nbr);
int		ft_parse_hex(unsigned long nb, char c);

// string
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strdup(char const *s1);
char	*ft_strndup(char const *s1, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(char const *big, char const *little, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(char const *c);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);

// convert
int		ft_atoi(char const *nptr);
long	ft_atol(char const *nptr);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ulong_itoa_base(unsigned long nbr, char const *base_to);

// memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memswap(void **a, void **b);

// iterative
int		ft_count_if(void **tab, size_t length, int (*f)(void *));
bool	ft_any(void **tab, size_t length, int (*f)(void *));
bool	ft_every(void **tab, size_t length, bool (*f)(void *));
bool	ft_is_sort(void **tab, size_t length, int (*cmp)(void *, void *));
void	ft_foreach(void **tab, size_t length, void (*f)(void *));
void	ft_sort(void **tab, size_t length, int (*cmp)(void *, void *));
void	**ft_map(void **tab, size_t length, void *(*f)(void *));

// linked list
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new_elem);
void	ft_lstadd_back(t_list **lst, t_list *new_elem);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstforeach(t_list *lst, void (*f)(void *));
void	ft_lstforeach_if(t_list *lst, void (*f)(void *),
			void *data_ref, int (*cmp)(void *, void *));
void	ft_lstmerge(t_list **head1, t_list *head2);
void	ft_lstremove_if(t_list **head, void *data_ref,
			int (*cmp)(void *, void *), void (*free_fct)(void *));
void	ft_lstreverse(t_list **head);
void	ft_lstsort(t_list *head, int (*cmp)(void *, void *));
t_list	*ft_lstat(t_list *head, unsigned int nb);
t_list	*ft_lstfind(t_list *head, void *data_ref, int (*cmp)(void *, void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);

// file
char	*get_next_line(int fd);

#endif
