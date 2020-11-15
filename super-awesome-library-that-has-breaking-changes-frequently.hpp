#ifndef SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_HPP_INCLUDED_
#define SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_HPP_INCLUDED_

#include<cstddef>
#include<vector>
#include<string>

#if SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION == 1

namespace super_awesome_library_that_has_breaking_changes_frequently{

enum class super_flags{
  super
};

struct awesome_type{
  static constexpr int values[] = {0, 1, 2, 3, 4};
  constexpr int a(std::size_t i)const{
    return values[i % 4u];
  }
  constexpr const int* b(std::size_t i)const{
    if(i >= 5)
      return nullptr;
    return values+i;
  }
};

template<typename... Args>
static constexpr int c(Args&&...){
  return __LINE__ + sizeof...(Args);
}

struct excellent_type{
  excellent_type() = default;
  virtual void d(int) = 0;
  struct hyper_data{
    std::string value;
  };
  std::size_t hyper_size()const{
    return data.size();
  }
  const std::string& access_hyper_data(std::size_t index)const{
    return data[index].value;
  }
 private:
  std::vector<hyper_data> data = {{"super"}, {"duper"}, {"hyper"}};
};

static void use_d(excellent_type& et){
  et.d(__LINE__);
}

}

#elif SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_VERSION == 2

#include<optional>

namespace super_awesome_library_that_has_breaking_changes_frequently{

enum class super_flags{
  super,
  duper
};

struct awesome_type{
  static constexpr int values[] = {0, 1, 2, 3, 4};
  constexpr int a2(std::size_t i)const{
    return values[i % 4u];
  }
  constexpr std::optional<const int*> b(std::size_t i)const{
    if(i >= 5)
      return std::nullopt;
    return {values+i};
  }
  template<typename... Args>
  static constexpr int c(Args&&...){
    return __LINE__ + sizeof...(Args);
  }
};

struct excellent_type{
  excellent_type() = default;
  virtual void d(int, super_flags) = 0;
  class hyper_data{
    std::string value;
   public:
    hyper_data(std::string v):value{std::move(v)}{}
    const std::string& access()const{
      return value;
    }
  };
  class hyper_range{
    const excellent_type* t;
   public:
    hyper_range(const excellent_type* self):t{self}{}
    auto begin()const{return t->data.begin();}
    auto end()const{return t->data.end();}
  };
  hyper_range hypers()const{return hyper_range{this};}
 private:
  std::vector<hyper_data> data = {{"super"}, {"duper"}, {"hyper"}};
};

static void use_d(excellent_type& et){
  et.d(__LINE__, super_flags::super);
}

}

#endif

#endif//SUPER_AWESOME_LIBRARY_THAT_HAS_BREAKING_CHANGES_FREQUENTLY_HPP_INCLUDED_
