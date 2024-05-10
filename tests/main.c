#include "ps_tests.h"

// Test suite initialization function
int init_suite(void) 
{
	return 0;
}

// Test suite cleanup function
int clean_suite(void) 
{
	return 0;
}

// Main function to run all tests
int main() 
{
    if (CUE_SUCCESS != CU_initialize_registry())
	{
        return CU_get_error();
    }

    // Add List Suite
    if (add_lists_tests() != CUE_SUCCESS || add_index_tests() != CUE_SUCCESS ||
	add_sort_tests())
	{
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
