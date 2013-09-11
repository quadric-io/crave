#pragma once

#include "AssignResult.hpp"
#include "expression/ReferenceExpression.hpp"

#include <boost/shared_ptr.hpp>

#include <map>
#include <utility>
#include <vector>

namespace crave {

struct Context;
class  EvalVisitor;
struct Generator;

class VariableContainer {

  friend struct Context;
  friend class  EvalVisitor;
  friend struct Generator;

  typedef std::pair<int, boost::shared_ptr<crave::ReferenceExpression> > ReadRefPair;
  typedef std::pair<int, boost::shared_ptr<crave::AssignResult> > WriteRefPair;

  std::map<int, boost::intrusive_ptr<Node> > variables_;
  std::map<int, boost::intrusive_ptr<VectorExpr> > vector_variables_;
  std::vector<ReadRefPair> read_references_;
  std::vector<WriteRefPair> write_references_;
};

} // end namespace crave