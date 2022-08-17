#pragma once

template<typename KeyType, typename ValueType>
class TPair
{
public:
	//생성자
	TPair()
		:key(), value()
	{

	}

	// 값 받았을 때 변수를 각각 설정해주는 생성자
	TPair(const KeyType& key, const ValueType& value)
		:key(key), value(value)
	{

	}

	// 연산자 오버로딩
	bool operator==(const TPair<KeyType, ValueType>& other)
	{
		return key == other.key && value == other.value;
	 }

	bool operator!=(const TPair<KeyType, ValueType>& other)
	{
		return key != other.key || value != other.value;
		//return !(*this == other) 이런식으로도 작성 위에 코드와 같음
	}

	bool operator>(const TPair<KeyType, ValueType>& other)
	{
		return key > other.key;
	}

	bool operator<(const TPair<KeyType, ValueType>& other)
	{
		return key<other.key;
	}

	bool operator>=(const TPair<KeyType, ValueType>& other)
	{
		return key >= other.key;
	}

	bool operator<=(const TPair<KeyType, ValueType>& other)
	{
		return key <= other.key;
	}

	// 키-값 변수
	KeyType key;
	ValueType value;





};

