import 'package:flutter/material.dart';

class PanduanUi extends StatelessWidget {
  const PanduanUi({super.key});

  Widget buildStep(IconData icon, String title, String desc) {
    return Card(
      elevation: 3,
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(15),
      ),
      margin: const EdgeInsets.symmetric(vertical: 10),
      child: ListTile(
        leading: CircleAvatar(
          backgroundColor: Colors.green,
          child: Icon(icon,
           color: Colors.black),
        ),
        title: Text(
          title,
          style: const TextStyle(fontWeight: FontWeight.bold),
        ),
        subtitle: Text(desc),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,

      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: ListView(
          children: [

            const SizedBox(height: 10),

            const Text(
              "Panduan Penggunaan AgroLytics",
              style: TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
              ),
            ),

            const SizedBox(height: 10),

            const Text(
              "Ikuti langkah-langkah berikut untuk menggunakan aplikasi:",
            ),

            const SizedBox(height: 20),
            buildStep(
              Icons.bluetooth,
              "1. Hubungkan Bluetooth",
              "Masuk ke menu Bluetooth Page untuk menghubungkan alat dengan aplikasi.",
            ),
            buildStep(
              Icons.monitor,
              "2. Monitoring Tanah",
              "Lihat kondisi tanah seperti nilai NPK dan parameter lainnya secara realtime.",
            ),
            buildStep(
              Icons.recommend,
              "3. Rekomendasi Tanaman",
              "Dapatkan rekomendasi tanaman yang cocok berdasarkan kondisi tanah.",
            ),

            buildStep(
              Icons.history,
              "4. Riwayat Data",
              "Lihat riwayat penggunaan aplikasi.",
            ),

            const SizedBox(height: 20),

            const Center(
              child: Text(
                "Selamat menggunakan aplikasi AgroLytics",
                style: TextStyle(fontWeight: FontWeight.bold),
              ),
            ),
          ],
        ),
      ),
    );
  }
}