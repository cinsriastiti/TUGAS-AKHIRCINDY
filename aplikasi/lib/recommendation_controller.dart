// import 'dart:convert';
import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter_application_ble/bluetooth_controller.dart';
import 'package:flutter_application_ble/recommendation_ui.dart';

class RekomendasiController extends GetxController {
  final BluetoothController bluetooth = Get.find();

  final RxDouble nitrogen = 0.0.obs;
  final RxDouble phosfor = 0.0.obs;
  final RxDouble kalium = 0.0.obs;
  final RxDouble ec = 0.0.obs;
  final RxDouble ph = 0.0.obs;
  final RxDouble suhu = 0.0.obs;
  final RxDouble kelembaban = 0.0.obs;

  final RxString rekomendasi = "-".obs;
  final RxDouble latitude = 0.0.obs;
  final RxDouble longitude = 0.0.obs;
  final RxString currentMode = "monitoring".obs;
  final RxBool isLoading = false.obs;
  final RxList<double> probabilitas = <double>[0, 0, 0, 0, 0, 0, 0].obs;

  final List<String> Kelas = [
    "Bawang Daun",
    "Bawang Merah",
    "Cabai",
    "Parsley",
    "Selada",
    "Tomat",
    "Zucchini",
  ];
  String get idMap {
    // "${latitude.value.toStringAsFixed(6)},${longitude.value.toStringAsFixed(6)}";
    final pos = maps.pickedPosition.value ?? maps.currentPosition.value;

    if (pos.latitude == 0 || pos.longitude == 0) {
      return "unknown";
    }

    return "${pos.latitude.toStringAsFixed(6)},${pos.longitude.toStringAsFixed(6)}";
  }

  @override
  void onInit() {
    super.onInit();

    ever(bluetooth.receivedText, (raw) {
      if (raw == null || raw.toString().isEmpty) return;
      _parseSensorsData(raw.toString());
    });
  }

  void setCoordinates(double lat, double lon) {
    latitude.value = lat;
    longitude.value = lon;
  }

  void _parseSensorsData(String raw) {
    try {
      final parts = raw.split(',');
      if (parts.length < 8) return;

      nitrogen.value = _toDouble(parts[0]);
      phosfor.value = _toDouble(parts[1]);
      kalium.value = _toDouble(parts[2]);
      ec.value = _toDouble(parts[3]);
      ph.value = _toDouble(parts[4]);
      suhu.value = _toDouble(parts[5]);
      kelembaban.value = _toDouble(parts[6]);
      rekomendasi.value = parts[7].isEmpty ? '-' : parts[7];

      if (parts.length >= 15) {
        probabilitas.value = parts
            .sublist(8, 15)
            .map((e) => _toDouble(e))
            .toList();
      }
    } catch (e) {
      print("Parse error rekomendasi: $e");
    }
  }

  double _toDouble(String v) => double.tryParse(v) ?? 0.0;

  Future<bool> _savefirebase() async {
    final body = {
      "id_map": idMap,
      "nilai_n": nitrogen.value,
      "nilai_p": phosfor.value,
      "nilai_k": kalium.value,
      "nilai_suhu": suhu.value,
      "nilai_kelembaban": kelembaban.value,
      "nilai_ec": ec.value,
      "nilai_ph": ph.value,
      "name": rekomendasi.value,
    };

    try {
      isLoading.value = true;

      await FirebaseFirestore.instance.collection('agrolytics').add(body);
      return true;
    } catch (e) {
      print("Firebase error: $e");
      return false;
    } finally {
      isLoading.value = false;
    }
  }

  Future<void> sendFirebase() async {
    final success = await _savefirebase();

    if (success) {
      Get.snackbar(
        "Sukses",
        "Data berhasil dikirim ke database",
        snackPosition: SnackPosition.BOTTOM,
        backgroundColor: Colors.green,
        colorText: Colors.white,
      );
    } else {
      Get.snackbar(
        "Gagal",
        "Gagal mengirim data ke database",
        snackPosition: SnackPosition.BOTTOM,
        backgroundColor: Colors.red,
        colorText: Colors.white,
      );
    }
  }
}
