/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  z73_drv.h
 *
 *      \author  cs
 *
 *       \brief  Header file for Z73 driver containing
 *               Z73 specific status codes and
 *               Z73 function prototypes
 *
 *    \switches  _ONE_NAMESPACE_PER_DRIVER_
 *               _LL_DRV_
 *               Z73_POSCNT_24
 *
 *
 *---------------------------------------------------------------------------
 * Copyright 2010-2019, MEN Mikro Elektronik GmbH
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

#ifndef _Z73_DRV_H
#define _Z73_DRV_H

#ifdef __cplusplus
      extern "C" {
#endif

/*-----------------------------------------+
|  DEFINES                                 |
+-----------------------------------------*/
/** \name Z73 specific Getstat/Setstat standard codes
 *  \anchor getstat_setstat_codes
 */
/**@{*/
#define Z073_SIG_PRS_REL        (M_DEV_OF+0x00)
        /**<  S:  set signal to trigger when button is pressed/released */
#define Z073_SIG_MOVE           (M_DEV_OF+0x01)
        /**<  S:  set signal to trigger when button is moved up or down */
#define Z073_INT_PRS            (M_DEV_OF+0x02)
        /**< G/S: set/clear interrupt enable for button pressed */
#define Z073_INT_REL            (M_DEV_OF+0x03)
        /**< G/S: set/clear interrupt enable for button release */
#define Z073_INT_UP             (M_DEV_OF+0x04)
        /**< G/S: set/clear interrupt enable for button move up */
#define Z073_INT_DWN            (M_DEV_OF+0x05)
        /**< G/S: set/clear interrupt enable for button move down */
#define Z073_STATUS             (M_DEV_OF+0x06)
        /**<  G: get information (structure) about current button status
                 (button pressed/released, count moved up/down). */
        /*!< This is usually called from application after a signal is
             received. */
/**@}*/

/** \name Z073_STATUS word returned
 *  \anchor status_return
 */
/**@{*/
#define Z073_STATUS_PRESS_N     0x40000000  /**< current: push button pressed */
#define Z073_STATUS_INPUT_B     0x20000000  /**< current: input A       */
#define Z073_STATUS_INPUT_A     0x10000000  /**< current: input B       */
#define Z073_STATUS_REL         0x08000000  /**< push button released   */
#define Z073_STATUS_PRS         0x04000000  /**< push button pressed    */
#define Z073_STATUS_MOV         0x01000000  /**< position changed       */
#ifdef Z73_POSCNT_24
 #define Z073_STATUS_CNT        0x00FFFFFF  /**< current position       */
#else
 #define Z073_STATUS_CNT        0x0000FFFF  /**< current position       */
#endif
/**@}*/

/** \name Z073 specific Error/Warning codes */
/**@{*/
#define Z073_ERR_NO_STATUS          (ERR_DEV+1) /**< No status change from HW */
#define Z073_ERR_STATUSQ_FULL       (ERR_DEV+2) /**< Status queue full */
/**@}*/

/*-----------------------------------------+
|  TYPEDEFS                                |
+-----------------------------------------*/
/* ... */
/*-----------------------------------------+
|  PROTOTYPES                              |
+-----------------------------------------*/
#ifdef _LL_DRV_
#   ifdef _ONE_NAMESPACE_PER_DRIVER_
#       define Z73_GetEntry LL_GetEntry
#   else
#       ifdef Z73_SW
#           define Z73_GetEntry Z73_SW_GetEntry
#       endif /* Z73_SW */
        extern void Z73_GetEntry(LL_ENTRY* drvP);
#   endif
#endif /* _LL_DRV_ */

/*-----------------------------------------+
|  BACKWARD COMPATIBILITY TO MDIS4         |
+-----------------------------------------*/
#ifndef U_INT32_OR_64
 /* we have an MDIS4 men_types.h and mdis_api.h included */
 /* only 32bit compatibility needed!                     */
 #define INT32_OR_64  int32
 #define U_INT32_OR_64 u_int32
 typedef INT32_OR_64  MDIS_PATH;
#endif /* U_INT32_OR_64 */

#ifdef __cplusplus
      }
#endif

#endif /* _Z73_DRV_H */

