#pragma once
#include <windows.h>

// Shared definitions between client and driver

#define IOCTL_READ_PROCESS_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GET_PROCESS_ID CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct _KERNEL_READ_REQUEST {
    ULONG ProcessId;
    ULONG_PTR Address;
    SIZE_T Size;
    PVOID pBuffer;
} KERNEL_READ_REQUEST, *PKERNEL_READ_REQUEST;
