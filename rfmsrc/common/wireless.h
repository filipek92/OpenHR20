/*
 *  Open HR20
 *
 *  target:     ATmega169 in Honnywell Rondostat HR20E / ATmega8
 *
 *  compiler:   WinAVR-20071221
 *              avr-libc 1.6.0
 *              GCC 4.2.2
 *
 *  copyright:  2008 Jiri Dobry (jdobry-at-centrum-dot-cz)
 *
 *  license:    This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU Library General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later version.
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *              GNU General Public License for more details.
 *
 *              You should have received a copy of the GNU General Public License
 *              along with this program. If not, see http:*www.gnu.org/licenses
 */

/*!
 * \file       wireless.c
 * \brief      wireless layer
 * \author     Jiri Dobry <jdobry-at-centrum-dot-cz>
 * \date       $Date$
 * $Rev$
 */


extern uint8_t Keys[5*8]; // 40 bytes
#define K_mac (Keys+0*8)
#define K_enc (Keys+1*8)
#define K1 (Keys+3*8)
#define K2 (Keys+4*8)
#define K_m (Keys+3*8)  /* share same position as K1 & K2 */
// note: do not change order of keys in Keys array, it depend to crypto_init

void crypto_init(void);
void wirelessSendPacket(void);
void wirelessReceivePacket(void);
#if defined(MASTER_CONFIG_H)
    void wirelessSendSync(void);
#else
    void wirelesTimeSyncCheck(void);
#endif 

#if (RFM==1)
void wireless_putchar(uint8_t ch);
#else
#define wireless_putchar(ch) 
#endif


extern int8_t time_sync_tmo;
extern uint8_t wireless_buf_ptr;
