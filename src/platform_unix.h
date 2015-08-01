
//    Milton Paint
//    Copyright (C) 2015  Sergio Gonzalez
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


#ifdef __linux__
#define _GNU_SOURCE  // To get MAP_ANONYMOUS on linux
#include <asm-generic/mman-common.h>
#include <sys/mman.h>
#else
#error "This is not the Unix you're looking for"
#endif


#define inline extern inline

#define HEAP_BEGIN_ADDRESS NULL
#ifndef NDEBUG
#undef HEAP_BEGIN_ADDRESS
#define HEAP_BEGIN_ADDRESS (void*)(1024LL * 1024 * 1024 * 1024)
#endif

#ifndef MAP_ANONYMOUS

#ifndef MAP_ANON
#error "MAP_ANONYMOUS flag not found!"
#else
#define MAP_ANONYMOUS MAP_ANON
#endif

#endif // MAP_ANONYMOUS

#define allocate_big_chunk_of_memory(total_memory_size) mmap(HEAP_BEGIN_ADDRESS, \
                                                             total_memory_size, \
                                                             PROT_WRITE | PROT_READ, \
                                                             MAP_PRIVATE | MAP_ANONYMOUS, \
                                                             -1, \
                                                             0)
#define platform_load_gl_func_pointers()

#define milton_log printf

int main(int argc, char** argv)
{
    milton_main();
}
