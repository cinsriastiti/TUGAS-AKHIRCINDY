import 'package:flutter_application_ble/Monitoring_Controller.dart';
import 'package:get/get.dart';
import 'package:flutter_blue_plus/flutter_blue_plus.dart';
import 'dart:convert';

class BluetoothController extends GetxController {
  final Guid targetServiceUuid = Guid("f740711c-cf44-416a-bce0-b1104ce9b8ce");
  final Guid notifyUuid = Guid("83620794-4bad-4366-a73f-2ecc00d857dd");
  final Guid writeUuid = Guid("bb178305-facf-4742-89b7-b592fb5c37ee"); 

  var bluetoothIsOn = false.obs;
  var isScanning = false.obs;
  var scanResults = <ScanResult>[].obs;

  Rx<BluetoothDevice?> connectedDevice = Rx<BluetoothDevice?>(null);

  BluetoothCharacteristic? notifyChar;
  BluetoothCharacteristic? writeChar;

  final receivedText = "".obs;

  @override
  void onInit() {
    super.onInit();

    FlutterBluePlus.adapterState.listen((state) {
      bluetoothIsOn.value = state == BluetoothAdapterState.on;
    });
  }

  void scanDevices() async {
    isScanning.value = true;
    scanResults.clear();

    FlutterBluePlus.startScan(timeout: const Duration(seconds: 4));

    FlutterBluePlus.scanResults.listen((results) {
      scanResults.value = results;
    });

    await Future.delayed(const Duration(seconds: 4));
    isScanning.value = false;
  }

  Future<void> connectToDevice(BluetoothDevice device) async {
    try {
      await device.connect();
    } catch (_) {
      // Kalau sudah connect, lanjut saja
    }

    connectedDevice.value = device;
    await discover(device);
  }

  Future<void> discover(BluetoothDevice dev) async {
    final services = await dev.discoverServices();

    for (var service in services) {
      if (service.uuid == targetServiceUuid) {
        for (var c in service.characteristics) {
          if (c.uuid == notifyUuid) {
            notifyChar = c;
            await c.setNotifyValue(true);
            c.onValueReceived.listen((data) {
              _handleIncomingData(data);
            });
          }
          if (c.uuid == writeUuid) {
            writeChar = c;
          }
        }
      }
    }
  }

  void _handleIncomingData(List<int> data) {
    final text = utf8.decode(data);
    receivedText.value = text;
    print("Data Masuk: $text");
    if(text.contains(",")){
      try{
        final monitoring = Get.find<MonitoringController>();
        monitoring.parseSensorFromBluetooth(text);
        print("Sensor parsed : $text");
      } catch(e){
        print("ERROR  parseSensor: $e");
      }
    }
  }

  
  Future<void> send(String message) async {
    if (writeChar == null) return;

    await writeChar!.write(
      utf8.encode(message),
      withoutResponse: false,
    );
  }

  Future<void> setMonitoringMode() async => send("monitor");
  Future<void> setRecommendationMode() async => send("recommend");

 
  Future<void> disconnect() async {
    if (connectedDevice.value != null) {
      await connectedDevice.value!.disconnect();
    }

    connectedDevice.value = null;
    notifyChar = null;
    writeChar = null;
  }
}
