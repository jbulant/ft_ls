/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/11 04:46:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awstr.h"
#include <stdio.h>
int		ft_putawstr(t_awstr *str)
{
	int		ret_value;

	ret_value = (int)str->size;
	write (1, str->buffer, str->size);
	str->size = 0;
	return (ret_value);
}

int		ft_awstrncatendl(t_awstr *dst, const char *src, size_t n)
{
	return (ft_awstrrpad(dst, src, n, ft_awpad('\n', n + 1)));
}

int		ft_awstrset(t_awstr *dst, char c, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_putawstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			ft_memset(dst->buffer, c, STR_BUFFSIZE);
			write(1, dst->buffer, STR_BUFFSIZE);
			ret_value += STR_BUFFSIZE;
			n -= STR_BUFFSIZE;
		}
	}
	ft_memset(dst->buffer + dst->size, c, n);
	dst->size += n;
	return (ret_value);
}

int		ft_awstrncat(t_awstr *dst, const char *src, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst || !src)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_putawstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			write(1, src, STR_BUFFSIZE);
			src += STR_BUFFSIZE;
			n -= STR_BUFFSIZE;
			ret_value += STR_BUFFSIZE;
		}
	}
	ft_memcpy(dst->buffer + dst->size, src, n);
	dst->size += n;
	return (ret_value);
}

int		ft_awstrpad(t_awstr *dst, const char *src, size_t n, t_awpad pad)
{
	int		ret_value1;
	int		ret_value2;

	ret_value1 = (pad.height > n) ? ft_awstrset(dst, pad.c, pad.height - n) : 0;
	if (ret_value1 != -1)
		ret_value2 = ft_awstrncat(dst, src, n);
	if (ret_value1 != -1 && ret_value2 != -1)
		return (ret_value1 + ret_value2);
	return (-1);
}

int		ft_awstrrpad(t_awstr *dst, const char *src, size_t n, t_awpad pad)
{
	int		ret_value1;
	int		ret_value2;

	ret_value1 = ft_awstrncat(dst, src, n);
	if (ret_value1 != -1)
	{
		if (pad.height > n)
			ret_value2 = ft_awstrset(dst, pad.c, pad.height - n);
		else
			ret_value2 = 0;
	}
	if (ret_value1 != -1 && ret_value2 != -1)
		return (ret_value1 + ret_value2);
	return (-1);
}

t_awpad	ft_awpad(char c, size_t height)
{
	t_awpad ret;

	ret = (t_awpad){c, height};
	return (ret);
}

int		test_awstr()
{
	t_awstr 	str;
	char		t[28] = "abcdefghijklmnopqrstuvwxyz";

	str.size = 0;
	printf("set:   (%d) '-' / 10\n", ft_awstrset(&str, '-', 5));
	printf("cat:   (%d) %s\n", ft_awstrncat(&str, t, 5), t);
	printf("set:   (%d) '\\n' / 1\n", ft_awstrset(&str, '\n', 1));
	printf("write: (%d)\n", ft_putawstr(&str));
	printf("pad:   (%d)\n", ft_awstrpad(&str, t, 5, ft_awpad('-', 10)));
	printf("set:   (%d) '\\n' / 1\n", ft_awstrset(&str, '\n', 1));
	printf("write: (%d)\n", ft_putawstr(&str));
	printf("pad:   (%d)\n", ft_awstrrpad(&str, t, 5, ft_awpad('-', 10)));
	printf("set:   (%d) '\\n' / 1\n", ft_awstrset(&str, '\n', 1));
	printf("write: (%d)\n", ft_putawstr(&str));
	return (0);
}
