/*
 * Copyright (c) 2023 Nordic Semiconductor
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */
#include <zephyr/logging/log.h>
#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <soc.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <bluetooth/services/lbs.h>
#include <zephyr/settings/settings.h>

LOG_MODULE_REGISTER(MFS_BLE_ADV, LOG_LEVEL_DBG);

#define DEVICE_NAME         CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN     (sizeof(DEVICE_NAME) - 1)
#define RUN_LED_BLINK_INTERVAL 1000

static bool is_connected = false;

/* Get LED0 from the devicetree */
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* Advertising data */
static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_NO_BREDR),
    BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
};

/* Scan response data (example URL) */
static unsigned char url_data[] = {
    0x17, '/', '/', 'a', 'c', 'a', 'd', 'e', 'm', 'y', '.', 'n', 'o', 'r', 'd', 'i', 'c', 's', 'e', 'm', 'i', '.', 'c', 'o', 'm'
};
static const struct bt_data sd[] = {
    BT_DATA(BT_DATA_URI, url_data, sizeof(url_data)),
};

static void connected(struct bt_conn *conn, uint8_t err)
{
    if (err) {
        LOG_ERR("Connection failed (err %u)", err);
        return;
    }
    LOG_INF("Bluetooth connected");
    is_connected = true;
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
    LOG_INF("Bluetooth disconnected (reason %u)", reason);
    is_connected = false;
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
    .connected = connected,
    .disconnected = disconnected,
};

#if defined(APPROTECT_HW_DISABLE) && (APPROTECT_HW_DISABLE == 1)
void approtect_hw_disable(void)
{
    LOG_INF("In approtect_hw_disable()");
    /* Check if access port protection is enabled */
    if ((NRF_UICR->APPROTECT & UICR_APPROTECT_PALL_Msk) == UICR_APPROTECT_PALL_Msk) {
        LOG_INF("Access port protection is enabled; disabling...");
        NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Wen << NVMC_CONFIG_WEN_Pos;
        while (NRF_NVMC->READY == NVMC_READY_READY_Busy) {
            /* Waiting for NVMC to be ready */
            k_sleep(K_MSEC(1));
        }
        NRF_UICR->APPROTECT = (UICR_APPROTECT_PALL_Protected << UICR_APPROTECT_PALL_Pos);
        while (NRF_NVMC->READY == NVMC_READY_READY_Busy) {
            k_sleep(K_MSEC(1));
        }
        NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren << NVMC_CONFIG_WEN_Pos;
        while (NRF_NVMC->READY == NVMC_READY_READY_Busy) {
            k_sleep(K_MSEC(1));
        }
        LOG_INF("APPROTECT disabled; resetting system...");
        NVIC_SystemReset();
    } else {
        LOG_INF("Access port protection already disabled");
    }
}
#endif

int main(void)
{
    int err;
    bool blink_state = false;

    LOG_INF("Pre-HW Disable");
#if defined(APPROTECT_HW_DISABLE) && (APPROTECT_HW_DISABLE == 1)
    approtect_hw_disable();
#endif

    LOG_INF("Starting MFS BLE Advertising example");

    /* Configure LED0 */
    LOG_DBG("Checking LED0 device readiness...");
    if (!device_is_ready(led0.port)) {
        LOG_ERR("LED0 device is not ready");
        return -1;
    }
    LOG_DBG("Configuring LED0 as output...");
    err = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
    if (err < 0) {
        LOG_ERR("Failed to configure LED0 (err %d)", err);
        return err;
    }
    LOG_INF("LED0 configured");

    /* Initialize Bluetooth */
    LOG_INF("Initializing Bluetooth...");
    err = bt_enable(NULL);
    if (err) {
        LOG_ERR("Bluetooth init failed (err %d)", err);
        return -1;
    }
    LOG_INF("Bluetooth initialized");

    /* Start advertising */
    LOG_INF("Starting advertising...");
    err = bt_le_adv_start(BT_LE_ADV_NCONN, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
    if (err) {
        LOG_ERR("Advertising failed to start (err %d)", err);
        return -1;
    }
    LOG_INF("Advertising successfully started");

    while (1) {
        if (is_connected) {
            /* Solid LED when connected */
            LOG_DBG("Device connected: LED ON");
            gpio_pin_set_dt(&led0, 1);
        } else {
            /* Blink LED when not connected */
            blink_state = !blink_state;
            LOG_DBG("Device not connected: LED %s", blink_state ? "ON" : "OFF");
            gpio_pin_set_dt(&led0, blink_state);
        }
        k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));
    }

    return 0;
}
