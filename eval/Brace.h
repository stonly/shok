// Copyright (C) 2013 Michael Biggs.  See the COPYRIGHT file at the top-level
// directory of this distribution and at http://lush-shell.org/copyright.html

#ifndef _Brace_h_
#define _Brace_h_

/* Brace -- actually, just an AST token that requires a match */

#include "Log.h"
#include "Node.h"
#include "RootNode.h"
#include "Token.h"

namespace eval {

class Brace : public Node {
public:
  Brace(Log& log, RootNode*const root, const Token& token, bool isOpen)
    : Node(log, root, token),
      m_isOpen(isOpen) {}
  ~Brace() {}

  bool isOpen() const;
  bool isIrrelevant() const;
  bool matchesCloseBrace(Brace* closeBrace) const;

  virtual void setup();
  virtual void evaluate();

private:
  bool m_isOpen;
};

};

#endif // _Brace_h_
