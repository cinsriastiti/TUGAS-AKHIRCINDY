import 'package:get/get.dart';
// import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter_application_ble/monitoring_ui.dart';
import 'package:flutter_application_ble/bluetooth_controller.dart';

class MonitoringController extends GetxController {
  final BluetoothController bluetooth = Get.find();

  // Data monitoringg
  final nitrogen = 0.0.obs;
  final phosfor = 0.0.obs;
  final kalium = 0.0.obs;
  final suhu = 0.0.obs;
  final kelembaban = 0.0.obs;
  final ph = 0.0.obs;
  final ec = 0.0.obs;
  final rekomendasi = "-".obs;
  final latitude = 0.0.obs;
  final longitude = 0.0.obs;

  RxBool isMonitoring = false.obs;

  // String get idMap {
  //   final pos = maps.pickedPosition.value ?? maps.currentPosition.value;
  //   if (pos.latitude == 0 || pos.longitude == 0) {
  //     return "unknown";
  //   }

  //   return "${pos.latitude.toStringAsFixed(6)},${pos.longitude.toStringAsFixed(6)}";
  // }

  String sessionId = "";
  DateTime lastSent = DateTime.now();

  @override
  void onInit() {
    super.onInit();
    ever(bluetooth.receivedText, (raw) {
      if (!isMonitoring.value) return;

      _parseSensorData(raw.toString());
    });
  }

  void startMonitoring() async {
    final pos = maps.pickedPosition.value ?? maps.currentPosition.value;

    if (pos.latitude == 0 || pos.longitude == 0) {
      print("Lokasi belum tersedia!");
      return;
    }

    latitude.value = pos.latitude;
    longitude.value = pos.longitude;

    sessionId = DateTime.now().millisecondsSinceEpoch.toString();
    isMonitoring.value = true;

    await FirebaseFirestore.instance
        .collection("agrolytics_monitoring")
        .doc(sessionId)
        .set({
          "startTime": FieldValue.serverTimestamp(),
          "location": GeoPoint(latitude.value, longitude.value),
        });
    bluetooth.send("monitor");
  }

  void stopMonitoring() async {
    isMonitoring.value = false;
    if (sessionId.isNotEmpty) {
      await FirebaseFirestore.instance
          .collection("agrolytics_monitoring")
          .doc(sessionId)
          .update({"endTime": FieldValue.serverTimestamp()});
    }
    bluetooth.send("STOP");
  }

  void parseSensorFromBluetooth(String raw) {
    _parseSensorData(raw);
  }

  void _parseSensorData(String raw) {
    try {
      final parts = raw.split(',');

      if (parts.length < 7) return;

      nitrogen.value = double.tryParse(parts[0]) ?? 0;
      phosfor.value = double.tryParse(parts[1]) ?? 0;
      kalium.value = double.tryParse(parts[2]) ?? 0;
      ec.value = double.tryParse(parts[3]) ?? 0;
      ph.value = double.tryParse(parts[4]) ?? 0;
      suhu.value = double.tryParse(parts[5]) ?? 0;
      kelembaban.value = double.tryParse(parts[6]) ?? 0;
     
     
      latitude.value = latitude.value;
      longitude.value = longitude.value;
      print("Parsed: $parts");
      _sendToFirestore();
    } catch (e) {
      print("Parse Error Monitoring: $e");
    }
  }

  void _sendToFirestore() async {
    if (!isMonitoring.value || sessionId == null) return;

    final now = DateTime.now();

    // ⏱️ kirim tiap 2 detik
    if (lastSent != null && now.difference(lastSent!).inSeconds < 2) return;

    lastSent = now;

    await FirebaseFirestore.instance
        .collection("agrolytics_monitoring")
        .doc(sessionId)
        .collection("data")
        .add({
          "nitrogen": nitrogen.value,
          "phosphorus": phosfor.value,
          "potassium": kalium.value,
          "ec": ec.value,
          "ph": ph.value,
          "temperature": suhu.value,
          "humidity": kelembaban.value,
          "timestamp": FieldValue.serverTimestamp(),
        });
  }
}
