#ifndef _LIBSODIUM_PCH_
#define _LIBSODIUM_PCH_

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>

#include "core.h"
#include "crypto_generichash_blake2b.h"
#include "randombytes.h"
#include "utils.h"
#include "private/common.h"
#include "private/sse2_64_32.h"
#include "private/implementations.h"
#include "runtime.h"
#include "crypto_stream_chacha20.h"
#include "crypto_stream_salsa20.h"

#endif /* !_LIBSODIUM_PCH_ */
