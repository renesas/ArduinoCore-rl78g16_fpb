/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F121BC.DVF                                                     */
/*    V1.00 (2022/07/01)                                                */
/*    Copyright(C) 2022 Renesas                                         */
/* Tool Version: 4.0.15                                                 */
/* Date Generated: 2023/06/02                                           */
/************************************************************************/

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI() __builtin_rl78_di()
#define EI() __builtin_rl78_ei()
#define HALT() __halt()
#define NOP() __nop()
#define STOP() __stop()

#endif

#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

typedef struct {
	unsigned short no0 :1;
	unsigned short no1 :1;
	unsigned short no2 :1;
	unsigned short no3 :1;
	unsigned short no4 :1;
	unsigned short no5 :1;
	unsigned short no6 :1;
	unsigned short no7 :1;
	unsigned short no8 :1;
	unsigned short no9 :1;
	unsigned short no10 :1;
	unsigned short no11 :1;
	unsigned short no12 :1;
	unsigned short no13 :1;
	unsigned short no14 :1;
	unsigned short no15 :1;
} __BITS16;

#endif

#ifndef IODEFINE_H
#define IODEFINE_H

/*
 IO Registers
 */
union un_p0 {
	unsigned char p0;
	__BITS8 BIT;
};
union un_p1 {
	unsigned char p1;
	__BITS8 BIT;
};
union un_p2 {
	unsigned char p2;
	__BITS8 BIT;
};
union un_p4 {
	unsigned char p4;
	__BITS8 BIT;
};
union un_p6 {
	unsigned char p6;
	__BITS8 BIT;
};
union un_p12 {
	unsigned char p12;
	__BITS8 BIT;
};
union un_p13 {
	unsigned char p13;
	__BITS8 BIT;
};
union un_pm0 {
	unsigned char pm0;
	__BITS8 BIT;
};
union un_pm1 {
	unsigned char pm1;
	__BITS8 BIT;
};
union un_pm2 {
	unsigned char pm2;
	__BITS8 BIT;
};
union un_pm4 {
	unsigned char pm4;
	__BITS8 BIT;
};
union un_pm6 {
	unsigned char pm6;
	__BITS8 BIT;
};
union un_pm12 {
	unsigned char pm12;
	__BITS8 BIT;
};
union un_adm0 {
	unsigned char adm0;
	__BITS8 BIT;
};
union un_ads {
	unsigned char ads;
	__BITS8 BIT;
};
union un_egp0 {
	unsigned char egp0;
	__BITS8 BIT;
};
union un_egn0 {
	unsigned char egn0;
	__BITS8 BIT;
};
union un_egp1 {
	unsigned char egp1;
	__BITS8 BIT;
};
union un_egn1 {
	unsigned char egn1;
	__BITS8 BIT;
};
union un_iics0 {
	unsigned char iics0;
	__BITS8 BIT;
};
union un_iicf0 {
	unsigned char iicf0;
	__BITS8 BIT;
};
union un_compmdr {
	unsigned char compmdr;
	__BITS8 BIT;
};
union un_compfir {
	unsigned char compfir;
	__BITS8 BIT;
};
union un_compocr {
	unsigned char compocr;
	__BITS8 BIT;
};
union un_rtcc0 {
	unsigned char rtcc0;
	__BITS8 BIT;
};
union un_rtcc1 {
	unsigned char rtcc1;
	__BITS8 BIT;
};
union un_csc {
	unsigned char csc;
	__BITS8 BIT;
};
union un_ostc {
	unsigned char ostc;
	__BITS8 BIT;
};
union un_ckc {
	unsigned char ckc;
	__BITS8 BIT;
};
union un_cks0 {
	unsigned char cks0;
	__BITS8 BIT;
};
union un_if2 {
	unsigned short if2;
	__BITS16 BIT;
};
union un_if2l {
	unsigned char if2l;
	__BITS8 BIT;
};
union un_mk2 {
	unsigned short mk2;
	__BITS16 BIT;
};
union un_mk2l {
	unsigned char mk2l;
	__BITS8 BIT;
};
union un_pr02 {
	unsigned short pr02;
	__BITS16 BIT;
};
union un_pr02l {
	unsigned char pr02l;
	__BITS8 BIT;
};
union un_pr12 {
	unsigned short pr12;
	__BITS16 BIT;
};
union un_pr12l {
	unsigned char pr12l;
	__BITS8 BIT;
};
union un_if0 {
	unsigned short if0;
	__BITS16 BIT;
};
union un_if0l {
	unsigned char if0l;
	__BITS8 BIT;
};
union un_if0h {
	unsigned char if0h;
	__BITS8 BIT;
};
union un_if1 {
	unsigned short if1;
	__BITS16 BIT;
};
union un_if1l {
	unsigned char if1l;
	__BITS8 BIT;
};
union un_if1h {
	unsigned char if1h;
	__BITS8 BIT;
};
union un_mk0 {
	unsigned short mk0;
	__BITS16 BIT;
};
union un_mk0l {
	unsigned char mk0l;
	__BITS8 BIT;
};
union un_mk0h {
	unsigned char mk0h;
	__BITS8 BIT;
};
union un_mk1 {
	unsigned short mk1;
	__BITS16 BIT;
};
union un_mk1l {
	unsigned char mk1l;
	__BITS8 BIT;
};
union un_mk1h {
	unsigned char mk1h;
	__BITS8 BIT;
};
union un_pr00 {
	unsigned short pr00;
	__BITS16 BIT;
};
union un_pr00l {
	unsigned char pr00l;
	__BITS8 BIT;
};
union un_pr00h {
	unsigned char pr00h;
	__BITS8 BIT;
};
union un_pr01 {
	unsigned short pr01;
	__BITS16 BIT;
};
union un_pr01l {
	unsigned char pr01l;
	__BITS8 BIT;
};
union un_pr01h {
	unsigned char pr01h;
	__BITS8 BIT;
};
union un_pr10 {
	unsigned short pr10;
	__BITS16 BIT;
};
union un_pr10l {
	unsigned char pr10l;
	__BITS8 BIT;
};
union un_pr10h {
	unsigned char pr10h;
	__BITS8 BIT;
};
union un_pr11 {
	unsigned short pr11;
	__BITS16 BIT;
};
union un_pr11l {
	unsigned char pr11l;
	__BITS8 BIT;
};
union un_pr11h {
	unsigned char pr11h;
	__BITS8 BIT;
};

#define P0 (*(volatile union un_p0 *)0xFFF00).p0
#define P0_bit (*(volatile union un_p0 *)0xFFF00).BIT
#define P1 (*(volatile union un_p1 *)0xFFF01).p1
#define P1_bit (*(volatile union un_p1 *)0xFFF01).BIT
#define P2 (*(volatile union un_p2 *)0xFFF02).p2
#define P2_bit (*(volatile union un_p2 *)0xFFF02).BIT
#define P4 (*(volatile union un_p4 *)0xFFF04).p4
#define P4_bit (*(volatile union un_p4 *)0xFFF04).BIT
#define P6 (*(volatile union un_p6 *)0xFFF06).p6
#define P6_bit (*(volatile union un_p6 *)0xFFF06).BIT
#define P12 (*(volatile union un_p12 *)0xFFF0C).p12
#define P12_bit (*(volatile union un_p12 *)0xFFF0C).BIT
#define P13 (*(volatile union un_p13 *)0xFFF0D).p13
#define P13_bit (*(volatile union un_p13 *)0xFFF0D).BIT
#define SDR00 (*(volatile unsigned short *)0xFFF10)
#define SIO00 (*(volatile unsigned char *)0xFFF10)
#define TXD0 (*(volatile unsigned char *)0xFFF10)
#define SDR01 (*(volatile unsigned short *)0xFFF12)
#define RXD0 (*(volatile unsigned char *)0xFFF12)
#define TDR00 (*(volatile unsigned short *)0xFFF18)
#define TDR01 (*(volatile unsigned short *)0xFFF1A)
#define TDR01L (*(volatile unsigned char *)0xFFF1A)
#define TDR01H (*(volatile unsigned char *)0xFFF1B)
#define ADCR (*(volatile unsigned short *)0xFFF1E)
#define ADCRH (*(volatile unsigned char *)0xFFF1F)
#define PM0 (*(volatile union un_pm0 *)0xFFF20).pm0
#define PM0_bit (*(volatile union un_pm0 *)0xFFF20).BIT
#define PM1 (*(volatile union un_pm1 *)0xFFF21).pm1
#define PM1_bit (*(volatile union un_pm1 *)0xFFF21).BIT
#define PM2 (*(volatile union un_pm2 *)0xFFF22).pm2
#define PM2_bit (*(volatile union un_pm2 *)0xFFF22).BIT
#define PM4 (*(volatile union un_pm4 *)0xFFF24).pm4
#define PM4_bit (*(volatile union un_pm4 *)0xFFF24).BIT
#define PM6 (*(volatile union un_pm6 *)0xFFF26).pm6
#define PM6_bit (*(volatile union un_pm6 *)0xFFF26).BIT
#define PM12 (*(volatile union un_pm12 *)0xFFF2C).pm12
#define PM12_bit (*(volatile union un_pm12 *)0xFFF2C).BIT
#define ADM0 (*(volatile union un_adm0 *)0xFFF30).adm0
#define ADM0_bit (*(volatile union un_adm0 *)0xFFF30).BIT
#define ADS (*(volatile union un_ads *)0xFFF31).ads
#define ADS_bit (*(volatile union un_ads *)0xFFF31).BIT
#define EGP0 (*(volatile union un_egp0 *)0xFFF38).egp0
#define EGP0_bit (*(volatile union un_egp0 *)0xFFF38).BIT
#define EGN0 (*(volatile union un_egn0 *)0xFFF39).egn0
#define EGN0_bit (*(volatile union un_egn0 *)0xFFF39).BIT
#define EGP1 (*(volatile union un_egp1 *)0xFFF3A).egp1
#define EGP1_bit (*(volatile union un_egp1 *)0xFFF3A).BIT
#define EGN1 (*(volatile union un_egn1 *)0xFFF3B).egn1
#define EGN1_bit (*(volatile union un_egn1 *)0xFFF3B).BIT
#define SDR02 (*(volatile unsigned short *)0xFFF44)
#define TXD1 (*(volatile unsigned char *)0xFFF44)
#define SDR03 (*(volatile unsigned short *)0xFFF46)
#define RXD1 (*(volatile unsigned char *)0xFFF46)
#define SIO11 (*(volatile unsigned char *)0xFFF46)
#define SDR10 (*(volatile unsigned short *)0xFFF48)
#define TXD2 (*(volatile unsigned char *)0xFFF48)
#define SIO20 (*(volatile unsigned char *)0xFFF48)
#define SDR11 (*(volatile unsigned short *)0xFFF4A)
#define RXD2 (*(volatile unsigned char *)0xFFF4A)
#define IICA0 (*(volatile unsigned char *)0xFFF50)
#define IICS0 (*(volatile union un_iics0 *)0xFFF51).iics0
#define IICS0_bit (*(volatile union un_iics0 *)0xFFF51).BIT
#define IICF0 (*(volatile union un_iicf0 *)0xFFF52).iicf0
#define IICF0_bit (*(volatile union un_iicf0 *)0xFFF52).BIT
#define COMPMDR (*(volatile union un_compmdr *)0xFFF60).compmdr
#define COMPMDR_bit (*(volatile union un_compmdr *)0xFFF60).BIT
#define COMPFIR (*(volatile union un_compfir *)0xFFF61).compfir
#define COMPFIR_bit (*(volatile union un_compfir *)0xFFF61).BIT
#define COMPOCR (*(volatile union un_compocr *)0xFFF62).compocr
#define COMPOCR_bit (*(volatile union un_compocr *)0xFFF62).BIT
#define TDR02 (*(volatile unsigned short *)0xFFF64)
#define TDR03 (*(volatile unsigned short *)0xFFF66)
#define TDR03L (*(volatile unsigned char *)0xFFF66)
#define TDR03H (*(volatile unsigned char *)0xFFF67)
#define TDR04 (*(volatile unsigned short *)0xFFF68)
#define TDR05 (*(volatile unsigned short *)0xFFF6A)
#define TDR06 (*(volatile unsigned short *)0xFFF6C)
#define TDR07 (*(volatile unsigned short *)0xFFF6E)
#define ITMC (*(volatile unsigned short *)0xFFF90)
#define SEC (*(volatile unsigned char *)0xFFF92)
#define MIN (*(volatile unsigned char *)0xFFF93)
#define HOUR (*(volatile unsigned char *)0xFFF94)
#define WEEK (*(volatile unsigned char *)0xFFF95)
#define DAY (*(volatile unsigned char *)0xFFF96)
#define MONTH (*(volatile unsigned char *)0xFFF97)
#define YEAR (*(volatile unsigned char *)0xFFF98)
#define ALARMWM (*(volatile unsigned char *)0xFFF9A)
#define ALARMWH (*(volatile unsigned char *)0xFFF9B)
#define ALARMWW (*(volatile unsigned char *)0xFFF9C)
#define RTCC0 (*(volatile union un_rtcc0 *)0xFFF9D).rtcc0
#define RTCC0_bit (*(volatile union un_rtcc0 *)0xFFF9D).BIT
#define RTCC1 (*(volatile union un_rtcc1 *)0xFFF9E).rtcc1
#define RTCC1_bit (*(volatile union un_rtcc1 *)0xFFF9E).BIT
#define CMC (*(volatile unsigned char *)0xFFFA0)
#define CSC (*(volatile union un_csc *)0xFFFA1).csc
#define CSC_bit (*(volatile union un_csc *)0xFFFA1).BIT
#define OSTC (*(volatile union un_ostc *)0xFFFA2).ostc
#define OSTC_bit (*(volatile union un_ostc *)0xFFFA2).BIT
#define OSTS (*(volatile unsigned char *)0xFFFA3)
#define CKC (*(volatile union un_ckc *)0xFFFA4).ckc
#define CKC_bit (*(volatile union un_ckc *)0xFFFA4).BIT
#define CKS0 (*(volatile union un_cks0 *)0xFFFA5).cks0
#define CKS0_bit (*(volatile union un_cks0 *)0xFFFA5).BIT
#define RESF (*(volatile unsigned char *)0xFFFA8)
#define WDTE (*(volatile unsigned char *)0xFFFAB)
#define CRCIN (*(volatile unsigned char *)0xFFFAC)
#define IF2 (*(volatile union un_if2 *)0xFFFD0).if2
#define IF2_bit (*(volatile union un_if2 *)0xFFFD0).BIT
#define IF2L (*(volatile union un_if2l *)0xFFFD0).if2l
#define IF2L_bit (*(volatile union un_if2l *)0xFFFD0).BIT
#define MK2 (*(volatile union un_mk2 *)0xFFFD4).mk2
#define MK2_bit (*(volatile union un_mk2 *)0xFFFD4).BIT
#define MK2L (*(volatile union un_mk2l *)0xFFFD4).mk2l
#define MK2L_bit (*(volatile union un_mk2l *)0xFFFD4).BIT
#define PR02 (*(volatile union un_pr02 *)0xFFFD8).pr02
#define PR02_bit (*(volatile union un_pr02 *)0xFFFD8).BIT
#define PR02L (*(volatile union un_pr02l *)0xFFFD8).pr02l
#define PR02L_bit (*(volatile union un_pr02l *)0xFFFD8).BIT
#define PR12 (*(volatile union un_pr12 *)0xFFFDC).pr12
#define PR12_bit (*(volatile union un_pr12 *)0xFFFDC).BIT
#define PR12L (*(volatile union un_pr12l *)0xFFFDC).pr12l
#define PR12L_bit (*(volatile union un_pr12l *)0xFFFDC).BIT
#define IF0 (*(volatile union un_if0 *)0xFFFE0).if0
#define IF0_bit (*(volatile union un_if0 *)0xFFFE0).BIT
#define IF0L (*(volatile union un_if0l *)0xFFFE0).if0l
#define IF0L_bit (*(volatile union un_if0l *)0xFFFE0).BIT
#define IF0H (*(volatile union un_if0h *)0xFFFE1).if0h
#define IF0H_bit (*(volatile union un_if0h *)0xFFFE1).BIT
#define IF1 (*(volatile union un_if1 *)0xFFFE2).if1
#define IF1_bit (*(volatile union un_if1 *)0xFFFE2).BIT
#define IF1L (*(volatile union un_if1l *)0xFFFE2).if1l
#define IF1L_bit (*(volatile union un_if1l *)0xFFFE2).BIT
#define IF1H (*(volatile union un_if1h *)0xFFFE3).if1h
#define IF1H_bit (*(volatile union un_if1h *)0xFFFE3).BIT
#define MK0 (*(volatile union un_mk0 *)0xFFFE4).mk0
#define MK0_bit (*(volatile union un_mk0 *)0xFFFE4).BIT
#define MK0L (*(volatile union un_mk0l *)0xFFFE4).mk0l
#define MK0L_bit (*(volatile union un_mk0l *)0xFFFE4).BIT
#define MK0H (*(volatile union un_mk0h *)0xFFFE5).mk0h
#define MK0H_bit (*(volatile union un_mk0h *)0xFFFE5).BIT
#define MK1 (*(volatile union un_mk1 *)0xFFFE6).mk1
#define MK1_bit (*(volatile union un_mk1 *)0xFFFE6).BIT
#define MK1L (*(volatile union un_mk1l *)0xFFFE6).mk1l
#define MK1L_bit (*(volatile union un_mk1l *)0xFFFE6).BIT
#define MK1H (*(volatile union un_mk1h *)0xFFFE7).mk1h
#define MK1H_bit (*(volatile union un_mk1h *)0xFFFE7).BIT
#define PR00 (*(volatile union un_pr00 *)0xFFFE8).pr00
#define PR00_bit (*(volatile union un_pr00 *)0xFFFE8).BIT
#define PR00L (*(volatile union un_pr00l *)0xFFFE8).pr00l
#define PR00L_bit (*(volatile union un_pr00l *)0xFFFE8).BIT
#define PR00H (*(volatile union un_pr00h *)0xFFFE9).pr00h
#define PR00H_bit (*(volatile union un_pr00h *)0xFFFE9).BIT
#define PR01 (*(volatile union un_pr01 *)0xFFFEA).pr01
#define PR01_bit (*(volatile union un_pr01 *)0xFFFEA).BIT
#define PR01L (*(volatile union un_pr01l *)0xFFFEA).pr01l
#define PR01L_bit (*(volatile union un_pr01l *)0xFFFEA).BIT
#define PR01H (*(volatile union un_pr01h *)0xFFFEB).pr01h
#define PR01H_bit (*(volatile union un_pr01h *)0xFFFEB).BIT
#define PR10 (*(volatile union un_pr10 *)0xFFFEC).pr10
#define PR10_bit (*(volatile union un_pr10 *)0xFFFEC).BIT
#define PR10L (*(volatile union un_pr10l *)0xFFFEC).pr10l
#define PR10L_bit (*(volatile union un_pr10l *)0xFFFEC).BIT
#define PR10H (*(volatile union un_pr10h *)0xFFFED).pr10h
#define PR10H_bit (*(volatile union un_pr10h *)0xFFFED).BIT
#define PR11 (*(volatile union un_pr11 *)0xFFFEE).pr11
#define PR11_bit (*(volatile union un_pr11 *)0xFFFEE).BIT
#define PR11L (*(volatile union un_pr11l *)0xFFFEE).pr11l
#define PR11L_bit (*(volatile union un_pr11l *)0xFFFEE).BIT
#define PR11H (*(volatile union un_pr11h *)0xFFFEF).pr11h
#define PR11H_bit (*(volatile union un_pr11h *)0xFFFEF).BIT

/*
 Sfr bits
 */
#define ADCE ADM0_bit.no0
#define ADCS ADM0_bit.no7
#define SPD0 IICS0_bit.no0
#define STD0 IICS0_bit.no1
#define ACKD0 IICS0_bit.no2
#define TRC0 IICS0_bit.no3
#define COI0 IICS0_bit.no4
#define EXC0 IICS0_bit.no5
#define ALD0 IICS0_bit.no6
#define MSTS0 IICS0_bit.no7
#define IICRSV0 IICF0_bit.no0
#define STCEN0 IICF0_bit.no1
#define IICBSY0 IICF0_bit.no6
#define STCF0 IICF0_bit.no7
#define C0ENB COMPMDR_bit.no0
#define C0MON COMPMDR_bit.no3
#define C1ENB COMPMDR_bit.no4
#define C1MON COMPMDR_bit.no7
#define C0IE COMPOCR_bit.no0
#define C0OE COMPOCR_bit.no1
#define C0OP COMPOCR_bit.no2
#define C1IE COMPOCR_bit.no4
#define C1OE COMPOCR_bit.no5
#define C1OP COMPOCR_bit.no6
#define SPDMD COMPOCR_bit.no7
#define RCLOE1 RTCC0_bit.no5
#define RTCE RTCC0_bit.no7
#define RWAIT RTCC1_bit.no0
#define RWST RTCC1_bit.no1
#define RIFG RTCC1_bit.no3
#define WAFG RTCC1_bit.no4
#define RITE RTCC1_bit.no5
#define WALIE RTCC1_bit.no6
#define WALE RTCC1_bit.no7
#define HIOSTOP CSC_bit.no0
#define XTSTOP CSC_bit.no6
#define MSTOP CSC_bit.no7
#define MCM0 CKC_bit.no4
#define MCS CKC_bit.no5
#define CSS CKC_bit.no6
#define CLS CKC_bit.no7
#define PCLOE0 CKS0_bit.no7
#define PIF7 IF2L_bit.no0
#define PIF8 IF2L_bit.no1
#define PIF9 IF2L_bit.no2
#define CMPIF0 IF2L_bit.no3
#define CMPIF1 IF2L_bit.no4
#define CTSUWRIF IF2L_bit.no5
#define CTSURDIF IF2L_bit.no6
#define CTSUFNIF IF2L_bit.no7
#define PMK7 MK2L_bit.no0
#define PMK8 MK2L_bit.no1
#define PMK9 MK2L_bit.no2
#define CMPMK0 MK2L_bit.no3
#define CMPMK1 MK2L_bit.no4
#define CTSUWRMK MK2L_bit.no5
#define CTSURDMK MK2L_bit.no6
#define CTSUFNMK MK2L_bit.no7
#define PPR07 PR02L_bit.no0
#define PPR08 PR02L_bit.no1
#define PPR09 PR02L_bit.no2
#define CMPPR00 PR02L_bit.no3
#define CMPPR01 PR02L_bit.no4
#define CTSUWRPR0 PR02L_bit.no5
#define CTSURDPR0 PR02L_bit.no6
#define CTSUFNPR0 PR02L_bit.no7
#define PPR17 PR12L_bit.no0
#define PPR18 PR12L_bit.no1
#define PPR19 PR12L_bit.no2
#define CMPPR10 PR12L_bit.no3
#define CMPPR11 PR12L_bit.no4
#define CTSUWRPR1 PR12L_bit.no5
#define CTSURDPR1 PR12L_bit.no6
#define CTSUFNPR1 PR12L_bit.no7
#define WDTIIF IF0L_bit.no0
#define PIF0 IF0L_bit.no1
#define PIF1 IF0L_bit.no2
#define PIF2 IF0L_bit.no3
#define PIF3 IF0L_bit.no4
#define PIF4 IF0L_bit.no5
#define PIF5 IF0L_bit.no6
#define STIF0 IF0L_bit.no7
#define CSIIF00 IF0L_bit.no7
#define IICIF00 IF0L_bit.no7
#define SRIF0 IF0H_bit.no0
#define SREIF0 IF0H_bit.no1
#define TMIF01H IF0H_bit.no2
#define TMIF00 IF0H_bit.no3
#define TMIF01 IF0H_bit.no4
#define STIF1 IF0H_bit.no5
#define SRIF1 IF0H_bit.no6
#define CSIIF11 IF0H_bit.no6
#define IICIF11 IF0H_bit.no6
#define SREIF1 IF0H_bit.no7
#define STIF2 IF1L_bit.no0
#define CSIIF20 IF1L_bit.no0
#define IICIF20 IF1L_bit.no0
#define SRIF2 IF1L_bit.no1
#define SREIF2 IF1L_bit.no2
#define TMIF03H IF1L_bit.no3
#define IICAIF0 IF1L_bit.no4
#define TMIF02 IF1L_bit.no5
#define TMIF03 IF1L_bit.no6
#define ADIF IF1L_bit.no7
#define RTCIF IF1H_bit.no0
#define RTITIF IF1H_bit.no1
#define ITIF IF1H_bit.no2
#define TMIF04 IF1H_bit.no3
#define TMIF05 IF1H_bit.no4
#define TMIF06 IF1H_bit.no5
#define TMIF07 IF1H_bit.no6
#define PIF6 IF1H_bit.no7
#define WDTIMK MK0L_bit.no0
#define PMK0 MK0L_bit.no1
#define PMK1 MK0L_bit.no2
#define PMK2 MK0L_bit.no3
#define PMK3 MK0L_bit.no4
#define PMK4 MK0L_bit.no5
#define PMK5 MK0L_bit.no6
#define STMK0 MK0L_bit.no7
#define CSIMK00 MK0L_bit.no7
#define IICMK00 MK0L_bit.no7
#define SRMK0 MK0H_bit.no0
#define SREMK0 MK0H_bit.no1
#define TMMK01H MK0H_bit.no2
#define TMMK00 MK0H_bit.no3
#define TMMK01 MK0H_bit.no4
#define STMK1 MK0H_bit.no5
#define SRMK1 MK0H_bit.no6
#define CSIMK11 MK0H_bit.no6
#define IICMK11 MK0H_bit.no6
#define SREMK1 MK0H_bit.no7
#define STMK2 MK1L_bit.no0
#define CSIMK20 MK1L_bit.no0
#define IICMK20 MK1L_bit.no0
#define SRMK2 MK1L_bit.no1
#define SREMK2 MK1L_bit.no2
#define TMMK03H MK1L_bit.no3
#define IICAMK0 MK1L_bit.no4
#define TMMK02 MK1L_bit.no5
#define TMMK03 MK1L_bit.no6
#define ADMK MK1L_bit.no7
#define RTCMK MK1H_bit.no0
#define RTITMK MK1H_bit.no1
#define ITMK MK1H_bit.no2
#define TMMK04 MK1H_bit.no3
#define TMMK05 MK1H_bit.no4
#define TMMK06 MK1H_bit.no5
#define TMMK07 MK1H_bit.no6
#define PMK6 MK1H_bit.no7
#define WDTIPR0 PR00L_bit.no0
#define PPR00 PR00L_bit.no1
#define PPR01 PR00L_bit.no2
#define PPR02 PR00L_bit.no3
#define PPR03 PR00L_bit.no4
#define PPR04 PR00L_bit.no5
#define PPR05 PR00L_bit.no6
#define STPR00 PR00L_bit.no7
#define CSIPR000 PR00L_bit.no7
#define IICPR000 PR00L_bit.no7
#define SRPR00 PR00H_bit.no0
#define SREPR00 PR00H_bit.no1
#define TMPR001H PR00H_bit.no2
#define TMPR000 PR00H_bit.no3
#define TMPR001 PR00H_bit.no4
#define STPR01 PR00H_bit.no5
#define SRPR01 PR00H_bit.no6
#define CSIPR011 PR00H_bit.no6
#define IICPR011 PR00H_bit.no6
#define SREPR01 PR00H_bit.no7
#define STPR02 PR01L_bit.no0
#define CSIPR020 PR01L_bit.no0
#define IICPR020 PR01L_bit.no0
#define SRPR02 PR01L_bit.no1
#define SREPR02 PR01L_bit.no2
#define TMPR003H PR01L_bit.no3
#define IICAPR00 PR01L_bit.no4
#define TMPR002 PR01L_bit.no5
#define TMPR003 PR01L_bit.no6
#define ADPR0 PR01L_bit.no7
#define RTCPR0 PR01H_bit.no0
#define RTITPR0 PR01H_bit.no1
#define ITPR0 PR01H_bit.no2
#define TMPR004 PR01H_bit.no3
#define TMPR005 PR01H_bit.no4
#define TMPR006 PR01H_bit.no5
#define TMPR007 PR01H_bit.no6
#define PPR06 PR01H_bit.no7
#define WDTIPR1 PR10L_bit.no0
#define PPR10 PR10L_bit.no1
#define PPR11 PR10L_bit.no2
#define PPR12 PR10L_bit.no3
#define PPR13 PR10L_bit.no4
#define PPR14 PR10L_bit.no5
#define PPR15 PR10L_bit.no6
#define STPR10 PR10L_bit.no7
#define CSIPR100 PR10L_bit.no7
#define IICPR100 PR10L_bit.no7
#define SRPR10 PR10H_bit.no0
#define SREPR10 PR10H_bit.no1
#define TMPR101H PR10H_bit.no2
#define TMPR100 PR10H_bit.no3
#define TMPR101 PR10H_bit.no4
#define STPR11 PR10H_bit.no5
#define SRPR11 PR10H_bit.no6
#define CSIPR111 PR10H_bit.no6
#define IICPR111 PR10H_bit.no6
#define SREPR11 PR10H_bit.no7
#define STPR12 PR11L_bit.no0
#define CSIPR120 PR11L_bit.no0
#define IICPR120 PR11L_bit.no0
#define SRPR12 PR11L_bit.no1
#define SREPR12 PR11L_bit.no2
#define TMPR103H PR11L_bit.no3
#define IICAPR10 PR11L_bit.no4
#define TMPR102 PR11L_bit.no5
#define TMPR103 PR11L_bit.no6
#define ADPR1 PR11L_bit.no7
#define RTCPR1 PR11H_bit.no0
#define RTITPR1 PR11H_bit.no1
#define ITPR1 PR11H_bit.no2
#define TMPR104 PR11H_bit.no3
#define TMPR105 PR11H_bit.no4
#define TMPR106 PR11H_bit.no5
#define TMPR107 PR11H_bit.no6
#define PPR16 PR11H_bit.no7

/*
 Interrupt vector addresses
 */
#define RST_vect 0x0
#define INTDBG_vect 0x2
#define INTWDTI_vect 0x4
#define INTP0_vect 0x6
#define INTP1_vect 0x8
#define INTP2_vect 0xA
#define INTP3_vect 0xC
#define INTP4_vect 0xE
#define INTP5_vect 0x10
#define INTCSI00_vect 0x12
#define INTIIC00_vect 0x12
#define INTST0_vect 0x12
#define INTSR0_vect 0x14
#define INTSRE0_vect 0x16
#define INTTM01H_vect 0x18
#define INTTM00_vect 0x1A
#define INTTM01_vect 0x1C
#define INTST1_vect 0x1E
#define INTCSI11_vect 0x20
#define INTIIC11_vect 0x20
#define INTSR1_vect 0x20
#define INTSRE1_vect 0x22
#define INTCSI20_vect 0x24
#define INTIIC20_vect 0x24
#define INTST2_vect 0x24
#define INTSR2_vect 0x26
#define INTSRE2_vect 0x28
#define INTTM03H_vect 0x2A
#define INTIICA0_vect 0x2C
#define INTTM02_vect 0x2E
#define INTTM03_vect 0x30
#define INTAD_vect 0x32
#define INTRTC_vect 0x34
#define INTRTIT_vect 0x36
#define INTIT_vect 0x38
#define INTTM04_vect 0x3A
#define INTTM05_vect 0x3C
#define INTTM06_vect 0x3E
#define INTTM07_vect 0x40
#define INTP6_vect 0x42
#define INTP7_vect 0x44
#define INTP8_vect 0x46
#define INTP9_vect 0x48
#define INTCMP0_vect 0x4A
#define INTCMP1_vect 0x4C
#define INTCTSUWR_vect 0x4E
#define INTCTSURD_vect 0x50
#define INTCTSUFN_vect 0x52
#define INTFL_vect 0x54
#define BRK_I_vect 0x7E
#endif
