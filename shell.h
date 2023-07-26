#ifndef _SHELL_H_
#define _SHELL_H_
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define E_OF_F -2
#define EXIT -3

int file_comnd_fle_proc(char *file_path, int *exe_ret);

int token_len(char *str, char *delim);
int token_count(char *str, char *delim);

int open_fail(char *file_path);

void handle_signal(int sig);
int execute(char **args, char **front);

char *fill_path_dir(char *path);

void free_list(list_t *head);

ssize_t gt_nw_ln(char *line);
void lgcl_ps(char *line, ssize_t *new_len);

char *get_pro_id(void);
char *env_val_get(char *beginning, int len);

int lenght_num(int num);

void als_set(char *var_name, char *value);
void als_print(alias_t *alias);

/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;

/**
 * struct list_s - struct type defining a linked list.
 * @dir: directory path.
 * @next: pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/* Helpers */
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/* Handling error */
int create_err(char **args, int err);
char *err_env(char **args);
char *err_1(char **args);
char *error_2_exit(char **args);
char *err_2cd(char **args);
char *err_2synt(char **args);
char *err126(char **args);
char *err_127(char **args);

/**
 * struct builtin_s - struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - struct defining aliases.
 * @name: name of the alias.
 * @value: value of the alias.
 * @next: pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Builtins */
int (*get_builtin(char *command))(char **args, char **front);
int cfn_sh_exit(char **args, char **front);
int cfn_sh_env(char **args, char __attribute__((__unused__)) **front);
int cfn_sh_setenv(char **args, char __attribute__((__unused__)) **front);
int cfn_sh_unsetenv(char **args, char __attribute__((__unused__)) **front);
int cfn_sh_cd(char **args, char __attribute__((__unused__)) **front);
int cfn_sh_alias(char **args, char __attribute__((__unused__)) **front);
int cfn_sh_help(char **args, char __attribute__((__unused__)) **front);

/* Global aliases for linked list */
alias_t *aliases;

/* Major Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
char *_itoa(int num);

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);

/* Input Helpers */
void handl_lne(char **line, ssize_t read);
void var_replace(char **args, int *exe_ret);
char *arg_get(char *line, int *exe_ret);
int arg_call(char **args, char **front, int *exe_ret);
int arg_run(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);

/* Str functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Linked list Helpers */
alias_t *als_end_add(alias_t **head, char *name, char *value);
void als_free_list(alias_t *head);
list_t *add_on_node_end(list_t **head, char *dir);

void all_help(void);
void als_help(void);
void c_d_help(void);
void exit_help(void);
void help_h(void);
void env_help(void);
void help_set_env(void);
void help_unset_env(void);
void hist_help(void);

#endif /* _SHELL_H_ */
