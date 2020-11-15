#include<cassert>
#include<algorithm>
#include"super-awesome-library-that-has-breaking-changes-frequently.hpp"

#include"sal_wrapper.hpp"

namespace sal = super_awesome_library_that_has_breaking_changes_frequently;

struct T : sal_wrapper::excellent_base{
  constexpr T():l{}{}
  int l;
  void d(int line)override{
    this->l = line;
  }
};

int main(){
#if SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION == 1
  static_assert(sal_wrapper::a(sal::awesome_type{}, 2) == sal::awesome_type{}.a(2));
  static_assert(sal_wrapper::b(sal::awesome_type{}, 2) == sal::awesome_type{}.b(2));
  static_assert(sal_wrapper::c(42, 42.f) == sal::c(42, 42.f));
  {
    T t = {};
    struct U : sal::excellent_type{
      constexpr U():l{}{}
      int l;
      void d(int line)override{
        this->l = line;
      }
    }u = {};
    assert((sal::use_d(t), sal::use_d(u), t.l == u.l));
    std::size_t i = 0;
    for(auto&& x : sal_wrapper::hypers(t))
      assert(x.access() == u.access_hyper_data(i++));
    assert(i == u.hyper_size());
  }
#elif SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION == 2
  static_assert(sal_wrapper::a(sal::awesome_type{}, 2) == sal::awesome_type{}.a2(2));
  static_assert(sal_wrapper::b(sal::awesome_type{}, 2) == *sal::awesome_type{}.b(2));
  static_assert(sal_wrapper::c(42, 42.f) == sal::awesome_type::c(42, 42.f));
  {
    T t = {};
    struct U : sal::excellent_type{
      constexpr U():l{}{}
      int l;
      void d(int line, sal::super_flags)override{
        this->l = line;
      }
    }u = {};
    assert((sal::use_d(t), sal::use_d(u), t.l == u.l));
    auto it = u.hypers().begin();
    for(auto&& x : sal_wrapper::hypers(t))
      assert(x.access() == (it++)->access());
    assert(it == u.hypers().end());
  }
#endif
}
