/**
 * @file openaptx.h
 * @brief Reverse-engineered apt-X header file.
 *
 * This file is a part of [open]aptx.
 *
 * @copyright
 * This project is licensed under the terms of the MIT license.
 *
 * @note
 * The [open]aptx header file is based on the reverse-engineered proprietary
 * library, which is currently owned by Qualcomm. The apt-X library itself is
 * copyrighted under the terms of the Qualcomm Technologies, Inc.
 *
 */

#ifndef OPENAPTX_H
#define OPENAPTX_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Encoder handler. */
typedef void * APTXENC;

/**
 * Initialize encoder structure.
 *
 * @note
 * Encoder handler shall be properly allocated before passing it to
 * this function. To do so, one should use malloc(SizeofAptxbtenc()).
 *
 * @param enc Apt-X encoder handler.
 * @param swap Swap byte order of the output codeword. The output has to be in
 *   the big-endian format, so for little-endian hosts this value shall be set
 *   to true. One may use `__BYTE_ORDER == __LITTLE_ENDIAN` for convenience.
 * @return On success 0 is returned. */
int aptxbtenc_init(
		APTXENC enc,
		bool swap);

/**
 * Encode stereo PCM data.
 *
 * @param enc Initialized encoder handler.
 * @param pcmL Four 24-byte audio samples for left channel.
 * @param pcmR Four 24-byte audio samples for right channel.
 * @param code Two 16-byte codewords with auto-sync inserted.
 * @return On success 0 is returned. */
int aptxbtenc_encodestereo(
		APTXENC enc,
		const int32_t pcmL[4],
		const int32_t pcmR[4],
		uint16_t code[2]);

/**
 * Library build name. */
const char *aptxbtenc_build(void);

/**
 * Library version number. */
const char *aptxbtenc_version(void);

/**
 * Get the size of the encoder structure. */
size_t SizeofAptxbtenc(void);

/**
 * Get initialized encoder structure.
 *
 * @note
 * This function is NOT thread-safe.
 *
 * @param swap Swap byte order of the output codeword.
 * @return This function returns an address to the statically allocated
 *   encoder structure. Do not pass this handler to the free() function. */
APTXENC NewAptxEnc(bool swap);

#ifdef __cplusplus
}
#endif

#endif