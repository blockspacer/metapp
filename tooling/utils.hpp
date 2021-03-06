#ifndef LLVM_CLANG_TOOLS_EXTRA_METAPP_TOOLING_UTILS_HPP
#define LLVM_CLANG_TOOLS_EXTRA_METAPP_TOOLING_UTILS_HPP
#pragma once

#include <algorithm>
#include <string>

/* -- LLVM includes */
#include "clang/Frontend/FrontendActions.h"

#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "clang/AST/RecursiveASTVisitor.h"

/* Declares llvm::cl::extrahelp. */
#include "llvm/Support/CommandLine.h"

// using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;
using namespace llvm;


/* ========================================================================= */
/* STL Utils                                                                 */
/* ========================================================================= */
inline bool ends_with(std::string const &value, std::string const &ending) {
  if (ending.size() > value.size())
    return false;

  return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

/* ========================================================================= */
/* LLVM Utils                                                                */
/* ========================================================================= */
clang::QualType GetDesugaredType(clang::ASTContext *ctx, clang::QualType t);

inline void GetRealTypeName(clang::ASTContext *ctx, clang::QualType t, raw_ostream &os) {
  clang::QualType retType = GetDesugaredType(ctx, t);
  retType.print(os, ctx->getPrintingPolicy());
}

clang::SmallString<32> GenerateQualifier(clang::ASTContext *ctx, clang::QualType type);

clang::SmallString<8> PrintfFormatForType(clang::ASTContext *ctx, clang::QualType t);

#endif // LLVM_CLANG_TOOLS_EXTRA_METAPP_TOOLING_UTILS_HPP
