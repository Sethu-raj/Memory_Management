# Linux Kernel Memory Management

## Overview

This repository contains programs and examples demonstrating the fundamental concepts of **Linux Kernel Memory Management**. The examples cover virtual memory, physical memory, page management, memory allocation techniques, buddy allocator, memory zones, page faults, and kernel memory allocation APIs.

The objective is to understand how the Linux kernel manages memory internally and how kernel modules allocate and free memory efficiently.

---

## Topics Covered

### 1. Physical Address Space
- 32-bit physical address space
- 4 GB addressable memory
- Memory-mapped I/O (MMIO)
- BIOS, APIC, PCI memory mapping

### 2. Virtual Memory
- Virtual vs Physical Address
- User Space and Kernel Space
- 3G/1G memory split
- MMU (Memory Management Unit)
- Address translation
- Page tables

### 3. Virtual to Physical Address Translation
- virt_to_phys()
- phys_to_virt()

### 4. Memory Pages
- PAGE_SIZE
- struct page
- Page Frames
- PFN (Page Frame Number)
- page_to_pfn()
- pfn_to_page()

### 5. Low Memory and High Memory
- LOWMEM
- HIGHMEM
- Kernel virtual memory mapping

### 6. User Space vs Kernel Space Allocation
- malloc()
- kmalloc()
- Demand Paging
- Lazy Allocation
- Physical memory allocation

### 7. Page Fault
- Minor Page Fault
- Major Page Fault
- Demand Paging example

### 8. Linux Memory Zones
- ZONE_DMA
- ZONE_DMA32
- ZONE_NORMAL

### 9. Buddy Allocator
- Physical page allocation
- Power-of-two allocation
- Memory splitting
- Buddy merging
- /proc/buddyinfo

### 10. Kernel Memory Allocators

#### kmalloc()
- Physically contiguous memory
- Slab allocator
- GFP flags

#### vmalloc()
- Virtually contiguous memory
- Large allocations

#### kzalloc()
- Zero initialized memory

#### kfree()
- Free kmalloc()/kzalloc() memory

#### vfree()
- Free vmalloc() memory

### 11. GFP Flags
- GFP_KERNEL
- GFP_ATOMIC
- GFP_DMA
- GFP_DMA32

### 12. ksize()
- Actual allocated memory size
- Memory alignment
- Allocation rounding

### 13. Linux Memory Information
- /proc/meminfo
- free -h
- free -m
- /proc/buddyinfo

---

## Programs Included

- Virtual to Physical Address Conversion
- PAGE_SIZE Example
- struct page Example
- Page Fault Demonstration
- Buddy Allocator Information
- GFP Flag Demonstration
- kmalloc() Example
- vmalloc() Example
- kzalloc() Example
- ksize() Example

---

## Directory Structure
