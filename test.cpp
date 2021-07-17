TEST(TestCaseName, Sub1)
{
	Subtype<int, 1, 10> t(1);

	EXPECT_EQ(t, 1);

	t = 2;
	EXPECT_EQ(t, 2);


	Subtype<int, 1, 10> t2(t);

	EXPECT_EQ(t2, t);

	Subtype<int, 1, 10> t3;
	EXPECT_EQ(t3, 1);


	EXPECT_NE(t3, t2);
		

	t3 = t2;

	EXPECT_EQ(t3, t2);

	

	

	Subtype<int, 11, 13> t4;

	EXPECT_THROW(t = t4, std::out_of_range);

	EXPECT_EQ(t, 2);


	int val = t;

	EXPECT_EQ(val, 2);
	


	auto vall = t++;

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
	Subtype<int, 1, 10> t3(5);

	
	t3 += t;

	EXPECT_EQ(t3, 7);

	t3 += 2;

	EXPECT_EQ(t3, 9);

	//dont compile
	//int tot = t + t2 + t3 + 4;

	int tot = t.getValue() + t2.getValue() + t3.getValue() + 4;

	EXPECT_EQ(tot, 18);	

	EXPECT_THROW(t = t.getValue() + t2.getValue() + t3.getValue(), std::out_of_range);


	Subtype<int, 2, 10> g;


	tot = g + t2;

	EXPECT_EQ(tot, 5);

	
	g = t;

	EXPECT_EQ(g, 2);


	g += t2;

	EXPECT_EQ(g, 5);



	Subtype<int, 1, 10> t0;

	EXPECT_THROW(g = t0 , std::out_of_range);

	
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

	EXPECT_THROW(g = g - t2 , std::out_of_range);

	EXPECT_EQ(g, 3);


	//dont compile
	//Subtype<int, 1, 3>  x1(g+ g);


	Subtype<int, 1, 10>  x(g + 3 + 3) ;
	
	EXPECT_EQ(x, 9);

	try
	{
		Subtype<int, 1, 10> xx(11);
		EXPECT_EQ(true, false);		//should cot come here..
	}
	catch (std::out_of_range )
	{
	}

}