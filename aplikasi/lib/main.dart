import 'Splash_page.dart';
import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter_application_ble/maps_controller.dart';
import 'package:flutter_application_ble/history_controller.dart';
import 'package:flutter_application_ble/monitoring_controller.dart';
import 'package:flutter_application_ble/bluetooth_controller.dart';

void main() async{
  WidgetsFlutterBinding.ensureInitialized();
  Get.put(BluetoothController(), permanent: true);
  Get.put(MonitoringController(), permanent: true);
  Get.put(MapsController(), permanent: true);
  Get.put(HistoryController(), permanent: true);
  await Firebase.initializeApp();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,

      theme: ThemeData(
        useMaterial3: true,
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.red),
        // scaffoldBackgroundColor: Colors.red,
        scaffoldBackgroundColor: const Color.fromARGB(255, 183, 231, 129),
        // appBarTheme: const AppBarTheme(
        //   backgroundColor: Colors.red,
        //   elevation: 0,
        //   centerTitle: true,
        // ),
      ),
    

      home: const SplashPage(),
    );
  }
}
