#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_string.h"
#include "tests/tests.h"

static void empty(void *ar, char *arg)
{
	(void)ar;
	(void)arg;
}

int		parse_args_test(void)
{
	return (0);
}

int		getset_opt_list_test(void)
{
	const t_opt	op1[] = {
		{"--test", 't', &empty, OPT_NOARG},
	};
	const t_opt *op2 = NULL;

	ft_set_opt_list(op1);
	if (ft_get_opt_list() != op1)
		return (1);
	ft_set_opt_list(op2);
	if (ft_get_opt_list() != op1)
		return (2);
	return (0);
}

int		getset_program_name_test(void)
{
	char *s1 = "toto";
	char *s2 = 0;

	ft_set_progname(s1);
	if (ft_progname() != s1)
		return (ft_putstr_fd(ft_progname(), 2), 1);
	ft_set_progname(s2);
	if (ft_progname() == s2)
		return (2);
	return (0);
}

int		getset_version_test(void)
{
	char *s1 = "toto";
	char *s2 = 0;

	ft_set_version(s1);
	if (ft_progversion() != s1)
		return (ft_putstr_fd(ft_progversion(), 2), 1);
	ft_set_version(s2);
	if (ft_progversion() == s2)
		return (2);
	return (0);
}


int tests_args(void)
{
	int		collect;
	t_test	test[] = {
		{"getset_version", getset_version_test},
		{"getset_progname", getset_program_name_test},
		{"getset_opt_list", getset_opt_list_test},
		{"parse_args", parse_args_test},
		{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
