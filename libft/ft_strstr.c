/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:45:05 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/09/17 19:49:16 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hay_ptr;
	const char	*needle_ptr;
	if (*needle == '\0')
	{
	    return ((char *)haystack);
	}
	while (*haystack)
	{
		hay_ptr = haystack;
		needle_ptr = needle;
		while (*hay_ptr == *needle_ptr && *needle_ptr != '\0')
		{
			hay_ptr++;
			needle_ptr++;
		}
		if (*needle_ptr == '\0')
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}

