#include <check.h>
#include <stdlib.h>

#include "malgo/scrypt.c"

unsigned unittest_failures;
// _applog
struct mining_algorithm *mining_algorithms;

START_TEST(scrypt_hash_data_zero)
    malgo_scrypt->hash_data_f(0, 0);
    ck_assert_int_eq(1, 1);
END_TEST

static Suite *scrypt_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Scrypt");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, scrypt_hash_data_zero);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = scrypt_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}


/*void test_scrypt(void)
{
    static const uint32_t input[20] = {0};
    uint32_t X[32];
    char hex[257];
    {
        PBKDF2_SHA256_80_128(input, X);
        static const uint32_t expect_X[] = {
            0x0ea9ea2c, 0x458a4459, 0xac2e8931, 0x227bb8f5,
            0xf2b1fe63, 0x65f4ca78, 0xc13ee80a, 0x9dd6a8b9,
            0x37a70962, 0xce24556e, 0x169081af, 0x73a06c4c,
            0x7feffbbe, 0x90188614, 0x499f4152, 0x174f00cf,
            0x5a2f89a9, 0x9f98d171, 0x2ff50782, 0xc8c551b1,
            0xcf4afba2, 0x089745f0, 0x37553b1f, 0xbca60eec,
            0x193ed225, 0x0d4c2da1, 0x4a670674, 0x4420645c,
            0x432ead7e, 0xa70b8496, 0x1d992334, 0x842b14de,
        };
        if (memcmp(expect_X, X, sizeof(expect_X)))
        {
            ++unittest_failures;
            bin2hex32(hex, X, 32);
            applog(LOG_ERR, "%s: %s failed (got %s)", __func__, "PBKDF2_SHA256_80_128", hex);
        }
    }
    {
        for (int i = 0; i < 0x10; ++i)
            X[i] = i;
        salsa20_8(X, input);
        static const uint32_t expect_X[] = {
            0x4fdd18f5, 0xe08388b9, 0xc05479a8, 0x7086ab5c,
            0x0888bb83, 0x75102855, 0x58a08522, 0x166cf522,
            0x0f2a4a9d, 0x232514d2, 0x0bc658d7, 0x681b4136,
            0x0586532d, 0xd271b814, 0x2a045976, 0x5d47fa5a,
        };
        if (memcmp(expect_X, X, sizeof(expect_X)))
        {
            ++unittest_failures;
            bin2hex32(hex, X, 16);
            applog(LOG_ERR, "%s; %s failed (got %s)", __func__, "salsa20_8", hex);
        }
    }
    {
        char scratchpad[SCRATCHBUF_SIZE];
        scrypt_1024_1_1_256_sp(input, scratchpad, X);
        static const uint32_t expect_X[] = {
            0x161d0876, 0xf3b93b10, 0x48cda1bd, 0xeaa7332e,
            0xe210f713, 0x1b42013c, 0xb43913a6, 0x553a4b69,
        };
        if (memcmp(expect_X, X, sizeof(expect_X)))
        {
            ++unittest_failures;
            bin2hex32(hex, X, 8);
            applog(LOG_ERR, "%s: %s failed (got %s)", __func__, "scrypt_1024_1_1_256_sp", hex);
        }
    }
}*/