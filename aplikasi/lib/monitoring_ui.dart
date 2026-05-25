import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:flutter_application_ble/maps_controller.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:flutter_application_ble/history_controller.dart';
import 'package:flutter_application_ble/bluetooth_controller.dart';
import 'package:flutter_application_ble/monitoring_controller.dart';

final maps = Get.put(MapsController());

class MonitoringUi extends StatelessWidget {
  MonitoringUi({super.key});

  final monitoring = Get.put(MonitoringController());
  final bluetooth = Get.find<BluetoothController>();
  final history = Get.find<HistoryController>();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color.fromARGB(255, 244, 243, 243),
      body: Obx(
        () => SingleChildScrollView(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Container(
                // liat si bluetoothnya udha kesambung ataubelumm
                padding: const EdgeInsets.all(16),
                decoration: BoxDecoration(
                  color: bluetooth.connectedDevice.value != null
                      ? const Color.fromARGB(255, 35, 137, 220)
                      : const Color.fromARGB(255, 232, 71, 69),
                  borderRadius: BorderRadius.circular(10),
                ),

                // bluetooth
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Icon(
                      bluetooth.connectedDevice.value != null
                          ? Icons.bluetooth_connected
                          : Icons.bluetooth_disabled,
                      color: Colors.white,
                      size: 30,
                    ),
                    const SizedBox(width: 10),
                    Text(
                      bluetooth.connectedDevice.value != null
                          ? "Bluetooth Connected : ${bluetooth.connectedDevice.value!.platformName}"
                          : "Bluetooth Not Connected",
                      style: const TextStyle(
                        color: Colors.white,
                        fontSize: 11,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ],
                ),
              ),

              // GMAPS
              const SizedBox(height: 20),
              SizedBox(
                height: 200,
                child: Obx(() {
                  if (maps.currentPosition.value.latitude == 0 &&
                      maps.currentPosition.value.longitude == 0) {
                    return const Center(child: CircularProgressIndicator());
                  }

                  return GoogleMap(
                    mapType: MapType.hybrid,
                    initialCameraPosition: CameraPosition(
                      target: maps.currentPosition.value,
                      zoom: 18,
                    ),
                    onMapCreated: maps.onMapCreated,
                    markers: maps.markerSet.toSet(),
                    onTap: maps.onTap,
                    zoomControlsEnabled: true,
                    scrollGesturesEnabled: true,
                    myLocationEnabled: true,
                    myLocationButtonEnabled: true,
                  );
                }),
              ),

              SizedBox(height: 8),
              Obx(() {
                final pos =
                    maps.pickedPosition.value ?? maps.currentPosition.value;

                return Center(
                  child: Column(
                    children: [
                      const Text(
                        "Lokasi Terpilih",
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      Text(
                        "${pos.latitude}, ${pos.longitude}",
                        style: const TextStyle(fontSize: 16),
                      ),
                    ],
                  ),
                );
              }),

              // MONITORING TOMBOL
              const SizedBox(height: 20),
              Row(
                children: [
                  Expanded(
                    flex: 2,
                    child: ElevatedButton(
                      onPressed: () {
                        if (monitoring.isMonitoring.value) {
                          monitoring.stopMonitoring();
                        } else {
                          monitoring.startMonitoring();
                        }
                        history.addHistory(
                          "START MONITORING",
                          "Mode Monitoring dimulai",
                        );
                      },
                      style: ElevatedButton.styleFrom(
                        backgroundColor: monitoring.isMonitoring.value
                            ? Colors.red
                            : Colors.green,
                        minimumSize: const Size(100, 130),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(15),
                        ),
                      ),
                      child: Text(
                        monitoring.isMonitoring.value ? "STOP" : "START",
                        textAlign: TextAlign.center,
                        style: const TextStyle(
                          color: Colors.white,
                          fontSize: 15,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    ),
                  ),

                  const SizedBox(width: 20),

                  // sensor gridnya biar bisa scroll
                  Expanded(
                    flex: 5,
                    child: SizedBox(
                      height: 180,
                      child: GridView.count(
                        scrollDirection: Axis.horizontal,
                        shrinkWrap: true,
                        crossAxisCount: 2, // 🔥 ini bikin 2 baris
                        mainAxisSpacing: 10,
                        crossAxisSpacing: 10,
                        childAspectRatio: 0.85,
                        children: [
                          sensorCard("N", monitoring.nitrogen.value),
                          sensorCard("P", monitoring.phosfor.value),
                          sensorCard("K", monitoring.kalium.value),
                          sensorCard("EC", monitoring.ec.value),
                          sensorCard("pH", monitoring.ph.value),
                          sensorCard("Suhu", monitoring.suhu.value),
                          sensorCard("Kelembaban", monitoring.kelembaban.value),
                        ],
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }

  Widget sensorCard(String title, double value) {
    return Container(
      padding: const EdgeInsets.all(10),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
        boxShadow: [
          BoxShadow(
            color: Colors.black26,
            blurRadius: 4,
            offset: const Offset(1, 2),
          ),
        ],
      ),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Text(
            title,
            textAlign: TextAlign.center,
            style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold),
          ),
          const SizedBox(height: 6),
          Text(
            value.toStringAsFixed(2),
            style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
          ),
        ],
      ),
    );
  }
}
