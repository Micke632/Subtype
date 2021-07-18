#pragma once



#if !defined(SUBTYPE_NO_THROW)
#   include <stdexcept>
#   define OUT_OF_RANGE() throw std::out_of_range("")
#else
#   
#   define OUT_OF_RANGE() ;
#endif



template <typename UNDERLYING, UNDERLYING MIN, UNDERLYING MAX>
class Subtype
{

	static_assert(MAX > MIN);

	constexpr bool check(UNDERLYING val)
	{
		if (val > MAX || val < MIN)
		{
			OUT_OF_RANGE();
			return false;
		}
		return true;
	}

	UNDERLYING add(UNDERLYING a, UNDERLYING b) const
	{	
		return a + b;
	}

	UNDERLYING sub(UNDERLYING a, UNDERLYING b) const
	{
		return a - b;
	}


	explicit Subtype(UNDERLYING val, bool)
	{
		value = val;
	}

public:

	Subtype()
	{
		value = MIN;
	}


	explicit Subtype(UNDERLYING val)
	{
		if (check(val))
			value = val;
	}

	Subtype(const Subtype &other)
	{
		if (check(other.value))
			value = other.value;

	}

	Subtype &operator=(const Subtype &other)
	{
		if (check(other.value))
			value = other.value;
		return *this;
	}


	Subtype &operator=(UNDERLYING val)
	{
		if (check(val))
			value = val;
		return *this;
	}


	//////////////////////////////////
	//+ and += operator
	///////////////////////////

	//deleted + operator
	//to avoid a scenario like
	//SubType<int,1,10> t(10)
	//SubType<int,1,10> x = t+t which is overflow but not thrown
	//so when doing for instance:
	//int sum = t + t   getValue() must be used:
	//int sum = t.getValue()+t.getValue();

	const Subtype operator+(const Subtype &other) const = delete;		


	const Subtype operator+(UNDERLYING other) const
	{
		auto val = add(this->value, other);
		return Subtype(val,false);
	
	}


	Subtype& operator+=(const Subtype &other)
	{
		*this = add(this->value, other.value);
		return *this;
	}

	Subtype& operator+=(UNDERLYING other)
	{
		*this = add(this->value, other);
		return *this;
	}



	//////////////////////////////////
	//- and -= operator
	///////////////////////////
	const Subtype operator-(const Subtype &other) const = delete;


	const Subtype operator-(UNDERLYING other) const 
	{	
		auto val = sub(this->value, other);
		return Subtype(val, false);
	}


	Subtype& operator-=(const Subtype &other)
	{
		*this = sub(this->value, other.value);
		return *this;
	}

	Subtype& operator-=(UNDERLYING other)
	{
		*this = sub(this->value, other);
		return *this;
	}




	//post
	Subtype operator++(UNDERLYING)
	{
		Subtype temp;
		temp.value = value;

		*this += static_cast<UNDERLYING>(1);
		return temp;
	}

	//pre
	Subtype& operator++()
	{
		*this += static_cast<UNDERLYING>(1);
		return *this;

	}


	bool operator==(const Subtype &other) const
	{
		return value == other.value;
	}

	bool operator!=(const Subtype &other)  const
	{
		return value != other.value;
	}

	constexpr UNDERLYING getMax() const
	{
		return MAX;
	}
	constexpr UNDERLYING getMin() const
	{
		return MIN;
	}

	operator UNDERLYING() const { return value; }

	UNDERLYING getValue() const { return value; }




private:
	UNDERLYING value;


};


