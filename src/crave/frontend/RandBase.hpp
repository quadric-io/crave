// Copyright 2012-2016 The CRAVE developers, University of Bremen, Germany. All rights reserved.

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Constraint.hpp"

namespace crave {

class rand_base {
 protected:
  rand_base() {}

  ~rand_base() {}

 public:
  virtual bool next() = 0;
  virtual void gather_values(std::vector<int64_t>*) = 0;
  virtual std::string obj_kind() const = 0;
};

class rand_obj_base : public rand_base {
 public:
  virtual void add_base_child(rand_base* rb) = 0;
  virtual std::string obj_kind() const { return "rand_obj"; }
};

template <typename T>
class randv_base : public rand_base {
 public:
  operator T() const { return value; }

  friend std::ostream& operator<<(std::ostream& os, const randv_base<T>& e) {
    os << e.value;
    return os;
  }

  WriteReference<T> const& operator()() const { return var; }
  
  virtual std::string obj_kind() const { return "randv"; }

 protected:
  explicit randv_base(rand_obj_base* parent) : var(&value) {
    if (parent != 0) parent->add_base_child(this);
  }

  randv_base(const randv_base& other) : var(&value), value(other.value) {}
  WriteReference<T> var;
  T value;
};
}  // namespace crave
