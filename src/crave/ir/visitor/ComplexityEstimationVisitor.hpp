// Copyright 2014 The CRAVE developers. All rights reserved.//

#pragma once

#include <boost/intrusive_ptr.hpp>

#include <stack>
#include <utility>

#include "../Node.hpp"
#include "NodeVisitor.hpp"

namespace crave {

class ComplexityEstimationVisitor : NodeVisitor {
  typedef boost::intrusive_ptr<Node> result_type;
  typedef std::pair<result_type, unsigned int> stack_entry;

 public:
  ComplexityEstimationVisitor() : NodeVisitor(), exprStack_() {}

 private:
  virtual void visitNode(Node const&);
  virtual void visitTerminal(Terminal const&);
  virtual void visitUnaryExpr(UnaryExpression const&);
  virtual void visitUnaryOpr(UnaryOperator const&);
  virtual void visitBinaryExpr(BinaryExpression const&);
  virtual void visitBinaryOpr(BinaryOperator const&);
  virtual void visitTernaryExpr(TernaryExpression const&);
  virtual void visitPlaceholder(Placeholder const&);
  virtual void visitVariableExpr(VariableExpr const&);
  virtual void visitConstant(Constant const&);
  virtual void visitVectorExpr(VectorExpr const&);
  virtual void visitNotOpr(NotOpr const&);
  virtual void visitNegOpr(NegOpr const&);
  virtual void visitComplementOpr(ComplementOpr const&);
  virtual void visitInside(Inside const&);
  virtual void visitExtendExpr(ExtendExpression const&);
  virtual void visitAndOpr(AndOpr const&);
  virtual void visitOrOpr(OrOpr const&);
  virtual void visitLogicalAndOpr(LogicalAndOpr const&);
  virtual void visitLogicalOrOpr(LogicalOrOpr const&);
  virtual void visitXorOpr(XorOpr const&);
  virtual void visitEqualOpr(EqualOpr const&);
  virtual void visitNotEqualOpr(NotEqualOpr const&);
  virtual void visitLessOpr(LessOpr const&);
  virtual void visitLessEqualOpr(LessEqualOpr const&);
  virtual void visitGreaterOpr(GreaterOpr const&);
  virtual void visitGreaterEqualOpr(GreaterEqualOpr const&);
  virtual void visitPlusOpr(PlusOpr const&);
  virtual void visitMinusOpr(MinusOpr const&);
  virtual void visitMultipliesOpr(MultipliesOpr const&);
  virtual void visitDevideOpr(DevideOpr const&);
  virtual void visitModuloOpr(ModuloOpr const&);
  virtual void visitShiftLeftOpr(ShiftLeftOpr const&);
  virtual void visitShiftRightOpr(ShiftRightOpr const&);
  virtual void visitVectorAccess(VectorAccess const&);
  virtual void visitIfThenElse(IfThenElse const&);
  virtual void visitForEach(ForEach const&);
  virtual void visitUnique(Unique const&);
  virtual void visitBitslice(Bitslice const&);

  template <typename T>
  void visitSimpleTwoBinExpr(const T& object);
  template <typename T>
  void visitSimpleBinExpr(const T& object);
  
  void pop(stack_entry&);
  void pop2(stack_entry&, stack_entry&);
  void pop3(stack_entry&, stack_entry&, stack_entry&);
  void evalBinExpr(BinaryExpression const&, stack_entry&, stack_entry&);
  void evalTernExpr(TernaryExpression const&, stack_entry&, stack_entry&, stack_entry&);

 public:
  unsigned int getComplexityEstimation(Node const& expr) {
    expr.visit(this);
    stack_entry entry;
    pop(entry);

    return entry.second;
  }

 private:
  std::stack<stack_entry> exprStack_;
};

}  // end namespace crave
