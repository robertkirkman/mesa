/*
 * © Copyright 2018 Alyssa Rosenzweig
 * Copyright (C) 2019 Collabora, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "pan_bo.h"
#include "pan_device.h"
#include "pan_pool.h"

/* Knockoff u_upload_mgr. Uploads whereever we left off, allocating new entries
 * when needed.
 */

mali_ptr
pan_pool_upload(struct pan_pool *pool, const void *data, size_t sz)
{
        return pan_pool_upload_aligned(pool, data, sz, sz);
}

mali_ptr
pan_pool_upload_aligned(struct pan_pool *pool, const void *data, size_t sz, unsigned alignment)
{
        struct panfrost_ptr transfer = pan_pool_alloc_aligned(pool, sz, alignment);
        memcpy(transfer.cpu, data, sz);
        return transfer.gpu;
}
