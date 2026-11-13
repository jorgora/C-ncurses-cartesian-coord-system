#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "../headers/point.h"

#define FAIL -1
#define SUCCESS 0

// -------- point_create --------

static void test_point_create_success(void **state)
{
    // create pointer
    Point *p = point_create(10, 20, 4, "tt" );

    // make assertions
    assert_non_null(p);
    assert_int_equal(p->x, 10);
    assert_int_equal(p->y, 20);
    assert_int_equal(p->colour, 4);
    assert_string_equal(p->str, "tt");

    // free memory
    free(p->str);
    free(p);
    p = NULL;
}

static void test_point_create_invalid_colour_fail(void **state)
{
    // create pointer
    Point *p = point_create(10, 20, -1, "tt" );

    // make assertions
    assert_null(p);

    // free memory
    free(p);
    p = NULL;
}

static void test_point_create_null_str_fail(void **state)
{
    // create pointer
    Point *p = point_create(10, 20, 4, NULL);

    // make assertions
    assert_null(p);

    // free memory
    free(p);
    p = NULL;
}

// -------- point_move --------

// test point_move succeeds
static void test_point_move_success(void **state)
{
    // create pointer
    Point *p = point_create(10, 20, 4, "tt");

    // run function
    int return_code = point_move(p, 5, -5);

    // make assertions
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, 15);
    assert_int_equal(p->y, 15);

    // run function
    return_code = point_move(p, -5, 5);

    // make assertions
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, 10);
    assert_int_equal(p->y, 20);

    // free memory
    free(p->str);
    free(p);
    p = NULL;
}

// test point_move fails on NULL values
static void test_point_move_null_fail(void **state)
{
    // run function
    int return_code = point_move(NULL, 5, -5);

    // make assertions
    assert_int_equal(return_code, FAIL);
 }

// -------- point_set --------


// test point_set succeeds
static void test_point_set_success(void **state)
{
    // create pointer
    Point *p = point_create(10, 20, 4, "tt");

    // run function
    int return_code = point_set(p, 30, -30);

    // make assertions
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, 30);
    assert_int_equal(p->y, -30);

    // run function
    return_code = point_set(p, -30, 30);

    // make assertions
    assert_int_equal(return_code, SUCCESS);
    assert_int_equal(p->x, -30);
    assert_int_equal(p->y, 30);

    // free memory
    free(p->str);
    free(p);
    p = NULL;
}

// test point_set fails on NULL values
static void test_point_set_null_fail(void **state)
{
    // run function
    int return_code = point_set(NULL, 5, -5);

    // make assertions
    assert_int_equal(return_code, FAIL);
}


// -------- point_refresh --------

// test point_refresh fails on NULL values
static void test_point_refresh_null_fail(void **state)
{
    // run function
    int return_code = point_refresh(NULL);

    // make assertions
    assert_int_equal(return_code, FAIL);
}


// -------- point --------

static void test_point_invalid_colour_fail(void **state)
{
    // run function
    int return_code = point(10, 20, -1, "tt" );

    // make assertions
    assert_int_equal(return_code, FAIL);
}

static void test_point_null_str_fail(void **state)
{
    // run function
    int return_code = point(10, 20, 4, NULL);

    // make assertions
    assert_int_equal(return_code, FAIL);
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        // point_create
        cmocka_unit_test(test_point_create_success),
        cmocka_unit_test(test_point_create_invalid_colour_fail),
        cmocka_unit_test(test_point_create_null_str_fail),

        // point_move
        cmocka_unit_test(test_point_move_success),
        cmocka_unit_test(test_point_move_null_fail),

        // point_set
        cmocka_unit_test(test_point_set_success),
        cmocka_unit_test(test_point_set_null_fail),

        // point_refresh
        cmocka_unit_test(test_point_refresh_null_fail),
        
        // point
        cmocka_unit_test(test_point_null_str_fail),
        cmocka_unit_test(test_point_invalid_colour_fail),

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
