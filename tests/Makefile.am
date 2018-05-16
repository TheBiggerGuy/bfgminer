TESTS =
noinst_PROGRAMS =
check_PROGRAMS =

TESTS += test-bfgminer.sh
EXTRA_DIST = test-bfgminer.sh
SH_LOG_COMPILER = /bin/sh
AM_TESTS_ENVIRONMENT = PATH='$(top_builddir)':'$(srcdir)':"$$PATH"; export PATH;
TESTS_ENVIRONMENT = $(AM_TESTS_ENVIRONMENT)
TEST_EXTENSIONS = .sh

if USE_SCRYPT
TESTS += test_scrypt
noinst_PROGRAMS += test_scrypt
check_PROGRAMS += test_scrypt
test_scrypt_SOURCES = test_scrypt.c $(bfgminer_SOURCES)
test_scrypt_CPPFLAGS = $(CHECK_CFLAGS) $(bfgminer_CPPFLAGS) $(bfgminer_CFLAGS)
test_scrypt_LDADD = $(CHECK_LIBS) $(bfgminer_LDADD)
test_scrypt_LDFLAGS = $(bfgminer_LDFLAGS)
EXTRA_test_scrypt_DEPENDENCIES = $(EXTRA_bfgminer_DEPENDENCIES)
endif