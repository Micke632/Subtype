
TEST(TestCaseName, Sub1)
{
	Subtype<int, 1, 10> t(1);

	EXPECT_EQ(t, 1);

	t = 2;
	EXPECT_EQ(t, 2);


	Subtype<int, 1, 10> t2(t);

	EXPECT_EQ(t2, 2);

	Subtype<int, 1, 10> t3;
	EXPECT_EQ(t3, 1);


	t3 = t2;

	EXPECT_EQ(t3, t2);


	Subtype<int, 11, 13> t4;

	EXPECT_THROW(t = t4, std::out_of_range);

	EXPECT_EQ(t, 2);


	int val = t;

	EXPECT_EQ(val, 2);



	int i = 0;
	int valx = i++;

	EXPECT_EQ(i, 1);

	EXPECT_EQ(valx, 0);


	valx = ++i;

	EXPECT_EQ(i, 2);

	EXPECT_EQ(valx, 2);


	int vall = t++;

	EXPECT_EQ(vall, 2);
	EXPECT_EQ(t, 3);


	vall = ++t;

	EXPECT_EQ(vall, 4);
	EXPECT_EQ(t, 4);

	t++;

	EXPECT_EQ(t, 5);

	++t;

	EXPECT_EQ(t, 6);



}

TEST(TestCaseName, Sub2)
{
	Subtype<int, 1, 10> t(2);


	Subtype<int, 1, 10> t2(3);


	Subtype<int, 1, 10> t3 = t + t2;

	EXPECT_EQ(t3, 5);

	t3 += t;

	EXPECT_EQ(t3, 7);

	t3 += 2;

	EXPECT_EQ(t3, 9);

	int tot = t + t2 + t3 + 4;

	EXPECT_EQ(tot, 18);

	EXPECT_THROW(t = t + t2 + t3, std::out_of_range);



	Subtype<int, 2, 10> g;

	g = t;

	EXPECT_EQ(g, 2);


	g += t2;

	EXPECT_EQ(g, 5);



	Subtype<int, 1, 10> t0;

	EXPECT_THROW(g = t0, std::out_of_range);


	EXPECT_EQ(g, 5);


	g = g;

	EXPECT_EQ(g, 5);


	Subtype<int, 1, 10> tt(10);

	EXPECT_THROW(g += tt, std::out_of_range);

	EXPECT_EQ(g, 5);


	g = g - t;

	EXPECT_EQ(g, 3);


	tot = g - t2;

	EXPECT_EQ(tot, 0);
	EXPECT_EQ(g, 3);

	EXPECT_THROW(g = g - t2, std::out_of_range);

	EXPECT_EQ(g, 3);

}