//===- LLToken.h - Token Codes for LLVM Assembly Files ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the enums for the .ll lexer.
//
//===----------------------------------------------------------------------===//

#ifndef LIBS_ASMPARSER_LLTOKEN_H
#define LIBS_ASMPARSER_LLTOKEN_H

namespace llvm {
namespace lltok {
  enum Kind {
    // Markers
    Eof, Error,

    // Tokens with no info.
    dotdotdot,         // ...
    equal, comma,      // =  ,
    star,              // *
    lsquare, rsquare,  // [  ]
    lbrace, rbrace,    // {  }
    less, greater,     // <  >
    lparen, rparen,    // (  )
    backslash,         // \    (not /)
    exclaim,           // !

    kw_x,
    kw_begin,   kw_end,
    kw_true,    kw_false,
    kw_declare, kw_define,
    kw_global,  kw_constant,

    kw_private, kw_linker_private, kw_internal, kw_linkonce, kw_linkonce_odr,
    kw_weak, kw_weak_odr, kw_appending, kw_dllimport, kw_dllexport, kw_common,
    kw_available_externally,
    kw_default, kw_hidden, kw_protected,
    kw_extern_weak,
    kw_external, kw_thread_local,
    kw_zeroinitializer,
    kw_undef, kw_null,
    kw_to,
    kw_tail,
    kw_target,
    kw_triple,
    kw_deplibs,
    kw_datalayout,
    kw_volatile,
    kw_nuw,
    kw_nsw,
    kw_exact,
    kw_inbounds,
    kw_align,
    kw_addrspace,
    kw_section,
    kw_alias,
    kw_module,
    kw_asm,
    kw_sideeffect,
    kw_alignstack,
    kw_gc,
    kw_c,

    kw_cc, kw_ccc, kw_fastcc, kw_coldcc,
    kw_x86_stdcallcc, kw_x86_fastcallcc,
    kw_arm_apcscc, kw_arm_aapcscc, kw_arm_aapcs_vfpcc,
    kw_msp430_intrcc,

    kw_signext,
    kw_zeroext,
    kw_inreg,
    kw_sret,
    kw_nounwind,
    kw_noreturn,
    kw_noalias,
    kw_nocapture,
    kw_byval,
    kw_nest,
    kw_readnone,
    kw_readonly,

    kw_inlinehint,
    kw_noinline,
    kw_alwaysinline,
    kw_optsize,
    kw_ssp,
    kw_sspreq,
    kw_noredzone,
    kw_noimplicitfloat,
    kw_naked,

    kw_type,
    kw_opaque,
    kw_union,

    kw_eq, kw_ne, kw_slt, kw_sgt, kw_sle, kw_sge, kw_ult, kw_ugt, kw_ule,
    kw_uge, kw_oeq, kw_one, kw_olt, kw_ogt, kw_ole, kw_oge, kw_ord, kw_uno,
    kw_ueq, kw_une,

    // Instruction Opcodes (Opcode in UIntVal).
    kw_add,  kw_fadd, kw_sub,  kw_fsub, kw_mul,  kw_fmul,
    kw_udiv, kw_sdiv, kw_fdiv,
    kw_urem, kw_srem, kw_frem, kw_shl,  kw_lshr, kw_ashr,
    kw_and,  kw_or,   kw_xor,  kw_icmp, kw_fcmp,

    kw_phi, kw_call,
    kw_trunc, kw_zext, kw_sext, kw_fptrunc, kw_fpext, kw_uitofp, kw_sitofp,
    kw_fptoui, kw_fptosi, kw_inttoptr, kw_ptrtoint, kw_bitcast,
    kw_select, kw_va_arg,

    kw_ret, kw_br, kw_switch, kw_indirectbr, kw_invoke, kw_unwind,
    kw_unreachable,

    kw_malloc, kw_alloca, kw_free, kw_load, kw_store, kw_getelementptr,

    kw_extractelement, kw_insertelement, kw_shufflevector, kw_getresult,
    kw_extractvalue, kw_insertvalue, kw_blockaddress,

    // Unsigned Valued tokens (UIntVal).
    GlobalID,          // @42
    LocalVarID,        // %42

    // String valued tokens (StrVal).
    LabelStr,          // foo:
    GlobalVar,         // @foo @"foo"
    LocalVar,          // %foo %"foo"
    MetadataVar,       // !foo
    StringConstant,    // "foo"

    // Type valued tokens (TyVal).
    Type,

    APFloat,  // APFloatVal
    APSInt // APSInt
  };
} // end namespace lltok
} // end namespace llvm

#endif
