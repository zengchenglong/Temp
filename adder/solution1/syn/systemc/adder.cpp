// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "adder.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic adder::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic adder::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<2> adder::ap_ST_st1_fsm_0 = "1";
const sc_lv<2> adder::ap_ST_st2_fsm_1 = "10";
const sc_lv<32> adder::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<1> adder::ap_const_lv1_1 = "1";
const sc_lv<32> adder::ap_const_lv32_1 = "1";

adder::adder(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_done);
    sensitive << ( c_1_ack_in );
    sensitive << ( ap_sig_cseq_ST_st2_fsm_1 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( c_1_ack_in );
    sensitive << ( ap_sig_cseq_ST_st2_fsm_1 );

    SC_METHOD(thread_ap_sig_17);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_68);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_cseq_ST_st1_fsm_0);
    sensitive << ( ap_sig_17 );

    SC_METHOD(thread_ap_sig_cseq_ST_st2_fsm_1);
    sensitive << ( ap_sig_68 );

    SC_METHOD(thread_c);
    sensitive << ( c_1_data_reg );

    SC_METHOD(thread_c_1_ack_in);
    sensitive << ( c_1_vld_reg );

    SC_METHOD(thread_c_1_vld_in);
    sensitive << ( ap_start );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );

    SC_METHOD(thread_c_assign_fu_51_p2);
    sensitive << ( a );
    sensitive << ( b );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( c_1_ack_in );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    ap_CS_fsm = "01";
    c_1_data_reg = "00000000000000000000000000000000";
    c_1_vld_reg = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "adder_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, a, "(port)a");
    sc_trace(mVcdFile, b, "(port)b");
    sc_trace(mVcdFile, c, "(port)c");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st1_fsm_0, "ap_sig_cseq_ST_st1_fsm_0");
    sc_trace(mVcdFile, ap_sig_17, "ap_sig_17");
    sc_trace(mVcdFile, c_1_data_reg, "c_1_data_reg");
    sc_trace(mVcdFile, c_1_vld_reg, "c_1_vld_reg");
    sc_trace(mVcdFile, c_1_vld_in, "c_1_vld_in");
    sc_trace(mVcdFile, c_1_ack_in, "c_1_ack_in");
    sc_trace(mVcdFile, c_assign_fu_51_p2, "c_assign_fu_51_p2");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st2_fsm_1, "ap_sig_cseq_ST_st2_fsm_1");
    sc_trace(mVcdFile, ap_sig_68, "ap_sig_68");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("adder.hdltvin.dat");
    mHdltvoutHandle.open("adder.hdltvout.dat");
}

adder::~adder() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
}

void adder::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_st1_fsm_0;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (((!(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read())) && 
  esl_seteq<1,1,1>(ap_const_logic_1, c_1_vld_in.read()) && 
  esl_seteq<1,1,1>(ap_const_logic_0, c_1_vld_reg.read())) || (!(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read())) && 
  esl_seteq<1,1,1>(ap_const_logic_1, c_1_vld_in.read()) && 
  esl_seteq<1,1,1>(ap_const_logic_1, c_1_vld_reg.read()) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_const_logic_1)))) {
        c_1_data_reg = c_assign_fu_51_p2.read();
    }
}

void adder::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
         !esl_seteq<1,1,1>(c_1_ack_in.read(), ap_const_logic_0))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void adder::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void adder::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
         !esl_seteq<1,1,1>(c_1_ack_in.read(), ap_const_logic_0))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void adder::thread_ap_sig_17() {
    ap_sig_17 = esl_seteq<1,1,1>(ap_CS_fsm.read().range(0, 0), ap_const_lv1_1);
}

void adder::thread_ap_sig_68() {
    ap_sig_68 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(1, 1));
}

void adder::thread_ap_sig_cseq_ST_st1_fsm_0() {
    if (ap_sig_17.read()) {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_0;
    }
}

void adder::thread_ap_sig_cseq_ST_st2_fsm_1() {
    if (ap_sig_68.read()) {
        ap_sig_cseq_ST_st2_fsm_1 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st2_fsm_1 = ap_const_logic_0;
    }
}

void adder::thread_c() {
    c = c_1_data_reg.read();
}

void adder::thread_c_1_ack_in() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, c_1_vld_reg.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, c_1_vld_reg.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_const_logic_1)))) {
        c_1_ack_in = ap_const_logic_1;
    } else {
        c_1_ack_in = ap_const_logic_0;
    }
}

void adder::thread_c_1_vld_in() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
         !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        c_1_vld_in = ap_const_logic_1;
    } else {
        c_1_vld_in = ap_const_logic_0;
    }
}

void adder::thread_c_assign_fu_51_p2() {
    c_assign_fu_51_p2 = (!b.read().is_01() || !a.read().is_01())? sc_lv<32>(): (sc_biguint<32>(b.read()) + sc_biguint<32>(a.read()));
}

void adder::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if (!esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) {
                ap_NS_fsm = ap_ST_st2_fsm_1;
            } else {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            }
            break;
        case 2 : 
            if (!esl_seteq<1,1,1>(c_1_ack_in.read(), ap_const_logic_0)) {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            } else {
                ap_NS_fsm = ap_ST_st2_fsm_1;
            }
            break;
        default : 
            ap_NS_fsm = "XX";
            break;
    }
}

void adder::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"a\" :  \"" << a.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"b\" :  \"" << b.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c\" :  \"" << c.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

