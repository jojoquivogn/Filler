/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:57:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/22 02:42:57 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_init_round(t_map *map, t_piece *piece)
{
	map->range = 0;
	map->best_range = 2147483647;
	map->curr_x = 0;
	map->curr_y = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	piece->act_x = 0;
	piece->act_y = 0;
	piece->weidth = 0;
	piece->heigth = 0;
	piece->x = 0;
	piece->y = 0;
}

static void	ft_init(t_map *map)
{
	map->p_id = 0;
	map->round = 0;
	map->w_size = 0;
	map->h_size = 0;
	map->finish = 0;
}

int			main(void)
{
	t_map	map;
	t_piece	piece;
	int		ret;

	ret = 0;
	ft_init(&map);
	if (!ft_get_info(&map, &piece))
		return (ft_error(1, &map));
	while (1)
	{
		ft_init_round(&map, &piece);
		if ((ret = ft_get_map(&map)) != 1 || (ret = ft_get_piece(&map, &piece))
		!= 1)
			return (ft_error(ret, &map));
		if (!ft_play(&map, &piece))
			break ;
		map.round++;
		ft_free_tab(piece.piece);
	}
	ft_free_tab(map.map);
	return (0);
}
