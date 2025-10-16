/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:29:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/12 15:52:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "mine_smartptr.hpp"

using namespace mine;

// typename befere SharedPointer<T>::Box returns as Box is a nested type that
// needs to be derived from the template parameter T of the enclosing class
//
// a bit unclear

// canonical 5 form
template < typename T >
SharedPointer< T >::Box::Box(T *ptr) NOEXCEPT : _ptr(ptr),
												_strongcount(0),
												_weakcount(0) {}
template < typename T >
SharedPointer< T >::Box::Box(const Box &o) NOEXCEPT : _ptr(o._ptr),
													  _strongcount(o._strongcount),
													  _weakcount(o._weakcount) {}
template < typename T > SharedPointer< T >::Box::~Box() NOEXCEPT {}

#if defined(__cplusplus) && __cplusplus >= 201103L
template < typename T >
typename SharedPointer< T >::Box &
SharedPointer< T >::Box::operator=(Box &&other) NOEXCEPT {
	if (this != &other) {
		_ptr = other._ptr;
		_strongcount = other._strongcount;
		_weakcount = other._weakcount;
		other._ptr = NULLPTR;
		other._strongcount = 0;
	}
	return *this;
}
#endif

template < typename T >
typename SharedPointer< T >::Box &
SharedPointer< T >::Box::operator=(const Box &other) NOEXCEPT {
	if (this != &other) {
		_ptr = other._ptr;
		_strongcount = other._strongcount;
	}
	return *this;
}

template < typename T >
T *SharedPointer< T >::Box::operator*(void) const NOEXCEPT {
	return this->getPtr();
}
template < typename T >
T *SharedPointer< T >::Box::getPtr(void) const NOEXCEPT {
	return _ptr;
}
template < typename T > void SharedPointer< T >::Box::setPtr(T *ptr) NOEXCEPT {
	_ptr = ptr;
}

template < typename T >
void SharedPointer< T >::Box::setCustomDeleter(void (*f)(T *)) {
	this->_customDeleter = f;
}

template < typename T >
void (*SharedPointer< T >::Box::getCustomDeleter(void))(T *) {
	return this->_customDeleter;
}

template < typename T > void SharedPointer< T >::Box::callCustomDeleter(void) {
	if (this->_customDeleter && this->_ptr)
		this->_customDeleter(this->_ptr);
}
