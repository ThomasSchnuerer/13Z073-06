/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  z73_doc.c
 *
 *      \author  Christian.Schuster@men.de
 *
 *      \brief   User documentation for Z73 module driver
 *
 *     Required: -
 *
 *     \switches -
 *
 *
 *---------------------------------------------------------------------------
 * Copyright 2005-2019, MEN Mikro Elektronik GmbH
 ****************************************************************************/

 /*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*! \mainpage
	This is the documentation of the MDIS low-level driver for the 16Z073_QDEC
	FPGA module.

	The 16Z073_QDEC is a quadrature decoder implemented in an Chameleon FPGA.
	It supports the following features:

	- 16 bit counter for position
	- debouncing of input signals (fixed debounce parameters)
	- seperate interrupts for move up, move down, button press and button
	  release.

	\n
	\section Variants Variants
	\code
	  Core      Description        Driver        Switch
	--------    ---------------    ----------    -------------
	16Z73-00    16 bit position    Standard           -
	16Z73-01    24 bit position    driver_24*    Z73_POSCNT_24
    \endcode

	\n \section FuncDesc Functional Description

	\n \subsection General General

	This Z073 MDIS5 driver initializes the hardware and services the interrupt
	of the FPGA module. If an interrupt occurs, the driver will send a signal
	(if installed) to the application to inform it that the button was moved,
	pressed or released.

	The actual data (position counter) is only read when the application
	performs an M_GetStat(Z073_STATUS). Due to the slow frequency of
	buttons the application should have plenty of time for collecting the data.

	\n \subsection reading Reading the Data

	The application can either poll the status of the module in an user
	definable frequency or install signals to get informed of changes on the
	hardware (only when individual interrupts enabled). Whenever the status
	is read, the position counter is zeroed and	the status of the individual
	events is reset.

	\n \subsubsection getblock Using M_getblock()
	The status can be read using the M_Getstat(Z073_STATUS). This GetStat will
	return an 32bit with the encoded status of the hardware. For the exact
	layout of this status word
	see \ref status_return "section about Z073_STATUS word returned".

	\n \section interrupts Interrupts
	The driver supports interrupts from the FPGA. The M-Module�s interrupt
	can be enabled/disabled through the M_MK_IRQ_ENABLE SetStat code or the
	device descriptor. The SetStats Z073_INT_UP, Z073_INT_DWN, Z073_INT_PRS
	and Z073_INT_REL enable/disable the single interrupt causes. The same effect
	can be achieved through the corresponding descriptor entries.

	\n \section signals Signals
	The driver can send signals to notify the application of changes on the
	signal lines . The signal must be activated via the Z73_SIG_PRS_REL and
	Z073_SIG_MOVE SetStat codes and can be cleared by the same code and passing
	0 as argument.

	\n \section api_functions Supported API Functions

	<table border="0">
	<tr>
		<td><b>API function</b></td>
		<td><b>Functionality</b></td>
		<td><b>Corresponding low level function</b></td></tr>

	<tr><td>M_open()</td><td>Open device</td><td>Z73_Init()</td></tr>

	<tr><td>M_close()     </td><td>Close device             </td>
	<td>Z73_Exit())</td></tr>
	<tr><td>M_read()      </td><td>not supported by driver  </td>
	<td>Z73_Read()</td></tr>
	<tr><td>M_write()     </td><td>not supported by driver  </td>
	<td>Z73_Write()</td></tr>
	<tr><td>M_setstat()   </td><td>Set device parameter     </td>
	<td>Z73_SetStat()</td></tr>
	<tr><td>M_getstat()   </td><td>Get device parameter     </td>
	<td>Z73_GetStat()</td></tr>
	<tr><td>M_getblock()  </td><td>not supported by driver  </td>
	<td>Z73_BlockRead()</td></tr>
	<tr><td>M_setblock()  </td><td>not supported by driver  </td>
	<td>Z73_BlockWrite()</td></tr>
	<tr><td>M_errstringTs() </td><td>Generate error message </td>
	<td>-</td></tr>
	</table>

	\n \section descriptor_entries Descriptor Entries

	The low-level driver initialization routine decodes the following entries
	("keys") in addition to the general descriptor keys:

	<table border="0">
	<tr><td><b>Descriptor entry</b></td>
		<td><b>Description</b></td>
		<td><b>Values</b></td>
	</tr>

	<tr><td>Z073_INT_PRS</td>
		<td>enable push button pressed interrupt</td>
		<td>0..1, default: 0</td>
	</tr>
	<tr><td>Z073_INT_REL</td>
		<td>enable push button released interrupt</td>
		<td>0..1, default: 0</td>
	</tr>
	<tr><td>Z073_INT_UP</td>
		<td>enable button (counter) moved up interrupt</td>
		<td>0..1, default: 0</td>
	</tr>
	<tr><td>Z073_INT_DWN</td>
		<td>enable button (counter) moved down interrupt</td>
		<td>0..1, default: 0</td>
	</tr>
	</table>


	\n \section codes Z73 specific Getstat/Setstat codes
	see \ref getstat_setstat_codes "section about Getstat/Setstat codes"

	\n \section Documents Overview of all Documents

	\subsection z73_simp  Simple example for using the driver
	z73_simp.c (see example section)
*/

/** \example z73_simp.c
Simple example for driver usage
*/

/** \page dummy
  \menimages
*/

