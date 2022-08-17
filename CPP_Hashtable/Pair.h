#pragma once

template<typename KeyType, typename ValueType>
class TPair
{
public:
	//������
	TPair()
		:key(), value()
	{

	}

	// �� �޾��� �� ������ ���� �������ִ� ������
	TPair(const KeyType& key, const ValueType& value)
		:key(key), value(value)
	{

	}

	// ������ �����ε�
	bool operator==(const TPair<KeyType, ValueType>& other)
	{
		return key == other.key && value == other.value;
	 }

	bool operator!=(const TPair<KeyType, ValueType>& other)
	{
		return key != other.key || value != other.value;
		//return !(*this == other) �̷������ε� �ۼ� ���� �ڵ�� ����
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

	// Ű-�� ����
	KeyType key;
	ValueType value;





};

