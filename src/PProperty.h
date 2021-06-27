#pragma once

template<typename T>
class PProperty
{
public:
	PProperty(T InValue)
	{
		Value = InValue;
	}

	PProperty(const PProperty<T>& InField)
	{
		Value = InField.Value;
	}

	const T& operator* () const
	{
		return Value;
	}

private:
	T Value;

};