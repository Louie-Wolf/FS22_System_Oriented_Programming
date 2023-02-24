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


/// @brief Reset
#define N "\033[0m\n"
/// @brief Black
#define X "\033[40m "
/// @brief White
#define _ "\033[47m "

// tests
static void test_empty_input(void)
{
	// arrange
	const char *out_txt[] =
		{ N
		, N
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) "</dev/null 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

static void test_black_and_white_input(void)
{
	// arrange
	const char *out_txt[] =
		{ N
		, _ X _ N
		, N
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system("echo ' # ' | " XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE);
	// assert
	CU_ASSERT_EQUAL(WEXITSTATUS(exit_code), EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
	assert_lines(ERRFILE, err_txt, sizeof(err_txt)/sizeof(*err_txt));
}

static void test_snp_input(void)
{
	// arrange
	const char *out_txt[] =
		{ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X X X X X X X X X X X X X _ _ X X X X X X X X _ _ _ _ X X X X X X X X X X X X X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ X X X X _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ _ _ X X X X X X _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ _ _ X X _ _ X X _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ X X X X _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X X X X X X X X X X X X X _ _ X X _ _ X X _ _ X X _ _ X X X X X X X X X X X X X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X X X X X X _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X X X _ _ X X X X _ _ X X _ _ _ _ X X X X X X X X _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X X _ _ X X _ _ _ _ _ _ _ _ X X _ _ X X _ _ X X _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X _ _ X X X X _ _ X X X X _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ X X _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ _ _ X X X X X X X X _ _ _ _ X X X X X X _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ X X X X _ _ X X X X _ _ _ _ X X _ _ _ _ X X X X _ _ X X X X X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X X X X X X _ _ X X _ _ X X _ _ X X _ _ X X _ _ X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X X X X X X X X X X X X X _ _ _ _ _ _ _ _ _ _ X X X X X X _ _ X X X X _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ X X _ _ X X X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ X X X X X X X X X X X X _ _ _ _ X X _ _ X X X X X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ X X _ _ _ _ _ _ X X X X _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ X X X X X X _ _ X X _ _ _ _ X X X X _ _ X X X X _ _ _ _ X X X X _ _ X X X X _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ X X _ _ X X _ _ _ _ _ _ _ _ _ _ X X X X _ _ X X X X X X _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ X X X X X X X X X X X X X X _ _ X X X X X X X X X X X X _ _ _ _ X X _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ N
		, N
		};
	const char *err_txt[] = { NULL };
	// act
	int exit_code = system(XSTR(TARGET) "<" SNP_INPUT " 1>" OUTFILE " 2>" ERRFILE);
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
				  , test_empty_input
				  , test_black_and_white_input
				  , test_snp_input
				  );
	
}
