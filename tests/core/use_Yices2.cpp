#define BOOST_TEST_MODULE YICES2
#include <crave/ConstrainedRandom.hpp>

#include <string>

struct Context_Fixture {
  Context_Fixture() { crave::set_solver_backend("Yices2"); }
};

#include "test_Context.cpp"
#include "test_Operators.cpp"
#include "test_Random_Object.cpp"
#include "test_Constraint_Management.cpp"
#include "test_Vector_Constraint.cpp"
#include "test_Distribution.cpp"
