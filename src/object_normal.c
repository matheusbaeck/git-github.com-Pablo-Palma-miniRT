/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:27:31 by math              #+#    #+#             */
/*   Updated: 2024/03/21 20:35:42 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

static t_vec3  normal_pl(t_plane *plane, t_vec3 point)
{
    (void)point;
    return (plane->normal);
}

static t_vec3  normal_sp(t_sphere *sphere, t_vec3 point)
{
    return(normalize(vector_sub(point, sphere->center)));
}

// static t_vec3  normal_cyl(t_cyl *cyl, t_vec3 point)
// {
//     (void)cyl;
//     return (point);
// }

t_vec3 get_normal(t_obj *obj, t_vec3 point)
{
	if (is_child(obj, "pl"))
        return (normal_pl((t_plane *)obj->child, point));
    else if (is_child(obj, "sp"))
        return (normal_sp((t_sphere *)obj->child, point));
	// else if (!ft_strncmp(((t_obj *)(obj->content))->line, "cy", 2))
    //     return (normal_sp((t_cyl *)((t_obj *)(obj->content))->child, point));
    else
		return (point);
}