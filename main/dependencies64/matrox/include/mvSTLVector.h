// vector standard header
#pragma once

#include <memory>
#include <stdexcept>

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4244)

#if _MSC_VER > 1500 // VS2008 is 1500
template<class _Ty,
	class _Diff,
	class _Pointer,
	class _Reference>
	struct _Ranit
		: public _Iterator_base

	{	// base type for container random-access iterator classes
	typedef random_access_iterator_tag iterator_category;
	typedef _Ty value_type;
	typedef _Diff difference_type;
	typedef _Diff distance_type;	// retained
	typedef _Pointer pointer;
	typedef _Reference reference;
	};
	
#endif
// TEMPLATE CLASS _MV_Vector_val
template<class _Ty, class _Alloc>
	class _MV_Vector_val
	{	// base class for vector to hold allocator _Alval
protected:
	_MV_Vector_val(_Alloc _Al = _Alloc())
		: _Alval(_Al)
		{	// construct allocator from _Al
		}

	typedef typename _Alloc::template
		rebind<_Ty>::other _Alty;

	_Alty _Alval;	// allocator object for values
	};

		// TEMPLATE CLASS vector
template<class _Ty, class _Ax = allocator<_Ty> >
	class TMvSTLVector
		: public _MV_Vector_val<_Ty, _Ax>
	{	// varying size array of values
public:
	typedef TMvSTLVector<_Ty, _Ax> _Myt;
	typedef _MV_Vector_val<_Ty, _Ax> _Mybase;
	typedef typename _Mybase::_Alty _Alloc;
	typedef _Alloc allocator_type;
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type _Dift;
	typedef _Dift difference_type;
	typedef typename _Alloc::pointer _Tptr;
	typedef typename _Alloc::const_pointer _Ctptr;
	typedef _Tptr pointer;
	typedef _Ctptr const_pointer;
	typedef typename _Alloc::reference _Reft;
	typedef _Reft reference;
	typedef typename _Alloc::const_reference const_reference;
	typedef typename _Alloc::value_type value_type;

  #define _ITER_BASE(it)	(it)._Myptr
		// CLASS const_iterator
	class const_iterator;
	friend class const_iterator;

	class const_iterator
		: public _Ranit<_Ty, _Dift, _Ctptr, const_reference>
		{	// iterator for nonmutable vector
	public:
		typedef random_access_iterator_tag iterator_category;
		typedef _Ty value_type;
		typedef _Dift difference_type;
		typedef _Ctptr pointer;
		typedef const_reference reference;

		const_iterator()
			{	// construct with null pointer
			_Myptr = 0;
			}

		const_iterator(_Tptr _Ptr)
			{	// construct with pointer _Ptr
			_Myptr = _Ptr;
			}

		const_reference operator*() const
			{	// return designated object


			return (*_Myptr);
			}

		_Ctptr operator->() const
			{	// return pointer to class object
			return (&**this);
			}

		const_iterator& operator++()
			{	// preincrement
			++_Myptr;
			return (*this);
			}

		const_iterator operator++(int)
			{	// postincrement
			const_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		const_iterator& operator--()
			{	// predecrement
			--_Myptr;
			return (*this);
			}

		const_iterator operator--(int)
			{	// postdecrement
			const_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		const_iterator& operator+=(difference_type _Off)
			{	// increment by integer
			_Myptr += _Off;
			return (*this);
			}

		const_iterator operator+(difference_type _Off) const
			{	// return this + integer
			const_iterator _Tmp = *this;
			return (_Tmp += _Off);
			}

		const_iterator& operator-=(difference_type _Off)
			{	// decrement by integer
			return (*this += -_Off);
			}

		const_iterator operator-(difference_type _Off) const
			{	// return this - integer
			const_iterator _Tmp = *this;
			return (_Tmp -= _Off);
			}

		difference_type operator-(const const_iterator& _Right) const
			{	// return difference of iterators


			return (_Myptr - _Right._Myptr);
			}

		const_reference operator[](difference_type _Off) const
			{	// subscript
			return (*(*this + _Off));
			}

		bool operator==(const const_iterator& _Right) const
			{	// test for iterator equality


			return (_Myptr == _Right._Myptr);
			}

		bool operator!=(const const_iterator& _Right) const
			{	// test for iterator inequality
			return (!(*this == _Right));
			}

		bool operator<(const const_iterator& _Right) const
			{	// test if this < _Right


			return (_Myptr < _Right._Myptr);
			}

		bool operator>(const const_iterator& _Right) const
			{	// test if this > _Right
			return (_Right < *this);
			}

		bool operator<=(const const_iterator& _Right) const
			{	// test if this <= _Right
			return (!(_Right < *this));
			}

		bool operator>=(const const_iterator& _Right) const
			{	// test if this >= _Right
			return (!(*this < _Right));
			}

		friend const_iterator operator+(difference_type _Off,
			const const_iterator& _Right)
			{	// return iterator + integer
			return (_Right + _Off);
			}


		_Tptr _Myptr;	// offset of element in vector
		};

		// CLASS iterator
	class iterator;
	friend class iterator;

	class iterator
		: public const_iterator
		{	// iterator for mutable vector
	public:
		typedef random_access_iterator_tag iterator_category;
		typedef _Ty value_type;
		typedef _Dift difference_type;
		typedef _Tptr pointer;
		typedef _Reft reference;

		iterator()
			{	// construct with null vector pointer
			}

		iterator(pointer _Ptr)
			: const_iterator(_Ptr)
			{	// construct with pointer _Ptr
			}

		reference operator*() const
			{	// return designated object
			return ((reference)**(const_iterator *)this);
			}

		_Tptr operator->() const
			{	// return pointer to class object
			return (&**this);
			}

		iterator& operator++()
			{	// preincrement
			++this->_Myptr;
			return (*this);
			}

		iterator operator++(int)
			{	// postincrement
			iterator _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		iterator& operator--()
			{	// predecrement
			--this->_Myptr;
			return (*this);
			}

		iterator operator--(int)
			{	// postdecrement
			iterator _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		iterator& operator+=(difference_type _Off)
			{	// increment by integer
			this->_Myptr += _Off;
			return (*this);
			}

		iterator operator+(difference_type _Off) const
			{	// return this + integer
			iterator _Tmp = *this;
			return (_Tmp += _Off);
			}

		iterator& operator-=(difference_type _Off)
			{	// decrement by integer
			return (*this += -_Off);
			}

		iterator operator-(difference_type _Off) const
			{	// return this - integer
			iterator _Tmp = *this;
			return (_Tmp -= _Off);
			}

		difference_type operator-(const const_iterator& _Right) const
			{	// return difference of iterators
			return ((const_iterator)*this - _Right);
			}

		reference operator[](difference_type _Off) const
			{	// subscript
			return (*(*this + _Off));
			}

		friend iterator operator+(difference_type _Off,
			const iterator& _Right)
			{	// return iterator + integer
			return (_Right + _Off);
			}
		};

	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	TMvSTLVector()
		: _Mybase()
		{	// construct empty vector
		_Buy(0);
		}

	explicit TMvSTLVector(const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct empty vector with allocator
		_Buy(0);
		}

	explicit TMvSTLVector(size_type _Count)
		: _Mybase()
		{	// construct from _Count * _Ty()
		_Construct_n(_Count, _Ty());
		}

	TMvSTLVector(size_type _Count, const _Ty& _Val)
		: _Mybase()
		{	// construct from _Count * _Val
		_Construct_n(_Count, _Val);
		}

	TMvSTLVector(size_type _Count, const _Ty& _Val, const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct from _Count * _Val, with allocator
		_Construct_n(_Count, _Val);
		}

	TMvSTLVector(const _Myt& _Right)
		: _Mybase(_Right._Alval)
		{	// construct by copying _Right
		if (_Buy(_Right.size()))
			_TRY_BEGIN
			_Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
			_CATCH_ALL
			_Tidy();
			_RERAISE;
			_CATCH_END
		}

	template<class _Iter>
		TMvSTLVector(_Iter _First, _Iter _Last)
		: _Mybase()
		{	// construct from [_First, _Last)
		_Construct(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		TMvSTLVector(_Iter _First, _Iter _Last, const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct from [_First, _Last), with allocator
		_Construct(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Construct(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	// initialize with _Count * _Val
		size_type _Size = (size_type)_Count;
		_Construct_n(_Size, _Val);
		}

	template<class _Iter>
		void _Construct(_Iter _First,
			_Iter _Last, input_iterator_tag)
		{	// initialize with [_First, _Last), input iterators
		_Buy(0);
		_TRY_BEGIN
		insert(begin(), _First, _Last);
		_CATCH_ALL
		_Tidy();
		_RERAISE;
		_CATCH_END
		}

	void _Construct_n(size_type _Count, const _Ty& _Val)
		{	// construct from _Count * _Val
		if (_Buy(_Count))
			{	// nonzero, fill it
			_TRY_BEGIN
			_Mylast = _Ufill(_Myfirst, _Count, _Val);
			_CATCH_ALL
			_Tidy();
			_RERAISE;
			_CATCH_END
			}
		}

	~TMvSTLVector()
		{	// destroy the object
		_Tidy();
		}

	_Myt& operator=(const _Myt& _Right)
		{	// assign _Right
		if (this != &_Right)
			{	// worth doing


			if (_Right.size() == 0)
				clear();	// new sequence empty, free storage
			else if (_Right.size() <= size())
				{	// enough elements, copy new and destroy old
				pointer _Ptr = copy(_Right._Myfirst, _Right._Mylast,
					_Myfirst);	// copy new
				_Destroy(_Ptr, _Mylast);	// destroy old
				_Mylast = _Myfirst + _Right.size();
				}
			else if (_Right.size() <= capacity())
				{	// enough room, copy and construct new
				pointer _Ptr = _Right._Myfirst + size();
				copy(_Right._Myfirst, _Ptr, _Myfirst);
				_Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
				}
			else
				{	// not enough room, allocate new array and construct new
				if (_Myfirst != 0)
					{	// discard old array
					_Destroy(_Myfirst, _Mylast);
					this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
					}
				if (_Buy(_Right.size()))
					_Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast,
						_Myfirst);
				}
			}
		return (*this);
		}

	void reserve(size_type _Count)
		{	// determine new minimum length of allocated storage
		if (max_size() < _Count)
			_Xlen();	// result too long
		else if (capacity() < _Count)
			{	// not enough room, reallocate
			pointer _Ptr = this->_Alval.allocate(_Count);

			_TRY_BEGIN
			_Ucopy(begin(), end(), _Ptr);
			_CATCH_ALL
			this->_Alval.deallocate(_Ptr, _Count);
			_RERAISE;
			_CATCH_END

			size_type _Size = size();
			if (_Myfirst != 0)
				{	// destroy and deallocate old array
				_Destroy(_Myfirst, _Mylast);
				this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
				}


			_Myend = _Ptr + _Count;
			_Mylast = _Ptr + _Size;
			_Myfirst = _Ptr;
			}
		}

	size_type capacity() const
		{	// return current length of allocated storage
		return (_Myfirst == 0 ? 0 : _Myend - _Myfirst);
		}

	iterator begin()
		{	// return iterator for beginning of mutable sequence
		return (iterator(_Myfirst));
		}

	const_iterator begin() const
		{	// return iterator for beginning of nonmutable sequence
		return (const_iterator(_Myfirst));
		}

	iterator end()
		{	// return iterator for end of mutable sequence
		return (iterator(_Mylast));
		}

	const_iterator end() const
		{	// return iterator for end of nonmutable sequence
		return (const_iterator(_Mylast));
		}

	reverse_iterator rbegin()
		{	// return iterator for beginning of reversed mutable sequence
		return (reverse_iterator(end()));
		}

	const_reverse_iterator rbegin() const
		{	// return iterator for beginning of reversed nonmutable sequence
		return (const_reverse_iterator(end()));
		}

	reverse_iterator rend()
		{	// return iterator for end of reversed mutable sequence
		return (reverse_iterator(begin()));
		}

	const_reverse_iterator rend() const
		{	// return iterator for end of reversed nonmutable sequence
		return (const_reverse_iterator(begin()));
		}

	void resize(size_type _Newsize)
		{	// determine new length, padding with _Ty() elements as needed
		resize(_Newsize, _Ty());
		}

	void resize(size_type _Newsize, _Ty _Val)
		{	// determine new length, padding with _Val elements as needed
		if (size() < _Newsize)
			_Insert_n(end(), _Newsize - size(), _Val);
		else if (_Newsize < size())
			erase(begin() + _Newsize, end());
		}

	size_type size() const
		{	// return length of sequence
		return (_Myfirst == 0 ? 0 : _Mylast - _Myfirst);
		}

	size_type max_size() const
		{	// return maximum possible length of sequence
		return (this->_Alval.max_size());
		}

	bool empty() const
		{	// test if sequence is empty
		return (size() == 0);
		}

	_Alloc get_allocator() const
		{	// return allocator object for values
		return (this->_Alval);
		}

	const_reference at(size_type _Pos) const
		{	// subscript nonmutable sequence with checking
		if (size() <= _Pos)
			_Xran();
		return (*(begin() + _Pos));
		}

	reference at(size_type _Pos)
		{	// subscript mutable sequence with checking
		if (size() <= _Pos)
			_Xran();
		return (*(begin() + _Pos));
		}

	const_reference operator[](size_type _Pos) const
		{	// subscript nonmutable sequence
		return (*(begin() + _Pos));
		}

	reference operator[](size_type _Pos)
		{	// subscript mutable sequence
		return (*(begin() + _Pos));
		}

	reference front()
		{	// return first element of mutable sequence
		return (*begin());
		}

	const_reference front() const
		{	// return first element of nonmutable sequence
		return (*begin());
		}

	reference back()
		{	// return last element of mutable sequence
		return (*(end() - 1));
		}

	const_reference back() const
		{	// return last element of nonmutable sequence
		return (*(end() - 1));
		}

#if _MSC_VER > 1500 // VS2008 is 1500
	void push_back(const _Ty* _Val)
		{	// insert element at end
		if (size() < capacity())
			_Mylast = _Ufill(_Mylast, 1, _Val);
		else
			insert(end(), _Val);
		}
#else	
void push_back(const _Ty& _Val)
		{	// insert element at end
		if (size() < capacity())
			_Mylast = _Ufill(_Mylast, 1, _Val);
		else
			insert(end(), _Val);
		}
#endif

	void pop_back()
		{	// erase element at end
		if (!empty())
			{	// erase last element
			_Destroy(_Mylast - 1, _Mylast);
			--_Mylast;
			}
		}

	template<class _Iter>
		void assign(_Iter _First, _Iter _Last)
		{	// assign [_First, _Last)
		_Assign(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Assign(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	// assign _Count * _Val
		_Assign_n((size_type)_Count, (_Ty)_Val);
		}

	template<class _Iter>
		void _Assign(_Iter _First, _Iter _Last, input_iterator_tag)
		{	// assign [_First, _Last), input iterators
		erase(begin(), end());
		insert(begin(), _First, _Last);
		}

	void assign(size_type _Count, const _Ty& _Val)
		{	// assign _Count * _Val
		_Assign_n(_Count, _Val);
		}
#if _MSC_VER > 1500 // VS2008 is 1500
	iterator insert(iterator _Where, const _Ty* _Val)
		{	// insert _Val at _Where
		size_type _Off = size() == 0 ? 0 : _Where - begin();
		_Insert_n(_Where, (size_type)1, _Val);
		return (begin() + _Off);
		}

	void insert(iterator _Where, size_type _Count, const _Ty* _Val)
		{	// insert _Count * _Val at _Where
		_Insert_n(_Where, _Count, _Val);
		}
#else
	iterator insert(iterator _Where, const _Ty& _Val)
		{	// insert _Val at _Where
		size_type _Off = size() == 0 ? 0 : _Where - begin();
		_Insert_n(_Where, (size_type)1, _Val);
		return (begin() + _Off);
		}

	void insert(iterator _Where, size_type _Count, const _Ty& _Val)
		{	// insert _Count * _Val at _Where
		_Insert_n(_Where, _Count, _Val);
		}
#endif



	template<class _Iter>
		void insert(iterator _Where, _Iter _First, _Iter _Last)
		{	// insert [_First, _Last) at _Where
		_Insert(_Where, _First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Insert(iterator _Where, _Iter _First, _Iter _Last,
			_Int_iterator_tag)
		{	// insert _Count * _Val at _Where
		_Insert_n(_Where, (size_type)_First, (_Ty)_Last);
		}

	template<class _Iter>
		void _Insert(iterator _Where, _Iter _First, _Iter _Last,
			input_iterator_tag)
		{	// insert [_First, _Last) at _Where, input iterators
		for (; _First != _Last; ++_First, ++_Where)
			_Where = insert(_Where, *_First);
		}

	template<class _Iter>
		void _Insert(iterator _Where,
			_Iter _First, _Iter _Last, forward_iterator_tag)
		{	// insert [_First, _Last) at _Where, forward iterators
		size_type _Count = 0;
		_Distance(_First, _Last, _Count);
		size_type _Capacity = capacity();

		if (_Count == 0)
			;
		else if (max_size() - size() < _Count)
			_Xlen();	// result too long
		else if (_Capacity < size() + _Count)
			{	// not enough room, reallocate
			_Capacity = max_size() - _Capacity / 2 < _Capacity
				? 0 : _Capacity + _Capacity / 2;	// try to grow by 50%
			if (_Capacity < size() + _Count)
				_Capacity = size() + _Count;
			pointer _Newvec = this->_Alval.allocate(_Capacity);
			pointer _Ptr = _Newvec;

			_TRY_BEGIN
			_Ptr = _Ucopy(_Myfirst, _ITER_BASE(_Where),
				_Newvec);	// copy prefix
			_Ptr = _Ucopy(_First, _Last, _Ptr);	// add new stuff
			_Ucopy(_ITER_BASE(_Where), _Mylast, _Ptr);	// copy suffix
			_CATCH_ALL
			_Destroy(_Newvec, _Ptr);
			this->_Alval.deallocate(_Newvec, _Capacity);
			_RERAISE;
			_CATCH_END

			_Count += size();
			if (_Myfirst != 0)
				{	// destroy and deallocate old array
				_Destroy(_Myfirst, _Mylast);
				this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
				}
			_Myend = _Newvec + _Capacity;
			_Mylast = _Newvec + _Count;
			_Myfirst = _Newvec;
			}
		else if ((size_type)(end() - _Where) < _Count)
			{	// new stuff spills off end
			_Ucopy(_ITER_BASE(_Where), _Mylast,
				_ITER_BASE(_Where) + _Count);	// copy suffix
			_Iter _Mid = _First;
			advance(_Mid, end() - _Where);

			_TRY_BEGIN
			_Ucopy(_Mid, _Last, _Mylast);	// insert new stuff off end
			_CATCH_ALL
			_Destroy(_ITER_BASE(_Where) + _Count, _Mylast + _Count);
			_RERAISE;
			_CATCH_END

			_Mylast += _Count;
			copy(_First, _Mid, _ITER_BASE(_Where));	// insert to old end
			}
		else
			{	// new stuff can all be assigned
			pointer _Oldend = _Mylast;
			_Mylast = _Ucopy(_Oldend - _Count, _Oldend,
				_Mylast);	// copy suffix
			copy_backward(_ITER_BASE(_Where), _Oldend - _Count,
				_Oldend);	// copy hole
			copy(_First, _Last, _ITER_BASE(_Where));	// insert into hole
			}
		}

	iterator erase(iterator _Where)
		{	// erase element at where
		copy(_ITER_BASE(_Where) + 1, _Mylast, _ITER_BASE(_Where));
		_Destroy(_Mylast - 1, _Mylast);
		--_Mylast;
		return (_Where);
		}

	iterator erase(iterator _First, iterator _Last)
		{	// erase [_First, _Last)
		if (_First != _Last)
			{	// worth doing, copy down over hole
			pointer _Ptr = copy(_ITER_BASE(_Last), _Mylast,
				_ITER_BASE(_First));
			_Destroy(_Ptr, _Mylast);
			_Mylast = _Ptr;
			}
		return (_First);
		}

	void clear()
		{	// erase all
		_Tidy();
		}

	void swap(_Myt& _Right)
		{	// exchange contents with _Right
		if (this->_Alval == _Right._Alval)
			{	// same allocator, swap control information
			std::swap(_Myfirst, _Right._Myfirst);
			std::swap(_Mylast, _Right._Mylast);
			std::swap(_Myend, _Right._Myend);
			}
		else
			{	// different allocator, do multiple assigns
			_Myt _Ts = *this; *this = _Right, _Right = _Ts;
			}
		}

protected:
	void _Assign_n(size_type _Count, const _Ty& _Val)
		{	// assign _Count * _Val
		_Ty _Tmp = _Val;	// in case _Val is in sequence
		erase(begin(), end());
		insert(begin(), _Count, _Tmp);
		}

	bool _Buy(size_type _Capacity)
		{	// allocate array with _Capacity elements
		_Myfirst = 0, _Mylast = 0, _Myend = 0;
		if (_Capacity == 0)
			return (false);
		else if (max_size() < _Capacity)
			_Xlen();	// result too long
		else
			{	// nonempty array, allocate storage
			_Myfirst = this->_Alval.allocate(_Capacity);
			_Mylast = _Myfirst;
			_Myend = _Myfirst + _Capacity;
			}
		return (true);
		}

	void _Destroy(pointer _First, pointer _Last)
		{	// destroy [_First, _Last) using allocator
		_Destroy_range(_First, _Last, this->_Alval);
		}

	void _Tidy()
		{	// free all storage
		if (_Myfirst != 0)
			{	// something to free, destroy and deallocate it
			_Destroy(_Myfirst, _Mylast);
			this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
			}
		_Myfirst = 0, _Mylast = 0, _Myend = 0;
		}

	template<class _Iter>
		pointer _Ucopy(_Iter _First, _Iter _Last, pointer _Ptr)
		{	// copy initializing [_First, _Last), using allocator
		return (_Uninitialized_copy(_First, _Last,
			_Ptr, this->_Alval));
		}
#if _MSC_VER > 1500 // VS2008 is 1500
	void _Insert_n(iterator _Where,
		size_type _Count, const _Ty* _Val)
		{	// insert _Count * _Val at _Where
		_Ty _Tmp = *_Val;	// in case _Val is in sequence
		size_type _Capacity = capacity();

		if (_Count == 0)
			;
		else if (max_size() - size() < _Count)
			_Xlen();	// result too long
		else if (_Capacity < size() + _Count)
			{	// not enough room, reallocate
			_Capacity = max_size() - _Capacity / 2 < _Capacity
				? 0 : _Capacity + _Capacity / 2;	// try to grow by 50%
			if (_Capacity < size() + _Count)
				_Capacity = size() + _Count;
			pointer _Newvec = this->_Alval.allocate(_Capacity);
			pointer _Ptr = _Newvec;

			_TRY_BEGIN
			_Ptr = _Ucopy(_Myfirst, _ITER_BASE(_Where),
				_Newvec);	// copy prefix
			_Ptr = _Ufill(_Ptr, _Count, &_Tmp);	// add new stuff
			_Ucopy(_ITER_BASE(_Where), _Mylast, _Ptr);	// copy suffix
			_CATCH_ALL
			_Destroy(_Newvec, _Ptr);
			this->_Alval.deallocate(_Newvec, _Capacity);
			_RERAISE;
			_CATCH_END

			_Count += size();
			if (_Myfirst != 0)
				{	// destroy and deallocate old array
				_Destroy(_Myfirst, _Mylast);
				this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
				}
			_Myend = _Newvec + _Capacity;
			_Mylast = _Newvec + _Count;
			_Myfirst = _Newvec;
			}
		else if ((size_type)(_Mylast - _ITER_BASE(_Where)) < _Count)
			{	// new stuff spills off end
			_Ucopy(_ITER_BASE(_Where), _Mylast,
				_ITER_BASE(_Where) + _Count);	// copy suffix

			_TRY_BEGIN
			_Ufill(_Mylast, _Count - (_Mylast - _ITER_BASE(_Where)),
				&_Tmp);	// insert new stuff off end
			_CATCH_ALL
			_Destroy(_ITER_BASE(_Where) + _Count, _Mylast + _Count);
			_RERAISE;
			_CATCH_END

			_Mylast += _Count;
			fill(_ITER_BASE(_Where), _Mylast - _Count,
				_Tmp);	// insert up to old end
			}
		else
			{	// new stuff can all be assigned
			pointer _Oldend = _Mylast;
			_Mylast = _Ucopy(_Oldend - _Count, _Oldend,
				_Mylast);	// copy suffix
			copy_backward(_ITER_BASE(_Where), _Oldend - _Count,
				_Oldend);	// copy hole
			fill(_ITER_BASE(_Where), _ITER_BASE(_Where) + _Count,
				_Tmp);	// insert into hole
			}
		}

	pointer _Ufill(pointer _Ptr, size_type _Count, const _Ty *_Val)
		{	// copy initializing _Count * _Val, using allocator
		_Uninitialized_fill_n(_Ptr, _Count, _Val, this->_Alval);
		return (_Ptr + _Count);
		}
#else
void _Insert_n(iterator _Where,
		size_type _Count, const _Ty& _Val)
		{	// insert _Count * _Val at _Where
		_Ty _Tmp = _Val;	// in case _Val is in sequence
		size_type _Capacity = capacity();

		if (_Count == 0)
			;
		else if (max_size() - size() < _Count)
			_Xlen();	// result too long
		else if (_Capacity < size() + _Count)
			{	// not enough room, reallocate
			_Capacity = max_size() - _Capacity / 2 < _Capacity
				? 0 : _Capacity + _Capacity / 2;	// try to grow by 50%
			if (_Capacity < size() + _Count)
				_Capacity = size() + _Count;
			pointer _Newvec = this->_Alval.allocate(_Capacity);
			pointer _Ptr = _Newvec;

			_TRY_BEGIN
			_Ptr = _Ucopy(_Myfirst, _ITER_BASE(_Where),
				_Newvec);	// copy prefix
			_Ptr = _Ufill(_Ptr, _Count, _Tmp);	// add new stuff
			_Ucopy(_ITER_BASE(_Where), _Mylast, _Ptr);	// copy suffix
			_CATCH_ALL
			_Destroy(_Newvec, _Ptr);
			this->_Alval.deallocate(_Newvec, _Capacity);
			_RERAISE;
			_CATCH_END

			_Count += size();
			if (_Myfirst != 0)
				{	// destroy and deallocate old array
				_Destroy(_Myfirst, _Mylast);
				this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
				}
			_Myend = _Newvec + _Capacity;
			_Mylast = _Newvec + _Count;
			_Myfirst = _Newvec;
			}
		else if ((size_type)(_Mylast - _ITER_BASE(_Where)) < _Count)
			{	// new stuff spills off end
			_Ucopy(_ITER_BASE(_Where), _Mylast,
				_ITER_BASE(_Where) + _Count);	// copy suffix

			_TRY_BEGIN
			_Ufill(_Mylast, _Count - (_Mylast - _ITER_BASE(_Where)),
				_Tmp);	// insert new stuff off end
			_CATCH_ALL
			_Destroy(_ITER_BASE(_Where) + _Count, _Mylast + _Count);
			_RERAISE;
			_CATCH_END

			_Mylast += _Count;
			fill(_ITER_BASE(_Where), _Mylast - _Count,
				_Tmp);	// insert up to old end
			}
		else
			{	// new stuff can all be assigned
			pointer _Oldend = _Mylast;
			_Mylast = _Ucopy(_Oldend - _Count, _Oldend,
				_Mylast);	// copy suffix
			copy_backward(_ITER_BASE(_Where), _Oldend - _Count,
				_Oldend);	// copy hole
			fill(_ITER_BASE(_Where), _ITER_BASE(_Where) + _Count,
				_Tmp);	// insert into hole
			}
		}

	pointer _Ufill(pointer _Ptr, size_type _Count, const _Ty &_Val)
		{	// copy initializing _Count * _Val, using allocator
		_Uninitialized_fill_n(_Ptr, _Count, _Val, this->_Alval);
		return (_Ptr + _Count);
		}
#endif
	void _Xlen() const
		{	// report a length_error
		_THROW(length_error, "vector<T> too long");
		}

	void _Xran() const
		{	// report an out_of_range error
		_THROW(out_of_range, "invalid vector<T> subscript");
		}

public:
	pointer _Myfirst;	// pointer to beginning of array
	pointer _Mylast;	// pointer to current end of sequence
	pointer _Myend;	// pointer to end of array
	};

		// vector TEMPLATE FUNCTIONS
template<class _Ty, class _Alloc> inline
	bool operator==(const TMvSTLVector<_Ty, _Alloc>& _Left,
		const TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// test for vector equality
	return (_Left.size() == _Right.size()
		&& equal(_Left.begin(), _Left.end(), _Right.begin()));
	}

template<class _Ty, class _Alloc> inline
	bool operator!=(const TMvSTLVector<_Ty, _Alloc>& _Left,
		const TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// test for vector inequality
	return (!(_Left == _Right));
	}

template<class _Ty, class _Alloc> inline
	bool operator<(const TMvSTLVector<_Ty, _Alloc>& _Left,
		const TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// test if _Left < _Right for vectors
	return (lexicographical_compare(_Left.begin(), _Left.end(),
		_Right.begin(), _Right.end()));
	}

template<class _Ty, class _Alloc> inline
	bool operator>(const TMvSTLVector<_Ty, _Alloc>& _Left,
		const TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// test if _Left > _Right for vectors
	return (_Right < _Left);
	}

template<class _Ty, class _Alloc> inline
	bool operator<=(const TMvSTLVector<_Ty, _Alloc>& _Left,
		const TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// test if _Left <= _Right for vectors
	return (!(_Right < _Left));
	}

template<class _Ty, class _Alloc> inline
	bool operator>=(const TMvSTLVector<_Ty, _Alloc>& _Left,
		const TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// test if _Left >= _Right for vectors
	return (!(_Left < _Right));
	}

template<class _Ty, class _Alloc> inline
	void swap(TMvSTLVector<_Ty, _Alloc>& _Left, TMvSTLVector<_Ty, _Alloc>& _Right)
	{	// swap _Left and _Right vectors
	_Left.swap(_Right);
	}

		// CLASS vector<bool>
typedef unsigned _MV_Vbase;	// word type for vector<bool> representation
const int _VBITS = 8 * sizeof (_MV_Vbase);	// at least CHAR_BITS bits per word

template<class _Alloc>
	class TMvSTLVector<_Bool, _Alloc>
	{	// varying size array of bits
public:
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type _Dift;
	typedef TMvSTLVector<_MV_Vbase,
		typename _Alloc::template rebind<_MV_Vbase>::other>
			_MV_Vbtype;
	typedef TMvSTLVector<_Bool, _Alloc> _Myt;
	typedef _Dift difference_type;
	typedef _Bool _Ty;
	typedef _Alloc allocator_type;

	typedef bool const_reference;
	typedef bool value_type;


		// CLASS _Vb_iter_base
	class _Vb_iter_base
		: public _Ranit<_Bool, _Dift, value_type *, value_type>
		{	// store information common to reference and iterators
	public:
		_Vb_iter_base()
			: _Myoff(0), _Myptr(0)
			{	// construct with null pointer
			}

		_Vb_iter_base(_MV_Vbase *_Ptr)
			: _Myoff(0), _Myptr(_Ptr)
			{	// construct with offset and pointer
			}

		size_type _Myoff;
		_MV_Vbase *_Myptr;
		};

		// CLASS reference
	class reference
		: public _Vb_iter_base
		{	// reference to a bit within a base word
	public:
		reference()
			{	// construct with null pointer
			}

		reference(const _Vb_iter_base& _Right)
			: _Vb_iter_base(_Right)
			{	// construct with base
			}

		reference& operator=(const reference& _Right)
			{	// assign reference _Right to bit
			return (*this = bool(_Right));
			}

		reference& operator=(bool _Val)
			{	// assign _Val to bit
			if (_Val)
				*_Getptr() |= _Mask();
			else
				*_Getptr() &= ~_Mask();
			return (*this);
			}

		void flip()
			{	// toggle the bit
			*_Getptr() ^= _Mask();
			}

		bool operator~() const
			{	// test if bit is reset
			return (!bool(*this));
			}

		operator bool() const
			{	// test if bit is set
			return ((*_Getptr() & _Mask()) != 0);
			}

		_MV_Vbase *_Getptr() const
			{	// get pointer to base word


			return (this->_Myptr);
			}

	protected:
		_MV_Vbase _Mask() const
			{	// convert offset to mask
			return ((_MV_Vbase)(1 << this->_Myoff));
			}
		};

	typedef reference _Reft;

		// CLASS const_iterator
	class const_iterator
		: public _Vb_iter_base
		{	// iterator for nonmutable vector<bool>
	public:
		typedef random_access_iterator_tag iterator_category;
		typedef _Bool value_type;
		typedef _Dift difference_type;
		typedef const_reference *pointer;
		typedef const_reference reference;

		const_iterator()
			{	// construct with null reference
			}

		const_iterator(const _MV_Vbase *_Ptr)
			: _Vb_iter_base((_MV_Vbase *)_Ptr)

			{	// construct with offset and pointer
			}

		const_reference operator*() const
			{	// return (reference to) designated object
			return (_Reft(*this));
			}

		const_iterator& operator++()
			{	// preincrement
			_Inc();
			return (*this);
			}

		const_iterator operator++(int)
			{	// postincrement
			const_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		const_iterator& operator--()
			{	// predecrement
			_Dec();
			return (*this);
			}

		const_iterator operator--(int)
			{	// postdecrement
			const_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		const_iterator& operator+=(difference_type _Off)
			{	// increment by integer
			this->_Myoff += _Off;
			this->_Myptr += this->_Myoff / _VBITS;
			this->_Myoff %= _VBITS;
			return (*this);
			}

		const_iterator operator+(difference_type _Off) const
			{	// return this + integer
			const_iterator _Tmp = *this;
			return (_Tmp += _Off);
			}

		const_iterator& operator-=(difference_type _Off)
			{	// decrement by integer
			return (*this += -_Off);
			}

		const_iterator operator-(difference_type _Off) const
			{	// return this - integer
			const_iterator _Tmp = *this;
			return (_Tmp -= _Off);
			}

		difference_type operator-(const const_iterator _Right) const
			{	// return difference of iterators
			return (_VBITS * (this->_Myptr - _Right._Myptr)
				+ (difference_type)this->_Myoff
				- (difference_type)_Right._Myoff);
			}

		const_reference operator[](difference_type _Off) const
			{	// subscript
			return (*(*this + _Off));
			}

		bool operator==(const const_iterator& _Right) const
			{	// test for iterator equality
			return (this->_Myptr == _Right._Myptr && this->_Myoff == _Right._Myoff);
			}

		bool operator!=(const const_iterator& _Right) const
			{	// test for iterator inequality
			return (!(*this == _Right));
			}

		bool operator<(const const_iterator& _Right) const
			{	// test if this < _Right
			return (this->_Myptr < _Right._Myptr
				|| this->_Myptr == _Right._Myptr && this->_Myoff < _Right._Myoff);
			}

		bool operator>(const const_iterator& _Right) const
			{	// test if this > _Right
			return (_Right < *this);
			}

		bool operator<=(const const_iterator& _Right) const
			{	// test if this <= _Right
			return (!(_Right < *this));
			}

		bool operator>=(const const_iterator& _Right) const
			{	// test if this >= _Right
			return (!(*this < _Right));
			}

		friend const_iterator operator+(difference_type _Off,
			const const_iterator& _Right)
			{	// return iterator + integer
			return (_Right + _Off);
			}

	protected:
		void _Dec()
			{	// decrement bit position
			if (this->_Myoff != 0)
				--this->_Myoff;
			else
				this->_Myoff = _VBITS - 1, --this->_Myptr;
			}

		void _Inc()
			{	// increment bit position
			if (this->_Myoff < _VBITS - 1)
				++this->_Myoff;
			else
				this->_Myoff = 0, ++this->_Myptr;
			}
		};

		// CLASS iterator
	class iterator
		: public const_iterator
		{	// iterator for mutable vector<bool>
	public:
		typedef random_access_iterator_tag iterator_category;
		typedef _Bool value_type;
		typedef _Dift difference_type;
		typedef _Reft *pointer;
		typedef _Reft reference;

		iterator()
			{	// construct with null reference
			}

		iterator( _MV_Vbase *_Ptr)
			: const_iterator(_Ptr)
			{	// construct with offset and pointer
			}

		reference operator*() const
			{	// return (reference to) designated object
			return (_Reft(*this));
			}

		iterator& operator++()
			{	// preincrement
			++*(const_iterator *)this;
			return (*this);
			}

		iterator operator++(int)
			{	// postincrement
			iterator _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		iterator& operator--()
			{	// predecrement
			--*(const_iterator *)this;
			return (*this);
			}

		iterator operator--(int)
			{	// postdecrement
			iterator _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		iterator& operator+=(difference_type _Off)
			{	// increment by integer
			*(const_iterator *)this += _Off;
			return (*this);
			}

		iterator operator+(difference_type _Off) const
			{	// return this + integer
			iterator _Tmp = *this;
			return (_Tmp += _Off);
			}

		iterator& operator-=(difference_type _Off)
			{	// decrement by integer
			return (*this += -_Off);
			}

		iterator operator-(difference_type _Off) const
			{	// return this - integer
			iterator _Tmp = *this;
			return (_Tmp -= _Off);
			}

		difference_type operator-(const const_iterator _Right) const
			{	// return difference of iterators
			return (*(const_iterator *)this - _Right);
			}

		reference operator[](difference_type _Off) const
			{	// subscript
			return (*(*this + _Off));
			}

		friend iterator operator+(difference_type _Off,
			const iterator& _Right)
			{	// return iterator + integer
			return (_Right + _Off);
			}
		};

	typedef iterator pointer;
	typedef const_iterator const_pointer;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	TMvSTLVector()
		: _Mysize(0), _Myvec()
		{	// construct empty vector
		}

	explicit TMvSTLVector(const _Alloc& _Al)
		: _Mysize(0), _Myvec(_Al)
		{	// construct empty vector, with allocator
		}

	explicit TMvSTLVector(size_type _Count, bool _Val = false)
		: _Mysize(0), _Myvec(_Nw(_Count), (_MV_Vbase)(_Val ? -1 : 0))
		{	// construct from _Count * _Val
		_Trim(_Count);
		}

	TMvSTLVector(size_type _Count, bool _Val, const _Alloc& _Al)
		: _Mysize(0), _Myvec(_Nw(_Count), (_MV_Vbase)(_Val ? -1 : 0), _Al)
		{	// construct from _Count * _Val, with allocator
		_Trim(_Count);
		}

	template<class _Iter>
		TMvSTLVector(_Iter _First, _Iter _Last)
		: _Mysize(0), _Myvec()
		{	// construct from [_First, _Last)
		_BConstruct(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		TMvSTLVector(_Iter _First, _Iter _Last, const _Alloc& _Al)
		: _Mysize(0), _Myvec(_Al)
		{	// construct from [_First, _Last), with allocator
		_BConstruct(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _BConstruct(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	// initialize from _Count * _Val
		size_type _Num = (size_type)_Count;
		_Myvec.assign(_Num, (_Ty)_Val ? -1 : 0);
		_Trim(_Num);
		}

	template<class _Iter>
		void _BConstruct(_Iter _First, _Iter _Last, input_iterator_tag)
		{	// initialize from [_First, _Last), input iterators
		insert(begin(), _First, _Last);
		}

	~TMvSTLVector()
		{	// destroy the object
		_Mysize = 0;
		}

	void reserve(size_type _Count)
		{	// determine new minimum length of allocated storage
		_Myvec.reserve(_Nw(_Count));
		}

	size_type capacity() const
		{	// return current length of allocated storage
		return (_Myvec.capacity() * _VBITS);
		}

	iterator begin()
		{	// return iterator for beginning of mutable sequence
		return (iterator(_ITER_BASE(_Myvec.begin())));
		}

	const_iterator begin() const
		{	// return iterator for beginning of nonmutable sequence
		return (const_iterator(_ITER_BASE(_Myvec.begin())));
		}

	iterator end()
		{	// return iterator for end of mutable sequence
		iterator _Tmp = begin();
		if (0 < _Mysize)
			_Tmp += _Mysize;
		return (_Tmp);
		}

	const_iterator end() const
		{	// return iterator for end of nonmutable sequence
		const_iterator _Tmp = begin();
		if (0 < _Mysize)
			_Tmp += _Mysize;
		return (_Tmp);
		}

	reverse_iterator rbegin()
		{	// return iterator for beginning of reversed mutable sequence
		return (reverse_iterator(end()));
		}

	const_reverse_iterator rbegin() const
		{	// return iterator for beginning of reversed nonmutable sequence
		return (const_reverse_iterator(end()));
		}

	reverse_iterator rend()
		{	// return iterator for end of reversed mutable sequence
		return (reverse_iterator(begin()));
		}

	const_reverse_iterator rend() const
		{	// return iterator for end of reversed nonmutable sequence
		return (const_reverse_iterator(begin()));
		}

	void resize(size_type _Newsize, bool _Val = false)
		{	// determine new length, padding with _Val elements as needed
		if (size() < _Newsize)
			_Insert_n(end(), _Newsize - size(), _Val);
		else if (_Newsize < size())
			erase(begin() + _Newsize, end());
		}

	size_type size() const
		{	// return length of sequence
		return (_Mysize);
		}

	size_type max_size() const
		{	// return maximum possible length of sequence
		const size_type _Maxsize = _Myvec.max_size();
		return (_Maxsize < (size_type)(-1) / _VBITS
			? _Maxsize * _VBITS : (size_type)(-1));
		}

	bool empty() const
		{	// test if sequence is empty
		return (size() == 0);
		}

	_Alloc get_allocator() const
		{	// return allocator object for values
		return (_Myvec.get_allocator());
		}

	const_reference at(size_type _Off) const
		{	// subscript nonmutable sequence with checking
		if (size() <= _Off)
			_Xran();
		return (*(begin() + _Off));
		}

	reference at(size_type _Off)
		{	// subscript mutable sequence with checking
		if (size() <= _Off)
			_Xran();
		return (*(begin() + _Off));
		}

	const_reference operator[](size_type _Off) const
		{	// subscript nonmutable sequence
		return (*(begin() + _Off));
		}

	reference operator[](size_type _Off)
		{	// subscript mutable sequence
		return (*(begin() + _Off));
		}

	reference front()
		{	// return first element of mutable sequence
		return (*begin());
		}

	const_reference front() const
		{	// return first element of nonmutable sequence
		return (*begin());
		}

	reference back()
		{	// return last element of mutable sequence
		return (*(end() - 1));
		}

	const_reference back() const
		{	// return last element of nonmutable sequence
		return (*(end() - 1));
		}

	void push_back(bool _Val)
		{	// insert element at end
		insert(end(), _Val);
		}

	void pop_back()
		{	// erase element at end
		if (!empty())
			erase(end() - 1);
		}

	template<class _Iter>
		void assign(_Iter _First, _Iter _Last)
		{	// assign [_First, _Last)
		_Assign(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Assign(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	// assign _Count * _Val
		_Assign_n((size_type)_Count, (bool)_Val);
		}

	template<class _Iter>
		void _Assign(_Iter _First, _Iter _Last, input_iterator_tag)
		{	// assign [_First, _Last), input iterators
		erase(begin(), end());
		insert(begin(), _First, _Last);
		}

	void assign(size_type _Count, bool _Val)
		{	// assign _Count * _Val
		_Assign_n(_Count, _Val);
		}

	iterator insert(iterator _Where, bool _Val)
		{	// insert _Val at _Where
		size_type _Off = _Where - begin();
		_Insert_n(_Where, (size_type)1, _Val);
		return (begin() + _Off);
		}

	void insert(iterator _Where, size_type _Count, bool _Val)
		{	// insert _Count * _Val at _Where
		_Insert_n(_Where, _Count, _Val);
		}

	template<class _Iter>
		void insert(iterator _Where, _Iter _First, _Iter _Last)
		{	// insert [_First, _Last) at _Where
		_Insert(_Where, _First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Insert(iterator _Where, _Iter _Count, _Iter _Val,
			_Int_iterator_tag)
		{	// insert _Count * _Val at _Where
		_Insert_n(_Where, (size_type)_Count, (bool)_Val);
		}

	template<class _Iter>
		void _Insert(iterator _Where, _Iter _First, _Iter _Last,
			input_iterator_tag)
		{	// insert [_First, _Last) at _Where, input iterators
		size_type _Off = _Where - begin();

		for (; _First != _Last; ++_First, ++_Off)
			insert(begin() + _Off, *_First);
		}

	template<class _Iter>
		void _Insert(iterator _Where,
			_Iter _First, _Iter _Last,
			forward_iterator_tag)
		{	// insert [_First, _Last) at _Where, forward iterators


		size_type _Count = 0;
		_Distance(_First, _Last, _Count);

		size_type _Off = _Insert_x(_Where, _Count);
		copy(_First, _Last, begin() + _Off);
		}

	iterator erase(iterator _Where)
		{	// erase element at _Where
		size_type _Off = _Where - begin();

		copy(_Where + 1, end(), _Where);
		_Trim(_Mysize - 1);
		return (begin() + _Off);
		}

	iterator erase(iterator _First, iterator _Last)
		{	// erase [_First, _Last)
		size_type _Off = _First - begin();

		iterator _Next = copy(_Last, end(), _First);
		_Trim(_Next - begin());

		return (begin() + _Off);
		}

	void clear()
		{	// erase all elements
		erase(begin(), end());
		}

	void flip()
		{	// toggle all elements
		for (typename _MV_Vbtype::iterator _Next = _Myvec.begin();
			_Next != _Myvec.end(); ++_Next)
			*_Next = (_MV_Vbase)~*_Next;
		_Trim(_Mysize);
		}

	void swap(_Myt& _Right)
		{	// exchange contents with right
		std::swap(_Mysize, _Right._Mysize);
		_Myvec.swap(_Right._Myvec);
		}

	static void swap(reference _Left, reference _Right)
		{	// swap _Left and _Right vector<bool> elements
		bool _Val = _Left;
		_Left = _Right;
		_Right = _Val;
		}

protected:
	void _Assign_n(size_type _Count, bool _Val)
		{	// assign _Count * _Val
		erase(begin(), end());
		_Insert_n(begin(), _Count, _Val);
		}

	void _Insert_n(iterator _Where,
		size_type _Count, bool _Val)
		{	// insert _Count * _Val at _Where
		size_type _Off = _Insert_x(_Where, _Count);
		fill(begin() + _Off, begin() + (_Off + _Count), _Val);
		}

	size_type _Insert_x(iterator _Where, size_type _Count)
		{	// make room to insert _Count elements at _Where
		size_type _Off = _Where - begin();


		if (_Count == 0)
			;
		else if (max_size() - size() < _Count)
			_Xlen();	// result too long
		else
			{	// worth doing
			_Myvec.resize(_Nw(size() + _Count), 0);
			if (size() == 0)
				_Mysize += _Count;
			else
				{	// make room and copy down suffix
				iterator _Oldend = end();
				_Mysize += _Count;
				copy_backward(begin() + _Off, _Oldend, end());
				}

			}
		return (_Off);
		}

	static size_type _Nw(size_type _Count)
		{	// return number of base words from number of bits
		return ((_Count + _VBITS - 1) / _VBITS);
		}

	void _Trim(size_type _Size)
		{	// trim base vector to exact length in bits
		if (max_size() < _Size)
			_Xlen();	// result too long
		size_type _Words = _Nw(_Size);

		if (_Words < _Myvec.size())
			_Myvec.erase(_Myvec.begin() + _Words, _Myvec.end());
		_Mysize = _Size;
		_Size %= _VBITS;
		if (0 < _Size)
			_Myvec[_Words - 1] &= (_MV_Vbase)((1 << _Size) - 1);
		}

	void _Xlen() const
		{	// report a length_error
		_THROW(length_error, "vector<bool> too long");
		}

	void _Xran() const
		{	// throw an out_of_range error
		_THROW(out_of_range, "invalid vector<bool> subscript");
		}

public:
	size_type _Mysize;	// current length of sequence
	_MV_Vbtype _Myvec;	// base vector of words
	};

typedef TMvSTLVector<bool, allocator<bool> > _Bvector;

#pragma warning(default: 4244)
#pragma warning(pop)
#pragma pack(pop)

/*
 * Copyright (c) 1992-2002 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 */

/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this
 * software and its documentation for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Hewlett-Packard Company makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
 V3.13:0009
 */
