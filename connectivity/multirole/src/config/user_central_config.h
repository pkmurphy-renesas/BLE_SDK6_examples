 /**
 ***************************************************************************************
 * Copyright (c) 2021 Renesas Electronics Corporation. All rights reserved.
 * 
 * The MIT License (MIT)
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************************
 */
#ifndef _USER_CENTRAL_CONFIG_H_
#define _USER_CENTRAL_CONFIG_H_

#define SCAN_FILTER_NONE									(0)
#define SCAN_FILTER_NAME									(1)
#define SCAN_FILTER_16_BIT_SVC_DATA				(2)
#define SCAN_FILTER_TX_POWER							(3)
#define SCAN_FILTER_MFG_DATA							(4)

#define	SCAN_FILTER												(SCAN_FILTER_NAME)

#define CONNECT_TO_PERIPHERAL							(1)

#if CONNECT_TO_PERIPHERAL == 1
	#if SCAN_FILTER == SCAN_FILTER_NAME
		#define PERIPH_MATCH_DATA			"DLG-PROXR"
		#define PERIPH_MATCH_DATA_LEN	(sizeof(PERIPH_MATCH_DATA))
	#else
		#undef CONNECT_TO_PERIPHERAL
	#endif
		
	#define xENABLE_BAS
		
	#define xENABLE_IAS
		
	#define CONNECTION_TIMEOUT_10MS			(1000) //5 seconds

#endif 
		
		
#ifdef APP_EASY_MAX_ACTIVE_CONNECTION
#undef APP_EASY_MAX_ACTIVE_CONNECTION
#define APP_EASY_MAX_ACTIVE_CONNECTION      (CFG_MAX_CONNECTIONS)
#endif

#endif //_USER_CENTRAL_CONFIG_H_
		