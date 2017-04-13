/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:31:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:45:07 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include "signal.h"
# include <stdbool.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <stdio.h>
# include <sys/wait.h>
# include <dirent.h>

# define IS_CHAR s[0] >= 32 && s[0] <= 126 && s[1] == 0
# define KEY_LE s[0] == 27 && s[1] == 91 && s[2] == 68
# define KEY_RI s[0] == 27 && s[1] == 91 && s[2] == 67
# define KEY_DO s[0] == 27 && s[1] == 91 && s[2] == 66
# define KEY_UPP s[0] == 27 && s[1] == 91 && s[2] == 65
# define BACKSPACE s[0] == 127 && s[1] == 0
# define DEL s[0] == 27 && s[1] == 91 && s[2] == 51
# define CTRL_D s[0] == 4
# define HOME s[0] == 27 && s[1] == 91 && s[2] == 53
# define END s[0] == 27 && s[1] == 91 && s[2] == 54
# define CTRL_RIGHT s[2] == 49 && s[4] == 53 && s[5] == 67
# define CTRL_LEFT s[2] == 49 && s[4] == 53 && s[5] == 68
# define CTRL_DO s[2] == 49 && s[4] == 53 && s[5] == 66
# define CTRL_UP s[2] == 49 && s[4] == 53 && s[5] == 65
# define ALT_C s[0] == -61 && s[1] == -89 && s[2] == 0
# define ALT_V s[0] == -30 && s[1] == -120 && s[2] == -102
# define ENTER s[0] == 10 && s[1] == 0
# define RED "\x1B[31m"
# define RESET "\x1B[0m"
# define HLEN 20
# define FD_ERR 2

typedef struct		s_hist
{
	char			**tab;
	int				index;
	int				pos;
	bool			art;
	char			*quote;
	int				status;
	int				ctrl_c;
	int				fd;
}					t_hist;

typedef struct		s_env
{
	char			**t;
	struct termios	term;
	t_hist			*hist;
}					t_env;

typedef struct		s_line
{
	char			*str;
	char			*prompt;
	char			*buffer_copy;
	char			*quote;
	int				plen;
	int				pos;
	int				len;
	int				*fukn;
	int				fd;
	t_hist			*h;
}					t_line;

typedef struct		s_data
{
	t_line			*l;
	t_env			*e;
}					t_data;

typedef	struct		s_tree
{
	int				type;
	char			*str;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

int					col(void);
int					row(void);

struct termios		*def_term(void);
bool				clean_exit(t_line *line);
bool				restore_term(struct termios *term_restore);
struct termios		get_env(struct termios term);
bool				init_error(void);
bool				error(void);
char				*s_add(char *s, char c, int pos);
char				*s_del(char *s, int pos);
char				*readline(char *prompt, t_hist *hist);
char				key_pressed(char *s, t_line *line);
t_line				*struct_init(char *prompt, t_hist *h);

int					outc(int c);
int					letter(t_line *line, char c);
int					key_del(t_line *line);
bool				key_le(t_line *line);
bool				key_ri(t_line *line);
bool				key_upp(t_line *line);
bool				key_suppr(t_line *line);
bool				key_do(t_line *line);
bool				key_ho(t_line *line);
bool				key_en(t_line *line);
bool				key_next_word(t_line *line);
bool				key_prev_word(t_line *line);
bool				check_eol(t_line *line, int p);
bool				check_bol(t_line *line, int p);
void				print_end(t_line line);
int					posx(t_line line);
int					posy(t_line line);
int					leny(t_line line);

bool				quotes_hist(t_line *line);

void				restore_curs(t_line line);
void				move_curs(int x, t_line line);
int					cursrow(int fd);
int					curscol(int fd);
int					debug(t_line *line, int a, int b, int c);

bool				copy(t_line *line);
void				copy_read(t_line *line);
void				paste(t_line *line);

t_hist				*hist_init(void);
void				hist_add(t_hist *h, char *s);
void				hist_read_up(t_line *l);
void				hist_read_do(t_line *l);

char				*clean_line(t_line *line);
void				s_add_s(t_line *l);

void				ft_signal(void);
void				ft_sigint(int i);
t_data				*get_data(t_data *d);

t_env				*env_init(void);
bool				display_env(char **line, t_env *env);
bool				set_env(char **line, t_env *env);
bool				buildin(char **line, t_env *env);
char				*parser(char *str, t_env *env, int fork);
bool				unset_env(char **line, t_env *env);

int					disp_err(int code);

char				**split_path(char **env);
int					is_exec(char **param);
char				*get_home_dir(char **env);
int					basic_exec(char **param, char **env, int fork);
int					exec_bin(char **env, char **param, char **path, int fork);
bool				env_alone(char **env, t_opt opt);
bool				env_i(t_opt opt);
bool				env_u(char **env, t_opt opt);

void				change_env_val(char **env, char *key, char *newval);
char				*get_env_val(char **env, char *key);

bool				cd(char **env, char **line);
void				super_exit(t_env *env);
bool				b_echo(char **line);
bool				need_quote(char *str);
char				*quotes(t_hist *hist, char *str);
void				printn(char *s, int fd);

int					ctrl_d(t_line *line);
char				*parse_quote(char *s);
t_tree				*fill_tree(char *str, char **t);
int					type_cmd(char *str);
int					find_next(char *str);
void				read_tree(t_tree *tree);
void				tree_exec(t_tree *tree, t_env *env);
char				*ft_strchrskipquote(char *s, char c);
t_line				*stock(t_line *l, int mode);
bool				main_quote(t_line *line);
void				ft_siguseless(int i);
void				tree_clean(t_tree *tree);
char				*replace_dollar(char *s, char **tab);
char				*ft_repdol(char *cmd, char *var, int pos, int lenvar);
void				ft_signal2(void);
void				ft_sigwinch(int i);
int					isfirstfork(int i);
void				chk_t(t_tree *t);
int					tree_error(int i);
int					ft_fork(t_tree *tree, t_env *env);
char				**redir_to_tab(char *str);
int					is_redir(char *str);
int					is_valid_redir(char *str, int i);
char				**redir_to_tab(char *str);
char				**check_redir(char **t);
bool				redir_in_row(char **t);
int					skip_quote(char *str, int i);
int					chvrndroit(char *str, int i);
bool				check_redir2(char *str);
int					chvrngauche(char *str, int i);
char				*redir_to_tab_ext(char *str, int *i);
char				*cmd_to_tab(char *str, int *i);
int					which_redir(char *str);
int					which_redir2(char *str);
char				**tab_rmemptyline(char **t);
char				***split_tab(char **t1);
int					main_redir(char *str, t_env *env);
int					find_exec(char **t);
char				**red_err(char *msg, char **t);
int					treat_redir(char **tl, t_env *env);
int					parse_fd(int *fd, char **t);
int					exec_redir(int *fd, char **tl, t_env *env);
int					open_file(char *filename, int red_type);
int					exec_redir2(int *fd, char *cmd, t_env *env, int *savefd);
bool				check_redir3(char **t);
int					parse_heredoc(char **t);
int					heredoc(char **t, char *strstop);
int					main_heredoc(char **t);
void				problem(void);
char				key_press_ext(char *s, t_line *line);
char				*dol_ext(char *s1, char *s2, int i, int j);
int					free_ret(char *s1, char *s2, int r);
int					cde(char *tmp, char **arg);
int					tree_exec_ext(t_tree *tree, t_env *env);
int					fill_tree_ext(char *str, t_tree *tree);
int					exec_bin_ext(int forkit, char *tmp,
		char **env, char **param);
#endif
