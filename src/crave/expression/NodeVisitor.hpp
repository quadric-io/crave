#pragma once

#include <iosfwd>
#include <ostream>
#include <set>

namespace crave {

class Node;
class Placeholder;
class Terminal;
class VariableExpr;
class Constant;
class VectorExpr;
class UnaryExpression;
class UnaryOperator;
class NotOpr;
class NegOpr;
class ComplementOpr;
class Inside;
class BinaryExpression;
class BinaryOperator;
class AndOpr;
class OrOpr;
class XorOpr;
class EqualOpr;
class NotEqualOpr;
class LessOpr;
class LessEqualOpr;
class GreaterOpr;
class GreaterEqualOpr;
class PlusOpr;
class MinusOpr;
class MultipliesOpr;
class DevideOpr;
class ModuloOpr;
class ShiftLeftOpr;
class ShiftRightOpr;
class AssignOpr;
class VectorAccess;
class TernaryExpression;
class IfThenElse;

class NodeVisitor {
protected:
  NodeVisitor() { }
  virtual ~NodeVisitor() { }

public:
  virtual bool visitNode( Node const & ) = 0;
  virtual void visitTerminal( Terminal const & ) = 0;
  virtual void visitUnaryExpr( UnaryExpression const & ) = 0;
  virtual void visitUnaryOpr( UnaryOperator const & ) = 0;
  virtual void visitBinaryExpr( BinaryExpression const & ) = 0;
  virtual void visitBinaryOpr( BinaryOperator const & ) = 0;
  virtual void visitTernaryExpr( TernaryExpression const & ) = 0;
  virtual void visitPlaceholder( Placeholder const & ) = 0;
  virtual void visitVariableExpr( VariableExpr const & ) = 0;
  virtual void visitConstant( Constant const & ) = 0;
  virtual void visitVectorExpr( VectorExpr const & ) = 0;
  virtual void visitNotOpr( NotOpr const & ) = 0;
  virtual void visitNegOpr( NegOpr const & ) = 0;
  virtual void visitComplementOpr( ComplementOpr const & ) = 0;
  virtual void visitInside( Inside const & ) = 0;
  virtual void visitAndOpr( AndOpr const & ) = 0;
  virtual void visitOrOpr( OrOpr const & ) = 0;
  virtual void visitXorOpr( XorOpr const & ) = 0;
  virtual void visitEqualOpr( EqualOpr const & ) = 0;
  virtual void visitNotEqualOpr( NotEqualOpr const & ) = 0;
  virtual void visitLessOpr( LessOpr const & ) = 0;
  virtual void visitLessEqualOpr( LessEqualOpr const & ) = 0;
  virtual void visitGreaterOpr( GreaterOpr const & ) = 0;
  virtual void visitGreaterEqualOpr( GreaterEqualOpr const & ) = 0;
  virtual void visitPlusOpr( PlusOpr const & ) = 0;
  virtual void visitMinusOpr( MinusOpr const & ) = 0;
  virtual void visitMultipliesOpr( MultipliesOpr const & ) = 0;
  virtual void visitDevideOpr( DevideOpr const & ) = 0;
  virtual void visitModuloOpr( ModuloOpr const & ) = 0;
  virtual void visitShiftLeftOpr( ShiftLeftOpr const & ) = 0;
  virtual void visitShiftRightOpr( ShiftRightOpr const & ) = 0;
  virtual void visitAssignOpr( AssignOpr const & ) = 0;
  virtual void visitVectorAccess( VectorAccess const & ) = 0;
  virtual void visitIfThenElse( IfThenElse const & ) = 0;
};

class ToDotVisitor : public NodeVisitor {
public:
  ToDotVisitor( std::ostream & os ) : NodeVisitor(), out_(os), nodes_() { }

  bool visitNode( Node const & );
  void visitTerminal( Terminal const & );
  void visitUnaryExpr( UnaryExpression const & );
  void visitUnaryOpr( UnaryOperator const & );
  void visitBinaryExpr( BinaryExpression const & );
  void visitBinaryOpr( BinaryOperator const & );
  void visitTernaryExpr( TernaryExpression const & );
  void visitPlaceholder( Placeholder const & );
  void visitVariableExpr( VariableExpr const & );
  void visitConstant( Constant const & );
  void visitVectorExpr( VectorExpr const & );
  void visitNotOpr( NotOpr const & );
  void visitNegOpr( NegOpr const & );
  void visitComplementOpr( ComplementOpr const & );
  void visitInside( Inside const & );
  void visitAndOpr( AndOpr const & );
  void visitOrOpr( OrOpr const & );
  void visitXorOpr( XorOpr const & );
  void visitEqualOpr( EqualOpr const & );
  void visitNotEqualOpr( NotEqualOpr const & );
  void visitLessOpr( LessOpr const &o );
  void visitLessEqualOpr( LessEqualOpr const & );
  void visitGreaterOpr( GreaterOpr const & );
  void visitGreaterEqualOpr( GreaterEqualOpr const & );
  void visitPlusOpr( PlusOpr const & );
  void visitMinusOpr( MinusOpr const & );
  void visitMultipliesOpr( MultipliesOpr const & );
  void visitDevideOpr( DevideOpr const & );
  void visitModuloOpr( ModuloOpr const & );
  void visitShiftLeftOpr( ShiftLeftOpr const & );
  void visitShiftRightOpr( ShiftRightOpr const & );
  void visitAssignOpr( AssignOpr const & );
  void visitVectorAccess( VectorAccess const & );
  void visitIfThenElse( IfThenElse const & );

private:
  std::ostream& out_;
  std::set<Node*> nodes_;
};

} // end namespace crave
