/**
 * \file sm4.h
 */
#ifndef XYSSL_SM4_H
#define XYSSL_SM4_H

#define SM4_ENCRYPT     1
#define SM4_DECRYPT     0
#define SM4_KEY_SIZE    16
#define SM4_BLOCK_SIZE  16

/**
 * \brief          SM4 context structure
 */
typedef unsigned int u32; 
typedef unsigned char u8;
typedef struct
{
    u32 sk[32];       /*!<  SM4 subkeys       */
    int mode;                   /*!<  encrypt/decrypt   */
}
sm4_context;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief          SM4 key schedule (128-bit, encryption)
 *
 * \param ctx      SM4 context to be initialized
 * \param key      16-byte secret key
 */
void sm4_setkey_enc( sm4_context *ctx, const u8 key[SM4_KEY_SIZE] );

/**
 * \brief          SM4 key schedule (128-bit, decryption)
 *
 * \param ctx      SM4 context to be initialized
 * \param key      16-byte secret key
 */
void sm4_setkey_dec( sm4_context *ctx, const u8 key[SM4_KEY_SIZE] );

/**
 * \brief          SM4 one block encryption/decryption
 * \param ctx      SM4 context
 * \param input    input block  //
 * \param output   output block
 */
void sm4_crypt( sm4_context *ctx,
                const u8 input[SM4_BLOCK_SIZE],
                u8 output[SM4_BLOCK_SIZE]);

#ifdef __cplusplus
}
#endif

#endif /* sm4.h */
