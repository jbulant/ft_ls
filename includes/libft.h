/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:45 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/12 05:44:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef unsigned char	t_byte;
typedef enum			e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;
typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,\
									size_t n);
void					*ft_memmove(void *dest, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					ft_memclr(void *buffer, size_t size);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *src);
char					*ft_strndup(const char *src, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *str, const char *to_find);
char					*ft_strnstr(const char *str, const char *to_find,\
									size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
t_bool					ft_isalpha(int c);
t_bool					ft_isdigit(int c);
t_bool					ft_isalnum(int c);
t_bool					ft_isascii(int c);
t_bool					ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
char					*ft_strrealloc(char **dst, size_t new_size);
void					ft_strdel(char **as);
void					ft_strclr(char *str);
void					ft_striter(char *str, void (*f)(char *));
void					ft_striteri(char *str, void (*f)(unsigned int, char *));
char					*ft_strmap(const char *str, char (*f)(char));
char					*ft_strmapi(const char *s,\
									char (*f)(unsigned int, char));
t_bool					ft_strequ(const char *s1, const char *s2);
t_bool					ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *str, unsigned int start,\
									size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *str);
char					**ft_strsplit(const char *str, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_putendl(char *str);
void					ft_putnbr(int nb);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *str, int fd);
void					ft_putendl_fd(char *str, int fd);
void					ft_putnbr_fd(int nb, int fd);
t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **alst,\
									void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void **));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstappend(t_list **alst, t_list *new);
void					ft_lstjoin(t_list **alst, t_list *new);
char					**ft_arstrnew(size_t size);
size_t					ft_count_words(const char *str, char seperator);
size_t					ft_strclen(const char *str, char c);
char					*ft_strrev(char *str);
void					ft_swap(int *a, int *b);
void					ft_swap_addr(void **ap1, void **ap2);
t_bool					ft_isspace(int c);
t_bool					ft_iswhitespace(int c);
int						ft_abs(int nb);
int						ft_npow(int n, int pow);
unsigned int			ft_poweroftwo(int n);
int						ft_poweroften(int n);
char					*ft_static_itoa(int nb);
t_bool					ft_basecheck(char *base);
int						ft_get_basevalue(char value, char *base, int b_height);
int						ft_atoi_base(char *str, char *base);
//char					*ft_itoa_base(int nb, char *base);
void					ft_print_byte(const t_byte byte);
t_byte					ft_swap_byte(const t_byte byte);
t_byte					ft_hexstr_to_byte(char *str);
t_bool					ft_ishexa(char c);
t_bool					ft_str_iscolorhex(char *str);

#endif
