//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// The class was added for DFENCE.
//
//===----------------------------------------------------------------------===//

#include "wsq.h"
using namespace llvm;

int WSQ::seq_wsq_put_the(int task) {
	q.push_back(task);
	return true;
}

int WSQ::seq_wsq_take_the() {
	if (!q.empty()) {
	  int res = q.back();
	  q.pop_back();
	  return res;
	}
	else {
	  int res;
	  res = -1;
	  return res;	
	} 
}

int WSQ::seq_wsq_steal_the() {
	if (!q.empty()) {
	  int res = q.front();
	  q.pop_front();
	  return res;
	}
	else {
	  int res;
	  res = -1;
	  return res;	
	}
}
