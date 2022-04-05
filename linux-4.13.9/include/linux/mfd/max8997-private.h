/*
 * max8997-private.h - Voltage regulator driver for the Maxim 8997
 *
 *  Copyright (C) 2010 Samsung Electrnoics
 *  MyungJoo Ham <myungjoo.ham@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINUX_MFD_MAX8997_PRIV_H
#define __LINUX_MFD_MAX8997_PRIV_H

#include <linux/i2c.h>
#include <linux/export.h>
#include <linux/irqdomain.h>

#define MAX8997_REG_INVALID	(0xff)

enum max8997_pmic_reg {
	MAX8997_REG_PMIC_ID0	= 0x00,
	MAX8997_REG_PMIC_ID1	= 0x01,
	MAX8997_REG_INTSRC	= 0x02,
	MAX8997_REG_INT1	= 0x03,
	MAX8997_REG_INT2	= 0x04,
	MAX8997_REG_INT3	= 0x05,
	MAX8997_REG_INT4	= 0x06,

	MAX8997_REG_INT1MSK	= 0x08,
	MAX8997_REG_INT2MSK	= 0x09,
	MAX8997_REG_INT3MSK	= 0x0a,
	MAX8997_REG_INT4MSK	= 0x0b,

	MAX8997_REG_STATUS1	= 0x0d,
	MAX8997_REG_STATUS2	= 0x0e,
	MAX8997_REG_STATUS3	= 0x0f,
	MAX8997_REG_STATUS4	= 0x10,

	MAX8997_REG_MAINCON1	= 0x13,
	MAX8997_REG_MAINCON2	= 0x14,
	MAX8997_REG_BUCKRAMP	= 0x15,

	MAX8997_REG_BUCK1CTRL	= 0x18,
	MAX8997_REG_BUCK1DVS1	= 0x19,
	MAX8997_REG_BUCK1DVS2	= 0x1a,
	MAX8997_REG_BUCK1DVS3	= 0x1b,
	MAX8997_REG_BUCK1DVS4	= 0x1c,
	MAX8997_REG_BUCK1DVS5	= 0x1d,
	MAX8997_REG_BUCK1DVS6	= 0x1e,
	MAX8997_REG_BUCK1DVS7	= 0x1f,
	MAX8997_REG_BUCK1DVS8	= 0x20,
	MAX8997_REG_BUCK2CTRL	= 0x21,
	MAX8997_REG_BUCK2DVS1	= 0x22,
	MAX8997_REG_BUCK2DVS2	= 0x23,
	MAX8997_REG_BUCK2DVS3	= 0x24,
	MAX8997_REG_BUCK2DVS4	= 0x25,
	MAX8997_REG_BUCK2DVS5	= 0x26,
	MAX8997_REG_BUCK2DVS6	= 0x27,
	MAX8997_REG_BUCK2DVS7	= 0x28,
	MAX8997_REG_BUCK2DVS8	= 0x29,
	MAX8997_REG_BUCK3CTRL	= 0x2a,
	MAX8997_REG_BUCK3DVS	= 0x2b,
	MAX8997_REG_BUCK4CTRL	= 0x2c,
	MAX8997_REG_BUCK4DVS	= 0x2d,
	MAX8997_REG_BUCK5CTRL	= 0x2e,
	MAX8997_REG_BUCK5DVS1	= 0x2f,
	MAX8997_REG_BUCK5DVS2	= 0x30,
	MAX8997_REG_BUCK5DVS3	= 0x31,
	MAX8997_REG_BUCK5DVS4	= 0x32,
	MAX8997_REG_BUCK5DVS5	= 0x33,
	MAX8997_REG_BUCK5DVS6	= 0x34,
	MAX8997_REG_BUCK5DVS7	= 0x35,
	MAX8997_REG_BUCK5DVS8	= 0x36,
	MAX8997_REG_BUCK6CTRL	= 0x37,
	MAX8997_REG_BUCK6BPSKIPCTRL	= 0x38,
	MAX8997_REG_BUCK7CTRL	= 0x39,
	MAX8997_REG_BUCK7DVS	= 0x3a,
	MAX8997_REG_LDO1CTRL	= 0x3b,
	MAX8997_REG_LDO2CTRL	= 0x3c,
	MAX8997_REG_LDO3CTRL	= 0x3d,
	MAX8997_REG_LDO4CTRL	= 0x3e,
	MAX8997_REG_LDO5CTRL	= 0x3f,
	MAX8997_REG_LDO6CTRL	= 0x40,
	MAX8997_REG_LDO7CTRL	= 0x41,
	MAX8997_REG_LDO8CTRL	= 0x42,
	MAX8997_REG_LDO9CTRL	= 0x43,
	MAX8997_REG_LDO10CTRL	= 0x44,
	MAX8997_REG_LDO11CTRL	= 0x45,
	MAX8997_REG_LDO12CTRL	= 0x46,
	MAX8997_REG_LDO13CTRL	= 0x47,
	MAX8997_REG_LDO14CTRL	= 0x48,
	MAX8997_REG_LDO15CTRL	= 0x49,
	MAX8997_REG_LDO16CTRL	= 0x4a,
	MAX8997_REG_LDO17CTRL	= 0x4b,
	MAX8997_REG_LDO18CTRL	= 0x4c,
	MAX8997_REG_LDO21CTRL	= 0x4d,

	MAX8997_REG_MBCCTRL1	= 0x50,
	MAX8997_REG_MBCCTRL2	= 0x51,
	MAX8997_REG_MBCCTRL3	= 0x52,
	MAX8997_REG_MBCCTRL4	= 0x53,
	MAX8997_REG_MBCCTRL5	= 0x54,
	MAX8997_REG_MBCCTRL6	= 0x55,
	MAX8997_REG_OTPCGHCVS	= 0x56,

	MAX8997_REG_SAFEOUTCTRL	= 0x5a,

	MAX8997_REG_LBCNFG1	= 0x5e,
	MAX8997_REG_LBCNFG2	= 0x5f,
	MAX8997_REG_BBCCTRL	= 0x60,

	MAX8997_REG_FLASH1_CUR	= 0x63, /* 0x63 ~ 0x6e for FLASH */
	MAX8997_REG_FLASH2_CUR	= 0x64,
	MAX8997_REG_MOVIE_CUR	= 0x65,
	MAX8997_REG_GSMB_CUR	= 0x66,
	MAX8997_REG_BOOST_CNTL	= 0x67,
	MAX8997_REG_LEN_CNTL	= 0x68,
	MAX8997_REG_FLASH_CNTL	= 0x69,
	MAX8997_REG_WDT_CNTL	= 0x6a,
	MAX8997_REG_MAXFLASH1	= 0x6b,
	MAX8997_REG_MAXFLASH2	= 0x6c,
	MAX8997_REG_FLASHSTATUS	= 0x6d,
	MAX8997_REG_FLASHSTATUSMASK	= 0x6e,

	MAX8997_REG_GPIOCNTL1	= 0x70,
	MAX8997_REG_GPIOCNTL2	= 0x71,
	MAX8997_REG_GPIOCNTL3	= 0x72,
	MAX8997_REG_GPIOCNTL4	= 0x73,
	MAX8997_REG_GPIOCNTL5	= 0x74,
	MAX8997_REG_GPIOCNTL6	= 0x75,
	MAX8997_REG_GPIOCNTL7	= 0x76,
	MAX8997_REG_GPIOCNTL8	= 0x77,
	MAX8997_REG_GPIOCNTL9	= 0x78,
	MAX8997_REG_GPIOCNTL10	= 0x79,
	MAX8997_REG_GPIOCNTL11	= 0x7a,
	MAX8997_REG_GPIOCNTL12	= 0x7b,

	MAX8997_REG_LDO1CONFIG	= 0x80,
	MAX8997_REG_LDO2CONFIG	= 0x81,
	MAX8997_REG_LDO3CONFIG	= 0x82,
	MAX8997_REG_LDO4CONFIG	= 0x83,
	MAX8997_REG_LDO5CONFIG	= 0x84,
	MAX8997_REG_LDO6CONFIG	= 0x85,
	MAX8997_REG_LDO7CONFIG	= 0x86,
	MAX8997_REG_LDO8CONFIG	= 0x87,
	MAX8997_REG_LDO9CONFIG	= 0x88,
	MAX8997_REG_LDO10CONFIG	= 0x89,
	MAX8997_REG_LDO11CONFIG	= 0x8a,
	MAX8997_REG_LDO12CONFIG	= 0x8b,
	MAX8997_REG_LDO13CONFIG	= 0x8c,
	MAX8997_REG_LDO14CONFIG	= 0x8d,
	MAX8997_REG_LDO15CONFIG	= 0x8e,
	MAX8997_REG_LDO16CONFIG	= 0x8f,
	MAX8997_REG_LDO17CONFIG	= 0x90,
	MAX8997_REG_LDO18CONFIG	= 0x91,
	MAX8997_REG_LDO21CONFIG	= 0x92,

	MAX8997_REG_DVSOKTIMER1	= 0x97,
	MAX8997_REG_DVSOKTIMER2	= 0x98,
	MAX8997_REG_DVSOKTIMER4	= 0x99,
	MAX8997_REG_DVSOKTIMER5	= 0x9a,

	MAX8997_REG_PMIC_END	= 0x9b,
};

enum max8997_muic_reg {
	MAX8997_MUIC_REG_ID		= 0x0,
	MAX8997_MUIC_REG_INT1		= 0x1,
	MAX8997_MUIC_REG_INT2		= 0x2,
	MAX8997_MUIC_REG_INT3		= 0x3,
	MAX8997_MUIC_REG_STATUS1	= 0x4,
	MAX8997_MUIC_REG_STATUS2	= 0x5,
	MAX8997_MUIC_REG_STATUS3	= 0x6,
	MAX8997_MUIC_REG_INTMASK1	= 0x7,
	MAX8997_MUIC_REG_INTMASK2	= 0x8,
	MAX8997_MUIC_REG_INTMASK3	= 0x9,
	MAX8997_MUIC_REG_CDETCTRL	= 0xa,

	MAX8997_MUIC_REG_CONTROL1	= 0xc,
	MAX8997_MUIC_REG_CONTROL2	= 0xd,
	MAX8997_MUIC_REG_CONTROL3	= 0xe,

	MAX8997_MUIC_REG_END		= 0xf,
};

/* MAX8997-MUIC STATUS1 register */
#define STATUS1_ADC_SHIFT		0
#define STATUS1_ADCLOW_SHIFT		5
#define STATUS1_ADCERR_SHIFT		6
#define STATUS1_ADC_MASK		(0x1f << STATUS1_ADC_SHIFT)
#define STATUS1_ADCLOW_MASK		(0x1 << STATUS1_ADCLOW_SHIFT)
#define STATUS1_ADCERR_MASK		(0x1 << STATUS1_ADCERR_SHIFT)

/* MAX8997-MUIC STATUS2 register */
#define STATUS2_CHGTYP_SHIFT		0
#define STATUS2_CHGDETRUN_SHIFT		3
#define STATUS2_DCDTMR_SHIFT		4
#define STATUS2_DBCHG_SHIFT		5
#define STATUS2_VBVOLT_SHIFT		6
#define STATUS2_CHGTYP_MASK		(0x7 << STATUS2_CHGTYP_SHIFT)
#define STATUS2_CHGDETRUN_MASK		(0x1 << STATUS2_CHGDETRUN_SHIFT)
#define STATUS2_DCDTMR_MASK		(0x1 << STATUS2_DCDTMR_SHIFT)
#define STATUS2_DBCHG_MASK		(0x1 << STATUS2_DBCHG_SHIFT)
#define STATUS2_VBVOLT_MASK		(0x1 << STATUS2_VBVOLT_SHIFT)

/* MAX8997-MUIC STATUS3 register */
#define STATUS3_OVP_SHIFT		2
#define STATUS3_OVP_MASK		(0x1 << STATUS3_OVP_SHIFT)

/* MAX8997-MUIC CONTROL1 register */
#define COMN1SW_SHIFT			0
#define COMP2SW_SHIFT			3
#define COMN1SW_MASK			(0x7 << COMN1SW_SHIFT)
#define COMP2SW_MASK			(0x7 << COMP2SW_SHIFT)
#define COMP_SW_MASK		(COMP2SW_MASK | COMN1SW_MASK)

#define CONTROL1_SW_USB			((1 << COMP2SW_SHIFT) \
						| (1 << COMN1SW_SHIFT))
#define CONTROL1_SW_AUDIO		((2 << COMP2SW_SHIFT) \
						| (2 << COMN1SW_SHIFT))
#define CONTROL1_SW_UART		((3 << COMP2SW_SHIFT) \
						| (3 << COMN1SW_SHIFT))
#define CONTROL1_SW_OPEN		((0 << COMP2SW_SHIFT) \
						| (0 << COMN1SW_SHIFT))

#define CONTROL2_LOWPWR_SHIFT		(0)
#define CONTROL2_ADCEN_SHIFT		(1)
#define CONTROL2_CPEN_SHIFT		(2)
#define CONTROL2_SFOUTASRT_SHIFT	(3)
#define CONTROL2_SFOUTORD_SHIFT		(4)
#define CONTROL2_ACCDET_SHIFT		(5)
#define CONTROL2_USBCPINT_SHIFT		(6)
#define CONTROL2_RCPS_SHIFT		(7)
#define CONTROL2_LOWPWR_MASK		(0x1 << CONTROL2_LOWPWR_SHIFT)
#define CONTROL2_ADCEN_MASK		(0x1 << CONTROL2_ADCEN_SHIFT)
#define CONTROL2_CPEN_MASK		(0x1 << CONTROL2_CPEN_SHIFT)
#define CONTROL2_SFOUTASRT_MASK		(0x1 << CONTROL2_SFOUTASRT_SHIFT)
#define CONTROL2_SFOUTORD_MASK		(0x1 << CONTROL2_SFOUTORD_SHIFT)
#define CONTROL2_ACCDET_MASK		(0x1 << CONTROL2_ACCDET_SHIFT)
#define CONTROL2_USBCPINT_MASK		(0x1 << CONTROL2_USBCPINT_SHIFT)
#define CONTROL2_RCPS_MASK		(0x1 << CONTROL2_RCPS_SHIFT)

#define CONTROL3_JIGSET_SHIFT		(0)
#define CONTROL3_BTLDSET_SHIFT		(2)
#define CONTROL3_ADCDBSET_SHIFT		(4)
#define CONTROL3_JIGSET_MASK		(0x3 << CONTROL3_JIGSET_SHIFT)
#define CONTROL3_BTLDSET_MASK		(0x3 << CONTROL3_BTLDSET_SHIFT)
#define CONTROL3_ADCDBSET_MASK		(0x3 << CONTROL3_ADCDBSET_SHIFT)

enum max8997_haptic_reg {
	MAX8997_HAPTIC_REG_GENERAL	= 0x00,
	MAX8997_HAPTIC_REG_CONF1	= 0x01,
	MAX8997_HAPTIC_REG_CONF2	= 0x02,
	MAX8997_HAPTIC_REG_DRVCONF	= 0x03,
	MAX8997_HAPTIC_REG_CYCLECONF1	= 0x04,
	MAX8997_HAPTIC_REG_CYCLECONF2	= 0x05,
	MAX8997_HAPTIC_REG_SIGCONF1	= 0x06,
	MAX8997_HAPTIC_REG_SIGCONF2	= 0x07,
	MAX8997_HAPTIC_REG_SIGCONF3	= 0x08,
	MAX8997_HAPTIC_REG_SIGCONF4	= 0x09,
	MAX8997_HAPTIC_REG_SIGDC1	= 0x0a,
	MAX8997_HAPTIC_REG_SIGDC2	= 0x0b,
	MAX8997_HAPTIC_REG_SIGPWMDC1	= 0x0c,
	MAX8997_HAPTIC_REG_SIGPWMDC2	= 0x0d,
	MAX8997_HAPTIC_REG_SIGPWMDC3	= 0x0e,
	MAX8997_HAPTIC_REG_SIGPWMDC4	= 0x0f,
	MAX8997_HAPTIC_REG_MTR_REV	= 0x10,

	MAX8997_HAPTIC_REG_END		= 0x11,
};

/* slave addr = 0x0c: using "2nd part" of rev4 datasheet */
enum max8997_rtc_reg {
	MAX8997_RTC_CTRLMASK		= 0x02,
	MAX8997_RTC_CTRL		= 0x03,
	MAX8997_RTC_UPDATE1		= 0x04,
	MAX8997_RTC_UPDATE2		= 0x05,
	MAX8997_RTC_WTSR_SMPL		= 0x06,

	MAX8997_RTC_SEC			= 0x10,
	MAX8997_RTC_MIN			= 0x11,
	MAX8997_RTC_HOUR		= 0x12,
	MAX8997_RTC_DAY_OF_WEEK		= 0x13,
	MAX8997_RTC_MONTH		= 0x14,
	MAX8997_RTC_YEAR		= 0x15,
	MAX8997_RTC_DAY_OF_MONTH	= 0x16,
	MAX8997_RTC_ALARM1_SEC		= 0x17,
	MAX8997_RTC_ALARM1_MIN		= 0x18,
	MAX8997_RTC_ALARM1_HOUR		= 0x19,
	MAX8997_RTC_ALARM1_DAY_OF_WEEK	= 0x1a,
	MAX8997_RTC_ALARM1_MONTH	= 0x1b,
	MAX8997_RTC_ALARM1_YEAR		= 0x1c,
	MAX8997_RTC_ALARM1_DAY_OF_MONTH	= 0x1d,
	MAX8997_RTC_ALARM2_SEC		= 0x1e,
	MAX8997_RTC_ALARM2_MIN		= 0x1f,
	MAX8997_RTC_ALARM2_HOUR		= 0x20,
	MAX8997_RTC_ALARM2_DAY_OF_WEEK	= 0x21,
	MAX8997_RTC_ALARM2_MONTH	= 0x22,
	MAX8997_RTC_ALARM2_YEAR		= 0x23,
	MAX8997_RTC_ALARM2_DAY_OF_MONTH	= 0x24,
};

enum max8997_irq_source {
	PMIC_INT1 = 0,
	PMIC_INT2,
	PMIC_INT3,
	PMIC_INT4,

	FUEL_GAUGE, /* Ignored (MAX17042 driver handles) */

	MUIC_INT1,
	MUIC_INT2,
	MUIC_INT3,

	GPIO_LOW, /* Not implemented */
	GPIO_HI, /* Not implemented */

	FLASH_STATUS, /* Not implemented */

	MAX8997_IRQ_GROUP_NR,
};

enum max8997_irq {
	MAX8997_PMICIRQ_PWRONR,
	MAX8997_PMICIRQ_PWRONF,
	MAX8997_PMICIRQ_PWRON1SEC,
	MAX8997_PMICIRQ_JIGONR,
	MAX8997_PMICIRQ_JIGONF,
	MAX8997_PMICIRQ_LOWBAT2,
	MAX8997_PMICIRQ_LOWBAT1,

	MAX8997_PMICIRQ_JIGR,
	MAX8997_PMICIRQ_JIGF,
	MAX8997_PMICIRQ_MR,
	MAX8997_PMICIRQ_DVS1OK,
	MAX8997_PMICIRQ_DVS2OK,
	MAX8997_PMICIRQ_DVS3OK,
	MAX8997_PMICIRQ_DVS4OK,

	MAX8997_PMICIRQ_CHGINS,
	MAX8997_PMICIRQ_CHGRM,
	MAX8997_PMICIRQ_DCINOVP,
	MAX8997_PMICIRQ_TOPOFFR,
	MAX8997_PMICIRQ_CHGRSTF,
	MAX8997_PMICIRQ_MBCHGTMEXPD,

	MAX8997_PMICIRQ_RTC60S,
	MAX8997_PMICIRQ_RTCA1,
	MAX8997_PMICIRQ_RTCA2,
	MAX8997_PMICIRQ_SMPL_INT,
	MAX8997_PMICIRQ_RTC1S,
	MAX8997_PMICIRQ_WTSR,

	MAX8997_MUICIRQ_ADCError,
	MAX8997_MUICIRQ_ADCLow,
	MAX8997_MUICIRQ_ADC,

	MAX8997_MUICIRQ_VBVolt,
	MAX8997_MUICIRQ_DBChg,
	MAX8997_MUICIRQ_DCDTmr,
	MAX8997_MUICIRQ_ChgDetRun,
	MAX8997_MUICIRQ_ChgTyp,

	MAX8997_MUICIRQ_OVP,

	MAX8997_IRQ_NR,
};

#define MAX8997_NUM_GPIO	12
struct max8997_dev {
	struct device *dev;
	struct max8997_platform_data *pdata;
	struct i2c_client *i2c; /* 0xcc / PMIC, Battery Control, and FLASH */
	struct i2c_client *rtc; /* slave addr 0x0c */
	struct i2c_client *haptic; /* slave addr 0x90 */
	struct i2c_client *muic; /* slave addr 0x4a */
	struct mutex iolock;

	unsigned long type;
	struct platform_device *battery; /* battery control (not fuel gauge) */

	int irq;
	int ono;
	struct irq_domain *irq_domain;
	struct mutex irqlock;
	int irq_masks_cur[MAX8997_IRQ_GROUP_NR];
	int irq_masks_cache[MAX8997_IRQ_GROUP_NR];

	/* For hibernation */
	u8 reg_dump[MAX8997_REG_PMIC_END + MAX8997_MUIC_REG_END +
		MAX8997_HAPTIC_REG_END];

	bool gpio_status[MAX8997_NUM_GPIO];
};

enum max8997_types {
	TYPE_MAX8997,
	TYPE_MAX8966,
};

extern int max8997_irq_init(struct max8997_dev *max8997);
extern void max8997_irq_exit(struct max8997_dev *max8997);
extern int max8997_irq_resume(struct max8997_dev *max8997);

extern int max8997_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest);
extern int max8997_bulk_read(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int max8997_write_reg(struct i2c_client *i2c, u8 reg, u8 value);
extern int max8997_bulk_write(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int max8997_update_reg(struct i2c_client *i2c, u8 reg, u8 val, u8 mask);

#define MAX8997_GPIO_INT_BOTH	(0x3 << 4)
#define MAX8997_GPIO_INT_RISE	(0x2 << 4)
#define MAX8997_GPIO_INT_FALL	(0x1 << 4)

#define MAX8997_GPIO_INT_MASK	(0x3 << 4)
#define MAX8997_GPIO_DATA_MASK	(0x1 << 2)
#endif /*  __LINUX_MFD_MAX8997_PRIV_H */
