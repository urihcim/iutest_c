/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_spi_tests.c
 * @brief		iutest_spi test
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_spi_c.h"

const char* null_str;
int a, b, n1, n100;
int  aa[5];
int  ab[6];
char ac[5];

void SPITest_SetUp(void)
{
	int  aa_[5] = { 0, 1, 2, 3, 4 };
	int  ab_[6] = { 0, 1, 2, 3, 4, 5 };
	char ac_[5] = { 0, 0, 2, 3, 5 };
	int i;
	null_str = NULL;
	a = b = 0;
	n1 = 1;
	n100 = 100;
	for( i=0; i < 5; ++i )
	{
		aa[i] = aa_[i];
		ab[i] = ab_[i];
		ac[i] = ac_[i];
	}
	ab[5] = 5;
}

iuTestFixture SPITest = {
	NULL
	, NULL
	, SPITest_SetUp
	, NULL
	, NULL
};

static void FatalFailure_Sub(int* count)
{
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_TRUE(FALSE), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_FALSE(TRUE), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NULL((void*)1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NOTNULL((void*)0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_SAME(a, b), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ(1, a), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NE(a, b), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_LE(n1, a), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_LT(n1, a), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_GE(a, n1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_GT(a, n1), "" );
#if IUTEST_C_HAS_FLOATINGPOINT
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_FLOAT_EQ(1, a), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_DOUBLE_EQ(1, a), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NEAR(a, n100, 2), "" );
#endif

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", null_str), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ(null_str, "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRNE("a", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRNE(null_str, null_str), "" );

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", null_str), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("a", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("A", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(100), "" );
#endif
	
	/*
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );
	*/
	
	(*count)++;
}
	
IUTEST_F(SPITest, FatalFailure)
{
	int count=0;
	FatalFailure_Sub(&count);
	IUTEST_ASSERT_EQ(1, count);
}

static void FatalFailure2_Sub(int* count)
{
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_TRUE(FALSE), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_FALSE(TRUE), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NULL((void*)1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NOTNULL((void*)0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_SAME(a, b), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ(1, a), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NE(a, b), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_LE(n1, a), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_LT(n1, a), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_GE(a, n1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_GT(a, n1), "" );
#if IUTEST_C_HAS_FLOATINGPOINT
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_FLOAT_EQ(1.0f, a), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_DOUBLE_EQ(1.0, a), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NEAR(a, n100, 2.0), "" );
#endif

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", null_str), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ(null_str, "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRNE("a", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRNE(null_str, null_str), "" );

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", null_str), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("a", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("A", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(100), "" );
#endif
	
	/*
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );
	*/

	(*count)++;
}
	
IUTEST_F(SPITest, FatalFailure2)
{
	int count=0;
	FatalFailure2_Sub(&count);
	IUTEST_ASSERT_EQ(1, count);
}

IUTEST_F(SPITest, NonFatalFailure)
{
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_TRUE(FALSE), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_FALSE(TRUE), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NULL((void*)1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NOTNULL((void*)0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_SAME(a, b), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ(1, a), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NE(a, b), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_LE(n1, a), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_LT(n1, a), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_GE(a, n1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_GT(a, n1), "" );
#if IUTEST_C_HAS_FLOATINGPOINT
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_FLOAT_EQ(1.0f, a), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_DOUBLE_EQ(1.0, a), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NEAR(a, n100, 2.0), "" );
#endif
	
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", null_str), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ(null_str, "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE("a", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE(null_str, null_str), "" );

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", null_str), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("a", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("A", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(100), "" );
#endif

	/*
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );
	*/
}

IUTEST_F(SPITest, NonFatalFailure2)
{
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_TRUE(FALSE), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_FALSE(TRUE), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NULL((void*)1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NOTNULL((void*)0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_SAME(a, b), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ(1, a), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NE(a, b), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_LE(n1, a), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_LT(n1, a), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_GE(a, n1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_GT(a, n1), "" );
#if IUTEST_C_HAS_FLOATINGPOINT
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_FLOAT_EQ(1, a), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_DOUBLE_EQ(1, a), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NEAR(a, n100, 2), "" );
#endif

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", null_str), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ(null_str, "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE("a", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE(null_str, null_str), "" );

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", null_str), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("a", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("A", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(100), "" );
#endif

	/*
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );
	*/
}

