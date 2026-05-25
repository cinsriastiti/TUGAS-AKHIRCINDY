
import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:flutter_application_ble/history_controller.dart';

class HistoryPage extends StatelessWidget {
  HistoryPage({super.key});

  final HistoryController history = Get.put(HistoryController());

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Obx(() {
        if (history.historyList.isEmpty) {
          return const Center(child: Text("Belum ada History"));
        }

        return ListView.builder(
          padding: const EdgeInsets.all(16),
          itemCount: history.historyList.length,
          itemBuilder: (context, index) {
            final item = history.historyList[index];

            return Container(
              margin: const EdgeInsets.only(bottom: 12),
              padding: const EdgeInsets.all(16),
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(16),
                boxShadow: [
                  BoxShadow(
                    color: Colors.black.withOpacity(0.3),
                    blurRadius: 10,
                    offset: const Offset(0, 4),
                  ),
                ],
              ),
              child: Row(
                children: [
                  // CircleAvatar(
                  //   radius: 22,
                  //   backgroundColor: _getColor(item["title"]!),
                  //   child: Icon(_getIcon(item["title"]!), color: Colors.white),
                  // ),
                  const SizedBox(width: 16),
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(
                          item["title"]!,
                          style: const TextStyle(
                            fontSize: 16,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 4),
                        Text(
                          item["desc"]!,
                          style: const TextStyle(color: Colors.black),
                        ),
                      ],
                    ),
                  ),

                  Text(
                    item["date"]!,
                    style: const TextStyle(fontSize: 12, color: Colors.black),
                  ),
                ],
              ),
            );
          },
        );
      }),
      backgroundColor: Colors.white,
    );
  }
}
