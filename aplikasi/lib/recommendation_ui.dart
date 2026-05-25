import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:flutter_application_ble/maps_controller.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:flutter_application_ble/history_controller.dart';
import 'package:flutter_application_ble/bluetooth_controller.dart';
import 'package:flutter_application_ble/recommendation_controller.dart';

final maps = Get.put(MapsController());

class RecommendationUi extends StatelessWidget {
  RecommendationUi({super.key});
  //
  final rekom = Get.put(RekomendasiController());
  final bluetooth = Get.find<BluetoothController>();
  final history = Get.find<HistoryController>();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color.fromARGB(255, 244, 243, 243),
      body: Obx(
        () => SingleChildScrollView(
          padding: const EdgeInsets.all(16),
          child: Column(
            children: [
              Container(
                padding: const EdgeInsets.all(16),
                decoration: BoxDecoration(
                  color: bluetooth.connectedDevice.value != null
                      ? Color.fromARGB(255, 35, 137, 220)
                      : const Color.fromARGB(255, 232, 71, 69),
                  borderRadius: BorderRadius.circular(10),
                ),
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
                        fontSize: 9,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ],
                ),
              ),

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

                return Column(
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
                      style: const TextStyle(fontSize: 16, color: Colors.black),
                    ),
                  ],
                );
              }),

              const SizedBox(height: 20),
              SizedBox(
                height: 180,
                child: Row(
                  children: [
                    Expanded(
                      flex: 2,
                      child: ElevatedButton(
                        onPressed: () {
                          if (rekom.currentMode.value == "recommend") {
                            bluetooth.send("STOP");
                            rekom.currentMode.value = "monitoring";

                            history.addHistory(
                              "STOP REKOMENASI",
                              "Mode Rekomendasi Dihentikan",
                            );
                          } else {
                            bluetooth.send("recommend"); // perintah ke ESP
                            rekom.currentMode.value = "recommend";

                            history.addHistory(
                              "START REKOMENASI",
                              "Mode Rekomendasi dimulai",
                            );
                          }
                        },
                        style: ElevatedButton.styleFrom(
                          backgroundColor:
                              rekom.currentMode.value == "recommend"
                              ? Colors.red
                              : Colors.green,
                          minimumSize: const Size(100, 130),
                          shape: RoundedRectangleBorder(
                            borderRadius: BorderRadius.circular(15),
                          ),
                        ),
                        child: Text(
                          rekom.currentMode.value == "recommend"
                              ? "STOP"
                              : "START",
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

                    Expanded(
                      flex: 5,
                      child: GridView(
                        scrollDirection: Axis.horizontal,
                        shrinkWrap: true,
                        gridDelegate:
                            const SliverGridDelegateWithFixedCrossAxisCount(
                              crossAxisCount: 2,
                              mainAxisSpacing: 10,
                              crossAxisSpacing: 10,
                              childAspectRatio: 0.85,
                            ),
                        children: [
                          sensorCard("N", rekom.nitrogen.value),
                          sensorCard("P", rekom.phosfor.value),
                          sensorCard("K", rekom.kalium.value),
                          sensorCard("EC", rekom.ec.value),
                          sensorCard("pH", rekom.ph.value),
                          sensorCard("Suhu", rekom.suhu.value),
                          sensorCard("Kelembaban", rekom.kelembaban.value),
                        ],
                      ),
                    ),
                  ],
                ),
              ),

              const SizedBox(height: 20),

              Container(
                width: double.infinity,
                padding: const EdgeInsets.all(16),
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(12),
                  boxShadow: const [
                    BoxShadow(
                      color: Colors.black26,
                      blurRadius: 4,
                      offset: Offset(1, 2),
                    ),
                  ],
                ),
                child: Obx(() {
                  // state helper
                  final String hasil = rekom.rekomendasi.value;
                  final String mode = rekom.currentMode.value;

                  Widget content;

                  if (mode == "recommend" && (hasil == "-" || hasil.isEmpty)) {
                    // Sedang proses rekomendasi
                    content = Column(
                      children: const [
                        SizedBox(height: 8),
                        CircularProgressIndicator(),
                        SizedBox(height: 12),
                        Text(
                          "Sedang memproses rekomendasi...",
                          style: TextStyle(fontSize: 16),
                        ),
                      ],
                    );
                  } else if (hasil == "-" || hasil.isEmpty) {
                    // Belum ada hasil sama sekali
                    content = const Text(
                      "Belum ada rekomendasi",
                      style: TextStyle(fontSize: 16, color: Colors.grey),
                    );
                  } else {
                    content = Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        const Text(
                          "Tanaman yang Direkomendasikan",
                          style: TextStyle(fontSize: 16, color: Colors.black54),
                        ),
                        const SizedBox(height: 8),
                        Center(
                          child: Text(
                            hasil.toUpperCase(),
                            style: const TextStyle(
                              fontSize: 22,
                              fontWeight: FontWeight.bold,
                              color: Colors.green,
                            ),
                          ),
                        ),
                        const SizedBox(height: 16),
                        const Text(
                          "Rincian Rekomendasi",
                          style: TextStyle(
                            fontSize: 16,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 8),
                        ...List.generate(rekom.Kelas.length, (i) {
                          final proba = rekom.probabilitas.length > i
                              ? rekom.probabilitas[i]
                              : 0.0;
                          final isTop =
                              rekom.Kelas[i].toLowerCase() ==
                              hasil.toLowerCase();
                          return Padding(
                            padding: const EdgeInsets.symmetric(vertical: 4),
                            child: Row(
                              children: [
                                Expanded(
                                  child: Text(
                                    rekom.Kelas[i],
                                    style: TextStyle(
                                      fontSize: 14,
                                      fontWeight: isTop
                                          ? FontWeight.bold
                                          : FontWeight.normal,
                                      color: isTop
                                          ? Colors.green
                                          : Colors.black,
                                    ),
                                  ),
                                ),
                                Text(
                                  "${proba.toStringAsFixed(1)}%",
                                  style: TextStyle(
                                    fontSize: 14,
                                    fontWeight: isTop
                                        ? FontWeight.bold
                                        : FontWeight.normal,
                                    color: isTop ? Colors.green : Colors.black,
                                  ),
                                ),
                              ],
                            ),
                          );
                        }),
                      ],
                    );
                  }

                  return Column(
                    children: [
                      const Text(
                        "Hasil Rekomendasi",
                        style: TextStyle(
                          fontSize: 20,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      const SizedBox(height: 12),
                      content,
                    ],
                  );
                }),
              ),

              const SizedBox(height: 25),

              ElevatedButton(
                onPressed: () async {
                  await rekom.sendFirebase();

                  history.addHistory(
                    "KIRIM KE DATABASE",
                    "Mengirim data ke Database",
                  );
                },
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color.fromARGB(255, 22, 58, 3),
                  minimumSize: const Size(250, 45),
                ),
                child: const Text(
                  "Kirim ke Database",
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 18,
                    fontWeight: FontWeight.bold,
                  ),
                ),
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
        boxShadow: const [
          BoxShadow(color: Colors.black26, blurRadius: 4, offset: Offset(1, 2)),
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
