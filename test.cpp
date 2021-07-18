
TEST(TestCaseName, SubType)
{
	{
		Subtype<int, 1, 10> t;
		EXPECT_EQ(t, 1);
	}
	{
		Subtype<int, 1, 10> t(1);
		EXPECT_EQ(t, 1);

		t = 2;
		EXPECT_EQ(t, 2);

		EXPECT_THROW(t = 0, std::out_of_range);
		EXPECT_EQ(t, 2);

		EXPECT_THROW(t = 11, std::out_of_range);
		EXPECT_EQ(t, 2);

		try
		{
			Subtype<int, 1, 10> xx(0);  //should throw
			EXPECT_EQ(true, false);		
		}
		catch (std::out_of_range)
		{
		}

	}

	{
		Subtype<int, 1, 10> t1(1);
		Subtype<int, 1, 10> t2(2);
		
		t1 = t2;
		EXPECT_EQ(t1, 2);
		EXPECT_EQ(t1, t2);

		t2 = 4;
		EXPECT_NE(t1, t2);
	}

	{
		Subtype<int, 1, 10> t1(10);
		Subtype<int, 10, 50> g1;

		g1 = t1;
		EXPECT_EQ(t1, g1);

		

		g1 += 1;
		EXPECT_EQ(g1, 11);

		EXPECT_THROW(t1 = g1, std::out_of_range);

		g1 += t1;
		EXPECT_EQ(g1, 21);

		g1 = t1.getValue() + t1.getValue();
		EXPECT_EQ(g1, 20);

		g1 = g1 + t1;
		EXPECT_EQ(g1, 30);

		EXPECT_THROW(g1 = g1 + 21, std::out_of_range);

		int sum = g1 + t1;
		EXPECT_EQ(sum, 40);

		sum = g1 + t1 + 100;
		EXPECT_EQ(sum, 140);


		sum = t1.getValue() + t1;
		EXPECT_EQ(sum, 20);

		g1 -=  t1;
		EXPECT_EQ(g1, 20);

		g1 = g1 - t1;
		EXPECT_EQ(g1, 10);

		EXPECT_THROW(g1 -= 1, std::out_of_range);


		g1++;
		EXPECT_EQ(g1, 11);

		++g1;
		EXPECT_EQ(g1, 12);

		auto t = g1++;

		EXPECT_EQ(t, 12);
		EXPECT_EQ(g1, 13);

		auto t2 = ++g1;

		EXPECT_EQ(t2, 14);
		EXPECT_EQ(g1, 14);


	}
	{
		Subtype<int, 1, 10> g;

		//should not compile
		//Subtype<int, 1, 100>  x(g + g);
		//Subtype<int, 1, 100>  x = (g + g);

		//Subtype<int, 1, 100>  x = g;
	}

}