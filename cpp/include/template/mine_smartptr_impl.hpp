/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine_smartptr_impl.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:52:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/12 15:52:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "mine_smartptr.hpp"
#include "portability.hpp"

using namespace mine;
// if count is not provided it'll expect T to have [incRef decRef] [getRef
// setRef]
template < typename T >
IntrusiveSharedPointer< T >::IntrusiveSharedPointer(T *ptr) NOEXCEPT
	: _ptr(ptr) {
	if (_ptr)
		incRef();
}
template < typename T >
IntrusiveSharedPointer< T >::IntrusiveSharedPointer(
	const IntrusiveSharedPointer &o) NOEXCEPT
	: _ptr(o._ptr) {
	if (_ptr)
		incRef();
}

template < typename T > IntrusiveSharedPointer< T >::~IntrusiveSharedPointer() {
	if (!_ptr)
		return;
	decRef();
	if (getRef() == 0)
		delete _ptr;
	_ptr = NULL;
}
template < typename T >
IntrusiveSharedPointer< T > &IntrusiveSharedPointer< T >::operator=(
	const IntrusiveSharedPointer &other) NOEXCEPT {
	if (this != &other) {
		if (this->_ptr != other._ptr && this->_ptr) {
			decRef();
			if (exists() && getRef() == 0)
				delete _ptr;
		}
		_ptr = other._ptr;
		incRef();
	}
	return (*this);
}

#if defined(__cplusplus) && __cplusplus >= 201103L
// construction by move -> no need to del or check del for _ptr
template < typename T >
IntrusiveSharedPointer< T >::IntrusiveSharedPointer(
	IntrusiveSharedPointer< T > &&o) NOEXCEPT : _ptr(o._ptr) {
	o._ptr = NULL;
}

template < typename T >
IntrusiveSharedPointer< T > &IntrusiveSharedPointer< T >::operator=(
	IntrusiveSharedPointer &&other) NOEXCEPT {
	if (this != &other) {
		if (exists()) {
			decRef();
			if (getRef() == 0)
				delete _ptr;
		}
		_ptr = other._ptr;
		_ptr = NULLPTR;
	}
	return (*this);
}
#endif

// [gets]
template < typename T > T &IntrusiveSharedPointer< T >::operator*(void) {
	return (*this->_ptr);
}
template < typename T >
const T &IntrusiveSharedPointer< T >::operator*(void) const {
	return (*this->_ptr);
}
template < typename T > T *IntrusiveSharedPointer< T >::get(void) NOEXCEPT {
	return (this->_ptr);
}
template < typename T >
const T *IntrusiveSharedPointer< T >::get(void) const NOEXCEPT {
	return (this->_ptr);
}
template < typename T >
std::size_t IntrusiveSharedPointer< T >::use_count(void) const {
	return (getRef());
}
template <typename T >
typename APointer<T>::PTRStrength IntrusiveSharedPointer<T>::getStrenght(void) const  {
	return (APointer<T>::STRONG);
}
// [checks]
template < typename T >
bool IntrusiveSharedPointer< T >::unique(void) const NOEXCEPT {
	return (getRef() == 1);
}

template < typename T >
bool IntrusiveSharedPointer< T >::exists(void) const NOEXCEPT {
	return (_ptr != NULL);
}
// [converters]
template < typename T >
UniquePointer< T > IntrusiveSharedPointer< T >::makeUnique(void) {
	if (unique() == false)
		throw std::runtime_error(
			"Cannot make unique from non-unique IntrusiveSharedPointer");
	UniquePointer< T > up(this->_ptr);
	this->_ptr = NULLPTR;
	decRef(); // will be del-ed when out of scope
	return (up);
}
// virtual IntrusiveSharedPointer<T> makeShared(void) = 0; // TODO
// [modifiers]
template < typename T >
void IntrusiveSharedPointer< T >::reset(T *ptr) NOEXCEPT {
	if (get() == ptr)
		return;
	decRef();
	if (getRef() == 0 && _ptr)
		delete _ptr;
	this->_ptr = ptr;
	incRef();
}
template < typename T >
void IntrusiveSharedPointer< T >::swap(IntrusiveSharedPointer &other) NOEXCEPT {
	T *tmp;

	tmp = _ptr;
	_ptr = other._ptr;
	other._ptr = tmp;
	return;
}

template < typename T > void IntrusiveSharedPointer< T >::decRef(void) {
	if (_ptr)
		return (_ptr->decRef());
	throw std::runtime_error("Dereferencing a null pointer");
}
template < typename T > void IntrusiveSharedPointer< T >::incRef(void) {
	if (_ptr)
		return (_ptr->incRef());
	throw std::runtime_error("Dereferencing a null pointer");
}
template < typename T >
std::size_t IntrusiveSharedPointer< T >::getRef(void) const {
	if (_ptr)
		return (_ptr->getRef());
	return (0); // maybe -1?
}

template < typename T >
void IntrusiveSharedPointer< T >::setRef(std::size_t nc) {
	if (_ptr)
		return (_ptr->setRef(nc));
	throw std::runtime_error("Dereferencing a null pointer");
}

template < typename T > void IntrusiveSharedPointer< T >::resetRef(void) {
	setRef(0);
}

// intrusive shared end

// Shared pointer start

// canonical 5 form
template < typename T >
SharedPointer< T >::SharedPointer(T *ptr) NOEXCEPT : _box(new Box(ptr)),
	APointer<T>::_strenght(APointer<T>::STRONG) {
	this->incCount();
}

template < typename T >
SharedPointer< T >::SharedPointer(const SharedPointer &o) NOEXCEPT
	: _box(o._box), APointer<T>::_strenght(APointer<T>::WEAK) {
	if (_box)
		this->incCount();
}
template < typename T > SharedPointer< T >::~SharedPointer() {
	if (_box)
		this->decCount();
	this->del_check();
	this->_box = NULLPTR;
}
template < typename T >
SharedPointer< T > &
SharedPointer< T >::operator=(const SharedPointer &other) NOEXCEPT {
	if (this != &other) {
		if (_box) {
			this->decCount();
			this->del_check();
		}
		this->_box = other._box;
		_strength = APointer<T>::WEAK; // any copy construction is weak by default
		if (_box)
			this->incCount();
	}
	return *this;
}

#if defined(__cplusplus) && __cplusplus >= 201103L
// move semantics
template < typename T >
SharedPointer< T >::SharedPointer(SharedPointer &&o) NOEXCEPT : _box(o._box),
	_strength(o._strength) {
	o._box = NULLPTR;
	o._strength = 0;
}

template < typename T >
SharedPointer< T > &
SharedPointer< T >::operator=(SharedPointer &&other) NOEXCEPT {
	if (this != &other) {
		if (_box) {
			_box->decCount();
			del_check();
		}
		this->_box = other._box;
		other._box = NULLPTR;
		_strength = other.getStrenght();
		other._strength = 0;
	}
	return *this;
}
#endif

// [getters]
// direct value accessors
template < typename T > T &SharedPointer< T >::operator*(void) {
	if (_box && _box->getPtr())
		return *(_box->getPtr());
	throw std::runtime_error("Dereferencing a null pointer");
}
template < typename T > const T &SharedPointer< T >::operator*(void) const {
	if (_box && _box->getPtr())
		return *(_box->getPtr());
	throw std::runtime_error("Dereferencing a null pointer");
}
// indirect value accessors
template < typename T > T *SharedPointer< T >::get(void) NOEXCEPT {
	if (_box)
		return _box->getPtr();
	return NULLPTR;
}
template < typename T > const T *SharedPointer< T >::get(void) const NOEXCEPT {
	if (_box)
		return _box->getPtr();
	return NULLPTR;
}
// infos
template < typename T > std::size_t SharedPointer< T >::use_count(void) const {
	if (_box)
		return _box->_strongcount + _box->_weakcount;
	return (0);
}
// [checks]
template < typename T > bool SharedPointer< T >::unique(void) const NOEXCEPT {
	if (!exists())
		return false;
	return (use_count() == 1);
}
template < typename T > bool SharedPointer< T >::exists(void) const NOEXCEPT {
	return (_box != NULLPTR && _box->getPtr() != NULLPTR);
}

// protected
// [macros/helpers]
template < typename T > void SharedPointer< T >::del_check(void) {
	if (!_box || _box->_strongcount != 0)
		return;
	if (_box->getPtr())
		delete _box->getPtr();
	if (_box->_weakcount == 0)
	{
		delete _box;
		_box = NULLPTR;
	}
}
// [converters]
template < typename T >
UniquePointer< T > SharedPointer< T >::makeUnique(void) {
	if (!unique())
		throw std::runtime_error(
			"Cannot make unique from non-unique SharedPointer");
	if (!_box)
		throw std::runtime_error("Cannot make unique from null SharedPointer");
	T *ptr = this->_box->getPtr();
	_box->setPtr(NULLPTR);
	_box->decCount();
	del_check();
	return UniquePointer< T >(ptr);
}

// [modifiers]
template < typename T > void SharedPointer< T >::reset(T *ptr) NOEXCEPT {
	if (this->_box) {
		_box->decCount();
		this->del_check();
	}
	this->_box = new Box(ptr);
}

template < typename T >
void SharedPointer< T >::swap(SharedPointer &other) NOEXCEPT {
	if (this != &other) {
		if (*(*this) != *other) { // avoid swapping same pointers
			Box *temp = this->_box;
			this->_box = other._box;
			other._box = temp;
		}
	}
	return;
}

// end of SharedPointer

// ------------------------------------------------------
// UniquePointer
// ------------------------------------------------------

// canonical form
template < typename T >
UniquePointer< T >::UniquePointer() NOEXCEPT : _ptr(NULLPTR) {}
template < typename T >
UniquePointer< T >::UniquePointer(T *ptr) NOEXCEPT : _ptr(ptr) {}
template < typename T > UniquePointer< T >::~UniquePointer() {
	if (_ptr)
		delete _ptr;
}

#if defined(__cplusplus) && __cplusplus >= 201103L
// move semantics
template < typename T >
UniquePointer< T >::UniquePointer(UniquePointer &&o) NOEXCEPT : _ptr(o._ptr) {
	o._ptr = NULLPTR;
}
template < typename T >
UniquePointer< T > &
UniquePointer< T >::operator=(UniquePointer &&other) NOEXCEPT {
	if (this != &other) {
		if (this->_ptr)
			delete this->_ptr;
		this->_ptr = other._ptr;
		other._ptr = NULLPTR;
	}
	return *this;
}
#endif

// [getters]
// direct value accessors
template < typename T > T &UniquePointer< T >::operator*(void) {
	if (this->get())
		return *(this->get());
	throw std::runtime_error("Dereferencing a null pointer");
}
template < typename T > const T &UniquePointer< T >::operator*(void) const {
	if (this->get())
		return *(this->get());
	throw std::runtime_error("Dereferencing a null pointer");
}
// indirect value accessors
template < typename T > T *UniquePointer< T >::get(void) NOEXCEPT {
	return this->_ptr;
}
template < typename T > const T *UniquePointer< T >::get(void) const NOEXCEPT {
	return this->_ptr;
}
// infos
template < typename T > std::size_t UniquePointer< T >::use_count(void) const {
	if (this->exists())
		return 1;
	return 0;
}

// [checks]
template < typename T > bool UniquePointer< T >::unique(void) const NOEXCEPT {
	if (this->exists())
		return true;
	return false;
}
template < typename T > bool UniquePointer< T >::exists(void) const NOEXCEPT {
	return (this->_ptr != NULLPTR);
}

// [converters]
template < typename T >
UniquePointer< T > UniquePointer< T >::makeUnique(void) {
	if (!this->exists())
		throw std::runtime_error("Cannot make unique from null UniquePointer");
	return UniquePointer< T >(this->release());
}

// [modifiers]
template < typename T > T *UniquePointer< T >::release(void) NOEXCEPT {
	T *temp = this->_ptr;
	this->_ptr = NULLPTR;
	return temp;
}
template < typename T > void UniquePointer< T >::reset(T *ptr) NOEXCEPT {
	if (this->_ptr)
		delete this->_ptr;
	this->_ptr = ptr;
}
template < typename T >
void UniquePointer< T >::swap(UniquePointer &other) NOEXCEPT {
	T *temp = this->_ptr;
	this->_ptr = other._ptr;
	other._ptr = temp;
}

// ----
// prints

template < typename T >
std::ostream &operator<<(std::ostream &os, const mine::SharedPointer< T > &sp) {
	if (sp.get())
		return (os << *sp);
	return (os << "null");
}

template < typename T >
std::ostream &operator<<(std::ostream &os, const mine::UniquePointer< T > &up) {
	if (up.get())
		return (os << *up);
	return (os << "null");
}
