/* File generated by C:\ncs\v2.9.0\nrf\scripts\partition_manager_output.py, do not modify */
#ifndef PM_CONFIG_H__
#define PM_CONFIG_H__
#define PM_TFM_OFFSET 0x0
#define PM_TFM_ADDRESS 0x0
#define PM_TFM_END_ADDRESS 0x8000
#define PM_TFM_SIZE 0x8000
#define PM_TFM_NAME tfm
#define PM_TFM_ID 0
#define PM_tfm_ID PM_TFM_ID
#define PM_tfm_IS_ENABLED 1
#define PM_0_LABEL TFM
#define PM_TFM_DEV flash_controller
#define PM_TFM_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_TFM_SECURE_OFFSET 0x0
#define PM_TFM_SECURE_ADDRESS 0x0
#define PM_TFM_SECURE_END_ADDRESS 0x8000
#define PM_TFM_SECURE_SIZE 0x8000
#define PM_TFM_SECURE_NAME tfm_secure
#define PM_TFM_SECURE_ID 1
#define PM_tfm_secure_ID PM_TFM_SECURE_ID
#define PM_tfm_secure_IS_ENABLED 1
#define PM_1_LABEL TFM_SECURE
#define PM_TFM_SECURE_DEV flash_controller
#define PM_TFM_SECURE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_APP_OFFSET 0x8000
#define PM_APP_ADDRESS 0x8000
#define PM_APP_END_ADDRESS 0x100000
#define PM_APP_SIZE 0xf8000
#define PM_APP_NAME app
#define PM_APP_ID 2
#define PM_app_ID PM_APP_ID
#define PM_app_IS_ENABLED 1
#define PM_2_LABEL APP
#define PM_APP_DEV flash_controller
#define PM_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_TFM_NONSECURE_OFFSET 0x8000
#define PM_TFM_NONSECURE_ADDRESS 0x8000
#define PM_TFM_NONSECURE_END_ADDRESS 0x100000
#define PM_TFM_NONSECURE_SIZE 0xf8000
#define PM_TFM_NONSECURE_NAME tfm_nonsecure
#define PM_TFM_NONSECURE_ID 3
#define PM_tfm_nonsecure_ID PM_TFM_NONSECURE_ID
#define PM_tfm_nonsecure_IS_ENABLED 1
#define PM_3_LABEL TFM_NONSECURE
#define PM_TFM_NONSECURE_DEV flash_controller
#define PM_TFM_NONSECURE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_OTP_OFFSET 0x0
#define PM_OTP_ADDRESS 0xff8100
#define PM_OTP_END_ADDRESS 0xff83fc
#define PM_OTP_SIZE 0x2fc
#define PM_OTP_NAME otp
#define PM_SRAM_SECURE_OFFSET 0x0
#define PM_SRAM_SECURE_ADDRESS 0x20000000
#define PM_SRAM_SECURE_END_ADDRESS 0x20008000
#define PM_SRAM_SECURE_SIZE 0x8000
#define PM_SRAM_SECURE_NAME sram_secure
#define PM_TFM_SRAM_OFFSET 0x0
#define PM_TFM_SRAM_ADDRESS 0x20000000
#define PM_TFM_SRAM_END_ADDRESS 0x20008000
#define PM_TFM_SRAM_SIZE 0x8000
#define PM_TFM_SRAM_NAME tfm_sram
#define PM_SRAM_NONSECURE_OFFSET 0x8000
#define PM_SRAM_NONSECURE_ADDRESS 0x20008000
#define PM_SRAM_NONSECURE_END_ADDRESS 0x20080000
#define PM_SRAM_NONSECURE_SIZE 0x78000
#define PM_SRAM_NONSECURE_NAME sram_nonsecure
#define PM_SRAM_PRIMARY_OFFSET 0x8000
#define PM_SRAM_PRIMARY_ADDRESS 0x20008000
#define PM_SRAM_PRIMARY_END_ADDRESS 0x20070000
#define PM_SRAM_PRIMARY_SIZE 0x68000
#define PM_SRAM_PRIMARY_NAME sram_primary
#define PM_RPMSG_NRF53_SRAM_OFFSET 0x70000
#define PM_RPMSG_NRF53_SRAM_ADDRESS 0x20070000
#define PM_RPMSG_NRF53_SRAM_END_ADDRESS 0x20080000
#define PM_RPMSG_NRF53_SRAM_SIZE 0x10000
#define PM_RPMSG_NRF53_SRAM_NAME rpmsg_nrf53_sram
#define PM_NUM 4
#define PM_ALL_BY_SIZE "otp tfm tfm_sram sram_secure tfm_secure rpmsg_nrf53_sram sram_primary sram_nonsecure app tfm_nonsecure"
#define PM_CPUNET_APP_OFFSET 0x0
#define PM_CPUNET_APP_ADDRESS 0x1000000
#define PM_CPUNET_APP_END_ADDRESS 0x1040000
#define PM_CPUNET_APP_SIZE 0x40000
#define PM_CPUNET_APP_NAME app
#define PM_CPUNET_APP_ID 4
#define PM_CPUNET_app_ID PM_APP_ID
#define PM_CPUNET_app_IS_ENABLED 1
#define PM_4_LABEL CPUNET_APP
#define PM_CPUNET_APP_DEV flash_controller
#define PM_CPUNET_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_CPUNET_IPC_RADIO_OFFSET 0x0
#define PM_CPUNET_IPC_RADIO_ADDRESS 0x1000000
#define PM_CPUNET_IPC_RADIO_END_ADDRESS 0x1040000
#define PM_CPUNET_IPC_RADIO_SIZE 0x40000
#define PM_CPUNET_IPC_RADIO_NAME ipc_radio
#define PM_CPUNET_IPC_RADIO_ID 5
#define PM_CPUNET_ipc_radio_ID PM_IPC_RADIO_ID
#define PM_CPUNET_ipc_radio_IS_ENABLED 1
#define PM_5_LABEL CPUNET_IPC_RADIO
#define PM_CPUNET_IPC_RADIO_DEV flash_controller
#define PM_CPUNET_IPC_RADIO_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_CPUNET_SRAM_PRIMARY_OFFSET 0x0
#define PM_CPUNET_SRAM_PRIMARY_ADDRESS 0x21000000
#define PM_CPUNET_SRAM_PRIMARY_END_ADDRESS 0x21010000
#define PM_CPUNET_SRAM_PRIMARY_SIZE 0x10000
#define PM_CPUNET_SRAM_PRIMARY_NAME sram_primary
#define PM_CPUNET_NUM 6
#define PM_CPUNET_ALL_BY_SIZE "sram_primary ipc_radio app"
#define PM_ADDRESS 0x8000
#define PM_SIZE 0xf8000
#define PM_SRAM_ADDRESS 0x20008000
#define PM_SRAM_SIZE 0x68000
#endif /* PM_CONFIG_H__ */