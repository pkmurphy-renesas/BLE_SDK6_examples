/**************************************************************************//**
 * @file     os_tick.h
 * @brief    CMSIS OS Tick header file
 * @version  V1.0.1
 * @date     24. November 2017
 ******************************************************************************/
/*
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
/*
 * Copyright (c) 2021 Renesas Electronics Corporation. All rights reserved.
 * 
 * This software ("Software") is owned by Renesas Electronics Corporation. By using this
 * Software you agree that Renesas Electronics Corporation retains all intellectual
 * property and proprietary rights in and to this Software and any use, reproduction,
 * disclosure or distribution of the Software without express written permission or a
 * license agreement from Renesas Electronics Corporation is strictly prohibited. This
 * Software is solely for use on or in conjunction with Renesas Electronics Corporation
 * products.
 * 
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES OR AS
 * REQUIRED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. EXCEPT AS OTHERWISE PROVIDED
 * IN A LICENSE AGREEMENT BETWEEN THE PARTIES OR BY LAW, IN NO EVENT SHALL RENESAS
 * ELECTRONICS CORPORATION BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE SOFTWARE.
 *
 ***************************************************************************************
 */
/*
 * Copyright (c) 2021 Renesas Electronics Corporation. All rights reserved.
 * 
 * This software ("Software") is owned by Renesas Electronics Corporation. By using this
 * Software you agree that Renesas Electronics Corporation retains all intellectual
 * property and proprietary rights in and to this Software and any use, reproduction,
 * disclosure or distribution of the Software without express written permission or a
 * license agreement from Renesas Electronics Corporation is strictly prohibited. This
 * Software is solely for use on or in conjunction with Renesas Electronics Corporation
 * products.
 * 
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES OR AS
 * REQUIRED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. EXCEPT AS OTHERWISE PROVIDED
 * IN A LICENSE AGREEMENT BETWEEN THE PARTIES OR BY LAW, IN NO EVENT SHALL RENESAS
 * ELECTRONICS CORPORATION BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE SOFTWARE.
 *
 ***************************************************************************************
 */
/*
 * Copyright (c) 2017-2017 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OS_TICK_H
#define OS_TICK_H

#include <stdint.h>

/// IRQ Handler.
#ifndef IRQHANDLER_T
#define IRQHANDLER_T
typedef void (*IRQHandler_t) (void);
#endif

/// Setup OS Tick timer to generate periodic RTOS Kernel Ticks
/// \param[in]     freq         tick frequency in Hz
/// \param[in]     handler      tick IRQ handler
/// \return 0 on success, -1 on error.
int32_t  OS_Tick_Setup (uint32_t freq, IRQHandler_t handler);

/// Enable OS Tick timer interrupt
void     OS_Tick_Enable (void);

/// Disable OS Tick timer interrupt
void     OS_Tick_Disable (void);

/// Acknowledge execution of OS Tick timer interrupt
void     OS_Tick_AcknowledgeIRQ (void);

/// Get OS Tick timer IRQ number
/// \return OS Tick IRQ number
int32_t  OS_Tick_GetIRQn (void);

/// Get OS Tick timer clock frequency
/// \return OS Tick timer clock frequency in Hz
uint32_t OS_Tick_GetClock (void);

/// Get OS Tick timer interval reload value
/// \return OS Tick timer interval reload value
uint32_t OS_Tick_GetInterval (void);

/// Get OS Tick timer counter value
/// \return OS Tick timer counter value
uint32_t OS_Tick_GetCount (void);

/// Get OS Tick timer overflow status
/// \return OS Tick overflow status (1 - overflow, 0 - no overflow).
uint32_t OS_Tick_GetOverflow (void);

#endif  /* OS_TICK_H */