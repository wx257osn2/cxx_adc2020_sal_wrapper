all: test

SALW_CXX_VERSION ?= c++2a

sal_wrapper.hpp-must-not-contain-SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION-identifier: sal_wrapper.hpp
	:; ! grep SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION sal_wrapper.hpp

test1_$(SALW_CXX_VERSION): super-awesome-library-that-has-breaking-changes-frequently.hpp sal_wrapper.hpp main.cpp
	g++ -std=$(SALW_CXX_VERSION) -Wall -Wextra -pedantic-errors -o $@ -DSUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION=1 main.cpp


test2_$(SALW_CXX_VERSION): super-awesome-library-that-has-breaking-changes-frequently.hpp sal_wrapper.hpp main.cpp
	g++ -std=$(SALW_CXX_VERSION) -Wall -Wextra -pedantic-errors -o $@ -DSUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION=2 main.cpp

test: sal_wrapper.hpp-must-not-contain-SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION-identifier test1_$(SALW_CXX_VERSION) test2_$(SALW_CXX_VERSION)
	./test1_$(SALW_CXX_VERSION)
	./test2_$(SALW_CXX_VERSION)

.PHONY: all clean test sal_wrapper.hpp-must-not-contain-SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION-identifier
