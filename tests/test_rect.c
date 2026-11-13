#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "../headers/rect.h"

#define FAIL -1
#define SUCCESS 0

// ensure points get created
static void test_rect_create(void **state)
{
    Rect *r = rect_create(10, 20, 4, 7, 5, "tt" );
    assert_non_null(r);
    assert_int_equal(r->x, 10);
    assert_int_equal(r->y, 20);
    assert_int_equal(r->width, 4);
    assert_int_equal(r->height, 7);
    assert_int_equal(r->colour, 5);
    assert_string_equal(r->str, "tt");

    free(r);
    r = NULL;
}

static void test_rect_create_invalid_colour_fail(void **state)
{
    Rect *r = rect_create(10, 20, 4, 7, -1, "tt");
    assert_null(r);

    free(r);
    r = NULL;

}

static void test_rect_create_null_str_fail(void **state) {

    Rect *r = rect_create(10, 20, 4, 7, 4, NULL);
    assert_null(r);

    free(r);
    r = NULL;
}


int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_rect_create),
      cmocka_unit_test(test_rect_create_invalid_colour_fail),
      cmocka_unit_test(test_rect_create_null_str_fail),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

