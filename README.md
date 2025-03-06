---

# Project Context and Known Issues

This repository contains the MFS BLE Advertising example developed for a custom Nordic nRF5340 MFS. The project is intended to initialize Bluetooth Low Energy (BLE) advertising while toggling an LED (LED0) based on connection status. The code was derived from the reference example used on the nRF5340 DK, with modifications to support our custom hardware configuration.

## Project Overview

- **Platform:** Nordic nRF5340 MFS variant
- **Purpose:**  
  - Initialize BLE stack and start advertising.
  - Indicate device state via LED0: blink when not connected, steady when connected.
- **Key Modules:**
  - Zephyr RTOS (v3.7.99-1f8f3dc29142)
  - Nordic BLE host and HCI driver
  - Custom board configuration (using internal flash only, with LED remapped)

## Known Issues and Error Messages

Several issues have been observed during development, which appear to be configuration-related rather than hardware differences. Below are the error messages encountered:

### Error Message 1: Kernel Oops due to HCI Driver Timeout

```
*** Booting nRF Connect SDK v2.9.0-7787b2649840 ***
*** Using Zephyr OS v3.7.99-1f8f3dc29142 ***
[00:00:00.251,831] <inf> MFS_BLE_ADV: Pre-HW Disable
[00:00:00.251,831] <inf> MFS_BLE_ADV: Starting MFS BLE Advertising example
[00:00:00.251,861] <dbg> MFS_BLE_ADV: main: Checking LED0 device readiness...
[00:00:00.251,861] <dbg> MFS_BLE_ADV: main: Configuring LED0 as output...
[00:00:00.251,892] <inf> MFS_BLE_ADV: LED0 configured
[00:00:00.251,892] <inf> MFS_BLE_ADV: Initializing Bluetooth...
ASSERTION FAIL [err == 0] @ WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c:430
        Controller unresponsive, command opcode 0x0c03 timeout with err -11
[00:00:10.262,268] <err> os: r0/a1:  0x00000003  r1/a2:  0x00000000  r2/a3:  0x00000002
[00:00:10.262,298] <err> os: r3/a4:  0x00000003 r12/ip:  0x00000010 r14/lr:  0x0000bf1f
[00:00:10.262,298] <err> os:  xpsr:  0x01000000
[00:00:10.262,329] <err> os: Faulting instruction address (r15/pc): 0x0000bf2e
[00:00:10.262,359] <err> os: >>> ZEPHYR FATAL ERROR 3: Kernel oops on CPU 0
[00:00:10.262,389] <err> os: Current thread: 0x20009468 (unknown)
[00:00:10.899,963] <err> os: Halting system
```

**Context:**  
This error indicates that during initialization, the HCI driver failed to receive a timely response from the Bluetooth controller. The error `-11` is being returned, leading to an assertion failure and a kernel oops on CPU 0.

### Error Message 2: HCI Endpoint Binding Failure

```
*** Booting nRF Connect SDK v2.9.0-7787b2649840 ***
*** Using Zephyr OS v3.7.99-1f8f3dc29142 ***
[00:00:00.251,831] <inf> MFS_BLE_ADV: Pre-HW Disable
[00:00:00.251,831] <inf> MFS_BLE_ADV: Starting MFS BLE Advertising example
[00:00:00.251,861] <dbg> MFS_BLE_ADV: main: Checking LED0 device readiness...
[00:00:00.251,861] <dbg> MFS_BLE_ADV: main: Configuring LED0 as output...
[00:00:00.251,892] <inf> MFS_BLE_ADV: LED0 configured
[00:00:00.251,892] <inf> MFS_BLE_ADV: Initializing Bluetooth...
[00:00:01.252,807] <err> bt_hci_driver: Endpoint binding failed with -11
[00:00:01.252,807] <err> bt_hci_core: HCI driver open failed (-11)
[00:00:01.252,838] <err> MFS_BLE_ADV: Bluetooth init failed (err -11)
```

**Context:**  
This error occurs during the Bluetooth initialization phase. The HCI driver is unable to bind to the endpoint, which results in an error `-11`. This failure prevents the BLE stack from initializing correctly.

---
