; RUN: opt < %s -analyze -scalar-evolution |& grep {/u 3}
; XFAIL: *

define i32 @f(i32 %x) nounwind readnone {
entry:
	%0 = icmp ugt i32 %x, 999		; <i1> [#uses=1]
	br i1 %0, label %bb2, label %bb.nph

bb.nph:		; preds = %entry
	br label %bb

bb:		; preds = %bb.nph, %bb1
	%indvar = phi i32 [ 0, %bb.nph ], [ %indvar.next, %bb1 ]		; <i32> [#uses=2]
	%tmp = mul i32 %indvar, 3		; <i32> [#uses=1]
	%x_addr.04 = add i32 %tmp, %x		; <i32> [#uses=1]
	%1 = add i32 %x_addr.04, 3		; <i32> [#uses=2]
	br label %bb1

bb1:		; preds = %bb
	%2 = icmp ugt i32 %1, 999		; <i1> [#uses=1]
	%indvar.next = add i32 %indvar, 1		; <i32> [#uses=1]
	br i1 %2, label %bb1.bb2_crit_edge, label %bb

bb1.bb2_crit_edge:		; preds = %bb1
	%.lcssa = phi i32 [ %1, %bb1 ]		; <i32> [#uses=1]
	br label %bb2

bb2:		; preds = %bb1.bb2_crit_edge, %entry
	%x_addr.0.lcssa = phi i32 [ %.lcssa, %bb1.bb2_crit_edge ], [ %x, %entry ]		; <i32> [#uses=1]
	ret i32 %x_addr.0.lcssa
}
