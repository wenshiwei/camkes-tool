/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _CAMKES_DMA_H_
#define _CAMKES_DMA_H_

#include <platsupport/io.h>
#include <stdint.h>

/* Initialise the DMA allocator. This function must be called before using any
 * of the functions below. Pass in the pool to allocate from, the size of this
 * pool in 4K pages and a function to reverse mappings. Returns 0 on success.
 */
int camkes_dma_init(void *dma_pool, size_t dma_pool_sz,
    uintptr_t (*get_paddr)(void *ptr));

/* Allocate a page for DMA used. Returns NULL on failure. */
void *camkes_dma_alloc_page(void);

/* Free a page that was allocated by camkes_dma_alloc_page. Behaviour is
 * undefined if you pass a pointer to memory that was not allocated by
 * camkes_dma_alloc_page.
 */
void camkes_dma_free_page(void *ptr);

/* Return the physical address of a pointer into a DMA buffer. Returns NULL if
 * you pass a pointer into memory that is not part of a DMA buffer. Behaviour
 * is undefined if you pass a pointer into memory that is part of a DMA buffer,
 * but not one currently allocated to you by camkes_dma_alloc_page.
 */
uintptr_t camkes_dma_get_paddr(void *ptr);

/* Initialise a DMA manager for use with libplatsupport. This manager will be
 * backed by the (generated) CAmkES DMA pool. Returns 0 on success.
 *
 * If you only need simple DMA allocation, prefer the alloc_page and free_page
 * functions above, but if you need a more interoperable DMA interface then use
 * this function. Note that you can mix calls to alloc_page, free_page and the
 * manager initialised by this function with no adverse effects.
 */
int camkes_dma_manager(ps_dma_man_t *man);

#endif
