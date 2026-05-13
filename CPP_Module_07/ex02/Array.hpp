#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class	Array
{
	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array(void) : _data(NULL), _size(0)
		{
		}

		Array(unsigned int n) : _data(new T[n]()), _size(n)
		{
		}

		Array(const Array &other) : _data(NULL), _size(0)
		{
			*this = other;
		}

		~Array(void)
		{
			delete[] _data;
		}

		Array	&operator=(const Array &other)
		{
			if (this != &other)
			{
				T	*newData = NULL;

				if (other._size > 0)
				{
					newData = new T[other._size];
					for (unsigned int i = 0; i < other._size; ++i)
						newData[i] = other._data[i];
				}
				delete[] _data;
				_data = newData;
				_size = other._size;
			}
			return (*this);
		}

		T	&operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return (_data[index]);
		}

		const T	&operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return (_data[index]);
		}

		unsigned int	size(void) const
		{
			return (_size);
		}
};

#endif
