/**
 * pxar hardware constants
 * this file contains DAC definitions and other global constants such
 * as testboard register ids
 */

#ifndef PXAR_CONSTANTS_H
#define PXAR_CONSTANTS_H

namespace pxar {

// --- Data Transmission settings ----------------------------------------------
//#define DTB_SOURCE_BLOCK_SIZE  32767
#define DTB_SOURCE_BLOCK_SIZE  16383
#define DTB_SOURCE_BUFFER_SIZE 50000000


// --- TBM Types ---------------------------------------------------------------
// FIXME just an example...
#define TBM_07             0x01
#define TBM_07A            0x02
#define TBM_08             0x03


// --- TBM Register -----------------------------------------------------------
// These register addresses give the position relative to the base of the cores
// To actually program the TBM the base has to be added, e.g.
// Register 0x04 + Base -> 0xE4 or 0xF4
#define TBM_REG_COUNTER_SWITCHES    0x00
#define TBM_REG_SET_MODE            0x02
#define TBM_REG_CLEAR_INJECT        0x04
#define TBM_REG_SET_PKAM_COUNTER    0x08
#define TBM_REG_SET_DELAYS          0x0A
#define TBM_REG_TEMPERATURE_CONTROL 0x0C


// --- ROC Size ---------------------------------------------------------------
#define ROC_NUMROWS 80
#define ROC_NUMCOLS 52


// --- ROC Types ---------------------------------------------------------------
#define ROC_PSI46V2        0x01
#define ROC_PSI46XDB       0x02
#define ROC_PSI46DIG       0x03
#define ROC_PSI46DIG_TRIG  0x04
#define ROC_PSI46DIGV2_B   0x05
#define ROC_PSI46DIGV2     0x06
#define ROC_PSI46DIGV21    0x07


// --- ROC DACs ---------------------------------------------------------------
#define ROC_DAC_Vdig       0x01
#define ROC_DAC_Vana       0x02
#define ROC_DAC_Vsh        0x03
#define ROC_DAC_Vcomp      0x04
#define ROC_DAC_Vleak_comp 0x05
#define ROC_DAC_VrgPr      0x06
#define ROC_DAC_VwllPr     0x07
#define ROC_DAC_VrgSh      0x08
#define ROC_DAC_VwllSh     0x09
#define ROC_DAC_VhldDel    0x0A
#define ROC_DAC_Vtrim      0x0B
#define ROC_DAC_VthrComp   0x0C
#define ROC_DAC_VIBias_Bus 0x0D
#define ROC_DAC_Vbias_sf   0x0E
#define ROC_DAC_VoffsetOp  0x0F
#define ROC_DAC_VIbiasOp   0x10
#define ROC_DAC_VoffsetRO  0x11
#define ROC_DAC_VIon       0x12
#define ROC_DAC_VIbias_PH  0x13
#define ROC_DAC_VIbias_DAC 0x14
#define ROC_DAC_VIbias_roc 0x15
#define ROC_DAC_VIColOr    0x16
#define ROC_DAC_Vnpix      0x17
#define ROC_DAC_VsumCol    0x18
#define ROC_DAC_Vcal       0x19
#define ROC_DAC_CalDel     0x1A
#define ROC_DAC_CtrlReg    0xFD
#define ROC_DAC_WBC        0xFE
#define ROC_DAC_Readback   0xFF


// --- Testboard Signal Delay -------------------------------------------------
#define SIG_CLK 0
#define SIG_CTR 1
#define SIG_SDA 2
#define SIG_TIN 3

#define SIG_DESER160PHASE 0xFE

#define SIG_MODE_NORMAL  0
#define SIG_MODE_LO      1
#define SIG_MODE_HI      2


// --- Testboard Clock / Timing -----------------------------------------------
#define CLK_SRC_INT 0
#define CLK_SRC_EXT 1

// --- Clock Stretch and Clock Divider settings -------------------------------
#define STRETCH_AFTER_TRG  0
#define STRETCH_AFTER_CAL  1
#define STRETCH_AFTER_RES  2
#define STRETCH_AFTER_SYNC 3

#define MHZ_1_25   5
#define MHZ_2_5    4
#define MHZ_5      3
#define MHZ_10     2
#define MHZ_20     1
#define MHZ_40     0


// --- Testboard digital signal probe -----------------------------------------
#define PROBE_OFF     0
#define PROBE_CLK     1
#define PROBE_SDA     2
#define PROBE_PGTOK   3
#define PROBE_PGTRG   4
#define PROBE_PGCAL   5
#define PROBE_PGRESR  6
#define PROBE_PGREST  7
#define PROBE_PGSYNC  8
#define PROBE_CTR     9
#define PROBE_CLKP   10
#define PROBE_CLKG   11
#define PROBE_CRC    12


// --- Testboard analog signal probe ------------------------------------------
#define PROBEA_TIN     0
#define PROBEA_SDATA1  1
#define PROBEA_SDATA2  2
#define PROBEA_CTR     3
#define PROBEA_CLK     4
#define PROBEA_SDA     5
#define PROBEA_TOUT    6
#define PROBEA_OFF     7

#define GAIN_1   0
#define GAIN_2   1
#define GAIN_3   2
#define GAIN_4   3


// --- Testboard pulse pattern generator --------------------------------------
#define PG_TOK   0x0100
#define PG_TRG   0x0200
#define PG_CAL   0x0400
#define PG_RESR  0x0800
#define PG_REST  0x1000
#define PG_SYNC  0x2000

} //namespace pxar

#endif /* PXAR_CONSTANTS_H */
