#include <ntifs.h>
#include "../common/defs.h"

// Dummy driver entry point

VOID UnloadDriver(PDRIVER_OBJECT pDriverObject);
NTSTATUS DriverDispatch(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
    pDriverObject->DriverUnload = UnloadDriver;
    pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DriverDispatch;
    
    // Create device, symbolic link, etc.
    
    DbgPrint("insightcore: Driver loaded.\n");
    return STATUS_SUCCESS;
}

VOID UnloadDriver(PDRIVER_OBJECT pDriverObject) {
    DbgPrint("insightcore: Driver unloaded.\n");
}

NTSTATUS DriverDispatch(PDEVICE_OBJECT pDeviceObject, PIRP pIrp) {
    // Handle IOCTLs from the client application
    return STATUS_SUCCESS;
}
