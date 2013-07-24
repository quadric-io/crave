#include <ctime>

#include "../crave/expression/FactoryMetaSMT.hpp"
#include "../crave/ConstrainedRandom.hpp"

namespace crave {

  int new_var_id() { static int _ID=0; return ++_ID;}

  boost::mt19937 rng(std::time(0));

  void set_global_seed(unsigned int s) { rng.seed(s); };

  struct random_bit_gen {
    random_bit_gen() : rnd(0, 1) {}

    bool operator() () {
      return rnd(rng);
    }

    boost::uniform_int<unsigned short> rnd;
  };

  boost::function0<bool> random_bit = random_bit_gen();

  void set_solver_backend(std::string const& type) {
    FactoryMetaSMT::setSolverType(type);
  }

} // namespace crave

// vim: tabstop=2 shiftwidth=2 expandtab
