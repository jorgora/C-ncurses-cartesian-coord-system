#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "../headers/point.h"

#define FAIL -1
#define SUCCESS 0

// ensure points get created
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

static void test_point_create_invalid_colour_fail(void **state)
{
    Point *p = point_create(10, 20, -1, "tt" );
    assert_null(p);

    free(p);
    p = NULL;
}

static void test_point_create_null_str_fail(void **state)
{
    Point *p = point_create(10, 20, 4, NULL);
    assert_null(p);

    free(p);
    p = NULL;
}

// test point_move succeeds
static void test_point_move(void **state)
{
    Point *p = point_create(10, 20, 4, "tt");

    int return_code = point_move(p, 5, -5);
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, 15);
    assert_int_equal(p->y, 15);

    return_code = point_move(p, -5, 5);
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, 10);
    assert_int_equal(p->y, 20);

    free(p);
    p = NULL;
}

// test point_move fails on NULL values
static void test_point_move_null_fail(void **state)
{
    int return_code = point_move(NULL, 5, -5);
    assert_int_equal(return_code, FAIL);
 }

// test point_set fails on NULL values
static void test_point_set_null_fail(void **state)
{
    int return_code = point_set(NULL, 5, -5);
    assert_int_equal(return_code, FAIL);
}

// test point_set succeeds
static void test_point_set(void **state)
{
    Point *p = point_create(10, 20, 4, "tt");

    int return_code = point_set(p, 30, -30);
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, 30);
    assert_int_equal(p->y, -30);

    return_code = point_set(p, -30, 30);
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, -30);
    assert_int_equal(p->y, 30);

    free(p);
    p = NULL;
}

// test point_refresh fails on NULL values
static void test_point_refresh_null_fail(void **state) {

    int return_code = point_refresh(NULL);
    assert_int_equal(return_code, FAIL);
}
static void test_point_invalid_colour_fail(void **state)
{
    int return_code = point(10, 20, -1, "tt" );
    assert_int_equal(return_code, FAIL);
}

static void test_point_null_str_fail(void **state)
{
    int return_code = point(10, 20, 4, NULL);
    assert_int_equal(return_code, FAIL);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_point_create),
      cmocka_unit_test(test_point_create_invalid_colour_fail),
      cmocka_unit_test(test_point_create_null_str_fail),

      cmocka_unit_test(test_point_move),
      cmocka_unit_test(test_point_move_null_fail),

      cmocka_unit_test(test_point_set),
      cmocka_unit_test(test_point_set_null_fail),
      cmocka_unit_test(test_point_refresh_null_fail),

      cmocka_unit_test(test_point_null_str_fail),
      cmocka_unit_test(test_point_invalid_colour_fail),

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
