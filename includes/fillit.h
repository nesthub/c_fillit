/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:01:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/07 10:13:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# include <stdio.h>

# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 545

typedef	struct 			s_termi
{
	char 				*piece;
	int					pos;
	struct s_termi		*next;
}						termi;

typedef struct			s_mapsnap
{
	int					id;
	int					*ok;
	char				*map_str;
	int					last;
	struct s_mapsnap	*prev;
	struct s_mapsnap	*next;
}						t_mapsnap;

// fichier read_file.c
char					*read_and_check(char **path, char *buf);
void					call_error(int info);

// fichier check_file.c
int						check_file(char *buf, int ret);
int						check_map(int ret, int pieces);
int						check_termi(char *buf);
int						check_char_and_format(char *buf, int line, int char_nb, int pieces);
int						check_connect_termi(char *buf, int i, int valid2);

termi					*buffer_to_list(char *buf, termi *list);
termi					*create_termi_list(termi *list, char *str, int pos);
char					**create_tab(char *buf, char **tab);
void					del_split_tab(char **tab, int nb_termi);

// fichier convert_tab2.c
char					put_to_alphabet_tab(char *str, char c);

// fichier solve_it.c
void					solve_it(char **tab);
int						loop_mapsnap(t_mapsnap *mapsnap, char **tab);


// fichier create_tab.c
char					**create_tab2(char *buf, char **tab);

// fichier convert_tab.c
void					convert_tab(char **tab);
char					put_to_top_tab(char *str, int ok);
char					*up_once_tab(char *tmp);
char					put_to_left_tab(char *str, int ok);
char					*left_once_tab(char *tmp);

// fichier map.c
int						map_first_size(char **tab);
char					*map_build(int map_size);
char					*map_insert(char *map_str, char *piece);

// fichier mapsnap.c
t_mapsnap				*snapit(t_mapsnap *prev, int *ok, char *map_str, int last);
void					free_mapsnap(t_mapsnap *mapsnap);
void					free_this_snap(t_mapsnap *free_it);

// fichier pieces.c
int						*ok_build(char **tab);
int						*ok_remove(int *ok, int remove);

// debug
void					print_snap(t_mapsnap *mapsnap, int id);

#endif
