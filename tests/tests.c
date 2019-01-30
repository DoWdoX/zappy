/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** 
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "tests_inc.h"

Test(add_to_action_queue, add_to_action_queue_test)
{
	client_t *active = init_test_client();

	cr_assert_str_eq(active->action, "Potatoe pc");
	cr_assert_str_neq(active->actions_queue->action, "Potatoe pc");
	cr_assert_str_eq(active->actions_queue->action, "Chmod 777 your mom");
	cr_assert_str_eq(active->actions_queue->next->action, "Test: icals");
}

Test(nat, nat_test)
{
	client_t *active = init_test_client();

	next_action(active);
	cr_assert_str_neq(active->action, "Potatoe pc");
	cr_assert_str_eq(active->action, "Chmod 777 your mom");
	cr_assert_str_eq(active->actions_queue->action, "Test: icals");
	next_action(active);
	cr_assert_str_eq(active->action, "Test: icals");
}

Test(cta, cta_test)
{
	client_t *active = init_test_client();

	cr_assert_eq(count_actions(active), 3);
	add_to_action_queue(active, "Hello world");
	cr_assert_eq(count_actions(active), 4);
}

Test(p, p_test)
{
	params_t p1;
	params_t p2;
	params_t p3;
	int test_ac = 0;
	char **test_av = init_test_av(&test_ac);

	cr_assert_neq(get_params(test_ac, test_av, &p2), 0);
	test_av[test_ac++] = strdup("-y");
	test_av[test_ac++] = strdup("21");
	cr_assert_eq(get_params(test_ac, test_av, &p1), 0);
	test_av[test_ac++] = strdup("-help");
	cr_assert_eq(get_params(test_ac, test_av, &p3), 1);
}
