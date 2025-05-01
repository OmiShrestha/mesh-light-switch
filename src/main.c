/*
 * Author: Omi Shrestha (work.omishrestha@gmail.com)
 * Implemented Bluetooth Mesh Light Switch using Zephyr RTOS sample code. 
*/

#include <zephyr/bluetooth/bluetooth.h>
#include <bluetooth/mesh/models.h>
#include <bluetooth/mesh/dk_prov.h>
#include <dk_buttons_and_leds.h>
#include "model_handler.h"

static void bt_ready(int err)
{
	if (err) {
		printk("Bluetooth initialization has failed (err %d)\n", err);
		return;
	}
	printk("Bluetooth initialized\n");

	err = dk_leds_init();
	if (err) {
		printk("Initializing LEDs failed (err %d)\n", err);
		return;
	}

	err = dk_buttons_init(NULL);
	if (err) {
		printk("Initializing buttons failed (err %d)\n", err);
		return;
	}

	err = bt_mesh_init(bt_mesh_dk_prov_init(), model_handler_init());
	if (err) {
		printk("Initializing mesh failed (err %d)\n", err);
		return;
	}

	// Check if the device is configured for Low Power Node (LPN) mode and enable it if true.
	if (IS_ENABLED(CONFIG_BT_MESH_LOW_POWER)) {
		bt_mesh_lpn_set(true);
	}

	// Load persistent settings if the CONFIG_SETTINGS option is enabled.
	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	/* This will be a no-op if settings_load() loaded provisioning info */
	bt_mesh_prov_enable(BT_MESH_PROV_ADV | BT_MESH_PROV_GATT);

	printk("Mesh initialized\n");
}

int main(void)
{
	int err;

	printk("Initializing...\n");

	err = bt_enable(bt_ready);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
	}

	return 0; // Will never reach here
}
