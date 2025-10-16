/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 06:21:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/13 06:21:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <cstdlib>
#include <iostream>

#include "mine.hpp"
#include "portability.hpp"

using namespace mine;

class int_rc {
  public:
	int_rc(int start = 0) : a(start), ref_c(0) {}
	~int_rc() {}
	int_rc(const int_rc &o) = delete;

	int			a;
	std::size_t ref_c;
	void		incRef(void) {
		   ref_c++;
	}
	void decRef(void) {
		ref_c--;
	}
	std::size_t getRef(void) const {
		return ref_c;
	}
	void setRef(std::size_t s) {
		ref_c = s;
	}
	bool operator==(const int_rc &o) {
		return (this->a == o.a);
	}
};

template < typename T >
static void disp_shrd_info(const SharedPointer< T > &sp, const char *vname) {
	std::cout << vname << ":{" << std::endl;
	try {
		std::cout << "\tget: " << sp.get() << "\t*: " << *sp
				  << "\tuse_count:" << sp.use_count() << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << "\t" << e.what() << std::endl;
	}
	std::cout << "}" << std::endl;
}

// Legacy test dont wanna re-write them
static int legacy_tests() {
	SharedPointer< int > sp1(new int(42));

#ifdef VERBOSE
	std::cout << "initial state:" << std::endl;
	disp_shrd_info(sp1, "sp1");
#endif
	{
		SharedPointer< int > sp2 = sp1;

#ifdef VERBOSE
		std::cout << "sp1 + sp2" << std::endl;
		disp_shrd_info(sp1, STRINGIFY(sp1));
		disp_shrd_info(sp2, STRINGIFY(sp2));
#endif

		{
			SharedPointer< int > sp3(sp2);
#ifdef VERBOSE
			std::cout << "Entering inner scope" << std::endl;
			disp_shrd_info(sp3, STRINGIFY(sp3));
			disp_shrd_info(sp1, STRINGIFY(sp1));
			disp_shrd_info(sp2, STRINGIFY(sp2));
#endif
			assert(sp1.use_count() == 3); //"use_count should be 3"
			assert(sp2.use_count() == 3); //"use_count should be 3"
			assert(sp3.use_count() == 3); //"use_count should be 3"
			assert(sp1.use_count() ==
				   sp2.use_count());		// if prev worked this should too
			assert(sp1.get() == sp2.get()); // should be the same
			assert(sp2.get() == sp3.get()); // should be the same
		}
#ifdef VERBOSE
		std::cout << "re-Entering out scope" << std::endl;
		std::cout << "sp1 + sp2" << std::endl;
		disp_shrd_info(sp1, STRINGIFY(sp1));
		disp_shrd_info(sp2, STRINGIFY(sp2));
		std::cout << "Modifying value pointed to by sp2 to 84" << std::endl;
#endif
		*sp2 = 84;

#ifdef VERBOSE
		std::cout << "sp1 + sp2" << std::endl;
		disp_shrd_info(sp1, STRINGIFY(sp1));
		disp_shrd_info(sp2, STRINGIFY(sp2));
#endif
		assert(sp1.use_count() == 2);  //"use_count should be 2"
		assert(sp2.use_count() == 2);  //"use_count should be 2"
		assert(*sp1 == 84);			   //"Value pointed to by sp1 should be 84"
		assert(*sp2 == 84);			   //"Value pointed to by sp2 should be 84"
		assert(sp1.unique() == false); //"sp1 should not be unique"
		assert(sp2.unique() == false); //"sp2 should not be unique"
		assert(sp1.get() ==
			   sp2.get()); //"sp1 and sp2 should point to the same address"
		assert(*sp1 ==
			   *sp2); //"Value pointed to by sp1 and sp2 should be the same"
	}
#ifdef VERBOSE
	std::cout << "After sp2 out of scope" << std::endl;
	disp_shrd_info(sp1, STRINGIFY(sp1));
#endif
	assert(sp1.use_count() == 1); //"use_count should be 1"
	assert(*sp1 == 84);			  //"Value pointed to by sp1 should still be 84"
	assert(sp1.unique() == true); //"sp1 should be unique now"

	mine::UniquePointer< int > u1 = sp1.makeUnique();
	assert(sp1.get() == NULLPTR); //"sp1 should be null after makeUnique"
	assert(u1.get() != NULLPTR);  //"u1 should not be null after makeUnique"
	assert(*u1 == 84);			  //"Value pointed to by u1 should be 84"
#ifdef VERBOSE
	std::cout << "After makeUnique" << std::endl;
	std::cout << "sp1 exist?: " << (sp1.get() != NULLPTR ? "yes" : "no")
			  << std::endl;
	disp_shrd_info(sp1, STRINGIFY(sp1));
	std::cout << "Value pointed to by u1: " << *u1 << std::endl;
	std::cout << "Adress pointed to by u1: " << u1.get() << std::endl;
#endif
	return 0;
}
void tests(void);

// TODO: refactor tests on Sharepointer
void tests(void) {
	try {
		if (legacy_tests())
			throw std::runtime_error("Legacy tests failed");
	} catch (...) {
	}
	// null sp
	try {
		SharedPointer< int > sp_null;
	} catch (...) {
		std::cerr << "Exception caught during null sp creation/destruction"
				  << std::endl;
	}
	// pre-released sp
	try {
		SharedPointer< int > sp1(new int(21));
		SharedPointer< int > sp2 = sp1;

		sp2.~SharedPointer(); // ~ => sp2 will call ~ twice
	} catch (std::exception &e) {
		std::cerr << "Exception caught during pre-released sp destruction: "
				  << e.what() << std::endl;
	}
	// pre-released sp [multiple]
	// no mem leaks / crash allowed
	try {
		SharedPointer< int > sp1(new int(21));
		SharedPointer< int > sp2 = sp1;

		sp2.~SharedPointer();
		sp2.~SharedPointer();
		sp2.~SharedPointer();
		sp2.~SharedPointer();
		sp2.~SharedPointer();
		sp1.~SharedPointer();
		sp1.~SharedPointer();
		sp1.~SharedPointer();
		sp1.~SharedPointer();
		sp1.~SharedPointer();
		sp1.~SharedPointer();
	} catch (std::exception &e) {
		std::cerr << "Exception caught during pre-released sp destruction: "
				  << e.what() << std::endl;
	}

	try {
		SharedPointer< int > sp1(new int(21));
		SharedPointer< int > sp2 = sp1;
		UniquePointer< int > u1;

		try {
			u1 = sp1.makeUnique();
		} catch (std::runtime_error &e) {
			UNUSED_PARAM(e);
			// make unique intended to fail here as sp2 exists
		}
	} catch (std::exception &e) {
		std::cerr << "Unexpected exception caught during makeUnique test"
				  << std::endl
				  << e.what() << std::endl;
	}
	// member functions Sharedptrs
	try {
		int					*raw = new int(42);
		SharedPointer< int > sp(raw);

		assert(sp.exists());
		assert(sp.unique());
		assert(sp.use_count() == 1);
		assert(sp.get() != NULLPTR);
		assert(sp.get() == raw);
		assert(*sp == 42);
		assert(*sp == *raw);
		*sp = 84;
		assert(*sp == 84);
		assert(*sp == *raw);
		sp.reset(); // reset internal box of container
		assert(sp.get() == NULLPTR);
		assert(sp.exists() == false);
		assert(sp.unique() == false);
		assert(sp.use_count() == 1); // uses null as ptr for box,
		// box used by sp, so use_count is 1 ... should maybe have a way to
		// set it to 0 explicitly ? maybe a clear?
		sp.reset(new int(21)); // no memory leak should occur
		sp.reset(new int(99)); // no memory leak should occur

		assert(sp.exists());
		assert(sp.unique());
		assert(sp.use_count() == 1);
		assert(sp.get() != NULLPTR);
		assert(*sp == 99);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Shared: ok" << std::endl;

	// no tests
	std::cout << "Uniq: ok" << std::endl;

	// intrusive shared
	std::cout << "intrusive Shared:";
	try {
		{
			IntrusiveSharedPointer< int_rc > isp(NULLPTR);
			assert(isp.unique() == false);
			assert(isp.use_count() == 0);
			assert(isp.get() == NULLPTR);
			assert(isp.exists() == false);
		}
		{
			int_rc							*raw = new int_rc(21);
			IntrusiveSharedPointer< int_rc > sp1(raw);
			assert(sp1.use_count() == 1);
			assert(sp1.unique() == true);
			assert(sp1.exists() == true);
			assert(sp1.get() == raw);
			assert(*sp1 == *raw);
			(*sp1).a = 42;
			assert(raw->a == 42);
		}
		{
			int_rc							*raw = new int_rc(21);
			IntrusiveSharedPointer< int_rc > sp1(raw);
			IntrusiveSharedPointer< int_rc > sp2 = sp1;
			assert(sp1.exists() == true);
			assert(sp1.exists() == sp2.exists());
			assert(sp1.get() == raw);
			assert(sp1.get() == sp2.get());
			assert(raw->ref_c == 2);
			assert(sp1.use_count() == sp2.use_count());
			assert(sp1.unique() == false);
			assert(*sp1 == *sp2);
			(*sp1).a = 42;
			assert(raw->a == 42);
			assert(*sp1 == *sp2);
			assert((*sp1).a == 42);
		}
		{
			int_rc							*raw = new int_rc(21);
			IntrusiveSharedPointer< int_rc > sp1(raw);
			IntrusiveSharedPointer< int_rc > sp2 = sp1;

			assert(raw->ref_c == 2);
			assert(sp1.use_count() == sp2.use_count());
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			// sp2
			assert(sp2.exists() == false);
			assert(sp2.get() == NULLPTR);
			assert(sp2.unique() == false);
			assert(sp2.use_count() == 0);
			// sp1
			assert(sp1.use_count() == 1);
			assert(sp1.use_count() == raw->ref_c);
			assert(sp1.get() == raw);
			assert(sp1.get()->a == raw->a);
		}
		{
			int_rc							*raw = new int_rc(21);
			IntrusiveSharedPointer< int_rc > sp1(raw);
			IntrusiveSharedPointer< int_rc > sp2 = sp1;

			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends

			// sp2
			assert(sp2.exists() == false);
			assert(sp2.get() == NULLPTR);
			assert(sp2.unique() == false);
			assert(sp2.use_count() == 0);
			// sp1
			assert(sp1.use_count() == 1);
			assert(sp1.use_count() == raw->ref_c);
			assert(sp1.get() == raw);
			assert(sp1.get()->a == raw->a);
		}
		{
			int_rc							*raw = new int_rc(21);
			IntrusiveSharedPointer< int_rc > sp1(raw);
			IntrusiveSharedPointer< int_rc > sp2 = sp1;
			IntrusiveSharedPointer< int_rc > sp3 = sp2;

			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp2.~IntrusiveSharedPointer(); // explicit destructor before ends

			// sp2
			assert(sp2.exists() == false);
			assert(sp2.get() == NULLPTR);
			assert(sp2.unique() == false);
			assert(sp2.use_count() == 0);
			// sp3
			assert(sp3.use_count() == 2);
			assert(sp3.use_count() == raw->ref_c);
			assert(sp3.get() == raw);
			assert(sp3.get()->a == raw->a);
			// sp1
			assert(sp1.use_count() == 2);
			assert(sp1.use_count() == raw->ref_c);
			assert(sp1.get() == raw);
			assert(sp1.get()->a == raw->a);

			sp3.~IntrusiveSharedPointer(); // explicit destructor before ends
			sp3.~IntrusiveSharedPointer(); // explicit destructor before ends
			// sp2
			assert(sp2.exists() == false);
			assert(sp2.get() == NULLPTR);
			assert(sp2.unique() == false);
			assert(sp2.use_count() == 0);
			// sp2
			assert(sp3.exists() == false);
			assert(sp3.get() == NULLPTR);
			assert(sp3.unique() == false);
			assert(sp3.use_count() == 0);
			// sp1
			assert(sp1.use_count() == 1);
			assert(sp1.use_count() == raw->ref_c);
			assert(sp1.get() == raw);
			assert(sp1.get()->a == raw->a);
		}
		std::cout << " ok" << std::endl;
	} catch (std::exception &e) {
		std::cout << " ko (" << e.what() << ")" << std::endl;
	};

	std::cout << "smart pointers : ok" << std::endl;
}

int main(int argc, char *argv[]) {
	UNUSED_PARAM(argc);
	UNUSED_PARAM(argv);

	if (legacy_tests() != 0) {
		std::cerr << "Legacy tests failed" << std::endl;
		return EXIT_FAILURE;
	}
	tests();
	return EXIT_SUCCESS;
}
