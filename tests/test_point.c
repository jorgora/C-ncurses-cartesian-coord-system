#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "../headers/point.h"
static void test_point_create(void **state)
{
    Point *p = point_create(10, 20, 4, "tt" );
    assert_non_null(p);
    assert_int_equal(p->x, 10);
    assert_int_equal(p->y, 20);
    assert_int_equal(p->colour, 4);
    assert_string_equal(p->str, "tt");

    free(p);
    p = NULL;
}

static void test_point_move(void **state)
{
    Point *p = point_create(10, 20, 4, "tt");

    point_move(p, 5, -5);
    assert_int_equal(p->x, 15);
    assert_int_equal(p->y, 15);

    point_move(p, -5, 5);
    assert_int_equal(p->x, 10);
    assert_int_equal(p->y, 20);

    free(p);
    p = NULL;
}


static void test_point_set(void **state)
{
    Point *p = point_create(10, 20, 4, "tt");

    point_set(p, 30, -30);
    assert_int_equal(p->x, 30);
    assert_int_equal(p->y, -30);

    point_set(p, -30, 30);
    assert_int_equal(p->x, -30);
    assert_int_equal(p->y, 30);

    free(p);
    p = NULL;
}


int main(void)
{
    const struct CMUnitTest tests[] =
    {
      cmocka_unit_test(test_point_create),
      cmocka_unit_test(test_point_set),
      cmocka_unit_test(test_point_move),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
