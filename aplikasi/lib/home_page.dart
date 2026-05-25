import 'package:flutter/material.dart';
import 'package:flutter_application_ble/Bluetooth_UI.dart';
import 'package:flutter_application_ble/History_UI.dart';
import 'package:flutter_application_ble/Monitoring_UI.dart';
import 'package:flutter_application_ble/Recommendation_UI.dart';
import 'package:flutter_application_ble/panduan_ui.dart';

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

// ini tu kaya fungsi
class Destinationpage {
  const Destinationpage(this.label, this.icon, this.selectedIcon);

  final String label;
  final Widget icon;
  final Widget selectedIcon;
}

// ini list homepagenya, ada 4 menu yess
const List<Destinationpage> destinations = <Destinationpage>[
  Destinationpage(
    'Panduan Page',
    Icon(Icons.book_online_outlined),
    Icon(Icons.book),
  ),
  Destinationpage(
    'Bluetooth Page',
    Icon(Icons.bluetooth_outlined),
    Icon(Icons.bluetooth),
  ),
  Destinationpage(
    'Monitoring Page',
    Icon(Icons.monitor_weight_outlined),
    Icon(Icons.monitor),
  ),
  Destinationpage(
    'Recommendation Page',
    Icon(Icons.recommend_outlined),
    Icon(Icons.recommend),
  ),
  Destinationpage(
    'History Page',
    Icon(Icons.history_toggle_off_outlined),
    Icon(Icons.history),
  ),
];

// ini yaa, urutannya dari 10, karena anggapnya indexnya, dan panduan bakalan yg pertama muncul
class _HomePageState extends State<HomePage> {
  int selectedIndex = 0;

  final List<Widget> pages = [
    PanduanUi(),
    BluetoothUi(),
    MonitoringUi(),
    RecommendationUi(),
    HistoryPage(),
  ];

  // ini fungsinay untuk ganti halaman
  void onItemTapped(int index) {
    setState(() {
      selectedIndex = index;
    });
  }

  void showPanduan() {
    showDialog(
      context: context,
      builder: (context) => AlertDialog(
        title: const Text("Panduan"),
        content: const Text(
          "Ini adalah panduan penggunaan aplikasi AgroLytics.",
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(context),
            child: const Text("Tutup"),
          ),
        ],
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,

      appBar: AppBar(
        backgroundColor: const Color.fromARGB(255, 104, 145, 90),
        centerTitle: true,

        title: Row(
          mainAxisSize: MainAxisSize.min,
          children: [
            Image.asset("assets/logobg.png", height: 28),
            const SizedBox(width: 8),
            Text(
              destinations[selectedIndex].label,
              style: const TextStyle(
                fontWeight: FontWeight.bold,
                color: Colors.white,
                fontSize: 20,
              ),
            ),
          ],
        ),
      ),

      // ini nih yg utama buat ganti halaman
      body: pages[selectedIndex],

      //  ini biar kek aplikasi contoh, jadi flyting dia
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          setState(() {
            selectedIndex = 0;
          });
        },
        backgroundColor: Color.fromARGB(255, 104, 145, 90),
        child: const Icon(Icons.book),
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,

      // ini buat bottom barnya
      bottomNavigationBar: BottomAppBar(
        color: const Color.fromARGB(255, 242, 239, 239),
        shape: const CircularNotchedRectangle(),
        notchMargin: 8,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            // ini kiri punya
            Row(
              children: [
                buildNavItem(index: 1, icon: Icons.bluetooth),
                const SizedBox(width: 20),
                buildNavItem(index: 2, icon: Icons.monitor),
              ],
            ),

            // ini kanan punya
            Row(
              children: [
                buildNavItem(index: 3, icon: Icons.recommend),
                const SizedBox(width: 20),
                buildNavItem(index: 4, icon: Icons.history),
              ],
            ),
          ],
        ),
      ),
    );
  }

  Widget buildNavItem({required int index, required IconData icon}) {
    bool isActive = selectedIndex == index;

    return GestureDetector(
      onTap: () => onItemTapped(index),
      child: AnimatedContainer(
        duration: const Duration(milliseconds: 200),
        padding: const EdgeInsets.all(10),
        decoration: BoxDecoration(
          color: isActive
              ? Color.fromARGB(255, 104, 145, 90)
              : Colors.transparent,
          borderRadius: BorderRadius.circular(20),
        ),
        child: Icon(
          icon,
          color: isActive ? Colors.white : Colors.black,
          size: 26,
        ),
      ),
    );
  }
}
