/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <CUnit/Basic.h>
#include "test_utils.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"
/// @brief The input data
#define SNP_INPUT "snp.input"

// setup & cleanup
static int setup(void)
{
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}


// tests
static void test_no_arg(void)
{
	// arrange

	// act
	int exit_code = system(XSTR(TARGET) " 1>/dev/null 2>/dev/null");
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_FAILURE);

}

static void test_13(void)
{
	// arrange
	const char *out_txt[] =
		{ "unsigned:   13 (0x0d)\n"
        , "  signed:   13 (0x0d)\n"
	    , "    +255:   12 (0x0c)\n"
		, "   one's:  -14 (0xfffffff2)\n"
		, "   two's:  -13 (0xfffffff3)\n"
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) " 13 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

static void test_131_2(void)
{
	// arrange
	const char *out_txt[] =
		{ "               dec   hex   oct\n"
		, "your input   : 131  0x83  0203\n"
		, "bit 2 is not set.\n"
		, "bit 2 cleared: 131  0x83  0203\n"
		, "bit 2 set    : 135  0x87  0207\n"
		, "bit 2 flipped: 135  0x87  0207\n"
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) " 131 2 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

static void test_255_7(void)
{
	// arrange
	const char *out_txt[] =
		{ "               dec   hex   oct\n"
		, "your input   : 255  0xff  0377\n"
		, "bit 7 is set.\n"
		, "bit 7 cleared: 127  0x7f  0177\n"
		, "bit 7 set    : 255  0xff  0377\n"
		, "bit 7 flipped: 127  0x7f  0177\n"
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) " 255 7 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

static void test_127_7(void)
{
	// arrange
	const char *out_txt[] =
		{ "               dec   hex   oct\n"
		, "your input   : 127  0x7f  0177\n"
		, "bit 7 is not set.\n"
		, "bit 7 cleared: 127  0x7f  0177\n"
		, "bit 7 set    : 255  0xff  0377\n"
		, "bit 7 flipped: 255  0xff  0377\n"
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) " 127 7 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

static void test_0_0(void)
{
	// arrange
	const char *out_txt[] =
		{ "               dec   hex   oct\n"
		, "your input   :   0  0x00  0000\n"
		, "bit 0 is not set.\n"
		, "bit 0 cleared:   0  0x00  0000\n"
		, "bit 0 set    :   1  0x01  0001\n"
		, "bit 0 flipped:   1  0x01  0001\n"
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) " 0 0 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("lab test", setup, teardown
				  , test_no_arg
				  , test_13
				  , test_131_2
				  , test_255_7
				  , test_127_7
				  , test_0_0
				  );
	
}
