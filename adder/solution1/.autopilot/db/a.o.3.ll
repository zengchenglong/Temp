; ModuleID = 'F:/test/adder/solution1/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@adder_str = internal unnamed_addr constant [6 x i8] c"adder\00" ; [#uses=1 type=[6 x i8]*]
@p_str2 = private unnamed_addr constant [21 x i8] c"-bus_bundle adder_io\00", align 1 ; [#uses=4 type=[21 x i8]*]
@p_str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=32 type=[1 x i8]*]
@p_str = private unnamed_addr constant [8 x i8] c"ap_none\00", align 1 ; [#uses=1 type=[8 x i8]*]

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=0]
define void @adder(i32 %a, i32 %b, i32* %c) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %a) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %b) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %c) nounwind, !map !10
  call void (...)* @_ssdm_op_SpecTopModule([6 x i8]* @adder_str) nounwind
  %b_read = call i32 @_ssdm_op_Read.ap_auto.i32(i32 %b) nounwind ; [#uses=1 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %b_read}, i64 0, metadata !16), !dbg !25 ; [debug line = 3:23] [debug variable = b]
  %a_read = call i32 @_ssdm_op_Read.ap_auto.i32(i32 %a) nounwind ; [#uses=1 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %a_read}, i64 0, metadata !26), !dbg !27 ; [debug line = 3:16] [debug variable = a]
  call void @llvm.dbg.value(metadata !{i32 %a}, i64 0, metadata !26), !dbg !27 ; [debug line = 3:16] [debug variable = a]
  call void @llvm.dbg.value(metadata !{i32 %b}, i64 0, metadata !16), !dbg !25 ; [debug line = 3:23] [debug variable = b]
  call void @llvm.dbg.value(metadata !{i32* %c}, i64 0, metadata !28), !dbg !29 ; [debug line = 3:31] [debug variable = c]
  call void (...)* @_ssdm_op_SpecInterface(i32* %c, [8 x i8]* @p_str, i32 1, i32 1, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1) nounwind, !dbg !30 ; [debug line = 5:1]
  call void (...)* @_ssdm_op_SpecResource(i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 -1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [21 x i8]* @p_str2), !dbg !30 ; [debug line = 5:1]
  call void (...)* @_ssdm_op_SpecResource(i32 %b, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 -1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [21 x i8]* @p_str2), !dbg !30 ; [debug line = 5:1]
  call void (...)* @_ssdm_op_SpecResource(i32 %a, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 -1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [21 x i8]* @p_str2), !dbg !30 ; [debug line = 5:1]
  %c_assign = add nsw i32 %b_read, %a_read, !dbg !32 ; [#uses=1 type=i32] [debug line = 5:2]
  call void @_ssdm_op_Write.ap_none.i32P(i32* %c, i32 %c_assign) nounwind, !dbg !32 ; [debug line = 5:2]
  call void (...)* @_ssdm_op_SpecResource(i32* %c, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 -1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [1 x i8]* @p_str1, [21 x i8]* @p_str2), !dbg !33 ; [debug line = 6:1]
  ret void, !dbg !33                              ; [debug line = 6:1]
}

; [#uses=1]
define weak void @_ssdm_op_Write.ap_none.i32P(i32*, i32) {
entry:
  store i32 %1, i32* %0
  ret void
}

; [#uses=1]
define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

; [#uses=4]
define weak void @_ssdm_op_SpecResource(...) nounwind {
entry:
  ret void
}

; [#uses=1]
define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

; [#uses=3]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

; [#uses=2]
define weak i32 @_ssdm_op_Read.ap_auto.i32(i32) {
entry:
  ret i32 %0
}

!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{metadata !1}
!1 = metadata !{i32 0, i32 31, metadata !2}
!2 = metadata !{metadata !3}
!3 = metadata !{metadata !"a", metadata !4, metadata !"int", i32 0, i32 31}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 0, i32 0, i32 0}
!6 = metadata !{metadata !7}
!7 = metadata !{i32 0, i32 31, metadata !8}
!8 = metadata !{metadata !9}
!9 = metadata !{metadata !"b", metadata !4, metadata !"int", i32 0, i32 31}
!10 = metadata !{metadata !11}
!11 = metadata !{i32 0, i32 31, metadata !12}
!12 = metadata !{metadata !13}
!13 = metadata !{metadata !"c", metadata !14, metadata !"int", i32 0, i32 31}
!14 = metadata !{metadata !15}
!15 = metadata !{i32 0, i32 0, i32 1}
!16 = metadata !{i32 786689, metadata !17, metadata !"b", metadata !18, i32 33554435, metadata !21, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!17 = metadata !{i32 786478, i32 0, metadata !18, metadata !"adder", metadata !"adder", metadata !"", metadata !18, i32 3, metadata !19, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (i32, i32, i32*)* @adder, null, null, metadata !23, i32 4} ; [ DW_TAG_subprogram ]
!18 = metadata !{i32 786473, metadata !"adder/adder.c", metadata !"F:\5Ctest", null} ; [ DW_TAG_file_type ]
!19 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !20, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!20 = metadata !{null, metadata !21, metadata !21, metadata !22}
!21 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!22 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !21} ; [ DW_TAG_pointer_type ]
!23 = metadata !{metadata !24}
!24 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!25 = metadata !{i32 3, i32 23, metadata !17, null}
!26 = metadata !{i32 786689, metadata !17, metadata !"a", metadata !18, i32 16777219, metadata !21, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!27 = metadata !{i32 3, i32 16, metadata !17, null}
!28 = metadata !{i32 786689, metadata !17, metadata !"c", metadata !18, i32 50331651, metadata !22, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!29 = metadata !{i32 3, i32 31, metadata !17, null}
!30 = metadata !{i32 5, i32 1, metadata !31, null}
!31 = metadata !{i32 786443, metadata !17, i32 4, i32 1, metadata !18, i32 0} ; [ DW_TAG_lexical_block ]
!32 = metadata !{i32 5, i32 2, metadata !31, null}
!33 = metadata !{i32 6, i32 1, metadata !31, null}
