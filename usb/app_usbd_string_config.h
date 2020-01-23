/**
 * Copyright (c) 2016 - 2018, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
#ifndef APP_USBD_STRING_CONFIG_H
#define APP_USBD_STRING_CONFIG_H

/**
 * @brief Supported languages identifiers
 *
 * Comma separated list of supported languages.
 */
#define APP_USBD_STRINGS_LANGIDS \
    ((uint16_t)APP_USBD_LANG_ENGLISH | (uint16_t)APP_USBD_SUBLANG_ENGLISH_US)

// <i> Setting ID to 0 disables the string.
//==========================================================
#ifndef APP_USBD_STRING_ID_MANUFACTURER
#define APP_USBD_STRING_ID_MANUFACTURER 1
#endif

/**
 * @brief Define whether @ref APP_USBD_STRINGS_MANUFACTURER is created by @ref APP_USBD_STRING_DESC
 * or declared as global variable.
 * */
#ifndef APP_USBD_STRINGS_MANUFACTURER_EXTERN
#define APP_USBD_STRINGS_MANUFACTURER_EXTERN 0
#endif

/**
 * @brief Manufacturer name string descriptor
 *
 * Comma separated list of manufacturer names for each defined language.
 * Use @ref APP_USBD_STRING_DESC macro to create string descriptor.
 *
 * The order of manufacturer names has to be the same like in
 * @ref APP_USBD_STRINGS_LANGIDS.
 */
#ifndef APP_USBD_STRINGS_MANUFACTURER
#define APP_USBD_STRINGS_MANUFACTURER APP_USBD_STRING_DESC("Nordic Semiconductor")
#endif

// <e> APP_USBD_STRING_ID_PRODUCT - Define product string ID.

// <i> Setting ID to 0 disables the string.
//==========================================================
#ifndef APP_USBD_STRING_ID_PRODUCT
#define APP_USBD_STRING_ID_PRODUCT 2
#endif

/**
 * @brief Define whether @ref APP_USBD_STRINGS_PRODUCT is created by @ref APP_USBD_STRING_DESC
 * or declared as global variable.
 * */
#ifndef APP_USBD_STRINGS_PRODUCT_EXTERN
#define APP_USBD_STRINGS_PRODUCT_EXTERN 0
#endif

/**
 * @brief Product name string descriptor
 *
 * List of product names defined the same way like in @ref APP_USBD_STRINGS_MANUFACTURER
 */
#ifndef APP_USBD_STRINGS_PRODUCT
#define APP_USBD_STRINGS_PRODUCT APP_USBD_STRING_DESC("StravaV10")
#endif


// <e> APP_USBD_STRING_ID_SERIAL - Define serial number string ID.

// <i> Setting ID to 0 disables the string.
//==========================================================
#ifndef APP_USBD_STRING_ID_SERIAL
#define APP_USBD_STRING_ID_SERIAL 3
#endif

/**
 * @brief Define whether @ref APP_USBD_STRING_SERIAL is created by @ref APP_USBD_STRING_DESC
 * or declared as global variable.
 * */
#ifndef APP_USBD_STRING_SERIAL_EXTERN
#define APP_USBD_STRING_SERIAL_EXTERN 1
#endif
/**
 * @brief Serial number string descriptor
 *
 * Create serial number string descriptor using @ref APP_USBD_STRING_DESC,
 * or configure it to point to any internal variable pointer filled with descriptor.
 *
 * @note
 * There is only one SERIAL number inside the library and it is Language independent.
 */
#ifndef APP_USBD_STRING_SERIAL
#define APP_USBD_STRING_SERIAL g_extern_serial_number
#endif


// <i> Setting ID to 0 disables the string.
//==========================================================
#ifndef APP_USBD_STRING_ID_CONFIGURATION
#define APP_USBD_STRING_ID_CONFIGURATION 4
#endif

// <q> APP_USBD_STRING_CONFIGURATION_EXTERN  - Define whether @ref APP_USBD_STRINGS_CONFIGURATION is created by macro or declared as global variable.


#ifndef APP_USBD_STRING_CONFIGURATION_EXTERN
#define APP_USBD_STRING_CONFIGURATION_EXTERN 0
#endif

// <s> APP_USBD_STRINGS_CONFIGURATION - String descriptor for the device configuration.

// <i> Note: This value is not editable in Configuration Wizard.
// <i> Configuration string that is defined the same way like in @ref APP_USBD_STRINGS_MANUFACTURER.
#ifndef APP_USBD_STRINGS_CONFIGURATION
#define APP_USBD_STRINGS_CONFIGURATION APP_USBD_STRING_DESC("Default configuration")
#endif

/**
 * @brief User strings default values
 *
 * This value stores all application specific user strings with its default initialization.
 * The setup is done by X-macros.
 * Expected macro parameters:
 * @code
 * X(mnemonic, [=str_idx], ...)
 * @endcode
 * - @c mnemonic: Mnemonic of the string descriptor that would be added to
 *                @ref app_usbd_string_desc_idx_t enumerator.
 * - @c str_idx : String index value, may be set or left empty.
 *                For example WinUSB driver requires descriptor to be present on 0xEE index.
 *                Then use X(USBD_STRING_WINUSB, =0xEE, (APP_USBD_STRING_DESC(...)))
 * - @c ...     : List of string descriptors for each defined language.
 */
#ifndef APP_USBD_STRINGS_USER
#define APP_USBD_STRINGS_USER          \
    X(APP_USER_1, , APP_USBD_STRING_DESC("Biker1"))
#endif

/** @} */
#endif /* APP_USBD_STRING_CONFIG_H */
