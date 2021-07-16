#pragma once



template <typename UNDERLYING, UNDERLYING MIN, UNDERLYING MAX>
class Subtype
{

	static_assert(MAX > MIN);

	constexpr void check(UNDERLYING val)
	{
		if (val > MAX || val < MIN) throw std::out_of_range("");
	}

	UNDERLYING add(UNDERLYING a, UNDERLYING b)
	{
		UNDERLYING temp = 0;
		temp = a + b;
		return temp;
	}

	UNDERLYING sub(UNDERLYING a, UNDERLYING b)
	{
		UNDERLYING temp = 0;
		temp = a - b;
		return temp;
	}

	//private constructor for temporiaries
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

		check(val);
		value = val;

	}

	Subtype(const Subtype &other)
	{
		check(other.value);
		value = other.value;

	}

	Subtype &operator=(const Subtype &other)
	{
		check(other.value);
		value = other.value;
		return *this;
	}


	Subtype &operator=(UNDERLYING val)
	{
		check(val);
		value = val;
		return *this;
	}

	//////////////////////////////////
	//+ and += operator
	///////////////////////////
	Subtype operator+(const Subtype &other)
	{
		UNDERLYING val = add(this->value, other.value);
		return Subtype(val, false); //dont check value
	}


	Subtype operator+(UNDERLYING other)
	{
		UNDERLYING val = add(this->value, other);
		return Subtype(val, false);		//dont check value
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
	Subtype operator-(const Subtype &other)
	{
		UNDERLYING val = sub(this->value, other.value);
		return Subtype(val, false);		//dont check value
	}


	Subtype operator-(UNDERLYING other)
	{
		UNDERLYING val = sub(this->value, other);
		return Subtype(val, false);		//dont check value
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



	bool operator==(UNDERLYING val) const
	{
		return value == val;
	}




	bool operator!=(UNDERLYING val) const
	{
		return value != val;
	}



	UNDERLYING getMax() const
	{
		return MAX;
	}
	UNDERLYING getMin() const
	{
		return MIN;
	}

	operator UNDERLYING() const { return value; }





private:
	UNDERLYING value;


};


