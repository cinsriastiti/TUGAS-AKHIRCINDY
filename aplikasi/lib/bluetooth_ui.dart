import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:flutter_application_ble/bluetooth_controller.dart';

class BluetoothUi extends StatelessWidget {
  BluetoothUi({super.key});

  final BluetoothController controller = Get.put(BluetoothController());

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        children: [
          const SizedBox(height: 20),

          Container(
            width: MediaQuery.of(context).size.width * 0.9,
            height: 260,
            padding: const EdgeInsets.all(20),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(25),
              boxShadow: [
                BoxShadow(
                  color: Colors.black.withOpacity(0.15),
                  blurRadius: 10,
                  offset: const Offset(0, 4),
                ),
              ],
            ),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Container(
                  width: 150,
                  height: 150,
                  decoration: const BoxDecoration(
                    color: Color.fromARGB(255, 255, 254, 254),
                    shape: BoxShape.circle,
                  ),
                  child: const Center(
                    child: Icon(
                      Icons.bluetooth_searching_rounded,
                      color: Colors.blue,
                      size: 100,
                    ),
                  ),
                ),

                const SizedBox(height: 15),

                Obx(
                  () => Text(
                    controller.bluetoothIsOn.value
                        ? "Bluetooth Aktif"
                        : "Bluetooth Mati",
                    style: const TextStyle(
                      fontSize: 20,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                ),
                Obx(() {
                  final dev = controller.connectedDevice.value;
                  if (dev == null) {
                    return const Text(
                      "Device Belum Terhubung",
                      style: TextStyle(color: Colors.black),
                    );
                  }
                  return Text(
                    "Connected To: ${dev.platformName}",
                    style: const TextStyle(
                      color: Colors.black,
                      fontSize: 9,
                      fontWeight: FontWeight.w600,
                    ),
                  );
                }),
              ],
            ),
          ),

          const SizedBox(height: 20),

          Expanded(
            child: Container(
              margin: const EdgeInsets.only(bottom: 20),
              width: MediaQuery.of(context).size.width * 0.9,
              padding: const EdgeInsets.all(20),
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(25),
                boxShadow: [
                  BoxShadow(
                    color: Colors.black.withOpacity(0.15),
                    blurRadius: 10,
                    offset: const Offset(0, 4),
                  ),
                ],
              ),

              child: Column(
                children: [
                  Obx(
                    () => SizedBox(
                      width: double.infinity,
                      height: 50,
                      child: ElevatedButton(
                        onPressed: controller.isScanning.value
                            ? null
                            : () => controller.scanDevices(),
                        style: ElevatedButton.styleFrom(
                          backgroundColor: Color.fromARGB(255, 104, 145, 90),
                          foregroundColor: Colors.white,
                          shape: RoundedRectangleBorder(
                            borderRadius: BorderRadius.circular(12),
                          ),
                        ),
                        child: controller.isScanning.value
                            ? const CircularProgressIndicator(
                                color: Colors.white,
                              )
                            : const Text(
                                "Scan Bluetooth",
                                style: TextStyle(fontSize: 18),
                              ),
                      ),
                    ),
                  ),

                  const SizedBox(height: 15),

                  Expanded(
                    child: Obx(() {
                      final devices = controller.scanResults;

                      if (devices.isEmpty) {
                        return const Center(
                          child: Text(
                            "Belum ada perangkat",
                            style: TextStyle(fontSize: 16),
                          ),
                        );
                      }

                      return ListView.builder(
                        itemCount: devices.length,
                        itemBuilder: (context, index) {
                          final d = devices[index];

                          final isConnected =
                              controller.connectedDevice.value?.remoteId ==
                              d.device.remoteId;

                          return Card(
                            shape: RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(15),
                            ),
                            child: ListTile(
                              leading: const Icon(Icons.devices),
                              title: Text(
                                d.device.platformName.isEmpty
                                    ? "Unknown Device"
                                    : d.device.platformName,
                              ),
                              subtitle: Text(d.device.remoteId.toString()),
                              trailing: Obx(() {
                                final current =
                                    controller.connectedDevice.value;

                                if (isConnected) {
                                  return const Icon(
                                    Icons.check_circle,
                                    color: Colors.green,
                                  );
                                } else if (current != null &&
                                    current.remoteId != d.device.remoteId) {
                                  return const Text(
                                    "Busy",
                                    style: TextStyle(color: Colors.grey),
                                  );
                                } else {
                                  return ElevatedButton(
                                    onPressed: () =>
                                        controller.connectToDevice(d.device),
                                    child: const Text("Connect"),
                                  );
                                }
                              }),
                            ),
                          );
                        },
                      );
                    }),
                  ),
                  Obx(() {
                    final isConnected =
                        controller.connectedDevice.value != null;

                    if (!isConnected) return const SizedBox();

                    return SizedBox(
                      width: double.infinity,
                      height: 50,
                      child: ElevatedButton(
                        onPressed: () => controller.disconnect(),
                        style: ElevatedButton.styleFrom(
                          backgroundColor: Colors.red,
                          foregroundColor: Colors.white,
                          shape: RoundedRectangleBorder(
                            borderRadius: BorderRadiusGeometry.circular(12),
                          ),
                        ),
                        child: const Text(
                          "Disconnected",
                          style: TextStyle(fontSize: 15),
                        ),
                      ),
                    );
                  }),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
