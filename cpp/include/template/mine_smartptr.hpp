/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine_smartptr.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:52:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/12 15:52:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

#include "portability.hpp"

// TODO: add
//	- weak pointer support
//	- intrusive pointer?

namespace mine {
template < typename T > class IntrusiveSharedPointer;
template < typename T > class SharedPointer;
template < typename T > class UniquePointer;
template < typename T > class APointer;

template < typename T > class APointer {
  public:
	enum PTRStrength {
		STRONG = 0,
		WEAK = 1,
	};

	virtual ~APointer() {}

	// [gets]
	virtual T		   &operator*(void) = 0;
	virtual const T	   &operator*(void) const = 0;
	virtual T		   *get(void) NOEXCEPT = 0;
	virtual const T	   *get(void) const NOEXCEPT = 0;
	virtual std::size_t use_count(void) const = 0;
	virtual PTRStrength getStrenght() const = 0;

	// [checks]
	virtual bool unique(void) const NOEXCEPT = 0;
	virtual bool exists(void) const NOEXCEPT = 0;

	// [converters]
	virtual UniquePointer< T > makeUnique(void) = 0;
	// virtual SharedPointer<T> makeShared(void) = 0; // TODO

	// [modifiers]
	virtual void reset(T *ptr = NULLPTR) NOEXCEPT = 0;

  private:
};

// intrusive version of shared pointer
template < typename T > class IntrusiveSharedPointer : public APointer< T > {
  public:
	// if count is not provided it'll expect T to have [incRef decRef] [getRef
	// setRef]
	IntrusiveSharedPointer(T *ptr) NOEXCEPT;
	IntrusiveSharedPointer(const IntrusiveSharedPointer &o) NOEXCEPT;
	~IntrusiveSharedPointer();
	IntrusiveSharedPointer &
	operator=(const IntrusiveSharedPointer &other) NOEXCEPT;

#if defined(__cplusplus) && __cplusplus >= 201103L
	IntrusiveSharedPointer(IntrusiveSharedPointer &&o) NOEXCEPT;
	IntrusiveSharedPointer &operator=(IntrusiveSharedPointer &&other) NOEXCEPT;
#endif

	// [gets]
	T				  &operator*(void);
	const T			  &operator*(void) const;
	T				  *get(void) NOEXCEPT;
	const T			  *get(void) const NOEXCEPT;
	std::size_t		   use_count(void) const;
	// [checks]
	bool			   unique(void) const NOEXCEPT;
	bool			   exists(void) const NOEXCEPT;
	// [converters]
	UniquePointer< T > makeUnique(void);
	// virtual IntrusiveSharedPointer<T> makeShared(void) = 0; // TODO
	// [modifiers]
	void			   reset(T *ptr = NULLPTR) NOEXCEPT;
	void			   swap(IntrusiveSharedPointer &other) NOEXCEPT;
	typename APointer< T >::PTRStrength getStrenght() const ;

  private:
	void		decRef(void);
	void		incRef(void);
	std::size_t getRef(void) const;

	void setRef(std::size_t nc);
	void resetRef(void); // when *refcount exist reset to NULL value;

	T								*_ptr;
	// ? custom deleter?
};

// no version of a intrusive unique pointer

// shared pointer
template < typename T > class SharedPointer : public APointer< T > {
  private:
	class Box {
	  public:
		// canonical form
		Box(T *ptr = NULLPTR) NOEXCEPT;
		Box(const Box &o) NOEXCEPT;
		~Box() NOEXCEPT;
		Box &operator=(const Box &other) NOEXCEPT;

#if defined(__cplusplus) && __cplusplus >= 201103L
		Box &operator=(Box &&other) NOEXCEPT;
#endif
		T	*operator*(void) const NOEXCEPT;
		T	*getPtr(void) const NOEXCEPT;
		void setPtr(T *ptr) NOEXCEPT;

		void setCustomDeleter(void (*customDeleter)(T *));
		void (*getCustomDeleter(void))(T *);
		void callCustomDeleter(void);

		std::size_t _strongcount; // count-> real object
		std::size_t _weakcount;	  // count-> box count
	  private:
		T	*_ptr;
		void (*_customDeleter)(T *);
	};

  public:
	// canonical form
	SharedPointer(T *ptr = NULLPTR) NOEXCEPT;
	SharedPointer(const SharedPointer &o) NOEXCEPT;
	~SharedPointer();
	SharedPointer &operator=(const SharedPointer &other) NOEXCEPT;

#if defined(__cplusplus) && __cplusplus >= 201103L
	SharedPointer(SharedPointer &&o) NOEXCEPT;
	SharedPointer &operator=(SharedPointer &&other) NOEXCEPT;
#endif

	// [gets]
	T										&operator*(void);
	const T									&operator*(void) const;
	T										*get(void) NOEXCEPT;
	const T									*get(void) const NOEXCEPT;
	std::size_t								 use_count(void) const;
	virtual typename APointer< T >::PTRStrength getStrenght() const {
		return (_strength);
	}
	std::size_t get_Strong_uc() const { return _box ? _box->_strongcount : 0; }
	std::size_t get_Weak_uc() const { return _box ? _box->_weakcount : 0;};

	// [checks]
	bool unique(void) const NOEXCEPT;
	bool exists(void) const NOEXCEPT;

	// [converters]
	UniquePointer< T > makeUnique(void);
	// virtual SharedPointer<T> makeShared(void) = 0; // TODO

	// [modifiers]
	void reset(T *ptr = NULLPTR) NOEXCEPT;
	void swap(SharedPointer &other) NOEXCEPT;

  protected:
	// [helpers]
	void del_check(void);
	void incCount(void) {
		if (!_box)
			return; // maybe throw?
		if (_strength == APointer< T >::WEAK)
			_box->_weakcount++;
		else
			_box->_strongcount++;
	}
	void decCount(void) {
		if (!_box)
			return; // maybe throw?
		if (_strength == APointer< T >::WEAK)
			_box->_weakcount--;
		else
			_box->_strongcount--;
	}

  private:
	Box								*_box;
	typename APointer< T >::PTRStrength _strength;
};

// unique pointer
template < typename T > class UniquePointer : public APointer< T > {
  public:
	// canonical form
	UniquePointer() NOEXCEPT;
	UniquePointer(T *ptr) NOEXCEPT;
	~UniquePointer();

#if defined(__cplusplus) && __cplusplus >= 201103L
	UniquePointer(const UniquePointer &o) = delete;
	UniquePointer(UniquePointer &&o) NOEXCEPT;
	UniquePointer &operator=(UniquePointer &&other) NOEXCEPT;
#endif

	// [gets]
	T		   &operator*(void);
	const T	   &operator*(void) const;
	T		   *get(void) NOEXCEPT;
	const T	   *get(void) const NOEXCEPT;
	std::size_t use_count(void) const;

	// [checks]
	bool unique(void) const NOEXCEPT;
	bool exists(void) const NOEXCEPT;

	// [converters]
	UniquePointer< T > makeUnique(void);
	T				  *release(void) NOEXCEPT;
	// virtual SharedPointer<T> makeShared(void) = 0; // TODO

	// [modifiers]
	void reset(T *ptr = NULLPTR) NOEXCEPT;
	void swap(UniquePointer &other) NOEXCEPT;

	virtual typename APointer< T >::PTRStrength getStrenght() const {
		return (APointer< T >::STRONG);
	}

  private:
	T *_ptr;
};

} // namespace mine

template < typename T >
std::ostream &operator<<(std::ostream &os, const mine::SharedPointer< T > &sp);
template < typename T >
std::ostream &operator<<(std::ostream &os, const mine::UniquePointer< T > &up);

// [implementations]
#include "box_impl.hpp"
#include "mine_smartptr_impl.hpp"
