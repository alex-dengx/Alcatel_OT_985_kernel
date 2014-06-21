#ifndef	_SMC9000_H_
# define _SMC9000_H_

/* I want some simple types */
typedef unsigned char			byte;
typedef unsigned short			word;
typedef unsigned long int		dword;


#define	BANK_SELECT		14

/* BANK 0  */

#define	TCR		0	/* transmit control register */
#define TCR_ENABLE	0x0001	/* if this is 1, we can transmit */
#define TCR_FDUPLX	0x0800	/* receive packets sent out */
#define TCR_STP_SQET	0x1000	/* stop transmitting if Signal quality error */
#define	TCR_MON_CNS	0x0400	/* monitors the carrier status */
#define	TCR_PAD_ENABLE	0x0080	/* pads short packets to 64 bytes */

#define	TCR_CLEAR	0	/* do NOTHING */
/* the normal settings for the TCR register : */
#define	TCR_NORMAL	(TCR_ENABLE | TCR_PAD_ENABLE)


#define EPH_STATUS	2
#define ES_LINK_OK	0x4000	/* is the link integrity ok ? */

#define	RCR		4
#define RCR_SOFTRESET	0x8000	/* resets the chip */
#define	RCR_STRIP_CRC	0x200	/* strips CRC */
#define RCR_ENABLE	0x100	/* IFF this is set, we can receive packets */
#define RCR_ALMUL	0x4	/* receive all multicast packets */
#define	RCR_PROMISC	0x2	/* enable promiscuous mode */

/* the normal settings for the RCR register : */
#define	RCR_NORMAL	(RCR_STRIP_CRC | RCR_ENABLE)
#define RCR_CLEAR	0x0		/* set it to a base state */

#define	COUNTER		6
#define	MIR		8
#define	MCR		10
/* 12 is reserved */

/* BANK 1 */
#define CONFIG			0
#define CFG_AUI_SELECT		0x100
#define	BASE			2
#define	ADDR0			4
#define	ADDR1			6
#define	ADDR2			8
#define	GENERAL			10
#define	CONTROL			12
#define	CTL_POWERDOWN		0x2000
#define	CTL_LE_ENABLE		0x80
#define	CTL_CR_ENABLE		0x40
#define	CTL_TE_ENABLE		0x0020
#define CTL_AUTO_RELEASE	0x0800
#define	CTL_EPROM_ACCESS	0x0003 /* high if Eprom is being read */

/* BANK 2 */
#define MMU_CMD		0
#define MC_BUSY		1	/* only readable bit in the register */
#define MC_NOP		0
#define	MC_ALLOC	0x20	/* or with number of 256 byte packets */
#define	MC_RESET	0x40
#define	MC_REMOVE	0x60	/* remove the current rx packet */
#define MC_RELEASE	0x80	/* remove and release the current rx packet */
#define MC_FREEPKT	0xA0	/* Release packet in PNR register */
#define MC_ENQUEUE	0xC0	/* Enqueue the packet for transmit */

#define	PNR_ARR		2
#define FIFO_PORTS	4

#define FP_RXEMPTY	0x8000
#define FP_TXEMPTY	0x80

#define	POINTER		6
#define PTR_READ	0x2000
#define	PTR_RCV		0x8000
#define	PTR_AUTOINC	0x4000
#define PTR_AUTO_INC	0x0040

#define	DATA_1		8
#define	DATA_2		10
#define	INTERRUPT	12

#define INT_MASK	13
#define IM_RCV_INT	0x1
#define	IM_TX_INT	0x2
#define	IM_TX_EMPTY_INT	0x4
#define	IM_ALLOC_INT	0x8
#define	IM_RX_OVRN_INT	0x10
#define	IM_EPH_INT	0x20
#define	IM_ERCV_INT	0x40 /* not on SMC9192 */

/* BANK 3 */
#define	MULTICAST1	0
#define	MULTICAST2	2
#define	MULTICAST3	4
#define	MULTICAST4	6
#define	MGMT		8
#define	REVISION	10 /* ( hi: chip id   low: rev # ) */


/* this is NOT on SMC9192 */
#define	ERCV		12

#define CHIP_9190	3
#define CHIP_9194	4
#define CHIP_9195	5
#define CHIP_9196	4
#define CHIP_91100	7
#define CHIP_91100FD	8

#define REV_9196	6

#define TS_SUCCESS	0x0001
#define TS_LOSTCAR	0x0400
#define TS_LATCOL	0x0200
#define TS_16COL	0x0010

#define RS_ALGNERR	0x8000
#define RS_BADCRC	0x2000
#define RS_ODDFRAME	0x1000
#define RS_TOOLONG	0x0800
#define RS_TOOSHORT	0x0400
#define RS_MULTICAST	0x0001
#define RS_ERRORS	(RS_ALGNERR | RS_BADCRC | RS_TOOLONG | RS_TOOSHORT)



/* select a register bank, 0 to 3  */

#define SMC_SELECT_BANK(x, y) { _outw( y, x + BANK_SELECT ); }

/* define a small delay for the reset */
#define SMC_DELAY(x) { inw( x + RCR );\
			inw( x + RCR );\
			inw( x + RCR ); }


#endif	/* _SMC_9000_H_ */
