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

    point_destroy(p);
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
      cmocka_unit_test(test_point_create),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
